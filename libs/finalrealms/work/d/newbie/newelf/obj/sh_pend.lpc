//by Taggert
inherit "/obj/armour";
void_setup()
{
    set_base_armour("amulet");
    set_short("Shirein's Pendant\n");
    set_long("\nThis is the pendant you have heard Eldevan speaking "
      "of many times before. You wonder what good it will be to him "
      "upon return, but it is good that you have found it, he will be "
      "so much happier to have it returned.\n");
    add_alias("pendant");
    set_main_plural("Shirein's Pendants");
    add_plural("pendant's");
    add_plural("shirein's pendants");
}
void init(){
    add_action("do_wear","wear");
    ::init();
}
int do_wear(string str)
{
    if(str == "pendant")
    {
	if(this_player()->query_set_in_use() == "pendant") {
	    write("\nYou are already wearing this pendant.\n");
	    return 0;
	}
	else{
	    write("\nYou gently slip the old pendant on and feel "
	      "like you could do cartwheels around the world.\n");
	    this_player()->adjust_con(1);
	    return(1);
	}
    }
}
