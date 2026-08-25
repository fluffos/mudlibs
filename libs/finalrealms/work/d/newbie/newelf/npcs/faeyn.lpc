inherit "/obj/monster";
/* changed from /w/devoe to /d/of by Jedi 5/11/93 */
void setup()
{
    //set_name("faeyn");
    add_alias("treant");
    add_alias("faeyn");
    add_alias("oak");
    set_short("Faeyn the Treant");
    set_long("This is Faeyn the Treant.  He advises the elves "
      "on living peacefully in the forest.  He is as strong as "
      "an oak, partly because he is an oak.\n");
    set_race("treant");
    set_guild("fighter");
    set_random_stats(10,18);
    set_str(18);
    set_level(20);
    adjust_money(10,"silver");
    set_gender(1);
    set_al(50);
}

void init() {
    ::init();
    call_out("first_approach",0,this_player());
}
int first_approach(object ob)
{
    write("A majestic oak comes to life and addresses you.\n");
    do_command("'I am Faeyn, leader of these woods.  These once peaceful "
      "woods have become infested with evil.  Please help us destroy the "
      "enemies of the forest!"
      "\n");
}


int event_person_say(object ob,string str, string mess)
{
    string s1;
    string *messes;
    messes = explode(mess," ");
    if(member_array("poison",messes) != -1)
    {
	do_command("'The only poisonous creatures in this woodland "
	  "are the wood imps.  There poison can be "
	  "deadly to an adventurer like you.  However "
	  "far to the north, near the entrance to the "
	  "evil part of the forest the imps call home, "
	  "grows a bush in a strange glade.  The berries "
	  "of this bush will give your body resistance "
	  "to the wood imp poison when eaten.\n");
	do_command("'I strongly suggest you seek out this bush "
	  "before doing combat with the imps.\n");
	return(1);
    }

}
