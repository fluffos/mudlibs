//modified by sgzl for dntg/donghai quest
#include <skill.h>

inherit NPC;
inherit F_MASTER;



void create()
{
       	set_name("敖广", ({"ao guang", "ao","guang","longwang","wang"}));

	set("long","敖广是东海的龙王，其兄弟分别掌管东，西，南，北四海。
由余其水族众多，声势浩大，俨然独霸一方。\n");
       set("gender", "男性");
       set("age", 66);
	set("title", "东海龙王");
	set("class","dragon");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("combat_exp", 1260000);
       set("daoxing", 1500000);
       set("rank_info/respect", "陛下");
       set("per", 20);
       set("str", 30);
       set("max_kee", 3000);
       set("max_gin", 400);
       set("max_sen", 1500);
       set("force", 3000);
       set("max_force", 1500);
  


        create_family("东海龙宫", 1, "水族");
	set_temp("apply/armor",50);
	set_temp("apply/damage",25);
	setup();

        carry_object("/d/xiyou/sea/obj/longpao")->wear();
}
