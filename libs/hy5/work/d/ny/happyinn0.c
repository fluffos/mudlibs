// Room: /d/snow/school2.c

inherit ROOM;

void create()
{
        
	set("coor",({-20,4950,10}));
	set("short", "辽东要塞广场");
        set("long",
"你现在正站在塞外要塞的广场上，你环顾四周，只见一赤膊大汉躺在藤椅上，他身边的边军\n"
"们正在恶狠狠的看着你，靠墙的桌边坐着几个江湖豪客，火头军正忙着上菜；从这儿往东则\n"
"是林间空场了。\n"
);
        set("exits", ([ /* sizeof() = 2 */
        "west" : __DIR__"happyinn2",
        "east" : __DIR__"happyinn1",
 ]));
        set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/zgx" : 1,
   __DIR__"npc/room_guard" : 5,
  __DIR__"npc/waiter" : 1,
]));
        set_temp("light",1);
        setup();
}
