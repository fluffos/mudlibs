//jiaozhong2.c	日月教众
//by bing
inherit NPC;
#include "riyuenpc.h"
#include <ansi.h>
void create()
{
        set_name("日月教众", ({ "riyue jiaozhong", "jiaozhong","zhong" }));
        set("long","他是日月神教教下弟子，入教已有四，五年，功夫也还可以。\n");
	set("gender", "男性");
        set("age", 30);
        set("shen_type", -1);
        set("str", 20);
        set("int", 23);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 400);
        set("max_jing", 400);
        set("neili", 400);
        set("max_neili", 400);
        set("combat_exp", 15000);

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

