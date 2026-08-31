
#include <std.h>                

inherit DAEMON;               

int cmd_functions(mixed target) {                                 
     string *my_func=({});                          
     mapping holdings=([]);                           
     string *my_parents=({});                             
     string parent,my_option;
     string pre,post;
    string out = "";
        int counter,index;                          

    if(stringp(target)) {                         
         if(!sscanf(target,"%s %s",target,my_option)) my_option = "file";
        if(!target=get_object(target))
            return notify_fail("Cannot find: "+target+"\n"); }


    if(!objectp(target)) return notify_fail("Search what object?\n");

    my_func=sort_array(functions(target),-1);
    counter=sizeof(my_func);
    while(counter--) {
           parent=function_exists(my_func[counter],target);
           if(!holdings[parent]) holdings[parent]=({});
           if(member_array( my_func[counter] , holdings[parent] ) < 0)
           holdings[parent] +=({ my_func[counter] }); }

     if(my_option=="file") {
             parent=sscanf(file_name(target),"%s#%s",pre,post) ? pre : file_name(target) ;
              write("Functions in %^BOLD%^%^BLACK%^"+parent+"%^RESET%^.c:");
              write(format_page(holdings[parent])); }

    if(archp(this_player()) && my_option=="all") {
         my_parents=keys(holdings);
         counter=sizeof(my_parents);
         while(counter--) {
              out += "%^CYAN%^%^BOLD%^"+my_parents[counter]+" %^GREEN%^define these functions for the object:\n";
              out += format_page(sort_array(holdings[my_parents[counter]],1))+"\n"; }}

    if (strlen(out)) this_player()->more(explode(out, "\n"));

    return 1; }

void help() {
  message("help",
    "Syntax: functions <object>"+( (this_player() && archp(this_player())) ? " [all]" : "")+"\n\n"
    "This command lists the functions defined in <object>.\n"
    +( (this_player() && archp(this_player())) ? "Arches can use the 'all' option to list all functions in all inherited objects." : ""),
    this_player() );
}

