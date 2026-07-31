// jingang-zhao.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;
//inherit F_UNIQUE;
void create()
{
        set_name(HIY"乌金背心"NOR, ({ "wujin beixin", "wujin", "beixin" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "黑黝黝的一件背心，拿在手里沉甸甸的，是用乌金丝、头发、和金丝猴毛混同织成,
任何厉害的兵刃都伤他不得。\n");
                set("material", "silk");
                set("unit", "件");
                //set("unique", 1);
		  //set("treasure", 1);
                set("value", 1000000);
                set("wear_msg", HIY "$N穿上一件$n。\n" NOR);
                set("remove_msg", HIY "$N将$n脱了下来。\n" NOR);
        	set("armor_prop/armor", 200);
             set("dzd",1);

        }
        setup();
}

