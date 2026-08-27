#ifndef _SHELLS_H
#define _SHELLS_H

#include "dirs.h"

#define DEFAULT_PATHS ({ CMD_DIR "/player", SECURE_CMD_DIR "/player" })
#define WIZARD_PATHS ({ CMD_DIR "/wiz", CMD_DIR "/adm",\
			SECURE_CMD_DIR "/wiz", SECURE_CMD_DIR "/adm" })

#endif /* _SHELLS_H */
