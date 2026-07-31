// Npc: /kungfu/class/nanshaolin/fangxiang.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;
string ask_me();
string ask_fangzhang();
int do_massage(string arg);
#include "/quest/givegift.c"
void create()
{
	set_name("方相", ({ "fang xiang", "fang", "xiang"}));
	set("long", "他是一位身穿黄布袈裟的青年僧人。脸上稚气未脱，身手却已相\n"
		"当矫捷，看来似乎学过一点武功。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50);
	set_skill("zhanzhuang-gong", 60);
	set_skill("shaolin-cuff", 60);
	set_skill("shaolin-leg", 60);
	set_skill("yiwei-dujiang", 60);
	set_skill("boluomi-hand", 60);
	set_skill("jingang-strike", 60);
	set_skill("wuxiang-finger", 60);
	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("yijinjing", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("luohan-quan", 50);
	set_skill("strike", 50);
	set_skill("sanhua-zhang", 50);
	set_skill("sanhua-zhang", 50);
	set_skill("finger", 50);
	set_skill("yizhi-chan", 50);
	set_skill("sword", 50);
	set_skill("damo-jian", 50);

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("strike", "sanhua-zhang");
	map_skill("finger", "yizhi-chan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");
	prepare_skill("strike", "sanhua-zhang");
	prepare_skill("finger", "yizhi-chan");

	set("inquiry", ([
		"手谕"       : (: ask_me :),
		"七十二绝艺" : (: ask_me :),
		"服侍方丈"   : (: ask_fangzhang :),
	]));
	create_family("南少林派", 21, "弟子");
	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
	carry_object(__DIR__"changjian")->wield();
}

void init()
{
	add_action("do_massage","massage");
}

string ask_me()
{
	mapping fam, skl; 
	object ob;
	string *sname;
	int i;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "南少林派")
		return RANK_D->query_respect(this_player()) +"与本派素无来往，不知此话从何谈起？";
	if ( (int)this_player()->query("guilty") > 0 )
		return RANK_D->query_respect(this_player()) +"你累犯数戒，身带重罪，我如何能给你这手谕！";
	if ( (int)this_player()->query_int() < 30 )
		return RANK_D->query_respect(this_player()) +"资质不够，不能进入藏经楼。";
	skl = this_player()->query_skills();
	sname = sort_array( keys(skl), (: strcmp :) );
	for(i=0; i<sizeof(skl); i++)
	{
		if (skl[sname[i]] < 50) 
		return RANK_D->query_respect(this_player()) +"功力不够，不够资格领取手谕。";
	}
	if ( (int)this_player()->query_skill("buddhism",1) < 80 )
		return RANK_D->query_respect(this_player()) +"想学习上乘武功，先要以高深佛法化解它们的戾气。";
	ob = new("/d/nanshaolin/obj/allow-letter");
	ob->move(this_player());
	message_vision("$N获得一封手谕。\n",this_player());
	return "好吧，凭这封手谕，你可自由进入藏经阁二楼研习上乘武功。";
}

string ask_fangzhang()
{
	mapping fam, skl; 
	object ob=this_player(), me=this_object();

	if(ob->query("massage_name"))
		return ("已经有人在服侍方丈了。\n");
	if(ob->query_condition("menpai_busy2") )
		return ("你才忙完，休息一下吧。\n");
	if((string)ob->query("family/family_name") != "南少林派")
		return ("非南少林弟子不能领工作。");
	if((string)ob->query("class") != "bonze" && !wizardp(ob))
		return ("俗家弟子不能领工作。");
	if(ob->query_temp("job_name"))
		return ("你不是已经领了工作吗？还不快去做。\n");
	me->set("massage_name",ob->query("name"));
	ob->set_temp("job_name","服侍方丈");
	ob->set_temp("massage", 1);
	return "来这里就是服侍方丈。你进去吧。";
}

int do_massage(string arg)
{
int i1,i2,exp;
	object ob=this_player(), me=this_object();

	if(!arg || arg != "ok") return 0;
	if(!ob->query_temp("massage")) return 0;
	if(!ob->query_temp("mark/按摩完")) return 0;
	if(ob->query("name")==me->query("massage_name")) 
	{
		command("pat "+ob->query("id"));
		command("say 真难为你了，方丈去休息了，阿弥陀佛！");
		i1=(int)(ob->query_skill("buddhism",1)/12);
		i2=(int)(ob->query_skill("buddhism",1)/10);
		if (i1>80) i1=80;
		if (i2>120) i2=120;	
		exp=i2+50;
exp=exp/2+3;
addnl(ob,"exp",exp);
me->apply_condition("menpai_busy2",2);
		me->delete("massage_name");
		ob->delete_temp("job_name");
		ob->delete_temp("massage");
		ob->delete_temp("massageed");
		ob->delete_temp("mark/按摩完");
		return 1;
	}
	return notify_fail("方相问道：你刚才进去服侍方丈了？\n");
}
#include "fang.h";

