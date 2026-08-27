// aliasd.c
// #pragma save_binary
mapping global_alias = ([
        "l":    "look",
        "n":    "go north",
        "e":    "go east",
        "w":    "go west",
        "s":    "go south",
        "south":   "go south",  // add by Cominging - Start
        "north":   "go north",  //
        "west":    "go west",  //
        "east":    "go east",  // 
        "northup": "go northup", //
        "eastup": "go eastup", //
        "westup": "go westup",  //
        "southup": "go southup", //
        "northdown": "go northdown", //
        "southdown": "go southdown", //
        "eastdown": "go eastdown", //
        "westdown": "go westdown", //
        "down": "go down", //
        "up":   "go up", // add by Cominging - End
        "nu":   "go northup",
        "eu":   "go eastup",
        "wu":   "go westup",
        "su":   "go southup",
        "nd":   "go northdown",
        "ed":   "go eastdown",
        "wd":   "go westdown",
        "sd":   "go southdown",
        "ne":   "go northeast",
        "se":   "go southeast",
        "nw":   "go northwest",
        "sw":   "go southwest",
        "u":    "go up",
        "d":    "go down",
        "o":    "go out",
        "i":    "inventory",
        "tt":   "team talk",
        "h":    "hp",
        "sc":   "score",
        "sco":  "score",
        "k":    "kill",
        "sk":   "skills",
        "wi":   "wield",
        "ueq":  "remove",
        "rem":  "remove",
        "uwi":  "unwield",
        ";" :   "reply ",
        "adv":  "advance",
        "tr":   "train",
        "c":    "cast",
        "ss":   "shoot",
        "ex":   "exert",
        "con":  "consider",
        "check": "consider",
        "sec":  "secure",
        "m":    "map",
        "eq":   "wear",
]);

string process_global_alias(string arg)
{
        string *word;

        if (arg[0]=='\'') return "say " + arg[1..strlen(arg)-1];

        word = explode(arg, " ");
        if( sizeof(word) && !undefinedp(global_alias[word[0]]) ) {
                word[0] = global_alias[word[0]];
                return implode(word, " ");
        }

        return arg;
}

