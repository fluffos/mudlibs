//Zine 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "土路");
        set("long", @LONG
这是一条土路，往西是建康府。往北远远可以望见长江。东北面通向镇江
府，东南通向苏州府，东面(east)似乎有条小路进入深山。
LONG
        );
		set("item_desc",(["east":"也许向东(east)能走进深山。\n"]));
        set("exits", ([
               "southwest" : __DIR__"guandaosd2",
               "westup" : __DIR__"tulue1",
               "southeast" : __DIR__"tulue3",
               "northeast" : __DIR__"tulune1",
               "northup" : __DIR__"zhongshan",
        ]));

        set("outdoors", "yingtianfu");
        setup();
        
}

void init()
{
	add_action("do_east","east");
}

int do_east()
{
	object me=this_player();
	if (me->is_busy()||me->is_fighting())
	{
		write("你正忙着呢。\n");
		return 1;
	}
	tell_room("/d/zhenjiang/jlsw2",me->name()+"走了过来。\n");
	me->move("/d/zhenjiang/jlsw2");
	tell_room(this_object(),HIG+me->name()+HIG+"穿过杂草丛生的小路，向东面山里走去。\n"+NOR);
	tell_object(me,"你走进东面的隐蔽小路。\n");
	return 1;
}
