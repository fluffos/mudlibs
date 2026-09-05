#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void do_answer(string);
void create()
{
set_name("陆冠英",({"lu guanying","lu","guanying"}));
set("nickname",HIY"域外飞侠"NOR);
set("title",GRN"归云庄"NOR+YEL"少主"NOR);
set("gender","男性");
set("age",27);
set("shen_type",1);
set("str",20);
set("int",24);
set("con",21);
set("dex",20);
set("max_qi",1000);
set("max_jing",800);
set("neili",1000);
set("max_neili",1000);
set("jiali",30);
set("combat_exp",60000);
set_skill("yuxiao-jian",40);
set_skill("luoying-shenfa",50);
set_skill("fuxue-shou",50);
set_skill("tanzhi-shengong",40);
set_skill("force",40);
set_skill("hand",40);
set_skill("dodge",40);
set_skill("finger",40);
set_skill("parry",40);
set_skill("sword",40);
    set_skill("luoying-xinfa", 50);
map_skill("force","luoying-shenfa");
map_skill("sword","yuxiao-jian");
map_skill("finger","tanzhi-shengong");
map_skill("hand","fuxue-shou");
map_skill("dodge","luoying-shenfa");
prepare_skill("finger","tanzhi-shengong");
prepare_skill("hand","fuxue-shou");
create_family("桃花岛",3,"弟子");
setup();
carry_object("/d/guiyunzhuang/npc/obj/qingshan")->wear();
carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
//	mapping fam;
	object ob;
	::init();
	add_action("do_answer","answer");
	ob=this_player();
	if((int)ob->query("PKS")>=10&&(string)ob->query("family/master_id")=="lu guanying")
    	{	
	command("say 你多次残害黎民百姓,邪气太重,我怎可容你.\n");
	command ("expell "+ob->query("id"));
	return;
	}
return;
}

void attempt_apprentice(object ob)
{
	if((int)ob->query("betrayer")>=5)
	{
        command("say 你多次背信弃义，我怎可信你!\n");
	command("say"+RANK_D->query_respect(ob)+"你多次残害黎民百姓，我怎可容你.\n");
	return;
	}
	if((string)ob->query("gender")=="无性")
	{
	
	command ("say 你不男不女的，我怎可收你.\n");
	command("say"+RANK_D->query_respect(ob)+"你不男不女的，我怎可收你.\n");
	return;
	}
	
	if((int)ob->query("shen")<0)
	{
	command("say"+RANK_D->query_respect(ob)+"还是请回吧,做几件侠义善事后再来找我吧.\n");
	return;
	}
	if ((string)ob->query("family/family_name") == "灵鹫宫" 
		&& ob->query("lingjiu/xiulian"))
	{
       		command("say "+RANK_D->query_respect(ob)+"，你现在拜我似乎会有很大损失，你能拿定主意吗？(answer)");
	return;		
	}
	command("say "+RANK_D->query_respect(ob)+"好吧,那我就收下你了!\n");
	command("recruit "+ob->query("id"));
    	this_player()->set("title",GRN"桃花岛"NOR+RED"第四代弟子"NOR);
	return;
}

void do_answer(string arg)
{
	object me=this_player();
	if (!arg || (arg != "是" && arg != "能" && arg != "yes"))
        	command("say 你说的什么乱七八糟的，看来你是没有诚心，算了！");
	else
	{
        	command("say 好吧，"+RANK_D->query_respect(me)+"，我就收下你了！");
		me->set("mud_age",me->query("lingjiu/mud_age"));
		me->set("age",14+me->query("mud_age")/3600/24);
		me->delete("lingjiu/skill_status");
		me->delete("lingjiu/qi");
		me->delete("lingjiu/eff_qi");
		me->delete("lingjiu/max_qi");
		me->delete("lingjiu/jing");
		me->delete("lingjiu/eff_jing");
		me->delete("lingjiu/max_jing");
		me->delete("lingjiu/jingli");
		me->delete("lingjiu/neili");
		me->delete("lingjiu/max_jingli");
		me->delete("lingjiu/max_neili");
		me->delete("lingjiu/combat_exp");
		me->delete("lingjiu/need_xiulian");
		me->delete("lingjiu/mud_age");
		me->delete("lingjiu/xiulian");
		me->delete("lingjiu/last_xiulian_time");
	        command("recruit "+me->query("id"));
	    	me->set("title",GRN"桃花岛"NOR+RED"第四代弟子"NOR);
	}
return;
}


void heal()
{
     object ob = this_object();
if(ob->query("eff_qi")<ob->query("max_qi"))
{
   command("exert heal");
   command("enforce 30");
   return;
}
if(ob->query("qi")<ob->query("eff_qi"))
{
     command("exert recover");
     return;
}
if(ob->query("jing")<ob->query("max_jing"))
{
     command("exert regenerate");
     return;
}
}
