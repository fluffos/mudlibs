inherit "std/thing";

create() {
   ::create();
   SetIds( ({"guide","book"}) );
   SetAds( ({"guide","flood","control"}) );
   SetShort("a guide book to Flood Control Dam #3");
   SetLong(
"This is a small book. The title should tell you what it is about.\n");
 SetWeight(300);
 SetValue(45);
}

init() {
  ::init();
  add_action("read","read");
}

read(string str) {
  if (!str) {return;}
  if (!id(str)) return 0;
write(
"                  Guide Book to Flood Control Dam #3\n\n"
"Flood Control Dam #3 (FCD3) was constructed in the year 789 of the Great "
"Underworld Empire to harness the destructive power of the Frigid River. "
"This work was supported by a grant of 37 million zorkmids from the central "
"bureaucracy and your own omnipotent local tyrant Lord Dimwit Flathead the "
"Excessive. This impressive structure composed of 3.7 cubic feet of concrete "
"is 256 feet tall at the center, and 193 feet wide at the top. The reservoir "
"created behind the dam has a volume of 37 billion cubic feet, an area of 12 "
"million square feet, and a shore line of 36 thousand feet.\n"
"The construction of the FCD3 took 112 days from ground breaking to the "
"dedication. It required a work force of 384 slaves, 34 slave drivers, 12 "
"engineers, 2 turtle doves, and a partridge in a pear tree. The work was "
"managed by a command team composed of 234 bureaucrats, 2347 secretaries "
"(at least two of whom could type), 12256 paper shufflers, 52469 rubber "
"stampers, 245193 red tape processors, and nearly one million dead trees.\n");
  return 1;
}
