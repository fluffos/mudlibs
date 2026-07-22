inherit ITEM;

void create()
{
        set_name("〖匕首入门〗", ({"dagger book", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
		set("value", 1000);
        set("material", "paper");
        set("skill", ([
                        "name": "dagger",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 20,
                        "max_skill": 80,
]) );
        }
}

