/* The little kiosk in the harbour of Nightfall */

inherit "/std/shop";

#include "path.h"
#include <rooms.h>
#include <doors.h>

create() {
  ::create();
  SetIntShort("The harbour shop");
  SetIntLong(
"The shop looks a little bit strange: You see ships hanging from above. Other "
"ships, built in little bottles, stand on shelves on the wall. It looks like a "
"real sailor shop. The shop seems to sell useful things for a sea trip. "
"To the east a door leads out to the harbour.\n");
  SetAppraise(0);
  SetSell(0);
  ForbidShopkeeper();
  RemoveDustbin();
  AddDetail(({"hanging ship","hanging ships","ships"}),
"You see all kinds of ships hanging her: little and big, old and new, "
"clippers, barks, schooners, trawlers and other fishboats, dragonboats from "
"Norway and from China, kajaks like build by the Inuits, dhaus from Arabia, "
"schebeks from Turkey, cargos from Java, perldiverboats from Persia... "
"All these ships seems to be souvenirs from all over the world.\n");
  AddDetail(({"bottle ship","bottle ships","bottleship","bottleships"}),
"It must be a difficult work to build these filigran bottleships. Like the "
"hanging ships you see here ship types from all over the world. Somebody in "
"this shop seems to be a fanatic collector of these shipmodels.\n");
  AddDetail("window",
    "The coloured glass shows a kogge sailing in the storm.\n");
  AddDetail("shelves",
"The shelves are fulfilled with dried seastars, cancers, phantasticly formed "
"snailhouses, and bottleships.\n");
  AddDetail(({"seastars","cancers","snailhouses"}),
"That are typical souvenirs from the trips over the oceans.\n");
  AddDoor("east","./nf_port","shop door",
    "The door is made from wood. A window of coloured glass lets the sun in.\n"
    ,0,DOOR_STATUS_OPEN);
  AddArticle(OBJ("kiss"),REFRESH_REMOVE,6);
  AddArticle(OBJ("meter"),REFRESH_REMOVE,3);
  AddArticle(OBJ("magicdie"),REFRESH_DESTRUCT,3);
  AddArticle(OBJ("garbage"),REFRESH_REMOVE,2);
  AddArticle(OBJ("hpmon"),REFRESH_REMOVE,4);
  AddArticle(OBJ("note"),REFRESH_REMOVE,6);
  // BEGONE AddArticle(AVAOBJ("shipguide"),REFRESH_REMOVE,6);
  // BEGONE AddArticle("/p/houses/common/obj/catalogue",REFRESH_REMOVE,6);
  // BEGONE AddArticle("/players/thragor/club/club_ring",REFRESH_REMOVE,6);
}
