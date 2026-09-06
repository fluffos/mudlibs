#define TP      this_player()
#define TO      this_object()
#define ENV     environment()

int main(string input) {
   int q;
   int number;
   number = to_int(input);
   if(!number) {
      notify_fail("==> [Format] tododel item#\n");
      return 0;
   }
   if(number > "obj/todo"->query_title_size() || number <= 0) {
      notify_fail("That number is not valid.\n");
      return 0;
   }
   q = number - 1;
   "/obj/todo"->delete(q);
   write("To Do Item number "+number+" deleted.\n");
   return 1;
}
