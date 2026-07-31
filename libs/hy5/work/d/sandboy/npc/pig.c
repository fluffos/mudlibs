inherit NPC;

void create()
{
        set_name("大肥猪", ({ "pig", "zhu" }) );
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 30);
        set("long", "一只吃得肥头大耳的猪,浑不知杀劫将临。\n");
        set("attitude", "friendly");
   set("looking", "肥肥胖胖，看起来足有二百来斤。");
        set("str", 20);
        set("dex", 40);
   set("qi", 300);
   set("jing", 300);
        set("limbs", ({ "头部", "身体" }) );
        set("verbs", ({ "bite"}) );
   set("combat_exp", 2000);
        set_skill("dodge", 20);
        set_temp("apply/armor", 30);

        setup();
}
void die()
{
           message("vision",
               name() + "哼哼叽叽地叫了几声，嘴角吐出一股血水,死了。\n", environment(),
                this_object() );
  new("/d/sandboy/obj/meat.c")->move(environment(this_object()));
        destruct(this_object());
   return;
}
