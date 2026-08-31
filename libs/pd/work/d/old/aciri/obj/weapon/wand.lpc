#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("wand");
   set_short("%^RESET%^%^CYAN%^an %^BOLD%^ice%^RESET%^%^CYAN%^ "
     "wand%^RESET%^");
   set_long("The shaft of the wand is a light blue metallic-feeling "
     "substance. The shaft is very smooth and makes for a good grip. "
     "Atop the wand is a crystal that looks like ice. An intense cold "
     "radiates from the ice crystal. The wand has a magical feel to "
     "it.");
   set_weight(6);
   set_id(({ "wand", "ice wand" }));
   set_property("magic item", ({ "point" }));
   set_wc(5);
   set_type("blunt");
   set_value(421);
}

int query_auto_load() {
   if (this_player()->query_level() >= 30) return 3;
}

int point_me(string str) {
   string s;
   object ob, tp, env;

   tp = this_player();
   env = environment(this_player());
   if (!str) {
     ob = tp->query_current_attacker();
     if (!ob) return notify_fail("Point wand at whom?\n");
   } else {
     if (!sscanf(str, "wand at %s", s))
       return notify_fail("Point wand at whom?\n");
     if (!ob = present(s, env))
       return notify_fail("You do not see "+capitalize(s)+" here.\n");
   }
   if (env->query_property("no attack") ||
       env->query_property("no magic"))
     return notify_fail("Great powers prevent your malice.\n");
   if (tp->query_disable() || tp->query_magic_round())
     return notify_fail("You too busy to do this.\n");
   tp->set_disable(1);
   tp->set_magic_round(1);
   write("You point the wand at "+ob->query_cap_name()+".");
   tell_room(env, tp->query_cap_name()+" 
}

void init() {
 ::init();
   add_action("point_me", "point");
}
