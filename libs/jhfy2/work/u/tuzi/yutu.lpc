// yutu.c 玉兔
inherit NPC;
void create()
{
        set_name("玉兔", ({
 "yu tu", "yu", "tu","hare" }) );
    set("race", "野兽");
    set("age", 5);
        set("no_die",1);
    set("long", "它是广寒宫里的玉兔，给兔子(tuzi)拐骗下凡了的。\n");
    set("attitude", "peaceful");
    
    set("limbs", ({
 "头部", "身体", "前脚", "后脚", "尾巴" }) );
    set("verbs", ({
 "bite", "claw" }) );
    set("combat_exp", 500000);
    set("chat_msg", ({
        (: this_object(), "random_move" :),
    }) );
    
    set_temp("apply/attack", 200);
    set_temp("apply/defense", 500);
    set_temp("apply/damage", 200);
    set_temp("apply/armor", 5000);
    setup();
}
void die()
{
    object ob;
    message_vision("$N凄惨的嚎了几声，死了。\n", this_object());
    ob = new(__DIR__"xianturou");
    ob->move(environment(this_object()));
    destruct(this_object());
}
    
