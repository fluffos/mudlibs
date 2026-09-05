//jiaozhong4.c	日月教众
//by bing
inherit NPC;
#include "riyuenpc.h"
#include <ansi.h>
void create()
{
        set_name("日月教众", ({ "riyue jiaozhong", "jiaozhong","zhong" }));
        set("long","他是日月神教教下弟子，入教已久，功夫已属一流，是教中好手。。\n");
	set("gender", "男性");
        set("age", 35);
        set("shen_type", -1);
        set("str", 20);
        set("int", 23);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 500);
        set("max_neili", 500);
        set("combat_exp", 50000);

        set("inquiry", ([
            "东方不败" : "东方教主的名字也是你叫得的？",
            "东方教主" : (: ask_df :),
	    "任我行" : (: ask_ren :),
	      ]) );

        set_skill("force", 60);
        set_skill("riyue-shengong", 60);
        set_skill("dodge", 40);
        set_skill("parry", 40);
	set_skill("strike",40);
	set_skill("kaishan-zhang",40);
        set_skill("feitian-shenfa", 40);
        set_skill("literate",60);
        map_skill("force", "riyue-shengong");
        map_skill("parry", "kaishan-zhang");
        map_skill("dodge", "feitian-shenfa");
        map_skill("strike","kaishan-zhang");
	create_family("日月神教", 22, "弟子");
        setup();
        carry_object(__DIR__"obj/heiyi")->wear();
}

void init()
{

}

void do_enter(string arg)
{
	object me = this_player();
	
	if (me->query("family/family_name") != "日月神教" 
		&& (arg == "lou")
		|| (arg == "zhu lou"))
		kill_ob(me);
	return 0;
}
