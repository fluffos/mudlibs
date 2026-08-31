
#include <std.h>                

inherit DAEMON;               

int cmd_functions(mixed target) {                                 
     string *my_func=({});                          
     mapping holdings=([]);                           
     string *my_parents=({});                             
     string parent,my_option;
     string pre,post;
        int counter,index;                          

    if(stringp(target)) {                         
         if(!sscanf(target,"%s %s",target,my_option)) my_option = "file";
        if(!target=get_object(target))
            return notify_fail("The system can not locate the object..."); }


    if(!objectp(target)) return notify_fail("This command requires an object's
ID to function...");

    my_func=sort_array(functions(target),-1);
    counter=sizeof(my_func);
    while(counter--) {
           parent=function_exists(my_func[counter],target);
           if(!holdings[parent]) holdings[parent]=({});
           if(member_array( my_func[counter] , holdings[parent] ) < 0)
           holdings[parent] +=({ my_func[counter] }); }

     if(my_option=="file") {
             parent=sscanf(file_name(target),"%s#%s",pre,post) ? pre : file_name(target) ;
              write("The functions present in the object's file ,%^BLACK%^%^BOLD%^"+parent+".c ,%^RESET%^ are as follows;\n");
              write(format_page(holdings[parent])); }

    if(archp(this_player()) && my_option=="all") {
         my_parents=keys(holdings);
         counter=sizeof(my_parents);
         while(counter--) {
              write("%^CYAN%^%^BOLD%^"+my_parents[counter]+" %^GREEN%^define the following functions for the object; ");
              write(format_page(sort_array(holdings[my_parents[counter]],1))); }}

    return 1; }

void help() {
     write("\n%^RED%^%^BOLD%^Syntax :: %^CYAN%^functions (object) "+ (archp(this_player()) ? "(all)" : "")+"%^RESET%^\n");
     write("This command will report the functions that are defined in the");
     write("object specified.\n");
      write("\n\nArchwizards may use the optional all selection to report ALL functions defined in the object.\n\n"); }

