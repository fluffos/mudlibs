//      /secure/simul_efun/file_exists.c
//      from the RotD Mudlib
//      returns true if the file named exists
//      created by Descartes of Borg 930822

int file_exists(string str) {
    int ret;

    seteuid(geteuid(previous_object()));
    if(file_size(str) > -1) ret = 1;
    else ret = 0;
    seteuid(0);
    return ret;
}
