// liang.c

inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("梁子翁", ({ "liang ziweng", "liang", "ziweng" }));
        set("gender", "男性");
        set("nickname", HIR"参仙"HIW"老怪"NOR);
        set("age", 43);
        set("str", 25);
        set("per", 20);
        set("dex", 16);
        set("long", "梁子翁身材中等，满头白发如银，但脸色光润，神采弈弈，穿一
件葛布长袍，打扮非道非俗。他是长白山武学的一派宗师。\n");
        set("combat_exp", 600000);
        set("shen_type", -1);
        set("attitude", "peaceful");

        set_skill("force", 160);
        set_skill("xuantian-wuji", 180);
        set_skill("dodge", 156);
        set_skill("kunlun-shenfa", 170);
        set_skill("strike", 170);
        set_skill("parry", 180);
        set_skill("kunlun-zhang", 180);

        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("strike", "kunlun-zhang");
        map_skill("parry", "kunlun-zhang");
        prepare_skill("strike", "kunlun-zhang");

        set("neili", 3800); 
        set("max_neili", 3800);
        set("qi", 2400);
        set("max_qi", 2400);
        set("eff_jingli",2200);
        set("jingli", 2200);
        set("jiali", 50);

        setup();
        carry_object(__DIR__"obj/changpao")->wear();
}

