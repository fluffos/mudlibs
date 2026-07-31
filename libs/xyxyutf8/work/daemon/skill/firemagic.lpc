// Firemagic.c 火系魔法
// Cracked by 凌惊雪 6-2-2003

inherit SKILL;

string *dodge_msg = ({
	"$n轻轻一纵，使个「御火步」，避开了这一招。\n",
	"$N眼一花，$n使出「御火式」一个筋斗从$N头顶越过。\n",
	"$n一声：好！一招「踏火式」连翻几个筋斗，连影子都没了。\n",
	"$n左足一点，腾空而起，避了开去。\n",
	"但是$n身子轻轻飘了开去。\n",
});

int valid_enable(string usage)
{
	return (usage=="magic") || (usage=="dodge");
}

int valid_learn(object me) { return 1;}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	return notify_fail("烈炎心法只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string conjure_magic_file(string magic)
{
	return CLASS_D("firemagic") + "/firemagic/" + magic;
}

string type() { return "magic";}