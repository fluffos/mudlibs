// 	/adm/simul_efun/article.c
// 	from DarkeMUD lib
//	returns the supplied string with the proper
//	indefinite article on the beginning.  Singular case only.
//	-Diewarzau 3/22/94

#define EXCEPTIONS ([ "hour":"an", "use":"a", "european":"a" ])

string article(string str) {
    string *except;
    int i;

    if((i=member_array(lower_case(str), (except = keys(EXCEPTIONS)))) > -1)
	return EXCEPTIONS[except[i]] + " " + str;
    switch(lower_case(str[0..0])) {
	case "a":
	case "e":
	case "i":
	case "o":
	case "u":
	return "an "+str;
	break;
	default:
	return "a "+str;
    }
}
