#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>
#include <sanguo.h>
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
inherit M_VALUE;
void setup()
{
    ::mudlib_setup();
    set_unit("只");
    set_id("listenring", HIG+"结婚戒指"+NOR);
    add_id("ring");
    set_in_room_desc(HIG+"结婚戒指"+NOR+"(listen's ring)");
    set_long("这是李大和小草的定情信物。");
    set_gettable(1);
	set_slot(HANDS);
	set_wearmsg("$N深情地把$o套在自己的无名指上。\n");
	set_removemsg("$N小心地把$o放回锦盒中。\n");
    set_attack_ability(100);
	set_defence_power(40);
    set_defence_ability(100);
    set_value(-1);
    set_currency_type("gold"); 
}
