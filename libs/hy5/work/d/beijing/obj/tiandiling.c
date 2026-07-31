#include <ansi.h>
//shenshe.c
inherit ITEM;
void create()
{
	set_name("天地会信物", ({ "tiandi ling", "xinwu"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "天地会信物，可以让天地会门人通过暗道回到天地会总舵。(玩家键入home即可)\n");
		set("unit", "件");
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
            return notify_fail("现在无法使用这个信物!\n");

        if( !objectp(ob = present("tiandi ling", me)) )
                return notify_fail("你没有这种东西。\n");
                
    if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR
       ||environment(me)->query("magicset")==1
       ||environment(me)->query("maze")
       ||environment(me)->query("magicroom"))
		return notify_fail("现在无法使用这个信物! \n");
		
        if (!environment(me)->valid_leave(me,"up"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"down"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"enter"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"out"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"east"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"west"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"south"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"north"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"southeast"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"southwest"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"northeast"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"northwest"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"eastup"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"westup"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"southup"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"northup"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"eastdown"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"westdown"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"southdown"))
		return notify_fail("现在无法使用这个信物! \n");
        if (!environment(me)->valid_leave(me,"northdown"))
		return notify_fail("现在无法使用这个信物! \n");
	if(me->query("family/family_name") != "云龙门")
	return notify_fail("你不是云龙门弟子，现在无法使用这个信物。\n");
	message_vision("$N从怀中掏出天地会信物，联系了附近的云龙门弟子，\n
	就见$N钻入了一个暗道，就消失了。￣￣￣\n",me);
	me->move("/d/beijing/dating");
        me->start_busy(6);
        me->add("jing",-me->query("eff_jing")/20);
//	destruct(this_object());
	return 1;
}
