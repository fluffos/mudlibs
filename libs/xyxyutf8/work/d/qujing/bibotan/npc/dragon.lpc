inherit NPC;

void create()
{
        set_name("五爪金龙", ({ "golden dragon", "dragon" }) );
        set("race", "野兽");
        set("gender", "雄性");
        set_level(100);
        set("age", 100);
        set("long", "一只满身金甲的五爪金龙。\n");
        set("attitude", "peaceful");
        set("looking", "威风凛凛，气势逼人。");
	set("force_factor", 50);
	set("mana_factor", 50);
        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴"}) );
        set("verbs", ({ "bite", "claw"}) );

	set("eff_dx", -500000);
	set("nkgain", 500);
        set_skill("dodge",1000);
        set_skill("parry",1000);
        set_skill("force",1000);
	set_skill("spells",1000);
        set_skill("unarmed",1000);
        set_temp("apply/damage", 40);
	set_temp("apply/armor", 60);	
	set_weight(5000000);
        setup();
}
void init()
{
        object ob;

        ::init();
        set("chat_chance", 5);
        set("chat_msg", ({
	    "五爪金龙在半空中盘旋了几圈。\n",
            "五爪金龙发出一阵龙吟。\n",
        }) );
}


int heal_up()
{

        if( environment() && !is_fighting() ) {
                call_out("leave", 0);
                return 1;
        }
        return ::heal_up() + 1;
}
