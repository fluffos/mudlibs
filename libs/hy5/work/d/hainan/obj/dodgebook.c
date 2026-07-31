// literate.c

inherit ITEM;

void create()
{
        set_name("〖观音普渡经〗", ({"jing", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
	set("long", "一本很旧的书。\n");
        set("material", "paper");
        set("skill", ([
                        "name": "dodge",
                        "exp_required": 500,
                        "jing_cost": 20,
                        "difficulty": 20,
                        "max_skill": 140,
]) );
        }
}

