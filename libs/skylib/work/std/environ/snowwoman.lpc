inherit OBJECT_OBJ;

void setup () {
  set_short("snowwoman");
  set_main_plural("snowwomen");
  set_long("A wonderful snowwoman with glowing eyes made of coal and twigs "+
           "for ears.\n");
  set_name("snowwoman");
  call_out("die",400);
  reset_get();
} /* setup() */

string long(string str, int dark) {
  int i;

  if ((i=find_call_out("die")) > 300)
    return ::query_long();
  return ::query_long()+"It is "+({ "mostly", "half", "slightly" })[i/100]+
         " melted.\n";
} /* long() */

void die() {
  say("The snowman melts into the floor.\n");
  dest_me();
} /* die() */
