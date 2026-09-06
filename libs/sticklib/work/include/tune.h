/* tune.h
 *
 *  Use this at least in guild damage formulas for easy tuning of damages.
 */

#ifndef _TUNE_H
#define _TUNE_H

#define INTERVAL_BETWEEN_HEALING        10
#define WEAPON_CLASS_OF_HANDS           (3)
#define ARMOUR_CLASS_OF_BARE            0
#define KILL_NEUTRAL_ALIGNMENT          10
#define ADJ_ALIGNMENT(al)               ((-al - KILL_NEUTRAL_ALIGNMENT)/4)

#define TUNE_GENERAL_DAMAGE(x)       ( 90 * (x) / 100 )
#define TUNE_GENERAL_EXP(x)          ( 100 * (x) / 100 )

#define TUNE_THIEF_DAMAGE(x)         (x)
#define TUNE_NINJA_DAMAGE(x)         (x)
#define TUNE_FIGHTER_DAMAGE(x)       (x)
// Tune has been added to Priests.
#define TUNE_PRIEST_DAMAGE(x)        (x)
// Tune has been added to Mages.
#define TUNE_MAGE_DAMAGE(x)          (x)
#define TUNE_NECRO_DAMAGE(x)         (x)

// This is how it will be defined when all the guilds have included the
// respective macros in their code...
//#define TUNE_NECRO_DAMAGE(x)         (TUNE_GENERAL_DAMAGE(x))

#endif /* _TUNE_H */
