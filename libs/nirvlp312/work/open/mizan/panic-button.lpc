id(str) { return str == "button"; }
short() { return "A panic button"; }
long() { 
  write("This is a large red button mounted nowhere in particular. It is here\n"+
	"for the people who are pulling their hair out trying to escape this\n"+
	"realm. Push it and see what happens.\n");
}

init() {
  add_action("boink","push");
}

boink(str) {
  if(!str || str!="button") return 0;
  write("You push the button, fall dizzy, and awaken elsewhere...\n");
  this_player()->move_player("in a puff of goofiness#room/church");
  return 1;
}
