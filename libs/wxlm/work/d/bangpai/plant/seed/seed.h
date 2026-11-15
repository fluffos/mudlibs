inherit COMBINED_ITEM;

/*
mapping seed_info = ([
	"name" : "种子",		//种子名字
	"long" : "描述。\n",	//种子描述
	"id" : "seed",			//种子ID
	"value" : 1,			//种子价值
	"mature_name" : "菜", //成熟名称
	"mature" : 0,			//成熟对象路径
	"time_need" : 0,		//成熟时间
]);*/

void create_seed(mapping seed_info)
{
	set_name(seed_info["name"], ({seed_info["id"] + " seed"}));
	set("long", "这是一粒" + seed_info["name"] + "。\n");
	set("base_unit", "粒");
	set("base_value", seed_info["value"]);
	set("base_weight", 1);
	set("seed_info", ([
		"mature_name" : seed_info["mature_name"],
		"mature" : __DIR__"veg/" + seed_info["id"],
	]));
	set("time_need", seed_info["time_need"]);
		
	set("seed", 1);
	set_amount(1);
	setup();
}

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}