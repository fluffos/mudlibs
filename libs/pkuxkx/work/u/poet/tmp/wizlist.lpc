// wizlist.c
// Last modified by Doing Lu 1999/1/23

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string *list;
    string *wiz_rank;
    object ob, user;

    wiz_rank = allocate(24);
    for (int i = 0; i < sizeof(wiz_rank); i++)
	wiz_rank[i] = 0;

    seteuid(getuid());
    ob = new("/clone/misc/cloth");

    write(MUD_NAME + "目前的巫师有：\n");
    list = sort_array(SECURITY_D->query_wizlist(), 1);
    for (int i=0; i < sizeof(list); i++)
    {
	string ranks;
	int rank_n;

	ob->set("id", list[i]);
	ob->set("name", "无名氏");
	ob->set("body", USER_OB);

	if( !objectp(user = LOGIN_D->make_body(ob)) || ! user->restore())
	    continue;

	rank_n = SECURITY_D->get_wiz_level(user) * 2;
	ranks = RANK_D->query_rank(user);

	if (user->query("gender") == "男性") rank_n++;
	if (user->is_ghost()) rank_n = 0;

	// 合并名字相同的列表
	for (int k = 0; k < sizeof(wiz_rank); k++)
	    if (wiz_rank[k] && strsrch(wiz_rank[k], ranks) != -1)
	    {
		rank_n = k;
		break;
	    }

	if (! wiz_rank[rank_n])
	    wiz_rank[rank_n] = RANK_D->query_rank(user) + "：";

	wiz_rank[rank_n] += user->query("id") + " ";
	destruct(user);
    }

    // 从高到低显示列表
    for (int i = sizeof(wiz_rank) - 1; i >= 0; i--)
    {
	if (wiz_rank[i])
	    write(wiz_rank[i] + "\n");
    }
    write("\n");
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : wizlist

用途 : 列出目前所有的巫师名单。
HELP
    );
    return 1;
}
