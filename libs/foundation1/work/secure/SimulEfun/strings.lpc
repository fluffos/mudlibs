/*    /adm/SimulEfun/strings.c
 *    from Nightmare IV
 *    SimulEfuns for string manipulation
 *    created by Descartes of Borg 940506
 */

varargs string center(string str, int x) {
    int y;

    if(!x) x= 80;
    if((y = strlen(strip_colours(str))) >= x) return str;
    x = x + strlen(str) - y;
    return sprintf(sprintf("%%\|%ds", x), str);
}

varargs string arrange_string(string str, int x) {
    int y;

    if(!x) x = 80;
    x += strlen(str) - strlen(strip_colours(str));
    return sprintf(sprintf("%%:-%ds", x), str);
}

varargs string wrap(string str, int x) {
    return sprintf(sprintf("%%-=%ds\n", (x ? x : 75)), str);
}
