
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "正厅" NOR);
	set("long", @LONG
 这里是苗家庄的正厅,周围的墙上挂着几幅字画,似乎出自名家手笔，屋子
打扫的很干净，但是一字两排八仙桌，却颇有山寨模样。
LONG);
	set("outdoors", "lanzhou");
        set("no_get_from", 1); 
     set("no_fight", 1);
        set("no_sleep_room", 1);
         set("objects", ([
                 __DIR__"npc/miaorenfeng" : 1,
         ]));
	set("exits", ([ 
	  "south" : __DIR__"qianting",
	  "north" : __DIR__"houyuan",
]));
            set("quest",1);
	setup();
}

void init()
{
	object me=this_player();
        if(me->query_condition("killer"))
	{
  	 message_vision(HIC"\n突然，不知道从哪里传来一个声音道：这里不欢迎$N。\n"NOR,me); 
		 tell_object(me,HIR"跟着，不知道哪里来的一只神脚飞起一脚，将你一脚踢飞出去！\n"NOR);
		 tell_room(environment(me),HIR"\n不知道哪里来的一只神脚飞起一脚，将"+ me->name()+ "踢飞出去！\n"NOR, ({ me }));
		 if(random(2)) me->move("/d/lanzhou/lanzhou");
		 else me->move("/d/lanzhou/zhengmen");
		 tell_room(environment(me), HIR"\n只见"+ me->name()+ "大叫一声飞过来，摔了个狗吃屎！好帅哦~~~~~~~~\n"NOR, ({ me }));
		 me->start_busy(1);
	   return;
	}
}
