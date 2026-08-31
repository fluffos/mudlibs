#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("female");
   set_name("cockroach");
   set_id( ({ "bug","cockroach"}) );
   set_short("A cockroach");
   set_long("Just an UGLY bug.");
   set_level(28);
   set_body_type("insctwgd");
   set_alignment(200);
   set_race("insect");
   set_class("fighter");
   set_skill("attack",200);
   set_skill("melee",200);

      }

int mush(string str) {
   if (!str || present(str, environment(this_object())) != this_object())
     return notify_fail("Squish what?\n");
   write("You squish the filthy cockroach!");
   say(this_player()->query_cap_name()+" squishes a cockroach!", this_player());
   this_object()->cease_all_attacks();
   this_object()->stop_hunting();
   this_object()->die();
   return 1;
}

void init() {
 ::init();
   add_action("mush", "squish");
}
