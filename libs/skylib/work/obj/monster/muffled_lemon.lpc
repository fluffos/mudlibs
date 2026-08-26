inherit NPC_OBJ;

int eaten;

string my_owner;

void check_env();

void setup() {
  set_name("lemon");
  set_short("muffled lemon");
  set_long( "The lemon bounces around, dancing wildly as it tries "
            "desperately to sing, but there appears to be a bit of "
            "rind in its mouth, muffling the words.  It seems to be "
            "trying to sing quest solutions to you.\n");
  basic_setup("lemon", 1, 0);
} /* setup() */

void set_owner( object thing ) {
   my_owner = (string)thing->query_name();
  load_chat(30, ({
1, "@dance",
1, "@waltz",
1, "@bounce ex",
1, "@sing about quests",
1, "@sing wyrm sword...  forest...  hair...",
1, "@sing the Womble's brooch is hidden in the hints room",
1, "@caper",
1, "@think about forests",
1, "@wonder about how to complete those tricky quests",
1, (: do_command("whisper "+my_owner+
                     " Remember to whittle.") :),
1, (: do_command("whisper "+my_owner+
                     " Don't let mushrooms grow on your teeth.") :),
      }));
  check_env();
} /* set_owner() */

void init() {
  ::init();
  if (my_owner && !find_player(my_owner)) {
    command("cry");
    command("'Woe is me! Wherefore art thou, "+my_owner+"?");
    eaten = 1;
    call_out("dest_me", 8);
  }
  this_player()->add_command("eat", this_object());
} /* init() */

int do_eat() {
  if ((string)this_player()->query_name() != my_owner || eaten)
    return 0;
  this_player()->add_succeeded_mess(this_object(),
"$D zips madly around the room avoiding $N "
"as $r attempt to rip it's skin off and eat it.\n",
({ }) );
  do_command( "unfollow "+ my_owner );
  eaten = 1;
  call_out("do_the_eat", 1);
  call_out("dest_me", 8);
  return 1;
} /* do_eat() */

void do_the_eat() {
  do_command("wonder why people are so unkind");
  do_command("sigh");
  do_command(":slowly melts into the floor.");
} /* do_the_eat() */

int attack_by(object ob) {
  ob->stop_fight(this_object());
  tell_object(ob, "The lemon is a terrible pacifist.\n");
} /* attack_by() */

int attack_ob(object ob) {
  ob->stop_fight(this_object());
  tell_object(ob, "The lemon is a terrible pacifist.\n");
} /* attack_by() */

void event_exit(object ob) {
  if (!stringp(my_owner)) return ;
  if (ob == find_player(my_owner)) {
    call_out("check_env", 0);
  }
} /* event_exit() */

void event_dest_me(object ob) {
  call_out("check_env", 0);
} /* check_env() */

void check_env() {
  if (!stringp(my_owner) || !find_player(my_owner)) {
    command("cry");
    eaten = 1;
    call_out("dest_me", 2);
    return ;
  }
   if ( environment() != environment( find_player( my_owner ) ) ) {
      move( environment( find_player( my_owner ) ),
            "$N appear$s with a song.", "$N disappear$s with a song." );
      command( "follow "+ my_owner );
   }
} /* check_env() */

string query_owner() { return my_owner; }

void dest_me() {
   if ( environment() )
      all_inventory()->move( environment() );
   ::dest_me();
} /* dest_me() */
