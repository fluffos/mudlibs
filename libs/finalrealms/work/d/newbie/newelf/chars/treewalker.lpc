inherit "/obj/monster";

int ob;
mapping treewalking_quest;

void setup()
{

    set_name("treewalker");
    set_main_plural("treewalkers");
    set_race("elf");
    set_short("treewalker");
    set_long("An old elf who has lived in these woods for years,"
      " Treewalker is the most expert person at walking on the treetops.\n");
    set_level(15);
    set_wimpy(0);
    set_al(-200);
    // add_attack("spell", 0, 10, 210, 50, 0, "magic");
    load_chat(70,({
	1,"Treewalker says:'Who are you and what are you doing here?'",
	1,"Treewalker says:'Why can't yall just leave me alone?'",
	1,"Treewalker says:'I don't have to train you and wipe yer butts anymore.'",
	1,"Treewalker says:'Goodbye, go away, leave me alone!'",
      }));
}
