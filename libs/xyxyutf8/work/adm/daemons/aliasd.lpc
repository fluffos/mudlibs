// aliasd.c
// Modify by Jingxue for XYCQ 6.10.2003

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
	"i":		"inventory",
	"tt":		"team talk",
        "tt*":  	"team talk*",
	"bai":		"apprentice",
	"cha":		"check",
	"chuan":	"wear",
	"cun":		"save",
	"dazuo":	"exercise",
	"du":		"study",
	"eryu":		"whisper",
	"fangqi": 	"abandon",
	"fangxia":	"unwield",
	"fei":		"fly",
	"gen":		"follow",
	"zhao":		"find",
	"yaoqing":	"invite",	
	"guan":		"close",
	"huida":	"reply",
	"jiali":	"enforce",
	"jianju": 	"accuse",
	"jifa":		"enable",
	"jineng":	"skills",
	"kai":		"open",
	"kaichu":	"expell",
	"lian":		"practice",
	"mai":		"buy",
	"miaoshu":	"describe",
	"mingsi":	"meditate",
	"na":		"get",
	"qiuhun":	"propose",
	"qujing":	"obstacles",
	"sha":		"kill",
	"shou":		"recruit",
	"shuo":		"say",
	"tou":		"steal",
	"touxian":	"title",
	"touxiang":	"surrender",
	"tuo": 		"remove",
	"xue":		"learn",
	"yaoqing":	"invite",
	"zhao":		"find",
	"zhuangbei":	"wield",
	"sc":		"score",
	"sk":		"skills",	
	"verify":	"helpskill",	
	"lianxi":	"practice",
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
mapping query_global_alias()
{
	if(!previous_object() || geteuid(previous_object()) != ROOT_UID)
		return 0;

	return global_alias;
}
