#include <std.h>

inherit STONE;

void create()
{
    ::create();
    set_name("sphere");
    set_short("A %^BOLD%^%^BLUE%^S%^RED%^p%^WHITE%^he%^RED%^r%^BLUE%^e%^RESET%^");
    set_long("A small round sphere made of pure energy, it glows strongly"
     " and you urge to touch it.");
    set_id( ({ "sphere" }) );
    set_action("touch");
    set_remove_mess("%^BOLD%^%^WHITE%^The %^BOLD%^%^BLUE%^S%^RED%^p%^WHITE%^he%^RED%^r%^BLUE%^e %^WHITE%^disintergrates in your hands.%^RESET%^");
    set_levels(({"disapating", "fading", "glowing", "sparkling", "radiating",
"energised" }));
    set_use_mess("%^BOLD%^%^WHITE%^The %^BOLD%^%^BLUE%^S%^RED%^p%^WHITE%^he%^RED%^r%^BLUE%^e %^WHITE%^disintergrates and the energy rushs into your body.%^RESET%^");
    set_mass(1);
    set_value(0);
}
