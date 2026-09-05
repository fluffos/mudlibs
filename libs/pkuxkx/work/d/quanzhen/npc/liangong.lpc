//daotong.c
//made by hacky
inherit NPC;
#include <ansi.h>
#include <random_name1.h>
void create ()
{
   string name;
   name=get_rndname();
 set_name(name,({"liangong dizi","dizi"}));
 set("title",HIB"全真派"NOR+YEL"练功弟子"NOR);
 set("long",@LONG
他是全真教刚刚入门的弟子.
LONG
    );
 
 set("gender","男性");
 set("age",16+random(7));
 set("attitude","peaceful");
 set("shen_type",0+random(1000));
  set("str",15+random(10));
  set("int",17+random(10));
  set("con",18+random(10));
  set("combat_exp",2000+random(1000));
  set("score",1000);
  set("max_neili",200+random(100));
  set("neili",200);
  set_skill("force",30);
  set_skill("parry",20);
  set_skill("dodge",30);
  set_skill("unarmed",30);
  set_temp("parry/attack",17+random(10));
  set_temp("parry/damage",5+random(4));
  set_temp("parry/defense",15+random(10));
  create_family("全真派",5,"弟子");
  setup();
 }
