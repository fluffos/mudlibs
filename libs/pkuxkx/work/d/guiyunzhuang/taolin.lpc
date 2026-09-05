// taolin.c
// By Pingpang 

inherit ROOM;

void create()
{
    set("short", "桃花林");
    set("long", @LONG
这里是[归云庄]后花园边上的一片桃林，你在此可以闻到一股扑鼻的香气。
这片桃林是陆庄主为了纪念当年在桃花岛学艺而种植的，可是桃林自从种植以来,
一直是[归云庄]的禁地，任何人不许进入的.
LONG
    );
     set("exits", ([
	"west" : __DIR__"houhuayuan",
	"east" : __DIR__"taolin1",
    "southeast" : __DIR__"hualin",
    "northeast" : __DIR__"hualin2",
	  ]));
                                                    
    set("objects", ([
        __DIR__"npc/crazyman" : 1]));
    	set("no_newbie_task",1);
    setup();
    replace_program(ROOM);
}

