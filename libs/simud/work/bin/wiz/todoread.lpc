#define TP      this_player()
#define TO      this_object()
#define ENV     environment()

int main(string input) {
  string output;
  int item,number;
  if(!input) {
    notify_fail("==> [Format] todoread item#\n");
    return 0;
  }
  number = to_int(input);
  item = number - 1;
  output  ="\n";
  output +="~CLAB  Item No~CDEF:     "+number+"\n";
  output +="~CLAB    Title~CDEF:     "+"/obj/todo"->query_title(item)+"\n";
  output +="~CLAB   Author~CDEF:     "+capitalize("/obj/todo"->query_author(item))+"\n";
  if ("/obj/todo"->query_update(item)!="/obj/todo"->query_author(item))
    output +="~CLABUpdate By~CDEF:     "+capitalize("/obj/todo"->query_update(item))+"\n";
  output +="~CLABDate/Time~CDEF:     "+"/obj/todo"->query_date(item)+"\n\n";
  output +=sprintf("%-70s\n","/obj/todo"->query_message(item));
  msg(output);
  return 1;
}
