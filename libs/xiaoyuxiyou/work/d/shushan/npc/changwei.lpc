#include <ansi.h>
inherit SUPER_NPC;

void create()
{
        set_name("常微", ({ "chang wei", "chang" }));
        set("long", "他是蜀山派年轻一代的大弟子，乃「常」字辈的大师兄。\n");
        set("gender", "男性");
        set("age", 45);
        set_level(90);
        set("attitude", "peaceful");
        set("class","taoist");
        
        set("force_factor", 160);
        set("mana_factor", 250);

        set_skill("spells",900);
        set_skill("force", 900);
        set_skill("dodge", 900);
        set_skill("parry", 900);
        set_skill("sword", 900);
        set_skill("xianfeng-yunti", 900);
        set_skill("zuixian-wangyue", 900);
        set_skill("chuanyun-zhang", 900);
        set_skill("literate", 900);
        set_skill("unarmed", 900);
	set_skill("yujianshu", 900);
        set_skill("tianshi-fufa",900);
        map_skill("spells", "tianshi-fufa");
        map_skill("dodge", "zuixian-wangyue");
        map_skill("force", "xianfeng-yunti");
        map_skill("parry", "yujianshu");
        map_skill("sword", "yujianshu");
        map_skill("unarmed", "chuanyun-zhang");
        set_skill("jiefeng",900);

        create_family("蜀山派", 4, "首席四代弟子");
        set("env/wimpy",10);
	set("env/test","HIB");
	set_temp("weapon_level",40+random(50));
	set_temp("armor_level",40+random(50));    
        
        setup();
        carry_object(0,"pifeng",random(2))->wear();
        carry_object(0,"shoes",random(2))->wear();
        carry_object(0,"kui",random(2))->wear();
        carry_object(0,"sword",random(3))->wield();
        carry_object(0,"cloth",random(2))->wear();
        carry_object(0,"armor",random(2))->wear();
}

void attempt_apprentice(object ob)
{
	if( ob->query("class") )
	{
		if( ob->query("class")=="yaomo" )
		{
			EMOTE_D->do_emote(this_object(), "pei",geteuid(ob),CYN,0,0,0);
			tell_object(ob,CYN+name()+CYN"说道：兀那妖魔，也想窥那天道？！\n"NOR);
			this_object()->kill_ob(ob);
			return;
		}
		else if( ob->query("class")=="bonze" )
		{
			EMOTE_D->do_emote(this_object(), "shake",geteuid(ob),CYN,0,0,0);
			tell_object(ob,CYN+name()+CYN"说道：你我道不同。\n"NOR);
			return;
		}
		else if( ob->query("class")!="taoist" )
		{
			EMOTE_D->do_emote(this_object(), "shake",geteuid(ob),CYN,0,0,0);
			tell_object(ob,CYN+name()+CYN"说道：你乃带艺拜师，还是先去找常风师弟询问「拜师」一事。\n"NOR);
			return;
		}
	}	
	if( ob->query_level()>95 )
	{
		EMOTE_D->do_emote(this_object(), "great",geteuid(ob),CYN,0,0,0);
		tell_object(ob,CYN+name()+CYN"说道：" + RANK_D->query_respect(ob) +"功夫已不输与我，还是去找长老吧。\n"NOR);
		return;
	}
	EMOTE_D->do_emote(this_object(), "pat",geteuid(ob),CYN,0,0,0);
	tell_object(ob,CYN+name()+CYN"说道：好，希望" + RANK_D->query_respect(ob) +"多加努力，把我们蜀山剑派发扬光大。\n"NOR);
        command("recruit " + geteuid(ob) );
        CHANNEL_D->do_channel(this_object(),"chat","蜀山剑派又多了一个弟子  "+ob->name(1)+HIW"\n                                 蜀山的势力加强了。\n"NOR);
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		ob->set("class", "taoist");
}
