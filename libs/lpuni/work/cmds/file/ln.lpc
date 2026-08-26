/* ln.c

 Tacitus @ LPUniversity
 15-JAN-06
 File System Command
 
*/

int main(string args)
{
     string file, refrence;
     
     if(!args) return(notify_fail("Syntax: ln <original file> <new refrence>\n"));
     
     if(sscanf(args, "%s %s", file, refrence) != 2) 
          return(notify_fail("Syntax: ln <original file> <new refrence>\n"));
     
     file = resolve_path(this_player()->query("cwd"), file);
     refrence = resolve_path(this_player()->query("cwd"), refrence);           
     
     if(!file_exists(file)) return(notify_fail("Error [ln]: File '" + file + "' does not exist.\n"));
     if(file_exists(refrence)) return(notify_fail("Error [ln]: File '" + refrence + "' already exists.\n"));
     if(directory_exists(file)) return(notify_fail("Error [ln]: '" + file + "' is a directory.\n"));
     if(directory_exists(refrence)) return(notify_fail("Error [ln]: '" + refrence + "' is a directory.\n"));
     if(!master()->valid_link(file, refrence)) return(notify_fail("Error [ln]: Permission denied.\n"));
     
     write((link(file, refrence) ? "Error [ln]: Linking of file '" + refrence + "' to '" + file + "' was unsuccesful.\n"
          : "Success [ln]: File '" + refrence + "' now linked to '" + file + "'.\n" ));
     
     return 1;
}

string help()
{
     return(" %^BOLD%^SYNTAX:%^RESET%^ ln <original file> <new refrence>\n\n"
     "This command is a very powerful tool that allows you to create a\n"
     "file that refrences to another file. This means when you access\n"
     "the new file you created with this command, you'll be actually\n"
     "accessing the original file. This is a very dangerous tool as\n"
     "well becuase the new file will inherit the permissions of it's\n"
     "new directory, possibly allowing people to access the file who\n"
     "wouldn't be able to access it before. For this command to work,\n"
     "you must have read and linking permissions in the directory of\n"
     "the original file and then write and linking permissions in the\n"
     "directory of the new refrence.\n");
}