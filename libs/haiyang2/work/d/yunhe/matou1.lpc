// Room: /d/city2/matou1
// Date:  inca    98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW "京城码头" NOR);
	set("long", @LONG
这里是扬州港的码头，江面上停有许多船(chuan)，码头上十分热
闹，帮运货物的工人来来回回下货，一些人正在此等候租上条船到江南
一游，租船的船家忙的不以乐乎，喜笑言开。
LONG
	);
	set("no_fight",1);
	set("item_desc", ([
		"chuan":"江上有很多船，如果要坐船的话，不妨找船家租一条。\n",
		]));
	set("exits", ([
                "east" :"/d/beijing/yongding",
			]));
	set("objects", ([
		 __DIR__"npc/shaogong1" :1,
	]));
	set("outdoors", "city2");
	setup();
	
}
void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
        object me,room;
        me=this_player();
        
        if (!arg || arg=="" || arg != "chuan" )  return 0;
       if (arg=="chuan")
                {
                if ( !(int)me->query_temp("ok"))
                        return notify_fail("你还没有租到船，上那门子的船？！\n");
			else
			 if (!(int)me->query_temp("ok1")) 
			  return notify_fail("船家说道：客官请先说好到哪里，小的才好准备。\n");
			 if( !(room = find_object(__DIR__"xiaozhou1")) )
            			room = load_object(__DIR__"xiaozhou1");
        		if( room = find_object(__DIR__"xiaozhou1") ) 
            			if((int)room->query("yell_trigger")==1 ) 
				 return notify_fail("船家说道：客官不要急，船还没停稳，请稍侯。\n");
			else {room->set("yell_trigger", 1);
                        message("vision", me->name() + "走上小船。\n", environment(me), ({me}) );
                        message("vinson","你踏上木板，摇摇晃晃的走上小舟 \n"+
					  "艄公将篙一撑，船离开码头，缓缓驶去\n" ,me);
                        me->move(__DIR__"xiaozhou1");}
                }
        return 1;
}


