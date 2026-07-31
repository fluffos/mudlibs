inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
  int i = 30+random(10);	
  set_name("长腿虾兵", ({"changtui xiabing","xiabing"}));
  set("gender", "男性");
  set_level(i);
  set("age", 25);
  set("title", "碧波潭九头驸马侍卫");
  set("long","碧波潭与龙宫和火云洞都有交情,他是来龙宫做客的,顺便也收些徒弟。\n");
  set("per", 15);
  set_skill("dodge",i*100);
  set_skill("parry",i*100);
  set_skill("unarmed",i*100);
  set_skill("force",i*100);
  set_skill("spells",i*100);
  set_skill("fork",i*100);
  set_skill("huaxue-dafa",i*100);
  set_skill("huaxue-force",i*100);
  set_skill("moyun-shou",i*100);
  set_skill("moshenbu",i*100);
  map_skill("force", "huaxue-force");
  map_skill("spells", "huaxue-dafa");
  map_skill("unarmed", "moyun-shou");
  map_skill("dodge", "moshenbu");
  map_skill("fork", "yueya-chan");
  set("force_factor", 20);
  set("mana_factor", 20);
  create_family("碧波潭", 3, "蓝");
  setup();
  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
  carry_object("d/obj/weapon/stick/mugun")->wield();
}