// yao2.c

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{

       set_name(HIR"红磷粉"NOR, ({ "honglin fen", "fen", "honglin" }) );
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long", "一包以蛇毒、断肠草等为原料制成的腥红色的毒粉。
可以倒(pour)进酒水里，或涂(tu)在兵器上。(涂之前必须先点燃(dian)它)\n");                       
               set("unit", "些");
               set("base_value", 5000);
               set("base_unit", "包");
               set("base_weight", 30);
               set("drug2", "/d/xingxiu/obj/yao2a");
               set("poison", "hot_poison");
       }
       set_amount(1);
}

#include "yao.h";