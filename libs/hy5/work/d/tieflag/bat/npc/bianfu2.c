#include <ansi.h>
inherit NPC;
void use_poison();
void create()
{
        set_name("七彩蝙蝠", ({ "colorful bat" }) );
        set("race", "野兽");
        set("age", 4);
        set("yes_carry", 1);
        set("long", "一只浑身布满七彩的蝙蝠。\n"); 
        set("limbs", ({ "头部", "身体", "尾巴", "翅膀" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 150+random(300));
        set("combat_exp", 500000+random(1000000));
        set("bellicosity", 3000 );
        set("arrive_msg", "一声不响地飞过来");
        set("leave_msg", "一声不响地飞开了");
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) ); 
        setup();
}
void use_poison()
{
        object *enemy, ob;
        string msg; 
        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))]; 
        tell_object(ob,
"你觉得一阵剧痛，伸手一摸发现一个毒牙印痕。\n");
        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                ob->apply_condition("qicaibat", 
                (int)this_player()->query_condition("qicaibat")
                + random(10)+5);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}   
