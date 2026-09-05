// yuebing.c 月饼
// by icer

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;
inherit F_AUTOLOAD;


string query_save_file()
{
	return "/open/test/yuebing/" + query("savetime");
}
void create()
{
        set_name(HIY +"中秋月饼"+ NOR, ({ "zhongqiu yuebing","yuebing","bing" }));
        set_weight( 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("material", "food");
                set("no_store",1);
                set("no_pawn",1);
        }
        set("savetime",time());
        setup();
}       

//type 二进制 1:exp,10:pot,100:ratio,11:exp+pot,101:exp+ratio,110:pot+ratio,111:all
//level 普通：1-10,精选：11-20,极品：21-30
//date：24-30，同date的月饼三块兑换高一级level

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
		levelratio = levelnum+random(10);
		set("exp_bonus_ratio",levelratio);
		yb_type += HIY"蛋黄"NOR;
		yb_desc += "经验奖励：" + levelratio + "% ";
	}
	type = type/2;
	if (type % 2 == 1)
	{
		set("pot_bonus",1);
		levelratio = levelnum+random(10);
		set("pot_bonus_ratio",levelratio);
		yb_type += HIW"莲蓉"NOR;
		yb_desc += "潜能奖励：" + levelratio + "% ";
	}
	type = type/2;
	if (type % 2 == 1)
	{
		set("ratio_bonus",1);
		levelratio = levelnum+random(10);
		set("ratio_bonus_ratio",levelratio);
		yb_type += HIC"蜂蜜"NOR;
		yb_desc += "掉宝率奖励：" + levelratio + "% ";
	}
	set("date",date);
	
	set("long","这是一块" + "2010年9月" + query("date") + "日生产的" + level + yb_type + "月饼，可以增加节日期间做任务的 " + yb_desc + "。\n" + HIR + "有关此月饼的具体用途请详细阅读 news 183，凡是此news中已经说明的问题不再回答，由于不看说明带来的奖励损失无补偿！！！如有bug立刻报告，否则一经发现将回档！巫师有对月饼的最终解释权！\n"+NOR);
	set("name",date + "号的" + level+yb_type+"月饼");
	set("yb_desc",yb_desc);
	
	//特殊功效
	if (random(5000) == 1 || type > 1) 
	{
		set("special",random(3)+1);
		set("name",date+"号的" + HIR + BNK + "魔力" + NOR + level+yb_type+"月饼");
		set("long",query("long") + "\n" + BNK + HIR + "月饼被一层带着微微红色光晕的纸包裹着，好像带有某种魔力！\n"+NOR);	
	}	
	seteuid(ROOT_UID);
	save();
}


void init()
{
		object me = this_player();
        add_action("do_eat", "eat");
        if (!me)
        	return;
        if (me->query("id") != query("ownerid"));
        {
        	set("ownerid",me->query("id"));
        	set("ownername",me->query("name"));
        	save();
        }
}

int do_eat(string arg)
{
        object me = this_player();
        object ob = this_object();
        if(arg != "bing" && arg != "yuebing" && arg != "zhongqiu yuebing")
        	return notify_fail("你要吃什么？");
        
	    if(me->query("bonus2010_num1")>2)
                return notify_fail("做人不要太贪，月饼吃多了也会肚子痛的！\n");
        if(me->query("mud_age")<36000)
                return notify_fail("起码要在这个mud中呆足10个小时才可以食用中秋月饼!\n");
        if(me->query("combat_exp")<20000)
                return notify_fail("经验20000以上才可以食用中秋月饼!\n");
		write("有关此月饼的具体用途请详细阅读 news 183，凡是此news中已经说明的问题不再回答，由于不看说明带来的奖励损失无补偿！如有bug立刻报告，否则一经发现将回档！巫师有对月饼的最终解释权！\n你确定要吃下这块月饼？(y/n)");
		input_to("do_eat1");
		return 1;
}

int do_eat1(string arg)
{
		object me = this_player();
		object ob = this_object();
		string *specialsk=({
		        "intellect","energy","constitution","chainless","perceive","sociability","lucky",
		        "greedy","agile","might","corporeity","ironskin","spirituality","athanasy","health"
		});		
		int i;
		string msg;
		
		arg = lower_case(arg);
		if (arg != "y")
			return 1;
		message_vision("$N吃下一块" + ob->name() + "，只觉得满口生香，舒畅无比！\n",me);
		me->add("bonus2010_num1",1);
		me->add("combat_exp",5000);
		me->add("potential",5000);
		tell_object(me,"你的经验增加了5000点！你的潜能增加了5000点！\n");
		me->delete("bonus2010");
		me->set("bonus2010/exp",ob->query("exp_bonus_ratio"));
		me->set("bonus2010/pot",ob->query("pot_bonus_ratio"));
		me->set("bonus2010/ratio",ob->query("ratio_bonus_ratio"));
		tell_object(me,"你的中秋红包已生效，你的中秋红包已生效，从现在开始到10月7日24点之前做任务奖励的经验、潜能奖励及掉宝率会根据此月饼的类型做相应的加成。\n");
		CHANNEL_D->do_channel(this_object(),"rumor",me->query("name") + "吃到了" + ob->name() + "！"+NOR);

	if (query("special") == 1) 
	{
		i = random(sizeof(specialsk));        
	    msg=specialsk[i];
	    while(me->query("special_skill/"+msg) == 1)
	    {
	     	i = random(sizeof(specialsk));             
	        msg=specialsk[i];
	    }
	    me->set("special_skill/"+msg,1);
		CHANNEL_D->do_channel(this_object(),"rumor",me->query("name") + "获得特技：" + msg + "！"+NOR);
		log_file("2010hongbao",me->query("id") + "吃到了" + ob->name() + "," + ob->query("yb_desc") + "，获得特技：" + msg + "。\n");
	}
	if (query("special") == 2)
	{
		me->add("betrayer",-1);
		CHANNEL_D->do_channel(this_object(),"rumor",me->query("name") + "减判师一次！" + NOR);
		if (me->query("betrayer") < 0)
		{
			me->set("betrayer",0);
			CHANNEL_D->do_channel(this_object(),"rumor","不过对" + me->query("name") + "来说似乎没什么效果......" + NOR);
		} else log_file("2010hongbao",me->query("id") + "吃到了" + ob->name() + "," + ob->query("yb_desc") + "，减判师一次。\n");
		
	}
	if (query("special") == 3)
	{
		me->add("kar",5);
		CHANNEL_D->do_channel(this_object(),"rumor",me->query("name") + "福缘增加五点！" + NOR);
		log_file("2010hongbao",me->query("id") + "吃到了" + ob->name() + "," + ob->query("yb_desc") + "，福源增加五点。\n");
	}

		me->add("food",30);
		destruct(this_object());
		return 1;
	
}

string query_autoload()
{
        return query_save_file();
}

void autoload(string arg)
{
	restore_object(arg);
}
