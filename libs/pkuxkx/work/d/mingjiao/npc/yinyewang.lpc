
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("殷野王", ({ "yin yewang", "yin", "yewang", }));
        set("long",
        "他是一位手摇折扇的中年男子，身穿一件白布长袍。\n"
        "他是白眉鹰王殷天正之子。一双眼睛犹如冷电，精光四射，气势摄人。\n"
        );

        set("title", GRN "明教" BLU "天微堂" NOR "堂主");
        set("nickname", "一飞冲天");
        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "fighert");

        set("age", 44);
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);
        set("combat_exp", 100000);
        set("score", 5000);

        set_skill("force", 85);
        set_skill("jiuyang-shengong", 85);
        set_skill("dodge", 85);
        set_skill("datengnuo-bufa", 85);
        set_skill("strike", 95);
        set_skill("hanbing-zhang", 95);
        set_skill("parry", 85);
        set_skill("claw", 85);
        set_skill("myingzhua-gong", 85);

        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "datengnuo-bufa");
        map_skill("strike", "hanbing-zhang");
        map_skill("claw", "myingzhua-gong");

        prepare_skill("claw", "myingzhua-gong");
        create_family("明教", 21, "天微堂堂主");
        setup();

        carry_object("/d/mingjiao/npc/obj/baipao")->wear();
}


