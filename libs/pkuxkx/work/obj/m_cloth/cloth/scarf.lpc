#pragma save_binary
#include <ansi.h>
#include <armor.h>
inherit M_CLOTH;
void create()
{
        set_name( COR "订作的" NOR, ({ "order" }) );
		set("unit", "条");
        set("no_drop",1);
		set("no_get",1);
       	set("make_time","zgtl_tanbin");
		set("origin","原料");
		set("timestamp","STAMP");
		set("maker","caifeng");
    	set("owner","fengyun");
    	set("level",1);
		set("armor_type", TYPE_NECK);
		set_desc();
	setup();
}
void owner_is_killed()
{
        write(HIY"只见一阵布帛撕裂的响声，"+query("name")+HIY"裂成碎片，随风飘散。\n"NOR);
        destruct(this_object());
}
