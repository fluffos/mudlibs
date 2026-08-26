//inherit F_CLEAN_UP;

mapping global_alias = ([
    "l": "look",
    "n": "go north",
    "e": "go east",
    "w": "go west",
    "s": "go south",
    "u": "go up",
    "d": "go down",
  "out": "go out",
   "ne": "go northeast",
   "se": "go southeast",
   "nw": "go northwest",
   "sw": "go southwest",
    "i": "inventory",
   "tt": "team talk",
   "sc": "score",
    "k": "kill",
    "f": "fight",
   "sk": "skills",
    "p": "perform",
]);

void create()
{
    seteuid(getuid());
}

string process_global_alias(string arg)
{
    string *word;

    if (arg[0]=='\'')
        return "say " + arg[1..];

    word = explode(arg, " ");
    if( sizeof(word) && !undefinedp(global_alias[word[0]]) )
    {
        word[0] = global_alias[word[0]];
        return implode(word, " ");
    }

    return arg;
}
