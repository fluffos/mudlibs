//Created by whuan@pkuxkx
//投名状任务之宝物
#include <ansi.h>
inherit ITEM;

void create()
{
       	set_name(HIW"镇山之宝"NOR, ({ "zhenshan zhibao", "baobei", "bao" }) );
       	set_weight(100);
       	if( clonep() )
               set_default_object(__FILE__);
      	else {
        	set("unit", "块");
          set("long", "这是铁掌帮的镇山之宝，听说以前是从大内盗来的。\n");
          set("value", 100000);
          set("no_sell", 1);
          set("zijin",1);
          set("no_put",1);
          set("material", "jade");
       }
       setup();
}