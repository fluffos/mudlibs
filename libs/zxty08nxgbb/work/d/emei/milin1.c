// Room: /d/emei/baoguosi.c 峨嵋派 密林1

inherit ROOM;

void create()
{
	set("short", "竹林小道");
	set("long", @LONG
这是一条卵石铺成的小道，曲曲折折地通向前方。两边是密密的竹林。
这里人迹罕至，惟闻足底叩击路面与敲木鱼声；微风吹拂竹叶，又如簌簌
禅唱。令人尘心为之一涤，真是绝佳的禅修所在。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"baoguosi",
                "south":__DIR__"fuhusi1",
	]));
        set("outdoors", "emei");

	setup();
}
