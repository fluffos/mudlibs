// /u/beyond/mr/npc/guanjia.c 总管家
// this is made by beyond
// update 1997.6.23
inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIC"总管家"NOR, ({ "zong guanjia", "guanjia", "jia"}));
        set("gender", "男性");
        set("age", 50);  
	set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("combat_exp", 70000);
        set("shen_type", 0);
        set("attitude", "peaceful");
	set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
	set("jiali",30);
	set("score", 8000);

        set_skill("cuff", 70);
	set_skill("parry",70);
	set_skill("yanling-shenfa",75);
        set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan-gong",70);

	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object(__DIR__"obj/cloth2")->wear();
	add_money("coin", 90);
}