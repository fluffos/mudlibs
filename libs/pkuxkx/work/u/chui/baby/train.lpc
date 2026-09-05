// train.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg,int skill)
{
	object ob,where;
	mapping fam;
	int sp, dp;
	int i, cost, train_level;

	seteuid(getuid());

        if( me->is_fighting() )
                return notify_fail("你自己一边打架一边教育孩子？你真是活腻了！\n");
	if ( !arg )
		return notify_fail("你要训练你的孩子？\n");
		
	if( !objectp(ob = present(arg, environment(me)) ))
		return notify_fail("这里没有你的孩子吧？\n");

        if( ob->is_fighting() )
                return notify_fail(ob->name() + "正在打架，没空理你！\n");
                
        if(member_array(me->query("id"),ob->query("parents"))>-1)
                return notify_fail(你不是人家父母亲，折腾啥劲儿呢！\n");
                
        if( ob->query_temp("owner") &&
           ( ob->query_temp("owner") != me->query("id") ))
                return notify_fail("你的伴侣正在教育，"+ob->name() + "你还折腾个啥劲儿呢！\n");
                
	if ( ob == me )
		return notify_fail("你没这么笨吧，把自己不当人？\n");
		
	if (!living(ob)) 
		return notify_fail("你的孩子都已经晕倒了，你怎能教育它呢？\n");

	cost = me->query("jing")/me->query("max_jing");

	if (cost*2=<1)
		return notify_fail("现在你太累了，无法训练野兽。\n");

	message_vision("只见$N冲着"+ob->name()+"，口中似对它轻轻细语。\n\n",me);

	sp = me->query_skill("literate",1) + me->query("int");
	dp = ob->query("combat_exp")/100;
	
	me->receive_damage("jing", cost*9/10 );
	
	if ( (int)me->query("combat_exp") > (train_level*train_level*train_level)/10)
	{
		me->improve_skill("training", random(me->query("int")));
	}

	ob->set("attitude", "peace");
	ob->remove_all_enemy();
	ob->set_temp("owner",me->query("id"));
	ob->set_temp("ownername",me->query("name"));
        return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : train <孩子>

此指令可用于教育孩子。，可以进行下述指令：

基本指令：
        come <孩子名>:                  让孩子跟随主人行动。
        stay:                           停止孩子的跟随。
        release:                        将孩子放回托儿所。
        wei(feed) <孩子名>:             给孩子喂食。
        heshui <孩子名>:                给孩子饮水。
        
特殊指令：
        attack <某人>:                  让孩子攻击敌人。
        stop <孩子名>:                  让孩子停止对人的攻击。
HELP
	);
	return 1;
}

