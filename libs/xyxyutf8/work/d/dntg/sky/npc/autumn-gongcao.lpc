// 秋值功曹
//created 4-8-97 pickle
inherit NPC;
 
void create()
{
        set_name("日值功曹", ({ "rizhi gongcao", "ri", "day",
"gongcao" }) );
        set("gender", "男性" );
        set("long","
四值功曹乃是托塔李天王帐前猛将。因经验不足而
出战失利，被罚为巡逻官。四人因志同道合而结为
金兰兄弟。日值功曹是老三，入天宫前在地府充当
勾魂使者，所以他作战经验远在老大和老二之上。\n"
        );
        set("age",35);
	set_level(155);
	set("daoxing", 2200000);	
        set("force_factor", 60);
        set("mana_factor", 60);
        set("eff_dx", 250000);
        set("nkgain", 350);
	set_skill("spells", 1500);
        set_skill("unarmed",1250);
        set_skill("parry",1405);
        set_skill("dodge",1500);
        set_skill("stick",1410);
        set_skill("kusang-bang",1410);
	set_skill("moshenbu", 1410);
        set_skill("force",1420);
        set_skill("jinghun-zhang",1500);
	map_skill("dodge", "moshenbu");
	map_skill("unarmed", "jinghun-zhang");
        map_skill("parry","kusang-bang");
	map_skill("stick", "kusang-bang");
   	set_temp("armor_level",50);
   	set_temp("weapon_level",50);
	setup();
	carry_object(0,"armor",random(5))->wear();
	carry_object(0,"shoes",random(5))->wear();
	carry_object(0,"stick",random(5))->wield();
	add_money("silver", 10);
}