// dapeng.c...weiqi, 97.09.27.

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
	set_name("大鹏明王", ({"dapeng mingwang", "dapeng", "mingwang", "wang"}));
	set("title", "三大王 鹏魔王");
	set("gender", "男性" );
	set("age", 45);
	set("per", 30);
	set("str", 30);
	set("long", "这位大鹏明王的确大有来历，说起来跟佛祖如来也有点亲戚关系，\n算是如来的“舅舅”。他不似其兄孔雀明王作恶多端，却也并非善类，\n且因其兄之故跟佛门结下深仇。生平最讨厌的就是和尚。\n");
	set("class", "yaomo");
	set("combat_exp", 51800000);
	set("daoxing", 39000000);

	set("attitude", "peaceful");
	create_family("大雪山", 1, "祖师");
	set("rank_info/respect", "明王");
    

	set("max_kee", 3500);
	set("max_jing", 3500);
	set("force", 3500);
	set("max_force", 1800);
	set("mana", 4000);
	set("max_mana", 2000);	
	set("force_factor", 120);
	set("mana_factor", 100);

	set_temp("apply/damage", 50);
	set_temp("spply/armor", 50);
	set_temp("apply/dodge", 50);
   
            setup();
            initlvl((750+random(750)),3);
	carry_object("/d/obj/cloth/choupao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
        carry_object("/d/qujing/shituo/obj/pingreal");
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object fabao = present ("fabao",me);
object taishang = new (__DIR__"pusa");
  if (ob)
  {
    ob->set_temp("obstacle/shituo3_killed",1);
    taishang->announce_success (ob);
  destruct (taishang); 
  }
  message_vision ("\n$N无可奈何地现了真身，原来是一只大鹏。\n",me);
  message_vision ("\n大鹏飞天而走。\n",me);
  
  if (fabao)
  {
    message_vision ("，丢下一只$n。\n",me,fabao);
    fabao->move(environment(me));
  }
  else
    message_vision ("。\n",me);
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
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void hurting (object me, object ob)
{
  object fabao = present ("fabao",me);

  if (fabao)
    fabao->ji_ob (ob);

  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}