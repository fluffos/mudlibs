#ifndef _PET_DEFS_H
#define _PET_DEFS_H
 
#include "living_defs.h"
 
#define F_RESET_USED            1 << 0
#define F_PET_CAN_SAY           1 << 1
#define F_PET_CAN_EMOTE         1 << 2
#define F_PET_CAN_CHANGE_STYLE  1 << 3
#define F_PET_IS_QUIET          1 << 4
#define F_PET_IS_LEASHED        1 << 5
#define F_PET_HAS_MASTER        1 << 6
#define F_PET_HAS_HB            1 << 7

#define PET_FILE         "/lib/pet"
 
#endif
