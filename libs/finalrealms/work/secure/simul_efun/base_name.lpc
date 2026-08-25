//      /secure/simul_efun/base_name.c
//      from the RotD Mudlib
//      returns the file name of the master copy of an object (no #???)
//      created by Descartes of Borg 930822

string base_name(object ob) {
    string file, tmp;

    seteuid(geteuid(previous_object()));
    if(sscanf(file_name(ob), "%s#%s", file, tmp) != 2) file = file_name(ob);
    seteuid(0);
    return file;
}
