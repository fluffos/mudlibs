//strategy第一本
inherit ITEM;
void create()
{
	set_name( "「唐太宗李卫公问对」",({ "tangli wendui", "book"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是一部以唐太宗李世民与卫国公李靖讨论兵法问答形式写成的兵书。\n"
		"书中就“奇正”、“虚实”、“主客”、“攻守”等几个方面发议论提出了独到的见解。\n");
		set("value", 1000);
		set("material", "paper");
		set("zijin",1); 
		set("skill", ([
	  	"name": "strategy",  //name of the skill
 		"exp_required": 0 , //minimum combat experience required
		"jing_cost": 10 + random(20),// jing cost every time study this
		"difficulty":	20,	// the base int to learn this skill
		"max_skill":	29,	// the maximum level you can learn
		]) );
	}
}