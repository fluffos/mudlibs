inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void do_answer(string);


void create()
{
        set_name("辛然", ({ "xin ran", "xin" }));
        set("long","他是明教烈火旗掌旗使。\n");
        set("title",GRN "明教" NOR + YEL +"掌旗使" NOR);
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        set("max_qi", 1000);
        set("max_jing", 700);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 20);
        set("combat_exp", 55000);
        set_skill("force", 55);
        set_skill("shenghuo-xinfa", 45);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("claw", 45);
        set_skill("datengnuo-bufa", 40);
        set_skill("myingzhua-gong", 50);
        set_skill("literate",40);
        map_skill("force", "shenghuo-xinfa");
        map_skill("parry", "shenghuo-shengong");
        map_skill("dodge", "datengnuo-bufa");
        map_skill("claw","myingzhua-gong");
        prepare_skill("claw", "myingzhua-gong");
        create_family("明教", 21, "弟子");
        setup();
        carry_object("/d/mingjiao/obj/huangshan")->wear();
//        carry_object("/d/mingjiao/npc/obj/gangdao")->wield();
       }
void init()
{
	add_action("do_answer","answer");
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name") != "明教" && (int)this_player()->query("combat_exp")>100)
         {   command("say 我派只收无家可归的孤儿。");
            return;
        }
        if((int)ob->query("betrayer")>=10)
        {
     command("say "+RANK_D->query_respect(ob)+"多次背信弃义，我怎可收你。");
                return;
        }
        else if ((string)ob->query("gender")=="无性" && ob->query_skill("pixie-j
ian")>=50)
        {
                command("say 我看你向东厂派来的奸细。");
                return;
        }
	if ((string)ob->query("family/family_name") == "灵鹫宫" 
		&& ob->query("lingjiu/xiulian"))
	{
       		command("say "+RANK_D->query_respect(ob)+"，你现在拜我似乎会有很大损失，你能拿定主意吗？(answer)");
	return;		
	}	

           command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
           command("recruit "+ob->query("id"));
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
	}
return;
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                if (ob->query("age")<20)
                {
                        ob->set("title",GRN "明教" NOR + YEL +"教童" NOR);
                        return;
                }
                else
                {
                        ob->set("title",GRN "明教" NOR + YEL +"教徒" NOR);
                        return;
                }
}
void re_rank(object student)
{
                if (student->query("age")<20)
                {
                        student->set("title",GRN "明教" NOR + YEL +"教童" NOR);
                        return;
                }
                else
                {
                        student->set("title",GRN "明教" NOR + YEL +"教徒" NOR);
                        return;
                }
}
