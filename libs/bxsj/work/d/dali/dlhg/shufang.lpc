inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "书房");
	set("long", @LONG
这里是大理皇宫的书房，只见四面皆是雕空玲珑木板，或山水人物，或翎
毛花卉，或集锦，或博古，或万万福寿，各种花样，皆名手雕镂，五彩销金嵌
宝的。保定帝经常在这里批阅奏折。后墙边有一个书架（jia)，书架上摆着不
少的书。
LONG
	);

	set("exits", ([
		"west" : __DIR__"huating",
	]));
	set("item_desc", ([
		"jia":"这是一个古色古香的书架。\n",      
	]));

	set("coor/x",-300);
  set("coor/y",-420);
   set("coor/z",-20);
   setup();
}

void init()
{
        add_action("do_fan", "fan");
}

int do_fan(string arg)
{
        object me;
	object ob;
	me = this_player();
	if( !arg || arg!="jia" || !me->query_temp("fan"))
           return notify_fail("没事乱翻什么？\n"); 
        if ( me->query_temp("book") < 4){
          me->add("jingli", -30);
        if (random(10) > 3){
	switch  (random(7)){
	case 0: ob = new(__DIR__"obj/book1"); break;
	case 1: ob = new(__DIR__"obj/book2"); break;
	case 2: ob = new(__DIR__"obj/book3"); break;
	case 3: ob = new(__DIR__"obj/book4"); break;
	case 4: ob = new(__DIR__"obj/book5"); break;
	case 5: ob = new(__DIR__"obj/book6"); break;
	case 6: ob = new(__DIR__"obj/book7"); break;
	case 7: ob = new(__DIR__"obj/book8"); break;
	}
          ob->set_temp("find",me->query("id"));
	  ob->move(this_player());
          message_vision(HIY "$N费劲周折，终于从书架上找到一本书！\n"NOR, me); 
          me->add_temp("book", 1);
	  }
	else{
	  message_vision("$N翻了半天，结果什么也没找到。\n", me); 
	  }
          }
	else{
          return notify_fail("你已经拿过书了，怎么还想拿？\n");
	}
     return 1;
}
