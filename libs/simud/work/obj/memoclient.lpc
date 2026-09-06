// this is the memo client, see /bin/memo.c for more details
// allaryin - 5/6/03

mapping memo;
string current_memo, current_title;

void show_list() {
  string title, body, buf, junk;
  int length = 10;
  if (!sizeof(memo)) {
    msg("You haven't written any memos yet.\n"+
        "Type ~CCOMmemo help~CDEF for a list of options.");
    return;
  }
  buf = "~CTITMemo List:\n";
  foreach (title : memo)
    if( strlen(title) > length )
       length = strlen(title);
  foreach (title, body : memo) {
    sscanf(body,"%s\n%s",body,junk);
    buf += "~CCOM"+pad(title,length,0)+"  ~CDEF"+
           pad(body,this_player()->query_term_width()-length-5,0)+"\n";
  }
  buf += "Total: "+sizeof(memo)+"\n"+
         "Type ~CCOMmemo help~CDEF for a list of options.";
  msg(buf);
  destruct(this_object());
}

void new_memo(string title) {
  msg("Creating new memo entry '"+title+"'.");
  msg("Use ~CCOM**~CDEF or ~CCOM.~CDEF when done or ~CCOM~TILDq~CDEF to abort.");
  current_title = title;
  current_memo = "";
  call_out("time_out", 500);
  add_interface("add_memo", "> ");
}

void time_out() {
  msg("Memo entry timed out, note '"+current_title+"' not added.");
  destruct(this_object());
}

void add_memo(string input) {
  remove_call_out("time_out");
  if (input != "**" && input != "~q" && input !=".") {
     current_memo += input+"\n";
  }
  else if (input == "**" || input == ".") {
     write("Memo '"+current_title+"' added.\n");
     memo += ([ current_title : current_memo ]);
     this_player()->set_memo(memo);
     drop_interface();
     destruct(this_object());
  }
  else { // input == "~q"
     write("Memo aborted.\n");
     current_title = "";
     current_memo = "";
     drop_interface();
     destruct(this_object());
  }
  call_out("time_out", 500);
}

void del_memo(string title) {
  if (!title) {
    msg("You must specify which note to delete.");
    return;
  } else if (!sizeof(memo) || !member(memo,title)) {
    msg("I can't find any note entitled '"+title+"'.");
    return;
  }
  msg("Deleting old memo entry '"+title+"'.");
  memo -= ([ title ]);
  destruct(this_object());
}

void show_memo(string title) {
  if (!title) {
    msg("You must specify which note to show.");
    return;
  } else if (!sizeof(memo) || !member(memo,title)) {
    msg("I can't find any note entitled '"+title+"'.");
    return;
  }
  msg("Displaying memo entry '~CTIT"+title+"~CDEF'.");
  msg(memo[title]);
  destruct(this_object());
}

void show_help() {
  string buf;
  buf = "~CTITSIMud Memo System v2 Help\n";
  buf += "  ~CREFshow <name>~CDEF  show the text of a memo\n";
  buf += "  ~CREFadd <name>~CDEF   adds a new memo\n";
  buf += "  ~CREFdel <name>~CDEF   delete a memo\n";
  buf += "  ~CREFlist~CDEF         list all memos\n";
  buf += "  ~CREFhelp~CDEF         show this help\n\n";
  buf += "See ~CCOMhelp memo~CDEF for even more details";
  msg(buf);
  destruct(this_object());
}

void domemo(object who, string str) {
  string command, arg;
  move_object(this_object(),who);
  memo = who->query_memo();
  if (!mappingp(memo))
    memo = ([]);

  if (!str)
    show_list();
  else {
    if (sscanf(str,"%s %s",command,arg) != 2)
      command = str;
    switch (command) {
      case "show": show_memo(arg); break;
      case "add": new_memo(arg); break;
      case "del": del_memo(arg); break;
      case "help": show_help(); break;
      case "list":
      default: show_list(); break;
    }
  }
}
