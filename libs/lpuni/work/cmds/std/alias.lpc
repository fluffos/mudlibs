/* alias.c

 Tacitus @ LPUniversity
 14-JAN-06
 Alias command
 
*/

int main(string args)
{
     string verb, alias;
     
     if(!args)
     {
          mapping data = this_player()->get_aliases();
          string *keys;
          int i;
          
          if(!mapp(data)) return(notify_fail("Aliases: No local aliases defined.\n"));
          
          keys = keys(data);
          
          if(!sizeof(keys)) return(notify_fail("Aliases: No local aliases defined.\n"));
          
          write("Current local aliases: \n");
          
          for(i = 0; i < sizeof(keys); i++)
          {
               printf("%-10s %-20s\n", keys[i], data[keys[i]]);
          } 
          
          return 1;        
     }
     
     if(args == "-g")
     {
          mapping data = this_player()->get_aliases(1);
          string *keys;
          int i;
          
          if(!mapp(data)) return(notify_fail("Aliases: No local aliases defined.\n"));
          
          keys = keys(data);
          
          if(!sizeof(keys)) return(notify_fail("Aliases: No local aliases defined.\n"));
          
          write("Current aliases: \n");
          
          for(i = 0; i < sizeof(keys); i++)
          {
               printf("%-10s %-20s\n", keys[i], data[keys[i]]);
          } 
          
          return 1;          
          
     }
     
     if(sscanf(args, "%s %s", verb, alias) == 2)
     {
          if(strsrch(alias, "$*") == -1)
          {
               if(alias[<1] != ' ') alias += " $*";
               else alias += "$*";
          }
          
          if(verb == "alias" || verb == "unalias")
               return(notify_fail("Error: You may not alias 'alias' or 'unalias'.\n"));
          
          this_player()->add_alias(verb, alias);
          
          write("Alias: Added alias '" + verb + " " + alias + "'\n");
          return 1;         
     }
     
     else return(notify_fail("Syntax: alias [-g] <[$]verb> <alias>\n"));    
} 

string help()
{
     return(" %^BOLD%^SYNTAX:%^RESET%^ alias [-g] <[$]verb> <alias>\n\n"
     "This command allows you to display your current aliases and\n"
     "add new ones. If you would like to view your current aliases,\n"
     "then simply type 'alias'. If you'd like to see your current\n"
     "aliases plus global aliases then affect you, provie -g as an\n"
     "argument by it's self. To add an alias, you must provide two arguments;\n"
     "the verb you wish to alias and the actual alias. You may use $n,\n"
     "where represents a number that repsents the index of a word as an\n"
     "argument when the alias is parsed. (example: 'alias say say %2 %1'\n"
     "will result in the first and second word to be always switched when\n"
     "you type say). You can also use $*, which will be replaced with all\n"
     "remaining words. If you place $ in front of the verb, then all commands\n"
     "beginning with that verb will be parsed with that alias\n"
     "(ex. 'alias $: emote $*' will result in any command beginning with ':' to\n"
     "be parsed as emote $*).\n\n"
     "%^BOLD%^See also:%^RESET%^ unalias\n");
}