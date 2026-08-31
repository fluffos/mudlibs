#include <std.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("pistol");
   set_short("a temporal machine gun");
   set_long("A semi-automatic machine gun of pure magic. Bullets "
	"appear and are launched out of it. Great for a hunt!");
   set_id(({ "gun", "machine gun", "temporal machine gun" }));
   set_type("blunt");
   set_wc(0);
}

int fire(string str) {
   int i;
   string what, who, trig = 0;
   object ob, igor, env, *all = ({ }), *ppl = ({ });
   if (sscanf(str, "%s with %s", who, what) == 2) {
     if (present(what, this_player()) != this_object()) return 
	notify_fail("Shoot who with what?\n");
   } else who = str;
   ob = present(who, environment(this_player()));
   if (ob) say(this_player()->query_cap_name()+" points a "
	"temporal machine gun at "+
	ob->query_cap_name()+" and fires!", this_player());
   if (!ob) {
     if (environment(this_player())->query_exit(who) == 
	"/d/standard/void") return notify_fail("You do not see that "
						"here.\n");
     igor = new("/wizards/inferno/igor");
     igor->move(environment(this_player())->query_exit(who));
     env = environment(igor);
     igor->remove();
     say(this_player()->query_cap_name()+" points an temporal machine "
	"gun "+who+" and "
	 "fires!", this_player());
     all = all_inventory(env);
     i = sizeof(all);
     while (i--) {
	if (all[i]->is_living()) ppl += ({ all[i] });
     }
     if (!sizeof(ppl)) return notify_fail("A stray bullet flys "+who+
					  " and hits the ground!\n");
     if (random(4) <= 1) { tell_object(env, "A stray bullet flys into the "
					    "room and hits the ground!");
			   write("The stray bullet flys "+who+" and hits "
				 "the ground.");
			   return 1; }
     i = random(sizeof(ppl));
     ob = ppl[i];
     tell_object(ob, "A stray bullet flys into the room and clips you!");
     say("A stray bullet flys into the room and clips "+ob->query_cap_name()
	+"!", ob);
     ob->damage(random(100) + 1000, "bullet");
     write("The stray bullet flys "+who+" and clips "
	+ob->query_cap_name()+"!");
     if (ob->query_hp() <= 0) ob->die();
     return 1;
   }
   message("info", "Bullets fly at "+ob->query_cap_name()+", slicing "
	"into "+
	ob->query_title_gender()+" body!", environment(this_player()));
   ob->force_me("scream in pain");
   ob->damage(random(300) + 1000, "bullet");
   if (ob->query_hp() <= 0) ob->die();

   return 1;
}

void init() {
 ::init();
   add_action("fire",  "shoot");
}
