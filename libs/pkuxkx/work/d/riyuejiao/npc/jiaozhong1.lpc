//jiaozhong1.c	日月教众
//by bing
inherit NPC;
#include "riyuenpc.h"
#include <ansi.h>
void create()
{
        set_name("日月教众", ({ "riyue jiaozhong", "jiaozhong","zhong" }));
        set("long","他是日月神教教下弟子，入教不久，功夫不是很深。\n");
	set("gender", "男性");
        set("age", 24);
        set("shen_type", -1);
        set("str", 20);
        set("int", 23);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 200);
        set("max_neili", 200);
        set("combat_exp", 5000);

        set("inquiry", ([
            "东方不败" : "东方教主的名字也是你叫得的？",
            "东方教主" : (: ask_df :),
	    "任我行" : (: ask_ren :),
	      ]) );

        set_skill("force", 40);
        set_skill("riyue-shengong", 40);
        set_skill("dodge", 20);
        set_skill("parry", 30);
	set_skill("strike",30);
	set_skill("kaishan-zhang",30);
        set_skill("feitian-shenfa", 20);
        set_skill("literate",40);
        map_skill("force", "riyue-shengong");
        map_skill("parry", "kaishan-zhang");
        map_skill("dodge", "feitian-shenfa");
        map_skill("strike","kaishan-zhang");
	create_family("日月神教", 22, "弟子");
        setup();
        carry_object(__DIR__"obj/heiyi")->wear();
}

