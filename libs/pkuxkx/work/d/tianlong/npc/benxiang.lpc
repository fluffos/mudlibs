// benguan.c 本相大师
// by paladin
#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_AQUESTMASTER;
#include "/kungfu/class/tianlong/tianlong.h"
void create()
{
       
set_name("本相大师", ({ "benxiang dashi", "benxiang" }));
        set("long",
                 "他就是本相大师，精通少冲剑。\n");
        set("title",RED "天龙寺" NOR + GRN +"长老" NOR);
        set("gender", "男性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("chat_chance_combat", 100);

        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 60);
        set("combat_exp", 90000);
        set("score", 8000);

        set_skill("force", 80);
        set_skill("dodge", 60);
        set_skill("finger", 60);
        set_skill("parry", 60);
        set_skill("sword", 60);
        set_skill("liumai-shenjian", 40);
        set_skill("yiyang-zhi",40);
        set_skill("kurong-shengong",60);
        set_skill("duanshi-shenfa",60);

        map_skill("force", "kurong-shengong");
        map_skill("dodge", "duanshi-shenfa");
        map_skill("finger", "yiyang-zhi");
        map_skill("sword", "liumai-shenjian");
        map_skill("parry", "yiyang-zhi");
        prepare_skill("finger","yiyang-zhi");
        create_family("天龙寺", 15, "长老");
        set("class", "bonze");

        setup();
//        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
		mapping fam;
        object ob;
        ::init();
        ob=this_player();
        if((int)ob->query("PKS")>=10&&(string)ob->query("family/master_id")=="benyin")
        {
        command("say 你多次残害黎民百姓,邪气太重,我怎可容你.\n");
        command ("expell "+ob->query("id"));
        return;
        }
        add_action("do_decide", "decide");
		add_action("give_wsquest","quest");
}

void attempt_apprentice(object ob)
{
		int index;
        if((int)ob->query("betrayer")>=4)
        {
        command("say 你多次背信弃义，我怎可信你!\n");
        //command("say"+RANK_D->query_respect(ob)+"你多次残害黎民百姓，我怎可容你.\n");
        return;
        }
        if( !ob->query("family")&&ob->query("combat_exp")>5000&&!ob->query("reborn/chushi")&&time()>1307960807)  
	    {   
		    command ("say 本寺不收来路不明的高手。\n");
		    return;
	    }
        if((string)ob->query("gender")!="男性")
        {

        command ("say 本寺只收男弟子，佛门清净地，男女混住，成何体统？\n");
        //command("say"+RANK_D->query_respect(ob)+"你不男不女的，我怎可收你.\n");
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
        //command("say "+RANK_D->query_respect(ob)+"好吧,贫僧就收下你了!\n");
		if (ob->query("family/family_name")!="天龙寺")
        index=1;
		else
		index=2;
		command("recruit "+ob->query("id"));
		tianlong(ob,index);
        this_player()->set("title",GRN"天龙寺"NOR+RED"第十六代弟子"NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
		  
}
void do_answer(string arg)
{
	object me=this_player();
	if (!arg || (arg != "是" && arg != "能" && arg != "yes"))
        	command("say 你说的什么乱七八糟的，看来你是没有诚心，算了！");
	else
	{
        	command("say "+RANK_D->query_respect(me)+"好吧,贫僧就收下你了!\n");
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
		me->set("title",GRN"天龙寺"NOR+RED"第十六代弟子"NOR);
//title系统记录玩家title by seagate@pkuxkx
	  me->set_title(TITLE_RANK, me->query("title"));
	}
return;
}