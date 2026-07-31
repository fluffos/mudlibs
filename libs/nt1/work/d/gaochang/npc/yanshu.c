// laoshu.c 鼹鼠
inherit NPC;
void create()
{
    set_name("鼹鼠", ({ "yan shu", "shu", "mouse" }) );
    set("race", "野兽");
    set("age", 2);
    set("long", "一只可爱的，贼兮兮的小鼹鼠。\n");
    set("attitude", "peaceful");
    
    set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
    set("verbs", ({ "bite", "claw" }) );
    set("combat_exp", 100);
    set("shen_type", -1);
    set("env/wimpy", 70);
    set("chat_chance", 10);
    
    set_temp("apply/attack", 5);
//  set_temp("apply/damage", 20);
    set_temp("apply/dodge", 20);
    set_temp("apply/armor", 1);
        set("chat_msg", ({
        "鼹鼠「吱吱」地叫了几声。\n",       
        "鼹鼠在草丛中钻来钻去。\n",
        "鼹鼠在你脚边闻了闻，随即挖了个洞钻了进去! \n",
        (: random_move :)
        }) );
        setup();
}
