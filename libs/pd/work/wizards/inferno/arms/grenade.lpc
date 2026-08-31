#include <std.h>
inherit OBJECT;

int pin = 1;

void create() {
 ::create();
   set_name("grenade");
   set_short("%^RESET%^%^GREEN%^a grenade%^RESET%^");
   set_long("");
   set_weight(3);
   set_id(({"grenade"}));
}

void blow_up() {
   object env, cur, *other = ({ }), igor;
   string *exits = ({ });
   int i, x;

   env = environment(this_object());
   if (env->is_living()) {
      tell_object(env, "%^RESET%^%^ORANGE%^BOOOM! %^BOLD%^THE GRENADE "
        "EXPLODES!!!");
      env->add_hp(-200);
      cur = environment(env);
      tell_room(cur, "%^YELLOW%^"+env->query_cap_name()+
        "'s grenade explodes!!!", ({ env }));
      other = all_inventory(cur);
      i = sizeof(other);
      while (i--) {
        if (!other[i]->is_living() && other[i] != env) continue;
        message("fallout", "The explosion rattles your bones!", other[i]);
        other[i]->damage(300);
        if (other[i]->query_hp() < 0) other[i]->die();
      }
      this_object()->remove();
      return;
   }
   tell_object(env, "%^RESET%^%^ORANGE%^BOOOM! %^BOLD%^The grenade explodes!!!");
   tell_object(env, "The explosion rattles your bones!");
   other = all_inventory(env);
   i = sizeof(other);
   while (i--) {
     if (!other[i]->is_living() && other[i] != env) continue;
     other[i]->damage(700);
     if (other[i]->query_hp() < 0) other[i]->die();
   }
   exits = env->query_exits();
   x = sizeof(exits);
   other = ({ });
   while (x--) {
     igor = new("/wizards/inferno/igor");
     igor->move(env->query_exit(exits[x]));
     cur = environment(igor);
     igor->remove();
     other = all_inventory(cur);
     i = sizeof(other);
     while (i--) {
       if (!other[i]->is_living() && other[i] != env) continue;
       message("fallout", "%^RESET%^Flames and shrapnal fly into the room!",
         other[i]);
       other[i]->damage(300);
       if (other[i]->query_hp() < 0) other[i]->die();
     }
   }
   this_object()->remove();
   return;
}

int pull_pin(string str) {
   if (!str || str != "pin") return notify_fail("Pull what?\n");
   write("You pull the pin on the grenade!");
   say(this_player()->query_cap_name()+" pulls the pin on a grenade!!",
     this_player());
   pin = 0;
   call_out("blow_up", 10);
   return 1;
}

int throw(string str) {
   string dir;
   if (!str) return 0;
   if (str == "grenade") {
      write("You toss the grenade!");
      say(this_player()->query_cap_name()+" tosses the grenade!",
        this_player());
      this_object()->move(environment(this_player()));
      return 1;
   }
   if (!sscanf(str, "grenade %s", dir))
     return notify_fail("Toss grenade where?\n");
   if (environment(this_player())->query_exit(dir) == "/d/standard/void")
     return notify_fail("You cannot toss it that way!\n");
   write("You toss the grenade "+dir+"!");
   say(this_player()->query_cap_name()+" tosses the grenade "+dir+"!",
     this_player());
   this_object()->move(environment(this_player())->query_exit(dir));
   tell_room(environment(this_object()), "A grendade slides across the floor!!",
     ({ this_object() }));
   return 1;
}

void init() {
 ::init();
   add_action("pull_pin", "pull");
   add_action("throw", "toss");
}

string query_long() {
   string str;
   str = "The grenade is a small, round object. ";
   if (pin) str += "A small silver pin sticks out of it.";
   else str += "The pin has been pulled!";
   return str;
}

void set_ping(int x) { pin = x; }
