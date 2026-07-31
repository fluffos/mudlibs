// story:anthem 国歌

#include <ansi.h>

static string char_id;
static string char_name;

object select_character();
int give_gift();

static mixed *story = ({
	"松井石根：快说，八路军的哪里？说了，金条的有。",
	"$N[$ID]：...",
	"松井石根：说！不说，死啦死啦的！",
	"$N[$ID]：...",
	"松井石根：八～哥呀～～～路",
	"李向阳：且慢！"
	"“啪！啪！”",
	"松井石根：嘿... 怎么打得这么准？",
	"松井石根翻翻白眼，倒在地上，口中吐出两口鲜血，死了。",
	"$N激动得热泪盈眶：同志，你可来了。",
	(: give_gift :),
});

void create()
{
	seteuid(getuid());
	if (! objectp(select_character()))
	{
		STORY_D->remove_story("anthem");
		destruct(this_object());
		return;
	}
}

string prompt() { return HIR "【传奇故事】" NOR; }

object select_character()
{
	object *obs;
	object ob;

	obs = filter_array(all_interactive(), (: ! wizardp($1) &&
						 living($1) &&
						 ! $1->query_skill("chinese-anthem", 1) &&
						 ! $1->query("doing") :));
	if (! sizeof(obs))
		return 0;

	ob = obs[random(sizeof(obs))];
	char_id = ob->query("id");
	char_name = ob->name(1);
	return ob;
}

mixed query_story_message(int step)
{
	mixed msg;

	if (step >= sizeof(story))
		return 0;

	msg = story[step];
	if (stringp(msg))
	{
		msg = replace_string(msg, "$N", char_name);
		msg = replace_string(msg, "$ID", char_id);
	}
	return msg;
}

int give_gift()
{
	object ob;

	ob = find_player(char_id);
	if (! ob) return 1;

	ob->set_skill("chinese-anthem", 200);
	STORY_D->remove_story("anthem");

	CHANNEL_D->do_channel(this_object(), "rumor", "听说" + ob->name(1) +
			      "领悟了义勇军进行曲。");
	return 1;
}

