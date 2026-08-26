// Chernobog & Titania (2/25/22)
// Wailing Isle - Beach

#include <std.h>
#include "../defs.h"
inherit INH+"beach";

void create(){
    ::create();
    set_exits(([
        "north" : ROOMS"beach3",
        "northwest" : ROOMS"marketsquare",
        "south" : ROOMS"beach1",
        ]));
    set_pre_exit_functions(({"northwest"}),({"going_up"}));
}

int going_up(){
    object player;
    player = this_player();
    
    tell_object(player, "%^RESET%^%^CRST%^%^C094%^You follow the steep %^C100%^s%^C101%^e%^C102%^r%^C103%^p%^C102%^e%^C101%^n%^C100%^t%^C101%^i%^C102%^n%^C103%^e %^C102%^c%^C101%^u%^C101%^r%^C100%^v%^C101%^e %^RESET%^%^C094%^of the road up to the %^C109%^market%^C094%^.%^CRST%^\n");
    return 1;
}

