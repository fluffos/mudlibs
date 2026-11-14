/* Jake Blues of the famous Blues Brothers! */

#include <properties.h>
inherit "std/npc";

void create() {
     if (::create()) return;
     SetName("jake");
     SetShort("Jake Blues");
     SetLong(
"You look at Jake Blues, one of the famous Blues Brothers!\n");
     AddId("blues");
     AddId("jake blues");
     SetLevel(12);
     SetHP(300);
     Set(P_ALIGN,500);
     SetAC(15);
     SetRace("human");
     SetGender(1);
     Set(P_HANDS,({
                ({"right fist",0,15}),
                ({"left fist",0,14}) }) );
     InitChats(20,({
               "Jake says: We're on a mission from god.\n",
               "Jake says: The Band! The Band! Only the band can help!\n",
               "Jake says: I've been in prison for 3 years.\n",
               "Jake says: Order 4 chicken and a coke at the Soul Food Cafe.\n",
               "Jake tells you: Please help us to get the band together! Please, please, please!\n",
               "Jake says: Please find Matt 'Guitar' Murphy!\n"}));
}



