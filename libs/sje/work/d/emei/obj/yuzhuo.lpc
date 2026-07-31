// zhihuan.c
// 指环
#include <ansi.h>
#include <armor.h>
inherit HANDS;
inherit F_UNIQUE;
void create()
{
       set_name("黑玉镯", ({ "yu zhuo", "zhuo" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "支");
               set("long", "这是一支黑玉镯，相传是大侠杨过送给郭襄的生日礼物。\n");
               set("value", 100000);
               set("no_get",1);                 
               set("no_give",1);
               set("unique", 1);
               set("treasure",1);
               set("material", "steel");
               set("armor_prop/armor", 10);
               set("no_put",1);
	       set("no_steal", 1);
               set("no_drop",1);
       }
       setup();
}


                

