// Room: /d/beijing/xingbu2.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", RED"刑部府衙"NOR);
        set("long",
CYN"衙内阴沉沉的气氛十分恐怖，案桌后设着张太师椅，顶上挂着“明镜
高悬”的匾额，周围摆放着的各种各样的刑具在微弱的灯光中闪着寒光，两
个狱卒围着角落一个炭炉喝着烧酒一声不响。凡朝廷命官都可在这发号令
（ａｒｒｅｓｔ）。\n"NOR
        );

        set("exits", ([
                 "south": __DIR__"xingbuyamen",
        ]));

        setup();
}
void init()
{
	add_action("do_arrest","arrest");

}

int do_arrest(string arg)
{
	object me, target;
	int exp, stra,leader,factor;
	if(!arg)
	return notify_fail("你要下令缉拿谁？\n");
	me = this_player();
	if((string) me->query("class") != "officer" )
	return notify_fail("你不是朝廷官员，不可缉拿疑犯！\n");
        if( me->is_busy() )
                return notify_fail("（你上一个动作还没有完成，不能抓拿。） \n");
        if((int) me->query("jingli") < 250 )
	return notify_fail("你的精力不够！\n");
        me->start_busy(2);
        me->add("jingli", - 120);
	if(!objectp(target = find_living(arg)))
	return notify_fail("找不到你想要的疑犯！\n");

// 	if( target->query("id")=="heiyi ren"&& random(this_player()->query("kar"))<10 )
//        return notify_fail("找不到你想要的疑犯！\n");
        if( interactive(target) || !environment(target))
	return notify_fail("找不到你想要的疑犯！\n");
	//设置一个参数，乱抓人容易出bug。
	if( !target->query("can_arrest") )
        return notify_fail("这个疑犯你还是亲自去捉拿吧！\n");
          if(userp(target))
        return notify_fail("警告：你不可以捉拿玩家！\n");
          if(target->query_temp("netdead"))
        return notify_fail("警告：你不可以捉拿断线的玩家！\n");

	message_vision("$N大声下令道：来人那．．把$n给我拿来！！\n",me,target);
	exp = (int) target->query("combat_exp");
	//算法(以strategy和leadership最高200级为基础，若这两项技能的最高等级有变动，需要修改此算法)
	stra = (int) me->query_skill("strategy",1);
	leader = (int) me->query_skill("leadership",1);
	factor = (stra * stra/10) * leader /10 * leader/10;
	factor = factor + me->query("combat_exp") / 10;
        if( random(factor + exp/2) <= exp)
	return notify_fail("以你现在的能力，还不足以缉拿"+target->query("name")+"！\n");
        this_player()->start_busy(5);
        call_out("gethim",5,target,me);
	return 1;
}
int gethim(object target,object me)
{
	if(!target || !me ) return 1;
	if(environment(me) == this_object())
	{
        message_vision("$N一句话不说，匆匆忙忙地离开了。\n",target);
        target->move(this_object());
        message_vision("$N被官兵押了进来。\n",target);
	if(me)
	{
	me->kill_ob(target);
	target->kill_ob(me);
	}
        return 1;
	}
	return 1;
}
int valid_leave(object me, string dir)
{
	if(me->is_fighting())
	return notify_fail("你现在正忙得不可开交怎么能离开！\n");
	return 1;
}
