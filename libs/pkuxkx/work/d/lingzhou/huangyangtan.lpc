// 大轮寺
//by kiden

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "黄羊滩");
        set("long", @LONG
这里林草茂盛、气候宜人，是黄羊成群结队经常出没的地方，故称“黄羊滩”。
放眼看去，这里山泉清澈、林草茂盛，让人心旷神怡。东南面却有一条山涧(creek)。
LONG
        );
		set("item_desc",(["creek":"一道很宽的山涧，只有身手敏捷的人才能跳(jump)过去。\n"]));
        set("exits", ([
                "north" : __DIR__"dalu2",
                "southwest" : "/d/dalunsi/muchang9",
                "southeast" : __DIR__"shulin",
        ]));
        set("objects", ([
//                __DIR__"npc/randomnpc" : 1,
        ]));

        set("outdoors", "dalunsi");
        setup();
        set("no_clean_up", 0);
        setup();
        
}


void init()
{
	this_player()->set_temp("muchang/last_go_time",time());
	add_action("do_jump","jump");
	return;	
}
/*int do_jump()
{
	object me=this_player(),room=load_object(__DIR__"zhaling2");
	if (me->is_busy()||me->is_fighting())
	{
		write("你正忙着呢。\n");
		return 1;
	}
	if (me->query_dex()<30)
	{
		write("你的轻功实在太糟了，没法跳过山涧。\n");
		return 1;
	}
	message_vision(HIC+"$N"+HIC+"奋力跳过山涧。\n"+NOR,me);
	tell_room(room,me->name()+"从"+query("short")+"跳了过来。\n");
	me->move(room);
	return 1;
}
*/

int valid_leave(object me, string dir)
{
    if ( dir == "southwest" && time()-me->query("xinan_block/last_time")>600&&me->query("combat_exp")-me->query("xinan_block/last_exp")>500000&&random(1000)>800)
        {
            me->set("xinan_block/last_exp",me->query("combat_exp"));
            me->set("xinan_block/last_time",time());
            me->set_temp("xinan_block/start",1);
            tell_object(me,HIR+BLINK+"牧民告诉你：牧场上最近出现了一只游荡的野狼，已经吞食了很多单身的旅人，没事最好经过这里。\n"+NOR);
        }
		me->set_temp("muchang/last_go_time",time());
        return ::valid_leave(me, dir);
}