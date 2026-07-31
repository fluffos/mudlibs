// Modify By River 98/12/
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIG"铸剑房"NOR);
	set("long", @LONG
这是一家富丽堂皇的铸剑房，墙上挂满长剑，大刀、铁锤、铁棍、匕首等
等兵器。屋角还摆着一个火炉，炉火把四周照得一片通红。炉边站着一位神态
严肃的铸剑师，他不但手艺好，信誉也不错。
LONG
);
	set("exits", ([ 
		"east" : __DIR__"xijie7",
	]));

	set("objects", ([
		"/d/zhiye/npc/zhujian-shi" : 1,
		"/d/zhiye/obj/zhujianlu" : 1,
	]));
	set("no_zhiye", 1);
	set("incity", 1);
	set("no_fight", 1);
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
		me->set_temp("dali_xc/yanzhi",1);
}
