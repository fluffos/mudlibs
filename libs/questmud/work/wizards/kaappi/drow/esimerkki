inherit "room/room";
static int opened;
reset(arg) {
        if(arg) return;
        add_exit("west","room13");
        add_exit("east","room15");
        short_desc = "A front of the huge twisted oak";
  long_desc = "The roaring sound which you heard earlier is coming from that fabulous and\n"+
              "huge looking oak. It seems like that oak is some kind of a portal to somewhere.\n"+
              "This part of forest is full of that strange mist and it seems like the mist is\n"+
              "is coming from inside that oak, this is surely a strange place.\n";
items = allocate(4);
items[0] = "oak";
items[1] = "The oak looks absolutely huge. That strange mist what is floating all-around this forest is coming inside that oak";
items[2] = "portal";
items[3] = "That oak seems to be somekind of portal, all those light flashing and things. You start to wander how can that portal be opened!";
}

init() {
	::init();
	add_action("yell", "yell");
}
yell(string str) {
if(!str) {
	write("Yell what?\n");
return 1;
}
if(str == "Behold iam the mighty overlord and i command you to open" && !opened && this_player()->query_alignment() > 0) {
write("As you yell those words the portal opens!\n");
shout("A demonical roar can be heard as "+this_player()->query_name()+" opens the mighty portal of darkness!\n");
add_exit("portal", "portalroom");
opened = 1;
return 1;
}
if(str == "Behold iam the mighty overlord and i command you to open" && !opened && this_player()->query_alignment() < 0) {
write("As you yell those words the portal opens and a mighty god of darkness appears and zaps you with strange magic!\n");
this_player()->death();
return 1;
}
write("You yell "+str+" but nothing happens!\n");
return 1;
}