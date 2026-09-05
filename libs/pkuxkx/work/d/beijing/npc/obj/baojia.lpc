#include <ansi.h>

#include <armor.h>



inherit CLOTH;



void create()

{

        set_name(HIY "真丝宝甲" NOR, ({ "zhensi baojia", "jia", "baojia" }) );

        set_weight(5000); 

        set("unique", 1);        
        if( clonep() )

                set_default_object(__FILE__);

        else {

                set("unit", "件");

//                set("no_drop","宝物是扔/卖不了的，也不能给别人。");
                set("long", "一件黑黝黝的背心，入手甚轻，衣质柔软异常，非丝非毛，不知什么质地。\n");
                set("value", 50000);

                set("material", "gold");

                set("armor_prop/armor", 550);
        }

        setup();

}



