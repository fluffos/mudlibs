int ask_me()
{
	object me;
	object ob;
	object where;
	mapping party,myfam;
	me=this_player();
	where=environment(me);
	party=(mapping)me->query("party");
	myfam=(mapping)me->query("family");
	
        if ( ( !party || party["party_name"]!=HIG "发梦二党" NOR ) && ( !myfam || myfam["family_name"]!="发梦二党" ) )
	{
		command("say 我不能把书给外人看。");
                return 0;
	}
	
        if ( file_name(where)!="/d/wenzhai/sxge")
         {
              command("say 书在书香阁，这里找不到书。");
              return 0;
         }
	if ( where->query("book_asked") )
	{
		command("say 书已经被人拿走了。");
                return 0;
	}
	
	command("say 好吧！这几本书可能对你有用，有好好读读吧。");
	ob=new("/d/wenjia/obj/forcebook");
	ob->move(where);
	ob=new("/d/wenjia/obj/dodgebook");
	ob->move(where);
	ob=new("/d/wenjia/obj/swordbook");
	ob->move(where);
	ob=new("/d/wenjia/obj/bladebook");
	ob->move(where);
	where->set("book_asked",1);
	return 1;
}

int ask_job()
{
	object me;
	mapping party,myfam,quest;
	me=this_player();
	party=(mapping)me->query("party");
	myfam=(mapping)me->query("family");
	quest = "/d/huafu/quest/fmquest"->query_quest();
	
        if ( ( !party || party["party_name"]!=HIG "发梦二党" NOR ) && ( !myfam || myfam["family_name"]!="发梦二党" ) )
	{
		command("say 你与本党毫无关系，这种事不能让你做。");
		return 1;
	}
	
            if ((me->query("combat_exp")>700000) && party)
            {
                   command("say 你已经是超级高手了。你不用做这种事情了。");
                   return 1;
                }
	if ( myfam && myfam["family_name"]=="发梦二党" )
	{
         if ( (int)me->query("combat_exp")<40000 )
		{
			command("say 你还是专心酿酒吧！");
			return 1;
		}
                  if ( (int)me->query_skill("dodge",1)<50 )
		{
			command("say 你的轻功不够，不适合做这种工作。");
			return 1;
		}
	}
	
	if ( party && party["party_name"]==HIG "发梦二党" NOR )
	{
          if ( (int)me->query("combat_exp")<40000 )
		{
                          command("say 你的实战经验太低了，去了恐怕有危险！");
			return 1;
		}
          if ( (int)me->query_skill("dodge",1)<50 )
		{
			command("say 你的轻功不够，不适合做这种工作。");
			return 1;
		}
	}
	
        if ( me->query_temp("job_huaxin") )
        {
               command("faint "+me->query("name"));
               command("say 你这个花花肠子，给你任务，你竟然跑去洗澡！\n");
               message_vision("$N睁着一双泪汪汪的大眼睛，无辜的望着$n。\n",me,this_object());
               me->delete_temp("job_start");
               me->delete_temp("job_huaxin");
               me->apply_condition("job_nodo",50);
               return 1;
               }
	if ( me->query_temp("job_failed") )
	{
		command("poor "+me->query("id"));
		command("say 你还是先练练功夫吧，免得又把工作搞咂了。");
             me->delete_temp("job_failed");
             me->delete_temp("job_start");
		return 1;
	}
	
	if (me->query_condition("job_nodo") > 0)
	{
		command("say 现在不需要你去做,你还是趁这段时间多练练功吧。");
       me->delete_temp("job_start");
       me->delete_temp("job_failed");
		return 1;
	}

	if ( me->query_temp("job_start") && !(me->query_temp("job_ok")) )
	{
		command("hmm");
		command("say 你已经有工作了。还不快去做？");
		return 1;
	}
	
	if (me->query_temp("job_ok") ==1 )
	{
		command("say 好好，干的好，你下去歇歇吧。");
                me->add("potential", 120+random(100));
               me->add("combat_exp", 150+random(120));
		me->delete_temp("job_start");
		me->delete_temp("job_ok");
                me->delete("duishou");
		me->delete_temp("where");
                me->apply_condition("job_nodo",0);
                 me->add("shen",50);
       me->delete_temp("job_failed");
                 if (party) {
                       party["tasks"]=party["tasks"]+2;
                        me->set("party",party);
                 }
		return 1;
	}
	
	command("say 你来的正好，听说" + quest["opp_name"] + "在" + quest["quest_env"] + quest["quest_thing"]+"，你去探听一下情报。");
	command("say 小心，别让" + quest["opp_name"] + "弟子发现了。");

	me->set_temp("job_start",1);
        me->set("duishou", quest["opp_name"]);
	me->set_temp("where", quest["file_name"]);
        me->apply_condition("job_nodo",0);
	
          call_out("do_datan",25, me);

	return 1;
}

void do_datan(object me)
{
	object where;
        object ob;

	where = environment(me);

	if (file_name(where)==me->query_temp("where"))
	{
                if (!objectp(present("dizi",where)))
                {
                ob=new("/d/chengdu/npc/tufei");
                ob->set_name(me->query("duishou")+"弟子",({"dizi"}));
                ob->move(where);
                }
                message_vision("$N发现了"+me->query("duishou")+"弟子走了过来，连忙低下头去。\n"NOR, me);
                message_vision(HIC"$N抖擞精神，屏住呼吸，开始注意"+me->query("duishou")+"弟子的言行举止。\n"NOR, me);
              me->apply_condition("fmquest",5);
	}
       else 
	{
                  message_vision("\n$N四处张望，显然还没到达指定地点，来不及了。\n", me);
		me->set_temp("job_failed",1);
               me->apply_condition("job_nodo",30);
	}
	return;
}

