inherit NPC_OBJ;

void last_words();
int eaten;

string my_owner;

void setup() {
  set_name("cabbage");
  set_short("rotten cabbage");
  set_long( "A cabbage, partially decomposed, and rotten to the core...\n" );
  basic_setup("cabbage", 20, 0 );
} /* setup() */

void set_owner( object thing ) {
   my_owner = (string)thing->query_name();
  load_a_chat(30, ({
    1, "@growl",
    1, "@grumble",
      }));
  attack_ob(thing);
} /* set_owner() */


void init() {
  ::init();
  this_player()->add_command("eat", this_object());
} /* init() */

int do_eat() {
  write("You cannot bring yourself to eat such a disgustingly rotten cabbage!\n");
  return 0;
} /* do_eat() */

void event_exit(object ob) {
  if (!stringp(my_owner)) return ;
  if (ob == find_living(my_owner)) {
    call_out("check_env", 0);
  }
} /* event_exit() */

void event_dest_me(object ob) {
  call_out("last_words", 0);
} /*dest_me*/

void check_env() {
  if (!stringp(my_owner) || !find_living(my_owner)) {
    call_out("dest_me", 2);
    return ;
  }
   if ( environment() != environment( find_living( my_owner ) ) ) {
      move( environment( find_living( my_owner ) ),
            "$N appear$s with a squelch.", "$N disappear$s with a squelch." );
      command( "follow "+ my_owner );
   }
} /* check_env() */


void last_words() {
do_command("say Curses!  Foiled again!");
} /* last_words() */

string query_owner() { return my_owner; }

