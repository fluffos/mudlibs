// hu.c
inherit NPC;
#include <ansi.h>
int wieldblade();
 
void create()
{
        set_name("顾青枫", ({ "gu qingfeng", "qingfeng" }) );
        set("gender", "男性" );
        set("age", 52);
        set("str", 30);
        set("str", 111);
        set("cor", 40);
        set("cps", 1);
        set("no_busy", 10);
                 set("reward_npc", 1);
        set("difficulty", 35);

        set("class","huashan");
            set("resistance/kee",99);
    set("resistance/sen",99);
    set("resistance/gin",99);

    set("long",
"这黄袍道人宽袍大袖，两鬃已斑白瘦消清矍的脸上，带着种很严肃的表情，脚步
虽然很轻健，看来却不像练武功的样子。 \n"
    );
        set("force_factor", 100);
        set("combat_exp", 7000000+random(3000000));
        set("attitude", "friendly");
        set_skill("move",100);
        set_skill("force",100);
        set_skill("unarmed",10);
        set_skill("dodge",999);
        set_skill("throwing",999);
        set_skill("tanzhi-shentong",999);
        
        
        //set_skill("tangforce",100);
        //set_skill("blade",180);
        //set_skill("tang-blade",180);        
        set_skill("perception", 220);
        //set("skill_public",1);
        map_skill("throwing", "tanzhi-shentong");
        //map_skill("force", "tangforce");
        set("chat_chance", 1);
        set("chat_msg", ({
                "青枫道人喃喃道，“世事无常，如白云苍狗，又有谁能想到，这一局残棋犹在，他的人却已经不在了。”\n",
                "青枫道人凄然而笑，“这一子摆下，黑棋就不输了。”\n",  
                "青枫道人忽然挥袖拂乱了这局残棋，悠悠慨叹，“人生岂非，也正如一局棋．输赢又何必太认真呢？”\n",
        }));
        //set("skill_public", 1);
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: wieldblade  :),
        }) );
        setup();
        carry_object("/d/wudang/npc/obj/cloth")->wear();
        carry_object("/d/resort/npc/obj/bqi");
        
} 

int wieldblade()
{
command("wield piece");
perform_action("throwing.tanzhijinghun");
command("unwield piece");
return 1;
}
