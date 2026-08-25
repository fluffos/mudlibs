#include "path.h"
#define MY_NAME "UPPER CASE"

/*
 * The upper case curse.  Means everything you say comes out in upper
 * case.
 */
object my_player;

void init_curse(object pl) {
  string str;
  int i;

  if (sscanf((str = file_name(this_object())), "%s#%d", str, i) != 2) {
/* A class not a clone */
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
int player_start(object pl) {
  object ob;

  if (!pl)
    pl = this_player();
  ob = clone_object(HERE+"upper_case");
  ob->init_curse(pl);
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

protected upper_case(string str) {
  string ret;
  int i;

  ret = "";
  for (i=0;i<strlen(str);i++)
    ret += capitalize(str[i..i]);
  return ret;
}

int do_say(string str) {
  return (int)my_player->do_say(upper_case(str));
}

int do_tell(string str) {
  return (int)my_player->do_tell(upper_case(str));
}

int do_loud_say(string str) {
  return (int)my_player->do_loud_say(upper_case(str));
}

int do_echo(string str) {
  return (int)my_player->do_echo(upper_case(str));
}

int do_echo_all(string str) {
  return (int)my_player->do_echo_all(upper_case(str));
}

int do_emote(string str) {
  return (int)my_player->do_emote(upper_case(str));
}

int do_whisper(string str) {
  return (int)my_player->do_whisper(upper_case(str));
}

int do_echo_to(string str) {
  return (int)my_player->do_echo_to(upper_case(str));
}

int do_shout(string str) {
  return (int)my_player->do_shout(upper_case(str));
}
