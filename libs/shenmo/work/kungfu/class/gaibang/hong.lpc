// sample master.c code
// xiake island master.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("洪七公", ({"hong qigong", "hong", "qigong"}));
	set("nickname", "九指神丐");
	set("gender", "男性");
	set("age", 75);
set("beggarlvl",9);
	set("long", 
		"他就是丐帮第十七任帮主，号称“北丐”的洪七公老爷子。\n");
	set("attitude", "peaceful");
        set("class", "beggar");
	
	set("str", 60);
	set("int", 64);
	set("con", 60);
	set("dex", 64);

	set("chat_chance", 1);
	set("chat_msg", ({
		"洪七公叹了口气道：“唉……何时能再吃到蓉儿做的「叫化鸡」啊……”\n",
		"洪七公说道：“俗话说「吃在江南」，所以老叫化特地跑来扬州看看。”\n",
		"洪七公喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”\n",
//		(: random_move :),
	}));
      set("inquiry", ([
              "青竹林" : "东北西北东西北。\n",
              "丐帮" : "东北西北东西北。\n",
              "名菜" : "我看呀，这天下的名菜都比不上蓉儿做的叫化鸡和玉笛谁家听落。\n",
              "拜师" : "你可以去东城门的我帮总舵拜鲁有脚。\n",
      ]));

	set("qi", 25000);
	set("max_qi", 25000);
	set("jing", 22400);
	set("max_jing", 22400);
	set("neili", 58000);
	set("max_neili", 58000);
	set("jiali", 300);
	
	set("combat_exp", 8000000);
	set("score", 200000);
	set("shen", 100000);
	 
		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 300);             // 基本内功
	set_skill("huntian-qigong", 380);    // 混天气功
	set_skill("unarmed", 260);           // 基本拳脚
	set_skill("xianglong-zhang", 380);   // 降龙十八掌
	set_skill("dodge", 260);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 380);        // 逍遥游
	set_skill("parry", 260);             // 基本招架
	set_skill("staff", 380);             // 基本棍杖
	set_skill("dagou-bang", 380);        // 打狗棒法
	set_skill("begging", 380);           // 叫化绝活
	set_skill("checking", 380);          // 道听途说
	set_skill("training", 380);         // 驭兽术
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
	create_family("丐帮", 17, "帮主");
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);

	setup();
	
    carry_object(__DIR__"obj/yuzhu_zhang")->wield();
    carry_object(__DIR__"obj/jiaohuaji");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20) {
		command("say 当叫化子需要能吃苦耐劳，依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合当叫化子？");
		return;
	}
//	if ((string)ob->query("family/family_name") != "" &&
//	    (string)ob->query("family/family_name") != "丐帮") {
//		command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜老叫化呢？");
//		return;
//	}
	if (this_player()->query_temp("jiahuoji")) command("recruit " + ob->query("id"));
        else
	command("say " + RANK_D->query_respect(ob) + "各项条件都不错，只可惜老叫化现在没力气收徒……");
	
}

int accept_object(object who, object ob)
{
object ob_yzz,me = this_object();;
	if (ob->query("food_supply") <= 0)
		return 0;
	if ((string)ob->query("id") != "jiaohua ji") {
		command("say 老叫化对" + (string)ob->query("name") + "没什么兴趣……");
		return 0;
	}
	if (query("food") >= max_food_capacity() - ob->query("food_supply")) {
		command("say 老叫化现在饱得很。");
		return 0;
	}
	command("say 啊……这正是我想吃的叫化鸡呀！");
	command("eat ji");
        command("say 想不到你小小年纪，心思却很细，就跟当年的蓉儿一样！");
	who->set_temp("jiahuoji",1);
    	if ((string)who->query("family/family_name") == "丐帮") {
 	if( ob_yzz = present("yuzhu zhang", me) ){
                ob_yzz->move(who);
                write("这根竹杖跟随我多年了，就送给你作见面礼吧。");
        	return 1;
    		}

//        	who->add("combat_exp",random(100));
//        	who->add("potential",random(20));
                if(random(30) == 1 
        	&& who->query("family/family_name") == "丐帮"
        	&& (int)who->query_skill("xianglong-zhang", 1) > 200
        	&& !who->query("xlz/hang")
)
{
        command("say 你等一下再走，我吃完后，有事和你说...");
               		call_out("kanglong", 10, who, this_object()); 
}
        	return 1;
}

	return 1;
}
int kanglong(object me, object ob)
{
	if(!ob || !me || !living(ob) || !living(me)
	|| environment(ob) != environment(me) 
	|| ob->is_fighting() || me->is_fighting())
	        return 0;
	        
        command("consider");
        command("say 你这娃娃真是不赖，能做出和黄丫头同样好的美味来。");
        command("say 我也不能白吃了你的菜，这样吧。");
        command("say 你去西域"+YEL+"鸣沙山"+NOR+"住上一阵子，有没有造化就看你自己了。");
//        command("say 你去西域"YEL"鸣沙山"NOR"住上一阵子，有没有造化就看你自己了。");
        me->set_temp("xlz/hang", 1);
        return 1;
}
