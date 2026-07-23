#include <ansi.h>
inherit NPC;
void create()
{
        set_name("白衣人", ({ "man in white" }) );
        set("gender", "男性");
        set("combat_exp", 3500000);
        set("title", HIW "一动不动"NOR);
        set("long",
                "他看起来就象是二十年前就已经名动江湖的＂一剑飞花＂花满天，他
现在却站在这里一动不动！\n"
        );
        set("reward_npc", 1);
        set("difficulty", 5);
        set("neili",1000);
        set("max_neili",1000);
        set("force_factor",30);
        
        set_skill("move", 200);
        set_skill("dodge", 180);
        set_skill("sword",180);
        set_skill("feixian-sword",150);
        set_skill("feixian-steps",150);
        set_skill("unarmed",200);

        set_skill("parry",150);
        
        map_skill("parry","feixian-sword");

        map_skill("dodge","feixian-steps");
        map_skill("sword","feixian-sword");
        map_skill("move","feixian-sword");
        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
   carry_object(__DIR__"obj/hua_sword")->wield();
}      
