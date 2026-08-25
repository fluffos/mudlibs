//by Taggert
inherit "/obj/armour";
void setup()
{
    set_base_armour("amulet");
    set_name("pendant");
    set_main_plural("Shirein's Pendants");
    set_short("Shirein's Pendant");
    set_long("\nThis is the pendant you have heard Eldevan speaking "
      "of many times before. You wonder what good it will be to him "
      "upon return, but it is good that you have found it, he will be "
      "so much happier to have it returned.\n");
    add_alias("pendant");
    add_plural("pendants");
    add_plural("shirein's pendants");
}
int set_in_use(int flag) {
    if(this_player()->query_race() =="drow" |this_player()->query_race() =="goblin" | this_player()->query_race() =="orc" | this_player()->query_race() =="duergar" | this_player()->query_race() =="troll" | this_player()->query_race() =="vampire" ) {
	call_out("dest_me", 0);
write("\nThe pendant burns your neck!!\n");
	this_player()->adjust_hp(-2);
    }
    else
    if(flag == 1){
	write("\nYou gently slip the old pendant on and feel "
	  "like you could do cartwheels around the world.\n");
	this_player()->adjust_con(1);
    }
    else{
	write("\nYou gently unclasp the pendant from your neck, hoping you "
	  "don't break it.");
	this_player()->adjust_con(-1);
    }
    return ::set_in_use(flag);
}
