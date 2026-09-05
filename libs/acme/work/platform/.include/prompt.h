#ifndef _PROMPT_H
#define _PROMPT_H

#define DEFAULT_PROMPT        "> "

#define PROMPT_TYPE           "type"
#define PROMPT_NO_ECHO        "noEcho"
#define PROMPT_IGNORE_BANG    "ignoreBang"
#define PROMPT_RETRY          "retry"
#define PROMPT_ATTEMPT        "attempt"
#define PROMPT_LAST_INPUT     "lastInput"
#define PROMPT_LAST_RESULT    "lastResult"
#define PROMPT_LAST_PROMPT    "lastPrompt"

#define PROMPT_TYPE_INPUT     1
#define PROMPT_TYPE_COMMAND   2

#define PROMPT_INFO_PROMPT    0
#define PROMPT_INFO_CONTEXT   1
#define PROMPT_INFO_CALLBACK  2
#define PROMPT_INFO_ARGS      3

#endif  // _PROMPT_H
