// rewritten by snowcat on 4/12/1997
#include "cloudfog.h"

inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("云里雾", ({"cloud fog", "cloud"}));
  set("long", "红孩儿手下六健将，其中又是云里雾"+
              "和雾里云最受红孩儿的喜爱，洞中的群妖都受过他俩的指导。\n");
  set("gender", "男性");
  set("age", 20);
  set("attitude", "heroism");
  set("shen_type", 1);
  set("con", 30+random(5));
  set("force_factor", 20);
  set_level(45);
  set_skill("unarmed",450);
  set_skill("dodge",450);
  set_skill("parry",450);
  set_skill("stick",450);
  set_skill("spells",450);
  set_skill("force",450);
  create_family("翠云山芭蕉洞",3,"弟子");
  set("inquiry", ([
        "princess" :   (: test_player :),
        "铁扇公主" :   (: test_player :),
        "公主"     :   (: test_player :),
      ]));
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}