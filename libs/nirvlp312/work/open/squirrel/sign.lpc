short() { return "A sign from the MANAGEMENT (read sign)"; }
long() {
  write(short()+"\n");
  write("It appears to address some issues of recent importance.\n");
}
id(str) { return str = "sign"; }
init() { add_action("read_sign","read"); }
read_sign(str) {
  if(!id(str)) return ;
  write("Guests of Nirvana -\n");
  write("  We're really sorry. We dont know what the hell has happened, but\n");
  write("somehow a bunch of squirrels have traveled from nearby forests into\n");
  write("town. Oddly enough, no exterminators are working today, so it looks\n");
  write("like we'll just have to put up with the little pests until tomorrow.\n");
  write("It should be ok though, they're kinda cute and fuzzy.\n");
  write("\t\t\t\t\t\tThe MANAGEMENT\n");
  return 1;
}
