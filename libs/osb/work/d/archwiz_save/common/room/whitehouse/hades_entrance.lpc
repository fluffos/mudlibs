inherit "std/room";

int try_north() {
  return (int) notify_fail(
    "Some invisible force prevents you from passing through the gate.\n") && 0;
}

create() {
  ::create();
  SetIntShort("Entrance to Hades");
  SetIntLong(
"You are outside a large gateway, on which something is inscribed. "
"The gate is open; through it you can see a desolation, with a pile "
"of mangled bodies in one corner. Thousands of voices, lamenting "
"some hideous fate, can be heard.\n"
"The way through the gate is barred by evil spirits, who jeer at "
"your attempts to pass.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"large gateway","gateway"}),"There's an inscription above it.\n");
  AddDetail("inscription","You may read it.\n");
  AddDetail(({"gate","evil gate"}),
    "It looks as if you shouldn't try it out.\n");
  AddDetail(({"desolation"}),"You don't want to be there.\n");
  AddDetail(({"pile","pile of mangled bodies","pile of bodies"}),
    "IIIIIIEEEEEEEKS!\n");
  AddDetail(({"bodies","body"}),"The bodies don't look very lively anymore.\n");
  AddDetail(({"spirit","spirits","evil spirits","evil spirit"}),
    "The evil spirits bar the gate.\n");
  SetIntNoise("You hear hollow voices lamenting.\n");
  AddReadMsg("inscription",
    "You read:\n  Abandon every hope all ye who enter here!\n\n");
  AddExit("north",#'try_north);
  AddExit("up","./cave1");
}
