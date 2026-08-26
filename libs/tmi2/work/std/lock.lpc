// lock.c
// A standard inheritable lock object.
// Written by Dk@TMI-2, 12-13-92
// Mobydick made some small changes getting it moved into /std.
// This file used to inherit OBJECT. It seems preferable to let the locked
// object inherit OBJECT (or something that inherits it, like CONTAINER)
// rather than rely on the lock for these functions.

// These have to be prototyped now that OBJECT isn't inherited.

mixed query (string str) ;
int set (string str, mixed val) ;

// These also need to be prototyped.

int lock_func(string str);
void pick_lock(object ob, int n);

int lock(int n) {
    object ob;
    string str;
    
    if (n == 0) {
        return query("lock");
    }
    ob = query("current_key");
    if (!ob) {
        str = "none";
    } else {
        str = ob->query("to_lock");
    }
    if (!str || (str != query("key") && !lock_func(str))) {
        return query("lock");
    }
    if (str == query("key") || lock_func(str)) {
        if (n == -1) {
            if (query("lock") == -1) {
                write ("Already unlocked!\n");
                return -1;
            }
            if (query("lock") == 0) {
                notify_fail ("What?\n");
                return 0;
            }
            set("lock", query("lock") - (int)ob->query("lock_turn"));
            if (query("lock") < 1) {
                say (this_object()->query("short")+" unlocks with a click.\n");
                set("lock", -1);
                return -1;
            } else {
                write ("You fail!\n");
                say (this_player()->query("name")+" fails!\n");
            }
            return query("lock");
        }
        if (n == 0) {
            write ("Try as you might, you can't break this lock.\n");
            return query("lock");
        }
        if (n > ob->query("lock_turn") && n > 0)  n = ob->query("lock_turn");
        if (n > query("max_lock"))  n = query("max_lock");
        if (query("lock") == -1 && n > 0)  say ("The lock clicks shut.\n");
        set("lock", n);
        return n;
    }
    if (str == "none"); {
        pick_lock(this_player(), n);
    }
    return query("lock");
}

int lock_func(string str) {
    if (str == "skeleton")  return 1;
    return 0;
}

void pick_lock(object me, int n) {
    set("lock", n);
}

int lock_object(string str) {
    string str2, str3;
    object ob;
    
    if (!str) {
        notify_fail("Lock what?\n");
        return 0;
    }
    if (sscanf(str, "%s with %s", str2, str3) == 2) {
        ob = present(str3, this_player());
        if (!ob)
            ob = present(str3, environment(this_player()));
        if (ob) {
            set("current_key", ob);
            if (query("lock") == query("max_lock")) {
                write ("It's already fully locked!\n");
                return 1;
            }
	    if (member_array(str2,(string *)query("id"))==-1) {
		// Not for this object.
		return 0 ;
	    }
	    if ((int)this_object()->query_is_closed()==0) {
		notify_fail ("You can't lock it unless it's closed.\n") ;
		return 0 ;
	    }
            write ("You lock "+str2+" with "+str3+".\n");
            say (this_player()->query("name")+" locks "+str2+" with "+str3+".\n");
            lock((int)ob->query("lock_turn"));
            if (query("lock") <= 0) {
                write ("You fail!\n");
                say (this_player()->query("name")+" fails!\n");
            }
            return 1;
        }
        write ("I can't seem to find "+str3+" here...\n");
        return 1;
    }
    write ("How?\n");
    return 1;
}

int unlock_object(string str) {
    string str2, str3;
    object ob;
    
    if (!str) {
        notify_fail("Unlock what?\n");
        return 0;
    }
    if (sscanf(str, "%s with %s", str2, str3) == 2) {
        ob = present(str3, this_player());
        if (!ob)
            ob = present(str3, environment(this_player()));
        if (ob) {
            set("current_key", ob);
            if (query("lock") == -1) {
                write ("It's already unlocked!\n");
                return 1;
            }
            write ("You unlock "+str2+" with "+str3+".\n");
            say (this_player()->query("name")+" unlocks "+str2+" with "+str3+".\n");
            lock(-1);
            if (query("lock") != -1) {
                write ("You fail!\n");
                say (this_player()->query("name")+" fails!\n");
            }
            return 1;
        }
        write ("I can't seem to find "+str3+" here...\n");
        return 1;
    }
    write ("Use your pick skill for that...\n");
    return 1;
}

void init() {
    add_action("lock_object", "lock");
    add_action("unlock_object", "unlock");
}

