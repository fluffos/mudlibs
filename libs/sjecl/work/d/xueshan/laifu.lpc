// Room: laifu.c

inherit MISC_ROOM;

void create()
{
	set("short", "来福杂货");
	set("long", @LONG
这间杂货铺铺面不大，货架上、地面上、甚至角落里都见缝插针地摆放着
些各式各样的货物，显得有些凌乱。不过从大到小，日常里用得着的这里都能
买到，附近居民还真离不开这间小店。墙上挂着个价目表(sign)。
LONG
	);

	set("exits", ([
		"east" : __DIR__"jiedao3",
	]));
        set("no_sleep_room",1);
	set("no_fight", 1);
        //set("item_desc",([
		//"sign" : "来福杂货，包罗万象。\n"
	//]));
        set("objects", ([__DIR__"npc/jiang" : 1,]));
	set("coor/x",-230);
	set("coor/y",130);
	set("coor/z",0);
	setup();
}
