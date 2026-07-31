#include <ansi.h>
inherit NPC;
void do_chan();
void create()
{
        string *names = ({"青蛇","绿蛇","花蛇"}); 
        set_name( names[random(sizeof(names))], ({ "big snake","snake"}));
        set("vendetta_mark","snake");
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 20);
        set("long", "这是一条大蛇。\n");
      
        set("str", 40);
        set("cor", 10);
        set("cps", 22); 
        set("fle",60);
        set("resistance/gin",35);
        set("resistance/sen",35);
        set("max_qi", 200);
        set("max_jing", 300);
        set("max_neili", 300);
        set("attitude", "peaceful");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
	        (: do_chan() :),
        }) ); 
        set("limbs", ({ "头部", "身体", "尾巴", "七寸" }) );
        set("verbs", ({ "bite" }) ); 
        set("combat_exp", 3000000);
        set("bellicosity", 5 );
        
        set_temp("apply/attack", 40);
        set_temp("apply/dodge", 40);
        set_temp("apply/unarmed_damage", 40);
        setup();
				carry_object("/clone/drug/gaoyao")->set_amount(1);
        carry_object(__DIR__"obj/snake_dan");
} 

void do_chan() {
        object *enemies,enemy;
        string msg;
        int be_damaged;
        enemies = query_enemy();
        if (!enemies || sizeof(enemies)==0)
	        return;
        enemy = enemies[random(sizeof(enemies))];
        msg = HIG"\n$N箭射一般扑上来，缠住了$n！\n"NOR;
        message_combatd(msg,this_object(),enemy);
        if (! enemy->is_busy())
                enemy->start_busy(3);

        start_busy(1);
}
