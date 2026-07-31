// guanjia.c 管家

#include <ansi.h>

int random_go(object me, string* dirs);

//int change_tianyi();
//int change_tianyao();
//int change_tianmo();
//int change_cangshi();
//int change_leidao();
string ask_cancel();
int change_mieyao();
//int change_menpainame();

//int gift();

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(WHT"管家"NOR, ({"guan jia", "master"}));
       set("long", "三界山的管家，不干涉门派纷争，于是在岛上开了一家客栈。\n");
       set("title", HIC"三界山"NOR);
       set("per", 40);
       set("gender", "男性");
       set("age", 40);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老仆人");
       set("max_kee", 500);
       set("max_gin", 100);
       set("max_sen", 500);
       set("force", 500);
       set("max_force", 500);
       set("force_factor", 50);
       set("max_mana", 500);
       set("mana", 500);
       set("mana_factor", 50);
       set("combat_exp", 45000);
       set("daoxing", 55000);

	set("inquiry", ([
	"name"     : "我是这里的老板，你有事吗？\n",
	"here"     : "这里是「浪儿店」，你有需要可以进来住住店。\n",
//        "三界山"    : (:change_menpainame:),
/*      "天一宫"   : (:change_tianyi:),
      "天妖宫"   : (:change_tianyao:),
      "天魔宫"   : (:change_tianmo:),
      "藏尸地"   : (:change_cangshi:),
      "雷刀门"   : (:change_leidao:),
*/      
      "灭妖"     : (:change_mieyao:),
//      "礼物"     : (:gift:),
	]));
	
	setup();
}

