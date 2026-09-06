#define TODO_FILE "/text/todolist"

/// \todo Document this object

string *todo_titles = ({});
string *todo_dates = ({});
string *todo_messages = ({});
string *todo_authors = ({});
string *todo_update =({});

create() {
   restore_object(TODO_FILE);
}

int query_title_size() {
   return (sizeof(todo_titles));
}

string query_title(int x) {
   if( x >= sizeof( todo_titles ) || x < 0 ) return "[Error] query_title("+(string)x+") --> Index out of bounds.";
   return (todo_titles[x]);
}

string query_date(int x) {
   if( x >= sizeof( todo_dates ) || x < 0 ) return "[Error] query_date("+(string)x+") --> Index out of bounds.";
   return (todo_dates[x]);
}

string query_message(int x) {
   if( x >= sizeof( todo_messages ) || x < 0 ) return "[Error] query_message("+(string)x+") --> Index out of bounds.";
   return (todo_messages[x]);
}

string query_author(int x) {
   if( x >= sizeof( todo_authors ) || x < 0 ) return "[Error] query_author("+(string)x+") --> Index out of bounds.";
   return (todo_authors[x]);
}

string query_update(int x) {
   if( x >= sizeof( todo_update ) || x < 0 ) return "[Error] query_update("+(string)x+") --> Index out of bounds.";
   return (todo_update[x]);
}

void add(string title,string message) {
   todo_titles += ({title});
   todo_messages += ({message});
   todo_dates += ({ctime(time())});
   todo_authors += ({(string)this_player()->query_real_name()});
   todo_update += ({(string)this_player()->query_real_name()});
   save_object(TODO_FILE);
}

void delete(int number) {
   todo_titles -= ({todo_titles[number]});
   todo_dates -= ({todo_dates[number]});
   todo_messages -= ({todo_messages[number]});

   // kill author entry, todo_authors -= ({todo_authors[number]}) kills everyone
   todo_authors = todo_authors[0..number-1] + todo_authors[number+1..sizeof(todo_authors)-1];
   todo_update = todo_update[0..number-1] + todo_update[number+1..sizeof(todo_update)-1];

   save_object(TODO_FILE);
}

void set(int number,string message) {
   todo_messages[number] = message;
   todo_dates[number] = ctime(time());
   todo_update[number] = (string)this_player()->query_real_name();
   save_object(TODO_FILE);
}
