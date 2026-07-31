
// Room: /u/cloud/nroad3.c


inherit ROOM;

void create()
{
        set("coor",({4000,-1200,0}));
	set("short", "山路");
        set("long",
"你现在正走在一条山间的小路上,小路两旁是郁郁葱葱的树木和草丛，偶尔还有几朵野花(fl\n"
"ower)，从林间传来阵阵鸟叫声。西边是一片树林，是这一带的柴火来源。\n"
);
        set("item_desc", ([/*sizeof() == 1 */
             "flower" : "这是一朵粉红色的花,你禁不住想把它摘下来,但是,
你可要记住:路边的野花采不得!\n",
            ]));
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nroad4",
            "westup" : __DIR__"wood",
]));
        set("outdoors", "cloud");

        setup();
//        replace_program(ROOM);
}

