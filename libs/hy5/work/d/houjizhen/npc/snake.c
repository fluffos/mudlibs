// snake.c
// by dicky

inherit NPC;

void create()
{
        set_name("竹叶青", ({ "snake", "she" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一条碧绿的蛇，不仔细，会将它和周边碧绿的树叶混为一体。\n");
        set("attitude","killer");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 6000);

        set_temp("apply/attack", 20);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 1);

        setup();
}
 
