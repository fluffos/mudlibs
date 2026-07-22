// yang.c 
inherit BHNPC;
void create()
{
	set_name("ÑîÁ«Í¤", ({ "yang lianting", "yang" }));
	set("long","ËûÉíÐÎ¿ýÎà, ÂúÁ³ò°÷×, ÐÎÃ²¼«ÎªÐÛ½¡. \n");
        set("gender", "ÄÐÐÔ");
	set("age", 40);
        set("per", 26);
	set("max_qi",500);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 10);
	set("combat_exp", 50000);
	set("shen_type", -1);
	setup();
	add_money("silver", 50);
	carry_object(__DIR__"obj/yaoshi");
        carry_object(__DIR__"obj/zaohong")->wear();
}
void die()
{
        object killer;
        if( objectp(killer = query_temp("last_damage_from")) )
                 killer->add_temp("kill yang",1);
           ::die();
}
	
