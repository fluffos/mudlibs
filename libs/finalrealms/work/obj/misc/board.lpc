#include "mail.h"
inherit "/std/object";

#include "board.h"
/* Taniwha 1995, a list of immort write only boards, easy to extend */
nosave string *readonly = ({"playerinfo","quests","announcements"});

string board_name;

mapping being_written;
#define ACTION_PRI 0

void setup() {
  set_name("board");
  set_short("bulletin board");
  add_adjective("bulletin");
  set_main_plural("boards");
  reset_get();
  board_name = "fish";
  being_written = ([ ]);
} /* setup() */

string query_plural() {
  mixed *stuff;

  stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  switch (sizeof(stuff)) {
    case 0:  return pluralize(::short(0))+" [ Empty ]";
    case 1:  return pluralize(::short(0))+" [ 1 note ]";
  }
   return pluralize(::short(0))+" [ "+sizeof(stuff)+" notes ]";
} /* query_plural() */

string short(int dark) {
  mixed *stuff;

  stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  switch (sizeof(stuff)) {
    case 0:  return ::short(dark)+" [ Empty ]";
    case 1:  return ::short(dark)+" [ 1 note ]";
    default:
      return ::short(dark)+" [ "+sizeof(stuff)+" notes ]";
  }
} /* short() */

string the_date(int i) {
  return ctime(i)[4..9];
} /* the_date() */

int subjects(string str, int dark) {
  int i;
  mixed *stuff;
  string ret;
  mapping news_rc;

  stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  if (!sizeof(stuff)) {
    notify_fail("The board is completely empty.\n");
    return 0;
  }
  news_rc = (mapping)this_player()->query_property(NEWS_RC);
  if (!news_rc)
    news_rc = ([ ]);
  ret = "";
  for (i=0;i<sizeof(stuff);i++)
    if (news_rc[board_name] < stuff[i][B_TIME])
      ret += sprintf("N %2d: %-=*s\n", i+1, (int)this_player()->query_cols()-6,
             stuff[i][B_SUBJECT]+" ("+
             capitalize(stuff[i][B_NAME])+" "+the_date(stuff[i][B_TIME])+")");
    else 
      ret += sprintf("  %2d: %-=*s\n", i+1, (int)this_player()->query_cols()-6,
             stuff[i][B_SUBJECT]+" ("+
             capitalize(stuff[i][B_NAME])+" "+the_date(stuff[i][B_TIME])+")");
  this_player()->set_finish_func(0);
  this_player()->more_string(ret);
  return 1;
} /* subjects() */

string long(string str, int dark) {
  int i,newones;
  mixed *stuff;
  string ret;
  mapping news_rc;

  stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  ret = "A bulletin board ("+board_name+").\n";
  ret += sprintf("%#-*s\n\n", this_player()->query_cols(),
                            "read [note number]\npost <subject>\n"+
                            "subjects\neat <note number>\n"+
                            "reply <note number>\nfollowup <note number>\n");
  if (!sizeof(stuff))
    return ret+"The board is completely empty.\n";
  news_rc = (mapping)this_player()->query_property(NEWS_RC);
  if (!news_rc)
    news_rc = ([ ]);
  newones = 0;
  for (i=0;i<sizeof(stuff);i++)
    if (news_rc[board_name] < stuff[i][B_TIME]) {
      ret += sprintf("N %2d: %-=*s\n", i+1, (int)this_player()->query_cols()-6,
             stuff[i][B_SUBJECT]+" ("+
             capitalize(stuff[i][B_NAME])+" "+the_date(stuff[i][B_TIME])+")");
      newones +=1;
    } else if (news_rc[board_name] < stuff[i][B_TIME]+(2*24*60*60))
      ret += sprintf("  %2d: %-=*s\n", i+1, (int)this_player()->query_cols()-6,
             stuff[i][B_SUBJECT]+" ("+
             capitalize(stuff[i][B_NAME])+" "+the_date(stuff[i][B_TIME])+")");
  if (!newones) 
    ret += "\nNo new messages\n";
  return ret;
} /* long() */

void init() {
   // Removed the * from the next two add_action's - Radix
  add_action("read", "read");
  add_action("post", "post");
  add_action("post", "note"); 
  add_action("eat", "eat");
  add_action("followup", "followup");
  add_action("reply", "reply");
  add_action("subjects", "subjects");
} /* init() */

void string_more(string arg, string prompt) {

  this_player()->set_finish_func(0);
  this_player()->more_string(arg, prompt);
} /* string_more() */

int read(string str) {
  int num, i;
  mixed stuff;
  mapping news_rc;

  notify_fail("Syntax: read <note number>\n");
  stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  news_rc = (mapping)this_player()->query_property(NEWS_RC);
  if (!news_rc)
    news_rc = ([ ]);
  if (!str) {
    i = sizeof(stuff)-1;
    while (i >= 0 &&stuff[i][B_TIME] > news_rc[board_name] )
      i--;
    if (i == sizeof(stuff)-1) {
      notify_fail("No unread messages.\n");
      return 0;
    }
    num = i+2;
  } else if (sscanf(str, "%d", num) != 1)
    return 0;
  if (num < 1 || num > sizeof(stuff)) {
    notify_fail("No note of that number.\n");
    return 0;
  }
  num --;
  if (news_rc[board_name] < stuff[num][B_TIME]) {
    news_rc[board_name] = stuff[num][B_TIME];
    this_player()->add_property(NEWS_RC, news_rc);
  }
  string_more(sprintf("Note #%d by %s posted at %s\nTitle: '%s'\n\n", 
              num+1, capitalize(stuff[num][B_NAME]), ctime(stuff[num][B_TIME]),
              stuff[num][B_SUBJECT][0..(int)this_player()->query_cols()-10])+
              BOARD_HAND->get_message(board_name, num),
                 "[Note "+(num+1)+"]");
  return 1;
} /* read() */

int post(string str) {

   if( (member_array(board_name,readonly) != -1) && !this_player()->query_creator())
   {
   write("Sorry, only immortals may write upon this board.\n");
    return 1;
  }
  notify_fail("Syntax: post <subject>\n");
  if (!str)
    return 0;
/* ok shove the editing stuff in here.  Lets make it function string_edit
 * sound froggy?
 */
  being_written[this_player()->query_name()] = str;
  this_player()->do_edit("","end_of_thing", this_object());
  return 1;
} /* post() */

void end_of_thing(string body) {
  if (body && body != "" && being_written[this_player()->query_name()])
    if (!BOARD_HAND->add_message(board_name, this_player()->query_name(),
                            being_written[this_player()->query_name()], body))
      write("Error writing message.\n");
    else
      write("Message posted.\n");
  else
    write("Error.\n");
  being_written = m_delete(being_written, this_player()->query_name());
  return ;
} /* end_of_thing() */

int eat(string str) {
  int num, i, eaten;

  notify_fail("Syntax: eat [up to] <note number>\n");
  if (!str)
    return 0;
  if (sscanf(str, "up to %d", num)) {
    for (i=0;i<num;i++)
      eaten += (int)BOARD_HAND->delete_message(board_name, i);
    if (!eaten) {
      notify_fail("Failed to eat any notes.\n");
      return 0;
    }
    write("You ate "+eaten+" notes, yum yum.\n");
    say(this_player()->query_cap_name()+" visciously tears off and eats "+
        query_num(eaten, 0)+" notes.\n");
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
  write("You viciously tear off and eat note "+num+"\n");
  say(this_player()->query_cap_name()+" viciously tears off and eats note "+
         num+".\n");
  event(users(), "inform", this_player()->query_cap_name()+" eats a note "+
                           "off "+board_name, "message");
  return 1;
} /* eat() */

int followup(string str) {
  int num, i;
  mixed stuff;
  string s;

  if(board_name=="announcements" && !this_player()->query_creator() )
  {
   write("Sorry, only immortals may write upon this board.\n");
    return 1;
  }
  notify_fail("Syntax: followup <note number>\n");
  if (!str)
    return 0;
  if (sscanf(str, "%d", num) != 1)
    return 0;
  stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  if (num < 1 || num > sizeof(stuff)) {
    notify_fail("No note of that number.\n");
    return 0;
  }
  if (sscanf(stuff[num-1][B_SUBJECT], "Re:#%d %s", i, s) != 2)
    being_written[this_player()->query_name()] = "Re:#1 "+stuff[num-1][B_SUBJECT];
  else
    being_written[this_player()->query_name()] = "Re:#"+i+" "+s;
  this_player()->do_edit(0,"end_of_thing");
  return 1;
} /* followup() */

int reply(string str) {
  int num;
  mixed stuff;

  if(board_name=="announcements" && !this_player()->query_creator() )
  {
  write("Sorry, only immortals may write upon this board.\n");
  return 1;
  }
  notify_fail("Syntax: reply <note number>\n");
  if (!str)
    return 0;
  if (sscanf(str, "%d", num) != 1)
    return 0;
  stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  if (num < 1 || num > sizeof(stuff)) {
    notify_fail("No note of that number.\n");
    return 0;
  }
  MAIL_TRACK->mail(stuff[num-1][B_NAME], stuff[num-1][B_SUBJECT]);
  return 1;
} /* reply() */

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
