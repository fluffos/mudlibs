inherit"std/object";

void init() {
    add_action("read_me","read");
}
int query_auto_load()
{
    return 1;
}

void setup()
{
    set_name("parchment");
    add_alias("paper");
    set_main_plural("parchments");
    add_plural("papers");
    set_short("Parchment");
    set_long("This is a dirty old piece of parchment.  It is "
      "rotten and wet.  Suprisingly, most of the writing "
      "looks readable.  "
      "\n\n");

    set_weight(2);
    set_value(0);
}


int read_me(string str) {
    if(str == "parchment" || str == "paper"){
	tell_room(environment(this_player()),this_player()->query_cap_name()
	  +" reads a tattered old parchment.  It falls apart "
	  "and scatters all over the floor.\n",({ this_player() }));
	write("The parchment reads:\n"
	  "Instructions on the use of a rope.\n"
	  "The parchment teaches you how to tie and climb "
	  "up or down a rope.\n"
	  "Just as you finish reading it, the parchment breaks "
	  "apart and falls to the floor. "
	  "\n\n");
	this_player()->add_property("skill_rope_knots",5);
	this_player()->add_property("skill_rope_climbing",5);
	this_player()->add_property("DWARVEN_ROPE",1);
	write_file("/d/mm/logs/ROPE_QUEST",this_player()->query_cap_name()+
	  " Has completed the rope-skills quest in the Dwarven "
	  "area on: "+ctime(time())+"\n");
	this_object()->dest_me();
	return 1;
    }

}
