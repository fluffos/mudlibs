inherit "/std/object";

string me, him;

void setup() {
  set_name("wooden disc");
  set_short("wooden disc");
  set_long("This small wooden disc appears to be shaped in just the "
           "right way to catch the wind.  Strange symbols cover it "
           "in bright colours, making it stand out against the sky.\n");
  add_property("feeding_frenzy", "frisbee");
   add_alias("disc");
  set_weight(5);
  set_main_plural("discs");
}
int query_auto_load() {
   return 1;
}

void init() {
  add_action("throw", "throw");
  ::init();
}

int throw(string str) {
  object *from, *dest;
  int i, j;

  if (!str){
    tell_object(this_player(), "Toss the disc to someone.\n");
    return 1; }

  if (sscanf(str, "%s at %s", me, him ) != 2 &&
      sscanf(str, "%s to %s", me, him ) != 2 &&
      sscanf(str, "%s the %s", him, me) != 2 &&
      sscanf(str, "%s %s", me, him) != 2) {
  tell_object(this_player(), "Toss the disc to someone.\n");
    return 1; }
  him = (string)this_player()->expand_nickname(him);
  me = (string)this_player()->expand_nickname(me);
  from = find_match(me, this_player()) +
         find_match(me, environment(this_player()));
  dest = find_match(him, this_player()) +
         find_match(him, environment(this_player()));

  if (!sizeof(dest)) { 
   if (!find_living(him))
     return 1; 
    else
      dest = ({ find_living(him) });
  }
  for (i=0;i<sizeof(from);i++)
    for (j=0;j<sizeof(dest);j++)
      if (!from[i]->do_throw(dest[j]))
        write("You cannot throw "+from[i]->short()+".\n");
  return 1;
}

int do_throw(object dest) {
  if (environment() != this_player()) {
    write("You must have the "+short(0)+" to throw it.\n");
    return 1;
  }
   if(!dest->query_consent("tag")) {
    tell_object(this_player(), "That person is a big LOSER and "
    "doesn't want to throw the disc with you.\n (see 'help consent')\n");
    return 1; }
  say(this_player()->query_cap_name()+" throws "+me+" to "+him+"\n",
      ({ dest, this_player() }));
  write("You throw the wooden disc to "+him+".\n");
  if (move(dest)) {
    tell_object(dest, this_player()->query_cap_name()+" throws "+
             this_object()->short()+" at you, but it falls on the floor.\n");

    tell_room(environment(dest), "A wooden disc arcs through the air, "+
              dest->query_name()+" trys to catch it but fails and it "+
              "falls on the floor", ({ dest, this_player() }) );
    move(environment(dest));
  } else {
    tell_object(dest, this_player()->query_cap_name()+" throws a wooden disc "+
                "at you, you catch it... just.\n");
    tell_room(environment(dest), dest->query_cap_name()+
          " fumbles the catch of the "+
          short(0)+" but manages to keep hold of it.\n",
          ({ dest, this_player() }));
  }
  return 1;
}
