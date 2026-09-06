#include <const.h>

int main(string arg) {
   string verb_obj;
   int i, n;
   mixed actions;
   WIZ_CHECK;

   if (!arg) {
     notify_fail("==> [Format] where verb\n");
     return 0;
   }
   if (0 != (verb_obj = this_player()->locate_command(arg))) {
      write(arg+" is implemented in "+comma_list(verb_obj)+".c.\n");
      return 1;
   }
   actions = query_actions(this_player());
   for(i=0,n=sizeof(actions);i<n;i++) {
      if (arg == actions[i]) {
         actions = query_actions(this_player(), 9);
         i*=2;
         write(arg+" is defined in "+object_name(actions[i+1])+"\n");
         return 1;
       }
   }
   write("Can't find anything that implements "+arg+".\n");
   return 1;
}
