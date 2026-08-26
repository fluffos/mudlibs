/*    /lib/virtual.c
 *    from Nightmare 3.3
 *    inheritable compiler for virtual objects
 *    created by Descartes of Borg 941001
 */


object compile_object(string file) {
    object ob;

    if(virtualp(this_object())) return 0;
    (ob = new(file_name(this_object())))->set_virtual(file);
    return ob;
}
