// Last Modified by Sir on May. 22 2001
// lin.c
#include <ansi.h>
inherit NPC;
int ask_me();

void create()
{
	set_name("仪琳", ({ "yi lin", "lin" }) );
	set("long", 
	"她就是定逸师太的最小的徒弟，也是恒山派最小的弟子。她一双大眼，\n"
	"清澄明澈，犹如两泓清泉，一张俏脸秀丽绝俗，不带半分人间烟火气，\n"
	"只是看起来有几分忧郁，有些消瘦。\n");
	set("gender", "女性");
	set("class", "bonze");
	set("age", 16);
	set("attitude", "peaceful");
	set("per", 30);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 3400);
	set("max_neili", 3400);
	set("jiali", 30);
	set("max_qi", 3500);
	set("max_jing", 3800);
	set("combat_exp", 600000);
	set("shen_type", 1);
	
	set_skill("unarmed", 50);
	set_skill("sword", 70);
	set_skill("force", 70);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("strike", 50);
	set_skill("hand", 50);
	set_skill("buddhism", 100);
	set_skill("baiyun-xinfa",80);	
	set_skill("hengshan-jian", 200);
	set_skill("chuanyun-shou",100);
	set_skill("tianchang-zhang",70); 
	set_skill("lingxu-bu", 100);

	map_skill("force","baiyun-xinfa");
	map_skill("sword", "hengshan-jian");
	map_skill("strike","tianchang-zhang");
	map_skill("hand","chuanyun-shou");
	map_skill("parry", "hengshan-jian");
	map_skill("dodge", "lingxu-bu");
	prepare_skill("strike", "tianchang-zhang");
	prepare_skill("hand", "chuanyun-shou");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yuyin" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),		
		(: exert_function, "recover" :),
	}) );
	
	set("inquiry", ([
	     "令狐冲": (: ask_me :),
       	]) );
       	
	create_family("恒山派", 14, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}

int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
	object tian = present("tian boguang",where);
	if(tian)
	{
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"还是先打发了面前这位吧！\n",this_object(),who);
		return 1;
	}
	  	if(((int)who->query("jinyong/book8")>=3))
	{
		message_vision("$N对$n说道： 你在说什么啊！\n",this_object(),who);
		return 1;	
	}
	command("wanfu " + who->query("id"));
	message_vision("$N对$n说道： 令狐大哥被岳掌门罚面壁思过，现在正在思过崖。\n",this_object(),who);
	
	i = random(1000);
	who->set("jinyong/book8",3);
	who->add("combat_exp",i+12000);
	who->add("potential",i*10);
	who->add("mpgx",10);
	who->add("expmax",2);
	//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
	tell_object (who,"你赢得了"+chinese_number(i+12000)+"点经验"+
	           chinese_number(i*10)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	call_out("leavet",1);
	return 1;
}


void leavet()
{
        object ob = this_object();
 message_vision("$N飞身向外离去！\n" NOR,this_object());
        destruct(this_object());
}