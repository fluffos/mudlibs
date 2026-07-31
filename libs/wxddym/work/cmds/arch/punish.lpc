// pun.c

inherit F_CLEAN_UP;

private void cut_exp(object me, object ob, int scale);

int help(object me);

int main(object me, string arg)
{
	string target;
	object ob;
	string msg;
	function f;
	string user, flogin, fuser;

	if (! SECURITY_D->valid_grant(me, "(arch)"))
		return 0;

	seteuid(getuid(me));

	if (! arg) return notify_fail("指令格式 : pun <玩家ID> <分项>\n" );

	if (sscanf(arg, "%s %s", target, arg) != 2)
		return help(me);

	ob = UPDATE_D->global_find_player(target);
	if (! objectp(ob))
		return notify_fail("没有这个玩家。\n");

	switch (arg)
	{
	case "exp-10":
		f = (: cut_exp, me, ob, 10 :);
		break;

	case "exp-20":
		f = (: cut_exp, me, ob, 20 :);
		break;

	case "exp-30":
		f = (: cut_exp, me, ob, 30 :);
		break;

	case "exp-40":
		f = (: cut_exp, me, ob, 40 :);
		break;

	case "exp-50":
		f = (: cut_exp, me, ob, 50 :);
		break;

	case "exp-60":
		f = (: cut_exp, me, ob, 60 :);
		break;

	default:
		write("没有这个处理办法。\n");
		UPDATE_D->global_destruct_player(ob, 1);
		return 1;
	}

	user = getuid(ob);
	flogin = "login/" + user[0..0] + "/" + user + __SAVE_EXTENSION__;
	fuser  = "user/"  + user[0..0] + "/" + user + __SAVE_EXTENSION__;

	if (file_size(TEMP_DIR + flogin) >= 0 ||
	    file_size(TEMP_DIR + fuser) >= 0)
	{
		msg = "由于暂存区(/temp/)下面已经存放了玩家"
		      "的数据，因此本次不作暂存。\n";
	} else
	{
		// move current user's data to /temp/
		assure_file(TEMP_DIR + flogin);
		assure_file(TEMP_DIR + fuser);
		cp(DATA_DIR + flogin, TEMP_DIR + flogin);
		cp(DATA_DIR + fuser,  TEMP_DIR + fuser);
		msg = "玩家 " + user + " 目前的数据暂时保存"
		      "到暂存区(/temp/)下。\n";
	}
	write(msg);

	evaluate(f);
	UPDATE_D->global_destruct_player(ob, 1);
	return 1;
}

private void cut_exp(object me, object ob, int scale)
{
	ob->set("combat_exp",
		ob->query("combat_exp") / 100 * (100 - scale));
	UPDATE_D->check_user(ob);
	ob->save();
	write(sprintf("你扣除了%s的 %d%% 战斗经验。\n",
		      ob->name(1), scale));
	tell_object(ob, sprintf("%s扣除了你 %d%% 战斗经验。\n",
				me->name(1), scale));
}

int help(object me)
{
	write(@HELP
指令格式 : pun <玩家ID> <分项>

你可以使用这个命令对玩家的数据做调整。调整方法是按照分项
指出的办法进行的。为了防止处理出错，处理前系统会自动将该
玩家的档案保存在暂存区，如果错误可以从这里恢复。处理完毕
需要清空暂存区。

分项包括：exp-10
	  exp-20
	  exp-30
	  exp-40
	  exp-50
	  exp-60

参考资料： restore, clear, cleartemp
HELP );
	return 1;
}

