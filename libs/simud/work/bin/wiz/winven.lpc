#include <wizard.h>
#include <const.h>

int main(string objref) {
   object env, curr;
   object *inv;
   string buf;
   int i, len;
   int names_only;

   WIZ_CHECK

   if( !stringp(objref) ) objref = "me";
   names_only = 0;
   if( objref[<1] == '!' ) {
      names_only = 1;
      objref = objref[..<2];
   }
   env = find_thing( objref );
   if( !env ) {
      notify_fail("==> [Wiz Inventory] Can't find object "+objref+"\n");
      return 0;
   }

   inv = all_inventory(env);
   len = this_player()->query_term_height() - 4;
   if( sizeof(inv) > len ) {
      string *oblist;

      oblist = allocate( sizeof(inv) );
      i = 0;
      foreach( curr: inv ) {
         string name;

         if( names_only )
            name = curr->query_name();
         else
            name = object_name(curr);
         oblist[i++] = name;
      }
      buf = "~CDRK--- Abbreviated listing -------------------------" +
          tab("-", this_player()->query_term_width() - 68) + " ~CTITWiz Inventory ~CDRK--\n~[100";
      buf += "/inherit/textdraw"->columns( oblist );
      objref = "~CTITEnvironment: ~CDEF"+env->query_name()+"~CLAB / ~CDEF"+process_codes(env->query_distant())+" ~CLAB"+object_name(env);
      buf += "~CDRK"+tab("-", this_player()->query_term_width() - strlen(objref) + 19) + " " + objref + " ~CDRK--~CDEF";
   }
   else {
      buf = "~CDRK--- ~CLABName ~CDRK--------- ~CLABDistant ~CDRK----------- ~CLABReference~CDRK " +
          tab("-", this_player()->query_term_width() - 68) + " ~CTITWiz Inventory ~CDRK--\n";
      i = 0;
      foreach( curr: inv )
         buf += "~CDEF" + pad((string)(++i)+".", 4, 2) + pad(curr->query_name(), 15, 0) + pad(process_codes(curr->query_distant()), 20, 0) + object_name(curr) + "\n";
      objref = "~CTITEnvironment: ~CDEF"+env->query_name()+"~CLAB / ~CDEF"+process_codes(env->query_distant())+" ~CLAB"+object_name(env);
      buf += "~CDRK"+tab("-", this_player()->query_term_width() - strlen(objref) + 19) + " " + objref + " ~CDRK--~CDEF";
   }
   msg(buf);

   return 1;
}