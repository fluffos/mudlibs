// restroom of the madmonks guild
// part of the Dojo
// made by MagicTCS 21/9/96

inherit "/players/magictcs/madmonks/restroom";   // ???
#define TP this_player()

void create() {
  ::create();
  SetIntShort("The restroom");
  SetIntLong("You are in the comfortable restroom of the MADMONKS' guild.\n"
    "This place is mostly used for restoring your health and for thanking\n"
    "and praying to your god for staying alive.\n"
    "A wonderful silence is around you.\n"
    "The restroom is part of the MADMONKS' dojo.\n"
    "All walls are made of paper pavarents. In one corner you can see a\n"
    "A geisha is sitting in one corner. You can call her for your needs.\n"
    "You can sit down, rest and pray");
  AddDetail(({"wall","walls"}),
    "The wall are made by the hard brown paper often used in japanese\n"
    "houses.\n");
  AddDetail(({"paper","brown paper"}),
    "You cannot see through the paper. But you see some shadows on the\n"
    "walls. It looks like that someone is running through the floor.\n");
  AddDetail("geisha",
    "She is wearing a long red kimono. A nice smile surrounds her lips. She\n"
    "looks very beautiful. A really nice girl. Ask her about food.\n");
  AddDetail(({"kimono","red kimono"}),
    "It is a high expensive kimono. Not all people can buy such a kimono.\n"
    "It is made of pure silk and is batiked by a master of this art.\n");
  SetIndoors(1);
  SetBright(100);
//  AddFood("some carrots",100, FOOD("carrots"));
//  AddFood("a cherry",10, FOOD("cherry"));
//  AddFood("a sandwich",50, FOOD("sandwich"));
//  AddFood("a bottle of orange juice",50, FOOD("juice"));
//  AddFood("a bottle of finest mead",20, FOOD("mead"));
//  AddExit("north", xxxxxxxxxxxxxx_exit???? );   // to the main dojo room
  AddRoomCmd("sit", "sit");
//  AddRoomCmd("rest","rest");
  AddRoomCmd("pray","pray");
  }

int sit() {
   write("You sit down on the earth and nod your head.\n");
   say(TP->QueryName()+" sits down on earth nodding his head.\n");
   return 1; 
}

int pray(string str) {   // restore some HP,SP ?
  if (!str) {
    write("You pray to your god for staying alive.\n");
    say(TP->QueryName()+" prays to his god.\n");
  }
  notify_fail("Try: pray (without any arguments)\n");
  return 0;
}
