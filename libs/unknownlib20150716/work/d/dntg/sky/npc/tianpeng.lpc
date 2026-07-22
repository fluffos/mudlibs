//sgzl
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("天蓬元帅",({"tianpeng yuanshuai","yuanshuai","tianpeng"}));
  set("gender", "男性");
  set("title", "天河");
  set("age", 35);
  set("long", "    \n一位威风凛凛的大帅，负责巡查天河。\n");
  set_level(170);
  set("attitude", "heroism");
  set("class", "xian");
  set("daoxing", 2000000);
  set("force_factor", 40);
  set("mana_factor", 40);
  set("per", 13);
  set_skill("spells", 1700);
  set_skill("dao", 1700);
  set_skill("force", 1700);
  set_skill("zhenyuan-force", 1700);
  set_skill("rake", 1700);
  set_skill("skyriver-rake", 1700);
  set_skill("parry", 1700);
  set_skill("yanxing-steps", 1700);
  set_skill("dodge", 1700);
  set_skill("unarmed", 1700);
  set_skill("wuxing-quan", 1700);


map_skill("spells", "dao");
map_skill("force", "zhenyuan-force");
map_skill("rake", "skyriver-rake");
map_skill("parry", "skyriver-rake");
map_skill("dodge", "yanxing-steps");
map_skill("unarmed", "wuxing-quan");
  set("inquiry", ([
  "name"   : "天蓬元帅",
  "here"   : "天河",
]));


setup();

carry_object("/d/kaifeng/obj/jiuchipa")->wield();
carry_object("/d/obj/armor/tongjia")->wear();

}

int accept_fight(object me)
{
  message_vision("天蓬元帅对$N把眼一瞪，喝道：呔，大胆，还不退下！\n", me);
  return 0;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

int heal_up()
{

  if( environment() && !is_fighting() ) 
    {
    call_out("leave", 1);
    return 1;
    }
    return ::heal_up() + 1;
}

void leave()
{
        object stone;

        this_object()->add("time", 1);
        if( (int)this_object()->query("time") >= 3 ) {
        message("vision",name() + "吐了口唾沫，骂道：下次别叫老子碰到！
天蓬元帅走了出去。\n", environment(),this_object() );
        destruct(this_object());

        }
        return;
}

void unconcious()
{
  object ob = query_temp("my_killer");
  object me = this_object();
  object temp_man; 
  /*
  if (ob && ob->query("dntg/bmw")=="fight")
  {
    ob->set("dntg/bmw","done");
    temp_man = new ("/d/dntg/sky/npc/announcer");
    temp_man->announce_success (ob);
  }
  */
  message_vision ("\n$N冷哼一声化作一股狂风不见了。\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void destruct_me(object me)
{
  destruct(me);
}

void die()
{
  unconcious();
}

