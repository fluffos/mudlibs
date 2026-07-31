
inherit NPC;
#include <ansi.h>

string ask_baibao();
int ask_character(string arg);
int ask_fanli();
int ask_xiandan();
int ask_illness();
int ask_kuilei();
int ask_mengzi();
int ask_buchang();
int ask_shimen();
int ask_gift();
int ask_viplv();
int ask_xidian();
int ask_shimen();
int ask_jiuyang();
int ask_huidanglibao();

string *sk_list = ({
		"qishang-quan",
		"zhuihun-jian",
		"zhuihun-jian",
		"zhuihun-jian",
		"baihua-quan",
		"baihua-quan",
		"hanbing-mianzhang",
		"hanbing-mianzhang",
		"hanbing-mianzhang",
		"sougu",
		"sougu",
		"yunlong-bian",
		"yunlong-bian",
		"yunlong-bian",
		"yunlong-shenfa",
		"yunlong-shenfa",
		"hanxing-bada",
		"hanxing-bada",
		"huanyin-zhi",
		"zijinbagua-dao",
		"sanfen-jianshu",
		"ningxue-shenzhao",
		"sanfen-jianshu",
		"huanyin-zhi",
		"zijinbagua-dao",
		"xuanming-zhang",
		"ningxue-shenzhao",
		"xuanming-zhang",
		"shenzhaojing",
});
string *sk_list2 = ({
		"qishang-quan",
		"zhuihun-jian",
		"baihua-quan",
		"hanbing-mianzhang",
		"sougu",
		"yunlong-bian",
		"yunlong-shenfa",
		"hanxing-bada",
		"xuanming-zhang",
		"sanfen-jianshu",
		"huanyin-zhi",
		"ningxue-shenzhao",
		"zijinbagua-dao",
		"shenzhaojing",
		"jiuyang-shengong",
});

void create()
{
		set_name(HIW"洗点师"NOR,({  "xidian", "shi" }) );
		set("gender", "男性" );
	//	set("race", "妖魔");
		set("age", 30);
		set("long", "这是一个成天无所事事的人。\n");

		set("str", 999);
		set("dex", 999);
		set("con", 999);
		set("int", 999);
		set("shen_type", 1);
		set("combat_exp", 100);
		set("attitude", "peaceful");

		setup();

		set("inquiry", ([


	        "洗点": (: ask_viplv :),
			"九阳解密": (: ask_jiuyang :),
			//"回档礼包": (: ask_huidanglibao :),
			//"师门": (: ask_shimen :),
		]));

		carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("ask_character","washme");
	add_action("ask_xidian","xidian");
	add_action("do_getvip","getvip");
	add_action("do_getsk","getsk");
}
int ask_jiuyang()
{
	object ob = this_player();
	object gift;
	int num,money,gongxian;
	string assd;
	assd = ob->query("name");
	gongxian = ob->query("gongxians");
	//CHANNEL_D->do_channel( this_object(), "chat", "群号出现了。"+ZJURL("tel:1131210568")"过去"+NOR"。");
	//CHANNEL_D->do_channel( this_object(), "chat", "百度出现了。"+ZJURL("http://m.hao123.comp")"过去"+NOR"。");
	if (ob->query("zjvip/jiuyangjiemi"))
	{
		tell_object(ob,"你已经解密九阳！\n");
		return 1;
	}
   if(!ob->query("gongxian")>20000)
		tell_object(ob,"滚吧，你师门贡献不够。");
		return 1;
	
	if (ob->query("family/family_name") == "明教")
	{
		ob->set("can_perform/jiuyang-shengong/jiu", 1);
	ob->set("can_perform/jiuyang-shengong/pi", 1);
	ob->set("can_perform/jiuyang-shengong/po", 1);
	ob->set("can_perform/jiuyang-shengong/ri", 1);
	ob->set("can_skill/jiuyang-shengong", 1);
	ob->add("gongxian", -20000);
	ob->set("zjvip/jiuyangjiemi",1);
	tell_object(ob,"你解密九阳！\n");
	CHANNEL_D->do_channel(this_object(), "chat", HIR""HIC+ob->query("name")+HIG"解密九阳！"NOR"");
	}
	else
	tell_object(ob,""+assd+"你不是明教中人！\n");


	
	return 1;
}




int ask_viplv()
{
	int i,lv;
	object me;
	string str;

	me = this_player();
	str = ZJOBLONG"快来洗点吧！"ZJBR"你的你可以对我做的事如下：\n";
	str += ZJOBACTS2+ZJMENUF(1,1,10,30);
	
	str += "[洗基础点]["+((me->query("zjvip/xiaobaizuishuai")||me->query("zjvip/reset_att_times"))?"已达成":"需吃洗点丹")+"]["
			+((me->query("zjvip/vipgift/vip5")&&!me->query("zjvip/reset_att_times"))?"已领取":"未领取")
			+"]:getvip 5"ZJSEP;
	

	tell_object(me,str+"\n");
}





int do_getvip(string arg)
{
	int i,lv;
	object ob,me;
	string sk,str;

	me = this_player();
	if(!me->query("zjvip/times"))
	{
		tell_object(me,"你没有vip，不能领取vip成就！\n");
		return 1;
	}
	lv = me->query("zjvip/level");
	if(!arg)
	{
		tell_object(me,"你要干什么！\n");
		return 1;
	}
	     
		 
		 
		 
		 
		 
	else if(arg=="5")
	{
		if(!me->query("zjvip/xiaobaizuishuai"))
		{
			tell_object(me,"你还没有达成该成就，不能领取奖励！\n");
			return 1;
		}
	 
		ask_xidian();
	}
	else if(arg=="6")
	{
		if(lv<6&&!me->query("zjvip/reset_cha_times"))
		{
			tell_object(me,"你还没有达成该成就，不能领取奖励！\n");
			return 1;
		}
		else if(me->query("zjvip/vipgift/vip6")&&!me->query("zjvip/reset_cha_times"))
		{
			tell_object(me,"你已经领取过vip6成就奖励了！\n");
			return 1;
		}
		ask_character(0);
	}

	return 1;
}
        
		
		
		
int ask_xidian(string arg)
{
	int i,rand,all,tmpstr,tmpcon,tmpdex,tmpint,lv;
	int dstr,dcon,ddex,dint;
	string leipi,*skills,msg, type, cs;
	mapping skl;

	object me = this_player();

	lv = me->query("zjvip/level");
	if(!me->query("zjvip/xiaobaizuishuai"))
	{
		tell_object(me,"你还没有达成该成就，不能领取奖励！\n");
		return 1;
	}
	//else if(me->query("zjvip/xiaobaizuishuai")&&!me->query("zjvip/reset_att_times"))
	//{
	//	tell_object(me,"你已经洗点了！\n");
	//	return 1;
	//}

	all = me->query("str") + me->query("int") + me->query("con") + me->query("dex");
	if(!me->query("gift/lighting"))
	{
		leipi = HIM"你尚未遭遇过雷劈天赋事件，本次洗点将赠送你雷劈天赋！"ZJBR;
		all++;
	}else leipi = "";
	
	if (!arg) {
		tell_object(me,INPUTTXT(leipi+"注意："HIR"洗点后所有不符合学习条件的技能都将删除，请认真考虑。"NOR"$br#请输入你想分配的方案：$br#"
						"按照臂力、悟性、根骨、身法次序输入4个用"
						"空格分开的数，注意每个数不能低于25或大于45，4个数之和必须为"+all+"。","xidian $txt#")+"\n");
		return 1;
	}
	else if(sscanf(arg, "yes %d %d %d %d",tmpstr,tmpint,tmpcon,tmpdex) == 4)
	{
		if(tmpstr<25||tmpint<25||tmpcon<25||tmpdex<25||tmpstr>45||tmpint>45||tmpcon>45||tmpdex>45||(tmpstr+tmpint+tmpcon+tmpdex)!=all)
		{
			tell_object(me,INPUTTXT(leipi+"注意："HIR"洗点后所有不符合学习条件的技能都将删除，请认真考虑。"NOR"$br#请输入你想分配的方案：$br#"
					"按照臂力、悟性、根骨、身法次序输入4个用"
					"空格分开的数，注意每个数不能低于25或大于45，4个数之和必须为"+all+"。","xidian $txt#")+"\n");
			return 1;
		}
		me->set("str",tmpstr);
		me->set("int",tmpint);
		me->set("con",tmpcon);
		me->set("dex",tmpdex);
		if(leipi != "")
			me->add("gift/lighting", 1);

		log_ufile(me,"viplvgift",sprintf("成功洗点，目前：臂力[%d]，悟性[%d]，根骨[%d]，身法[%d]。\n",me->query("str"),me->query("int"),me->query("con"),me->query("dex")));
		skl = me->query_skills();
	//	skills = keys(skl);
		for(i=0;i<sizeof(skills);i++)
		{
			if(!SKILL_D(skills[i])->valid_learn(me) && strsrch(skills[i],"-cognize")==-1)
			{
				tell_object(me, to_chinese(skills[i])+"已经不符合学习条件，自动删除，如有错误请联系代码管理恢复。\n");
				log_ufile(me,"viplvgift",me->query_skill(skills[i],1)+"级"+skills[i]+"洗点后已经不符合学习条件，自动删除。\n");
				me->set("valid_skill/"+skills[i],me->query_skill(skills[i],1));
				me->delete_skill(skills[i]);
			}
		}
		tell_object(me, "洗点成功，祝您游戏愉快。\n");
		CHANNEL_D->do_channel(this_object(), "chat", HIR""HIC+me->query("name")+HIG"成功洗点！"NOR"");
		if(me->query("zjvip/xiaobaizuishuai"))
			me->delete("zjvip/xiaobaizuishuai");
		else
			me->set("zjvip/xiaobaizuishuai",1);
	}
	else if(sscanf(arg, "%d %d %d %d",tmpstr,tmpint,tmpcon,tmpdex)  == 4)
	{
		msg = ZJOBLONG+"臂力["+tmpstr+"]，悟性["+tmpint+"]，根骨["+tmpcon+"]，身法["+tmpdex+"]，你确定吗？\n";			
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "确定:xidian yes "+arg;
		msg += ZJSEP"取消:look";
		tell_object(me,msg+"\n");
	}
	else
	{
		tell_object(me,INPUTTXT("输入格式不对，请重新输入你想分配的方案：$br#"
						"按照臂力、悟性、根骨、身法次序输入4个用"
						"空格分开的数，注意每个数不能低于25或大于45，4个数之和必须为"+all+"。","xidian $txt#")+"\n");
	}
	
	return 1;
}

int ask_huidanglibao()
{
	object ob = this_player();
	object gift;
	int num,money;


	command("nod "+ob->query("id"));
	command("say 我这就发给你。");
	gift = new("/clone/gift/huidanglibao");
	tell_object(ob,HIM"你获得了"+gift->short()+"。"NOR"\n");
	ob->set("zjvip/huidanglibao",1);
	log_file("buchang", sprintf("%s：%s(%s)领取了%s。\n",ctime(time()),ob->query("name"),ob->query("id"),gift->short()));

	gift->move(ob);
	return 1;
}



int ask_shimen()
{
	object me;
	int shimen,shenxia,jiang;
	me = this_player();
	shimen = me->query("shimen/today");
	tell_object("你已经完成"+shimen+"师门任务。\n");
	shenxia = 3500-shimen;
	if(me->query("shimen/today",3500))
	{
		return tell_object("你已经完成本周的师门任务。\n");
	}
	tell_object("你可以扫荡"+shenxia+"个师门任务。\n");
	me->add("shimen/today",shenxia);
	me->add("potential",shenxia*600);
	me->add("combat_exp",shenxia*600);
	jiang = shenxia*600;
	tell_object("你扫荡"+shenxia+"个师门任务,获得"+jiang+"潜能和修为。\n");
	return 1;
	}