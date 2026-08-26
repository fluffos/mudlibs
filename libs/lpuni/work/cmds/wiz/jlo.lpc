/* jlo.c

   Author: Scifi@LPUniversity
   Date:   August 26, 2006
   Objective:  See the tail enf of a wizards journal
*/

#define TPN this_player()->query("name")

int main(string name)
{
    string path;

    path = "/doc/journals/journal.";

    if(name) path = path+name;
    else path = path +TPN;

    if(!file_exists(path)) 
        return notify_fail("%^RED%^Error:%^RESET%^ "
         "No journal user '" + capitalize(name) + "' exists.\n");
         
    write("Journal: " + path + "\n\n");
        
    tail(path);

    return 1;
}

string help()
{
    return " %^BOLD%^SYNTAX:%^RESET%^ jlo [<username>]\n\n"
       "This command will return the last ten lines \n"
       "from the wizard's journal entry.  If no argument \n"
       "is given, the current user's name will be used.\n"; 
}
      

 
