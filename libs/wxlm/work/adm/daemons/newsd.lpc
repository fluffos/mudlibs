// newsd.c


#include <getconfig.h>

#pragma optimize


inherit F_SAVE;
inherit F_DBASE;

// 最多一千条新闻
#define MAX_NEWS_CAPACITY       1000

// 门派更新优先级
int     last_update_day = 0;
mapping family_priority = ([ ]);

void create()
{
	seteuid(getuid());
	restore();
	set_heart_beat(300);
}

// 心跳函数：每天增大所有门派的更新优先级
void heart_beat()
{
 
	string fam;

	if (time() / 86400 != last_update_day)
	{
		// 所有门派更新优先顺序增加
		last_update_day = time() / 86400;

		if (! mapp(family_priority))
			family_priority = ([ ]);

		foreach (fam in keys(FAMILY_D->query_all_family_name()))
			if (undefinedp(family_priority[fam]))
				family_priority[fam] = 10;
			else
				family_priority[fam] += 10;

		save();
	}
}

mapping query_family_priority()
{
	return family_priority;
}

varargs void remove(string euid)
{
	save();
}

void mud_shutdown()
{
	save();
}

// prompt user
void prompt_user(object me)
{
	int num;
	int total;
	mapping *notes;
	int last_read_time;

	last_read_time = me->query("last_read_news");
	if (! last_read_time)
	{
		tell_object(me, HIG "\n欢迎您进入" + LOCAL_MUD_NAME() +
				HIG "，今后请使用" HIY " news " HIG
				"命令查阅发布的新闻信息。"NOR"\n");
		me->set("last_read_news", time());
		return;
	}

	notes = query("notes");

	if (! pointerp(notes) || ! sizeof(notes))
		return;

	num = sizeof(notes);
	total = 0;
	while (num--)
		if (notes[num]["time"] > last_read_time)
			total++;
		else
			break;

	if (! total)
		tell_object(me, "\n你目前没有未曾阅读过的新闻。\n");
	else
		tell_object(me, sprintf(WHT "\n你目前一共有 " HIY "%d" NOR
					WHT " 条新闻还没有阅读，请使用 "
					HIY "news" NOR WHT " 命令阅读。"NOR"\n", total));

	// 开始定时通知
	if (previous_object() == find_object(LOGIN_D))
		me->start_call_out(bind((: call_other, __FILE__, "auto_notice", me :), me), 10 + random(10));
}

// show all the news's title
// raw = 1: only show the non-read news
void show_news(object me, int raw)
{
	mapping *notes;
	int i, last_time_read, non_read;
	string msg;

	notes = query("notes");
	if (! pointerp(notes) || ! sizeof(notes))
	{
		tell_object(me, "目前没有任何新闻。\n");
		return;
	}

	msg = "目前泥潭中的最新消息如下。\n"
	      WHT "-------------------------------------------------------------------------------"NOR"\n";
	last_time_read = me->query("last_read_news");
	i = sizeof(notes);
	non_read = 0;

	while (i--)
	{
		if (raw && (notes[i]["time"] <= last_time_read))
			break;

		msg += sprintf("%s[%3d]" NOR " %-" + (40 + color_len(notes[i]["title"])) +
			       "s %s (%s)\n",
			       (notes[i]["time"] > last_time_read ? HIY : ""),
			       i + 1, notes[i]["title"],
			       notes[i]["author"], ctime(notes[i]["time"])[0..15]);
		non_read++;
	}

	if (i == sizeof(notes) - 1)
	{
		tell_object(me, "目前泥潭中共有 " WHT + sizeof(notes) + NOR " 条新闻，"
				"没有任何未读过的新闻。\n");
		return;
	}

	msg += WHT "-------------------------------------------------------------------------------"NOR"\n";
	msg += "目前泥潭中共有 " WHT + sizeof(notes) + NOR " 条新闻，" WHT + non_read + NOR " 条未读。\n";

	me->start_more(msg);
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, int n, string text)
{
	int i;
 
	int pl;
	string sign;
	string pure;
	mapping *notes;

	if (! n) n = me->query("env/default_sign");
	if (! stringp(sign = me->query(sprintf("env/sign%d", n))))
	{
		// auto select the first none null sign
		for (i = 1; i <= 4; i++)
		{
			sign = me->query(sprintf("env/sign%d", i));
			if (stringp(sign)) break;
		}
	}

	if (stringp(sign))
	{
		sign = replace_string(sign, "\\n", "\n");
		sign = trans_color(sign, 1);
		pure = filter_color(sign);
		if (strlen(pure) >= 1 &&
		    pure[strlen(pure) - 1] != '\n')
			sign += "\n";

		pure = filter_color(text);
		pl = strlen(pure);
		if (pl >= 1 && pure[pl - 1] != '\n')
			text += "\n\n" + sign;
		else
		if (pl >= 2 && pure[pl - 2] != '\n')
			text += "\n" + sign;
		else
			text += sign;
	}

	text = color_filter(text) + NOR;

	note["msg"] = text;
	notes = query("notes");
	if (! pointerp(notes) || ! sizeof(notes))
		notes = ({ note });
	else
	{
		i = sizeof(notes) - 1;
		if (note["time"] <= notes[i]["time"])
			note["time"] = notes[i]["time"] + 1;
		notes += ({ note });
	}

	// Truncate the notes if maximum capacity exceeded.
	if (sizeof(notes) > MAX_NEWS_CAPACITY)
		notes = notes[MAX_NEWS_CAPACITY / 4 .. MAX_NEWS_CAPACITY];

	set("notes", notes);
	tell_object(me, "新闻发布完毕。\n");

	save();
}

// post a news
void do_post(object me, string arg)
{
	int n;
	mapping note;

	if (! wizardp(me) || ! interactive(me))
	{
		tell_object(me, "只有巫师才能发布新闻。\n");
		return;
	}

	if (! arg)
	{
		tell_object(me, "发布新闻请指定一个标题。\n");
		return;
	}

	if (sscanf(arg, "%s with %d", arg, n) != 2)
		n = 0;

	if (replace_string(arg, " ", "") == "")
		arg = "无标题";
	else
		arg = color_filter(arg) + NOR;

	note = allocate_mapping(4);
	note["title"] = arg;
	note["author"] = me->name(1) + "-" + me->query("id");
	note["time"] = time();
	me->edit(bind((: call_other, __FILE__, "done_post", me, note, n :), me));
}

// read a news
void do_read(object me, string arg)
{
	int num;
	mapping *notes;
	int last_read_time;

	last_read_time = me->query("last_read_news");
	notes = query("notes");

	if (! pointerp(notes) || ! sizeof(notes))
	{
		tell_object(me, "目前没有任何新闻。\n");
		return;
	}

	if (! arg)
	{
		tell_object(me, "你想读那一条新闻？\n");
		return;
	}

	if (arg == "new" || arg == "next")
	{
		if (! last_read_time)
			num = 1;
		else
			for (num = 1; num <= sizeof(notes); num++)
				if (notes[num - 1]["time"] > last_read_time)
					break;
	} else
	if (! sscanf(arg, "%d", num))
	{
		tell_object(me, "你要读第几条新闻？\n");
		return;
	}

	if (num < 1 || num > sizeof(notes))
	{
		tell_object(me, "没有这条新闻。\n");
		return;
	}
	num--;
	me->start_more(sprintf("[%d] %-" + (40 + color_len(notes[num]["title"])) +
			       "s %s (%s)\n----------------------------------------------------------------------\n",
			       num + 1, notes[num]["title"], notes[num]["author"],
			       ctime(notes[num]["time"])[0..9]) + notes[num]["msg"]);

	// Keep track which post we were reading last time.
	if (notes[num]["time"] > (int)last_read_time)
		me->set("last_read_news", notes[num]["time"]);
}

// discard a news
void do_discard(object me, string arg)
{
	mapping *notes;
	int num;
	string author, aid;

	if (! arg || sscanf(arg, "%d", num) != 1)
	{
		tell_object(me, "你想去掉拿一条新闻？\n");
		return;
	}

	notes = query("notes");
	if (! arrayp(notes) || num < 1 || num > sizeof(notes))
	{
		tell_object(me, "没有这条新闻。\n");
		return;
	}

	num--;

	if ((! stringp(author = notes[num]["author"]) ||
	     sscanf(author, "%*s-%s", aid) != 2 ||
	     aid != me->query("id")) &&
	    (string)SECURITY_D->get_status(me) != "(admin)")
	{
		tell_object(me, "只有天神才能去掉他人发布的新闻。\n");
		return;
	}

	notes = notes[0..num - 1] + notes[num + 1..sizeof(notes) - 1];
	set("notes", notes);
	save();
	tell_object(me, "删除第 " + (num + 1) + " 条新闻....Ok。\n");
}

// auto notice user
void auto_notice(object me)
{
	int num;
	mapping *notes;
	string msg;
	int last_read_time;

	if (! objectp(me))
		return;

	last_read_time = me->query("last_read_news");
	notes = query("notes");

	if (! pointerp(notes) || ! sizeof(notes))
		return;

	num = sizeof(notes) - 1;
	if (notes[num]["time"] <= last_read_time)
		return;

	// some news need read, start next call out
	me->start_call_out(bind((: call_other, __FILE__, "auto_notice", me :), me), 30 + random(30));

	if (! living(me) || me->query_temp("block_msg/all"))
		return;

	while (num-- > 0)
	{
		if (notes[num]["time"] <= last_read_time)
		{
			num++;
			break;
		}

		// contine to find next
	}

	if (num < 0) num = 0;

	switch (random(5))
	{
	case 0:
		msg = HIM "一阵烟雾过后，新闻精灵出现在你的面前，手里"
		      "捏着一张破破烂烂的纸头，对你宣读起来。"NOR"\n";
		break;
	case 1:
		msg = HIM "地上突然开了一个裂缝，冒出一个鬼鬼祟祟的新"
		      "闻精灵，对着你就喋喋不休的罗嗦起来。"NOR"\n";
		break;
	case 2:
		msg = HIM "你忽然听见有人喊你，你回头一看，原来是新闻"
		      "精灵满头大汗的跑了过来，"NOR"\n";
		break;
	case 3:
		msg = HIM "你刚打了一个哈欠，忽然前面冒出一股烟雾，散"
		      "去以后只见一个新闻精灵懒洋洋的看着你，口中念念有词。"NOR"\n";
		break;
	default:
		msg = HIM "“啪啦”一声，新闻精灵狼狈不堪的摔在地上，"
		      "你连忙将他扶起。"NOR"\n";
		break;
	}

	msg += HIG "新闻精灵告诉你来自神界的最新消息："NOR"\n";
	tell_object(me, msg);
	me->start_more(sprintf("[%d] %-" + (40 + color_len(notes[num]["title"])) +
			       "s %s (%s)\n----------------------------------------------------------------------\n",
			       num + 1, notes[num]["title"], notes[num]["author"],
			       ctime(notes[num]["time"])[0..9]) + notes[num]["msg"]);

	// Keep track which post we were reading last time.
	if (notes[num]["time"] > (int)last_read_time)
		me->set("last_read_news", notes[num]["time"]);
	tell_object(me, HIM "新闻精灵说完后，消失在一阵烟雾之中。"NOR"\n");
}

string query_save_file() { return DATA_DIR "newsd"; }