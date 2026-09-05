// suanming.c 算命先生
#include <ansi.h>
inherit NPC;

nosave string *topskill = ({
"wuying-jian","taiji-zhao","xianglong-zhang","hamagong","huagong-dafa"
,"dugu-jiujian","fuliu-jian","qiankun-danuoyi","pixie-jian","xiaohun-zhang"
,"tianyu-qijian","tonggui-jian","beiming-shengong","bihai-shengong","douzhuan-xingyi"
,"yunlong-zhua","shedao-qigong","guihun-jian","guishoushe","xiake-shengong"
,"yuejia-qiangfa"
});

string ask_me();

void create()
{
        set_name(WHT"铁笔判官"NOR, ({"tiebi panguan","panguan"}) );
        set("nickname",YEL"结朋天下"NOR);
        set("str",20);
        set("long",
                "他是武林中人缘最好的铁笔判官，他同黑白两道各门各派的关系都不错。\n");
	set("age",40);
        set("shen_type",0);
	set("gender","男性");
	set("combat_exp",200000);
	set_skill("unarmed",30);
	set_skill("force",30);
	set_skill("dodge",30);
	set_skill("parry",30);
	set("chat_chance_combat",20);
	set("chat_chance",4);
	setup();
	set("chat_msg",({HIC"铁笔判官说道：叛师有时候也是身不由己的。\n"NOR,
            HIC"铁笔判官说道：人谁无过？知错能改就好。\n"NOR,
            HIC"铁笔判官说道：想和背叛的师门调解关系，找我就对了。不过这个疏通渠道的费用，得要从你的户头拨给我。\n"NOR,
            HIC"铁笔判官说道：决心悔过空口无凭，放弃一门最强功夫才算让人信服。\n"NOR,
	}));
	set("inquiry", ([
	    "叛师" : (: ask_me :),
	
	]));
	carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
    add_action("do_sign","sign");
}

string ask_me()
{
	object me = this_player();
	int bet, bet_done, i, amount;
	int toplevel;
	string dropskill;
	
	bet = (int)me->query("betrayer");
	bet_done = (int)me->query("betrayer_fixed");
	if (!(bet_done>0))
	{
		bet_done=0;
	}

	if ( bet<1 )
		return "呵呵，你一定在开玩笑。\n";
		
	if ( bet_done>=5 )
		return "哼哼，你品行恶劣，怕是我也帮不了你。\n";

	toplevel=-1;
	dropskill = "none";
	for (i=0;i<21;i++)
	{
		if (((int)me->query_skill(topskill[i])) > toplevel && ((int)me->query_skill(topskill[i])) > 0)
		{
			toplevel = (int)me->query_skill(topskill[i]);
			dropskill = topskill[i];
		}
	}	
		
	amount = (bet_done+1)*(bet_done+1)*(bet_done+1)*100;
	say("人在江湖，身不由己。\n");
	say("你想跟原有师门改善关系？呵呵，找我就对了。这样吧，你给我 "+chinese_number(amount)+" 两黄金，\n");
	if (dropskill != "none")
	{
		say("同时完全放弃你的"+to_chinese(dropskill)+"("+dropskill+")这门功夫！然后我帮你来搞定师门这个事情。\n");
	}
	else
	{
		say("我帮你来搞定这个事情。\n");
	}
	if (((int)me->query("balance"))>amount*10000)
	{
		say("我这里有一张转帐同意票据\n");
		me->set_temp("mark/betrayer",1);
		me->set_temp("mark/dropskill",dropskill);
		return "你可以签：同意(sign yes)/不同意(sign no)\n";
	}
	else
	{
		return "但是你的存款好像不足。\n";
	}
}

int do_sign(string arg)
{
	object me = this_player();
	int bet, bet_done, i;
	int toplevel;
	string dropskill;
	
	if(!arg || (arg!="yes" && arg!="no"))
		return notify_fail("你要签署什么？\n");
		
	if (arg=="no")
	{
		me->delete_temp("mark/betrayer");
		return notify_fail("你想了想，还是放弃了。\n");
	}
	bet = (int)me->query("betrayer");
	bet_done = (int)me->query("betrayer_fixed");
	
	if ( bet<1 )
		return notify_fail("呵呵，你一定在开玩笑。\n");
		
	if ( bet_done>=5 )
		return notify_fail("哼哼，你品行恶劣，怕是我也帮不了你。\n");

	if ( ((int)me->query_temp("mark/betrayer")) != 1)
		return notify_fail("什么？\n");
		
	if (((int)me->query("balance"))< (bet_done+1)*(bet_done+1)*(bet_done+1)*100*10000)
		return notify_fail("你的存款不够，还是别签了。\n");
	
	// do it
	me->delete_temp("mark/betrayer");
	dropskill = (string)me->query_temp("mark/dropskill");
	me->set("betrayer", bet-1);
	me->set("betrayer_fixed", bet_done+1);	
	me->set("balance", ((int)me->query("balance"))-(bet_done+1)*(bet_done+1)*(bet_done+1)*100*10000);
	me->delete_skill(dropskill);
	if (dropskill!="none")
		tell_object(me,"为了表示悔悟的诚意，你放弃了学习"+to_chinese(dropskill)+"("+dropskill+")这项功夫！\n");
	
	tell_object(me,"铁笔判官转身就不见了，半柱香的功夫，他一溜烟跑来说：你的事情已经办好了。\n");
	return notify_fail("你的判师次数减少了！\n");
}
