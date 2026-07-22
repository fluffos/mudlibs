// jiading.c

inherit SUPER_NPC;

void create()
{
	set_name("土匪", ({"bandit"}));
	set("long","一个体型魁悟，看起来孔武有力的大个子．\n正狠巴巴的瞪着你．\n");
       	set("gender", "男性");
       	set_level(10+random(10));
       	set("age", 25+random(15));
       	set("attitude", "aggressive");
       	set("shen_type", 1);
        set_skill("blade", 100+random(100));
	set_skill("parry", 100+random(100));
	set_skill("dodge", 100+random(100));
	set_temp("weapon_level",1);
	setup();
        add_money("coin", 50);
        carry_object(0,"blade",random(2))->wield();

}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
		set_follow(ob);
}