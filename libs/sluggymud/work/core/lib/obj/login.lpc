#include <globals.h>

// needs fixed to handle passwords

#ifdef __INTERACTIVE_CATCH_TELL__
void catch_tell(string str) 
{
    receive(str);
}
#endif

void logon()
{
    object user;
    
#ifdef __NO_ADD_ACTION__
    set_this_player(this_object());
#endif
    write("Welcome to " + MUD_NAME +"!\n" + mudlib_name() + "  Ver " + mudlib_ver() +"\n");
    cat(WELCOME_TEXT_FILE);
    write("\n> ");
#ifdef __PACKAGE_UIDS__
    seteuid(getuid(this_object()));
#endif
    user= new(USER_OBJ);
    user->set_name("stuf" + getoid(user));
    exec(user, this_object());
    user->setup();
#ifndef __NO_ENVIRONMENT__
    user->move(VOID_OBJ);
#endif
    destruct(this_object());
}
