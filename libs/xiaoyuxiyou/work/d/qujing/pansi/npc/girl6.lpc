// created 11/20/1997 by snowcat

inherit NPC;

void create()
{
  set_name("金莲", ({ "jin lian", "jin", "lian" }));
  set("title", "七姐妹");   
  set("long", "一位红霞脸朱唇蛾眉蝉鬓的美女子。\n");
  set("gender", "女性");
  set("age", 20);
  set_level(72);
  set("attitude", "heroism");
  set("per", 30);
  set("force_factor",720);
  set("mana_factor",720);

  set_skill("spells",720);
  set_skill("dao",720);
  set_skill("unarmed",720);
  set_skill("puti-zhi", 720);
  set_skill("dodge",720);
  set_skill("jindouyun",720);
  set_skill("qianjun-bang",720);
  set_skill("parry",720);
  set_skill("force",720);
  set_skill("wuxiangforce",720);
  set_skill("staff",720);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  map_skill("parry", "qianjun-bang");
  setup();
  carry_object("/d/obj/cloth/nichang")->wear();
}

void die ()
{
  object me = this_object();
  message_vision ("\n$N浑身一软，攒着头现了蜘蛛精的原形。\n蜘蛛嗖的一声，钻进草丛不见了。\n",me);
  destruct(this_object());
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void hurting (object me, object ob)
{
  string *msgs = ({
    "$N将衣一掀露出肚皮，一股粗粗的白丝喷将出来将$n一缠！\n",
    "$N扒开衣服肚子一挺只见股股白丝射向$n！\n",
    "$N撩起衣角，从脐眼里射出一股粗白丝向$N缠去！\n",
  });
  string *strs = ({
    "( $N顿时一个磕地，刹那间摔个天昏地暗！ )\n",
    "( $N身麻脚软扑在地上，又摇晃着爬将起来！ )\n",
    "( $N心慌气短，踉跄着倒砸在地上！ )\n",
  });
  int damage;

  if (! me)
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;
 
  message_vision ("\n"+msgs[random(sizeof(msgs))],me,ob);
  message_vision (strs[random(sizeof(strs))],ob);
  damage = ob->query("max_kee")/(8+random(4));
  ob->add("kee",-damage); 
  ob->add("sen",-damage); 

  call_out ("hurting",random(10)+10,me,ob);  
}