#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("weed");
   set_id(({ "weed" }));
   set_short("dried weed roots");
   set_long("These are the roots of some sort of weed. The roots are "
     "about eight inches long. They are dry enough to be smoked.");
   set_weight(1);
    set_curr_value("copper", 52);
}

void smoke_me(object o) {
   if (!o) return;
   message("smoke", "You inhale the weed root smoke. It goes down "
     "smooth, but you cough anyway. This is some strong stuff!", o);
   message("smoking", o->query_cap_name()+" inhales weed root smoke. "
     +o->query_cap_name()+" coughs loudly.", environment(o), o);
   message("smoke", "You stumble around, dizzly.", o);
   o->add_hp(random(55));
   o->add_stat_bonus("constitution", 4, 13);
   o->add_stat_bonus("dexterity", -2, 10);
   o->add_stat_bonus("intelligence", -2, 10);
}

int can_smoke() { return 1; }
