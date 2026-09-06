/*
 * a small puddle with some special commands :)
 * made by magictcs - 22 may 97
 *
 * last changes:
 * [m] 08 jan 97 - remade
 */

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <skills.h>
#include <sykorath.h>

inherit SY_STREET;

int water,key;

//**************
// drink command
//**************
int drink_water(string str) {
  string norm;
  int drink;
  notify_fail("You can drink water from puddle.\n");
  if (!str) return 0;
  norm=norm_id(str);
  if (str=="water from puddle" || str=="water from small puddle") {
    if (water>0) {
      drink=TP->QueryDrink();
      if (TP->QueryMaxDrink()<=drink) {
        write("You can't drink anymore!\n");
        say(NAME+" tries to drink water from puddle, but fails.\n");
        return 1;
      }
      drink+=10;
      water-=10;
      if (drink>=TP->QueryMaxDrink()) drink=TP->QueryMaxDrink();
      TP->SetDrink(drink);
      write("You drink some water from the puddle.\n");
      say(NAME+" drinks some water from puddle.\n");
      return 1;
    }
    else {
      write("There is not enough water left in the puddle. Try it later!\n");
      say(NAME+" tries to drink water from puddle, but fails.\n");
      return 1;
    }
  }
  return 0;
}

//***************
// search command
//***************
int OnSucceedSearchingPuddle() {
  object ob;
  if (key) {
    ob=clone_object(OBJ("townwallkey"));
    ob->move(TO,M_SILENT);
    write("As you search the puddle you get wet fingers, but you find "
          "a small key.\n");
    TP->Take(ob,PUTGET_FULL);
    key--;
  } else {
    write("As you search the puddle you get wet fingers.\n"
          "The blinking something must be an illusion.\n");
  }
  return 1;
}

int OnFailSearchingPuddle() {
  write("You search the small puddle, but find nothing. Maybe you are "
    "experienced enough?\n");
  return 1;
}

//**************
// enter command
//**************
int enterpuddle(string str) {
  notify_fail("Enter what?\n");
  if (str=="puddle" || str=="small puddle") {
    write("You enter the puddle.\n");
    write("You got some wet feet.\n");
    show(NAME+" enters the puddle and got some wet feet.\n");
    return 1;
  }
  return 0;
}

//*********
// climbing
//*********
int OnFailClimbingTownwall() {
  write("You try to climb the townwall, but it is too high.\n");
  return 1;
}
int OnSucceedClimbingTownwall() {
  write("You try to climb the townwall, but it is too smooth.\n");
  return 1;
}

//*******
// create
//*******
create() {
  string townwall;
  ::create();
  water=50;
  key=1;
  SetIntShort("A dead end");
  SetIntLong(
    "The road ends directly before the high townwall. No way leads further!\n"
    "You can go back to the main plaza.\n"
    "The ground seems to be wet.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({640,560,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"end","dead end","road"}),
    P_LONG: #'IntLong ]) );
  townwall=AddVItem( ([
    P_IDS:  ({"townwall"}),
    P_ADS:  ({"high"}),
    P_LONG: "It is a very old wall, built of big stones, made of "
            "granite. The townwall is too high to climb. You can't pass "
            "the wall.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"way","way back"}),
    P_LONG: "The way leads back to the main plaza.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"mainplaza","main"}),
    P_ADS:  ({"main"}),
    P_LONG: "The main plaza can be found to the southwest.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"ground"}),
    P_ADS:  ({"wet"}),
    P_LONG: "There is a small puddle on the ground.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"puddle"}),
    P_ADS:  ({"small"}),
    P_LONG: "The small puddle is filled with drinkable water. Something "
            "blinks in the puddle.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"water"}),
    P_ADS:  ({"drinkable"}),
    P_LONG: "The warer looks drinkable.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"something","something in the puddle","something in puddle"}),
    P_LONG: "Maybe you can search the puddle?\n" ]) );

  /* commands */
  AddRoomCmd("enter",#'enterpuddle);
  AddRoomCmd("drink",#'drink_water);
  AddSkill(SK_SEARCH,"puddle",25,({"puddle","small puddle"}));
  // climb uses the added VItem for it
  AddSkill(SK_CLIMB,"townwall",100,townwall);

  /* exits */
  AddExit("southwest","./mainplazane");

  Set(P_INT_WIZMSG,
    "%^RED%^add details, make it friendlier!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

//**************
// special reset
//**************
reset() {
  ::reset();
  water=50;
  key=1;
}

