// Last Modified by Winder on May. 29 2001
// Npc: /kungfu/class/nanshaolin/daku.c

#include "da.h"
#include "ansi.h"
inherit NPC;
inherit F_MASTER;
string ask_me();
int do_zhongcai(string arg);
#include "/quest/givegift.c"
void create()
{
	set_name("大苦大师", ({ "daku dashi", "daku", "dashi"}));
	set("long",
		"他是一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，\n"
		"太阳穴微凸，双目炯炯有神。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 12000);
	set("max_jing", 11200);
	set("neili", 13000);
	set("max_neili", 13000);
	set("jiali",200);
	set("combat_exp", 8000000);
	set("score", 5000);
	set_skill("zhanzhuang-gong", 220);
	set_skill("shaolin-cuff", 220);
	set_skill("shaolin-leg", 220);
	set_skill("yiwei-dujiang", 220);
	set_skill("boluomi-hand", 220);
	set_skill("jingang-strike", 220);
	set_skill("wuxiang-finger", 220);
	set_skill("ruying-leg", 280);
	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 150);
	set_skill("force", 150);
	set_skill("yijinjing", 150);
	set_skill("dodge", 150);
	set_skill("shaolin-shenfa", 220);
set_skill("hunyuan-yiqi", 260);
// basic skill begin
	set_skill("hunyuan-yiqi", 220);
	set_skill("luohan-quan", 220);
	set_skill("sanhua-zhang", 220);
	set_skill("sanhua-zhang", 220);
	set_skill("xiuluo-dao", 220);
	set_skill("weituo-gun", 220);
	set_skill("nianhua-zhi", 220);
	set_skill("banruo-zhang", 220);
// basic skill end
// 鞭和拳
	set_skill("cuff", 150);
	set_skill("jingang-quan", 220);
	set_skill("whip", 150);

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");

	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 660);
	set_temp("apply/armor", 660);

	

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
  map_skill("parry","ruying-leg");
  map_skill("unarmed","ruying-leg");
  map_skill("leg","ruying-leg");
	prepare_skill("leg", "ruying-leg");
	
	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({		
		 (: perform_action, "leg.ruying" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("南少林派", 19, "僧监");
	set("inquiry", 
	([
		"轮值" : (: ask_me :),
	]));
	setup();
	carry_object(__DIR__"whip")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
	add_action("do_lunzhi","lunzhi");
	add_action("do_zhongcai","zhongcai");
}
string ask_me()
{
	mapping fam; 
	object me;
	object ob;
	ob=this_player();
	me=this_object();
	if(!wizardp(ob) && (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "南少林派" ))
		return RANK_D->query_respect(ob)+"，你不是本寺弟子，不能轮值！";
	if(!wizardp(ob) && (string)ob->query("class")!="bonze")
		return ("俗家弟子不能轮值。");
	if(!wizardp(ob) && ob->query_condition("menpai_busy") )
		return ("你才忙完，休息一下吧。\n");
			if(ob->query_condition("sl_lunzhi") )
		return ("你不是正在轮值吗。\n");
		
	if(ob->query_temp("lunzhi"))
		return ("现在已有人轮值了，你就等一次吧。\n");
	//me->apply_condition("sl_lunzhi",11);
	//me->set("lunzhi_name",ob->query("name"));
	me->set_temp("lunzhi",1);
	ob->set_temp("lunzhi",1);
	ob=new(__DIR__"obj/lunzhi-ling");
	ob->move(this_player());
	write("大苦大师给你一块轮值令。\n");
	return "好吧，你就到迎客亭把令交给方通吧，轮值时应当小心防范，防止外敌偷入寺中。";
}
int do_lunzhi(string arg)
{
	object ob,me;
	int i1,i2,exp;
	ob=this_player();
	me=this_object();
	if(!(arg)) return 0;
	if(!(arg=="ok")) return 0;
	if(!ob->query_temp("lunzhi")) return 0;
	if(!ob->query_temp("lunzhied")) return 0;

		if ( (int)ob->query_condition("sl_lunzhi"))
		{
			command("angry"+ob->query("id"));
			command("slap"+ob->query("id"));
			return notify_fail( "大苦大师大怒道："RED"想偷懒，快给我滚回去。\n"NOR);
		}
		command("pat "+ob->query("id"));
		command("say 哈哈，真难为你了，"+RANK_D->query_respect(ob)+"，干得好！");
		i1=(int)(ob->query_skill("buddhism",1)/12);
		i2=(int)(ob->query_skill("buddhism",1)/10)+(ob->query("kar",1)*2);
		if (i1>80) i1=80;
		if (i2>120) i2=120;	
		exp=i2+80;
exp=exp/2+108;
addnl(ob,"exp",exp);
me->apply_condition("menpai_busy",8);
		me->delete("lunzhi_name");
		me->delete_temp("lunzhi");
		ob->delete_temp("lunzhi");
		ob->delete_temp("lunzhied");
		return 1;

}

int do_zhongcai(string arg)
{
	int i1,i2;
	object ob=this_player(), me=this_object();

	if(!arg || arg != "ok") return 0;
	if(!ob->query_temp("mark/浇完")) return 0;
	{
		command("pat "+ob->query("id"));
		command("say 辛苦了！");
		i1=(int)(ob->query_skill("buddhism",1)/12);
		i2=(int)(ob->query_skill("buddhism",1)/10);
		if (i1>80) i1=80;
		if (i2>100) i2=100;	
		ob->add("potential",i1+20);
		ob->add("combat_exp",i2+50);
		ob->apply_condition("menpai_busy2",2);
		ob->delete_temp("job_name");
		ob->delete_temp("mark/浇完");
		return 1;
	}
	return notify_fail("方相问道：你刚才进去服侍方丈了？\n");
}

