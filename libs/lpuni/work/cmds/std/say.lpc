//say.c

//Tacitus @ LPUniversity
//01-JULY-05
//Simple communication command

int main(string arg)
{
    if(!arg) {
    write("You mumble to your self.\n");
    say(capitalize((string)previous_object()->query_name()) + " mumbles to themself.\n");
    return 1;
    }
    else
    {
    write("%^BOLD%^YELLOW%^You say:%^RESET%^ " + arg + "\n" + NOR);
    say("%^YELLOW%^" + capitalize((string)previous_object()->query_name())
      + " says:%^RESET%^ " +  arg + "\n" + NOR);
    return 1;
    }
}

string help()
{
    return(HIW + " SYNTAX:" + NOR + " say <argument>\n\n" +
      "This command will send a message to everyone in the room.\n" +
      "Example, if you type 'say Hello!' then the others in the\n" +
      "room will see '" + capitalize(this_player()->query_name()) + " says: Hello!'\n\n" +
      HIW + "See also:" + NOR + " tell, tune\n");
}

