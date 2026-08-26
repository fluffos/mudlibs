/*    /secure/sefun/security.c
 *    from Nightmare 3.3
 *    returns the file privs for any file or directory
 *    created by Descartes of Borg 940903
 */

#include <privs.h>

string file_privs(string file) {
    string *path;
    string ret;

    if(file[0..1] == "//") file = file[1..];
    if(!sizeof(path = explode(file, "/"))) ret = 0;
    else {
    switch(path[0]) {
        case "adm": ret =  PRIV_SECURE;break;
        case "cmds": ret =  PRIV_CMDS;break;
        case "daemon": ret =  PRIV_MUDLIB;break;
        case "estates": ret =  PRIV_GENERAL;break;
        case "lib": ret =  PRIV_GENERAL;break;
        case "secure": ret =  PRIV_SECURE;break;
        case "shadows": ret =  PRIV_GENERAL;break;
        case "www": ret =  PRIV_WWW;break;
        case "realms":
          if(sizeof(path) > 2) ret =  lower_case(path[2]);
          else ret =  0;
          break;
        case "domains":
          if(sizeof(path) > 1) ret =  capitalize(lower_case(path[1]));
          else ret =  0;
          break;
        default: ret =  0;
    }
    }
    //this_object()->tc("file_privs: "+file+" : "+ret);
    return ret;
}

int member_group(mixed who, string grp) {
    string *ppl;

    if(objectp(who)) who = (string)who->GetKeyName();
    if(!(ppl = (string *)master()->query_group(grp))) return 0;
    return (member_array(who, ppl) != -1);
}

mixed unguarded(function f) { return (mixed)master()->apply_unguarded(f); }
