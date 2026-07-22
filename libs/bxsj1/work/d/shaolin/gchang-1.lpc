// Room: /d/shaolin/taijie.c
// Date: YZC 96/01/19
// by zqb
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
穿过山门殿，面前三道平行的青石台阶通向前方的一个广场。台阶上精
工镂刻着麒麟，玄龟，松鹤等瑞兽，形态逼真动人。广场正中放着个二人高
的青铜大香炉，前面摆着个香台，几位香客正在虔诚谟拜。再往前就是天王
殿。
LONG
	);

	set("exits", ([
		"east" : __DIR__"gchang-3",
		"south" : __DIR__"smdian",
		"west" : __DIR__"gchang-2",
		"north" : __DIR__"qdian",
	]));

	set("outdoors", "shaolin");
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("coor/x",50);
  set("coor/y",220);
   set("coor/z",110);
   set("coor/x",50);
 set("coor/y",220);
   set("coor/z",110);
   setup();
}

void init()
{
	 
 
        object me;
	int lvl;
        mapping learned;

        me = this_player();

	lvl = me->query_skill("hunyuan-yiqi", 1);
	learned = me->query_learned();
	me->delete_skill("hunyuan-yiqi");
	if (lvl > 0) {
		me->delete_skill("yijin-jing");
		me->set_skill("yijin-jing", lvl);
		if (mapp(learned) && learned["hunyuan-yiqi"] > 0)
			me->improve_skill("yijin-jing",
				learned["hunyuan-yiqi"], 1);
		write(HIG "系统已将您的「混元一气功」转换为「易筋经」。\n" NOR);
	}
	if (me->query_skill_mapped("force") == "hunyuan-yiqi")
		me->map_skill("force", "yijin-jing");

}


