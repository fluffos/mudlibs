/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : _weapon.c
 * Author : Sinji@RevivalWorld
 * Date   : 2005-01-08
 * Note   : Refer to /std/inherit/feature/living/_combat_liv.c
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */

#include <ansi.h>
#include <message.h>

int is_weapon()
{
	return 1;
}
int is_singlehand()
{
	return query("hands", this_object()) == 1 ? 1:0;
}
void attack(object me, object target)
{
	if( !me || !target ) return;
	target->receive_attack(me, random(10)*10);
}
int allowable_wield(object ob)
{
	return 1;
}
int allowable_unwield(object ob)
{
	return 1;
}
// Refer to /std/inherit/feature/living/_combat_liv.c
void set_wield(int flag)
{
	set_temp("is_wield", flag, this_object());
}
int is_wield()
{
	return query_temp("is_wield", this_object());
}
