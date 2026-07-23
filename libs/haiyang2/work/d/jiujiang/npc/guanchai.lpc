
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("官差", ({"guan chai", "guan","chai"}));
        set("title", "盐局官差");
        set("gender", "男性");
        set("age", 34);

        set("str", 22);
        set("int", 24);
        set("dex", 18);
        set("con", 18);

        set("kee", 500); 
        set("max_jing", 500);
        set("gin", 100);
        set("max_qi", 100);
        set("sen",300);
        set("max_sen",300);
        set("combat_exp",300000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set("env/wimpy", 50);

        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 200);
		set_skill("cuff",120);
		set_skill("force",120);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 240);
        set("yunyan",4);
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

        