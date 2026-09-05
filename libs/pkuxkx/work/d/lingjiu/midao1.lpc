
inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
你的眼前是一条人工开凿的台阶，一直向下延伸，在火把的光照下，你勉强能看清周围的轮廓。
LONG );
	set("exits", ([
		"up" : __DIR__"huayuan",
		"northdown": __DIR__"midao2",
	]));
//        set("no_clean_up", 0);
	setup();
}
/*  将来加机关
int valid_leave(object me, string dir)
{
	if (  (dir == "northdown")
           && ((string)me->query("family/family_name") != "灵鹫宫")
	   && objectp(present("nv lang", environment(me))) )
	 return notify_fail
		("蒙面女郎伸手拦住你，说道：“对不起，本门重地，请回！”\n");
	return ::valid_leave(me, dir);
}
*/