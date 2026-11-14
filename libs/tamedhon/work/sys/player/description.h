// SilberLand MUDlib
//
// sys/player/.h -- player description header
//
// $Date: 1997/03/31 15:02:33 $
/* $Revision: 2.1 $
 * $Log: description.h,v $
 *
 * Revision 2.2  2008/01/13 16:00:00  TamTam
 * Augen-/Haar-/Hautfarbe+Racespecial anzeigen in long()
 * P_EYE_COLOR, P_HAIR_COLOR, P_SKIN_COLOR, P_HAIR_STYLE, P_RACE_SPECIAL
 * P_LOOK_INVIS
 *
 * Revision 2.1  1997/03/31 15:02:33  Woody
 * prepared for revision control
 *
 * Revision 2.0  1996/04/17  02:25:00  Woody
 * P_CLASS in thing/description ausgelagert, P_REFERENCE_OBJECT eingefuehrt
 *
 * Revision 1.2  1994/01/18  01:06:32  mud
 * *** empty log message ***
 *
 * Revision 1.2  1994/01/18  01:06:32  mud
 * *** empty log message ***
 *
 * Revision 1.1  1994/01/06  10:46:59  mud
 * Initial revision
 *
 */

#ifndef __PLAYER_DESCRIPTION_H__
#define __PLAYER_DESCRIPTION_H__

// properties

#define P_EXTRA_LOOK				"extralook"
#define P_PRESAY 				"presay"
#define P_TITLE 				"title"
#define P_REFERENCE_OBJECT                      "reference_object"

#define P_LOOK_INVIS				"lookinvis"
#define P_EYE_COLOR                             "eye_color"
#define P_HAIR_STYLE                            "hair_style"
#define P_HAIR_COLOR                            "hair_color"
#define P_SKIN_COLOR                            "skin_color"
#define P_RACE_SPECIAL                          "race_special"
#define P_AVATAR_URI              "p_lib_avataruri"

#endif // __PLAYER_DESCRIPTION_H__

#ifdef NEED_PROTOTYPES

#ifndef __PLAYER_DESCRIPTION_H_PROTO__
#define __PLAYER_DESCRIPTION_H_PROTO__

// prototypes
// no prototypes

#endif // __PLAYER_DESCRIPTION_H_PROTO__

#endif	// NEED_PROTOYPES
