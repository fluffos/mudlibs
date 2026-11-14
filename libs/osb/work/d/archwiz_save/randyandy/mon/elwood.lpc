/* Elwood Blues of the famous Blues Brothers! */

#include <properties.h>
inherit "std/npc";

void create() {
     if (::create()) return;
     SetName("elwood");
     SetShort("Elwood Blues");
     SetLong(
"You look at Elwood Blues, one of the famous Blues Brothers!\n");
     AddId("blues");
     AddId("elwood blues");
     SetLevel(12);
     SetHP(300);
     Set(P_ALIGN,500);
     SetAC(15);
     SetRace("human");
     SetGender(1);
     Set(P_HANDS,({
                ({"right fist",0,17}),
                ({"left fist",0,15}) }) );
     InitChats(23,({
               "Elwood says: We're on a mission from god.\n",
               "Elwood says: I lost contact to the band while my brother Jake was in prison.\n",
               "Elwood says: Can you help us re-uniting the band?\n",
               "Elwood says: Order a toast for me!\n",
               "Elwood tells you: Are you sure, you are clever enough to help us?\n",
               "Elwood says: You must find find Matt 'Guitar' Murphy!\n"}));
}



