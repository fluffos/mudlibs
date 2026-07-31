#include <ansi.h>
//shenshe.c
inherit ITEM;
void create()
{
	set_name("引路神蛇", ({ "shen she", "snake"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一条有识路能力的神蛇，可以把主人带到白
		      驼山。(玩家键入home即可)\n");
		set("unit", "条");
		set("value", 0);
	}
}
void init()
{
	add_action("do_home","home");
}
int do_home()
{
	string dir;
	object me = this_player();
        object ob;
//if( !SKILL_D(skill_name[item])->valid_learn(me) )
//return SKILL_D(skill_name[item])->valid_learn(me);
        if (me->is_busy())
            return notify_fail("你现在正忙着呢。\n");
        if (me->is_fighting() )
            return notify_fail("你无法在战斗中使用引路神蛇！\n");
        if( !objectp(ob = present("shen she", me)) )
                return notify_fail("你没有这种东西。\n");
    if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR
       ||environment(me)->query("magicset")==1
       ||environment(me)->query("maze")
       ||environment(me)->query("magicroom"))
		return notify_fail("迷宫中神蛇不认识路了! \n");
		
        if (!environment(me)->valid_leave(me,"up"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"down"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"enter"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"out"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"east"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"west"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"south"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"north"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"southeast"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"southwest"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"northeast"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"northwest"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"eastup"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"westup"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"southup"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"northup"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"eastdown"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"westdown"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"southdown"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
        if (!environment(me)->valid_leave(me,"northdown"))
		return notify_fail("你身上一定偷藏了什么，神蛇不听你使唤啦。\n");
	if(me->query("family/family_name") != "白驼山派")
	return notify_fail("你不是白驼山派弟子，「引路神蛇」不听你使唤。\n");
	message_vision("$N从怀中掏出「引路神蛇」，口里不知念了些什么，\n
	就见「引路神蛇」吐吐芯子，摇头摆尾地把$N往白驼山带去￣￣￣\n",me);
	me->move("/d/baituo/damen");
        me->start_busy(6);
        me->add("jing",-me->query("eff_jing")/20);
//	destruct(this_object());
	return 1;
}
