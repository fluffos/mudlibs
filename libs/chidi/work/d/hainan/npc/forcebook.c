// literate.c

inherit ITEM;

void create()
{
        set_name("〖妙法莲花经〗", ({"jing", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
	set("long", "一本陈旧的线装书。\n");
        set("material", "paper");
        set("skill", ([
                        "name": "bitao-shengong",
                        "exp_required": 1000,
                        "jing_cost": 100,
                        "difficulty": 100,
                        "max_skill": 120,
]) );
        }
}

