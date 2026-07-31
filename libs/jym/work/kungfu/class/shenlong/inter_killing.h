// Pingguo
// inter_killing.h



init()
{
		  object ob = this_player();

		  ::init();

		  add_action("do_kill_sb","kill");
		  add_action("do_kill_sb","hit");
		  add_action("do_throw","throw");
}


int do_throw(string arg)
{
		  object victim, ob1, ob, me = this_player();
		  string what, who;

		  if( !arg
		  ||      sscanf(arg, "%s at %s", what, who)!=2)
					 return notify_fail("命令格式: throw <物品> at <某人>。\n");

		  ob = present(what, me);
		  if( !ob ) ob = present(arg, environment(me));
		  if( !ob ) return notify_fail("你要扔什么？\n");

		  if (ob->query("no_drop"))
					 return notify_fail("这个东西不能离开你。\n");

		  if (!(victim = present(who, environment(me))))
					 return notify_fail("这里没有你的目标。\n");

		  if (!victim)
					 return notify_fail("这里并无此人！\n");

		  if (!living(victim))
					 return notify_fail("这不是活物！\n");

		  if ( victim->query("id") == me->query("id")  ) {
					 return notify_fail("自己杀自己？\n");
		  }

		  if ( victim->query("family/family_name") == "神龙教"  ) {
				message_vision("$n想要偷袭$N！！！\n", victim, me);
				message_vision( "$N一声冷笑：大胆狂徒！敢来我神龙教行凶杀人！\n", this_object() );
				this_object()->kill_ob(me);
				return 1;
		  }

	return 0;
}


int do_kill_sb(string arg)
{
		  object ob, ob1=this_object(), me = this_player();

		  if ( !arg || arg == "" ) return 0;

		  if ( !ob=present(arg, environment(me)) ) return 0;
		  if ( ob->query("id") == me->query("id")  ) {
					 return notify_fail("自己杀自己？\n");
		  }

		  if ( ob->query("family/family_name") == "神龙教"  && ob != ob1 ) {
			  message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活！」\n", ob, me);
				message_vision("$N一声冷笑：大胆狂徒！敢来我神龙教行凶杀人！\n", ob1);
				ob1->kill_ob(me);
				return 1;
		  }


		  return 0;
}
