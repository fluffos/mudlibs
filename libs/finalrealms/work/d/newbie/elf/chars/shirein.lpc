/* Coded By Darknight : Thane of Nothing, April 95 */
inherit "obj/monster";
# include "path.h";
void setup() {

	set_name("shirein");
	set_main_plural("shireins");
	set_short("Shirein");
        set_gender(2);
set_level(4);
set_random_stats(3,18);
set_long("This old woman is Shirein, wife to Eldevan the smith. "
		"She has been weeping ever since her son  dissappeared "
		"into the gloomy forest.  She looks so sad, perhaps "
		"you should 'console' her.\n\n");

 load_chat(95,
  ({
     1,"Geldon ....... You have returned, oh, I'm sorry "
		"I thought you were someone I knew.",
	1,"'Why did the Imps take MY son, my ONLY son?",
	1,"'Please, If it's the last thing you do, rid the forest "
	"of these wretched Imps!",
	1,":sobs quietly over her missing son."
	}));
}


void init()
{
	add_action("comfort_shirein","console");
}


int comfort_shirein()
{
do_command("'Thank you for consoling an old woman.  Perhaps "
		"a brave adventurer such as yourself could help me find "
		"my lost son.\n");
	do_command("'His name is Geldon, and he ventured into the gloomy "
		"woods to the north and never returned.\n");
	do_command("'You will need help to get through those woods.  Seek "
		"out my husband, the fabled smith Eldevan, and say our son's "
		"name to him. He will assist you and send you on your way.\n");
  return 1;
}

