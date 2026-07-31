
// Room: /u/cloud/nroad4.c

inherit ROOM;

void create()
{
        set("coor",({4000,-1150,0}));
	set("short", "山路");
        set("long",
"你现在正走在一条山间的小路上,小路两旁是郁郁葱葱的树木和草丛(grass)，偶尔还有几朵\n"
"野花，从林间传来阵阵鸟叫声。\n"
);
        set("item_desc", ([/*sizeof() == 1 */
             "grass" : "这只是一丛普通的草而已，有什么好看的呢?\n",
            ]));
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"shijie1",
  "south" : __DIR__"nroad3",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

