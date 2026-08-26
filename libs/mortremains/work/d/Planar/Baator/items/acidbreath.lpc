/*
** FILE: obsword.c
** PURPOSE: Example of set_bonus() function.
** CREATOR: Cyanide@Nightfall's Keep
** CHANGES:
**    9 Apr 97    Cyanide    Created the file.
**   18 Jun 97    Cyanide    Updated the weapon to include the new
**                           set_weapon_type function.
*/

#include <mudlib.h>

inherit OBJECT;
int count_down(int dmg, int rep);
void create() {
	set("mass", 0);
	set("id", ({ "acid" }) );
set("invisible", 2);
   }

int begin(int dmg){
object target;

target = environment(this_object());

if (!living(target)) return 1;

call_out("count_down", 1, dmg, 1);
return 1;
}
int count_down(int dmg, int rep){
object target;

target = environment(this_object());

if (!living(target)) return 1;

target->receive_damage(dmg, "acid");

if (rep == 3) this_object()->remove();
dmg /= 2;
rep +=1;
call_out("count_down", 1, dmg, rep);
return 1;
}