/*    /std/storage.c
 *    from Nightmare IV
 *    the standard object for storing things
 *    created by Descartes of Borg 940212
 */

#include <std.h>
#include "storage.h"

inherit CONTAINER;

private int __CanClose, __CanLock;
private string __Key;
nosave private int __Closed, __Locked;

void init() {
    ::init();
    add_action("Get", "get");
    add_action("Put", "put");
    add_action("Open", "open");
    add_action("Close", "close");
    add_action("Lock", "lock");
    add_action("Unlock", "unlock");
}

void create() {
    container::create();
    __CanClose = 0;
    __Closed = 0;
}

protected  int Put(string str) {
    object ob;
    string what, where;
    int tmp;

    if(!str) return 0;
    if(effective_light(this_player()) < -1)
      return notify_fail("It is too dark.\n");
    if(sscanf(lower_case(str), "%s in %s", what, where) != 2) return 0;
    if(present(where, environment(this_player())) != this_object() &&
      present(where, this_player()) != this_object()) return 0;
    if(!(ob = present(what, this_player()))) return 0;
    if(ob == this_object()) {
        message("my_action", "You cannot change the laws of physics.",
          this_player());
        return 1;
    }
    if(!((int)ob->allow_put(this_player()))) return 1;
    if(!((int)ob->allow_drop(this_player()))) return 1;
    if(tmp = (int)ob->move(this_object())) {
        if(query_closed())
          message("my_action", sprintf("The %s is closed.", query_name()),
            this_player());
        else message("my_action", "You cannot fit it in there.",this_player());
        return 1;
    }
    message("my_action", sprintf("You put %s into %s.",
      (string)ob->query_short(), query_short()), this_player());
    message("other_action", sprintf("%s puts %s into %s.",
      (string)this_player()->query_cap_name(), (string)ob->query_short(),
      query_short()), environment(this_player()), ({this_player()}));
    return 1;
}

protected  int Get(string str) {
    object *things;
    object ob;
    string what, where;
    int tmp, i;

    if(!str) return 0;
    if(effective_light(this_player()) < 1)
      return notify_fail("It is too dark.\n");
    if(sscanf(lower_case(str), "%s from %s", what, where) != 2) return 0;
    if(present(where, environment(this_player())) != this_object() &&
      present(where, this_player()) != this_object()) return 0;
    if(what == "all")
      i = sizeof(things = all_inventory(this_object()));
    else if(!(ob = present(what, this_object()))) {
        message("my_action", "There is no such thing in there!",this_player());
        return 1;
    }
    else {
        i = 1;
        things = ({ ob });
    }
    if(query_closed()) {
        message("my_action", sprintf("%s is closed.",
          capitalize(query_short())), this_player());
        return 1;
    }
    while(i--) {
        if(!((int)things[i]->allow_get(this_player()))) continue;
        message("my_action", sprintf("You get %s from %s.",
          (string)things[i]->query_short(), query_short()), this_player());
        message("other_action", sprintf("%s gets %s from %s.",
          (string)this_player()->query_cap_name(), (string)things[i]->query_short(),
          query_short()), environment(this_player()), ({this_player()}));
        if((int)things[i]->move(this_player())) {
            message("my_action", "You cannot carry that!", this_player());
            things[i]->move(environment(this_player()));
            message("other_action", sprintf("%s drops %s.",
              (string)this_player()->query_cap_name(), (string)things[i]->query_short()),
              environment(this_player()), ({ this_player() }));
        }
    }
    return 1;
}

protected  int Open(string str) {
    if(!str) return 0;
    if(!query_can_close()) return 0;
    if(present(str =lower_case(str), this_player()) != this_object() &&
      present(str, environment(this_player())) != this_object()) return 0;
    if(!query_closed()) {
        message("my_action", "It is already open!", this_player());
        return 1;
    }
    if(query_locked()) {
        message("my_action", "It is locked.", this_player());
        return 1;
    }
    set_closed(0);
    message("my_action", sprintf("You open %s.", query_short()),this_player());
    message("other_action", sprintf("%s opens %s.",
      (string)this_player()->query_cap_name(), query_short()),
      environment(this_player()), ({ this_player() }));
    return 1;
}

int Close(string str) {
    if(!str || !query_can_close()) return 0;
    if(present(str =lower_case(str), this_player()) != this_object() &&
      present(str, environment(this_player())) != this_object()) return 0;
    if(query_closed()) {
        message("my_action", "It is already closed.", this_player());
        return 1;
    }
    set_closed(1);
    message("my_action", sprintf("You close %s.", query_short()),
      this_player());
    message("other_action", sprintf("%s closes %s.",
      (string)this_player()->query_cap_name(), query_short()),
      environment(this_player()), ({ this_player() }));
    return 1;
}

int Lock(string str) {
    object ob;
    string what;

    if(!str || !query_can_close() || !query_can_lock()) return 0;
    if(__Key) {
        sscanf(str, "%s with %s", str, what);
        if(!what || !(ob = present(what, this_player())))
          return notify_fail("Lock it with what?\n");
        else if(ob != present(__Key, this_player()))
          return notify_fail("It does not work.\n");
    }
    if(present(str = lower_case(str), this_player()) != this_object() &&
      present(str, environment(this_player())) != this_object()) return 0;
    if(!query_closed()) {
        message("my_action", "It must be closed before you can lock it.",
          this_player());
        return 1;
    }
    if(query_locked()) {
        message("my_action", "It is already locked!", this_player());
        return 1;
    }
    message("my_action", sprintf("You lock %s.", query_short()),
      this_player());
    message("other_action", sprintf("%s locks %s.",
      (string)this_player()->query_cap_name(), query_short()),
      environment(this_player()), ({ this_player() }));
    set_locked(1);
    return 1;
}

protected  int Unlock(string str) {
    object ob;
    string what;

    if(!str || !query_can_close() || !query_can_lock()) return 0;
    if(__Key) {
        sscanf(str, "%s with %s", str, what);
        if(!what || !(ob = present(what, this_player())))
          return notify_fail("Unlock it with what?\n");
        else if(ob != present(__Key, this_player()))
          return notify_fail("It does not work.\n");
    }
    if(!query_locked()) {
        message("my_action", "It is not locked.", this_player());
        return 1;
    }
    set_locked(0);
    message("my_action", sprintf("You unlock %s.", query_short()),
      this_player());
    message("other_action", sprintf("%s unlocks %s.",
      (string)this_player()->query_cap_name(), query_short()),
      environment(this_player()), ({ this_player() }));
    return 1;
}

int pick_lock() {
    if(!query_can_lock()) return 0;
    set_locked(!query_locked());
    return 1;
}

varargs string query_long(string str) {
    string tmp;

    tmp = container::query_long(str);
    if(query_closed()) tmp +="\nIt is closed.";
    else tmp = sprintf("%s\nContents:\n%s%s", tmp,
      describe_item_contents(({})), (str = describe_living_contents(({}))) != "" ?
      "\n"+str : "");
    return tmp;
}

varargs int receive_objects(object ob) {
    if(query_closed()) return 0;
    return container::receive_objects(ob);
}

void set_can_close(int x) { __CanClose = x; }

int query_can_close() { return __CanClose; }

void set_can_lock(int x) { __CanLock = x; }

int query_can_lock() { return __CanLock; }

void set_closed(int x) { __Closed = x; }

int query_closed() { return query_can_close() && __Closed; }

void set_locked(int x) { __Locked = x; }

int query_locked() { return query_can_lock() && __Locked; }

void set_key(string str) { __Key = str; }

string query_key() { return __Key; }
