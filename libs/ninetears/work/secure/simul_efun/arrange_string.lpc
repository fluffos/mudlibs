//	/adm/simul_efun/arrange_string.c
//	from the Nightmare mudlib
//	makes a string a certain length
//	created by Descartes of Borg 23 december 1992

string arrange_string(string str, int x) {
    int i, y;

    if(!str || str == "") return "";
    if(!x) return "";
    if(intp(str)) str = str+"";
    y = strlen(str);
    if(y>x) return str[0..(x-1)];
    for(i=y; i<x; i++) str += " ";
    return str;
}
