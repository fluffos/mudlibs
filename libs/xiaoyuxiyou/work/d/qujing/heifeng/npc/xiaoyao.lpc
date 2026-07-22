//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/npc/xiaoyao.c

inherit NPC;

void create()
{
  string str;
  int i = 20+random(25);
  set_name("小妖", ({"xiao yao","yao", "jing"}));
  set("gender", "男性");
  set("age", 20*i);
  set("long","一个守洞的妖精。\n");
  set("per", 15);
  set_skill("parry", i*10);
  set_skill("unarmed", i*10);
  set_skill("dodge", i*10);
  set_skill("blade", i*10);
  set_skill("fork", i*10);
  set_skill("mace", i*10);
  set_skill("spear", i*10);
  set_skill("sword", i*10);
  set_skill("whip", i*10);
  set_skill("axe", i*10);
  set_skill("hammer", i*10);
  set_skill("rake", i*10);
  set_skill("stick", i*10);
  set_skill("staff", i*10);
  set_skill("dagger", i*10);
  set("force_factor",10*i);
  setup();
  carry_object("/d/qujing/yinwu/obj/cloth")->wear();
  str = "/d/qujing/yinwu/obj/weapon0";
  str[strlen(str)-1] = '0'+random(6);
  carry_object(str)->wield();
}

void die ()
{
  object me = this_object();
  object where = environment (me);

  if (! present("yao jing 4",where) &&
      where->query("short")=="平台")
  {
    object ob = new (__DIR__"xiaoyao");
    ob->move(where);
    message_vision ("\n只见从前方又跑过来一个小妖。\n",me);   
  }
  destruct (me);  
}

void unconcious ()
{
  die();
}
