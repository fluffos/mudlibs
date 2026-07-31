// yao1.c

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{

       set_name(WHT"银磷粉"NOR, ({ "yinlin fen", "fen", "yinlin" }) );
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long","一包以骨灰、蛇胆等为原料制成的银光闪闪的毒粉。
可以倒(pour)进酒水里，或涂(tu)在兵器上。(涂之前必须先点燃(dian)它)\n" );
               set("unit", "些");
               set("base_value", 5000);
               set("base_unit", "包");
               set("base_weight", 30);
               set("drug2", "/d/xingxiu/obj/yao1a");
               set("poison", "cold_poison");
       }
       set_amount(1);
}

#include "yao.h";
