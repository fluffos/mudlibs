// object.c

nomask varargs int getoid(object ob)
{
    int id;

    if (!ob)
        ob = previous_object();
    sscanf(file_name(ob), "%*s#%d", id);
        return id;
}

// Get the owner of a file.  Used by log_error() in master.c.
nomask string file_owner(string file)
{
    string name, rest;

    if (file[0] != '/')
    {
        file = "/" + file;
    }
// modify by mudring
    if (sscanf(file, "/u/%s/%s", name, rest) == 2)
// end
    {
        return name;
    }

    return 0;
}

// domain_file should return the domain associated with a given file.
nomask string domain_file(string file)
{
    string domain;

// modify by mudring
    if (sscanf(file, "/d/%s/%*s", domain)
        || sscanf(file, "/obj/%s/%*s", domain)
        || sscanf(file, "/daemon/%s/%*s", domain))
                return domain;

    if (sscanf(file, "/u/%*s"))
        return "Wizard";
//end

    return "MudOS";
}

// modify by mudring
// creator_file should return the name of the creator of a specific file.
nomask string creator_file(string file)
{
    string *path;
    object ppl, prev;

    path = explode(file, "/") - ({ 0 });
    if (!sizeof(path)) return ROOT_UID;

    ppl = this_player(1);
    prev = previous_object(1);

    switch(path[0])
    {
        case "adm":
    	    if (file==SIMUL_EFUN_OB)
                return "MudOS";
            else
                return ROOT_UID;
        case "cmds":
            return ROOT_UID;
        case "u":
/*
            if (ppl && wizardp(ppl))
                return getuid(ppl);
            // previous_object(0) is simul_efun object here.
            else if (prev)
                return geteuid(prev);
            return "Mudlib";
*/
            return "Wizard";
        case "d":
        case "obj":
        case "daemon":
            return "Domain";
        default:
            return "MudOS";
    }
}
// end

// author_file should return the name of the author of a specific file.
nomask string author_file(string file)
{
    string name;

// modify by mudring
    if (sscanf(file, "/u/%s/%*s", name))
// end
        return name;

    return "MudOS";
}

// check the object's euid wehter is root
nomask int is_root(mixed ob)
{
    if (stringp(ob))
        return (SECURITY_D->get_status(ob) == "(admin)");

    if (objectp(ob))
    {
        if (geteuid(ob) == ROOT_UID)
            // Root object want to execute
            return 1;

        return (SECURITY_D->get_status(geteuid(ob)) == "(admin)");
    }

    return 1;
}

nomask object unew(string str)
{
    object ob = new(str);
    int i = ob->query("unique"), j, k;
    object *clone;

    if (!i) return ob;
    clone = filter_array(children(base_name(ob)), (: clonep :));

    j = sizeof(clone);
    while (j--)
        if (!clone[j]->query("clone_by_wizard"))
        {
            if (k = clone[j]->query_amount()) i -= k;
            else i--;
        }
    if (i < 0) destruct(ob);

    return ob;
}

/*
nomask object new(string name)
{
    object *clone;

    clone = filter_array(children(name), (: clonep :));

    if (sizeof(clone) > 300) return 0;

    return efun::new(name);
}
*/

