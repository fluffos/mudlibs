/*
 * ccall,  compiles the object and everything that it has inherited
 * 
 * coder   dazzt
 * */


int main (string str) 
{
	string *ob;
	int i;
	
    if (!str)
	{
		notify_fail("Usage: ccall <filename>\n");
		return 0;
	}
	
	
	if (!absolute_path(str))
		str = THIS->query_cwd() + str;

	if (file_size(str) < 0)
	{
		notify_fail("File not found.\n");
		return 0;
	}
	
	ob = deep_inherit_list(find_object(str));
	if (!ob || ob == ({ }))
	{
		"/command/immortal/cc"->main(str);
		return 1;
	}
	for (i = sizeof(ob) - 1; i >= 0; i--)
		"/command/immortal/cc"->main(ob[i]);
	"/command/immortal/cc"->main(str);
	
	return 1;
}
