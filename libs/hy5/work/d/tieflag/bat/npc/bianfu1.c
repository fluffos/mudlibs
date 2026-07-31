#include <ansi.h>
inherit NPC;
void use_poison(); 
void create()
{
        set_name(HIC"青翼蝙蝠"NOR, ({ "deadly bat" }) );
        set("race", "野兽");
        set("age", 4);
        set("yes_carry", 1);
        set("long", "一只非常可怕的青翼蝙蝠。\n"); 
        set("limbs", ({ "头部", "身体", "尾巴", "翅膀" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 70+random(150));
        set("arrive_msg", "一声不响地飞过来");
        set("leave_msg", "一声不响地飞开了");
        set("combat_exp", 200000+random(400000));
        set("bellicosity", 3000 );
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
                ob->apply_condition("bat_poison",
                (int)this_player()->query_condition("bat_poison")
                + random(3)+5);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}      
