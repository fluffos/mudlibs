//小沙弥
//by icer
#include <ansi.h>


inherit NPC;

int ask_duan();


void create()
{
        set_name("小沙弥", ({ "xiao shami","shami" }));
        set("long", "这是一个眉清目秀的小沙弥，他低着头，微闭双目，双手合十。\n");
        set("gender", "男性");
        set("rank_info/respect", "小师傅");
        set("age", 14);
        set("str", 12);
        set("dex", 20);
        set("con", 14);
        set("int", 18);
        set("shen_type", 500);

        set_skill("finger", 20);
        set_skill("force", 30);
        set_skill("dodge", 10);

        set("combat_exp", 1500);

	set("attitude", "peaceful");
	set("class", "bonze");
        set("max_qi", 80);
        set("max_jing", 80);
        set("neili", 80);
        set("max_neili", 80);
        set("inquiry", ([
	    "段皇爷" : (: ask_duan :),
       ]) );

        setup();
        carry_object("/d/shaolin/obj/cloth")->wear();
}

int ask_duan()
{
	command("say 段皇爷早已不在人世，累施主空走一趟。且待小僧恭送施主下山。\n");
	this_player()->set_temp("marks/沙1",1);
	return 1;
}

int accept_object(object me, object ob)
{
        if (ob->query("id")=="hua juan")
	{
		if (me->query_temp("marks/沙1",1))
		{
           say("沙弥接过画卷，不敢打开观看，合十行了一礼，转身入内。\n");
              say("不久沙弥回来低眉合十道：恭请施主。\n");
			me->set_temp("marks/沙2",1);
			return 1;
		}
	}
}


