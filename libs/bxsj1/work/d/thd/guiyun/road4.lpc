// /u/jpei/guiyun/road4.c

#include <wanted.h>
inherit ROOM;

void create()
{
	set("short", "归云庄前");
	set("long",@LONG
这是通向归云庄的道路，西面就是归云庄。向南是一条小路，北面是一片
绿油油的草地。
LONG
);
	set("exits",([
		"west" : __DIR__"shiqiao",
		"south" : __DIR__"road3",
		"north" : __DIR__"caodi1",
	]) );
	set("no_clean_up",0);
	set("outdoors", "归云庄");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "west") {
		if (is_wanted(me))
			return 0;
		write("庄前有一个依据九宫算术布成的桃花阵。\n");
        if ((me->query("family/family_name") == "桃花岛" && me->query_skill("qimen-bagua", 1) > 14) || me->query_skill("qimen-bagua", 1) > 39)
			tell_object(me, "由于你平常看惯了这些简易的阵法，所以不用细想，信步就走出了阵！\n");
		else {
			me->set_temp("jiugong_dir", "w");
			me->move(__DIR__"jiugong" + (random(9) + 1));
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}
