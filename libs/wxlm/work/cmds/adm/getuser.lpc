

inherit F_CLEAN_UP;

void global_destruct_player(object ob, int raw)
{
	object login_ob;

	if (objectp(ob) && ob->query_temp("temp_loaded"))
	{
		// 增加对 login_ob 的析构
		if (objectp(login_ob = ob->query_temp("link_ob")))
		{
			if (raw) login_ob->save();
			destruct(login_ob);
		}
		
		if (raw) ob->save();
		destruct(ob);
	}
}

object global_find_player(string user)
{
	object ob;
	object login_ob;

	ob = find_player(user);
	if (! ob)
	{
		login_ob = new(LOGIN_OB);
		login_ob->set("id", user);
		ob = LOGIN_D->make_body(login_ob);
		if (! ob)
		{
			catch(destruct(login_ob));
			return 0;
		}

		evaluate(bind((: seteuid(getuid()) :), ob));

		if (! ob->restore())
		{
			catch(destruct(login_ob));
			catch(destruct(ob));
			return 0;
		}

		ob->set_temp("temp_loaded", 1);
		ob->set_temp("link_ob", login_ob);

		ob->start_call_out(bind((: call_other, __FILE__, 
				   "global_destruct_player", ob, 0 :),
				   ob), 0);

		login_ob->restore();
		login_ob->set_temp("body_ob", ob);
	}

	return ob;
}

int main(object me, string arg)
{
	object ob;
	if (!arg)
	{
		return notify_fail("指令格式：getuser <玩家ID>\n");
	}
	if (objectp(ob = global_find_player(arg)))
	{
		ob->move(environment(me));
		tell_object(me, HIM "你把" + ob->name() + HIM "变了出来。"NOR"\n");
		tell_room(environment(me), HIM + ob->name() + HIM "突然出现" +
			"在你眼前。"NOR"\n", ({ me, ob }));
		return 1;
	}
	else
	{
		return notify_fail("没有这个玩家或者玩家数据无法读取。\n");
	}
}
int help(object me)
{
	write(@HELP
指令格式 : getuser <某人>

此指令可让你(你)将某不在线的玩家抓到你面前。

若玩家已经在线，请使用summon命令。

HELP );
	return 1;
}