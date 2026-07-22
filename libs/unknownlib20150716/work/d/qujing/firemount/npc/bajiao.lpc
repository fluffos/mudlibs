// created 4/25/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  string dir;
  int i = 20+random(10);	
  set_name("芭蕉怪", ({"bajiao guai", "wannian guai", "guai"}));
  set("gender", "男性");
  set("age", 100+random(800));
  set_level(i);
  set("per", 20);
  set("long", "芭蕉怪。\n");
  set("attitude", "peaceful");

  set_skill("dodge",i*10);
  set_skill("parry",i*10);
  set_skill("force",i*10);
  set_skill("spells",i*10);
  set_skill("unarmed",i*10);
  set_skill("whip",i*10);
  setup();
/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
*/
  dir = "/d/qujing/firemount/";
  carry_object(dir+"obj/bian")->wield();
  carry_object(dir+"obj/skirt")->wear();

}

