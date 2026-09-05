/* Authored by Balowski */

string basename(mixed ob) {
    string fname, no;

    if (objectp(ob)) fname = file_name(ob);
    else if (stringp(ob)) fname = ob;
    else return 0;

    sscanf(fname, "%s#%s", fname, no);
    if (fname[0] != '/') return ("/" + fname);
 
    return fname;
}
