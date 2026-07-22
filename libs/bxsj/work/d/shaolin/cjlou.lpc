// Room: /d/shaolin/cjlou.c

inherit ROOM;

void create()
{
	set("short", "藏经阁一楼");
	set("long", @LONG
这里就是名满江湖的--少林藏经阁。不愧为中原佛法的总源，少林寺此
处藏经之富，天下罕有其匹。这里都是密密麻麻，高及顶棚的书架，书架间
仅有容身一人通行的空隙。几排大书架中间，间隔地放着数丈长的书桌。目
光及处，你看到桌上放了几本佛经。
LONG
	);

	set("exits", ([
		"out" : __DIR__"xiaoxi1",
		"up" : __DIR__"cjlou1",
	]));
	set("cant_hubiao", 1);

	set("objects",([
		CLASS_D("shaolin") + "/dao-yi" : 1,
	]));

	setup();
}


int valid_leave(object me, string dir)
{
	if (me->query("family/family_name") == "姑苏慕容" && me->query("family/generation") <3);
	else if (me->query("family/family_name") == "少林派" && me->query("family/generation") <36);
        else if( !present("shou yu", me) && (objectp(present("daoyi chanshi", environment(me)))) )
		if (dir == "up" ) return notify_fail("道一说道: 你未经许可，不能上二楼。\n");
	return ::valid_leave(me, dir);
}
