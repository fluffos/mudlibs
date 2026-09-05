// heaven_soldier.c

#include <ansi.h>

inherit NPC;
void backattack();
void create()
{

        set_name("金环蛇", ({ "jin she", "she" }) );
        set("race", "野兽");
        set("age", 2);
        set("long", "一只让人看了起毛骨悚然的金环蛇。\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("cor", 20);
        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("str", 40);
        set("dex", 30);
        set("con", 30);
        set("qi", 500 + random(300));
        set("max_qi", 500 + random(300));
        set("jing", 500 + random(300));
        set("max_jing", 500 + random(300));

        set("combat_exp", 50000);
        set_temp("apply/attack", 50);
        set_temp("apply/damage", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/defence",100);

        setup();

}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        object owner;
        message("vision",
                 name() + "吱吱的发出了几声怪声！\n\n"
                + name() + "钻进附近的草地就消失不见了。\n" , environment(),
                this_object() );
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("max_guard",-1);
        destruct(this_object());
}

void invocation(object who, int level)
{
        int i;
        object *enemy;
	int sexp;
        sexp=100000 + random(level/2*level*level);
        if (sexp>5000000) sexp=5000000;
        set_skill("parry", 70 + random(level));
        set_skill("dodge", 70 + random(level));
        set_skill("unarmed", 70 + random(level));
//        set("combat_exp", 100000 + random(level/2*level*level));
        set("combat_exp", sexp);
        message("vision",
                 name() + "吱吱的怪叫了几声,吐了吐舌头！\n" NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        set_leader(who);
        set("possessed",who);
}
void backattack()
{
        int i;
        object owner, *enemy;
        if(objectp(owner=this_object()->query("possessed")))
        {
                enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        }

        }

}

void die()
{
        object owner;
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("max_guard",-1);
        backattack();
        ::die();
}

