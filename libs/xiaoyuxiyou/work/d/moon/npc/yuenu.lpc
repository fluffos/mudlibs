#include <ansi.h>
inherit SUPER_NPC;

string ask_mieyao();
string ask_cancel();

void create()
{
	set_name("月奴", ({"yue nu", "yuenu", "yue","master"}));
       	set("long","她乃是桂树采天地之精华化成，后拜嫦娥为师。\n");
       	set_level(65);
       	set("gender", "女性");
       	set("age", 20);
       	set("class", "xian");
       	set("attitude", "friendly");
       	set("rank_info/respect", "仙姑");
       	set("per", 30);
	set("int", 30);
       	set("force_factor", 20);
       	set("mana_factor", 20);
       	set("combat_exp", 200000);
  	set("daoxing", 100000);
        set("eff_dx", 70000);
        set("nkgain", 260);

	set_skill("literate",400);
	set_skill("unarmed",400);
       	set_skill("dodge",400);
       	set_skill("force",400);
       	set_skill("parry",400);
       	set_skill("sword",400);
       	set_skill("spells",400);
        set_skill("moonshentong",400);
        set_skill("baihua-zhang", 400);
        set_skill("moonforce", 400);
        set_skill("snowsword", 400);
        set_skill("moondance", 400);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");
        set_skill("jiefeng",400);
        
        set("force_factor",0);
        set("mana_factor",450);        
	create_family("月宫", 3, "弟子");
	set("title", HIC"桂花仙"NOR);
	set("inquiry", ([
	   	"kill": (: ask_mieyao :),
	   	"师门任务": (: ask_mieyao :),
	    	"cancel": (: ask_cancel :),
	]));
	set("env/test","HIR");
	setup();
        carry_object(0,"cloth",1)->wear();
        carry_object(0,"kui",1)->wear();
        carry_object(0,"shoes",1)->wear();
        carry_object(0,"pifeng",1)->wear();
        carry_object(0,"armor",1)->wear();
        carry_object(0,"ring",1)->wear();
        carry_object(0,"neck",1)->wear();
        carry_object(0,"waist",1)->wear();
        carry_object(0,"wrists",1)->wear();
        carry_object(0,"sword",1)->wield();
	powerup(0,1);
}

void attempt_apprentice(object ob)
{
        if( !((string)ob->query("gender")=="女性"))
        {
        	EMOTE_D->do_emote(this_object(), "shake",geteuid(ob),CYN,0,0,0);
        	tell_object(ob,CYN+name()+CYN"说道：我们月宫只收女徒，这位" +RANK_D->query_respect(ob) + "还是另请高就吧。\n"NOR);
		return;
        }
        if( ob->query("class")=="yaomo" || ob->query("class")=="ghost" )
        {
		EMOTE_D->do_emote(this_object(), "kick",geteuid(ob),CYN,0,0,0);
           	tell_object(ob,CYN+name()+CYN"说道：我们月宫不收妖魔鬼怪，你还是另请高就吧。\n"NOR);
           	return ;
        }
        if( ob->query("class") )
        {
        	if( !ob->query_temp("mark/moon_class") )
        	{
			EMOTE_D->do_emote(this_object(), "hmm",geteuid(ob),CYN,0,0,0);
        	   	tell_object(ob,CYN+name()+CYN"说道：你乃带艺拜师，还是先去问问麻姑管家关于「拜师」一事吧。\n"NOR);
           		return ;
        	}
        	else	EMOTE_D->do_emote(this_object(), "smile",geteuid(ob),CYN,0,0,0);
        }
        if( ob->query_level()>70 )
        {
        	EMOTE_D->do_emote(this_object(), "wanfu",geteuid(ob),CYN,0,0,0);
		tell_object(ob,CYN+name()+CYN"说道：" + RANK_D->query_respect(ob) +"是我的前辈，还是进去找两位仙子吧。\n"NOR);
		return;
	}
	EMOTE_D->do_emote(this_object(), "pat",geteuid(ob),CYN,0,0,0);
	tell_object(ob,CYN+name()+CYN"说道：好，希望" + RANK_D->query_respect(ob) +"多加努力，把我们月宫发扬光大。\n"NOR);
        command("recruit " + geteuid(ob) );
        CHANNEL_D->do_channel(this_object(),"chat","昆仑山月宫又多了一个弟子  "+ob->name(1)+HIW"\n                                 月宫的势力加强了。\n"NOR);
        return;
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}

string ask_mieyao()
{
    	object who=this_player();
    	if((string)who->query("family/family_name")=="月宫") 
    	{
      		EMOTE_D->do_emote(this_object(), ({"addoil","touch","ok"})[random(3)],geteuid(who),CYN,0,0,0);
      		return "/quest/family/mieyao"->query_yao(who);
    	}
    	return ("非我门人,何故来此?\n");
}

string ask_cancel()
{
	if( this_player()->query("family/family_name")!="月宫" )
		return 0;
	return "/quest/family/mieyao"->cancel_me(this_player());	
}