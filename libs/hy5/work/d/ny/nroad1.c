
// Room: /d/snow/nroad1.c

inherit ROOM;

void create()
{
    set("coor",({0,4800,10}));
	set("short", "要塞前的空地");
	set("long",
"北面是一座要塞，辽东要塞的守将镇关西是一个出了名的恶霸，东面是一条石板路。\n"
"，街上人来人往非常热闹。\n"
);
	set("outdoors", "ny");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nroad2",
  "south" : __DIR__"square",
//  "west" : __DIR__"nroad3",
//  "east" : __DIR__"nroad7",
]));
	set("no_clean_up", 0);

	set("objects", ([
	  __DIR__"npc/wujiang" : 1,
  __DIR__"npc/bing" : 5,  
	__DIR__"npc/playboy":1,]));
	setup();
//    replace_program(ROOM)
//    replace_program(ROOM);
}
//int valid_leave(object me, string dir)
//        if( dir=="south" && !wizardp(me) )
//                return notify_fail("那里施工中，请改道。\n");
//        return ::valid_leave(me, dir);
//}
