#include <ansi.h>

inherit NPC;

void create()
{
        set_name("游侠儿", ({ "youxia er","er","xia", "man"}) );
        set("gender", "男性");
        set_level(35);
        set("age", 25);
	set("per", 20+random(5));
        set("long","时下游侠之风甚重，连长安街头也可看到华装佩剑少年。\n");
        set("combat_exp", 50000);
        set("attitude", "heroism");
        set("str", 23);
        set("force_factor", 15);
        set_skill("sword", 250);
	set_skill("xiaofeng-sword", 240);
        set_skill("unarmed", 250);
        set_skill("parry", 250);
        set_skill("dodge", 250);
	map_skill("sword", "xiaofeng-sword");
	map_skill("parry", "xiaofeng-sword");
        setup();
        carry_object(0,"sword",random(2))->wield();
        carry_object(0,"cloth",random(2))->wear();
        carry_object(0,"shoes",random(2))->wear();
        carry_object(0,"pifeng",random(2))->wear();
        carry_object(0,"wrists",random(2))->wear();
}