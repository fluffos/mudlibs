// poison_dust.c
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{

       set_name("毒虫粉", ({ "duchong fen", "duchong", "fen" }) );
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long",
                       "一包以蜈蚣、蜘蛛等为原料制成的毒粉。
可以倒(pour)进酒水里，或涂(tu)在兵器上。(涂之前必须先点燃(dian)它)\n" );
               set("unit", "些");
               set("base_value", 3000);
               set("base_unit", "包");
               set("base_weight", 30);
               set("drug2", "/d/xingxiu/obj/yaoa");
               set("poison", "xx_poison");
       }
       set_amount(1);
}
#include "yao.h";

