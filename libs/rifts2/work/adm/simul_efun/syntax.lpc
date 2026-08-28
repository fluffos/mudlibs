/*  /adm/simul_efun/syntax.c
 *  Made for DarkeMUD
 *  Created by Geldron 030296
 *  Copyright (c) 1996, DarkeMUD
 *  Do not remove this header
 */

string syntax(string str) {
    string *tmp;
    int i;

    str = replace_string(str, "[", "%^RESET%^[%^CYAN%^");
    str = replace_string(str, "]", "%^RESET%^%^BOLD%^]");
    tmp = explode(str, " ");
    for(i = 0; i < sizeof(tmp); i++)
	if(allcapp(replace_string(tmp[i], "|", "")))
	    tmp[i] = "%^RESET%^%^GREEN%^" + tmp[i] + "%^RESET%^%^BOLD%^";
    return "Syntax: <%^BOLD%^" + implode(tmp, " ") + "%^RESET%^>";
}
