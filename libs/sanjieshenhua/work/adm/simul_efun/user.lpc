// user.c

int playerp(object ob)
{
	return ob->is_player();
}

int pkerp(object ob)
{
        return ob->is_pker();
}

int metep(object ob)
{
        return ob->query("opinion/mete");
}

object *wizards()
{
        return filter_array(children(USER_OB), (: wizardp :));
}

int newbiep(mixed ob)
{
    if (!objectp(ob) || !userp(ob))
        return 0;

    if (ob->query("age") < 15)
        return 1;

    if (ob->query("age") < 16
        && (ob->query("combat_exp") < 500000
        || ob->query("daoxing") < 500000))
        return 1;

    return 0;
}

protected int filter_player(object ob, string id)
{
        if (clonep(ob) && getuid(ob) == id)
                return 1;
}

// return a user, needn't interactive
object find_player(string id)
{
        object found;
        object *ob;
        int i;

        if (found = efun::find_player(id))
                return found;

        ob = filter_array(children(USER_OB), (: filter_player :), id);
        switch (i = sizeof(ob))
        {
        case 0:
                return 0;
	case 1:
                return ob[0];
	default:
		log_file("log", sprintf("error find %d players(%s)\n",
			                sizeof(ob), id));
		error("The player(" + id + ") has existed in the world.\n");
		return ob[0];
        }

        // more than one players' id are the same? I will destruct them
        // who hasn't environment.
        i--;
        while (i >= 0)
        {
                if (! environment(ob[i]))
                        efun::destruct(ob[i]);
                else if (! ob[i]->query_temp("user_setup"))
                        destruct(ob[i]);
                i--;
        }
        ob -= ({ 0 });
        i = sizeof(ob);
        switch (i = sizeof(ob))
        {
	default:
                // aha, I have not idea to select out the real user
        case 1:
                return ob[0];
        case 0:
                return 0;
        }
}

