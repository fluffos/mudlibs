// fuliyuebing.c 福利月饼，无法合成
// by icer

#include <ansi.h>

inherit ITEM;
void set_prop(int,string,int);

void create()
{
        set_name(HIY +"中秋福利月饼"+ NOR, ({ "zhongqiu fuli yuebing","yuebing","bing" }));
        set_weight( 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("material", "food");
                set("no_store",1);
                set("no_pawn",1);
        }
        setup();
}       


void set_prop(int type,string level,int date)
{
	int levelnum,levelratio;
	string yb_type,yb_desc;
	
	set("level",level);
	if (level == "普通")
		levelnum = 1;
	else if (level == "精选")
	{
		level = HIM + level + NOR;
		levelnum = 11;
	}
	else if (level == "极品")
	{
		level = HIR + level + NOR;	
		levelnum = 21;
	}	
	yb_type = "";
	yb_desc = "";
	
	set ("type",type);
	
	if (type % 2 == 1)
	{
		set("exp_bonus",1);
		levelratio = 5;
		set("exp_bonus_ratio",levelratio);
		yb_type += HIY"蛋黄"NOR;
		yb_desc += "经验奖励：" + levelratio + "% ";
	}
	type = type/2;
	if (type % 2 == 1)
	{
		set("pot_bonus",1);
		levelratio = 5;
		set("pot_bonus_ratio",levelratio);
		yb_type += HIW"莲蓉"NOR;
		yb_desc += "潜能奖励：" + levelratio + "% ";
	}
	type = type/2;
	if (type % 2 == 1)
	{
		set("ratio_bonus",1);
		levelratio = 5;
		set("ratio_bonus_ratio",levelratio);
		yb_type += HIC"蜂蜜"NOR;
		yb_desc += "掉宝率奖励：" + levelratio + "% ";
	}
	set("date",date);
	
	set("long","这是一块" + "2010年9月" + query("date") + "日生产的" + level + yb_type + "月饼，可以增加节日期间做任务的 " + yb_desc + "。\n" + HIR + "不可兑换或合成更高级的月饼，吃过福利月饼之后也不可再吃其他类型的中秋月饼。\n"+NOR);
	set("name",date + "号的" + level+yb_type+"月饼");
	set("yb_desc",yb_desc);
}


void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();
        object ob = this_object();
        if(arg != "bing" && arg != "yuebing" && arg != "zhongqiu fuli yuebing")
        	return notify_fail("你要吃什么？");
        
	    if(me->query("bonus2010_num1")>0)
                return notify_fail("做人不要太贪，月饼吃多了也会肚子痛的！\n");
        if(me->query("mud_age")<36000)
                return notify_fail("起码要在这个mud中呆足10个小时才可以食用中秋月饼!\n");
        if(me->query("combat_exp")<20000)
                return notify_fail("经验20000以上才可以食用中秋月饼!\n");
		write("有关此月饼的具体用途请详细阅读 news 183，凡是此news中已经说明的问题不再回答，由于不看说明带来的奖励损失无补偿！如有bug立刻报告，否则一经发现将回档！巫师有对月饼的最终解释权！\n 吃过福利月饼就不能再吃其他月饼了，请一定看news中的说明！你确定要吃下这块月饼？(y/n)");
		input_to("do_eat1");
		return 1;
}

int do_eat1(string arg)
{
		object me = this_player();
		object ob = this_object();
		arg = lower_case(arg);
		if (arg != "y")
			return 1;
		message_vision("$N吃下一块" + ob->name() + "，只觉得满口生香，舒畅无比！\n",me);
		me->add("bonus2010_num1",3);
		me->add("combat_exp",15000);
		me->add("potential",15000);
		tell_object(me,"你的经验增加了15000点！你的潜能增加了15000点！\n");
		me->delete("bonus2010");
		me->set("bonus2010/exp",ob->query("exp_bonus_ratio"));
		me->set("bonus2010/pot",ob->query("pot_bonus_ratio"));
		me->set("bonus2010/ratio",ob->query("ratio_bonus_ratio"));
		tell_object(me,"你的中秋红包已生效，从现在开始到10月7日24点之前做任务奖励的经验、潜能奖励及掉宝率会根据此月饼的类型做相应的加成。\n");
		CHANNEL_D->do_channel(this_object(),"rumor",me->query("name") + "吃到了" + ob->name() + "！"+NOR);
		me->add("food",30);
		destruct(this_object());
		return 1;
	
}
