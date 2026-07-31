// yang.c 杨过
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小杨过",({"yang guo","yang","guo"}));
        set("title",HIW"古墓侠侣"NOR);
        set("nickname",HIY"神雕大侠"NOR);
        set("long", "他就是名满天下的杨过。虽断一臂但仍遮不去一脸的英雄豪气。\n");
        set("age", 35);
        set("attitude", "friendly");
        set("shen", 0);
	set("combat_exp", 10000000);
	set("score", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("sword", 350);
	set_skill("force", 400);
	set_skill("unarmed", 400);
	set_skill("dodge", 350);
	set_skill("parry", 350);
	set_skill("anranxiaohun-zhang",350);
	set_skill("xuantie-sword", 350);
	set_skill("xiantian-qigong", 100);
	set_skill("yunv-shenfa",300);
	map_skill("sword", "xuantie-sword");
	map_skill("parry", "anranxiaohun-zhang");
	map_skill("unarmed","anranxiaohun-zhang");
	map_skill("dodge", "yunv-shenfa");
	set("chat_chance_combat", 80);
       set("chat_msg_combat", ({
                (: perform_action, "parry.xiaohun" :),
                (: perform_action, "sword.feihongrudian" :),
                
        }) );
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 600);
	set("neili", 5000); 
	set("max_neili", 5000);
	set("max_qi", 10000);
	set("qi",10000);
	set("max_jing", 10000);
	set("jing",10000);

        setup();

        carry_object(__DIR__"obj/xtj")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object(__DIR__"obj/jinchuang");
        carry_object(__DIR__"obj/jinchuang");
        carry_object(__DIR__"obj/jinchuang");
}
