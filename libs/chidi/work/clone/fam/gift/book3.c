#include <ansi.h>
inherit ITEM;
void init(){
	add_action("do_canwu", "dakai");
}

void create()
{
        set_name(HIG "天书残谱-第3篇" NOR, ({ "tianshu canpu", "tianshu", "canpu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "这是一本黄帝遗留下来的天地魁宝--《君临天下》的残篇，你可以试着参悟（canwu）看看。\n" NOR);
                set("unit", "本");
                set("no_give", 1);
                set("no_drop", 1);
                set("no_put", 1);
                set("no_get", 1);
                set("value", 10000);
                set("weight", 50);
				set("merit", 5);//价值

                set("only_do_effect", 1);
                set("gift_type", "can_canwu");
                set("gift_name", "天书残谱-第3篇");
                set("gift_point", 30);
                set("gift_msg", HIY "突然间自己身上发出万道金光。\n" NOR);
        }
        setup();
}

int do_canwu(string arg) {
	int point;
	object me = this_player();
	int skill_lit, skill_king, skill_max;
	point = query("gift_point");

	if(!id(arg)) {
		return notify_fail("你要参悟什么？\n");
	}

	skill_lit = (int)me->query_skill("literate", 1);
	skill_max = (int)(skill_lit / 10000) - (int)(skill_lit / 10000 % 100);
	skill_king = (int)me->query_skill("king-of-dragon", 1);
	if(skill_king != 0) {
		if(skill_king >= skill_max) {
			return notify_fail("你的读书写字火候不足，难以领会这么高深的武功。\n");
		}
	}
	if((int)me->query_skill("literate", 1) < 1000000) {
		return notify_fail("你的读书写字火候不足，难以领会这么高深的武功。\n");
	}

	if((int)me->query_skill("jiuzhuan-12tian", 1) < 2000000) {
		return notify_fail("你的阴阳九转十二天火候还不到家，难以领会这么高深的武功。\n");
	}
	if((int)me->query("per") < 1000) {
		return notify_fail("你长得这么难看，没法领会君临天下的真要。\n");
	}
	if((int)me->query("kar") < 1000) {
		return notify_fail("你命格不好，恐怕不能学习这么高深的武功了。\n");
	}
       
	// 神龙附体提升成功几率
	if (me->query("special_skills/dragon")) {
		point += 35;
	}

	// 福星高照提升成功几率
	if (me->query("special_skill/lucky")) {
		point += 5;
	}

	message_vision(WHT "$N" WHT "打开了一" + query("unit") + name() + WHT "。\n" NOR, me);
/*
	if (me->query("gift/" + query("gift_type") + "/all") >= 100)
	{
			tell_object(me, "你再也看不懂这本书的玄奥之处。\n");
	} else
*/
	if (random(100) >= point) {
		tell_object(me, HIR "你怎么也看不懂这本书的玄奥之处的作用。\n" NOR);               

		// 记录失败的次数
		me->add("gift/" + query("gift_type") + "/fail", 1);
	} else {
		tell_object(me, query("gift_msg"));
		tell_object(me, HIC "你暂时领悟出" + query("gift_name") +
			HIC "的奥妙之处。\n" NOR);

		// 记录成功的记号
		me->add("gift/" + query("gift_type") + "/succeed", 1);

		// 增加相应的天赋属性
		call_out("can_canwu", 3600, me);
		me->apply_condition(query("gift_type"), 3600);
	}

	// 记录使用次数总量
	me->add("gift/" + query("gift_type") + "/all", 1);  
	destruct(this_object());      
	return 1;
}

void owner_is_killed() { destruct(this_object()); }