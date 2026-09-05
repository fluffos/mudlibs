// cuilaohan.c 崔老汉
//seagate@pkuxkx 2010/11/07 武当入门任务角色

inherit NPC;
int ask_me();

void create()
{
	set_name("崔老汉", ({ "cui laohan", "cui" }) );
	set("gender", "男性" );
	set("age", 62);
	set("long",
		"这是一个老年男子，浑身满是皱纹，一头苍白的头发，坐在门槛上整体摇头叹气。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("inquiry",([
		"麻烦" : (:ask_me:),
		]));
	set("shen_type",1);
	setup();
}

//设置任务信息
int ask_me()
{	
	object me=this_player(),enemy,qitem,rope;
	
	if(!me->query_temp("quest_fighter/start")) {
		message_vision("$N摇摇头说到：这年头让人没法活了！死了算了！\n",this_object(),me);
		return 1;
	}
	else if(me->query_temp("quest_fighter/ask_info")) {
		message_vision("$N叹了口气，说道：果然还是没有希望，算了算了！\n",this_object(),me);
		return 1;
	}
	
	me->set_temp("quest_fighter/ask_info",1);
  enemy=new(__DIR__"tufeitou");
  enemy->reset_stat(me);
  qitem=new(__DIR__"obj/zhuozi");
  qitem->move(enemy);
  qitem->set("request",me->query("id"));
  enemy->move("/d/wudang/zhulou");
  rope=new(__DIR__"obj/rope");
  rope->move(me);
  me->set_temp("quest_fighter/name", "银镯子");
  me->set_temp("quest_fighter/fight_stime", time());
  message_vision("$N说到：前几天村子里面来了几个土匪，把过世的老伴留给我的银镯子给抢走了，一定要帮我拿回来！\n这根绳子可以用来捆(kun)人，说不定对$p有点作用，土匪似乎稍微拷问拷问(kaowen)说不定就能获得想要的消息。\n",this_object(),me);
	return 1;
}

int accept_object(object me, object ob)
{
  if(me->query_temp("quest_fighter/ask_info")&&
  	 ob->query("request")==me->query("id")&&
  	 ob->query("id")=="yin zhuozi") {
  	message_vision("$N紧紧地抓住$n的手，老泪纵横，抽泣地说道：『太感谢了！』\n", this_object(), me);
  	me->set_temp("quest_fighter/success",1);
		call_out("destroying",1,ob);
  	return 1;
  }
  return 0;
}

void destroying(object ob)
{
	destruct(ob);
	return;
}