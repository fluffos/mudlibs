
// Room: /d/snow/eroad3.c

inherit ROOM;

void create()
{
        set("coor",({0,4600,10}));
	set("short", "山路");
        set("long",
"这是一条说宽不宽，说窄倒也不窄的山路，路面用几块生满青苔的大石铺成，北面是一段黄\n"
"土小径，从这里可以通向宁远城，南面通向兵营，那里可不是一般人可以去的地方，这里你\n"
"已经隐隐约约的听到士兵们在操练的叫喊声了。\n"
);
        set("exits", ([ /* sizeof() == 2 */
      "north" : __DIR__"nroad3",
      "south" : "/d/cloud/nroad",
]));
	set("no_clean_up",0);
        set("outdoors", "ny");
//	set("objects",(["/d/snow/npc/txtrainee": 3]));
        setup();
        replace_program(ROOM);
}
