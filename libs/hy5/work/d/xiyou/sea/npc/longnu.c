// Changed by sjmao  09-11-97

inherit NPC;
inherit F_MASTER;
string expell_me(object me);



void create()
{
       set_name("龙女", ({"long nu","gongzhu","long","princess"}));

	set("long","紫云宫主人，龙王的女儿．\n");
       set("gender", "女性");
       set("age", 20);
	set("int", 25+random(5));
       set("title", "紫云公主");
       set("attitude", "peaceful");
       set("combat_exp", 350000);
       set("daoxing", 100000);

       set("rank_info/respect", "公主殿下");
       set("class","dragon");
       set("per", 30);
       set("max_kee", 900);
       set("max_sen", 700);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 40);
       set("max_mana", 500);
       set("mana", 400);
       set("mana_factor", 30);
   

           
            create_family("东海龙宫", 2, "水族");
	setup();

        carry_object("/d/obj/cloth/pinkskirt")->wear();
	carry_object("/d/xiyou/sea/obj/yincha")->wield();
}

