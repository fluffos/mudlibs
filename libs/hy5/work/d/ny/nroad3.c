
inherit ROOM;

void create()
{
	set("coor",({0,4650,10}));
	set("short", "黄土小径");
	set("long",
"你现在正站在一条黄土小竟径山，北面是宁远城街道，南面是一条山路。这里本来是一个繁\n"
"荣的市场，后来因为战争的的冲击，很多的个体商人破产，昔日的热闹就不复返了。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nroad6",
        "north" : __DIR__"sroad1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/farmer" : 2,
]));
        set("outdoors", "ny");

	setup();
}
