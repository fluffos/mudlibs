#include <ansi.h>
inherit SUPER_NPC;

void create()
{
	set_name("清岐", ({ "qing qi", "qingqi", "yuheng" }));
	create_family2("蜀山派","玉衡宫",3, "长老");
        set("long","玉衡宫现任执事。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("class","taoist");
        set_level(120);

        set_skill("spells",1200);
        set_skill("force", 1200);
        set_skill("dodge", 1200);
        set_skill("parry", 1200);
        set_skill("sword", 1200);
        set_skill("xianfeng-yunti", 1200);
        set_skill("zuixian-wangyue", 1200);
        set_skill("chuanyun-zhang", 1200);
        set_skill("literate", 1200);
        set_skill("unarmed", 1200);
	set_skill("yujianshu", 1200);
        set_skill("tianshi-fufa",1200);
        map_skill("spells", "tianshi-fufa");
        map_skill("dodge", "zuixian-wangyue");
        map_skill("force", "xianfeng-yunti");
        map_skill("parry", "yujianshu");
        map_skill("sword", "yujianshu");
        map_skill("unarmed", "chuanyun-zhang");
        set_skill("yiyao",1200);
        set("env/wimpy",10);
	set("force_factor", 150);
	set("mana_factor", 200);
	set("env/test","HIR");
	set_temp("weapon_level",60+random(50));
	set_temp("armor_level",60+random(50));    
        
        setup();
        carry_object(0,"pifeng",random(2))->wear();
        carry_object(0,"shoes",random(2))->wear();
        carry_object(0,"kui",random(2))->wear();
        carry_object(0,"sword",random(3))->wield();
        carry_object(0,"cloth",random(2))->wear();
        carry_object(0,"armor",random(2))->wear();
}

void _attempt_apprentice(object ob)
{
	if( !ob )
		return;
	if( ob->query_level()>=125 )
	{
		EMOTE_D->do_emote(this_object(), "hoho",geteuid(ob),CYN,0,0,0);
		tell_object(ob,CYN+name()+CYN"说道：你这等修习卓为不易，还是去找掌门大师兄吧。\n"NOR);
		return;
	}	
	else if( ob->query_level()>=95 )
	{
		EMOTE_D->do_emote(this_object(), "nod",geteuid(ob),CYN,0,0,0);
		tell_object(ob,CYN+name()+CYN"说道：好，希望" + RANK_D->query_respect(ob) +"多加努力，把我们蜀山剑派发扬光大。\n"NOR);
        	command("recruit " + geteuid(ob) );
        	return;
	}
	else
	{
		EMOTE_D->do_emote(this_object(), "en",0,CYN,0,0,0);
		tell_object(ob,CYN+name()+CYN"说道：嗯，有志不在年高，你先去打好基础再来吧。\n"NOR);
		return;
	}
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
			tell_object(ob,CYN+name()+CYN"说道：你乃带艺拜师，还是先去找常风师侄询问「拜师」一事。\n"NOR);
			return;
		}
	}
	if( !ob->query("taoist/class") )
	{
		EMOTE_D->do_emote(this_object(), "shake",geteuid(ob),CYN,0,0,0);
		tell_object(ob,CYN+name()+CYN"说道：贫道不收俗家弟子。\n"NOR);
		return;
	}
	return _attempt_apprentice(ob);
}


int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
 		ob->set("class", "taoist");
}

int prevent_learn(object me, string skill)
{
	int i;
	string *noskill;
  	if( skill != "yiyao")
  		return 0;
  	noskill = ({
		"tundao","zhili","jianshu","fushui","jiee","yufeng","jiameng",
	});	
  	for(i=0;i<sizeof(noskill);i++)
  	{		
		if( me->query_skill(noskill[i],2)>0 )
		{
                	tell_object(me,CYN+name()+CYN"说道：你学了「"NOR HIC+to_chinese(noskill[i])+NOR CYN"」，本长老就不教你了。\n"NOR);
			return 1;
		} 
	}
	return 0;		
}