//#pragma save_binary

// make_land.c:  compile virtual rooms of domains

int query_prevent_shadow()
{
   return 1;
}

object compile_object(string s)
{
	object obj;
	string *tmp, domain;

	seteuid(getuid(this_object()));
	obj = new(file_name(this_object()));
	if( sscanf(s, "/d/%s/%*s", domain)!= 1 )
		return 0;
	tmp = explode(s,"/");
	obj->initialize(domain, tmp[sizeof(tmp) - 1]);
	return obj;
}
