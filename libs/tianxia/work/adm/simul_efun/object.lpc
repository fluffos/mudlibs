// object.c
// Modified by Find.

nomask varargs int getoid(object ob)
{
	int id;

	if (!ob) ob = previous_object();
	sscanf(file_name(ob), "%*s#%d", id);
	return id;
}

// Get the owner of a file.  Used by log_error() in master.c.
nomask string file_owner(string file)
{
    string name, rest;

    if (file[0] != '/') {
        file = "/" + file;
    }
    if (sscanf(file, WIZ_DIR+"%s/%s", name, rest) == 2) {
        return name;
    }
    return 0;
}

// domain_file should return the domain associated with a given file.
nomask string domain_file(string file)
{
	string domain;

	if( sscanf(file, "/d/%s/%*s", domain) )
		return domain;

	return "MudOS"; // by Find.
}

// creator_file should return the name of the creator of a specific file.
nomask string creator_file(string file)
{
	string *path, uid,pid;

	path = explode(file, "/") - ({ 0 });
	switch(path[0])
	{
		case "adm":
			if( file==SIMUL_EFUN_OB ) return "MudOS";
			else return ROOT_UID;
			break;
		case "cmds":
			return ROOT_UID;
			break;
		case "d":
			return capitalize(domain_file(file));
			break;
		case "wiz":
			if( sizeof(path) < 3 )
				return "MudOS";

			uid = path[1];

			if( this_player(1) )
			{
				pid = geteuid(this_player(1));
				if(wiz_level(pid) >= wiz_level(uid))
					return uid;
				else
					return pid;
			}
			else
				return uid;
			break;
                case "obj":
			if(sscanf(file,"/obj/wizard/%*s"))
			{
				if( this_player(1) )
					return geteuid(this_player(1));
			}
			else
				return "Object";
			break;
		case "std":
			return "Standard";
			break;
		case "u":
		case "open":
		case "ftp":
		default:
			return "MudOS";
	}
}

// author_file should return the name of the author of a specific file.
nomask string author_file(string file)
{
	string name;

	if( sscanf(file, WIZ_DIR+"%s/%*s", name) )
		return name;
	return "MudOS";  // by Find.
}

// modified by find.
nomask void destruct(object ob)
{
	if(ob)
	{
	
		if( previous_object() )
		{
			if(sscanf(file_name(ob),"/adm/%*s")
			&& !MASTER_OB->valid_write(file_name(ob),
				previous_object(),"destruct_object" ))
				return;
			else
				ob->remove( geteuid(previous_object()) );
		}
		else ob->remove(0);
	}
	else
	{
		ob = previous_object();
	}

	if(ob)
	efun::destruct(ob);
}

/* by Find */
nomask int exec(object to,object from)
{
	if(!objectp(to) || !objectp(from))
		return 0;

	if(previous_object()
	&& ( (previous_object() == find_object(LOGIN_D))
	|| (previous_object() == find_object(UPDATE_CMD))) )
		return efun::exec(to,from);
	else
		error("Permission Denied.\n");
}

/* by Find */
int is_money(object ob)
{
	if(!objectp(ob))
		return 0;

	if(ob->query("money_id") && sscanf(file_name(ob),"/obj/money/%*s"))
		return 1;
	else
		return 0;
}

int interactive(object ob)
{
        if(!objectp(ob) || !userp(ob))
                return 0;

        else
                return efun::interactive(ob);
}

void replace_program(string str)
{
	return;
}
