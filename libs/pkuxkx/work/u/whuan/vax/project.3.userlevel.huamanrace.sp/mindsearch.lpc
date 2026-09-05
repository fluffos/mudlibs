// where.c
// 06-14-95

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob, where, myplace, *ob_list;
	int i;
	int lvl, jingli;
	string strob, strme, msg;
	
	lvl = SPECIAL_D->query_level(me, "mind-searching");
	jingli = me->query("jingli");
	if (!lvl)
		return notify_fail("什么？\n");
	
	if (me->is_busy())
		return notify_fail("你现在正忙着呢！\n");
	
	if (jingli < 1000)
		return notify_fail("你气喘吁吁，感觉精力无法支持传音搜魂。\n");

	if (!str)
		return notify_fail("指令格式：mindsearch <玩家名>\n"); 
		
	me->set("jingli", jingli-500);
	if (random(800)+1>lvl*lvl)
	{
		tell_object(me, "你全神贯注默念了口诀，但是似乎没有什么效果。\n");
		//me->start_busy(random(20));
		return 1;
	}
	ob = find_player(str);
	if (!ob)
	{
		return notify_fail("该玩家不在线。\n");
	}
	else
	{
		if (random(5)>1)
			tell_object(ob, "你忽然觉得脊背有点发凉……\n");
		else
			tell_object(ob, "阿嚏～～……肯定是有人在背后骂你。\n");
	}
	where = environment(ob);
	myplace = environment(me);
	if (!where || !myplace) 
		return notify_fail("这个人不知道在哪里呢……\n");
	strob = (string)where->query("short")+1;	// ignore 1st '/'
	if (strsrch(strob, "/")>0)
		strob[strsrch(strob, "/")] = 0;
	strme = (string)myplace->query("short")+1;	// ignore 1st '/'
	if (strsrch(strme, "/")>0)
		strme[strsrch(strob, "/")] = 0;
	if (strcmp(strme,strob)!=0)
	{
		msg = sprintf("你费了九牛二虎之力，才发现原来%s(%s)距离你太远，无法产生任何感应。\n",
			(string)ob->name(),
			(string)ob->query("id") );
		return notify_fail(msg);
	}
	msg = sprintf("隐隐约约中，你得到了来自【%s】的一点微弱的感应感应，好像来自%s(%s)。\n",
		(string)where->query("short"),
		(string)ob->name(),
		(string)ob->query("id") );
	tell_object(me, msg);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: mindsearch <玩家的 ID>

修炼“传音搜魂大法”的玩家可以使用这个指令来搜索本地区目标玩家目前所在的位置。
传音搜魂越纯熟，成功率越高。

HELP
	);
	return 1;
}