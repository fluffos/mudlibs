#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("tatoo");
   set_short("");
   set_id( ({ "tatoo" }));
   set_long("A tatoo of a black skull amidst crimson hellfire.");
   set_weight(0);
}

int query_auto_load() { return 1; }

int drop() { return 1; }

string extra_look() {
    string ob;
    object o;
    ob = environment(this_object())->query_cap_name();
    o = environment(this_object());
    return "%^BOLD%^%^WHITE%^"+ob+" has a tatoo "
      "of a %^BOLD%^%^BLACK%^black skull %^BOLD%^%^WHITE%^amidst "
      "%^RESET%^%^ORANGE%^c%^RED%^r%^ORANGE%^i%^RED%^m%^ORANGE%^s%^RED%^o%^ORANGE%^n "
      "%^RED%^h%^ORANGE%^e%^RED%^l%^ORANGE%^l%^RED%^f%^ORANGE%^"
      "%^ORANGE%^i%^RED%^r%^ORANGE%^e%^BOLD%^%^WHITE%^ across "
      +o->query_title_gender()+" back.%^RESET%^\n";
}
