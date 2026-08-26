/* echo.c

 Tacitus @ LPUniversity
 12-AUG-06
 Simple echo command

*/

int main(string str) 
{ 
    if(!str) 
    return notify_fail("Syntax: echo <argument>\n");
    write("You echoed to the room: " + str + "\n");
    tell_room(environment(this_player()), str, ({ this_player() }));
    return 1;
}

string help()
{
    return(" %^BOLD%^SYNTAX:%^RESET%^ echo <string>\n\n"
      "This command allows you to echo a string of text to the room you are currently\n"
      "in. Other individuals in the room will see the argument that you pass to this\n"
      "command exactly as you typed it with a newline (aka linebreak) after it.\n\n"
      "For example, if you type 'echo The room shakes.' then everyone else in the room\n"
      "will see the following printed 'The room shakes.'.\n");
}
