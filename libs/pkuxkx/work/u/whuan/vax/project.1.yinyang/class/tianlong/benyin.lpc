// benyin.c 本因方丈
// by paladin


#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void do_answer(string);

void create()
{

        set_name("本因方丈", ({ "benyin fangzhang", "benyin" }));
        set("long",
                "他就是本因方丈。\n"
                "他今年三十岁。\n");
        set("title",RED "天龙寺" NOR + GRN +"本因方丈" NOR);
        set("gender", "男性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 30);
        set("con", 30);
        set("chat_chance_combat", 100);

        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 60);
        set("combat_exp", 200000);
        set("score", 8000);

        set_skill("force", 60);
        set_skill("dodge", 60);
        set_skill("finger", 80);
        set_skill("parry", 60);
        set_skill("dali-xinfa", 60);
        set_skill("literate", 50);
        set_skill("yiyang-zhi", 80);

        prepare_skill("finger","yiyang-zhi");
        create_family("天龙寺", 2, "弟子");
        set("class", "bonze");

        setup();

}


void init()
{
        mapping fam;
        object ob;
	add_action("do_answer","answer");
        ::init();
        ob=this_player();
        if((int)ob->query("PKS")>=10&&(string)ob->query("family/master_id")=="benyin")
    {
        command("say 你多次残害黎民百姓,邪气太重,我怎可容你.\n");
        command ("expell "+ob->query("id"));
        return;
}

}

        void attempt_apprentice(object ob)
{
        if((int)ob->query("betrayer")>=4)
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
        command("say "+RANK_D->query_respect(ob)+"好吧,贫僧就收下你了!\n");
        command("recruit "+ob->query("id"));
        this_player()->set("title",GRN"天龙寺"NOR+RED"第三代弟子"NOR);
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
		me->set("title",GRN"天龙寺"NOR+RED"第三代弟子"NOR);
	}
return;
}
