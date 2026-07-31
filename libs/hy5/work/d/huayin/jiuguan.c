//jiuguan.c

inherit ROOM;
void create()
{
        set("short","小酒馆");
        set("long",@LONG                                   
这里是铜山村唯一的一个小酒馆，几个农人站在柜台前边喝
着高粱酒边说着什么，你一进了，整个酒馆静了下来。人们都自
顾自地喝着酒，没有人再说话了。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "north":__DIR__"xiaolu3",
               
        ]) );

	set("objects",([
	__DIR__"npc/huoji" : 1,
	__DIR__"npc/beg_ma": 1,
]));
        setup();
        replace_program(ROOM);
}
