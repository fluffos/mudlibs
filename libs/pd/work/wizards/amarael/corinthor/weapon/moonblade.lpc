#include <std.h>
inherit WEAPON;

void create() {
   ::create();
     set_name("moonblade");
     set_short("%^BOLD%^BLUE%^M%^RESET%^MAGENTA%^o%^BOLD%^BLUE%^o%^RESET%^MAGENTA%^n%^BOLD%^BLUE%^b%^RESET%^MAGENTA%^l%^BOLD%^BLUE%^a%^RESET%^MAGENTA%^d%^BOLD%^BLUE%^e");
     set_id(({"moonblade"}));
     set_long("The moonblade is a sacred weapon of the elven race, and any whoever wields it is marked as leader of the forest. The blade always reflects moonlight, even indoors and even during day.");
     set_wc(8);
     set_type("blade");
     set_curr_value("gold", random(20)+12);
     set_mass(16);
}

int query_auto_load() {
    if(this_player()->query_race() == "elf") return 1;
    return 0;
}
