// user.c

// return the list of users
object *users()
{
        return filter_array(children(USER_OB), (: userp :));
}

// return all the interactive users
object *all_interactive()
{
        return efun::users();
}

int playerp(object ob)
{
	return (sscanf(file_name(ob), USER_OB + "#%*d") == 1);
}

int ultrap(object ob)
{
        return ob->query("opinion/ultra");
}

int masterp(object ob)
{
        return ob->query("opinion/master");
}

private int filter_player(object ob, string id)
{
        if (clonep(ob) && getuid(ob) == id)
                return 1;
}

// return a user, needn't interactive
object find_player(string id)
{
        object *ob;
        int i;

        ob = filter_array(children(USER_OB), (: filter_player :), id);
        switch (i = sizeof(ob))
        {
        case 0:
                return 0;
        case 1:
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
        case 1:
                return ob[0];
        case 0:
        default:
                // aha, I have not idea to select out the real user
                return 0;
        }
}
