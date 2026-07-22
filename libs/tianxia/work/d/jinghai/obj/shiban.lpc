// shiban.c

inherit ITEM;

string *name = ({"石斑鱼","老虎鱼","平鱼","巴鱼","黄花鱼"});

void create()
{
        set_name(name[random(sizeof(name))], ({ "sea fish", "fish" }) );
        set_weight(1000);

	set("unit", "尾");
	set("long", sprintf("这是一尾在静海一带水里常见的%s。\n",query("name")));
	set("value", 100);
}

int is_jinghai_fish() { return 1; }
