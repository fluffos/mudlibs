// Room: /d/city/gangkou
// Date:  inca    98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIW "华山村码头" NOR);
    set("long", @LONG
这里是华山村港的小码头，江面上停有许多船(chuan)，许多船家
在此稍做停留，休息休息，以便在赶路，从这里出去，可以到天下武
林人士皆知的华山。
LONG
    );
	set("no_fight",1);

        set("exits", ([
                "northwest"  : "/d/village/hsroad3",
        ]));

    set("item_desc", ([
         
       "chuan" :"江上有很多船，如果要坐船的话，不妨找船家租一条。\n",    ]));
    set("objects", ([
		__DIR__"npc/shaogong2" : 1,
	]));
    set("outdoors", "city");
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
			 if( !(room = find_object(__DIR__"xiaozhou2")) )
            			room = load_object(__DIR__"xiaozhou2");
        		if( room = find_object(__DIR__"xiaozhou2") ) 
            			if((int)room->query("yell_trigger")==1 ) 
				 return notify_fail("船家说道：客官不要急，船还没靠岸，请稍侯。\n");
			else {room->set("yell_trigger", 1);
                        message("vision", me->name() + "走上小船。\n", environment(me), ({me}) );
                        message("vinson","你踏上木板，摇摇晃晃的走上小舟 \n"+
					  "艄公将篙一撑，船离开码头，缓缓驶去\n" ,me);
                        me->move(__DIR__"xiaozhou2");}
                }
        return 1;
}
