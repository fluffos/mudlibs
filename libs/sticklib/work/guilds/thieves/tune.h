#ifndef _TUNE_H
#define _TUNE_H

// Chance that stab fails regardless of skill or situation
#define _STAB_FAILURE		(random(1000) < 27)

// Chance that a critical stab adds bleeding wound
#define _STAB_BLEED		(random(100) < 20)

// Random stab training, for successful stab
#define _STAB_S_RND		(random(100) < 55)

// Random stab training, for failed stab
#define _STAB_F_RND		(random(100) > 69)

// Constitution check; if true, poison gets through
#define _POISON_SAVE(c)		(random(120) > (c))

// Stab fumble chance; there already is only 50% chance to try this
#define _STAB_FUMBLE		(random(100) < 20)


// Tth skill divider for success number, and the random part divider
#define _TTH_SK_DIV		600
#define _TTH_SK_RND_DIV		325

// Weapon bounce/stuck chance
#define _TTH_WPN_STUCK		(random(1000) < 27)

// Random element of tth training
#define _TTH_T_RND		(random(100) < 7)


// Mtth automatic failure chance
#define _MTTH_SUCCESS        (random(100) < 93)


// Minimum player level to steal from
#define _STEAL_MIN_LVL		2

// Small level thieves can steal from even 1st level players
#define _STEAL_SMALL_THIEF	5

// Spell point cost for stealing
#define _STEAL_SP		10

// Chance that the steal is not an automatic failure
#define _STEAL_SUCCESS		(random(100) < 75)

// Sweat penalty to stealing success
#define _STEAL_SWEAT		(10 + random(100))

// Troll stealing penalty
#define _STEAL_TROLL		random(100)

// Invisible thief bonus
#define _STEAL_INVIS		25

// Random element of steal training
#define _STEAL_T_RND		(random(100) < 28)


#endif /* _TUNE_H */
