// /d/changbai/npc/feng.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("冯锡范", ({ "feng xifan", "feng" }));
        set("nickname", HIR"一剑无血"NOR);
        set("long",
"他容貌瘦削，黄中发黑，留着两撇燕尾须。\n"
"一副没精打采的模样，倒似个痨病鬼模样。\n"
"但偶然一双眼睛睁大了，却是神光炯炯。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "heroism");
        set("shen_type", -1);

        set("str", 26);
        set("int", 30);
        set("con", 30);
        set("dex", 28);

        set("max_qi", 2500);
        set("max_jing", 1500);
        set("neili", 3500);
        set("max_neili", 3500);

        set("jiali", 80);

        set("combat_exp", 8000000);

        set_temp("apply/armor", 340);

        set_skill("force", 160);
        set_skill("dodge", 160);
        set_skill("parry", 160);
        set_skill("sword", 160);
        set_skill("strike", 160);
/*
        set_skill("ding-force", 160);
        set_skill("wugou-jianfa", 160);
        set_skill("wuyu-zhangfa", 160);
        set_skill("tiyunzong", 160);

        map_skill("strike", "wuyu-zhangfa");
        map_skill("force", "ding-force");
        map_skill("parry", "wugou-jianfa");
        map_skill("sword", "wugou-jianfa");
        map_skill("dodge", "tiyunzong");

        prepare_skill("strike", "wuyu-zhangfa");
*/
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();

}


