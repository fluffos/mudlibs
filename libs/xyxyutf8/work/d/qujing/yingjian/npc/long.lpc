//Cracked by Roath

inherit NPC;
#include <ansi.h>

void create()
{
          set_name("小白龙", ({"bai long","long","dragon"}));
          set("long","他本是西海龙王敖闰之子，因犯了逆仵之罪，被贬下人间。\n");
          set_level(55);
          set("gender", "男性");
          set("age", 23);
          set("force_factor",20);
          set("env/wimpy",50);
          set_skill("unarmed",550);
          set_skill("dodge",550);
          set_skill("force",550);
          set_skill("parry",550);
          set_skill("hammer",550);
          set_skill("fork",550);
          set_skill("spells",550);
          set_skill("seashentong",550);
          set_skill("dragonfight",550);
          set_skill("dragonforce",550);
          set_skill("huntian-hammer",550);
          set_skill("fengbo-cha",550);
          set_skill("dragonstep",550);
          set_skill("longshen-yinggong",100);
          set_skill("jinlin-jia",550);
          map_skill("jinlin-jia","longshen-yinggong");
          map_skill("spells", "seashentong");
          map_skill("unarmed", "dragonfight");
          map_skill("force", "dragonforce");
          map_skill("fork", "fengbo-cha");
          map_skill("parry", "fengbo-cha");
          map_skill("dodge", "dragonstep");

         setup();
	carry_object("/d/sea/obj/longpao")->wear();
}

void die ()
{
  object me = this_object();
  message_vision ("\n只见小鱼苗嘶叫一声，冲天而起，原来是条真龙。\n",me);
  destruct (me);
}

void unconcious ()
{
  die ();
}