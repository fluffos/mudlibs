inherit "/std/object";

void setup()
{
    set_name("berry");
    add_property("no_undead",1); set_short("Berry");
    set_long("A magical berry with powerful resistant properties.\n");
    set_value(10);
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
    this_player()->add_timed_property("poison",1,1800);
    write ("You eat a berry.\n");
    tell_object(environment(this_player()), this_player()->query_cap_name()+ " eats "
      "a berry.\n", ({this_player()}) );
    this_player()->adjust_hp(2);
    if(TP->query_tmp_str() == 0)
    {
	TP->adjust_tmp_str(1);
    }
    this_object()->dest_me();
    return 1;
}
