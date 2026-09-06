inherit "/std/thing";

#include <properties.h>
#include <moving.h>

int pbut;
int val;
int kickc;

init() {
    add_action("insert_disp", "insert");
    add_action("press_but", "press");
    add_action("press_but", "push");
    add_action("press_but", "button");
    add_action("press_but", "drink");
    add_action("kick", "kick");
}

create() {
    ::create();
    kickc=0;
    pbut=0;
    AddId("dispenser");
    SetShort("Drink dispenser");
    SetLong("You can buy drinks from this dispenser. At first you have "+
         "to select a drink, then you have to insert the coins. After this "+
         "is done, the selected drink will appear.\n"+
         "\n"+
         "You see some buttons and the following legend:\n"+
         "  Drink                         Button       Price\n"+
         "------------------------------------------------------\n"+
         "  Reset                         button (0)\n"+
         "  Cup of tea                    button (1)    15 coins\n"+
         "  Large vacuum flask\n"+
         "  of espresso coffee            button (2)   100 coins\n"+
         "  Pangalactic gargle blaster    button (3)   210 coins\n\n\n"+
         "Under the legend you read:\n"+
         "   The Surgeon General: The drinks of this dispenser\n"+
	 "   impair your health!\n"+
	 "There is a small note on it which you can read.\n");
     Set(P_NOGET,"The dispenser is too heavy.\n");
   Set(P_HELP_MSG,
"Dispensers are useful inventions, giving out lots of necessities for "
"Adventurer's daily life. Usually they are operated by inserting money "
"and/or pressing buttons, but some also react on kicking.\n"
      );
}


insert_disp(str) {
    write("This is not the correct amount of coins.\n");
    write("The dispenser doesn't accept them. Get\n");
    write("your money and try it again.\n");
    write("The dispenser seems to be out of order.\n");
  return 1;
}

press_but(str) {
    write("Nothing happens. The dispenser seems to be out of order.\n");
    return 1;
}

kick(str) {
object coi;
  if (!str) return 0;
  if (str=="dispenser") {
  kickc++;
  if (kickc==2) {
     show(this_player()->QueryName()+" kicks the dispenser.\n",this_player());
     tell_room(environment(),"Something tinkles inside the dispenser.\n"+
     "A bottle of espresso falls out of the dispenser.\n");
     coi=clone_object("/d/archwiz/firestone/espresso");
     coi->move(environment(this_object()));
     return 1;
  }
  if (kickc>2) {
    write("You are beamed away.\n");
    show(this_player()->QueryName()+" becomes indistinct and disappears.\n",
      this_player());
    tell_room("/d/archwiz/firestone/transp",
	       this_player()->QueryName()+" arrives in a puff of smoke.\n");
    this_player()->move("/d/archwiz/firestone/transp", M_GO, "away");
    call_other("/d/archwiz/firestone/transp","long");
    call_other("/d/archwiz/firestone/transp","init_tell");
    kickc=1;
    return 1;
  }
  show(this_player()->QueryName()+" kicks the dispenser.\n",this_player());
  tell_room(environment(),"Something tinkles inside the dispenser.\n"+
        "Some money appears!\n");
  coi=clone_object("/obj/money");
  coi->AdjustMoney((["copper":20+random(130)]));
  coi->move(environment(this_object()),M_SILENT);
  return 1;
  }
}
