//Cracked by Roath
// animal: snake.c
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("毒蛇", ({ "snake", "she" }) );
	set("race", "野兽");
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
        set("age", 4);
        set("long", "一只有着三角形脑袋的蛇，尾巴沙沙做响。\n");
        set("attitude", "peaceful");

        set("msg_fail", "$n冲$N嘶地一吐舌头");
        set("msg_succ", "$n嘶嘶做响，蛇头随着$N的手动了起来");
        set("msg_trained","$n悄无声息地游到$N的脚下不动了");
        set("auto_follow",0);
        set("wildness", 9);

        set("str", 26);
        set("cor", 30);

        set("combat_exp", 1000);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}
void unconcious()
{
    die();
}
