// wugui.c

inherit NPC;

void create()
{
        set_name("乌龟", ({ "wu gui", "gui" }) );
        set("race", "野兽");
        set("age", 10);
        set("long", "一只大乌龟，看来岁数不小了。\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 1000);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}

void die()
{
        object ob;
        message_vision("$N翻转身，死了！\n", this_object());
        ob = new(__DIR__"obj/guijia");
        ob->move(environment(this_object()));
        destruct(this_object());
}
