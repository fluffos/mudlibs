#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("tobacco");
   set_id(({ "weed", "pipeweed", "pipe weed", "pipe-weed" }));
   set_short("pipe-weed");
   set_long("Crispy and dry, good with a pipe of some sort.");
    set_curr_value("copper", 52);
   set_weight(1);
}

void smoke_me(object o) {
   if (!o) return;
   message("smoke", "%^RESET%^%^YELLOW%^Y%^RESET%^%^ORANGE%^o%^YELLOW%^u "
     "%^RESET%^%^ORANGE%^l%^YELLOW%^o%^RESET%^%^ORANGE%^o%^YELLOW%^k%^RESET%^%^ORANGE%^ "
     "a%^YELLOW%^r%^RESET%^%^ORANGE%^o%^YELLOW%^u%^RESET%^%^ORANGE%^n%^YELLOW%^d "
     "%^RESET%^%^ORANGE%^a%^YELLOW%^n%^RESET%^%^ORANGE%^d "
     "%^YELLOW%^l%^RESET%^%^ORANGE%^a%^YELLOW%^u%^RESET%^%^ORANGE%^g%^YELLOW%^h%^RESET%^%^ORANGE%^ "
     "h%^YELLOW%^y%^RESET%^%^ORANGE%^s%^YELLOW%^t%^RESET%^%^ORANGE%^e%^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW%^c%^RESET%^%^ORANGE%^a%^YELLOW%^l%^RESET%^%^ORANGE%^l%^YELLOW%^y%^RESET%^%^ORANGE%^.", o);
   message("smoking", o->query_cap_name()+" looks around and laughs.", environment(o), o);
   o->add_hp(random(25));
   o->add_stat_bonus("dexterity", 2, 10);
   o->add_stat_bonus("intelligence", -2, 10);
}

int can_smoke() { return 1; }
