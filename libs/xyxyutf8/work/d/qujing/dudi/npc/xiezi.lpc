// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("蝎子精", ({ "xiezi jing", "xiezi", "jing" }));
  set("title", "琵琶洞");   
  set("long", "一位艳色迷人的女妖精。\n");
  set("gender", "女性");
  set_level(95);
  set("age", 26);
  set("attitude", "heroism");
  set("force_factor", 30);
  set("mana_factor", 30);

  set_skill("spells",950);
  set_skill("dao",950);
  set_skill("unarmed",950);
  set_skill("baihua-zhang",950);
  set_skill("dodge",950);
  set_skill("moondance", 950);
  set_skill("parry",950);
  set_skill("force", 950);
  set_skill("fork",950);
  set_skill("moonforce", 950);
  set_skill("fengbo-cha",950);
  map_skill("spells", "dao");
  map_skill("unarmed", "baihua-zhang");
  map_skill("fork", "fengbo-cha");
  map_skill("parry", "fengbo-cha");
  map_skill("dodge", "moondance");
  map_skill("force", "moonforce");
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/qujing/dudi/obj/cha")->wield();
}

void die ()
{
  object me = this_object();	
  message_vision ("\n$N浑身酥软趴在地上，原来是一只琵琶大小的毒蝎子。\n",me);
  message_vision ("\n天空闪过昴宿星官的影子，将蝎子拾起驾云而去。\n",me);
  destruct(me);
}

void unconcious ()
{
  die ();
}

int test_player (object who)
{
  string *names;
  string name;
  int len;

  if (! who)
    return 0;

  names = who->query_temp("apply/name");
  if (! names)
    return 0;

  if (sizeof(names) < 1)
    return 0;

  name = names[0];
  len = strlen (name);
  if (len < 1)
    return 0;

  if (name[len-2..len-1] != "鸡")
    return 0;

  return 1;    
}

void hurting (object me, object ob)
{
  string *msgs = ({
    "$N将裙角一掀，抬起毒刺向$n一扎！\n",
    "$N一转身，一个倒马桩向$n刺去！\n",
    "$N跳起往$n的头上一扎！\n",
  });
  string *strs = ({
    "( $N大叫一声：好痛！ )\n",
    "( $N抱起肿起的头忍不住惨叫一声！ )\n",
    "( $N的头上立刻肿起一大块红红的脑门痈！ )\n",
  });
  int damage;
  remove_call_out ("hurting");  
  if (! me)
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;
  if( !me->is_fighting(ob) )
  	return;
  message_vision ("\n"+msgs[random(sizeof(msgs))],me,ob);
  
  if (! test_player(ob))
  {
    message_vision (strs[random(sizeof(strs))],ob);
    damage = ob->query("max_kee")/(7+random(3));
    ob->add("kee",-damage); 
    ob->add("eff_kee",-damage); 
    ob->add("sen",-damage); 
    ob->add("eff_sen",-damage); 
  }
  else
  {
    message_vision ("只见$N发出一声鸡叫，"+
                    "$n顿时慌乱地放下裙子收起倒马桩！\n",ob,me);
  }
  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}

void kill_ob (object ob)
{
	object me = this_object();
   	call_out ("hurting",random(5)+5,me,ob);  
  	::kill_ob(ob);
}
