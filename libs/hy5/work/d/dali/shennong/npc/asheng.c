// °¢Ê¤    /d/menpai/shennong/npc/asheng.c
// by lala, 1998-01-21

inherit __DIR__"ShennongNpc.c";



void create()
{
    set_name("°¢Ê¤", ({ "a sheng", "asheng", "sheng", }) );
    set("class_score/ÉñÅ©°ï",       100);
    set("age",  25);
    set("int",  25);
    
   set("max_qi", 3700);
	set("max_jing", 3700);
	set("neili", 6500);
	set("max_neili", 6500);
	set("jiali", 30);
	set("combat_exp", 600000);
	set("score", 40000);

	set_skill("force", 170);
	set_skill("huagong-dafa", 150);
	set_skill("throwing", 170);
	set_skill("feixing-shu", 180);
	set_skill("dodge", 170);
	set_skill("zhaixinggong", 200);
	set_skill("strike", 180);
	set_skill("chousui-zhang", 180);
	set_skill("claw", 180);
	set_skill("sanyin-wugongzhao", 180);
	set_skill("parry", 170);
	set_skill("poison", 170);
	set_skill("staff", 170);
//	set_skill("tianshan-zhang", 60);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("throwing", "feixing-shu");

    setup();

    carry_object( "/clone/misc/cloth" )->wear();

    add_money( "coin", 20 + random(20) );
}


        
