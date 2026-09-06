#include <const.h>
#include <wizard.h>

int is_alpha_before( string s1, string s2 ) {
   return s1 > s2;
}

int main( string param ) {
   object ob;
   string *funcs, buf;

   WIZ_CHECK

   if( !param ) {
      notify_fail("==> [Format] flist obj\n");
      return 0;
   }

   ob = find_thing( param );
   if( !ob ) {
      notify_fail("==> [Error] Can't find '"+param+"'\n");
      return 0;
   }

   funcs = sort_array( functionlist(ob), "is_alpha_before" );

   // Display the buffer
   buf = "~[150Functions in " + object_name(ob) + " (" + ob->query_name() + " / " + ob->query_distant() + ")\n~[100";
   buf += "/inherit/textdraw"->columns( funcs );
   buf += "~[110   " + sizeof(funcs) + " function" + (sizeof(funcs) == 1?"":"s") + " found.\n~CDEF";
   msg_bare( buf );

   return 1;
}