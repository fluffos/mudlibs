// Room: /d/emei/milin2.c 峨嵋派 密林2


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
                "east"  : __DIR__"fuhusi1",
                "south" : __DIR__"liangfengqiao",
	]));

	setup();
	replace_program(ROOM);
}



