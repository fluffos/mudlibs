inherit OBJECT_OBJ;

void setup () {
  set_short("snowman");
  set_long("A wonderful snowman with glowing eyes made of coal and twigs "+
           "for ears.\n");
  set_name("snowman");
  call_out("die",400);
  reset_get();
} /* setup() */

string long(string str, int dark) {
  int i;

  i=find_call_out("die");
  if (i > 300 || i < 0) {
    return ::query_long();
  }
  return ::query_long()+"It is "+({ "mostly", "half", "slightly" })[i/100]+
         " melted.\n";
} /* long() */

void die() {
  say("The snowman melts into the floor.\n");
  dest_me();
} /* die() */
