// zhou.c 周芷若

#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("周芷若", ({ "zhou-zhiruo","zhiruo","zhou"}));
        set("long",
                "她是峨嵋派的第四代掌门弟子。\n"
                "一张脸秀丽绝俗。身着一身淡黄衣裳。\n"
                "略显清减的巧笑中带了些许无奈。\n"
                "她很寂寞。\n");
        set("gender", "女性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("class", "fighter");
        set("str", 130);
        set("int", 130);
        set("con", 130);
        set("dex", 130);
        set("per", 130);

        set("max_qi", 53500);
        set("max_jing",51000);
        set("neili", 353500);
        set("max_neili", 353500);
        set("jingli", 1000);
        set("max_jingli", 1000);

        set("combat_exp", 55000000);
        set("score", 1000);
        set_skill("persuading", 80);
        set_skill("force", 100);
        set_skill("throwing", 100);
        set_skill("dodge", 100);
        set_skill("finger", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("strike", 100);
        set_skill("sword", 1000);
        set_skill("claw", 100);
        set_skill("literate", 1000);
        set_skill("mahayana", 100);
        set_skill("jinding-zhang", 1300);
        set_skill("jiuyin-baiguzhao", 1300);
        set_skill("tiangang-zhi", 1300);
        set_skill("huifeng-jian", 1300);
        set_skill("zhutian-bu", 1300);
        set_skill("linji-zhuang", 330);
        map_skill("force","linji-zhuang");
        map_skill("claw","jiuyin-baiguzhao");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        prepare_skill("strike","jinding-zhang");
        set_temp("apply/attack", 500);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2550);
        create_family("峨嵋派", 4, "掌门弟子");

        setup();
        carry_object("/clone/weapon/changjian");
        carry_object("/d/emei/obj/ycloth.c")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
}

