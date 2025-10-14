#pragma once

#include <format>

#define LOG_I(color, fmt, ...)    Debug::LOG(ELogVerbosity::Log, color, fmt, ##__VA_ARGS__)
#define LOG_W(color, fmt, ...)    Debug::LOG(ELogVerbosity::Warning, color, fmt, ##__VA_ARGS__)
#define LOG_E(color, fmt, ...)    Debug::LOG(ELogVerbosity::Error, color, fmt, ##__VA_ARGS__)

namespace Debug
{

	static void Print(const FString& Msg, const FColor& Color = FColor::MakeRandomColor(), int32 InKey = -1)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(InKey, 7.f, Color, Msg);

			UE_LOG(LogTemp, Warning, TEXT("%s"), *Msg);
		}
	}

	template<typename... Args>
	static void LOG(ELogVerbosity::Type Verbosity, const FColor& Color, const std::string& FormatStr, Args&&... args)
	{
		auto ToStdStringArg = [](auto&& arg) -> std::string
			{
				using T = std::decay_t<decltype(arg)>;

				if constexpr (std::is_same_v<T, FString>)
				{
					return TCHAR_TO_UTF8(*arg);
				}
				else if constexpr (std::is_same_v<T, FName>)
				{
					return TCHAR_TO_UTF8(*arg.ToString());
				}
				else if constexpr (std::is_same_v<T, FText>)
				{
					return TCHAR_TO_UTF8(*arg.ToString());
				}
				else
				{
					// keep others type (int, float, std::string, const char*, ...)
					return std::format("{}", arg);
				}
			};

		// Make tuple to contain all the arguments
		auto ConvertedArgs = std::make_tuple(ToStdStringArg(std::forward<Args>(args))...);

		// using apply() for unpacking tuple when call vformat
		std::string Formatted = std::apply(
			[&](auto&&... unpacked)
			{
				return std::vformat(FormatStr, std::make_format_args(unpacked...));
			},
			ConvertedArgs
		);

		FString Msg = FString(Formatted.c_str());

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 7.0f, Color, Msg);

			switch (Verbosity)
			{
			case ELogVerbosity::Log:
				UE_LOG(LogTemp, Log, TEXT("%s"), *Msg);
				break;
			case ELogVerbosity::Warning:
				UE_LOG(LogTemp, Warning, TEXT("%s"), *Msg);
				break;
			case ELogVerbosity::Error:
				UE_LOG(LogTemp, Error, TEXT("%s"), *Msg);
				break;
			default:
				break;
			}
		}
	}
}
