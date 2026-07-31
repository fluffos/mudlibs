// bojuan.c



inherit ITEM;
string* titles = ({
	"three-sword",
	"blood-sword",
	"doomsword",
	"fy-sword",
	"siqi-sword",
	"qingpingsword",
	"sharen-sword",
	"feixian-sword",
});

string* titles2 = ({
	"三才剑法",
	"血衣剑法",
	"寒天吹血剑法",
	"大旗风云剑",
	"四奇剑法",
	"清平剑法",
	"杀人剑法",
	"飞仙剑法",
});

void create()
{
	int i;
	string wg,wg2;
	i=random(sizeof(titles));
	wg=titles[i];
	wg2=titles2[i];
	set_name("武功密籍:"+wg2, ({ "kungfushu" , "book"}) );
	set_weight(50);
//	set("no_drop", "这样东西不能离开你。\n");
	if( clonep() )
		{
		set("unit", "本");
		set("long", "翻开来看时,上面记的是"+wg2+"的武功密籍.\n");
		set("value", 0);
		set("no_pawn",1);
		set("material", "paper");
		set("skill", ([
			"name":		wg,
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	210,	// the maximum level you can learn
			"min_skill":	0	// the maximum level you can learn
		]) );
	}
	else {
		set("unit", "本");
		set("long", "翻开来看时,上面记的是"+wg2+"的武功密籍.\n");
		set("value", 0);
		set("no_pawn",1);
		set("material", "paper");
		set("skill", ([
			"name":		wg,
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	210,	// the maximum level you can learn
			"min_skill":	0	// the maximum level you can learn
		]) );
	}
}

