#include <debug2.h>
/*    /std/access.c
 *    from Nightmare 3.2.2
 *    an inheritable daemon for giving out access
 *    created by Descartes of Borg 940918
 */

#include <std.h>

inherit DAEMON;

function __ReadFunction, __WriteFunction;
mapping __ReadAccess, __WriteAccess;

void create() {
    daemon::create();
    if(unguarded((: file_exists, base_name(this_object())+__SAVE_EXTENSION__ :)))
      unguarded((: restore_object, base_name(this_object()) :));
    if(!__ReadAccess) __ReadAccess = ([]);
    if(!__WriteAccess) __WriteAccess = ([]);
}

nomask int check_access(object ob, string fun, string file, string oper) {
    string *who;
    mapping access;
    int x;

    if(oper == "read") {
        if(functionp(__ReadFunction) && ((int)(*__ReadFunction)(ob,fun,file)))
          return 1;
        else access = __ReadAccess;
    }
    else {
        if(functionp(__WriteFunction)) {
            x = (int)(*__WriteFunction)(ob, fun, file);
             if(x) {
                  return 1;
              }
        }
        access = __WriteAccess;
    }
    if(!pointerp(who = match_path(access, file))) return 0;
    return (member_array((string)ob->query_name(), who) != -1);
}

nomask int grant_access(string type, string file, string who) {
    if(type == "read") {
        if(__ReadAccess[file])
          __ReadAccess[file] = distinct_array(__ReadAccess[file] + ({who}));
        else __ReadAccess[file] = ({ who });
        if(!save_object(base_name(this_object()))) this_object()->remove();
        return 1;
    }
    else if(type != "write") return 0;
    if(__WriteAccess[file])
      __WriteAccess[file] = distinct_array(__WriteAccess[file] + ({ who }));
    else __WriteAccess[file] = ({ who });
    if(!save_object(base_name(this_object()))) this_object()->remove();
    return 1;
}

nomask int remove_access(string type, string file, string who) {
    if(type == "read") {
        if(!__ReadAccess[file]) return 0;
        else __ReadAccess[file] -= ({ who });
        if(!save_object(base_name(this_object()))) this_object()->remove();
        return 1;
    }
    else if(type != "write") return 0;
    if(!__WriteAccess) return 0;
    else __WriteAccess[file] -= ({ who });
    if(!save_object("/"+__DIR__"access")) this_object()->remove();
    return 1;
}

protected void set_access(string type, function f) {
    if(type == "read") __ReadFunction = f;
    else __WriteFunction = f;
}

mapping query_access(string type) {
    if(type == "read") return copy(__ReadAccess);
    else return copy(__WriteAccess);
}
