// yanyuan.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("颜垣", ({ "yan yuan", "yan" }));
        set("title",GRN "明教" NOR + YEL +"掌旗使" NOR);
        set("long",
"颜垣是明教厚土旗掌旗使，。\n");
        set("gender", "男性");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);

        set("max_kee", 800);
        set("max_gin", 600);
	set("max_sen", 300);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 20);
        set("combat_exp", 50000);

        set_skill("force", 50);
       set_skill("jiuyang-shengong", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("sword", 50);
        set_skill("xiaoyao-jian", 40);
        set_skill("xiaoyao-zhang", 40);
        set_skill("taxue-wuhen", 40);
        set_skill("strike", 50);
        set_skill("literate",40);	
               	

        map_skill("force", "jiuyang-shengong");
        map_skill("parry", "xiaoyao-jian");
        map_skill("sword", "xiaoyao-jian");
        map_skill("dodge", "taxue-wuhen");
        map_skill("strike", "xiaoyao-zhang");

        prepare_skill("strike", "xiaoyao-zhang");

        create_family("明教", 21, "弟子");

        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/mingjiao/obj/huangshan")->wear();
       }
void attempt_apprentice(object ob)
{

        if((int)ob->query("betrayer")>=10)
        {
                command("say "+RANK_D->query_respect(ob)+"多次背信弃义，我怎可收你。");
                return;
        }
        else if ((string)ob->query("gender")=="无性" && ob->query_skill("pixie-jian")>=50)
        {
                command("say 我看你向东厂派来的奸细。");
                return;
        }

           command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
           command("recruit "+ob->query("id"));


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

