
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// baixiang-zunzhe.c...weiqi, 97.09.15.

inherit NPC;
#include "/d/migong/romnpc2.c"

void create()
{
   set_name("白象尊者", ({"baixiang zunzhe", "baixiang", "zunzhe"}));
   set("title", "二大王 象魔王");
   set("gender", "男性" );
   set("age", 43);
   set("per", 112);//no rongmao description.
   set("str", 50);
   set("long", "狮驼山做二大王，\n生平最怕的是老鼠，看到尖嘴猴腮的人就讨厌。\n");
   set("class", "yaomo");
   set("combat_exp", 53800000);
   set("attitude", "peaceful");
   create_family("大雪山", 2, "弟子");


  set("str",100);
  set("dex",100);
   set("max_kee", 1200);
   set("max_jing", 600);
   set("force", 1600);
   set("max_force", 800);
   set("mana", 800);
   set("max_mana", 400);   
   set("force_factor", 60);
   set("mana_factor", 20);

        set("eff_dx", -200000);
        set("nkgain", 400);


   setup();
   initlvl((700+random(700)),38);

   carry_object("/d/obj/armor/yinjia")->wear();
   carry_object("/d/obj/weapon/blade/yanblade")->wield();
}


void init()
{       
   object ob=this_player();

   ::init();
   if ( ((string)ob->query("gender")=="男性") && ((int)ob->query("str") < 20) && (random(3) > 1) )
        {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        switch( random(1) ) {
                case 0:
     command("kick " + ob->query("id"));
     command("say 尖嘴猴腮！");
     command("laugh");
     break;
   }
}
void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");

object taishang = new (__DIR__"pusa");
  if (ob)
  {
    ob->set_temp("obstacle/shituo2_killed",1);
    taishang->announce_success (ob);
  destruct (taishang); 
  }
  message_vision ("\n$N无可奈何地现了真身，原来是一只白象。\n",me);
  message_vision ("\n白象飞天而走。\n",me);
  

::die();
}



void unconcious ()
{
  die ();
}
int accept_fight(object ob)
{
  
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);

  ::kill_ob(ob);
}
