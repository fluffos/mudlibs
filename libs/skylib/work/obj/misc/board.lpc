#include <mail.h>
#include <board.h>;

inherit OBJECT_OBJ;

#define DEBUG_ME

string board_name;

// Variables used to temporarily save data re a post to transfer to other uses
// eg in 'close' archive it then transfer to closed board and mail it
private string post_body, post_rec, post_sub, post_time;
private int post_num;
private string post_to;

mapping being_written;
int action_pri;

class info_written {
   string subject;
   int note_num;
}

int do_read_next();
int do_read_new();
int do_read(int num);
int do_close(int num);
int do_close(string str);
int do_followup(int num);
int do_reply(int num);
int do_eat(int num);
int do_post(string str);

void setup() {
   set_name("board");
   set_short("bulletin board");
   add_adjective("bulletin");
   set_main_plural("boards");
   reset_get();
   add_property("there", "mounted on one wall");
   add_property("survive fire", 1);
   board_name = "general";
   being_written = ([ ]);
   action_pri = 0;
} /* setup() */

string query_plural() {
   mixed *stuff;

   stuff = (mixed *)BOARD_H->get_subjects(board_name);
   switch (sizeof(stuff)) {
   case 0:
      return pluralize(::short(0))+" [ Empty ]";
   case 1:
      return pluralize(::short(0))+" [ 1 note ]";
   }
   return pluralize(::short(0))+" [ "+sizeof(stuff)+" notes ]";
} /* query_plural() */

string short(int dark) {
   mixed *stuff;

   stuff = (mixed *)BOARD_H->get_subjects(board_name);
   switch (sizeof(stuff)) {
   case 0:
      return ::short(dark)+" [ Empty ]";
   case 1:
      return ::short(dark)+" [ 1 note ]";
   default:
      return ::short(dark)+" [ "+sizeof(stuff)+" notes ]";
   }
} /* short() */

string the_date(int i) {
   return ctime(i)[4..9];
} /* the_date() */

int do_subjects() {
   int i, size;
   mixed *stuff;
   string ret;
   mapping news_rc;

   stuff = (mixed *)BOARD_H->get_subjects(board_name);
   if (!sizeof(stuff)) {
      add_failed_mess("The board is completely empty.\n");
      return 0;
   }
   news_rc = BOARD_H->query_newsrc(this_player()->query_name());
   if (!news_rc) {
      news_rc = ([ ]);
   }
   ret = "";
   size = sizeof(stuff);
   for (i=0; i < size; i++) {
      if (news_rc[board_name] < stuff[i][B_TIME]) {
         ret += sprintf("N %2d: %-=*s\n", i+1,
                     (int)TP->query_cols()-6,
                     stuff[i][B_SUBJECT]+" ("+
                     stuff[i][B_NAME]+" "+the_date(stuff[i][B_TIME])+")");
     } else {
         ret += sprintf("  %2d: %-=*s\n", i+1,
                     (int)TP->query_cols()-6,
                     stuff[i][B_SUBJECT]+" ("+
                     stuff[i][B_NAME]+" "+the_date(stuff[i][B_TIME])+")");
      }
   }
   TP->set_finish_func(0);
   TP->more_string(ret);
   return 1;
} /* subjects() */

string long(string str, int dark) {
   int i,newones, size;
   mixed *stuff;
   string ret;
   mapping news_rc;

   stuff = (mixed *)BOARD_H->get_subjects(board_name);
   ret = "A bulletin board ("+board_name+").\n";
   ret += sprintf("%#-*s\n\n", TP->query_cols(),
                             "read [note number]\nsubjects\n"+
                      (TP->query_property("guest")?"":
                             "post <subject>\neat <note number>\n"+
                             "reply <note number>\nfollowup <note number>\n"));
   if (!sizeof(stuff))
      return ret+"The board is completely empty.\n";
   news_rc = BOARD_H->query_newsrc(TP->query_name());
   if (!news_rc)
      news_rc = ([ ]);
   newones = 0;
   size = sizeof(stuff);
   for (i = 0; i < size; i++)
      if (news_rc[board_name] < stuff[i][B_TIME]) {
         ret += sprintf("N %2d: %-=*s\n", i+1,
                     (int)TP->query_cols()-6,
                     stuff[i][B_SUBJECT]+" ("+
                     stuff[i][B_NAME]+" "+the_date(stuff[i][B_TIME])+")");
         newones +=1;
      } else if (news_rc[board_name] < stuff[i][B_TIME]+(2*24*60*60))
         ret += sprintf("  %2d: %-=*s\n", i+1,
                     (int)TP->query_cols()-6,
                     stuff[i][B_SUBJECT]+" ("+
                     stuff[i][B_NAME]+" "+the_date(stuff[i][B_TIME])+")");
   if (!newones)
      ret += "\nNo new messages\n";
   return ret;
} /* long() */

void add_commands() {
   add_command("read", "[new]", (: do_read_new :));
   add_command("r", "[new]", (: do_read_new :));
   add_command("read", "<number>", (: do_read($4[0]) :));
   add_command("r", "<number>", (: do_read($4[0]) :));
   add_command("read", "next", (: do_read_next :));

   if( !TP->query_property("guest") ) {
       add_command("post", "<string>", (: do_post($4[0]) :));
       add_command("note", "<string>", (: do_post($4[0]) :));
       add_command("eat", "<number>", (: do_eat($4[0]) :));
       add_command("followup", "<number>", (: do_followup($4[0]) :));
       add_command("reply", "<number>", (: do_reply($4[0]) :));
   }

   if( creatorp(TP) )
       add_command("close", "<number>", (: do_close($4[0]) :));

   add_command("subjects", "");

} /* add_commands() */

void init() {
   if( TP && !present("board master", TP ) )
       add_commands();
} /* init() */

string query_post_to() { return post_to; }

void set_post_to(string val) { post_to = val; }

int do_close(int num){
  int i;
  int m;
  class info_written bing;

  mixed stuff = BOARD_H->get_subjects(board_name);
  string body;
  string s, pname = this_player() -> query_name();
  string close_to;

//  num = args[0];
  body = BOARD_H->get_message(board_name, num-1);

  TP->add_succeeded_mess(TO,"");

  if (num < 1 || num > sizeof(stuff))
    return notify_fail("No note of that number.\n");

  if (sscanf(stuff[num - 1][B_SUBJECT], "Re:#%d %s", i, s) != 2)
    being_written[pname] = "Re:#1 "+ stuff[num - 1][B_SUBJECT];
  else
    being_written[pname] = "Re:#"+ (i + 1) +" "+ s;

  if (body)
  {

// Truncate any signature.
    if ((m = strsrch(body, "\n\n--\n", 0)) != -1)
      body = body[0..m];

// Comment the post out.
    body = "> "+ replace(body, "\n", "\n> ") +"\n\n";
  } else {
    write("Unable to find a body for post "+ query_num(num) +
    ".\n");
    return 1;
  }

  if(!close_to = BOARD_H->query_close(board_name))
  {
    write("Unable to find a board to close to.\n");
    return 1;
  }

// Post copy to 'close board', amending as desired
  set_post_to(close_to);
  post_body = body;
  post_num=num;
  post_rec = stuff[num-1][B_NAME];
  post_sub = "Re : " + stuff[num-1][B_SUBJECT];
  post_time = ctime(stuff[num-1][B_TIME]);
  bing = new(class info_written);
  bing->subject = "Re: "+ stuff[num - 1][B_SUBJECT];
  bing->note_num = stuff[num - 1][B_NUM];
  being_written[(string)this_player()->query_name()] = bing;

  write(body);
  write("\nIs this the note you want to close (Y/N)?");
  input_to("do_close1");
  return 1;
} /* do_close() */

int do_close1(string str){
  if(!str || str ==""){
       write("\nIs this the note you want to close(Y/N)?");
       input_to("close1");
       return 1;
  }
  if(lower_case(str)!="y"){
     write("\nOkay close cancelled.\n");
     post_body = 0;
     post_rec = 0;
     post_sub = 0;
     post_time = 0;
     post_num=0;
     return 1;
  }

  write("\n-----------------------------------\n");
  write("TRANSFERRING COPY TO 'CLOSED' BOARD\n");
  write("ADD COMMENTS AS APPROPRIATE\n\n");
  write("-----------------------------------\n\n");
  this_player() -> do_edit(post_body +
      sprintf("\nRaised by %s %s\n", post_rec, post_time) +
      sprintf("\nClosed by %s %s\n", TP->query_cap_name(), ctime(time())),
      "end_of_close" );

// archive original copy
  BOARD_H->zap_message(board_name, post_num-1);

  return 1;
} /* do_close1() */

void end_of_close(string str)
{
  string body;
  TO->end_of_thing(str);

  body = post_body + sprintf("\nFixed by %s %s\n", TP->query_cap_name(), ctime(time()));
  post_body = body;
// mail copy to original bug reporter, saying 'fixed'
  write("\n----------------------------\n");
  write("MAILING COPY TO ORIGINATOR\n");
  write("ADD COMMENTS AS APPROPRIATE\n");
  write("----------------------------\n");

  this_player() -> do_edit(body,"end_of_mail_close" );

} /* end_of_close() */

void end_of_mail_close(string str){

  if(!str)
     str = post_body;

  MAIL_H->do_mail_message(post_rec, TP->query_name() , post_sub, 0,
                     str);

  post_body = 0;
  post_rec = 0;
  post_sub = 0;
  post_time = 0;
  post_num=0;
} /* mail_close() */

void mark_mine(mixed *stuff, mapping news_rc) {
   int i;
   string their_name;

   i = sizeof(stuff)-1;
   their_name = this_player()->query_name();
   while (i > 0 && stuff[i][B_TIME] > news_rc[board_name])
      i--;
   while ((i+1) < sizeof(stuff) && lower_case(stuff[i+1][B_NAME]) == their_name)
      i++;
   if (i >= sizeof(stuff)) {
      news_rc[board_name] = stuff[sizeof(stuff)-1][B_TIME];
      return;
   }
   if (news_rc[board_name] > stuff[i][B_TIME])
      return;
   news_rc[board_name] = stuff[i][B_TIME];
} /* mark_mine() */


int do_read_next()  {
   mapping  news_rc;
   mixed   *stuff;
   string   their_name, sub, next_sub;
   int      num, last_time;

   news_rc = BOARD_H->query_newsrc(this_player()->query_name());
   if (undefinedp(news_rc["last board"])  ||
       news_rc["last board"] != board_name)
   {
      add_failed_mess("You have not read a note on this board yet!\n");
      return 0;
   }

   stuff = BOARD_H->get_subjects(board_name);
   num = sizeof(stuff);
   their_name = this_player()->query_name();

write("last time: " + ctime(news_rc["last time"]) + "\n");
   last_time = news_rc["last time"];
   while (num  &&  stuff[num - 1][B_TIME] > last_time)  {
      num--;
   }

   sub = news_rc["last sub"];
   sscanf(sub, "Re:#%*d %s", sub);

   for (++num; num <= sizeof(stuff); num++)  {
      next_sub = stuff[num - 1][B_SUBJECT];
      sscanf(next_sub, "Re:#%*d %s", next_sub);
      if (next_sub == sub)  {
         return do_read(num);
      }
   }

   add_failed_mess("No further notes in the thread \"" + sub + "\".\n");
   return 0;
} /* do_read_next() */


int do_read_new() {
   int num;
   string their_name;
   mapping news_rc;
   mixed *stuff;

   news_rc = BOARD_H->query_newsrc(this_player()->query_name());
   if (!news_rc) {
      news_rc = ([ ]);
   }
   stuff = (mixed *)BOARD_H->get_subjects(board_name);
   num = sizeof(stuff);
   their_name = (string)this_player()->query_name();
   while(num && (stuff[num - 1][B_TIME] > news_rc[board_name])) {
      num--;
   }
   while ((num < sizeof(stuff)) &&
          (lower_case(stuff[num][B_NAME]) == their_name)) {
      num++;
   }
   if (num == sizeof(stuff)) {
      add_failed_mess("No unread messages.\n");
      return 0;
   }
   num++;
   return do_read(num);
} /* do_read_new() */

int do_read(int num) {
   mapping news_rc;
   mixed *stuff;

   news_rc = BOARD_H->query_newsrc(this_player()->query_name());
   if (!news_rc) {
      news_rc = ([ ]);
   }
   stuff = (mixed *)BOARD_H->get_subjects(board_name);
   if (num < 0) {
      num = sizeof(stuff) + num + 1;
   }
   if (num < 1 || (num > sizeof(stuff))) {
      add_failed_mess("No note of that number.\n");
      return 0;
   }
   num--;
   news_rc["last board"] = board_name;
   news_rc["last time"] = stuff[num][B_TIME];
   news_rc["last sub"] = stuff[num][B_SUBJECT];
   if (news_rc[board_name] < stuff[num][B_TIME]) {
      news_rc[board_name] = stuff[num][B_TIME];
   }
   BOARD_H->set_newsrc(this_player()->query_name(), news_rc);

   this_player()->more_string(sprintf("%s\nNote #%d by %s posted at %s%s\nTitle: "
                                     "\"%s\"\n\n%s",
                                     "%^BOLD%^",
                                     (num + 1),
                                     stuff[num][B_NAME],
                                     ctime(stuff[num][B_TIME]),
                                     "%^RESET%^",
                                     stuff[num]
                                     [B_SUBJECT][0..(int)this_player()->
                                                 query_cols() - 10],
                                     (string)BOARD_H->
                                       get_message(board_name, num)),
                             "[Note "+ (num + 1) +"]");
   //add_succeeded_mess(({ "", "$N $V a note.\n" }), ({ }));
   add_succeeded_mess("", ({ }));

   return 1;
} /* do_read() */

int do_post(string str) {
   class info_written bing;

   if (board_name=="announcements" && !creatorp(TP)) {
      add_failed_mess("Sorry. You can't post messages here.  "
            "It's for announcements "
            "from the creators only.  If you have a comment or flame, try "
            "the 'flame' board or the 'frog' board.  Bing\n");
      return 0;
   }
   if (!str) {
      return 0;
   }
   /*
    * ok shove the editing stuff in here.  Lets make it function string_edit
    * sound froggy?
    */
   /*
    string_edit("");
    body = string_edit_res;
    */
   if (!BOARD_H->test_can_write(board_name,
                                   this_object(),
                                   this_player()->query_name())) {
      add_failed_mess("You cannot write to this board.\n");
      return 0;
   }
   bing = new(class info_written);
   bing->subject = str;
   bing->note_num = 0;
   being_written[this_player()->query_name()] = bing;
   this_player()->do_edit(0, "end_of_thing");
   add_succeeded_mess(({ "", "$N looks like $r is "
                                        "contemplating a note.\n" }), ({ }) );
   return 1;
} /* do_post() */

void end_of_thing(string body) {
  class info_written bing;

  if(!post_to)
      post_to = board_name;
  if (body && body != "" &&
      being_written[this_player()->query_name()]) {
    if(board_name != "announcements")
      body = sprintf( "%-=78s", body ) + this_player()->append_signature();

    bing = (class info_written)being_written[ this_player()->query_name() ];
    if ( !BOARD_H->add_message( post_to,
         capitalize( (string)this_player()->query_name() ),
         bing->subject,
         body,
         bing->note_num ) ) {
      printf( "Error writing message.\n" );
    } else {
      printf("Message posted.\n");
    }
  } else {
    printf( "No message posted.\n" );
  }
  map_delete(being_written, this_player()->query_name());
  post_to = 0;
  return ;
} /* end_of_thing() */

int do_eat(int num) {
   object *users;

   if( !BOARD_H->delete_message( board_name, num - 1 ) ) {
       add_failed_mess("Failed to eat note.\n");
       return 0;
   }

   printf("You viciously tear off and eat note %d.\n", num );

   say( (string)TP->one_short()+" viciously tears off and eats note "+
        num +".\n");

   users = filter( users(), (:
           BOARD_H->test_can_read( board_name, TO, $1->query_name() ) :) );
   event( users, "inform", (string)TP->query_cap_name() +
        " eats a note off "+ board_name, "message", TP );
   return 1;

} /* eat() */

int do_followup(int num) {
   int i;
   mixed stuff;
   string s;
   class info_written bing;

   stuff = (mixed *)BOARD_H->get_subjects(board_name);
   if (num < 1 || num > sizeof(stuff)) {
      add_failed_mess("No note of that number.\n", ({ }));
      return 0;
   }

   /*
    * If there is a reply type, means we do something other than
    * post to this board.
    */
   if (!stuff[num - 1][B_REPLY_TYPE] &&
       !BOARD_H->test_can_write( board_name, TO, TP->query_name() ) ) {
       add_failed_mess("You cannot followup to this board.\n", ({ }));
       return 0;
   }

   bing = new(class info_written);
   if (sscanf(stuff[num - 1][B_SUBJECT], "Re:#%d %s", i, s) != 2) {
      bing->subject = "Re:#1 "+ stuff[num - 1][B_SUBJECT];
   } else {
      bing->subject = "Re:#"+ ( i + 1 ) +" "+ s;
   }
   bing->note_num = stuff[num - 1][B_NUM];
   being_written[(string)this_player()->query_name()] = bing;
   printf("Include original post? (y/[n]) ");
   input_to("include_post", 0, num - 1, stuff[num - 1]);
   add_succeeded_mess(({ "", "$N looks like $r is "
                                        "contemplating a note.\n" }), ({ }) );
   return 1;
} /* do_followup() */

void include_post(string str, int num, mixed *stuff) {
  if (!str || str == ""  || lower_case(str)[0] != 'y') {
    printf("No.\n");
    this_player()->do_edit(0, "end_of_thing");
    return;
  }

  if (this_player()->query_name() == "macchirton") {
    printf("No including notes for pointless and repeated abuse.\n");
    this_player()->do_edit(0, "end_of_thing");
    return;
  }

  this_player()->
    do_edit("On " + ctime(stuff[B_TIME]) + ", " + stuff[B_NAME] +
            " wrote:\n> " +
            replace_string(BOARD_H->get_message(board_name, num),
                                  "\n", "\n> ") + "\n", "end_of_thing");
} /* include_post() */

int do_reply(int num) {
   mixed stuff;

   stuff = (mixed *)BOARD_H->get_subjects(board_name);
   if (num < 1 || num > sizeof(stuff)) {
      add_failed_mess("No note of that number.\n", ({ }));
      return 0;
   }
   MAIL_TRACK->mail(stuff[num-1][B_NAME], stuff[num-1][B_SUBJECT]);
   add_succeeded_mess(({ "", "$N looks like $r is "
                                        "contemplating a note.\n" }), ({ }) );
   return 1;
} /* reply() */

void set_board_name(string str) { board_name = str; }
void set_datafile(string str) { board_name = str; }

int query_new_messages() {
   mixed *notes;
   mapping news_rc;

   news_rc = BOARD_H->query_newsrc(this_player()->query_name());
   if (!news_rc)
      news_rc = ([ ]);
   notes = (mixed *)BOARD_H->get_subjects(board_name);
   if (!sizeof(notes))
      return 0;
   return (notes[sizeof(notes)-1][B_TIME] > news_rc[board_name]);
} /* query_new_messages() */
