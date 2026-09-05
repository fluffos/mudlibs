#include "security.h"
#define ALIGN_EXP_DIVISOR		1800
#define WA_FACTOR       3
#define EXP_DIVISOR			190
#define INTERVAL_BETWEEN_HEALING	10
#define WEAPON_CLASS_OF_HANDS		(3)
#define ARMOUR_CLASS_OF_BARE		0
#define KILL_NEUTRAL_ALIGNMENT		10
#define CAP_GOOD_ALIGN	1800
#define CAP_EVIL_ALIGN	-1800
#define ADJ_ALIGNMENT(al)		((-al - KILL_NEUTRAL_ALIGNMENT)/4)
#define MAX_LIST			20
#define NAME_OF_GHOST			"some mist"

inherit "obj/living_pretypes.lpc";
