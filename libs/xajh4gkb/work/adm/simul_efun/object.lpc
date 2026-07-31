// object.c

varargs int getoid(object ob)
{
	int id;
	if (!ob) ob = previous_object();
	sscanf(file_name(ob), "%*s#%d", id);
	return id;
}
// Get the owner of a file.  Used by log_error() in master.c.
string file_owner(string file)
{
    string name, rest;
    if (file[0] != '/') {
        file = "/" + file;
    }
    if (sscanf(file, "/u/%s/%s", name, rest) == 2) {
        return name;
    }
    return 0;
}
// domain_file should return the domain associated with a given file.
string domain_file(string file)
{
	string domain;
	if( sscanf(file, "/d/%s/%*s", domain) )
		return domain;
	if( sscanf(file, "/kungfu/class/%s/%*s", domain) )
		return domain;
	return ROOT_UID;
}
// creator_file should return the name of the creator of a specific file.
string creator_file(string file)
{
	string *path;
	path = explode(file, "/") - ({ 0 });
	switch(path[0]) {
		case "adm":
			if( file==SIMUL_EFUN_OB ) return "MudOS";
			else return ROOT_UID;
		case "cmds":	return ROOT_UID;
		case "d":
                case "www":
		case "kungfu":	return ROOT_UID;
		case "clone":	if (sizeof(path)>=2 || path[1]!="user") return ROOT_UID;
		case "u":
			if( sizeof(path)>=2 ) return path[1];
		case "open":
		case "ftp":
			if( sizeof(path)>=3 ) return path[1];
		default:
			if( this_player(1) )
				return getuid(this_player(1));
			else
				return "MudOS";
	}
}
// author_file should return the name of the author of a specific file.
string author_file(string file)
{
	string name;
	if( sscanf(file, "/u/%s/%*s", name) )
		return name;
	return ROOT_UID;
}

int living(object ob) {
    if( ob->query_temp("disable_inputs") ) return 0;
    return efun::living(ob);
}

// check the object's euid wehter is root
int is_root(mixed ob)
{
        if (stringp(ob))
                return (SECURITY_D->get_status(ob) == "(boss)");

        if (objectp(ob))
        {
                if (geteuid(ob) == ROOT_UID)
                        // Root object want to execute
                        return 1;

                return (SECURITY_D->get_status(geteuid(ob)) == "(boss)");
        }

        return 1;
}