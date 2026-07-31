#include <ansi.h>
inherit BOSS;
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
        set("cor", 100);
        set("cps", 22); 
        set("fle",60);
        set("resistance/gin",35);
        set("resistance/sen",35);
        set("max_qi", 25000);
        set("max_jing", 27500);
        set("max_neili", 27500);
        set("attitude", "peaceful");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
	        (: do_chan() :),
        }) ); 
        set("limbs", ({ "头部", "身体", "尾巴", "七寸" }) );
        set("verbs", ({ "bite" }) ); 
        set("combat_exp", 3000000);
        set("bellicosity", 5 );
          set("bonus", random(100)+100);
        set_temp("apply/attack", 700);
        set_temp("apply/dodge", 1500);
        set_temp("apply/unarmed_damage", 30);
        setup();
        carry_object(__DIR__"obj/snake_dan");
} 
void init()
{
        object me, ob;

        ::init();
        if (! interactive(me = this_player()))
                return;
        
        if( !me->is_character() || me==this_object() || !me) return;
        if(me->query("vendetta/authority")) return;
        if(!userp(me)) return;
        
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
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
        enemy->start_busy(3);
        start_busy(1);
}