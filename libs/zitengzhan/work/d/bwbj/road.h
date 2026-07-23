int block_cmd(string args);
void init()
{
add_action("block_cmd", "", 1);
}
int block_cmd(string args)
{
string verb;
 verb = query_verb();
if ( verb == "cast" || verb == "get"|| verb == "perform"|| verb == "whisper" || verb == "drop" || verb == "recall") 
	return 1;
return 0;
}

