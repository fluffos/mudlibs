// by fire on Jan 8 1998
// study.c 
#include <mudlib.h>
string short();
mixed study_action;
void set_study_action(mixed action) {
    study_action = action;
}
mixed direct_study_obj() {
    return 1;
}
void study_it() {
    mixed action;
    this_body()->simple_action("$N专心地研究了一会儿"+short()+"。\n");    
        action = study_action;
    if (stringp(action))
        write(action);
    else
        evaluate(action);
        
}
