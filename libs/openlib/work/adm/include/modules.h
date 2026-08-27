#ifndef _MODULES_H
#define _MODULES_H

#include "dirs.h"

// These are listed in the approximate order they should be inherited
// when using more than one module.  (see the header file for each module
// for notes on additional work that may be needed.)

#define M_CLEAN_UP         MODULE_DIR "/m_clean_up"
#define M_OBJECT_CLASS     MODULE_DIR "/m_object_class"
#define M_FLAGS            MODULE_DIR "/m_flags"
#define M_LIGHT            MODULE_DIR "/m_light"
#define M_VISIBLE          MODULE_DIR "/m_visible"
#define M_MOVE             MODULE_DIR "/m_move"
#define M_VALUE            MODULE_DIR "/m_value"
#define M_DIMENSIONS       MODULE_DIR "/m_dimensions"
#define M_CONTAINER        MODULE_DIR "/m_container"
#define M_MONEY_CONTAINER  MODULE_DIR "/m_money_container"
#define M_ARMOUR           MODULE_DIR "/m_armour"
#define M_WEAPON           MODULE_DIR "/m_weapon"
#define M_COMBAT           MODULE_DIR "/m_combat"
#define M_LIVING           MODULE_DIR "/m_living"

#endif /* _MODULES_H */
