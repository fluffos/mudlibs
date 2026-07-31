// wugui.c

inherit NPC;

void create()
{
        set_name("乌龟", ({ "wu gui", "gui" }) );
	set("race", "野兽");
        set("age", 10);
        set("long", "一只大乌龟，看来岁数不小了。\n");
        set("attitude", "peaceful");

	set("limbs",  ({  "头部",  "爪子",  "尾巴"  })  );
	set("verbs",  ({  "bite"})  );
        set("str", 26);
        set("cor", 30);
        set("combat_exp", 10000);

        set_temp("apply/attack", 150);
        set_temp("apply/damage", 60);
        set_temp("apply/armor", 200);

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
