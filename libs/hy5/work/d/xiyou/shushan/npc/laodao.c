//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;

#define SYNTAX "指令格式：tellme [player_id] make <id>\n"

int check_ratio(object me, object ob);
int check_base_reward(object ob, int ratio);
int accept_object(object me, object ob);
void move_ob(object ob);
void destroy(object ob);

/************************************************************/

void create()
{
  set_name("怪老道", ({"guai laodao", "laodao","daoshi"}));
  set("long",
"他是剑圣的舅舅，想当年他名震江湖，外号“八百里”，只要他出手，\n"
"方圆八百里内，没有生物能生存，现在由于年纪大了，威猛不比当年。\n"
"但剑圣仍让他看守化妖炉，因为他和剑圣一样对妖魔，绝不手下留情 。\n");
  set("title", HIY"祭师"NOR);
  set("gender", "男性");
  set("per", 10);
  set("age", 100);
  set("str", 30);
  set("int", 30);
    set("max_sen", 2000);
  set("max_kee", 2000);
    set("force", 3000);
  set("max_force", 2000);
      set("mana", 3000);
  set("max_mana", 2000);
  
     
   set("attitude", "peaceful");
  set("combat_exp", 1500000);
  set("daoxing",2000000);
  set("inquiry", ([
     "name": "什么名字！我自己都不记得了！",
     "here": "这里是镇妖炉，你看不出来吗？",
     ]));
  setup();
  carry_object("/d/obj/weapon/sword/changjian")->wield();       
  //carry_object("/d/clone/misc/cloth/linen")->wear();
}
/************************************************************/

