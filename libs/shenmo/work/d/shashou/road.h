int block_cmd(string args);

void init()
{
add_action("block_cmd", "", 1);
}

int block_cmd(string args)
{
string verb;
 verb = query_verb();
if ( verb == "cast" || verb == "perform" || verb == "climb" || verb == "recall" || verb == "bian"  || verb == "drop") 
	return 1;
return 0;
}

