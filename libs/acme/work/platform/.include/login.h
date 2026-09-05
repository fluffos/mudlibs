#ifndef _LOGIN_H
#define _LOGIN_H

#define LOCALHOST              "127.0.0.1"
#define WELCOME_FILE           PlatformEtcDir "/issue"
#define TERMINAL_MAX_TRIES     3
#define TIMEOUT_SECS           (10 * 60)
#define CLEAR_SCREEN           1
#define InsecureWarning        "Warning: You are on an insecure connection. " \
                               "Act accordingly."
#define DefaultTermWarning     "Unable to detect terminal type. " \
                               "Using default."
#define TimeoutMessage         "Timeout exceeded, disconnecting...\n"

#endif  // _LOGIN_H
