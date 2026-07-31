 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("È¸×Óº×", ({ "zihe" }) );
        set("gender", "ÄÐÐÔ" );
        set("age", 35);
        set("title", HIW "Ë«ÕÆ·­Ìì"NOR);
        set("attitude", "peaceful");
        set("reward_npc", 1);
        set("intellgent",1);
        set("fly_target",1);
        set("chat_chance", 1);
        set("chat_msg", ({
//                (: random_move :),
                "È¸×Óº×à«à«µÀ£º³þÁôÏãÑ½£¬³þÁôÏã£¡¿´ÄãÕâ´ËÍùÄÄÀïÌÓ£¡\n",
        }) ); 
        set("long",     "½­ºþÖÐÈË³Æ£¢Ë«ÕÆ·­Ìì£¢µÄÈ¸×Óº×\n");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.miwu" :),
                (: perform_action, "dodge.liushuichanchan" :) 
        }) );
        set("combat_exp", 3299999);
        set_skill("unarmed", 120);
        set_skill("dodge", 100);
        set_skill("yunwu-strike", 380);
        set_skill("liuquan-steps", 370); 
        map_skill("unarmed", "yunwu-strike");
        map_skill("dodge", "liuquan-steps"); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
}      
