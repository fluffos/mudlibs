 // weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("卫天鹏", ({ "wei tianpeng","wei" }) );
        set("gender", "男性" );
        set("long",
                "黑披风，红腰带，鞍旁有箭，手中有弓，腰间有刀。\n"
                );
        set("nickname", HIC"怒箭神弓斩鬼刀"NOR);
        set("attitude", "peaceful");
        set("age", 38);
//      set("str", 20);
        set("cor", 20);
        set("agi", 30);
        set("per", 5);
        set("combat_exp", 800000); 
        set("chat_chance", 5);
        set("chat_msg", ({
                "卫天鹏恨声道：谁敢得罪我们吕三爷，老子二话不说就把他一刀剁了。\n",
                }) ); 
        set_skill("unarmed", 100);
        set_skill("parry", 150);
        set_skill("dodge", 100);
        set_skill("blade", 100);
                
        setup();
        add_money("silver", 30);
        carry_object(__DIR__"obj/heipifeng")->wear();
        carry_object(__DIR__"obj/ghostblade")->wield();
}
