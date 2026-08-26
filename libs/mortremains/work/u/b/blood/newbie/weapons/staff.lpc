#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "blood");
    set("short", "Ironwood Staff");
    set("long", @Endtext
This staff is about 6 ft. long and it has 2 bands of platinum on each end.
Streaks of flame, walls of water and long spikes of rock have been carved
into this staff, to symbolize the elements from which it came.
Endtext
    );
    set("id", ({ "staff", "ironwood staff" }) );
    set_weapon_type("quarterstaff");
    set("name", "staff");
    set_verbs( ({ "attack" , "swing at" , "thrust at" }) );
    set("nosecond",1);         
    set_bonus(1);
    set("value", 2000);

}   
