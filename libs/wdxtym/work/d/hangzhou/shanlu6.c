// shanlu6.c
// Date: Nov.1997 by Venus

inherit BUILD_ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
山路崎岖，曲折蜿延。四周林木苍翠，修竹茂密。山路旁有一山
洞，据说洞里有时会传出虎哮声，故名老虎洞，虽然如此，景色如此
宜人，怎能不让人心生长住之意？西边是下山的路，往东下山便到了
山底。
LONG);
	set("exits", ([
	    "eastup"  : __DIR__"yuhuangsd",
	    "westdown": __DIR__"yuhuangshan",
	]));
	set("objects", ([
	    __DIR__"npc/laohu" : 1,
	    __DIR__"obj/shuzhi" : 1,
	]));
	set("outdoors", "hangzhou");
	set("max_room", 4);
	setup();
}
