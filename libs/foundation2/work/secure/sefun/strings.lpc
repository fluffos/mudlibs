/*    /adm/sefun/strings.c
 *    from Foundation II
 *    sefuns for string manipulation
 *    created by Descartes of Borg 940506
 */

varargs string center(string str, int x) {
    int y;

    if(!x) x= 80;
    if((y = strlen(strip_colours(str))) >= x) return str;
    x = x + strlen(str) - y;
    return sprintf(sprintf("%%|%ds", x), str);
}

varargs string arrange_string(string str, int x) {
    int y;

    if(!x) x = 80;
    x += strlen(str) - strlen(strip_colours(str));
    return sprintf(sprintf("%%:-%ds", x), str);
}

string trim(string str) {
    string *whitespace;
    int j, i = 0;
 
    j = strlen(str) - 1;
    whitespace = ({ ' ', '\t' });
    while(member_array(str[i], whitespace) != -1) i++;
    while(i < j  && member_array(str[j], whitespace) != -1) j--;
    return str[i..j];
}
/* #define NEW_WRAP */
#ifndef NEW_WRAP
varargs string wrap(string str, int x) {
    if( !x ) {
        if( !this_player() ) x = 79;
        else {
            int *tmp;

            tmp = (int *)this_player()->GetScreen();
            if( tmp ) x = (tmp[0] || 79);
            else x = 79;
        }
    }
    return sprintf("%-=" + x + "s\n", str);
}
#else
varargs string wrap(string str, int x) {
    string ret = "";
    int len;

    if(find_player("descartes"))
      message("system", str, find_player("descartes"));
    if( !x ) {
	if( !this_player() ) x = 79;
	else x = ((int *)this_player()->GetScreen())[0] || 79;
    }
    else if( x < 5 ) return str;
    while( (len = strlen(str)) >= x ) {
	int i, count, ignore, actual;

	for(i=0, count = 0, actual = 0; i<len; i++) {
	    int pt;

	    ret = ret + str[i..i];
	    if( str[i] == '\n' ) {
		str = str[i+1..];
		break;
	    }
	    actual++;
	    if( ignore ) {
		if( ignore == 1 && str[i] != '%' ) continue;
		if( i == len-1 ) continue;
		else if( ignore == 1 ) {
		    if( str[i+1] != '^' ) continue;
		    if( i == len-2 || str[i+2] != '^' ) {
			ignore = 2;
			continue;
		    }
		    continue;
		}
		else {
		    ignore = 0;
		    continue;
		}
	    }
	    else {
		if( i != len-1 ) count++;
		else if( str[i] != '%' ) count++;
		else if( str[i+1] != '^' ) count++;
		else {
		    if( i == len-2 || str[i+2] != '^' ) {
			ignore = 1;
			continue;
		    }
		    count++;
		}
	    }
	    if( count < x ) continue;
	    if( count == x ) {
		int no_whitespace;

		pt = actual;
		write(ret[<1..<1] + " : " + str[(pt-1)..(pt-1)]);
		if( str[pt-1] == ' ' || str[pt-1] == '-' ) {
		    if( str[pt-1] == '-' ) ret = ret[0..<2] + "\n";
		    if( pt < len-2 && str[pt] == ' ' ) {
			if( pt < len-3 ) str = str[pt+1..];
			else str = "";
		    }
		    else if( pt < len-2 ) str = str[pt..];
		    else str = "";
		    break;
		}
		else if( pt < len-1 && (str[pt] == ' ' || str[pt] == '\n') ) {
		    if( pt < len-2 ) str = str[pt+1..];
		    else str = "";
		    break;
		}
		else {
		    no_whitespace = 1;
		    while( --pt ) {
			int ch;
			
			ch = str[pt-1];
			if( ch == ' ' || ch == '-' ) {
			    ret = ret[0..<(actual-pt+1)] + "\n";
			    str = str[pt..];
			    no_whitespace = 0;
			    break;
			}
		    }
		    if( !no_whitespace ) break;
		}
	    }
	    else if( str[actual-1] == ' ' || str[actual-1] == '-' ) {
		ret = ret[0..<2] + "\n";
		str = str[actual..];
		break;
	    }
	}
    }
    return ret + str + "\n";
}
#endif    
varargs mixed convert_string(string str, int flag) {
    mixed *ret = ({ 0, "" });

    if( (str = trim(str)) == "" ) return 0;
    if( str[0] == '(' ) {
	switch(str[1]) {

	    case '{':

	    ret[0] = ({});
	    str = str[2..];
	    while(str[0] != '}') {
		mixed *tmp;

		tmp = convert_string(str, 1);
		ret[0] += ({ tmp[0] });
		str = tmp[1];
		while(str[0] == ' ' || str[0] == '\t') str = str[1..];
		if( str[0] != ',' && str[0] != '}' )
		  error("Improperly formatted array: " + str + "\n");
		else if( str[0] == ',') {
		    str = str[1..];
		    while(str[0] == ' ' || str[0] == '\t') str = str[1..];
		}
	    }
	    if( str[1] != ')' ) {
		str = str[2..];
		while(str[0] == ' ' || str[0] == '\t') str = str[1..];
		if( str[0] != ')' ) error("Illegal array terminator.\n");
		else ret[1] = str[1..];
	    }
	    else ret[1] = str[2..];
	    if( !flag ) return ret[0];
	    while(ret[1][0] == ' ' || ret[1][0] == '\t') ret[1] = ret[1][1..];
	    return ret[0];

	    case '[':

	    ret[0] = ([]);
	    str = str[2..];
	    while(str[0] != ']') {
		mixed *tmp;
		mixed cle, val;

		tmp = convert_string(str, 1);
		str = tmp[1];
		while(str[0] == ' ' || str[0] == '\t') str = str[1..];
		if( str[0] != ':' ) 
		  error("Illegally formatting mapping: " + str + "\n");
		cle = tmp[0];
		tmp = convert_string(str[1..], 1);
		ret[0][cle] = tmp[0];
		str = tmp[1];
		while(str[0] == ' ' || str[0] == '\t') str = str[1..];
		if( str[0] != ',' && str[0] != ']' ) 
		  error("Illegally formatted mapping: " + str + "n");
		else if( str[0] != ']' ) {
		    str = str[1..];
		    while(str[0] == ' ' || str[0] == '\t') str = str[1..];
		}
	    }
	    if( str[1] != ')' ) {
		str = str[2..];
		while(str[0] == ' ' || str[0] == '\t') str = str[1..];
		if( str[0] != ')' ) error("Illegal array terminator.\n");
		else ret[1] = str[1..];
	    }
	    else ret[1] = str[2..];
	    if( !flag ) return ret[0];
	    while(ret[1][0] == ' ' || ret[1][0] == '\t') ret[1] = ret[1][1..];
	    return ret;
        }
    }
    else if( str[0] == '"' ) {
	string tmp;

	tmp = "";
	while( str[1] != '"' || (str[1] == '"' && str[0] == '\\') ) {
	    if( str[1] == '"' ) tmp = tmp[0..<2] + "\"";
	    else tmp += str[1..1];
	    str = str[1..];
	}
	if( !flag ) return tmp;
	if( strlen(str) > 2 ) str = trim(str[2..]);
	return ({ tmp, str });
    }
    else if( str[0] >= '0' && str[0] <= '9') {
	string tmp;
	int y;

	if( strlen(str) > 1 && str[0..1] == "0x" ) {
	    tmp = "0x";
	    str = str[2..];
	    while(str != "" && (str[0] >= '0' && str[0] <= '9')) {
		tmp += str[0..0];
		if( strlen(str) > 1 ) str = str[1..];
		else str = "";
	    }
	    sscanf(tmp, "%x", y);
	}
	else {
	    tmp = "";
	    while(str != "" && (str[0] >= '0' && str[0] <= '9')) {
		tmp += str[0..0];
		if( strlen(str) > 1 ) str = str[1..];
		else str = "";
	    }
	    sscanf(tmp, "%d", y);
	}
	if( !flag ) return y;
	if( str != "" ) str = trim(str);
	return ({ y, str });
    }
    else {
	string tmp;

	tmp = "";
	while(strlen(str) && ((str[0] >= 'a' && str[0] <= 'z') ||
			      (str[0] >= 'A' && str[0] <= 'Z') ||
			      (str[0] >= '0' && str[0] <= '9') ||
			      (str[0] == '_'))) {
	    tmp += str[0..0];
	    if( strlen(str) > 1 ) str = str[1..];
	    else str = "";
	}
	if( !flag ) return to_object(tmp);
	else return ({ to_object(tmp), str });
    }
    error("Gobbledygook in string.\n");
}
