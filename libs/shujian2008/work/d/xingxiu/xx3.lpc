// room: /d/xingxiu/xx3

inherit ROOM;

void create()
{
        set("short", "石道");
        set("long", @LONG
这是一条两旁点缀花卉的小径。花儿发出的香味多多少少冲淡了周围弥漫
着沼泽的瘴气。来来往往都是星宿弟子，而且都是男的，哼着小曲。西边有一
山洞，洞里不时传来嬉笑声，其中也夹杂了哭叫求饶声。
LONG
        );
	set("outdoors", "星宿");
	set("exits", ([
		"east" : __DIR__"xx2",
		"west" : __DIR__"chufang",
		"enter" : __DIR__"xiaoyao",
        ]));
	set("objects", ([
		__DIR__"npc/caihua" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if (dir =="enter" && present("caihua zi", environment(me))) {
		if (!myfam || myfam["family_name"] != "星宿派")
			return notify_fail("采花子挡住了你：我的小妞可不是给你们邪派弟子准备的！\n");
		if (me->query("gender")=="无性")
			return notify_fail("采花子挡住了你，一脸讥笑：您这小身板还想玩妞？别开玩笑了。\n");
		if (!me->query_temp("marks/花"))
			return notify_fail("采花子挡住了你：喂，你总该意思意思吧？\n");
        }
	return ::valid_leave(me, dir);
}
