// eyu.c 鳄鱼
// By River 99.5.25
inherit NPC;

void create()
{
        set_name("鳄鱼", ({ "e yu", "e", "yu" }));
        set("race", "野兽");
        set("age", 20);
        set("long", "一条庞大无比鳄鱼，浑身长着像铁甲般的鳞片。\n");
        set("str", 70);
        set("con", 50);
        set("max_qi", 800);
        set("limbs", ({ "头部", "身体", "尾巴", "嘴巴"}) );
        set("verbs", ({ "bite" }));
        set("combat_exp", 300000);

        set_temp("apply/attack", 250);
        set_temp("apply/damage", 250);
        set_temp("apply/armor", 250);
        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player())){
             remove_call_out("kill_ob");
             call_out("kill_ob", 1, ob); 
             }
}
