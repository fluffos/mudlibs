#include <room.h>
inherit ROOM;

void create()
{
	set("short", "后堂");
	set("long", @long
这里是书场的后堂，里面有一张桌子和一张床，墙上的窗户半掩着，墙上
挂着一副年画。
long);
	set("item_desc", ([
		"picture" : "这一张寻常农家过年时贴的年画。\n",
	]));

	set("exits", ([
"out" : __DIR__"shuchang",
	]));
        create_door("out", "小门", "enter", DOOR_CLOSED);
	set("incity",1);
	setup();
}
void init()
{
	add_action("do_jie","jie");
	add_action("do_jump","jump");
}
	
int do_jie(string arg)
{
	object me;
	me=this_player();
	
	if (!arg) return 0;
	if (arg !="picture") return 0;
	if (arg=="picture"){
		write("你揭开年画，发现墙上有个洞，恰好能容纳一个人，你忍不住想跳(jump)下去。\n"
		);
	this_player()->set_temp("marks/揭1", 1);
	return 1;
	}
}
int do_jump(string arg)
{
	object me;
	me=this_player();
	if (me->query_temp("marks/揭1")){
  message("vision", me->name() +
"钻进了墙上的洞，跳了下去，只听的“乒”的一声响。\n",
                    environment(me), ({me}) );
 me->move(__DIR__"szyunhe");
            message("vision", me->name() + "突然间从上面摔了下来。\n",
                    environment(me), ({me}) );
            this_player()->delete_temp("marks/揭1");
	return 1;
	}
}
