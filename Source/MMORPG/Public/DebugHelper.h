#pragma once

#include <format>

#define LOG_I(fmt, ...)    Debug::LOG(ELogVerbosity::Log, fmt, ##__VA_ARGS__)
#define LOG_W(fmt, ...)    Debug::LOG(ELogVerbosity::Warning, fmt, ##__VA_ARGS__)
#define LOG_E(fmt, ...)    Debug::LOG(ELogVerbosity::Error, fmt, ##__VA_ARGS__)

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
	static void LOG(ELogVerbosity::Type Verbosity, const std::string& FormatStr, Args&&... args)
	{
		std::string Formatted = std::vformat(FormatStr, std::make_format_args(std::forward<Args>(args)...));

		FString Msg = FString(Formatted.c_str());

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::MakeRandomColor(), Msg);

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
