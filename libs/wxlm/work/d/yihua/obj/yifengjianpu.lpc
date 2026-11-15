inherit ITEM;

void create()
{
	set_name( "移风剑谱", ({ "jian pu", "pu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");

		set("long", "这是一本移风剑谱，上面画着一些奇奇怪怪的鲜花。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"yifeng-jian",	
//			"literate": 500,
			"exp_required":	100000,
			"jing_cost": 5,
			"difficulty":	10,
			"max_skill":	500,
		]) );
	}
}
