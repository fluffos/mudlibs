/* Matt 'Guitar' Murphy */

#include <properties.h>
inherit "std/npc";

void create() {
     if (::create()) return;
     SetName("matt");
     AddId("matt murphy");
     AddId("matt 'guitar' murphy");
     AddId("murphy");
     SetShort("Matt 'Guitar' Murphy");
     SetLong(
"You see Matt 'Guitar' Murphy. He once played guitar for the Blues Brothers "+
"but now he has married and runs the Soul Food Cafe with his wife.\n");
     SetLevel(12);
     SetHP(300);
     Set(P_ALIGN,500);
     SetAC(15);
     SetRace("human");
     SetGender(1);
     Set(P_HANDS,({
               ({"right fist",0,15}),
               ({"left fist",0,14}) }) );
     call_out("leave",10);
}


leave() {
	say("Matt 'Guitar' Murphy leaves.\n"); 
/*      tell_room(environment(this_object()), "Matt 'Guitar' Murphy leaves.\n"); */
        destruct(this_object());
	return 1;
}

