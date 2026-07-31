#include <ansi.h>
inherit NPC;
void create()
{
        set_name(RED "斑斓猛虎" NOR, ({ "lao hu","tiger" }) );
        set("race", "野兽");
        set("age", 20);
        set("attitude","aggressive");
        set("str",100);
        set("long",RED "    一只凶猛的吊睛白额锦毛大虫!!" NOR+"但见:\n"+@LONG
               毛披一带金黄色，爪露银钩十八只。
               睛如闪电尾如鞭，口似血盆牙似戟。
               伸腰展臂势狰狞，摆尾摇头声霹雳。
               山中狐兔尽潜藏，涧下獐鹿皆敛达。
LONG);

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 1000000);
        setup();
        carry_object(__DIR__"obj/tigercloth")->wear();
}


