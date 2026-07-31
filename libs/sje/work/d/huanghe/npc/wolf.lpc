// wolf　by xiaoyao
#include <ansi.h>

inherit NPC;
void create()
{
        set_name(WHT"灰狼"NOR, ({ "hui lang", "wolf", "lang" }));
        set("race", "野兽");
        set("age", 5);
        set("long","这是一头灰色的狼，正用红色的眼睛盯着你，不时发出令人胆战的嗥声！\n");
        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 200000);
        set("str", 80);
        set("con", 80);
        set("chat_chance", 6);
        set("chat_msg", ({
              (: this_object(), "random_move" :),
        }) );
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 50);
        setup();
}

void unconcious()
{    
       object ob;
       message_vision("$N用仇恨的眼光看着你，鲜血从尖利的牙缝中流出，死了！\n", this_object());
        ob = new(__DIR__"obj/langya");
       ob->move(environment(this_object()));
       destruct(this_object());     
}
void die(){ unconcious(); }

