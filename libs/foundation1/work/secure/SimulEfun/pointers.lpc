/*    /adm/SimulEfun/pointers.c
 *    from Nightmare IV
 *    SimulEfuns for testing things
 *    created by Descartes of Borg 940213
 */


int ambassadorp(object ob) {
    if(!ob) ob = previous_object();
    return (userp(ob) && member_group(ob, "ambassador"));
}

int adminp(object ob) {
    string str;

    if(!ob) ob = previous_object();
    if(!creatorp(ob)) return 0;
    return (member_group(ob, "assist") || member_group(ob, "SECURE"));
}

int hiddenp(object ob) {
    if(!objectp(ob)) error("Bad argument 1 to hiddenp().\n");
    return !find_object(file_name(ob));
}

varargs int creatorp(object ob) { 
    if( !ob ) ob = previous_object();
    return userp(ob);
}

int high_mortalp(object ob) {
    if(!ob) ob = previous_object();
    return (!creatorp(ob) && ((int)ob->query_level() > 19));
}

