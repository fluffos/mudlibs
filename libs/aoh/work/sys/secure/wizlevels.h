#ifndef _SECURE_WIZLEVELS_
#define _SECURE_WIZLEVELS_ 1

/*------------------------------------------------------------------------
 * /sys/secure/wizlevels.h -- User level definitions
 *
 * Copyright (C) 1998 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *------------------------------------------------------------------------
 * This file defines the various user types and some macros dealing with
 * them. Also included are High Level Player macros.
 * See /doc/concepts/levels for more information.
 *
 * Actually, 'wizlevels' is a misnamer as they are in fact 'userlevels',
 * but people got used to the name.
 *-------------------------------------------------------------------------
 */

/* Types are expressed in numerical values for ease of use. */

#define LVL_PLAYER  0  // Normal players
#define LVL_ANCIENT 1  // Retired players
#define LVL_WIZARD  2  // Wizards


// Predicates for user types
#define IS_PLAYER(x)   (LVL_PLAYER == query_user_level(x) || (x)->Query("NoWiz"))
#define IS_IMMORTAL(x) (LVL_PLAYER != query_user_level(x))
#define IS_ANCIENT(x)  (LVL_ANCIENT == query_user_level(x))
#define IS_WIZARD(x)   (LVL_WIZARD == query_user_level(x))

// Long and short names for the wizard types, so changes are easier
// later on.
#define PLAYER_S  "Pl"
#define PLAYER_L  "Player"
#define ANCIENT_S "Anc"
#define ANCIENT_L "Ancient"
#define WIZARD_S  "Wiz"
#define WIZARD_L  "Wizard"

/* High Level Player stuff */

#define RLVL_HLP  20  // Minimum P_LEVEL required for High Level Playerness

#define IS_HLP(x) (LVL_PLAYER == query_user_level(x) && RLVL_HLP <= ({int})(x)->QueryRealLevel())


#endif /* _SECURE_WIZLEVELS_ */
