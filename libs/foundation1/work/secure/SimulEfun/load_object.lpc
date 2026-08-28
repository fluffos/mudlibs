/*    /adm/simul_efun/load_object.c
 *    from Nightmare IV
 *    find and object and return it, or load an object and return it
 *    created by Descartes of Borg 940213
 */


object load_object(string str) {
    object ob;
    //tc("str: "+str);
    if(!stringp(str)) error("Bad argument 1 to load_object().\n");
    if(ob = find_object(str)){
        //tc("ob already exists: "+identify(ob));
        return ob;
    }
    catch(call_other(str, "???"));
    ob = find_object(str);
    //tc("load_object("+identify(str)+"): "+identify(ob));
    return ob;
}
