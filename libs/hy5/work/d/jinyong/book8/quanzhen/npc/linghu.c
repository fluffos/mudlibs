// linghu.c 令狐冲
#include <ansi.h>;
inherit NPC;
int ask_me();

void create()
{
	set_name("令狐冲", ({ "linghu chong", "linghu", "chong" }));
	set("nickname", "大师兄");
	set("long", 
"令弧冲身材较瘦，长的浓眉阔眼，气宇暄昂，他在\n"
"同门中排行老大，是华山派年轻一代中的顶尖好手。\n");
	set("gender", "男性");
	set("age", 28);
	set("class", "swordsman");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 3800);
	set("max_qi", 3800);
	set("jing", 3600);
	set("max_jing", 3600);
	set("neili", 3400);
	set("max_neili", 3400);
	set("jiali", 60);
	
	set("combat_exp", 2500000);
	set("score", 100000);
	set_skill("chongling-jian", 180);
	set_skill("blade", 180);
	set_skill("cuff", 180);
	set_skill("feiyan-huixiang", 180);
	set_skill("hand", 180);
	set_skill("finger", 180);
	set_skill("strike",180);
	set_skill("claw", 180);
	set_skill("unarmed",180);
	set_skill("force", 180);
	set_skill("zixia-shengong", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("sword", 180);
	set_skill("huashan-sword", 180);
	set_skill("literate", 120);
	
	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "huashan-sword");
	map_skill("sword", "chongling-jian");
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "sword.ai" :),
		(: perform_action, "sword.jianzhang" :),	
		(: perform_action, "sword.jie" :),	
		(: perform_action, "sword.jm" :),	
		(: perform_action, "sword.wudui" :),				
	      }) );
	create_family("华山派", 14, "弟子");

	set("inquiry", ([
	     "青城四秀": (: ask_me :),
       	]) );
       
	setup();	 	
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/clone/cloth/cloth")->wear();
}

int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
	object hong = present("hong renxiong",where);
	if(hong)
	{
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"还是先打发了面前这位吧！\n",this_object(),who);
		return 1;
	}

  	if(((int)who->query("jinyong/book8")>=1))
	{
		message_vision("$N对$n说道： 你在说什么啊！\n",this_object(),who);
		return 1;	
	}

  	if(!who->query_temp("killhrx"))
	{
		message_vision("$N对$n说道： 你在说什么啊！你帮我对付青城四兽了吗?\n",this_object(),who);
		return 1;	
	}

  	if(((int)who->query("combat_exp",1)<=1000000))
	{
		message_vision("$N对$n说道： 你的武功太差了，等武功好点再来吧！\n",this_object(),who);
		return 1;	
	}
	
	command("bow " + who->query("id"));
	message_vision("$N对$n说道： 什么青城四秀，我看是青城四兽，平日里无恶不作。\n",this_object(),who);
	message_vision("听说这次福威镖局少镖头林平之路见不平杀了青城派掌门余沧海的儿子，青城派几乎全部都去了福州想要报仇。\n",this_object());
	message_vision("其实我看报仇还是小事，觊觎林家的剑谱才大事。\n",this_object());
	message_vision("这次出来又惹事了，回去又要被师父责罚去思过崖了。\n",this_object());
	command("sigh");
	
	i = random(800);
	who->set("jinyong/book8",1);
	who->add("combat_exp",i+6800);
	who->add("potential",i*8);
	who->add("mpgx",10);
	who->add("expmax",2);
	//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
	tell_object (who,"你赢得了"+chinese_number(i+6800)+"点经验"+
	           chinese_number(i*8)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
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