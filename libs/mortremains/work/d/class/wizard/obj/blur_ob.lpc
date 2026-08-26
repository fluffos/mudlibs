/*
** FILE:        blur_ob.c
** PURPOSE:     Spell object for mages' "blur" spell.
** COST:        12 SP
** EFFECTS:     Gives the caster 2 magical points of armor.
** DURATION:    1 minute/level.
** CREDITS: 
**    20 Jan 98  Cyanide wrote the spell.
*/               

#include <mudlib.h>

#define ENV environment()
#define ENAME ENV->query("cap_name")

inherit OBJECT;

void create() {
   seteuid(getuid());
   set("id", ({ "#BLUR_OBJECT#" }) );
   set("prevent_drop", 1);
   set("dest_at_die", 1);
}

int begin_spell (object master, int level) {
   if (!master) return 0;

   if (!environment()) return 0;
   if (!level) destruct(this_object());
   set("enchantment", 1);
   set("level", level);
   set("caster", master);
   set("schools", ({ "illusion" }) );

   set("extra_look", "$N's form is shifting and blurred.\n");

   if (environment() && living(environment()))
     environment()->add("magical_defense", 2);
environment()->calc_armor_class();

   call_out("remove", (60*level));
   return 1;
}

int remove() {
	object ob;
	string name;

	if (environment() && living(environment())) {
		environment()->add("magical_defense", -2);
environment()->calc_armor_class();

		ob = environment();
		name = ob->query("cap_name");
		tell_object(ob, "Your blur spell comes to an end.\n");
		tell_room(environment(ob), name +
		  "'s form stops blurring and becomes normal again.\n",
		  ({ ob }) );
	}

   return ::remove();
}



