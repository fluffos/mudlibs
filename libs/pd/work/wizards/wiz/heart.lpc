#include <std.h>
inherit OBJECT;

void create() {
 ::create();
 set_name("heart");
 set_short("%^BOLD%^%^WHITE%^a "
   "gl%^RESET%^%^CYAN%^as%^BOLD%^%^WHITE%^s%^RESET%^%^CYAN%^ "
   "he%^BOLD%^%^WHITE%^art");
 set_long("The glass heart is a replica of a human heart. It pulses softly in "
    "your hand. The heart beats to the same rythm as your own heart.%^BLACK%^ "
    "Something tells you not to loose or drop this cursed heart!%^RESET%^");
 set_id( ({ "glass heart", "heart" }) );
 set_properties( ([ "no steal" : 1 ]) );
 set_mass(2);
 set_value(0);
}

void set_die() { 
   object ob, tp, to;

   tp = this_player();
   ob = tp->query_current_attacker();

//   if(!ob->is_monster()) {
//     write("%^BOLD%^The glass heart shatters into a million pieces!");
//     to = new("/wizards/wiz/death");
//     to->move(this_player());
//     to->trig_death();
//     this_object()->remove();
//     return;
//   }
   write("%^BLACK%^A terrible shadow passes before your soul as you are brought "
     "into the clutches of death!");
   tp->heal(1000000);
   write("%^BOLD%^The glass heart beats as one with yours and life enters your "
     "body.");
   write("You raise the glass heart above your head.");
   write("%^YELLOW%^A beam of energy shoots through "+ob->query_cap_name()+"'s "
     "chest!");
   ob->die();
}

int
query_auto_load()
{
    if (wizardp(this_player()))
        return 1;
    return 0;
}

int drop(string str) {
   object bla;
   if (!str) return 0;
   if (present(str, this_player()) != this_object()) return 0;
   say(this_player()->query_cap_name()+" drops a glass heart!", this_player());
   say("%^BOLD%^The heart shatters into a thousand tiny pieces!", this_player());
   say("%^RED%^"+this_player()->query_cap_name()+"'s heart stops.",
     this_player());
   write("%^BOLD%^The heart shatters into a thousand tiny pieces!");
   write("%^RED%^Your heart stops.");
   bla = new("/wizards/wiz/death");                     
   bla->move(this_player());
   bla->trig_death();
   this_object()->remove();
   return 1;
}

void init() {
 ::init();
   add_action("drop", "drop");
}
