// /d/gb/xinglin8
// by pishou
// Lklv modify 2001.9.27

inherit ROOM;

void create()
{
    set("short", "杏子林");
       set("long", @LONG
这儿是杏子林中间的一片空地，四周的杏树上开满了花。一群蜜蜂飞来飞
去繁忙地采蜜。树下有几个乞丐围坐在一起，旁边站着两个年轻乞丐。他们脸
色凝重，好像在商议着什么。
LONG
       );
	set("outdoors", "苏州");
	set("exits", ([
		"south" : __DIR__"xinglin7",
		"north" : __DIR__"xinglin9",
	]));

        set("objects", ([
		CLASS_D("gaibang/song") : 1,
		CLASS_D("gaibang/zfdizi") : 1,
                CLASS_D("gaibang/bai") : 1,
        ]));

	setup();
}