inherit "/std/object";

void setup()
{
    set_name("leaf");
    add_property("no_undead",1); set_short("Leaf");
    set_long("\nThis silver leaf obviosly magical, with some "
      "strange veins running through it of different colours.\n");
    set_value(20);
    set_weight(1);
}
int query_auto_load() { return 1; }

void init()
{
    add_action("eat_me", "eat");
    ::init();
}

int eat_me()
{
    write ("You eat a leaf.\n");
    tell_object(environment(this_player()), this_player()->query_cap_name()+ " eats "
      "a leaf.\n", ({this_player()}) );
    this_player()->adjust_hp(2);
    if(TP->query_tmp_str() == 0)
    {
	TP->adjust_dex(1);
    }
    this_object()->dest_me();
    return 1;
}
