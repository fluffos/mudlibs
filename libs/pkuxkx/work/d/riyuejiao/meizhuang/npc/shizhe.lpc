//shizhe.c	紫衫使者
//by bing
inherit NPC;
#include "riyuenpc.h"
#include <ansi.h>
void create()
{
        set_name(MAG "紫衫使者" NOR, ({ "zishan shizhe", "shizhe","zhe" }));
        set("long","他身穿紫袍，这在教中乃是地位显赫的标志。虽然他入教也不久，
但近年教中变化甚大，不可以常理度之。\n");
	set("gender", "男性");
        set("age", 45);
        set("shen_type", -1);
        set("str", 20);
        set("int", 23);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("combat_exp", 150000);

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

