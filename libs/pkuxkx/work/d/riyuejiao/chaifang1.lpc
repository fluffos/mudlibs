//chaifang1.c	农家柴房
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","柴房");
	set("long",@LONG 
这里是一间小棚子，里面乱七八糟的堆放着好多树枝(wood)，空气
甚是污浊。大概是这户人家放置冬天烧的柴火和闲杂物品的地方。地上
有一滩血迹(blood)。
LONG
	);
	set("item_desc",([
  	"wood"	: "你可以搬动它(move)。\n",
	"blood"	: "血色尚新，应该是最近留下的。\n",
 	   ]));
	set("qu",1);

	set("exits", ([
		"north"	: __DIR__"xiaoyuan",
	]));
	setup();
}

void init()
{
    object me=this_player();
    int i,count=0;
    object chai;
    object *all=all_inventory(this_object());
    add_action("do_get","get");
    add_action("do_move", "move");
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("is_chai"))
        {
            count=1;
        }
    }
    if (userp(me)&&me->query("rynewbiejob/chufang/start")&&count<1)
    {
        chai=new(__DIR__"obj/chai");
        chai->move(this_object());
    }
}

int do_get(string arg)
{
    object me=this_player();
    if (arg=="all")
    {
        tell_object(me,"这里只能一件一件拿东西。\n");
        return 1;
    }
    if (arg=="chai huo"||arg=="chai"||arg=="chaihuo")
    {
        if (!me->query("rynewbiejob/chufang/start"))
        {
            tell_object(me,"一根柴火也偷，真是辱没你在江湖的威名啊。\n");
            return 1;
        }
        if (present("chai huo",me))
        {
            tell_object(me,"你身上不是有一根柴火了吗？\n");
            return 1;
        }
    }
}

int do_move(string arg)
{
        object me,qu;
        me = this_player();
	if (!arg || arg != "wood")
	{
		tell_object(me,"你要移动什么？\n");
		return 1;
	}
	if (query("qu") == 0 &&
		  time()-query("qutime")<=45*60)
	{
		message_vision("$N翻了翻这些枯枝，结果什么也没发现。\n",me);
		set("qutime",time());
		return 1;
	}
	message_vision("$N移动了一捆柴火，突然从柴火下面滚出一个人来。\n",me);
	qu = new(__DIR__"npc/quyang");
	qu->move(environment(me));
	set("qu",0);
	set("qutime",time());
	return 1;
}
