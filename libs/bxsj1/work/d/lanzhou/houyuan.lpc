
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIM"后院" NOR);
	set("long", @LONG
这里是苗家的後院，打扫的非常干净，错落有序的放着几把藤椅。一角种
种植着各种花草，只是似乎很久没人管理，有些杂乱。南边是正厅。
LONG
	);
	//set("outdoors", "");
	set("exits", ([ 
	  "south" : __DIR__"zhenting",
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
