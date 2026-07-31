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
               set("long", "这是一块大燕国的皇家玉玺，全身透着亮白色,玉玺的一边好象有一丝裂痕。\n");
               set("value", 100000);
               set("no_get",1);                 
               set("no_give",1);
               set("treasure",1);
               set("no_put",1);
               set("no_drop",1);           
set("count",1);
               set("material", "jade");
       }
       setup();
}                   

void init()
{
        add_action("do_chou", "chou");
}

int do_chou()
{
	object me = this_player();
	object ob = this_object();
	if ( !present("yu xi",me) ) return 0;
	if ( me->query_temp("慕容/chou") < 1 ) {
		if ( ob->query("count") > 0 ) {
 			new(__DIR__"paper")->move(ob);
			message("vision","你把一张纸卷从玉玺后的小细缝中抽了出来。\n",me);
                        me->delete_temp("慕容/chou");
                        ob->add("count", -1);
			return 1;
		}
		else {
			write("你仔细地看了玉玺半天，但却什么也没有拿到。\n",me);
			me->delete_temp("慕容/chou");
			return 1;
		}
		return 1;
	}
	
}	


