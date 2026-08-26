/* what.c

 Tacitus @ LPUniversity
 12-AUG-06
 Displays acitivity info about users

*/

int main()
{
    if(!adminp(previous_object())) return 0;
    write("=----------------------------------------------=\n");
    printf(" %-15s %-s \n", "Username", "Last Command");
    write("=----------------------------------------------=\n");

    foreach(object user in users())
    {
    string *commandHistory = user->query_commandHistory();
    if(!living(user)) continue;

    if(sizeof(commandHistory) <= 0)
        printf("  %-15s %s\n", user->query_cap_name(),
          "<none>");
    else

        printf("  %-15s %s\n", user->query_cap_name(),
          commandHistory[sizeof(commandHistory)-1]);
    }

    write("=----------------------------------------------=\n");

    return 1;
}

string help()
{
    return(" %^BOLD%^SYNTAX%^RESET%^: what\n\n"
      "This command allows you to view the last command executed by\n"
      "all users logged in. It is recommended that you review any\n"
      "privacy policy that your mud might have before using this tool.\n");
}
