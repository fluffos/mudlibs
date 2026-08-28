// 	/adm/simul_efun/article.c
// 	from DarkeMUD lib
//	returns the supplied string with the proper
//	indefinite article on the beginning.  Singular case only.
//	-Diewarzau 3/22/94

#define EXCEPTIONS ([ "hour":"an", "use":"a", "european":"a", "18":"an", "11":"an" ])

string article(string str) {
    string *except;
    string tmp;
    int i;

    tmp = explode(str," ")[0];
    if((i=member_array(lower_case(tmp), (except = keys(EXCEPTIONS)))) > -1)
	return EXCEPTIONS[except[i]] + " " + str;
    switch(lower_case(str[0..0])) {
	case "a":
	case "e":
	case "i":
	case "o":
	case "u":
	case "8":
	return "an "+str;
	break;
	default:
	return "a "+str;
    }
}
