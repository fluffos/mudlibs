// create by snowcat 11/6/1997

inherit NPC;

void create()
{
  set_name("妖王", ({"yao wang", "wang" }));
  set("title","赛太岁");
  set("gender", "男性");
  set("age", 80);
  set_level(80);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("force_factor",800);
  set("mana_factor", 40);

  set_skill("unarmed",800);
  set_skill("dodge",800);
  set_skill("parry",800);
  set_skill("spells",800);
  set_skill("force",800);
  set_skill("gouhunshu",800);
  set_skill("tonsillit",800);
  set_skill("ghost-steps",800);
  set_skill("jinghun-zhang",800);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("dodge", "ghost-steps");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("eff_dx",-150000);
  set("nkgain",200);
  
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  
}

void die()
{
  object where = environment();
  if (where)
  {
    message("sound","\n\n只听得半空厉声高叫：“手下留情，观音来也！”\n",where);
    message("sound", "\n妖王打了一个滚，现了金毛兽原形，被一道金光罩去。\n\n", where);
  }

  destruct (this_object());
}
