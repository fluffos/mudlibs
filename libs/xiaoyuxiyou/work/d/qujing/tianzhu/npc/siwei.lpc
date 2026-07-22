// created by snowcat on 12/5/1997

inherit NPC;

void create()
{
  int i = 30+random(10);
  set_name("皇宫伺卫", ({"si wei", "wei"}));
  set_level(i);
  set("gender", "男性");
  set("age", 40);
  set("long","一位守卫皇宫的伺卫官。\n");
  set("per", 15);
  set_skill("parry",10*i);
  set_skill("unarmed",10*i);
  set_skill("dodge",10*i);
  set("force_factor",20*i);
  setup();
  carry_object("/d/obj/armor/tiejia")->wear();
  switch (random (5))
  {
    case 0:
    {
      carry_object("/d/obj/weapon/spear/changqiang")->wield();
      break;
    }
    case 1:
    {
      carry_object("/d/obj/weapon/sword/changjian")->wield();
      break;
    }
    case 2:
    {
      carry_object("/d/obj/weapon/blade/blade")->wield();
      break;
    }
    case 3:
    {
      carry_object("/d/obj/weapon/fork/gangcha")->wield();
      break;
    }
    case 4:
    {
      carry_object("/d/obj/weapon/rake/gangpa")->wield();
      break;
    }
  }
}

void kill_ob (object ob)
{
  object me = this_object();
  object where = environment (me);
  object bing1 = present ("gong bing 1",where);
  object bing2 = present ("gong bing 2",where);

  if (bing1)
    bing1->kill_ob(ob);
  if (bing2)
    bing2->kill_ob(ob);
  ::kill_ob(ob);
}

void unconcious ()
{
	die();
}

void die ()
{
	message_vision ("\n$N跌跌撞撞勉强爬回宫门。\n",this_object());
	powerup(0,1);
	remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());
}


