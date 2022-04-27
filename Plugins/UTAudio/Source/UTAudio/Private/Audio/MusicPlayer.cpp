#include "Audio/MusicPlayer.h"
#include "Core/Log.h"
#include "Components/AudioComponent.h"

/**
 * @brief Create a new instance of the MusicPlayer class
 */
AMusicPlayer::AMusicPlayer()
{
	// Initialize the audio player
	PrimaryActorTick.bCanEverTick = false;
	AudioPlayer = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Player"));
}

/**
 * @brief Overridable native event for when play begins for this actor
 */
void AMusicPlayer::BeginPlay()
{
	// Automatically play the music
	Super::BeginPlay();
	AudioPlayer->Play();
}

/**
 * @brief Adjust the playback volume of the music
 * @param Volume The new volume of the music
 */
void AMusicPlayer::SetVolume(const float Volume) const
{
	// Check if everything was initialize correctly
	if (AudioPlayer == nullptr)
	{
		ULog::Error("MusicPlayer::SetVolume", "AudioPlayer is nullptr");
		return;
	}

	// Set the new volume
	AudioPlayer->SetVolumeMultiplier(Volume);
	ULog::Info("MusicPlayer::SetVolume",
		FString("Volume changed to ").Append(FString::SanitizeFloat(Volume, 5)));
}

/**
 * @brief Play the music
 */
void AMusicPlayer::Play() const
{
	// Check if everything was initialize correctly
	if (AudioPlayer == nullptr)
	{
		ULog::Error("MusicPlayer::Play", "AudioPlayer is nullptr");
		return;
	}

	// Check if the music is paused
	if (AudioPlayer->bIsPaused)
	{
		AudioPlayer->SetPaused(false);
		ULog::Info("MusicPlayer::Play", "Music resumed");
		return;
	}

	// Check if the music is stopped
	if (!AudioPlayer->IsPlaying())
	{
		AudioPlayer->Play();
		ULog::Info("MusicPlayer::Play", "Music played");
		return;
	}

	ULog::Warning("MusicPlayer::Play", "Music already playing and is not paused");
}

/**
 * @brief Pause the music
 */
void AMusicPlayer::Pause() const
{
	// Check if everything was initialize correctly
	if (AudioPlayer == nullptr)
	{
		ULog::Error("MusicPlayer::Pause", "AudioPlayer is nullptr");
		return;
	}

	// Check if the music is paused
	if (AudioPlayer->bIsPaused)
	{
		ULog::Warning("MusicPlayer::Pause", "Music already paused");
		return;
	}

	// Check if the music is stopped
	if (!AudioPlayer->IsPlaying())
	{
		ULog::Warning("MusicPlayer::Pause", "Music is not playing");
		return;
	}

	AudioPlayer->SetPaused(true);
	ULog::Info("MusicPlayer::Pause", "Music paused");
}
/**
 * @brief Stop the music
 */
void AMusicPlayer::Stop() const
{
	// Check if everything was initialize correctly
	if (AudioPlayer == nullptr)
	{
		ULog::Error("MusicPlayer::Stop", "AudioPlayer is nullptr");
		return;
	}

	// Check if the music is already stopped
	if (!AudioPlayer->bIsPaused && !AudioPlayer->IsPlaying())
	{
		ULog::Warning("MusicPlayer::Stop", "Music already stopped");
		return;
	}

	// Stop the music
	AudioPlayer->Stop();
	ULog::Info("MusicPlayer::Stop", "Music stopped");
}