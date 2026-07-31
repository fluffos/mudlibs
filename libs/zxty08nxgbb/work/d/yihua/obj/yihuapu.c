inherit ITEM;

void create()
{
	set_name( "移花接木功法谱", ({ "gongfa pu", "pu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("no_drop", "这样东西不能丢了，不然让宫主追问下来就麻烦了\n");
		set("no_give", "这么宝贵的东西怎么能随便乱给人呢？\n");
		set("no_sell", "当了要是宫主知道了就麻烦了。\n");
		set("no_get", "这样东西拿不起来。\n");
		set("long", "这是一幅移花接木功法图，上面画着一些奇奇怪怪的花木，怎么看也不像练功图。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"yihua-jiemu",	
			"exp_required":	1000000,
			"dodge": 300,
			"int": 30,
			"dex": 40,
			"dodge": 300,
			"per": 22,
			"jing_cost": 10,
			"difficulty":	10,
			"max_skill":	350,
		]) );
	}
}
