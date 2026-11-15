inherit ITEM;

void create()
{
	set_name( "移花接木功法谱", ({ "gongfa pu", "pu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一幅移花接木功法图，上面画着一些奇奇怪怪的花木，怎么看也不像练功图。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
             "name": "beiming-shengong",  
            "exp_required": 1000,
            "dodge": 0,
            "int": 0,
            "dex": 0,
			"dodge": 300,
            "per": 0,
            "jing_cost": 0,
			"difficulty":	10,
            "max_skill":    1350,
		]) );
	}
}
