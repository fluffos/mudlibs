#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("陈英勇", ({ "chen yingyong", "cyy", "yong" }));
        set("gender", "男性");
        set("age", 19);
        set("long", "他就是「电学实验室」的跑腿儿－－陈英勇。\n");
	set("title", GRN "八大山人" NOR);
	set("nickname", RED "野比" NOR);

        set("combat_exp", 3000000);
        set("shen_type", 1);

        set("max_neili",50000);
        set("neili", 50000);
        set("jiali", 1000);

        set_skill("force", 200);
        set_skill("unarmed", 500);
        set_skill("dodge", 250);
        set_skill("parry", 250);

        set("inquiry", ([
                "实验" : "“今天不上班，改日再来！”",
        ]) );

        set_temp("apply/damage", 15);

        setup();
}
