// huo-chan.c

#include <ansi.h>
inherit BHNPC;

void create()
{
        set_name(RED"Ç§Äê»ðó¸"NOR, ({ "huo chan", "chan" }) );
        set("race", "Ò°ÊÞ");
        set("age", 100);
        set("long", "Ò»Ö»°ºÊ×Í¦ÐØ£¬Í¨Ìå´¿ºì£¬Åç×Å»ðÃç£¬¡°°º°º¡±Ö±½ÐµÄó¸òÜ¡£\n");
        set("attitude", "aggressive");
        
        set("str", 30);
        set("cor", 30);

        set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°½Å", "ºó½Å" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("age", 50);
       
        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                "»ðó¸°º°ºÖ±½Ð£º°º£¡°º£¡°º£¡°º£¡°º£¡°º£¡\n",
                "»ðó¸Í»È»¿ÚÍÂ´ó»ð£¬µ½´¦ÂÒÅç¡£\n"
        }) );
                
        set_temp("apply/attack", 45);
        set_temp("apply/damage", 30);
       set_temp("apply/armor", 5);

        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                random(ob->query_kar() + ob->query_per()) < 30) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }       
}
void die()
{
        object ob;
        message_vision("$N°ºÒ»Éù£¬±ÐÃüÁË£¡\n", this_object());
          ob = new("/d/mingjiao/npc/obj/si-huochan.c");
        ob->move(environment(this_object()));
        destruct(this_object());
}

