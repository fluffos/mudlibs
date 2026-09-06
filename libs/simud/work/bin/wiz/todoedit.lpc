#define TP      this_player()
#define TO      this_object()
#define ENV     environment()

int editing=0;
string current_message,current_date,current_title;
string user;

int main(string input) {
  int number;
  if (!input) {
    notify_fail("==> [Format] todoedit number (between 1 and "+(string)"/obj/todo"->query_title_size()+")\n");
    return 0;
  }
  number = to_int(input);
  if (number <= 0 || number > "/obj/todo"->query_title_size()) {
    notify_fail("==> [Format] todoedit number (between 1 and "+(string)"/obj/todo"->query_title_size()+")\n");
    return 0;
  }
  if (user) {
    notify_fail("==> [Error] " + capitalize(user) + " is busy editing item " + (string)editing + ". Please wait.\n");
    return 0;
  }
  user = TP->query_real_name();
  msg("Enter the text of your message. Use ** or . when done or ~q to abort.");
  editing = number - 1;
  msg_bare("Editing To Do List item: \"~CCOM"+"/obj/todo"->query_title(editing)+"~CDEF\".\n"
        "Enter '~CCOMr~CDEF' to replace message, '~CCOMa~CDEF' to append to message, or '~CCOMq~CDEF' to exit.\n");
  add_interface("update_todo", "> ");
  call_out( "time_out", 500 );
  return 1;
}

int update_todo(string input) {
  if (user!=TP->query_real_name()) {
    write("[Error] "+capitalize(user)+" is already editing the list.\n");
    return 0;
  }
//  drop_interface();
  if(input == "r") {
    current_message = "";
    msg_bare("Replacing message. Enter the text of your message. Use ~CCOM**~CDEF or ~CCOM.~CDEF when done or ~CCOM~TILDq~CDEF to abort.\n");
    shift_interface("replace_message", "> ");
    return 1;
  }
  if(input == "a") {
    current_message = "/obj/todo"->query_message(editing);
    msg_bare("Appending to message. Enter the text of your message. Use ~CCOM**~CDEF or ~CCOM.~CDEF when done or ~CCOM~TILDq~CDEF to abort.\n");
    shift_interface("append_message", "> ");
    return 1;
  }
  editing = 0;
  user = 0;
  write("Aborted.\n");
  drop_interface();
  return 1;
}

int replace_message(string input) {
  remove_call_out( "time_out" );
  if (input != "**" && input != "." && input != "~q") {
    current_message += input + "\n";
    call_out("time_out",500);
  } else if(input == "**" || input == ".") {
    "/obj/todo"->set(editing,current_message);
    current_message = "";
    editing = 0;
    write("Message replaced.\n");
    user = 0;
    drop_interface();
    return 1;
  } else { // input == "~q"
    current_message = "";
    editing = 0;
    write("Aborted.\n");
    user = 0;
    drop_interface();
    return 1;
  }
}

int append_message(string input) {
  remove_call_out( "time_out" );
  if (input != "**" && input != "." && input != "~q") {
    current_message += input + "\n";
    call_out("time_out",500);
  } else if(input == "**" || input == ".") {
    "/obj/todo"->set(editing,current_message);
    current_message = "";
    editing = 0;
    write("Message updated.\n");
    user = 0;
    drop_interface();
    return 1;
  } else { // input == "~q"
    current_message = "";
    editing = 0;
    write("Aborted.\n");
    user = 0;
    drop_interface();
    return 1;
  }
}

string query_user() {
   return user;
}

void time_out() {
   debug("todoedit timed out.");
   user = 0;
}
