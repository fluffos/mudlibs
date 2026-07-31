#include <ansi.h>;
inherit NPC;

void create()
{
        set_name(HIW"仙鹤"NOR, ({ "xian he", "he" }) );
        set("race", "野兽");
        set("age", 100);
        set("long", "一只年过百岁的仙鹤，你可以试着骑(qi)上去.\n");
        set("attitude", "peaceful");
        set("str",100);
        set("int",100);
        set("per",100);
        set("con",100);
        set("limbs", ({ "头部", "身体", "翅膀" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 50000000);

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 110);
        set_temp("apply/armor", 100);
        set_temp("apply/defence",190);

        setup();
}
void die()
{
        object ob,me;
me = this_player();
        message_vision("$N嘶哑的叫了几声，倒在地上死了。。。\n 一道白光闪过，一撮美丽的羽毛飘落在$N的身上。。\n\n", this_object(),me);
        ob = new("/d/hainan/obj/yumao");
        ob->move(me);
        destruct(this_object());
}
