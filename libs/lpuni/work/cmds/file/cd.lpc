//cd.c

//Byre @ LPUniversity
//05-APR-05
//File Navigation

//Last edited on October 2nd, 2005 by Tacitus

int main(string str)
{
     string *exp;
     if(!str)
     {
          if(directory_exists(user_path(this_player()->query_name())))
          {
               str = user_path(this_player()->query_name());
          }
          else
          {
               return notify_fail("Syntax: cd <directory>\n");
          }
     }
     if(str[0]!='/') str=resolve_path(this_player()->query("cwd"), str);
     exp=explode(str,"/");
     if(sizeof(exp)<=1)
     {
          if(!directory_exists(str)) return notify_fail("Error [cd]: Directory doesn't exist.\n");
          if(!(int)master()->valid_read(str, this_player(), "cd")) return notify_fail("Error [cd]: Permission denied.\n");
          this_player()->set("cwd",str);
          write(str+"\n");
          return 1;
     }
     
     if(exp[<1]=="..")
     {
          str="/"+implode(exp[0..<3],"/");
          if(str[0]!='/') str+="/";
          if(!directory_exists(str)) return notify_fail("Error [cd]: Directory doesn't exist.\n");
          if(!(int)master()->valid_read(str, this_player(), "cd")) return notify_fail("Error [cd]: Permission denied.\n");
          this_player()->set("cwd",str);
          write(str+"\n");
          return 1;
     }
     
     if(!(int)master()->valid_read(str, this_player(), "cd")) return notify_fail("Error [cd]: Permission denied.\n");
     if(!directory_exists(str)) return notify_fail("Error [cd]: Directory doesn't exist.\n");
     
     if(str[<1..] != "/") str += "/";
     this_player()->set("cwd",str);
     write(str+"\n");
     return 1;
}

string help() {
    return (HIW + " SYNTAX: " + NOR + "cd <directory>\n\n" + 
    "This command allows you to navigate through various directories.\n" + 
    "To use this command, you simply provide the directory (either\n" + 
    "an absolute path or one relative to the current directory) as the\n" +
    "argument to this command.\n\n" + 
    HIW + "See also: " + NOR + " mkdir, rmdir, ls\n"); 
} 
