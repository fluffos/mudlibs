#include <std.h>
#include <lodos.h>
inherit OBJECT;

void create() {
 ::create();
   set_short("a large, black mirror");
   set_name("mirror");
   set_long("The mirror is a swirling, misty black surface. The "
     "reflection in it is very dim, making it seem as though the "
     "mirror is used for some other purpose than a conventional mirror. "
     "The mirror is right behind the "
     "altar and around it is the only spot in the room where there is "
     "no blood.");
   set_weight(1);
   set_value(0);
   set_id(({ "mirror", "black mirror", "large black mirror" }));
}

int get() { return 0; }

void enter(object ob) {
   if (ob->query_ghost()) return;
   message("info", "You enter the mirror's surface.", ob);
   ob->move_player(ROOMS"secret2", "mirror");
}

void hurt(object ob) {
   if (environment(ob) != environment(this_object())) return 0;
   message("info", "%^BOLD%^%^RED%^A sharp, wracking pain fills your body!", ob);
   tell_room(environment(ob), ob->query_cap_name()+" screams in pain!",
      ({ ob }));
   ob->damage(random(100), "unholy");
   call_out("enter", 1, ob);
}

int portal(string str) {
   if (!str || str != "mirror") return 0;
   write("You take a step towards the mirror and brace yourself..");
   call_out("hurt", 1, this_player());
   return 1;
}

void init() {
 ::init();
//   add_action("portal", "enter");
}
