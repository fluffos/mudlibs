// aliasd.c

mapping global_alias = ([
	"l":		"look",
	"n":		"go north",
	"north":	"go north",
	"e":		"go east",
	"east":		"go east",
	"w":		"go west",
	"west":		"go west",
	"s":		"go south",
	"south":	"go south",
	"nu":		"go northup",
	"northup":	"go northup",
	"eu":		"go eastup",
	"eastup":	"go eastup",
	"wu":		"go westup",
	"westup":	"go westup",
	"su":		"go southup",
	"southup":	"go southup",
	"nd":		"go northdown",
	"northdown":"go northdown",
    "auc":      "auction",	
    "shou":      "recruit",	
    "dazuo":     "exercise",	
    "tuna":      "respitate", 	
    "quanjia":   "persuade", 	
    "jiajing":   "enchant", 	
    "lian":      "practice", 	
    "yun":       "exert", 	
    "jifa":      "enable",	
    "xue":       "learn",	
	"ed":		 "go eastdown",
	"eastdown":	 "go eastdown",
	"wd":		 "go westdown",
	"westdown":	 "go westdown",
	"sd":		 "go southdown",
	"southdown": "go southdown",
	"ne":		 "go northeast",
	"northeast": "go northeast",
	"se":		 "go southeast",
	"southeast": "go southeast",
	"nw":		 "go northwest",
	"northwest": "go northwest",
	"sw":		 "go southwest",
	"southwest": "go southwest",
	"u":		 "go up",
	"up":		 "go up",
	"d":		 "go down",
	"down":		 "go down",
	"i":		 "inventory",
	"bai":		 "apprentice",
	"tt":		 "team talk",
	"sc":		 "score",
    "fangqi":    "abandon",
    "du":        "study",
	"jiali":     "enforce",
]);

string process_global_alias(string arg)
{
	string *word;

	if ( !stringp(arg) ) return "";
	if ( arg[0]=='\'' ) return "say " + arg[1..strlen(arg)-1];
	
	word = explode(arg, " ");

	if ( sizeof(word) && !undefinedp(global_alias[word[0]]) )
	{
		word[0] = global_alias[word[0]];
		return implode(word, " ");
	}

	return arg;
}
