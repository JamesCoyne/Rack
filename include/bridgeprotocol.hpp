#pragma once
#include <stdint.h>


namespace rack {


// TODO Change driver and port number to something less common
/** Driver ID in AudioIO and MidiIO */
#define BRIDGE_DRIVER -5000
#define BRIDGE_HOST "127.0.0.1"
#define BRIDGE_PORT 5000
#define BRIDGE_NUM_PORTS 16
/** Number of VST/AU automation parameters */
#define BRIDGE_NUM_PARAMS 16
/** An arbitrary number which prevents connection from other protocols (like WebSockets) and old Bridge versions */
#define BRIDGE_HELLO 0xff00fefd


/** All commands are called from the client and served by the server
send
- uint8_t cmd
*/
enum BridgeCommand {
	NO_COMMAND = 0,
	/** Requests the server to shut down the client */
	QUIT_COMMAND,
	/** Sets the port
	send
	- uint8_t port
	*/
	PORT_SET_COMMAND,
	/** Sends a 3-byte MIDI command
	send
	- uint8_t msg[3]
	*/
	MIDI_MESSAGE_SEND_COMMAND,
	/** Sets the audio sample rate
	send
	- uint32_t sampleRate
	*/
	AUDIO_SAMPLE_RATE_SET_COMMAND,
	/** Sets the number of audio channels
	Currently not supported, hard-coded at 2.
	send
	- uint8_t channels
	*/
	AUDIO_CHANNELS_SET_COMMAND,
	/** Sends and receives an audio buffer
	send
	- uint32_t length
	- float input[length]
	recv
	- float output[length]
	*/
	AUDIO_PROCESS_COMMAND,
	/** Resumes the audio buffer, forcing Rack to wait on an audio buffer */
	AUDIO_ACTIVATE,
	/** Pauses the audio buffer, allowing Rack to not wait on an audio buffer */
	AUDIO_DEACTIVATE,
	NUM_COMMANDS
};


} // namespace rack