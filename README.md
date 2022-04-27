# Audio Plugin
An audio system used to manage the basic properties of audio files. It includes different sound classes, a sound mix, sound attenuation settings and a music player

## Installation
1. Download the latest release from GitHub
2. Navigate to `C:\Program Files\Epic Games\UE_{VERSION}\Engine\Plugins\`
3. Create a `Marketplace` folder if needed
4. Extract the release and copy to the `Marketplace` folder
5. Open Unreal Engine
6. Click on `Edit > Plugins`
7. Enable the plugin under the `Installed > Unreal Toolbox` category
8. Restart Unreal Engine

## Music Player
The `Music Player` actor can be placed in a map to easily play and manipulate background music. It includes the following functions:
1. `Set Volume` - Set the volume of the music
2. `Play` - Play/Resume the music
3. `Pause` - Pause the music
4. `Stop` - Stop the music

## Sound Classes
This plugin includes 4 different sound classes that can be assigned to all your audio files:
1. `UTAudio_EffectsSoundClass` - Used for sound effects. The default volume is `1.0`
2. `UTAudio_MusicSoundClass` - Used for background music. The default volume is `0.5`
3. `UTAudio_UISoundClass` - Used for UI sounds. The default volume is `1.0`
4. `UTAudio_VoiceSoundClass` - Used for voice files. The default volume is `3.0`