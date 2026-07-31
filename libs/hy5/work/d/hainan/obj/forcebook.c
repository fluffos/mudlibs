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
                        "name": "force",
                        "exp_required": 10,
                        "jing_cost": 10,
                        "difficulty": 10,
                        "max_skill": 120,
]) );
        }
}

