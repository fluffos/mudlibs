inherit NPC;

#include <ansi.h>

#include "/new_quest/qmingjiao.h"
#include "/new_quest/quest.h"
void create()
{
        set_name("唐洋", ({ "tang yang", "tang" }));
        set("title",GRN "明教" NOR + YEL +"掌旗使" NOR);
        set("long","他是明教洪水旗掌旗使。\n");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "friendly");
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
        set("combat_exp", 58000);
        set_skill("force", 55);
        set_skill("shenghuo-xinfa", 65);
        set_skill("dodge", 50);
        set_skill("parry", 55);
        set_skill("claw", 55);
        set_skill("sword",45);
        set_skill("strike",50);
        set_skill("datengnuo-bufa", 40);
        set_skill("shenghuo-shengong", 50);
        set_skill("literate",40);
        map_skill("force", "shenghuo-xinfa");
        map_skill("parry", "shenghuo-shengong");
        map_skill("dodge", "datengnuo-bufa");
        map_skill("strike","shenghuo-shengong");
        map_skill("sword","shenghuo-shengong");
        prepare_skill("strike", "shenghuo-shengong");
        set("inquiry", ([
        "quest":   (: ask_quest() :),
      ]));

        create_family("明教", 21, "弟子");
        setup();
        carry_object("/d/mingjiao/obj/huangshan")->wear();
        carry_object("/d/mingjiao/npc/obj/gangdao")->wield();
       }


int do_kill(string str)
{
        if ((str == "tang") || (str == "tang yang"))
	{
		command("say 我不和你打\n");
	        return 1;
	}
	return 0;
}

int do_hit(string str)
{
        if ((str == "tang") || (str == "tang yang"))
	{
		command("say 我不和你打\n");
	        return 1;
	}
	return 0;
}
