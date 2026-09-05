// define var
// poet modified to use F_SHELL
// poet modified to use free command style

int main(object me, string arg)
{
    mixed result;
    string name, value, str;
    int index;
    mapping vars;


    if (sizeof(me->query_temp("vars")) == 0)
    {
	me->set_temp("vars",([]));
	vars = ([ ]);
    } else
	vars = me->query_temp("vars");
    if (sizeof(vars) > 10) return notify_fail("请不要设置过多的shell变量。\n");
    if (!arg)
    {
	if ( sizeof(vars) > 0 )
	{
	    tell_object(me,"你当前设置的shell变量有：\n");
	    foreach(str in keys(vars))
	    tell_object(me, sprintf("%s\t== %O\n", str, vars[str]));
	    return 1;
	}
	else {
	    tell_object(me,"你目前没有设置任何shell变量。\n");
	    return 1;
	}
    }
    if ( !arg || arg == "" )
	return notify_fail("@ 变量名 = 值\n或者\nvar name = value\n");

    index = strsrch(arg, '=');

    if ( index == -1 )
    {
	name = arg;
    } else
    {
	name = arg[0..(index-1)];
	value = arg[(index+1)..<1];
    }
    name = replace_string(name, " ", "");

    if ( name == "me" )
    {
	return notify_fail("不可以与系统变量重名。\n");
    }
    if ( !value
      || value == "none" || value == " none"
      || value == "null" || value == " null" )
    {
	map_delete(vars, name);
	printf("delete var %s Ok.\n", name);
	return 1;
    }
    result = me->process_shell(value);
    vars[name] = result;
    me->set_temp("vars", vars);
    printf("var %s = %O\n", name, result);
    return 1;
}


