        /*Charity's Danny for NF's Folk Club  */
#include <properties.h>
inherit "std/npc";
create() {
 if (::create()) return 1;
  SetName("Danny");
  SetShort("Danny");
  SetLong("Danny is short, and has dark hair. He is dressed in a tee-shirt, and corduroy pants...\n");
  SetRace("bard");
  AddId("danny");
SetLevel(10);
  Set(P_ALIGN,100);
  Set(P_AC,2);
  Set(P_NOGET,"Danny fends you off by bashing you with his guitar. He'll be sending you the bill for damage.\n");
  SetGender(1);
  InitChats(3,({"Danny clears his throat.\n",
 "Danny takes a sip of water.\n",
 "Danny winks at you.\n",
 "Danny smiles happily at you.\n",
 "Danny plays and sings a song.\n",
 "Danny plays and sings a song that you requested.\n",
 "Danny plays and sings a song dedicated to you.\n",
 "Danny asks: 'Any requests?' \n",
 "Danny says: 'Thank you all for coming. I'm glad you could be here.' \n",
 "Danny says: 'I've got a little song here, that I hope you'll like.' \n",
 "Danny says: 'Feel free to sing along if you know it.' \n"}));
}
init() {
 ::init();
}
