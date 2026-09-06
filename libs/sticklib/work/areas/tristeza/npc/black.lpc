#include <npc.h>

#include <generic_items.h>

int coca, poti,hppoti;
void
create_monster()
{
    object amulet;

    set_name("man");
    set_short("A man hiding in the shadow");
    set_long("The man is hiding his face, and you get the feeling\n"+
      "that he might not be one of the good guys.\n"+
      "He seems to be selling something, so you might try 'list'.\n");
    set_money(100);
    set_alignment(AL_EVIL);
    set_level(16);
    set_hp(2500);
    set_ac(40);
    set_gender(G_MALE);
    //    set(NPC_YES_CONDITION);
    set_wc(16);
    coca = 10;

}

void
reset_monster()
{
    coca = 5;
    poti = 30;
    hppoti = 15;
}
void
init_monster()
{
    add_action("list_cmd", "list");
    add_action("buy_cmd", "buy");
}

int list_cmd()
{
    write("The man pulls you to the shadow and whispers:\n"+
      "I can offer you the best coca-leaves for only 6000 gold each.\n"+
      "       Coca leaf 6000,- (buy coca) "+coca+" left.\n"+
      "Or you could buy some of the potions I 'aquired':\n"+
      "       Fatigue potion 2500,- (buy potion) "+poti+" left.\n"+
      "       Hp-fp potion   5000,- (buy hpfp) "+hppoti+" left.\n\n");
    return 1;
}

int buy_cmd(string str)
{
    if(str != "coca" && str != "leaf" && str != "leaves" && str != "potion" && str != "hpfp")
    {
	notify_fail("Buy what?\n");
	return 0;
    }

    if(str == "coca" || str == "leaf")
    {
	if(coca <1) {
	    write("The man says: Don't have any\n");
	    return 1;
	}

	if(this_player()->query_money() < 6000)
	{
	    write("The man gets a grim look in his face as he says: You don't have the cash!\n");
	    return 1;
	}
	this_player()->add_money(-6000);
	move_object(clone_object(GENERIC_COCA), this_player());
	write("The man whispers to you: Here you go. Have fun.\n");
	coca--;
    }
    if(str == "potion")
    {
	if(poti <1) {
	    write("The man says: Don't have any\n");
	    return 1;
	}

	if(this_player()->query_money() < 2500)
	{
	    write("The man gets a grim look in his face as he says: You don't have the cash!\n");
	    return 1;
	}
	this_player()->add_money(-2500);
	move_object(clone_object(GENERIC_POTION_FP), this_player());
	write("The man whispers to you: Here you go. Have fun.\n");
	poti--;
    }
    if(str == "hpfp")
    {
	if(hppoti <1) {
	    write("The man says: Don't have any\n");
	    return 1;
	}

	if(this_player()->query_money() < 5000)
	{
	    write("The man gets a grim look in his face as he says: You don't have the cash!\n");
	    return 1;
	}
	this_player()->add_money(-5000);
	move_object(clone_object(GENERIC_POTION_FP_HP), this_player());
	write("The man whispers to you: Here you go. Have fun.\n");
	hppoti--;
    }
    return 1;
}
