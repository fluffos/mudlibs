// NPC: /d/huashan/npc/eyu.c
// Date: Look 99/03/25
// Modify by Lklv 2001.10.18

inherit NPC;

void create()
{
        set_name("鳄鱼", ({ "e yu", "eyu" }));
        set("race", "野兽");
        set("age", 10);
        set("long", "一条庞大无比的大鳄鱼，张开大嘴象你游来。\n");
        set("attitude", "aggressive");
        set("str", 70);
        set("con", 50);
        set("max_qi", 8000);
        set("no_get", "鳄鱼对你而言太重了。\n");
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 500000);
        set_temp("apply/attack", 200);
        set_temp("apply/armor", 200);
        setup();
}
void die()
{
        object sword;
        sword = unew("/clone/weapon/sword/bishui-jian");
        if( clonep(sword) ) {
		sword->move(environment(this_object()));
        }
	::die();
}

