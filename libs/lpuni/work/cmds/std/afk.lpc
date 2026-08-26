/*

    afk.c

    Parthenon@LPUniversity
    August 15th, 2006
    Command to set yourself as away

*/

int main(string args)
{
    if(!args) args = "";

    this_player()->set_env("away", args);

    write("\nYou are now away" + (!args || args == "" ? ".\n" : ": " + args + "\n"));
    write("Press "+ HIW + "[ENTER]" + NOR + " to return.\n");
    input_to("i_Return");
    return 1;
}

void i_Return(string arg)
{
    write("You return from away\n");
    this_player()->set_env("away", 0);
    return;
}

string help()
{
    return
    HIW + " SYNTAX:" + NOR + " afk [<message>]\n\n" +
    "This command allows you to set an away message. While away\n"+
    "you cannot perform any actions. If you set the optional away\n"+
    "message, then when others try to talk to you using things\n"+
    "such as tell, they will receieve that message.\n";
}


