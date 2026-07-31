// feng.c 风清扬
#include <ansi.h>
inherit NPC;
int ask_me();

void create()
{
	set_name("风清扬", ({ "feng qingyang", "feng", "qingyang" }));
	set("title", "华山第十二代剑宗长老");
	set("long", 
"这便是当年名震江湖的华山名宿风清扬。他身著青袍，神气抑郁脸如金纸。
身材瘦长，眉宇间一直笼罩着一股淡淡的忧伤神色，显然对当年的剑宗气宗
之争一直难以忘怀。\n");
	set("gender", "男性");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 70);
	set("int", 70);
	set("con", 70);
	set("dex", 70);
	
	set("qi", 39800);
	set("max_qi", 39800);
	set("jing", 38600);
	set("max_jing", 38600);
	set("neili", 54400);
	set("max_neili", 54400);
	set("jiali", 200);

	set("combat_exp", 15050000);
	set("score", 200000);

	set("fengset",1);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 380);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 380);
	set_skill("zixia-shengong", 380);
	set_skill("zixia-shengong", 380);
	set_skill("ziyunyin", 380);
	set_skill("zhengqijue", 380);
	set_skill("fanliangyi-dao", 380);
	set_skill("huashan-sword", 380);
	set_skill("hunyuan-zhang", 380);
	set_skill("lonely-sword", 380);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 200);
        set_skill("zhengqijue",380);
        set_skill("hunyuan-zhang", 380);
        set_skill("poyu-quan", 380);        
        set_skill("huashan-neigong", 380);        
        set_skill("chongling-jian", 380);
        set("fengset",1);
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");

	create_family("华山派", 12, "弟子");
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );

	set("inquiry", ([
	     "剑宗": (: ask_me :),
       ]) );
       
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

int ask_me()
{
	int i;

	object who = this_player();
  	if(((int)who->query("jinyong/book8")>=4))
	{
		message_vision("$N对$n说道： 你在说什么啊！\n",this_object(),who);
		return 1;	
	}
	say("风清扬望着身后的山川，语重心长地说道：“华山不幸曾分为气剑二宗。他\n");
	say("们气宗奉气为主，以剑为辅，以气运剑，无坚不摧。而剑宗则反道而行重剑\n");
	say("轻气。二宗各持己见，终于水火不容，同门操戈！现任掌门岳不群便是气宗\n");
	say("分支，此子颇有野心，现在率弟子前往嵩山参加五岳大会去了。剑宗现任宗\n");
	say("主封不平时刻想夺回华山掌门之位，听说已经带了门下弟子前往洛阳准备截”\n");
	say("杀岳不群一行人。唉，剑气之争从上一辈延续至今，怎么都看不开呢！”\n");
	i = random(1200);
	who->set("jinyong/book8",4);
	who->add("combat_exp",i+14000);
	who->add("potential",i*12);
	who->add("mpgx",10);
	who->add("expmax",2);
	//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
	tell_object (who,"你赢得了"+chinese_number(i+14000)+"点经验"+
	           chinese_number(i*12)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();
	call_out("leavet",1);
	return 1;
}


void leavet()
{
        object ob = this_object();
 message_vision("$N飞身向外离去！\n" NOR,this_object());
        destruct(this_object());
}
