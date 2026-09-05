// /u/beyond/mr/npc/obj/yuxi.c
// this is made by beyond
// update beyond
inherit ITEM;
#include <ansi.h>
void create()
{
       set_name(HIW"玉玺"NOR, ({ "yu xi", "yuxi", "xi" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "块");
               set("long", "这是一块大燕国的皇家玉玺，全身透着亮白色。\n");
               set("value", 100000);
               set("no_sell", 1);
               set("treasure",1);
               set("no_put",1);
               set("is_yuxi",1);//不让乱拿
               set("material", "jade");
       }
       setup();
}
