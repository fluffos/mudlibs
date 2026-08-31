#include <std.h>
#include "ether.h"
inherit ARMOUR;

void create() {
    :: create();

    set_name("kimono");
    set_short("%^BLUE%^s%^BOLD%^il%^RESET%^%^MAGENTA%^k %^BOLD%^ki"
"%^RESET%^%^MAGENTA%^m%^BOLD%^%^BLUE%^on%^RESET%^%^BLUE%^o%^RESET%^");
    set_long("%^CYAN%^This is a beautiful silk kimono, adorned with"
" %^BOLD%^blue sakura blossoms%^RESET%^%^CYAN%^. It was made "
"especially for Kumi, out of a special silk.%^RESET%^");
    set_id(({"kimono"}));
    set_ac(1);
    set_weight(20);
    set_type("blanket");
    set_limbs(({"torso", "left arm", "right arm"}));
}

int query_auto_load() { 
    if(this_player()->query_level() < 50) return 0; 
    return 1;
}
void welcome()
{
    call_out("wear", 3, "kimono");
}
void init_arg(mixed *arg) {
    welcome();
}
