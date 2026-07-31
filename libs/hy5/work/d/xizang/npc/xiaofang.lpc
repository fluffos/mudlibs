#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("小方", ({ "xiao fang","fang" }) );
        set("gender", "男性" );
        set("long",
                "一个流浪塞外、漂泊异乡的孤独浪子。\n"
                );
        set("title", HIW"浪子"NOR);
        set("attitude", "peaceful");
        
        set("age", 28);
        set("str", 40);
        set("cor", 36);
        set("agi", 60);
        set("per", 30);
        
        set("combat_exp", 5000000);
        
        set("max_jing", 5000);
        set("max_jing", 5000);
        
        set("neili",3000);
        set("max_neili",3000);
        set("force_factor",100);
        set("no_busy",4);
        set("class","fighter");
         
        set("chat_chance", 1);
        set("chat_msg", ({
                "小方远望着着窗外的圣母雪峰，哑着嗓子道：卜鹰……我一定会找到\n你，找到一个好好活着的你……\n",
                }) ); 
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 300);
        set_skill("sword", 300);
        set_skill("doomforce", 150);

        set_skill("doomsteps", 200);
           set_skill("doomsword",150);
        
        map_skill("sword", "doomsword");
        map_skill("dodge", "doomsteps");
        map_skill("parry","doomsword"); 
        set("chat_chance_combat", 30);
        set("chat_msg_combat",({
                      (:perform_action,"sword.hunranyijian":),
        }));
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/icesword")->wield();
} 
int accept_object(object me, object obj)
{
        if(obj->query("name") == BLU"魔眼剑"NOR && obj->query("owner") == me->query("id"))
        {
                message_vision("$N紧紧握着魔眼剑，眼中泪光闪烁，苍白的脸上泛出了血色。\n", this_object());
                message_vision("$N向$n感激地点了点头：卜大哥还活着，我早知道他还活着。\n",this_object(),me);
                if(!me->query("m_success/义助卜鹰"))
                {
                        me->set("m_success/义助卜鹰",1);
                        me->add("score",200);
                }
                return 1;
        }
        else
        {
                write("小方拱手道：“君子不夺人所爱，在下不能接受您的东西。”\n");
                return 0;
        }
} 
