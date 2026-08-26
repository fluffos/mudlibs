/*
 * messages.h
 *
 * Message classes -- these are strings for now;
 *      we could just as easily use unique ints for each
 */

#ifndef MESSAGES_H
#define MESSAGES_H

/*
 * atmosphere and environment
 */
#define MSG_COMBAT      "combat"
#define MSG_EMOTE       "emote"
#define MSG_INFO        "info"
#define MSG_LOOK        "look"
#define MSG_MOVEMENT    "movement"
#define MSG_PROMPT      "prompt"

/*
 * user communications
 *   "say", "tell", "whisper", "gtell", "wiz", etc
 */
#define MSG_CHANNEL     "channel"
#define MSG_SAY         "say"
#define MSG_TELL        "tell"

/*
 * MSG_SYSTEM  - system messages, errors, warnings
 * MSG_DEBUG   - for debugging
 * MSG_SNOOP   - when snooping
 * MSG_COMMAND - general command output
 * MSG_PRIVATE - private message; for special client shells only
 */
#define MSG_SYSTEM      "system"
#define MSG_DEBUG       "debug"
#define MSG_SNOOP       "snoop"
#define MSG_COMMAND     "command"
#define MSG_PRIVATE     "private"

#endif
