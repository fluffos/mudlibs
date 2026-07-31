// herbshop1.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这是一间光线阴暗的密室，从地上厚厚的灰尘看得出来这里很少有人
出入，靠西边的地上放着一副脚镣，连着一条铁链镶在墙上，不知道是用
来锁什麽人，南面的墙(wall)是用红杉木做的，跟另外三面的灰土墙比起
来显得有些不寻常。
LONG );

	set("exits", ([
		"east" : __DIR__"chuchang",
	]));

	set("objects", ([
		CLASS_D("gaibang") + "/hong" : 1,
	]));
	setup();

}
