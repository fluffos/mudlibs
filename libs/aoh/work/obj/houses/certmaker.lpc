#include <secure/wizlevels.h>
inherit "/std/thing";
string house_dir,exit,road, description,cert_file;
int price;

create() {
  (::create());
  SetShort("Certificate maker");
  AddId("certmaker");
  SetLong("use \"sell cert[ificate]\"\n\To escape in input type '~q'\n");
}
init() {
  (::init());
  if IS_IMMORTAL(this_player())
    add_action("sell","sell");
}
make7(arg) {
  if (arg=="~q") return 1;
  cert_file=arg;
  if ("/obj/houses/proppool"->AddProperty(house_dir, exit, road, to_int(price), description, cert_file) == 1) write("Ok.\n");
  return 1;
}
make6(arg) {
  if (arg=="~q") return 1;
  description=arg;
  write("\
Please give the full filename for the Certificate file you will use.\n\
The standard certfile is located in /d/avalon/common/std/cert_dummy\n\
Certificate file: ");
  input_to("make7");
}
make5(arg) {
  if (arg=="~q") return 1;
  price=arg;
  write("\
You have to enter the description which will be shown in the agancy.\n\
Normally it should be the name of the city/domain.\n\
In the agency you will read: A certificate for a house in <descr.>.\n\
Description: ");
  input_to("make6");
}
make4(arg) {
  if (arg=="~q") return 1;
  road=arg;
  write("\
Please enter the price for the house. The price is in copper coins.\n\
Price: ");
  input_to("make5");
}
make3(arg) {
  if (arg=="~q") return 1;
  exit=arg;
  write("\
Enter the full filename of the room which has to be connected with the\n\
entrance of the house garden.\n\
Room file: ");
  input_to("make4");
}
make2(arg) {
  if (arg=="~q") return 1;
  house_dir=arg;
  write("\
Enter the direction, to which the player has to leave his garden. He will\n\
go into the room, which you will specify after the direction.\n\
Exit lies to the: ");
  input_to("make3");
}
sell(arg) {
  if (arg != "cert" && arg != "certificate") return 0;
  write("\
Enter the full directory path where the houses have to be saved.\n\
House directory: ");
  input_to("make2");
  return 1;
}
