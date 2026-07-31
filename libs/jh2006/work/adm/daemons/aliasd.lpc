// aliasd.c

mapping global_alias = ([
	"bai":		"apprentice",
	"bei":		"prepare",
	"dating":	"check",
	"dazuo":	"exercise",
	"du":		"study",
	"fangqi":	"abandon",
	"i":		"inventory",
	"jia":		"marry",
	"jiali":	"enforce",
	"jifa":		"enable",
	"kaichu":	"expell",
	"l":		"look",
	"lian":		"practice",
	"qiu":		"propose",
	"quan":		"persuade",
	"sha":		"kill",
	"shou":		"recruit",
	"tk":		"teamkill",
	"tt":		"team talk",
	"tt*":		"team talk*",
	"tuna":		"respirate",
	"xue":		"learn",
	"yun":		"exert",
	"zisha":	"suicide",
	"n":		"go north",
	"e":		"go east",
	"w":		"go west",
	"s":		"go south",
	"nu":		"go northup",
	"eu":		"go eastup",
	"wu":		"go westup",
	"su":		"go southup",
	"nd":		"go northdown",
	"ed":		"go eastdown",
	"wd":		"go westdown",
	"sd":		"go southdown",
	"ne":		"go northeast",
	"se":		"go southeast",
	"nw":		"go northwest",
	"sw":		"go southwest",
	"u":		"go up",
	"d":		"go down"
]);

string process_global_alias(string arg, object ob)
{
	string *word;
	int i;

	if (!ob)
		ob = this_player();
	if (ob && userp(ob) && !wizardp(ob) && ob->is_ghost())
		return "";
	for (i=0; i<strlen(arg); i++)
		if (arg[i] != ' ') {
			arg = arg[i..<1];
			break;
		}
	if (arg[0]=='\'')
		arg = "say " + arg[1..<1];

	word = explode(arg, " ");
	if( sizeof(word) && !undefinedp(global_alias[word[0]]) ) {
		word[0] = global_alias[word[0]];
		arg = implode(word, " ");
	}
	i = strlen(arg);
	if (ob && userp(ob) && !wizardp(ob))
		while (i--)
			if (arg[i] < ' ' && arg[i] != 27 && arg[i] != 10) arg[i] = ' ';

	if (ob && wizardp(ob) && geteuid(ob) != "yuj")
		log_file("wiz/"+getuid(ob), ctime(time())[4..19] + arg + "\n");
	return arg;
}
