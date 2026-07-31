 // garrison.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("大衙役", ({ "yayi", "ya" }) );
        set("long",
                "正在上堂的衙役，千万不要惹他们\n"); 
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

        

        
        set("chat_chance", 1);
        set("chat_msg", ({
"衙役低声宣道：威～～～～武～～～～\n"
        }) ); 
        setup(); 
        carry_object(__DIR__"obj/yafu")->wear();
        carry_object(__DIR__"obj/sawei")->wield();
}   
