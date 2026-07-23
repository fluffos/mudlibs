#include <ansi.h>
#include <command.h>
inherit NPC;
int qijiao(); 
void create()
{
        set_name("当班差役", ({ "chaiyi"}) );
        set("long", "正在当班的差役。\n");
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
        set("reward_npc", 1);
        set("difficulty", 5); 
        set("cor", 40);
        set("cps", 25); 
        set("combat_exp", 4000000); 

        set_skill("unarmed", 200);
        set_skill("staff", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);

        

        

        setup(); 
        carry_object(__DIR__"obj/yafu")->wear();
        carry_object(__DIR__"obj/sawei")->wield();
} 
