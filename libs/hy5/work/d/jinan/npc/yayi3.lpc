 // garrison.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("衙役", ({ "yayi", "ya" }) );
        set("long",
                "护卫衙门的衙役，千万不要惹他们\n"); 
        set("attitude", "heroism");
        set("vendetta_mark", "authority"); 
        set("cor", 40);
        set("cps", 25); 
        set("combat_exp", 2000000); 
        set_skill("unarmed", 200);
        set_skill("staff", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);


        

        
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/parry", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);
        
        set("chat_chance", 1);
        set("chat_msg", ({
"衙役喝道：闲杂人等，不得入内。\n"
        }) ); 
        setup(); 
        carry_object(__DIR__"obj/yafu")->wear();
        carry_object(__DIR__"obj/sawei")->wield();
}  
