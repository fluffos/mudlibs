// /u/beyond/mr/shuzhi.c
// this is made by beyond
// update 1997.6.20
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",GRN"树上"NOR);
       set("long",@long
你跳上枝头，一片碧绿的草地映入眼帘，树的那边有一枝更大的树枝，
不知能不能越过去。
long);
       setup();
}
void init()
{
        add_action("do_jump","jump");
         add_action("do_yue","yue");
}

int do_yue(string arg)
{
        object me;
	
        me = this_player();
	if (!living(me)) return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if ((int)me->query("jing")<30)
		return notify_fail("你太累了，无法继续再跳了！\n");
    if ((int)me->query_skill("dodge",1)>100)
		return notify_fail(
	"你在树枝间跃来跳去，但是再跳下去好象对你的轻功没多大的帮助。\n");

        if ((int)me->query_skill("dodge", 1) < 20 )
		return notify_fail(
			"因为与那边的树枝太远，使你无法越过去，差点摔倒！\n");
	
me->receive_damage("jing", 25);
	me->improve_skill("dodge", me->query("int"));

	message_vision("$N在树枝间来回的跳跃。\n", me);
	me->move(__DIR__"shuzhi");

	return 1;	
}

int do_jump(string arg)
{
        object me;
        me = this_player();

        if (arg !="down") 
        return notify_fail("你要到那去？\n");
        if( arg=="down")
                   {
            
                    write("你顺着树枝跳了下去。\n");
                    message("vision",
me->name() +"顺着树枝跳了下去。\n",
                    environment(me), ({me}) );
                    me->move(__DIR__"liulin3");
                    message("vision",
   me->name() +"从树枝上跳了下去。\n",
                    environment(me), ({me}) );
                   }
                return 1;
            }
