// chike.c 吃客

inherit BHNPC;
string query_save_file() { return DATA_DIR + "npc/吃客"; } 

void create()
{
       set_name("吃客", ({ "chi ke","ke" }));
this_object()->init_bhnpc();
set("area_name","好吃党");
set("area_file","/d/city3/npc/chike.c");
set("ziyuan","肥鸡");
set("jizhi",55);//注25这个数字关系都地盘的收入,这个数子不要超过100就可以了
set("kaifa",40); //注:这个20表示的是这个地盘资源的起始开发度,这个不要太高,最好不要超过50
	set("gender", "男性");
	set("age", 20 + random(30));

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set("apply/attack", 15);
	set("apply/defense", 15);
	set("apply/damage", 5);
	set("combat_exp", 750);
	set("shen_type", 1);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 5);
}
	
#include <die.h>
