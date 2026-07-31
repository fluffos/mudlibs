//ROOM damen.c
inherit ROOM;
void create()
{
	set("short", "移花宫宫门");
        set("long",@LONG
这就是通向『移花宫』的大门。大门左右各有一片鲜花,香味
袭人，通过大门看进去，里面很多鲜花,你真的忍不住想要进去看看。
LONG
	);
        set("outdoors", "yihua");
        set("exits", ([
		"north" : __DIR__"yihua_out",
		"south" : __DIR__"yihua_ge",
        ]));

	set("objects",([
        "/kungfu/class/yihua/huanu" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (  (dir == "south")
           && ((string)me->query("family/family_name") != "移花宫")
	   && objectp(present("hua nu", environment(me))) )
	 return notify_fail
		("花奴伸手拦住你，说道：“好像你不是移花宫的弟子，不要到处乱跑，不然我去告诉宫主！”\n");
	return ::valid_leave(me, dir);
}
