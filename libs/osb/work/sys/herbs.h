#ifndef _HERBS_H_
#define _HERBS_H_

/*--------------------------------------------------------------------------
 * /sys/herbs.h --  Standard herb macros
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */
 
// Filepaths
#define HERB "/std/herb"
#define HERBS(x)    "/obj/herbs/"+(x)

#define P_HERB           "Herb"            // -> properties.h
#define P_HERB_NAME      "HerbName"
#define P_HERB_TYPE      "HerbType"        // std types listed below
#define P_HERB_STRENGTH  "HerbStrength"    // -> properties.h
#define P_HERB_EAT_MSG   "HerbEatMsg"      // text after eating
#define P_HERB_FUN       "HerbFun"         // fun to call after eating

#define SK_HERB          "Herbalism"       // -> skills.h

// Standard herb types
#define HERB_HEAL_HP        1
#define HERB_HEAL_SP        2 
#define HERB_HEAL_EP        3
#define HERB_HEAL_POISON    4
#define HERB_HURT_HP        5
#define HERB_HURT_SP        6
#define HERB_HURT_EP        7
#define HERB_HURT_POISON    8
#define HERB_SATIATE        9
#define HERB_INTOXICATE    10
#define HERB_SLEEP         11
#define HERB_CUSTOM        12           // some custom action

#define HERB_DEFAULT       13           // does no action

// The following herbs are searchable when added as property
// mapping for the AddSkill(SK_SEARCH,...WOODHERBS(1000,1000)
#define WOODHERBS(x,y) "flu":"/obj/herbs/flu_herb";\
(x)/1000;300*(y)/1000;0,\
"healing":"/obj/herbs/example_herb";(x)/1000;700*(y)/1000;0



#endif
