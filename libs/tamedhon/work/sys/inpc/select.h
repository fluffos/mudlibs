// SilberLand MUDlib
//
// sys/inpc/select.h -- Defines zur Wahl der Ausruestung
//
// $Date: 1997/03/31 14:12:59 $
/* $Revision: 1.1 $
 * $Log: select.h,v $
 * Revision 1.1  1997/03/31 14:12:59  Woody
 * prepared for revision control
 *
 */

#ifndef __INPC_SELECT_H__
#define __INPC_SELECT_H__

#define OT_WEAPON "weapon"
#define OT_COMBAT_OBJECT "combat_object"
#define OT_MISC "misc_objects"
#define INPC_BEST_WEAPON_ID "inpc_best_weapon"
#define INPC_BEST_SHIELD_ID "inpc_best_shield"

#endif

#ifdef NEED_PROTOTYPES
#ifndef __INPC_SELECT_PROTO__
#define __INPC_SELECT_PROTO__

int eval_wepon(object ob);
int eval_armour(object ob);
int eval_combat_object(object ob, mapping vals, object enemy);

object find_best_weapon(mixed from);
object find_best_armour(mixed from, mixed typ);
object *find_best_armours(mixed from);
varargs string find_best_combat_command(mixed from, object enemy, mapping pref);

varargs int wield_best_weapon(mixed from);
varargs int wear_best_armours(mixed from);
varargs int use_best_combat_command(mixed enemy, mixed from, mapping pref);


#endif
#endif
