#define TP      this_player()
#define TO      this_object()
#define ENV     environment()

string current_title,current_date,current_message;
string user;

string query_user() {
   return user;
}

int main(string title) {
  if (user) {
    msg("==> [Error] " + capitalize(user) + " is busy adding an item. Please wait.");
    return 1;
  }
  if(!title) {
    msg("==> [Format] todoadd title");
    return 1;
  }
  user = TP->query_real_name();
  current_title = title;
  msg("Enter the text of your message. Use ~CCOM**~CDEF or ~CCOM.~CDEF when done or ~CCOM~TILDq~CDEF to abort.");
  current_message = "";
  add_interface("add_todo", "> ");
  call_out( "time_out", 500 );
  return 1;
}

void time_out() {
   debug("todoadd timed out.");
   user = 0;
}

int add_todo(string input) {
  if (user != TP->query_real_name()) {
    msg("==> [Error] Please use the todoadd command directly.");
    return 0;
  }
  remove_call_out( "time_out" );
  if(input != "**" && input != "~q" && input !=".") {
    current_message += input+"\n";
  }
  else if( input == "**" || input == "." ) {
     write("To Do List item added.\n");
     "/obj/todo"->add(current_title,current_message);
     user = 0;
     drop_interface();
     return 1;
  }
  else { // input == "~q"
     write("Aborted.\n");
     current_title = "";
     current_date = "";
     current_message = "";
     user = 0;
     drop_interface();
     return 1;
  }
  call_out( "time_out", 500 );
}
