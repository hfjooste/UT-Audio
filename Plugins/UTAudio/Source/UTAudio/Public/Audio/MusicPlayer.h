﻿#pragma once

#include "GameFramework/Actor.h"
#include "MusicPlayer.generated.h"

/**
 * @brief Actor that is responsible for play music
 */
UCLASS()
class UTAUDIO_API AMusicPlayer final : public AActor
{
	GENERATED_BODY()

	/**
	 * @brief The audio player component is responsible for the music playback
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Audio", meta=(AllowPrivateAccess = "true"))
	class UAudioComponent* AudioPlayer;
	
public:	
	/**
	 * @brief Create a new instance of the MusicPlayer class 
	 */
	AMusicPlayer();
	
	/**
	 * @brief Adjust the playback volume of the music 
	 * @param Volume The new volume of the music
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Audio")
	void SetVolume(float Volume) const;

	/**
	 * @brief Play the music
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Audio")
	void Play() const;
	
	/**
	 * @brief Pause the music
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Audio")
	void Pause() const;

	/**
	 * @brief Stop the music
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Audio")
	void Stop() const;

protected:
	/**
	 * @brief Overridable native event for when play begins for this actor
	 */
	virtual void BeginPlay() override;
};