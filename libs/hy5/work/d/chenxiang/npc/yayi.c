 // garrison.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("³ÁÏãÑÃÒÛ", ({ "yayi", "ya" }) );
        set("long",
                "ÕýÔÚÉÏÌÃµÄÑÃÒÛ£¬Ç§Íò²»ÒªÈÇËûÃÇ\n"); 
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
        set("pursuer", 1); 
        set("str", 27);
        set("cor", 26);
        set("cps", 25); 
        set("combat_exp", random(5000000)); 
        set_skill("unarmed", 70+random(200));
        set_skill("staff", 70+random(200));
        set_skill("parry", 70+random(200));
        set_skill("dodge", 70+random(200));
        set_skill("move", 100+random(200)); 
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/damage", 30+random(100));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);
        set("chat_chance", 1);
        set("chat_msg", ({
"³ÁÏãÑÃÒÛµÍÉùÐûµÀ£ºÍþ¡«¡«¡«¡«Îä¡«¡«¡«¡«\n"
        }) ); 
        setup(); 
        carry_object(__DIR__"obj/yafu")->wear();
        carry_object(__DIR__"obj/spear")->wield();
}   
