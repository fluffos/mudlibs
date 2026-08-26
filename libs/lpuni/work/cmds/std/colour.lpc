//colour.c

//Tacitus @ LPUniversity
//24-OCT-05
//Standard command

int main(string str)
{
    switch(str)
    {
    case "enable" :
    case "on" :
    case "start" :
    case "ansi" :
    case "begin" : {
        this_player()->set_env("colour", "enabled");
        write("%^GREEN%^Success:%^RESET%^ Colour " + str + ".\n");
        return 1;
    }

    case "disable" :
    case "off" :
    case "stop" :
    case "none" :
    case "kill" : {
        this_player()->set_env("colour", "disabled");
        write("Success: Colour " + str + "\n");
        return 1;
    }

    default : {
        if(this_player()->query_env("colour") == "enabled")
        {
        write("Colour: Colour is currently %^GREEN%^enabled%^RESET%^.\n");
        return 1;
        }
        else
        {
        write("Colour: Colour is currently disabled.\n");
        return 1;                    
        }
    }
    }
}

string help()
{
    return(" %^BOLD%^WHITE%^SYNTAX:%^RESET%^ colour [<enable>||<disable>]\n\n" 
      "With no arguments, this command will tell you if you currently\n"
      "have colour enabled or disabled. You can also toggle colour by\n"
      "providing the arguments 'enable' to enable or 'disable' to disable.\n"
      "It should be noted that 'enable' and 'disable' aren't the only\n"
      "keywords to toggle colour, you can also use 'off', 'start',\n"
      "and 'none' to name a few. How many can you find?\n\n" 
      "%^BOLD%^WHITE%^See also:%^RESET%^ set_env\n");
}
