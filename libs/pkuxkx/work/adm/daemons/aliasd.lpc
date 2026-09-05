// aliasd.c
// Modified by iszt@pkuxkx, 2007-03-11, add "bei=prepare"

mapping global_alias = ([
	"l":	"look",
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
	"u":	"go up",
	"d":	"go down",
	"i":	"inventory",
        "cut":    "zhan",
        "jianding":    "identify",
        "topten": "top",
        "sc":    "score",
        "wi":    "wield",
        "uw":    "unwield",
       "gre":    "recitewords gre",
       "cet4":    "recitewords cet4",
       "cet6":    "recitewords cet6",
//skill cmds
        "cha":    "skills",
        "sk":    "skills",
        "prof":  "professions",
        "du":    "study",
        "bai":    "apprentice",
        "fangqi":    "abandon",
                "dazuo":"exercise",
                "jiali":"enforce",
		"tuna":"respirate",
		"yun":"exert",
		"kaichu":"expell",
		"lian":"practice",
		"jifa":"enable",
                "bei":"prepare",
		"shou":"recruit",
		"xue":"learn",
                "exit":"quit",
                "chi":"eat",
                "qudu":"antipoison",
                "he":"drink",
//for高级兵器，不在cmds/skill做N个命令了
"jianyi":"weapons jianyi",
"bafu":"weapons bafu",
"bianying":"weapons bianying",
"bimo":"weapons bimo",
"daomang":"weapons daomang",
"hengzhang":"weapons hengzhang",
"liuji":"weapons liuji",
"nuchui":"weapons nuchui",
"qianghun":"weapons qianghun",
"qiling":"weapons qiling",
]);

string process_global_alias(string arg)
{
	string *word;

	if (arg[0]=='\'') return "say " + arg[1..strwidth(arg)-1];

	word = explode(arg, " ");
	if( sizeof(word) && !undefinedp(global_alias[word[0]]) ) {
		word[0] = global_alias[word[0]];
		return implode(word, " ");
	}

	return arg;
}
