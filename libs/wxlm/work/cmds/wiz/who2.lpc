// who2.c

inherit F_CLEAN_UP;



int main(object me, string str)
{
	object where, ob;
	object *ob_list, *wiz_ob;
	mapping dbase;
	int admin;
	int i;
	string *line;

	if (! SECURITY_D->valid_grant(me, "(wizard)"))
		return 0;

	seteuid(getuid());

	admin = me->is_admin() || (SECURITY_D->query_site_privilege("finger") == "enable");

	ob_list = users();
	wiz_ob = filter_array(ob_list, (: wizardp :));
	ob_list -= wiz_ob;

	wiz_ob  = sort_array(wiz_ob, "sort_wizard");
	ob_list = sort_array(ob_list, "sort_user");
	ob_list = wiz_ob + ob_list;

	i = 0;
	line = allocate(sizeof(ob_list) + 2);
	line[i++] = HIG" 玩家    年龄 存款       地址	       所在       程序       "NOR"\n"
		    WHT "—————————————————————————————————————"NOR"\n";
	foreach (ob in ob_list)
	{
		dbase = ob->query_entire_dbase();
		where = environment(ob);

		line[i] = sprintf(WHT"%-8s:  "
				  HIR"%-2d "
				  HIG"%-6d "
				  HIY"%-20s ",
				  dbase["name"],
				  dbase["age"],
				  dbase["balance"] / 10000,
				  admin ? query_ip_name(ob) : "--------");
		if (where)
			line[i] += sprintf(HIM "%s" NOR "(" HIC "%s" NOR ")\n",
					   where->query("short"),
					   file_name(where));
		else
			line[i] += ""NOR"\n";
		i++;
	}
	line[i] = NOR WHT "—————————————————————————————————————\n" +
		  sprintf("%s共有 %d 位使用者连线中。"NOR"\n", str, sizeof(ob_list));

	str = implode(line, "");
	me->start_more(str);
	return 1;
}

int sort_user(object ob1, object ob2)
{
	return ob2->query("mud_age") - ob1->query("mud_age");
}

int sort_wizard(object ob1, object ob2)
{
	return (int)SECURITY_D->get_wiz_level(ob2)  -
	       (int)SECURITY_D->get_wiz_level(ob1);
}

int help(object me)
{
	write(@HELP
指令格式：who2

玩家信息查询列表2。
HELP );
	return 1;
}
