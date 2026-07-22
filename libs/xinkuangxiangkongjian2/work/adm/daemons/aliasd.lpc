// aliasd.c

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
	"tt":	"team talk",
]);

string msg_protect( string arg )
{
	string result, part;

	arg = replace_string( arg, "\07" , "" );
	arg = replace_string( arg, "\014", "" );
	if( strsrch( arg, "\e" ) < 0 ) return arg;
	result = "";
	foreach( part in explode( arg, "\e" ) ) {
		if( sscanf( part, "[%sm%*s", part ) != 2 ||
			( strlen(part) && ( part[<1] < '0' || part[<1] > '9' ) ) )
			result += part;
		else result += "\e" + part;
	}
	return result;
}

string check_text( string var )
{
	string newstr = "\n";
	do {
		newstr += replace_string(save_variable(var[0..499]), "\r", "\n");
		var = var[500..];
	} while(strlen(var));
	return newstr;
}

string process_global_alias( string arg )
{
	string *word;
	if( !arg || arg=="" )
		return arg;
	arg = msg_protect(arg);
	if( arg[0]=='\'' )
		return "say " + arg[1..-1];
	word = explode( arg, " " );
	if( sizeof(word) && !undefinedp(global_alias[word[0]]) ) {
		word[0] = global_alias[word[0]];
		return implode( word, " " );
	}
	return arg;
}
