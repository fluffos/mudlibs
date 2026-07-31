// story:niulang 牛郎织女 ->改为偷九转

#include <ansi.h>

static string char_id;
static string char_name;
static string family_name;

int give_gift();
object select_character();

string prompt() { return HIY "【故事传闻】" NOR; }

static mixed *story = ({
	"太上老君的炼丹房。",
	"清风和明月正在打盹。",
	"ZZZ~~~~~",
	"$N翻箱倒柜正找着什么。",
	"门外传来敲门声：清风、明月，该起来尿尿啦！",
	"$N吓得屁滚尿流，这不是太上老君的声音吗！",
	"太上老君：$N，你在这里干啥，莫非是学那猴头来盗我仙丹？",
	"说罢手中浮尘一挥，$N便飞将出去。",
	"$N眼前一黑，从手中掉落一物。",
		(: give_gift :),
	"太上老君大叫：哎呀！不好，我的仙丹！",		
});
object select_character()
{
	object *obs;
	object ob;
	
	obs = filter_array(all_interactive(), (: ! wizardp($1) &&
						 environment($1) &&
						 environment($1)->query("outdoors") &&
						 ! $1->query("doing") :));
	if (! sizeof(obs))
		return 0;
	
	ob = obs[random(sizeof(obs))];
	char_id = ob->query("id");
	char_name = ob->name(1);
	family_name = ob->query("family/family_name");
	return ob;
}
void create()
{
	seteuid(getuid());
		if (! objectp(select_character()))
	{
			destruct(this_object());
			return;
	}
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
	}
    return msg;
}

int give_gift()
{
	STORY_D->give_gift("/clone/vip/dan_jiuzhuan", 1,
		HIM "\n“啪”的一声一颗闪闪发光的仙丹掉到你面前。"NOR"\n");
	return 1;
}

