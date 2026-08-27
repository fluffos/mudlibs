/*  source file -- book object */

/* Original version written by Virtual */
/* Current version written by Vhaeraun */

#define MAX_PG 10

  /* inheritance */
inherit "/std/object"; 

  /* global variables */
int cur_pg;                 /* current page of book or zero if closed */
int max_pg;                      /* number of pages contained in book */
string page_file;           /* path name of pages WITHOUT page number */
string log_file;               /* path name where comments are logged */

  /* function definitions */
void setup() {
  set_name("book");
  add_alias("book");
  set_long("This is a thick and exclusive looking book bound in "+
    "dark blue velvet.  In it there are maps over the realm.  "+
    "It looks very expensive.  If you decide to keep it and read it "+
    "you might want to open it to be able to look at the maps.\n");
  set_weight(10);                                    /* about a pound */
  set_value(50);                              /* about 50 gold pieces */
  cur_pg = 0;             /* the book is initially closed when loaded */
  max_pg = MAX_PG;        /* only pages 1 to max_pg exist in the book */
}

string query_log_file() { return log_file; }
void set_log_file(string file_name) { log_file = file_name; }

string query_page_file() { return page_file; }
void set_page_file(string file_name) { page_file = file_name; }

void init() {
  ::init();
  add_action ("open","open");                        /* open the book */
  add_action ("close","close");                     /* close the book */
  add_action ("page","page");               /* turn to specified page */
  add_action ("next","next");                    /* turn to next page */
  add_action ("prev","prev");                /* turn to previous page */
  add_action ("comment","comment");      /* store comments about book */
}

int open(string str) {
  if ( str == "book" && !cur_pg ) {                /* is book closed? */
    tell_room(environment(this_player()),
      "You see "+ capitalize((string)this_player()->query_name())+    
      " open a book bound in dark blue velvet.\n",this_player());
    write("You open the magnificent atlas.\n");
    cur_pg = 1;                       /* open book to page one and... */
    cat(page_file + "1");                         /* print first page */
    return 1;
  }
  if ( str == "book" && cur_pg ) {           /* is book already open? */
    tell_room(environment(this_player()),
      "You see " + capitalize((string)this_player()->query_name())+
      " trying hard to open an already open book and naturaly "+
      "he makes a fool out of himself.\n",this_player());
    write("The book is already open on page " + cur_pg +".\n");
    return 1;
  }
  return 0;
}

int close(string str) {
  if ( str == "book" && cur_pg ) {              /* is the book open? */
    tell_room(environment(this_player()),
      "You see "+ capitalize((string)this_player()->query_name())+    
      " close a book bound in dark blue velvet.\n",this_player());
    write("You close the magnificent atlas.\n");
    cur_pg = 0;                                 /* book is now closed */
    return 1;
  }
  if ( str == "book" && !cur_pg ) {    /* is the book already closed? */
    tell_room(environment(this_player()),
      "You see "+ capitalize((string)this_player()->query_name())+    
      " making a fool out of himself trying to close an already "+
      "closed book.\n",this_player());
    write("The book is already closed\n");
    return 1;
  }
  return 0;
}

int next() {
  int tmp_pg;

  if ( !cur_pg ) {                             /* is the book closed? */
    notify_fail("The book is closed.  Open the book to turn a page.\n");
    return 0;
  }
  tmp_pg = cur_pg + 1;                          /* look for next page */
  if ( tmp_pg < max_pg ) {                     /* is next page valid? */
    tell_room(environment(this_player()),
      capitalize((string)this_player()->query_name())+
      " turns a page in a truely magnificent book.\n", this_player());
    cur_pg = tmp_pg;                           /* update current page */
    cat(page_file + tmp_pg);                            /* print page */
    return 1;
  }
  notify_fail("That page does not exist.\n");
  return 0;
}

int prev() {
  int tmp_pg;

  if ( !cur_pg ) {                                 /* is book closed? */
    notify_fail("The book is closed.  Open the book to turn a page.\n");
    return 0;
  }
  tmp_pg = cur_pg - 1;                      /* look for previous page */
  if ( tmp_pg > 0 ) {                      /* is previous page valid? */
    tell_room(environment(this_player()),
      capitalize((string)this_player()->query_name())+
      " turns a page in a truely magnificent book.\n", this_player());
    cur_pg = tmp_pg;                           /* update current page */
    cat(page_file + tmp_pg);                        /* print the page */
    return 1;
  }
  notify_fail("That page does not exist.\n");
  return 0;
}

int page(string str) {
  int tmp_pg;

  if (!str || str == "") {
    notify_fail("To turn to a page, type 'page <number>'.\n");
    return 0;
  }
  sscanf(str, "%d", tmp_pg);         /* convert string to page number */
  if ( tmp_pg > 0 && tmp_pg < max_pg ) {     /* is page number valid? */
    tell_room(environment(this_player()),
      capitalize((string)this_player()->query_name())+
      " turns a page in a truely magnificent book.\n", this_player());
     cur_pg = tmp_pg;                          /* Updates currentpage */
     cat(page_file + tmp_pg);                       /* print the page */
     return 1;
  }
  notify_fail("That page does not exist.\n");
  return 0;
}

int comment(string str) {
  if ( !str ) {                                /* is there a comment? */
    notify_fail("To give your comments, type 'comment <your "+
      "comment>'.\n");
    return 0;
  }
  write_file(log_file, "\nLogged by "+ this_player()->query_cap_name()+
    " on "+ ctime(time()) +" :\n");      /* log name and date then... */
  write_file(log_file, str+"\n");                  /* log the comment */
  write ("Comment saved.\n");
  return 1;
}

