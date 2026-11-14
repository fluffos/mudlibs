// SilberLand MUDlib
//
// sys/weapon.h -- weapon header
//
// $Date: 1997/10/09 01:01:52 $
/* $Revision: 1.7 $
 * $Log: weapon.h,v $
 * Revision 1.7  1997/10/09 01:01:52  Woody
 * P_WC_FIXFACTOR
 *
 * Revision 1.6  1997/08/25 11:58:34  Feyaria
 * P_SPECIAL_WC eingefuehrt
 *
 * Revision 1.5  1997/04/19 20:56:52  Feyaria
 * P_WIRELD_RESTRIVCTIONS
 *
 * Revision 1.4  1997/03/31 14:05:09  Woody
 * prepared for revision control
 *
 * Revision 1.3  1996/10/27  Woody
 * P_WIELD_FUNC, P_UNWIELD_FUNC, P_HIT_FUNC
 *
 * Revision 1.2  1996/09/21  12:30:00  Woody
 * P_WIELDED_TEXT, P_(UN)WIELD_TEXT eingefuehrt
 *
 * Revision 1.1  1994/03/09  21:38:36  Hate
 * Initial revision
 *
 * Revision 1.1  1994/03/09  21:38:36  Hate
 * Initial revision
 *
 */
 
#ifndef __WEAPON_H__
#define __WEAPON_H__

// properties

#define P_NR_HANDS     "nr_hands"
#define P_WC           "wc"
#define P_WC_FIXFACTOR "wc_fixfactor"
#define P_WEAPON_TYPE  "weapon_type"
#define P_DAM_TYPE     "dam_type"
#define P_WIELDED      "wielded"
#define P_WIELDED_TEXT "wielded_text"
#define P_WIELD_TEXT   "wield_text"
#define P_UNWIELD_TEXT "unwield_text"
#define P_WIELD_FUNC   "wield_func"
#define P_UNWIELD_FUNC "unwield_func"
#define P_HIT_FUNC     "hit_func"
#define P_SPECIAL_WC    "special_wc"
#define P_WIELD_RESTRICTIONS "wield_restrictions"

#endif // __WEAPON_H__

#ifdef NEED_PROTOTYPES

#ifndef __WEAPON_H_PROTO__
#define __WEAPON_H_PROTO__

// prototypes

varargs int wield(string str, int silent);
int unwield(string str);
varargs int wield_me(int silent);
varargs int DoUnwield(int silent);
int QueryDamage(object enemy);

// compatibility prototypes for old functions; use properties instead!

object SetWieldFunc(object ob);
object QueryWieldFunc();
object SetUnwieldFunc(object ob);
object QueryUnwieldFunc();
object SetHitFunc(object ob);
object QueryHitFunc();
object QueryWielded();

#endif // __WEAPON_H_PROTO__

#endif	// NEED_PROTOYPES
