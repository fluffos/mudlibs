// story:caishen 财神

#include <ansi.h>

int give_gift(string money, int amount, string name);

static mixed *story = ({
	"大小财神狭路相逢。",
	"大财神：让路！",
	"小财神：凭什么？",
	"大财神：废话，凭我比你有钱。",
	"小财神摸出几个铜板，随手扔了出去，哼哼道：来！",
	(: give_gift, "coin", 10 + random(5), "铜板" :),
	"大财神一声冷笑，摸出一些白银扔了出去。",
	(: give_gift, "silver", 10 + random(5), "白银" :),
	"小财神摸了半天，掏出一些黄金，咬咬牙扔了出去，道：继续呀！",
	(: give_gift, "gold", 1 + random(2), "黄金" :),
	"大财神呵呵大笑：随手摸出银票，轻飘飘的飞了出去。",
	(: give_gift, "cash", 1, "银票" :),
	"小财神面如土色，道：您老有钱，您老有钱，我让路，我让路。",
});

void create()
{
	seteuid(getuid());
}

mixed query_story_message(int step)
{
	return step < sizeof(story) ? story[step] : 0;
}

int give_gift(string money, int amount, string name)
{
	STORY_D->give_gift("/clone/money/" + money, amount,
			   HIM "\n“啪”的一声一些" + name + "掉到你面前。"NOR"\n");
	return 1;
}
