#define TP      this_player()
#define TO      this_object()
#define ENV     environment()

int main() {
   string output;
   int count, items, q;

   items = "/obj/todo"->query_title_size();
   output  = "\n~CBRT--==[ To Do List ]==--\n";
   output += "~CCOMtodo            ~CDEFShows all items on list\n";
   output += "~CCOMtodoread ~CBRT<#>    ~CDEFRead item number #\n";
   output += "~CCOMtodoadd ~CBRT<title> ~CDEFAdd item to list\n";
   output += "~CCOMtododel ~CBRT<#>     ~CDEFRemoves item number #\n";
   output += "~CCOMtodoedit ~CBRT<#>    ~CDEFEdits item number #\n\n";
   if("/bin/wiz/todoadd"->query_user())
     output += capitalize("/bin/wiz/todoadd"->query_user())+" is currently adding to the list.\n";
   if("/bin/wiz/todoedit"->query_user())
     output += capitalize("/bin/wiz/todoedit"->query_user())+" is currently updating the list.\n";
   if( items < 1 ) {
     output += "The list is empty\n";
   }
   else {
      output += "There are "+items+" items on the To Do List.\n";
      output += sprintf("\n~[127%-2s  %-"+(this_player()->query_term_width()-41)+"s  %-10s  %-10s  %-10s~CDEF\n","#","Title","Author","Date","Update");
      for(count = 0; count < items; count++) {
         q = count + 1;
         output += sprintf("~CCOM%-2s  ~CBRT%s  ~CCOM%s ",
           as_string(q), pad("/obj/todo"->query_title(count),this_player()->query_term_width()-41,0),
           pad(capitalize("/obj/todo"->query_author(count)), 11, 0));
         if (pad("/obj/todo"->query_date(count),10,0) ==
             pad(ctime(time()),10,0))
           output += "~CBRT";
         else
           output += "~CDEF";
         output += pad("/obj/todo"->query_date(count),10,0)+"~CDEF";
         if ("/obj/todo"->query_update(count) != "obj/todo"->query_author(count))
           output += sprintf("  %-10s\n",capitalize("/obj/todo"->query_update(count)));
         else
           output += "\n";
      }
   }
   msg_bare(output);
   return 1;
}
