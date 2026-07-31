// Modify By River 98/12
inherit NPC;

void create()
{
         set_name("小道童", ({ "xiao daotong", "xiao","daotong" }));
	 set("gender", "女性");
	 set("age", 16);
         set("long", "她是玉虚观内的一个小道童。\n");
	
	 set("combat_exp", 10000);
         set("shen_type", 100);

	 set("attitude", "peaceful");
	
	 set_skill("unarmed", 40);
	 set_skill("dodge", 40);
	 set_temp("apply/attack", 10);
	 set_temp("apply/defense", 10);

	 setup();
	 carry_object(__DIR__"obj/greenrobe1")->wear();
}
