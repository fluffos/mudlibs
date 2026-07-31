// aliasd.c

mapping global_alias = ([
	"l":	"lookold",
	"ll":	"look",
	"i":	"inventory",
	"tt":	"team talk",
	"bai":	"apprentice",
	"bei":	"prepare",
	"cha":	"skills",
	"dazuo":"exercise",
	"du":	"study",
	"fangqi":"abandon",
	"jiali":"enforce",
	"jifa":	"enable",
	"kaichu":"expell",
	"lian":	"practice",
	"shou":	"recruit",
	"tuna":	"respirate",
	"xue":	"learn",
	"yun":	"exert",
	"n":	"go north",
	"e":	"go east",
	"w":	"go west",
	"s":	"go south",
	"nu":	"go northup",
	"eu":	"go eastup",
	"wu":	"go westup",
	"su":	"go southup",
	"nd":	"go northdown",
	"ed":	"go eastdown",
	"wd":	"go westdown",
	"sd":	"go southdown",
	"ne":	"go northeast",
	"se":	"go southeast",
	"nw":	"go northwest",
	"sw":	"go southwest",
	"u":		"go up",
	"up":		"go up",
	"d":		"go down",
	"down":		"go down",
	"i":		"inventory",
	"bai":		"apprentice",
	"tt":		"team talk",
	"sc":		"score",
        "qi":	"recover",
      "jing":	"regenerate",
     "jingli":  "refresh",
 //by mol
	"x":		"xkan",
        "xrans":	"trans",
//by mol
	"ex":		"exercise" 

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
