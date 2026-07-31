
// Room: /d/snow/droad0.c


inherit ROOM;

void create()
{
        set("coor",({0,5000,10}));
	set("short", "罗刹营帐");
	set("long",
"来到这里，看了四周的景像真会令人不敢相信，和前面的军营竟大不相同，虎皮披于军椅，\n"
"银器列于黑刚曜石桌上，爵为金缘双虎抱图，北侧挂著刀、剑、杖，地面上有羊毛软皮铺陈\n"
"著，确实有副将营帐的味道。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"by2",


]));

        set("objects", ([
               "/kungfu/class/hu/wgj1" : 1,
               "/kungfu/class/hu/wgj2" : 1,
        ]));

	set("outdoors", "xq");
	setup();
//        replace_program(ROOM);
}
        