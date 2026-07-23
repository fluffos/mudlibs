int block_cmd(string args);

void init()
{
set("magicroom",1);
add_action("block_cmd", "", 1);
}

int block_cmd(string args)
{
string verb;
 verb = query_verb();
if ( verb == "cast" || verb == "perform" || verb == "climb" || verb == "recall" || verb == "xiulian" ) 
	return 1;
return 0;
}

