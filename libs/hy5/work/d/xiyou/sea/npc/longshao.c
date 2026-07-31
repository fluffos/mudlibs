// Changed by sjmao  09-11-97
inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name("龙少爷", ({"long shaoye","shaoye","taizi","long","prince"}));

set("long","龙王的大少爷．\n");
       set("gender", "男性");
	set("int", 25);
       set("age", 26);
       set("title", "龙宫太子");
       set("attitude", "peaceful");
       set("combat_exp", 450000);
  set("daoxing", 300000);

       set("rank_info/respect", "殿下");
       set("class","dragon");
       set("per", 30);
       set("max_kee", 1000);
       set("max_gin", 1000);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 40);
       set("max_mana", 800);
       set("mana", 800);
       set("mana_factor", 40);
  
      create_family("东海龙宫", 2, "水族");
	setup();

      
        carry_object("/d/obj/weapon/fork/gangcha.c")->wield();
}

