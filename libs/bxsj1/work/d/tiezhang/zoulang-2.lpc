// Room: /tiezhang/zoulang-2.c

#include <ansi.h>
inherit ROOM;

int get_object(object ob);
void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是一条走廊，走廊上很静，北面似乎传来一阵阵翻书的哗哗声，那里
是一个书房。铁掌帮的弟子平日在那里读书用功。
LONG
	);

	set("exits", ([
		"west" : __DIR__"zoulang-3",
		"east" : __DIR__"wztang",
		"north" : __DIR__"shufang",
	]));
	setup();
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int valid_leave(object me, string dir)
{
	object obj;
        mapping fam = me->query("family");
        object *inv = deep_inventory(me);
        if(dir == "north"){
		if(!fam || fam["family_name"]!= "铁掌帮")
			return notify_fail("突然有个声音在你耳边响起：" + RANK_D->query_respect(me) +"不是铁掌帮的人，不得进入禁地。\n");
		if (me->query_condition("killer"))
			return notify_fail("通缉犯不准入内。\n");
		obj = filter_array(inv,(:get_object:));
        	if(sizeof(obj)){
			write (HIR"你刚想偷偷背个人进去，结果负重太多，脚下一个绊拴，摔倒在地。\n"NOR);
			me->move(__DIR__"zoulang-2");
			me->unconcious();
			return 1;
		}
	}
	return ::valid_leave(me, dir);
}
