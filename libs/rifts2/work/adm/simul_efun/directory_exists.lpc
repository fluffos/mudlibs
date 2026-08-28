/*    /secure/sefun/files.c
 *    from Dead Souls 3.3
 *    functions which handle file operations
 *    created by Descartes of Borg 940926
 */

int directory_exists(string str){
    seteuid(geteuid(previous_object()));
    if(!str || (sizeof(str) < 2 && str != "/")) return 0;
    return (file_size(str) == -2);
}