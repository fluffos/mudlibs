// /d/wudang/snake.c 菜花蛇
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("菜花蛇", ({ "snake", "she" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一条身长二尺的菜花蛇，盘着身，抬着头紧盯着上方。\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 1000);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        set("shen_type",-1);
set("score",200);
setup();
}

void die()
{
        object ob;
        message_vision("$N啪的一声断成两截！$N死了。\n", this_object());
        destruct(this_object());
}


