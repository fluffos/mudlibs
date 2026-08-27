/*
 * /sys/poison_types.h
 *
 * This file defines the different types of damage that a poison can have.
 *
 * POISON_USER_DEF Define your own type of poison. Use the function
 *                 special_damage to define it.
 *
 * POISON_HP       Take HP from the poisonee
 * POISON_MANA     Take mana from the poisonee
 * POISON_FATIGUE  Make the poisonee more tired
 * POISON_STAT     (Temporaryly) take stats from the poisonee
 */

#ifndef POISON_TYPES
#define POISON_TYPES

#define POISON_USER_DEF -1
#define POISON_HP        0
#define POISON_MANA      1
#define POISON_FATIGUE   2
#define POISON_STAT      3

#endif
