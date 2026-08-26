/* unalias.c

 Tacitus @ LPUniveristy
 14-JAN-05
 Unalias command
 
*/

int main(string args)
{
     if(!args) return(notify_fail("Syntax: unalias <verb>\n"));
     if(this_player()->remove_alias(args))
     {
          write("Success [aliases]: Verb '" + args + "' is now longer aliased.\n");
          return 1;
     }
     else return(notify_fail("Error [aliases]: That verb is not aliased locally.\n"));
}

string help()
{
     return("%^BOLD%^SYNTAX:%^RESET%^ unalias <verb>\n\n"
     "This command allows you to unalias local aliases. A local alias\n"
     "is an alias that you have set, not global aliases. To unalias\n"
     "a verb that is currently aliased locally, simply provide the\n"
     "verb as the argument. If you don't like a global alias, you can\n"
     "create an alias with the same verb to override it.\n\n"
     "%^BOLD%^See also:%^RESET%^ alias\n");     
}
