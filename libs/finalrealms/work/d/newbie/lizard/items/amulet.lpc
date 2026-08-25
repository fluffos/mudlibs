inherit "/obj/armour";
void setup(){
    set_base_armour("amulet");
    set_name("amulet");
    set_short("Amulet of K'Laktaar");
    set_main_plural("amulets");
    set_weight(2);
    set_long("This is an ancient Amulet of the K'Laktaar.  Legend has"
      " that the K'Laktaar were a superior race of lizard-men"
      " that refined their abilties so that they were as skilled"
      " under the water as they were above it.\n");
    reset_drop();
}

void init()
{
    ::init();
    add_action("rub_amulet","rub");
}
int rub_amulet(string str)
{
    if(str != "amulet")
    {
	return(0);
    }
    {
	write("As you rub the legendary amulet the power of the "
	  "K'Laktaar rushes into your cold blood.\n");
	this_player()->adjust_hp(random(3)+1);
	return(1);
    }
}
