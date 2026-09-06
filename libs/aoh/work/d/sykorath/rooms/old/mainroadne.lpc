// part of the town
// made by magictcs - 22 may 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>

#include <sykorath.h>

inherit BASEROOM;

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
int search_puddle(string str) {
  object ob;
  notify_fail("You found nothing.\n");
  if (!str) return 0;
//::search(str);
  if (str=="puddle" || str=="small puddle") {
    say(NAME+" searches the puddle.\n");
    if (key) {
      ob=clone_object(OBJ("townwallkey"));
      ob->move(TO,M_SILENT);
      write("As you search the puddle you get wet fingers, but you find "
            "a small key.\n");
      TP->Take(ob,PUTGET_FULL);
      key--;
      return 1;
    } else {
      write("As you search the puddle you get wet fingers.\n"
            "The blinking something must be an illusion.\n");
      return 1;
    }
  }
  return 0;
//::search(str);
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

create() {
  ::create();
  water=50;
  key=1;
  SetIntShort("A dead end");
  SetIntLong(
    "The road ends directly before the high townwall. No way leads further!\n"
    "You can go back to the main plaza.\n"
    "The ground seems to be wet.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({35,31,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"end","dead end","road"}),#'IntLong);
  AddDetail(({"townwall","high townwall"}),
    "It is a very old wall, built of big stones, made of granite.\n"
    "The townwall is too high to climb. You can't pass the wall.\n");
  AddDetail(({"way","way back","main plaza"}),
    "The way leads back to the main plaza.\n");
  AddDetail("main plaza","The main plaza can be found to the southwest.\n");
  AddDetail(({"ground","wet ground"}),
    "There is a small puddle on the ground.\n");
  AddDetail(({"puddle","small puddle","water","drinkable water"}),
    "The small puddle is filled with drinkable water.\n"
    "Something blinks in the puddle.\n");
  AddDetail(({"something","something in the puddle","something in puddle"}),
    "Maybe you can search the puddle?\n");

  /* commands */
  AddRoomCmd("enter",#'enterpuddle);
  AddRoomCmd("drink",#'drink_water);
  AddRoomCmd("search",#'search_puddle);

  /* exits */
  AddExit("southwest","./mainplaza");
}

reset() {
  ::reset();
  water=50;
  key=1;
}

