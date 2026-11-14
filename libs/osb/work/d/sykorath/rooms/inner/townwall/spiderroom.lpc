/*
 * part of the townwall
 *
 * last changes:
 * [m] 26 jan 98 - first version
 */

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <moving.h>
#include <sykorath.h>

inherit TOWNWALL;

int cobweb;

//***********
// properties
//***********
int QueryCobWeb() { return cobweb; }
int SetCobWeb(int w) { return cobweb=w; }

//****************
// special details
//****************
string look_cobweb() {
  if (cobweb) return
    "Some cobwebs are hanging around. You can touch them!";
  return "";
}

string detail_cobweb() {
  if (cobweb) return
    "Some cobwebs are hanging around. You can touch them!";
  return 0;
}

//**************
// touch cobwebs
//**************
int cmd_touch(string str) {
  object ob;
  if (!str) return 0;
  if (sizeof(regexplode(norm_id(str),
    "^(the|a|an|[ ])*(some )*cobweb(s)*$"))==3) {
    if (cobweb) {
      write("As you touch the cobwebs they fall down to the ground.\n");
      show(NAME+" touches the cobwebs and they fall down to the ground.\n");
      ob=clone_object("/std/thing");
      if (ob) {
        ob->SetProperties( ([
          P_IDS:  ({"cobweb","cobwebs"}),
          P_ADS:  ({"some"}),
          P_SHORT:"some cobwebs",
          P_LONG: "Some cobwebs, not really useful.\n",
          P_WEIGHT: 1,
          P_VALUE: 0,
          P_NODROP: "You can't get rid of them, because they are little "
                    "bit sticky.\n"
        ]) );
        ob->move(TO,M_SILENT);
        cobweb=0;
      }
    } else {
      if (present("cobweb")) {
        write("You touch them, but you can still get them!\n");
        show(NAME+" touches the cobwebs at the ground.\n");
        return 1;
      }
    }
    return 1;
  }
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  cobweb=1;
  SetIntShort("Inside the townwall");
  SetIntLong(
    "You are inside the townwall. @@look_cobweb@@\n");

  SetIndoors(1);
  SetCoordinates( ({ ({700,560,5}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  AddVItem( ([
    P_IDS:  ({"townwall"}),
    P_ADS:  ({"inside"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"cobweb","cobwebs"}),
    P_ADS:  ({"some"}),
    P_LONG: #'detail_cobweb ]) );

  /* Items */
  AddItem(NPC("townwall_spider"),REFRESH_REMOVE);

  /* commands */
  AddRoomCmd("touch","cmd_touch");

  /* exits */
  AddExit("northwest","./town68x54");
  AddExit("south","./plank");

  Set(P_INT_WIZMSG,
    "%^RED%^add something special, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

//**************
// special reset
//**************
reset() {
  ::reset();
  if (!cobweb) {
    show_room(TO,"The spider webs some new cobwebs.\n");
    cobweb=1;
  }
}

