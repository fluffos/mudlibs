// Npc: /kungfu/class/shaolin/seng-bing.c
// Date: YZC 96/01/19

inherit NPC;

string ask_enter();
string ask_leave();
void destroying(object);

void create()
{
	set_name("高僧", ({"gao seng", "seng"}));
	set("long",
		"这是在洛阳万安寺出家的老年僧人，佛法高深，在附近广为人知。\n"
	);

	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 60);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 1000);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 100000);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("strike", 100);
	set_skill("banruo-zhang", 100);
	set_skill("parry", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("parry", "banruo-zhang");
	
  prepare_skill("strike", "banruo-zhang");
  set_temp("apply/attack", 100);
  set_temp("apply/defense", 100);
  set_temp("apply/damage", 100);
  set("uni_target", 1);

  set("inquiry", ([
    "离开" : (:ask_leave:),
    "法事" : (:ask_enter:)
  ]));

//高僧在一个小时以后会自动离开  
	remove_call_out("destroying");
	call_out("destroying",3600,this_object());
  
	setup();
}

//当高僧无主，并且在灵堂外面，你身上有任务凭证和标记的时候
//高僧收走书信带你进入灵堂。
int accept_object(object me, object ob)
{
	object tob=this_object();
	
//	printf("%s,%d,%s,%s\n",ob->query("id"),me->query_temp("quest_release/letter"),ob->query("owner"),environment(me)->query("short"));
	if(ob->query("id")=="letter"&&
		 me->query_temp("quest_release/letter")&&
		 ob->query("owner")==me->query("id")&&
		 environment(me)->query("short")!="灵堂"&&
		 !tob->query("owner")) {
		tell_room(environment(tob), "高僧收走了"+me->query("name")+"递过来的"+ob->query("name")+"。\n");
		command("say 就等你了，带上佛经一起进去吧。以后进出灵堂找我就行！");
		tob->set("owner",me->query("id"));
		me->move("/newbiequest/shaolin/lingtang");
		tob->move("/newbiequest/shaolin/lingtang");
		remove_call_out("destroying");
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

string ask_enter()
{
	object ob,me;
	
	ob=this_object();
	me=this_player();
	
	if(ob->query("owner")==me->query("id")&&
		 environment(me)->query("short")!="灵堂") {
		me->move("/newbiequest/shaolin/lingtang");
		ob->move("/newbiequest/shaolin/lingtang");
		return "都准备妥当了？我们进去做法事吧！\n";
	}
	else if(ob->query("owner")==me->query("id"))
		return "你已经在灵堂里面了，跟着大家一起做法事吧！\n";
	else
		return "我不认识你，你还是找熟悉的人带你进去做法事吧。\n";
}

string ask_leave()
{
	object ob,me;
	
	ob=this_object();
	me=this_player();

	if(ob->query("owner")==me->query("id")&&
		 environment(me)->query("short")=="灵堂"&&
		 !me->query_temp("quest_release/success")) {
	  if(userp(me)&&me->query_temp("channels")) {
      tell_object(me, "离开灵堂所有消息频道恢复正常。\n");
	    me->set("channels",this_player()->query_temp("channels"));
	    me->delete_temp("channels");
	  }
		me->move(me->query_temp("quest_release/target"));
		ob->move(me->query_temp("quest_release/target"));
		return "我们走吧，去外面歇歇！\n";
	}
	else if(ob->query("owner")==me->query("id")&&
		 environment(me)->query("short")=="灵堂"&&
		 me->query_temp("quest_release/success")) {
	  if(userp(me)&&me->query_temp("channels")) {
      tell_object(me, "离开灵堂所有消息频道恢复正常。\n");
	    me->set("channels",this_player()->query_temp("channels"));
	    me->delete_temp("channels");
	  }
		me->move(me->query_temp("quest_release/target"));
		remove_call_out("destroying");
		call_out("destroying",1,ob);
		return "终于做完法事了，我们可以走了！";
	}
	else if(ob->query("owner")==me->query("id"))
		return "我们已经在外面了！\n";
	else
		return "我不认识你，你还是找熟悉的人带你出去吧。\n";
}