// Ilz coded this.
// 24 Apr 98 Cyanide lowered the cost a little. Was WAY too high.

#include <mudlib.h>

inherit ROOM ;

void create() {
    ::create();
    set ("light", 1) ;
    set ("long",
      "This is The Society For the Luminiferous Aether.\n"+
      "Mages Only Are allowed past these doors.\n"+
      "For a small price (10 coins per point) the mages will\n"+
      "Recharge your spell points.\n"+
      "Just type recharge.\n");
    set ("short", "Mage Society") ;
}


void init(){
    add_action("recharge", "recharge");
}

int recharge(){

    int cost, spgain, spmax;

    spmax = TP->query("max_sp");
    spgain = ( spmax - TP->query("spell_points"));

    if (!spgain){
	write("You have all your spell points!\n");
	return 1;
    }
    cost = (spgain * 5);

    if (!(TP->debit(cost))){
	write("You do not have enough money for a recharge!\n");
	return 1;
    }

    TP->set("spell_points", spmax);
    write("The society draws upon their pool of mystic power to recharge you!\n");
    write("They charge you "+cost+" coins.\n");
    return 1;
}
