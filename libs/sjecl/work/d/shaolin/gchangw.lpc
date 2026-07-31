// Room: /d/shaolin/gchangw.c
// Date: CSWORD 96/02/28

inherit ROOM;

void create()
{
       set("short", "寺前广场");
       set("long", @LONG
这里是少林寺前的广场，整个广场由大块的青石铺成，极为平坦。但因年
代久远，都有些破损。丛丛小草从石板的缝隙中长了出来。广场周围都是密密
的松树林，四角上各放了几块石碑，字迹都甚为模糊。寺前三三两两的站着几
个僧人。
LONG
       );

       set("exits", ([
		"east" : __DIR__"guangchang",
       ]));

       set("outdoors", "shaolin");
       set("objects",([
               CLASS_D("shaolin") + "/qing-wei" : 1,
       ]));
	setup();
}
