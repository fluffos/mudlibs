//strategy第四本
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
		set("value", 3000);
		set("material", "paper");
		set("Strategy_Book_Series",4); 
		set("skill", ([
	  	"name": "strategy",  //name of the skill
 		"exp_required": 15000 , //minimum combat experience required
		"jing_cost": 25 + random(30),// jing cost every time study this
		"difficulty":	28,	// the base int to learn this skill
		"max_skill":	159,	// the maximum level you can learn
		"min_skill":    110
		]) );
	}
}