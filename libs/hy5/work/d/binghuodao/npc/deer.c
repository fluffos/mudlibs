// monkey.c

inherit NPC;

void create()
{
    set_name("梅花鹿", ({ "deer" }) );
    set("gender", "雄性");
    set("race", "野兽");
    set("age", 5);
    set("long",
        "鹿悠闲地吃着草。\n");
    set("combat_exp", 500);
    set("shen_type", -1);
    set("attitude", "peaceful");
    set("limbs", ({ "头", "前腿", "后腿", "尾巴" }) );
    set("verbs", ({ "bite", "claw" }) );

    set("water", 200);
    set("food", 200);

    set("apply/attack", 10);
    set("apply/defense", 10);

    /* set("chat_chance", 10);
    set("chat_msg", ({
        "猴子冲着你大扮鬼脸，叽叽歪歪一阵乱叫......!\n",
        "猴子忽然跳了过来，一个倒勾，前爪一伸摘了你的草帽!\n",
        "猴子轰的一声一起从这株树跳到那株树，把你吓了一大跳!\n",
    }) );  

    set_skill("unarmed", 25);
    set_skill("parry", 20);
    set_skill("dodge", 20); */

    setup();
}
