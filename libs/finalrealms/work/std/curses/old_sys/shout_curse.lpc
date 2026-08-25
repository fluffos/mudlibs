#include "path.h"
#define MY_NAME "Shout curse"

/*
 * The upper case curse.  Means everything you say comes out in upper
 * case.
 */
object my_player;

void init_curse(object pl) {
  string str, i;

  if (sscanf((str = file_name(this_object())), "%s#%d", str, i) != 2) {
/* A class, not a clone. */
    seteuid((string)"/secure/master"->creator_file(file_name(this_object())));
    clone_object(str)->init_curse(pl);
    return ;
  }
  my_player = pl;
  shadow(pl, 1);
  pl->add_curse(MY_NAME, str);
}

/*
 * No special requirements for removeing this curse...
 */
int query_remove() { return 1; }

/*
 * Called when the player logs on
 */
int player_start() {
  object ob;

  ob = clone_object(HERE+"upper_case");
  ob->init_curse(this_player());
}

/*
 * This gets called with the name of the curse we are getting rid of.
 */
int destruct_curse(string str) {
  if (str == MY_NAME)
    destruct(this_object());
  else
    my_player->destruct_curse(str);
}

int do_echo_all(string str) {
  write("Your voice is to horse to shout.\n");
  return 1;
}

int do_shout(string str) {
  write("Your voice is to horse to shout.\n");
  return 1;
}
