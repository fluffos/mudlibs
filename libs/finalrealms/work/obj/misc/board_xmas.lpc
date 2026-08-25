/* A christmas tree, for hanging ornaments on.
 * Very customized board object, Wonderflug, Dec 95
 */
#include "mail.h"
inherit "/std/object";

#include "board.h"

#define MAX_XMAS_POSTS 2

/* Taniwha 1995, a list of immort write only boards, easy to extend */
nosave string *readonly = ({"playerinfo","quests","announcements"});

string board_name;

mapping being_written;
int action_pri;

void setup() {
  set_name("tree");
  set_short("A Huge Christmas Tree");
  set_long("This is a HUGE Christmas tree, towering at least "
    "40 feet in the air.  Christmas candles and popcorn strings and "
    "decorations cover it from top to bottom, and a little "
    "charicature of Baldrick adorns the very top of it.  You have the "
    "sudden urge to 'create' an ornament for it, as many others have done.  "
   "Or just look at all the ornaments (with 'ornaments').  "
    "And maybe 'study' the interesting ones.\n");
  set_main_plural("trees");
  reset_get();
  board_name = "christmas";
  this_object()->set_datafile("christmas");
  being_written = ([ ]);
  action_pri = 0;
} /* setup() */


int subjects(string str, int dark) {
  int i;
  mixed *stuff;
  string ret;
  mapping news_rc;

  stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  if (!sizeof(stuff)) {
    notify_fail("The Christmas tree is bare of ornaments!  It looks "
      "so lonely.\n");
    return 0;
  }
  news_rc = (mapping)this_player()->query_property(NEWS_RC);
  if ( !news_rc )
    news_rc = ([ ]);
  ret = "You see the following ornaments hung on the tree:\n\n";
  for (i=0;i<sizeof(stuff);i++)
    if (news_rc[board_name] < stuff[i][B_TIME])
      ret += (i+1)+".  (New)  A "+stuff[i][B_SUBJECT]+" hung by "+
        capitalize(stuff[i][B_NAME])+"\n";
    else 
      ret += (i+1)+".  A "+stuff[i][B_SUBJECT]+" hung by "+
        capitalize(stuff[i][B_NAME])+"\n";
  this_player()->set_finish_func(0);
  this_player()->more_string(ret);
  return 1;
} /* subjects() */


void init() {
  add_action("read", "study");
  add_action("post", "create");
  add_action("break_orn", "break");
  add_action("subjects", "ornaments");
} /* init() */

void string_more(string arg, string prompt) {
  object obj;
  this_player()->set_finish_func(0);
  this_player()->more_string(arg, prompt);
} /* string_more() */

int read(string str) {
  int num, i;
  mixed stuff;
  mapping news_rc;

  notify_fail("Syntax: study [ornament] <number>\n");

  if ( !str )
    return 0;
  if ( sscanf(str, "%d", num) != 1 && sscanf(str, "ornament %d", num ) != 1 )
    return 0;

  stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  news_rc = (mapping)this_player()->query_property(NEWS_RC);
  if (!news_rc)
    news_rc = ([ ]);
  if (num < 1 || num > sizeof(stuff)) {
    notify_fail("No ornament of that number.\n");
    return 0;
  }
  num --;
  if (news_rc[board_name] < stuff[num][B_TIME]) {
    news_rc[board_name] = stuff[num][B_TIME];
    this_player()->add_property(NEWS_RC, news_rc);
  }
  string_more(sprintf("%s's ornament is a %s that looks like this: \n", 
           capitalize(stuff[num][B_NAME]),
              stuff[num][B_SUBJECT][0..(int)this_player()->query_cols()-10])+
              BOARD_HAND->get_message(board_name, num),
            "["+capitalize(stuff[num][B_NAME])+"'s ornament]");
  return 1;
} /* read() */

int post(string str) {
  string body;
  mixed stuff;
  int i, num_posts;

  num_posts=0;
  stuff = (mixed*)BOARD_HAND->get_subjects(board_name);
  for (i=0;i<sizeof(stuff);i++)
    if ( this_player()->query_name() == stuff[i][B_NAME] )
      num_posts++;

  if ( num_posts >= MAX_XMAS_POSTS )
  {
    notify_fail("You have already hung too many ornaments on the tree!\n");
    return 0;
  }


  notify_fail("Syntax: create a <ornament>\n");
  if ( !str || sscanf(str, "a %s", str) != 1 )
    return 0;

  write("Note that you can only add one ornament to the tree.\n");
  write("Now you need to enter a description for your ornament.\n");
  being_written[this_player()->query_name()] = str;
  this_player()->do_edit(0,"end_of_thing");
  return 1;
} /* post() */

void end_of_thing(string body) {
  if (body && body != "" && being_written[this_player()->query_name()])
    if (!BOARD_HAND->add_message(board_name, this_player()->query_name(),
                            being_written[this_player()->query_name()], body))
      write("Oops you dropped the ornament on the ground, and it broke.\n");
    else
      write("You hang your ornament on the tree.\n");
  else
    write("Error.\n");
  being_written = m_delete(being_written, this_player()->query_name());
  return ;
} /* end_of_thing() */

int break_orn(string str) {
  int num, i, eaten;

  notify_fail("Syntax: break [up to] <ornament number>\n");
  if (!str)
    return 0;
  if (sscanf(str, "up to %d", num)) {
    for (i=0;i<num;i++)
      eaten += (int)BOARD_HAND->delete_message(board_name, i);
    if (!eaten) {
      notify_fail("Failed to break any ornaments.\n");
      return 0;
    }
    write("You broke "+eaten+" ornaments, you grinch!\n");
    say(this_player()->query_cap_name()+" visciously rips off and shatters "+
        query_num(eaten, 0)+" ornaments.\n");
    if (eaten == 1)
      event(users(), "inform", this_player()->query_cap_name()+" eats a note "+
            "off "+board_name, "message");
    else
      event(users(), "inform", this_player()->query_cap_name()+" eats "+
            query_num(eaten, 0)+" notes off "+board_name, "message");
    return 1;
  } else if (sscanf(str, "%d", num) != 1)
    return 0;
  if (!BOARD_HAND->delete_message(board_name, num-1))
    return 0;
  write("You viciously tear off and break ornament "+num+"\n");
  say(this_player()->query_cap_name()+" viciously tears off and eats note "+
         num+".\n");
  event(users(), "inform", this_player()->query_cap_name()+" eats a note "+
                           "off "+board_name, "message");
  return 1;
} /* eat() */

void set_board_name(string str) {
  board_name = str;
  BOARD_HAND->create_board(board_name, 0);
}

void set_datafile(string str) {
  set_board_name(str);
  /*board_name = str;*/
}

int query_new_messages() {
  mixed *notes;
  mapping news_rc;

  news_rc = (mapping)this_player()->query_property(NEWS_RC);
  if (!news_rc)
    news_rc = ([ ]);
  notes = (mixed *)BOARD_HAND->get_subjects(board_name);
  if (!sizeof(notes)) return 0;
  return (notes[sizeof(notes)-1][B_TIME] > news_rc[board_name]);
} /* query_new_messages() */
