
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("说不得", ({ "shuo bude", "shuo", "bude", }));
        set("long",
        "他是一位笑嘻嘻的僧人，身穿一件白布长袍。\n"
        "\n"
        );

        set("title", GRN "明教" NOR "五散人");
        set("nickname", "布袋和尚");
        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 50);
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
        set_skill("hunyuan-yiqi", 85);
        set_skill("dodge", 85);
        set_skill("shaolin-shenfa", 85);
        set_skill("cuff", 95);
        set_skill("jingang-quan", 95);
        set_skill("parry", 85);
        set_skill("buddhism", 85);
        set_skill("literate", 85);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
        map_skill("parry", "jingang-quan");

        prepare_skill("cuff", "jingang-quan");
        create_family("明教", 21, "五散人");
        setup();

        carry_object("/d/mingjiao/npc/obj/baipao")->wear();
}



