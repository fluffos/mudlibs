// cracked by vikee 2/09/2002   vikee@263.net
// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("金鳞怪", ({ "jinlin guai", "jinglin", "guai" }));
  set("title", "通天河");   
  set("long", "一位身着金甲的妖怪。\n");
  set("gender", "男性");
  set("age", 76);
  set("attitude", "aggressive");
  set("per", 30);
  set("max_kee", 1700);
  set("max_gin", 1700);
  set("max_sen", 1700);
  set("force", 1700);
  set("max_force", 1700);
  set("force_factor", 100);
  set("max_mana", 600);
  set("mana", 600);
  set("mana_factor", 20);
  set("combat_exp", 1500000);
  set("daoxing", 1000000);

  set_skill("spells", 30);
  set_skill("dao", 30);
  set_skill("unarmed", 85);
  set_skill("hammer", 85);
  set_skill("dragonfight", 85);
  set_skill("dodge", 80);
  set_skill("dragonstep", 70);
  set_skill("parry", 85);
  set_skill("force", 70);
  set_skill("dragonforce", 120);
  map_skill("spells", "dao");
  map_skill("unarmed", "dragon-step");
  map_skill("dodge", "dragonstep");
  map_skill("force", "dragonforce");
  setup();
  carry_object("/d/obj/armor/jinjia")->wear();
  carry_object("/d/obj/weapon/hammer/bahammer")->wield();
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object lan = present("devine basket", ob);

  if (ob)
  {

  if( (string)ob->query("quest/pending/kill/name")==me->query("name")){
        ob->set("quest/pending/kill/done", 1);
  }

     if (lan){
     	ob->set_temp("obstacle/tongtian_killed",1);
	ob->set("obstacle/tongtian" , "fight");
	message_vision("\n$N只见紫竹篮刹那间飞上天．．．\n",ob);
  	message_vision ("\n$N一甩尾巴，现出金鱼的原身。\n",me);
  	message_vision ("$N眼看金鱼乖乖地一纵身扭着腰摇晃着头游进了竹篮中\n",ob);
    	call_out ("chen_appearing",1,ob);
	message_vision("$N目从竹篮向南海方向飞去了．．．\n",ob);
	}
	else{ 
	message_vision("$N一见不敌，趁机使个障眼法溜掉了．\n",me);
     	ob->set_temp("obstacle/tongtian_killed",1);
	ob->set("obstacle/tongtian" , "fight");
	}
    load_object("/obj/empty");
    me->move("/obj/empty");
    call_out ("destruct_me",3,me);
   }
}
void chen_appearing (object who)
{
  object chen = new ("/d/qujing/tongtian/npc/chen");

  chen->announce_success (who);
  destruct (chen); 
}

void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  ob->apply_condition("killer", 100);
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  ::kill_ob(ob);
}


