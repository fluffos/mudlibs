//quit.c

//Tacitus @ LPUniversity
//06-APR-05
//User command

//Last edited on October 8th, 2005 by Tacitus

#include <logs.h>
#include <config.h>

int main(string arg)
{
     previous_object()->exit_world();
     write("%^BOLD%^YELLOW%^Thank you for visiting " + mud_name() + "%^RESET%^\n");
     previous_object()->save_user();
     log_file(LOG_LOGIN, capitalize(previous_object()->query_name()) + " logged out from " +
     query_ip_number(previous_object()) + " on " + ctime(time()) + "\n");
     destruct(previous_object());
     return 1;
}

string help()
{
     return(HIW + " SYNTAX:" + NOR + " quit\n\n" +
     "This command will save your characher and disconnect you from the mud.\n\n" +
     HIW + "See also: " + NOR + "save\n");
}
