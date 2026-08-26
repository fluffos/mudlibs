/* log.c

 Tacitus @ LPUniversity
 14-JUL-06
 Log Viewer
 
 - Originaly coded by Gwegster @ LPUniversity
*/
 
/* Lasted updated on 14-JUL-06 by Tacitus */

int main(string arg)
{
     string logfile;
     
     if(!arg)
     {
          if(file_exists("/log/compile")) logfile = "/log/compile";
          if(file_exists(user_path(query_privs(this_player())) + "log")) 
               logfile = user_path(query_privs(this_player())) + "log";
     }
     else
     {
          if(file_exists("/log/" + arg)) logfile = "/log/" + arg;
          else return(notify_fail("Error [log]: Logfile '/log/" + arg +"' doesn't exist.\n"));

     }
     
     if(!logfile)
          return(notify_fail("Syntax: log <logfile>\n"));

     tail(logfile);
     
     return 1;
}

string help()
{
     return(" %^BOLD%^SYNTAX:%^RESET%^ log <logfile>\n\n"
     "This command allows you to see the tail (ending) of different\n"
     "logfiles. If you do not provide an argument and there is a file\n"
     "named 'log' in your home directory, then it will display that.\n"
     "If you don't provide an argument and there is not a file named\n"
     "'log' in your home directory, it will display '/log/log' if it\n"
     "exists. If you provide an argument, it will try to show the tail\n"
     "of /log/<logfile>. You can also view the tail of logfiles in the\n"
     "subdirectory of '/log/' (ex. 'log driver/UPRECORD').\n");
}          
          
               