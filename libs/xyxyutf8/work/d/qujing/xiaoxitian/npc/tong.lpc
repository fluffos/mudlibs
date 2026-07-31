// created by snowcat on 12/16/1997

inherit NPC;

string *names = ({
  "黑鼠怪",
  "黄犰怪",
  "灰狨怪",
  "白猁怪",
  "赤狻怪",
  "土猬怪",
  "石猊怪",
  "木猱怪",
  "水獾怪",
});

void create()
{
  set_name("小童", ({"xiao tong", "tong"}));
  set("gender", "男性");
  set("age", 13);
  set_level(45);

  set("per", 10);
  set_skill("parry",450);
  set_skill("unarmed",450);
  set_skill("dodge",450);
  set_skill("blade",450);
  set_skill("fork",450);
  set_skill("rake",450);
  set_skill("hammer",450);
  set_skill("sword",450);
  set_skill("stick",450);
  set_skill("staff",450);
  set("force_factor",10);
  setup();
  carry_object("/d/obj/cloth/sengyi")->wear();
  carry_object("/d/qujing/xiaoxitian/obj/shield");
}

void kill_ob (object ob)
{
  object me = this_object();

  if (me->query("id")!="yao guai")
  {
    set_level(49);
    setup();
    powerup(0,1);
    message_vision ("$N顿时变了颜色，现了妖精的本相！\n",me);
    me->set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai", "xiao tong", "tong"}));
    command("wear dun");
  }
  ::kill_ob(ob);
}