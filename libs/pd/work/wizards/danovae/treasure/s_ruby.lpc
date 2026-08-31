/*      ------- Danovae - Dec.24.2001 ------- */
/*      ------- Summoning Stone: Ruby ------- */

#include <std.h>
inherit OBJECT;
int uses;

void create() {
   ::create();
   uses = 1;
   set_name("summoning stone");
   set_id( ({ "stone","summoning stone","ruby" }) );
   set_property("magic item", ({ "summon","salamander" }) );
   set_short(
     "%^BOLD%^%^BLACK%^Dimension%^RED%^ Ruby%^RESET%^"
   );
   set_long(
     "A ruby with incredible cut dimensions. It appears "
     "almost as if there is another world inside of it. "
     "\n"
     "Perhaps it has some magical connection."
   );
   set_mass(3);
   set_curr_value("gold", 200);
}

void init() {
   ::init();
   add_action("summon","summon");
}

int summon(string str) {
   object tp, ob;
   int wis, sum;

   if((int)this_player()->query_mp() < 50) {
     notify_fail("You do not have the energy do to that.\n");
     return 0;
   }
   if(!present(this_object(), this_player())) return 0;
   wis = (int)this_player()->query_stats("wisdom");

   tp = this_player();


   if((str == "salamander") && (tp->query_mp() >= 50) && (wis >= 20)) {
     sum = 15;
     if (present("fire spirit", environment(this_player())))
     return notify_fail("You cannot do that.\n");
       if (random(sum) > random(wis)) {
       write("Your call goes unanswered.\n");
       return 1;
     }
     write("%^BOLD%^%^RED%^A salamander appears in a burst of flames.%^RESET%^");
     new("/wizards/danovae/treasure/summoned/sala")->move(environment(tp));
     }
     else { write("Summon what?\n"); return 1; }

   ob = present(str, environment(tp));
   write("You summon a creature from the plane of fire.");
   say(this_player()->query_cap_name()+" summons a creature from the plane of fire.", ob);
   ob->set_owner(tp);
   this_player()->add_mp(-(sum*2 + random(sum)));

   uses--;
   if(uses < 1)
   {
     write("Your ruby shatters into a thousand pieces.\n");
     this_object()->remove();
     return 1;
   }
  return 1;

}



