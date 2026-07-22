// 夏值功曹
//created 4-8-97 pickle
inherit NPC;
 
void create()
{
        set_name("月值功曹", ({ "yuezhi gongcao", "yue", "month",
"gongcao" }) );
        set("gender", "男性" );
        set("long","
四值功曹乃是托塔李天王帐前猛将。因经验不足而
出战失利，被罚为巡逻官。四人因为志同道合结为
金兰兄弟。月值功曹排行老二。他出师月宫，一手
灵活的雪山剑法，且在百花掌上有极深的造旨。\n"
        );
        set("age",38);
        set_level(110);
        set("str",20);
        set("daoxing",1550000);
        set("force_factor", 60);
        set("mana_factor", 50);
        set("eff_dx", 200000);
        set("nkgain", 340);
        set_skill("unarmed",1100);
        set_skill("parry",1100);
        set_skill("dodge",1100);
        set_skill("sword",1100);
        set_skill("snowsword",1100);
        set_skill("force",1100);
	set_skill("moshenbu", 1100);
	set_skill("baihua-zhang", 1100);
	set_skill("spells", 1100);
	map_skill("unarmed", "baihua-zhang");
	map_skill("dodge", "moshenbu");
        map_skill("parry","snowsword");
	map_skill("sword", "snowsword");
        set("inquiry", ([
                "name" : "在下就是月值功曹，乃托塔天王帐前大将。",
                "here" : "这里就是天宫。下官奉天王将令，在此巡查。",
        ]) );
   	set_temp("armor_level",50);
   	set_temp("weapon_level",50);
	setup();
	carry_object(0,"armor",random(5))->wear();
	carry_object(0,"shoes",random(5))->wear();
	carry_object(0,"sword",random(5))->wield();
}
