// created 11/20/1997 by snowcat

inherit NPC;

void create()
{
  set_name("道士", ({ "dao shi", "dao", "shi" }));
  set("title", "黄花五公");   
  set("long", "一位欲神欲仙的黄花观五公道士。");
  set("gender", "男性");
  set_level(80);
  set("age", 40);
  set("attitude", "heroism");
  set("per", 29);
  set("force_factor",800);
  set("mana_factor", 80);

  set_skill("spells",800);
  set_skill("dao",800);
  set_skill("unarmed",800);
  set_skill("puti-zhi",800);
  set_skill("dodge",800);
  set_skill("jindouyun",800);
  set_skill("qianjun-bang",800);
  set_skill("parry",800);
  set_skill("force",800);
  set_skill("wuxiangforce",800);
  set_skill("staff",800);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  map_skill("parry", "qianjun-bang");
  setup();
  carry_object("/d/obj/cloth/daopao")->wear();
}

void die ()
{
  object me = this_object();
  message_vision ("\n$N扑倒在尘埃里，现身为一七尺蜈蚣精。\n",me);
  message_vision ("\n蜈蚣精化为一股青烟噌地消散了。\n",me);
  destruct (me); 
}

void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  return 0;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  if( !me->is_fighting() )
  {
  	remove_call_out("recovering");  
  	remove_call_out("hurting");  
  }
  call_out ("recovering",1,me,ob);  
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void recovering (object me, object ob)
{
	object needle;

	remove_call_out("recovering");  
  	if(! me || ! ob)
    		return;
	if( !present(ob,environment()) )
    		return;
	needle = present("xiuhua zhen",ob);
	if( ( !needle 
         || needle != ob->query_temp("weapon")) 
          && (me->query("kee") < (me->query_maxkee()*3/4) 
           || me->query("sen") < (me->query_maxsen()*3/4)) )
  	{
    		message_vision ("\n$N身上万道金光一闪，顿时精神气血尽回！\n",me);
    		me->powerup(0,1);
	}
  	call_out ("recovering",1,me,ob);  
}

void hurting (object me, object ob)
{
  	string *msgs = ({
    		"$N将衣一掀，无数道金光向$n一射！\n",
    		"$N一抬手，胁下千只眼睛金光闪闪射向$n！\n",
    		"$N掀起胳膊下无数只眼睛迸出金光直射向$n！\n",
  	});
  	string *strs = ({
    		"( $N一个趔趄不由自主地惨叫一声！ )\n",
    		"( $N应声倒下，又勉强爬将起来！ )\n",
    		"( $N痛苦地惨嚎了一声！ )\n",
  	});
  	object needle;
  	int damage;
	
	remove_call_out("hurting");  
  	if( ! me || ! ob )
    		return;
	if( !present(ob,environment()) )
    		return;
	message_vision ("\n"+msgs[random(sizeof(msgs))],me,ob);
  	needle = present("xiuhua zhen",ob);
  	if( ! needle || needle != ob->query_temp("weapon") 
  	 || random(3) == 0)
  	{
    		message_vision (strs[random(sizeof(strs))],ob);
    		damage = ob->query_maxkee()/(6+random(4));
    		ob->receive_damage("kee",damage,this_object()); 
    		ob->receive_damage("sen",damage,this_object()); 
		ob->receive_wound("sen",damage,this_object()); 
		ob->receive_wound("kee",damage,this_object()); 
  	}
  	else
  	{
    		message_vision ("但见$N手上绣花针一闪，"+"$n嚎叫一声，胁下几只眼睛顿时灭去！\n",ob,me);
  	}
  	remove_call_out ("hurting");  
  	call_out ("hurting",random(10)+5,me,ob);  
}