// created 11/20/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("花语", ({ "hua yu", "hua", "yu" }));
  set("title", "七姐妹");   
  set("long", "一位红霞脸朱唇蛾眉蝉鬓的美女子。\n");
  set("gender", "女性");
  set("age", 20);
  set("attitude", "heroism");
  set("per", 30);
  set("max_qi", 500);
  set("max_jing", 500);
  set("max_jing", 500);
  set("neili", 500);
  set("max_neili", 500);
  set("force_factor", 60);
  set("max_neili", 500);
  set("neili", 500);
  set("mana_factor", 60);
  set("combat_exp", 350000);
  set("combat_exp", 53350000);

 
  setup();
  initlvl((500+random(500)),13);
  carry_object("/d/obj/cloth/nichang")->wear();
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  if (ob && 
      ! ob->query_temp("obstacle/pansi_killed_"+me->query("name")))
  {
    ob->set_temp("obstacle/pansi_killed_"+me->query("name"),1);
    ob->add_temp("obstacle/pansi_killed",1);
  }
  message_vision ("\n$N浑身一软，攒着头现了蜘蛛精的原形。\n",me);
  me->set_name("蜘蛛精", ({"zhizhu jing", "zhizhu", "jing"}));
  ::die();
}

void unconcious ()
{
  die ();
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
    "$N撩起衣角，从脐眼里射出一股粗白丝向$n缠去！\n",
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
  damage = ob->query("max_qi")/(8+random(4));
  ob->add("qi",-damage); 
  ob->add("jing",-damage); 

  call_out ("hurting",random(10)+10,me,ob);  
}
