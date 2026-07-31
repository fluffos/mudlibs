 // weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("沈璧君", ({ "shen bijun","shen" }) );
        set("gender", "女性" );
        set("nickname", HIG"美人如玉"NOR );
        set("long",
     "她的美丽是任何人也无法形容的，有人用花来比拟美人，但花哪有她这样动人？\n有人会说她像“图画中人”，但又有哪支画笔能画出她的风韵？就算是天上的\n仙子，也绝没有她这般温柔。无论任何人，然要瞧了她一眼，就永远也无法忘记。\n这就是武林中的第一美人——沈壁君。  \n"
                );
        set("attitude", "peaceful");
         set("age", 24);
        set("str", 15);
        set("cps", 15);
        set("int",30);
        set("per", 70);
        set("combat_exp", 600000);
        set("neili", 200);
        set("max_neili", 200);
        set("mana", 100);
        set("max_mana", 100);
        set("max_qi", 400);
        set("max_jing", 400);
        set("max_sen", 400);
        set("force_factor", 10);
        set("chat_chance", 1);
        set("chat_msg", ({
             "沈壁君星眸黯然，轻轻叹了口气，闭上眼睛。\n",
                }) ); 
        set_skill("unarmed", 50);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("move", 80);
        set_skill("fall-steps", 50);
        set_skill("meihua-shou", 50);
        map_skill("dodge", "fall-steps");
        map_skill("unarmed", "meihua-shou");
                
        setup(); 
        carry_object("/d/fugui/npc/obj/w_skirt1")->wear();
}    
