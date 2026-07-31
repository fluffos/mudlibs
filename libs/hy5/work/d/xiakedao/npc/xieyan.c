///xieyan.c 谢烟客

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("谢烟客", ({ "xie yanke", "xie", "yanke" }));
        set("long", "他就是摩天崖的主人。看年纪大约五十多岁，\n"
                   +"年轻时好武成兴，无比骄傲，自认为天下第一。\n");
        set("gender", "男性");
        set("age", 50);
        set("shen_type",1);
        set("attitude", "peaceful");
set("nickname", HIR"摩天居士"NOR);
        set("str", 30);
        set("int", 29);
        set("con", 30);
        set("dex", 28);

        set("qi", 38000);
        set("max_qi", 38000);
        set("jing", 38000);
        set("max_jing", 38000);
        set("neili", 51500);
        set("max_neili", 51500);
        set("jiali", 50);
        set_skill("parry", 380);
	set_skill("force", 380);
	set_skill("unarmed", 380);
	set_skill("dodge", 380);
	set_skill("taixuan-gong", 550);
	set_skill("feixian-steps", 580);
	set_skill("shenzhao-jing", 580);
	map_skill("force", "shenzhao-jing");
	map_skill("parry", "taixuan-gong");
	map_skill("unarmed", "shenzhao-jing");
	map_skill("dodge", "feixian-steps");
        set("combat_exp", 3500000);
        set("score", 200000);
set("max_neili",80000);
        set("neili",80000);
        set("max_qi",36800);
        set("max_jing",36800);
        set("jing",36800);
        set("qi",36800);
        set("eff_jingli",38000);
        set("jingli",38000);
        set("jiali",100);
	set("szj/passed", 1);
	set("szj/over200", 1);
	set("book_count", 1);
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "unarmed.wu" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
               
        }) );
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 2000);
	set_temp("apply/damage", 2000);


        setup();
carry_object("/clone/misc/cloth")->wear();
        add_money("gold",1);
}

