// gangcha.c

#include <weapon.h>

inherit STAFF;


void create()
{
        set_name("九股托天叉", ({ "tuotian fork","fork", "cha"}) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 50);
		set("no_sell", 1);
		set("long", "一根九股盘龙藤扭成的利叉，上面刻了些符篆。\n");
		set("wield_msg", "$N从背后拿出把哗哗做响的铁叉来。\n");
		set("unwield_msg", "$N把$n又放回背后。\n");
                set("material", "iron");
        }
        init_staff(660);
        setup();
}


