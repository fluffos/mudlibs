// Room: /d/tianshan/shanjian.c
// By Ciwei@SJ

#include <ansi.h>
inherit ROOM;

string long();

mapping dirs = ([
	"west":"西方",
	"westdown":"西下方",
	"westup":"西上方",
	"east":"东方",
	"eastdown":"东下方",
	"eastup":"东上方",
	"south":"南方",
	"southdown":"南下方",
	"southup":"南上方",
	"north":"北方",
	"northdown":"北下方",
	"northup":"北上方",
	"northeast":"东北方",
	"northwest":"西北方",
	"southeast":"东南方",
	"southwest":"西南方",
]);

void create()
{
        set("short", "山涧");
        set("long", (:long:) );
         foreach (string dir in keys(dirs))
         	set("exits/"+dir,__DIR__"shanjian");

        set("outdoors", "天山");
        setup();
}

void init()
{
	object me = this_player();
	if(!me->query_temp("shanjian_dir"))
		me->set_temp("shanjian_dir",keys(dirs)[random(sizeof(keys(dirs)))]);
}

int valid_leave(object me, string dir)
{
	if(me->query_temp("shanjian_dir")==dir)
	{
		tell_object(me,"你快步走出了山涧。\n");
		me->move(__DIR__"longtan");
		tell_room(environment(me),me->name()+"快步走了过来。\n",({me}) );
		me->delete_temp("shanjian_dir");
		return notify_fail("你眼前突然一亮，发现居然到了一个更为巨大的水潭边。\n");
	}
	return ::valid_leave(me,dir);
}

string long()
{
	object me = this_player();
	string str ="这是天山里的一个山涧，旁边是由于上面的山泉常年累月冲击形成的一个\n很深的水潭。这里周围长满了灌木";
	if(me && me->query_temp("shanjian_dir"))
		return str+"，"+dirs[me->query_temp("shanjian_dir")]+"似乎能走过去，你不由的加快了步伐。\n";
	return str+"。\n";
}
