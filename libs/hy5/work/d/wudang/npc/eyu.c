// animal: eyu.c

inherit NPC;

void create()
{
        set_name("鳄鱼", ({"eyu","e yu"}));
        set("race", "野兽");
        set("age", 100);
        set("long", "一条张开血盆大口的鳄鱼。\n");
        set("attitude", "aggressive");
set("qi",9000);
set("max_qi",9000);
set("max_jing",9000);
set("jing",9000);
        set("str", 35);
        set("cor", 35);
set_skill("force",500);
        set("limbs", ({ "头部", "身体", "脚部", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 800000);

          set_temp("apply/attack", 200);
          set_temp("apply/damage", 650);
        set_temp("apply/armor", 900);


        setup();
}

void die()
{
        object ob;
        message_vision("$N抽搐了几下，身体缩在一起，死了。\n", this_object());
        ob = new("/d/wudang/obj/tieluohan");
        ob->move(environment(this_object()));
        destruct(this_object());
}
