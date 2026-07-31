// Npc : /u/poq/sdxl/npc/dumang.c 毒蟒
// by poq@jyqx 97/7

inherit NPC;

void create()
{
    set_name("毒蟒", ({ "du mang", "mang" }) );
    set("race", "野兽");
    set("age", 4);
    set("long", "一条碗口粗细的三角头巨蟒。\n");
    set("attitude", "peaceful");

    set("str", 26);
    set("cor", 30);

    set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
    set("verbs", ({ "bite" }) );

    set("combat_exp", 10000);

    set_temp("apply/attack", 15);
    set_temp("apply/damage", 6);
    set_temp("apply/armor", 2);

    setup();
}

void die()
{
    object ob,ob1;
    ob = this_object();
    message_vision("$N全身扭曲，翻腾挥舞，蛇头始终难以动弹，过了良久，终於僵直而死。\n", this_object());
    ob1 = new(__DIR__"dan");
    if (ob1) ob1->move(environment());
    destruct(this_object());
}
