// yaobang.c 狼牙妖棒

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(RED"狼牙妖棒"NOR, ({"langya yaobang","yaobang", "bang"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一把狼牙棒，是大天妖惯用的兵器\n");
                set("unit", "把");
		set("wield_msg","$n"RED"「呼」地抽出$N捧在手中，身后出现大天妖的幻影。\n"NOR);
		set("unwield_msg",RED"$N将手中$n"NOR+RED"一收，插在背后！\n"NOR);
                set("value", 100);
		set("weapon_prop/courage", 100);
		set("replace_file", "/d/xiyou/sanjie/obj/bintiegun");
        }
        init_staff(300);
        setup();
}
