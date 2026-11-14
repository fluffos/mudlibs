// SilberLand MUDlib
//
// sys/moving.h -- object moving defines
//
// $Date: 2010/06/14 11:32:24 $
/* $Revision: 1.8 $
 * $Log: moving.h,v $
 * Revision 1.8  2010/06/14 11:32:24  Woody
 * P_NOMOVE definiert; allgemein umformatiert
 *
 * Revision 1.7  2000/05/05 08:14:31  Angrox
 * NO_STARGATE_TPORT added
 *
 * Revision 1.6  1999/03/01 20:47:57  Woody
 * ME_TOO_MUCH definiert
 *
 * Revision 1.5  1997/11/06 12:57:51  Woody
 * Da es nun 'raste' gibt, die div. MV Werte wieder etwas reduziert
 *
 * Revision 1.4  1997/07/18 21:28:19  Woody
 * MVP Konstanten etwas gelockert (Basiswert: 600 statt 500,
 * Hochidlen 60 bzw. 8 im Kampf statt 50 bzw. 5 bisher)
 *
 * Revision 1.3  1997/06/25 12:13:57  Woody
 * Movement Points Konstanten, ME_CANT_LEAVE_ENV
 *
 * Revision 1.2  1997/04/12 20:00:23  Feyaria
 * REJECT_DESTRUCT eingefuehrt
 *
 * Revision 1.1  1997/03/31 13:10:16  Woody
 * prepared for revision control
 *
 */

#ifndef __MOVING_H__
#define __MOVING_H__

/*
 * moving.h
 * How objects are moving around and reasons why they cant do it.
 */

/* Methods to move objects */
#define M_GO             1  // we walk around
#define M_TPORT        128  // We teleport to another place
#define M_NOCHECK        2  // just plain move it without any checks
#define M_GET            4  // obj geht von nonliving zu living
#define M_PUT            8  // obj geht von living zu nonliving
#define M_GIVE          16  // obj geht von living zu living
#define M_SILENT        32  // obj soll ohne meldung ausgezogen werden
#define M_NO_ATTACK    512  // Kein Begruessungsschlag
#define M_NO_SHOW      256  // Zeige nicht die Room-Descr beim ankommen

/* std/unit Flags to control split behaviour */
#define M_MOVE_ALL      32
#define M_FORCE_SPLIT   64

/* Errors when moving things */
#define ME_PLAYER           -1  // Hey, I'm a player and cant be simply carried away
#define ME_TOO_HEAVY        -2  // Cant move into container because I'm too heavy
#define ME_CANT_TPORT_IN    -3  // Cant teleport there !
#define ME_CANT_TPORT_OUT   -4  // Cant teleport from here !
#define ME_CANT_BE_DROPPED  -5  // You cant drop the feel... this thing
#define ME_CANT_BE_TAKEN    -6  // Nope, you cannot take me
#define ME_CANT_BE_INSERTED -7  // Container prevents me from inserting
#define ME_CANT_LEAVE_ENV   -8  // Container prevents me from leaving
#define ME_TOO_MUCH         -9  // Container has got enough objects

#define NO_TPORT          1
#define NO_TPORT_IN       2
#define NO_TPORT_OUT      4
#define NO_STARGATE_TPORT 8

/* Ablehnreaktionen von NPCs */
#define REJECT_DROP     "reject_drop"
#define REJECT_GIVE     "reject_give"
#define REJECT_KEEP     "reject_keep"
#define REJECT_DESTRUCT "reject_destruct"

/* Bewegungspunktesystem - Properties */

#define P_MV            "mv"          // Movement Points
#define P_MAX_MV        "max_mv"      // Max. Movement Points
#define P_RACE_TT_MV    "race_tt_mv"  // Rassen/Terrain-abhaengige Move-Kosten
#define P_RESTING       "resting"     // waehrend des Rastens
#define P_NOMOVE        "nomove"      // Regulaere Fortbewegung blockieren (im Living)

#define ME_TOO_EXHAUSTED    -10       // zu erschoepft
#define ME_RESTING          -11       // aber ich raste doch noch!
#define ME_CANT_MOVE        -12       // gehen/bewegen (move()) nicht moeglich

#define MVP_DEFAULT_COST        5
#define MVP_GAIN_NORMAL         50
#define MVP_GAIN_REST           120
#define MVP_GAIN_INFIGHT        4

// #define L_OFF                22
#define MVP_BASE                600
#define MVP_CON_FACTOR          25

#define DELAY_MV                3

#endif  // __MOVING_H__

