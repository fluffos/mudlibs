/*
*******************************************************************************
** process_string simulated efun
*******************************************************************************
*/

mixed process_value(string func) {
    int tmp;
    string arg;
    object obj;

    if (!func || !stringp(func))
	return 0;

    if ((tmp = member(func, '|')) != -1) {
	arg = func[tmp+1..];
	func = func[0..tmp-1];
    }
    if ((tmp = member(func, ':')) != -1) {
	obj = find_object(func[tmp+1..]);
	func = func[0..tmp-1];
    } else {
	obj = previous_object();
    }
    if (!obj)
	return 0;
    if (!arg)
      arg = "";
    
    return apply( symbol_function( func, obj ), explode(arg, "|") );
}

string process_string(string str) {
    int pr_start, il;
    string * parts;
    string tmp;

    parts = explode(str, "@@");
    
    pr_start = !(str[0..1]=="@@");
    
    for ( il = pr_start; il < sizeof(parts); il += 2) {
	tmp = process_value(parts[il]);
	if (stringp(tmp))
	    parts[il] = tmp;
    }

    return implode(parts, "");
}

