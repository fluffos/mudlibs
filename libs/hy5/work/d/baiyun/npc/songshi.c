 // XXDER@FY3
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("松实" , ({ "song shi","song" }) );
    set("nickname",HIY"啖松实"NOR);
    set("long", "乍一看去，这汉子敞衣赤足，眉目粗豪，但仔细打量，竟令人觉得他着实是个\n灵秀之人。\n");
        set("attitude", "friendly");
    set("age", 32);
        set("gender", "男性" );
        create_family("白云城",1, "狂生");
    set("per",40);
    set("combat_exp", 6000000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "松实拈着黑子沉吟半晌，忽然双眉一轩，下了一着，轻轻吁了口气。\n",
        "松实剑眉微皱，轻叹一声：这一局劫中有劫，既有共活，又有长生，何得破解？\n",
        }) );
    set_skill("move", 150);

        set_skill("parry", 180);
        set_skill("dodge", 150);
        set_skill("force", 160);
        set_skill("literate", 180);
        set_skill("sword", 240);
        set_skill("unarmed",100);
        set_skill("music",220);
        set_skill("feixian-steps",520);
        set_skill("feixian-sword",500);

        map_skill("dodge", "feixian-steps");
        map_skill("sword", "feixian-sword");
        map_skill("parry", "feixian-sword");

        map_skill("move","feixian-steps"); 
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );        
        setup();
    carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}      
