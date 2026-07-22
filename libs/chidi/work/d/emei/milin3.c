// Room: /d/emei/milin3.c 峨嵋派 密林3

inherit ROOM;
void create()
{
	set("short", "密林");
	set("long", @LONG
这是一条卵石铺成的小道，曲曲折折地通向前方。两边是密密的竹林。
这里人迹罕至，惟闻足底叩击路面与敲木鱼声；微风吹拂竹叶，又如簌簌
禅唱。令人尘心为之一涤，真是绝佳的禅修所在。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "west"  : __DIR__"basipan3",
                "up" : __DIR__"shanpo",
	]));

	setup();
	replace_program(ROOM);
}



