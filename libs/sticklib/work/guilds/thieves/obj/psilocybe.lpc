inherit "obj/food";

#include <conditions.h>

reset(arg)
{
    ::reset(arg);

    set_name("small mushroom");
    set_id(({"mushroom", "small"}));
    set_eater_mess("Klunk...Oh wow! Everything looks so cosmic!\n");
    set_value(5);
    set_strength(1);
    set_weight(1);
    set_short("Small mushroom");
    set_long("It is a small, brown mushroom. Only an inch tall.\n");
}

query_info()
{
    return "Oh wow! It's a genuine \"psilocybe coprophila\"!\n";
}

extra_eat()
{
    if (!this_player()->query_condition(C_HALLUCINATING))
	this_player()->set_condition(C_HALLUCINATING, 60 + random(50));
}
