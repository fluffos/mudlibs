// created 4/5/1997 by snowcat
#include <ansi.h>
#define NAME "铁扇公主"
inherit NPC;
inherit F_MASTER;

int test_player (object who);

void create()
{
  string dir;
  set_name(NAME, ({"tieshan gongzhu", "gongzhu", "princess"}));
  set("title", "火焰山红纶罗刹");
  set("gender", "女性");
  set("age", 28);
  set("long", "火焰山铁扇公主。\n");
  set_level(95);
  set("rank_info/respect", "红纶公主");
  
  set_skill("snowsword",950);
  set_skill("sword",950);
  set_skill("dragonfight",950);
  set_skill("unarmed",950);
  set_skill("dodge",950);
  set_skill("parry",950);
  set_skill("spells",950);
  set_skill("dragonstep",950);
  map_skill("dodge", "dragonstep");
  map_skill("unarmed", "dragonfight");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("force_factor", 40);
  set("eff_dx",80000);
  set("nkgain",140);
  create_family("翠云山芭蕉洞",2,"弟子");
  setup();
/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
*/
  dir = "/d/qujing/firemount/";
  carry_object(dir+"obj/skirt")->wear();
  carry_object(dir+"obj/tieshan")->wield();
}

void die()
{
	message_vision("$N化作一道红光，冲天而去！\n\n",this_object());
	destruct(this_object());
}