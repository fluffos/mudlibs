// Shows the list of pending call_outs
//
// Syntax: calls [-a] [filter]
//
//   -a     : sort alphabetically (default is by remaining delay)
//   filter :  will only show items that contain the filter text
//

status is_greater(mixed *a, mixed *b) {
    return object_name(a[0])>object_name(b[0]);
}

status calls_cmd(string str, object me)
{
    string s, s1, s2, tmp;

    if (!me && !(me=this_player())) return 0;

    mixed *call_array = call_out_info();

    if(!call_array)
	return notify_fail("#Calls: got 0 from call_out_info().\n"),0;

    string *txt = ({"Total of "+sizeof(call_array)+" pending call_outs:"});
    txt += ({sprintf("%-50s %-22s %s", "Object", "Function", "Delay\t Arg(s)") });
    txt += ({ sprintf("%'='89s", "" ) });

    if (str) {
	int flag = 0;
	if (str=="-a") { flag = 1; str = 0; }
	else if (sscanf(str, "-a %s", str)) flag = 1;
	if (flag) call_array = sort_array(call_array, #'is_greater);//'
    }

    foreach( mixed item : call_array)
    {
	tmp = objectp(item[0]) ? object_name(item[0]) : sprintf("%O", item[0]);
	if (str && sscanf(tmp,"%s"+str+"%s",s1,s2) < 2)  continue;

	if (tmp[0..7] == "players/") tmp = "~"+tmp[8..];

	if (closurep(item[1])) {
	    if (sscanf(to_string(item[1]), "#'%s->%s()%!s", s1, s2)==2) item[1] = s2;
	}

	s = sprintf("%-50s %-22s %d\t ", tmp,
	  stringp(item[1]) ? item[1] : sprintf("%O", item[1]), item[2]);

	if (sizeof(item) < 4) {
	    txt += ({ s+"0" });
	    continue;
	}

	if (intp(item[3]) || stringp(item[3]))
	    s += item[3];
	else if(objectp(item[3]))
	    s += "(Object)";
	else if(mappingp(item[3]))
	    s += "(["+sizeof(item[3])+"])";
	else
	    s += "({"+sizeof(item[3])+"})";

	txt += ({ s });
    }

    txt += ({ sprintf("%'='89s", "" ) });
    me->more(txt);
    return 1;
}
