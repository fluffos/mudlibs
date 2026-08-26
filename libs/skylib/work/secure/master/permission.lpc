
varargs mixed creator_file(string path, int author);

nomask int check_domain( mixed ob, string func, string path, int mask ) {
    string domain, euid, *bits = explode(path, "/") - ({ "", "." });

    if( sscanf( path, "/d/%s/%*s", domain ) != 2 )
        return ( mask & READ_MASK );

    if( objectp(ob) )
        ob = geteuid(ob);

    euid = ob;

    // Is it the domain itself?
    if( ob == creator_file(path) )
        return 1;

    if( DOMAIN_H->query_leader( bits[1], euid ) )
        return 1;

    return ( mask & READ_MASK );

} /* check_domain() */

nomask int check_project( mixed ob, string func, string path, int mask ) {
    string project, euid, *bits = explode(path, "/") - ({ "", "." });

    if( sscanf( path, "/p/%s/%*s", project ) != 2 )
        return ( mask & READ_MASK );

    if( objectp(ob) )
        ob = geteuid(ob);

    euid = ob;

    // Is it the project itself?
    if( ob == creator_file(path) )
        return 1;

    if( PROJECT_H->query_leader( bits[1], euid ) )
        return 1;

    return ( mask & READ_MASK );

} /* check_project() */

nomask int check_creator( mixed ob, string func, string path, int mask ) {
    string owner, *bits = explode(path, "/") - ({ "", "." });

    if( sscanf( path, "/w/%s/%*s", owner ) != 2 )
        return ( mask & READ_MASK );

    if( objectp(ob) )
        ob = geteuid(ob);

    // Creators are not allowed to give out write perms to their dirs using
    // the granting system, they should write their own master object if
    // they want to do this.
    if( mask & GRANT_MASK )
        return 0;

    if( sizeof(bits) > 2 )
        if( bits[2] == "secure" && bits[1] != ob )
            return 0;

    // Reading is allowed in creator dirs,
    // and writing is allowed if it's the owner doing it.
    if( ( mask & READ_MASK ) || ( ob == creator_file(path) ) )
        return 1;

    return 0;

} /* check_creator() */


/**
 * Permision handling stuff. Originally coded by Who Knows.
 * This now uses a system based on the previous_object() stack.
 * Coded by Turrican, based on code in the Nightmare Mudlib.
 * - First working version on 7-10-96
 * - Hacked some more on 4-4-97
 */
private int check_permission( mixed ob, string func, string path,
                              mapping perms, int mask ) {
    string tmp, euid;
    int i;
    mixed *stack;

    if( perms && sizeof(perms) && !undefinedp(perms["all"] ) &&
        ( perms["all"] & mask ) )
        return 1;

    if( unguarded_ob == ob ) {
        tmp = base_name(ob);
        if( tmp == "/global/player" || tmp == "/global/creator") {
            if( path == "/save/players/"+ob->query_name()[0..0]+"/"+ob->query_name() ||
                path == "/save/players/"+ob->query_name()[0..0]+"/"+ob->query_name()+".o")
                return 1;
            else
                i = sizeof( stack = ({ ob }) + previous_object(-1) );
        } else if( tmp == path )
            return 1;
        else
            i = sizeof( stack = ({ ob }) );
    } else if( unguarded_ob && base_name(ob) == "/secure/simul_efun") {
        if( unguarded_ob == previous_object(1) )
            i = sizeof( stack = ({ previous_object(1) }) );
        else
            i = sizeof( stack = ({ ob }) + previous_object(-1) );
    } else if( unguarded_ob ) {
        // Okay, unguarded object is not the calling object.
        // We only check the call stack as far back as the position
        // of the unguarded object.
        stack = previous_object(-1);
        for( i = 0; i < sizeof(stack) && stack[i] != unguarded_ob; i++ );
        i = sizeof( stack = ({ ob }) + stack[0..i] );
    } else
        i = sizeof( stack = ({ ob }) + previous_object(-1) );

    while( i-- ) {
        if( !stack[i] )
            return 0;

        if( stack[i] == TO )
            continue;

        if( objectp(stack[i]) ) {
            if( file_name(stack[i]) == "/secure/simul_efun")
                continue;
            if( !( euid = geteuid(stack[i]) ) )
                return 0;
        } else
            euid = stack[i];

        if( euid == get_root_uid() )
            continue;

        if( lordp(euid) && ( mask & READ_MASK ) )
            continue;

        if( adminp(euid) )
            continue;

        if( perms ) {
            if( !undefinedp(perms[euid]) && ( perms[euid] & mask ) )
                continue;

            // If the path is explicitly locked, and the lock isn't overridden
            // by other pemissions, we deny access.
            if( !undefinedp(perms["all"]) && ( perms["all"] & LOCK_MASK ) )
                return 0;
        }

        // Is this a creator directory?
        if( path[0..2] == "/w/") {
            if( check_creator( stack[i], func, path, mask ) )
                continue;
        } else if( path[0..2] == "/d/") {
            // It's a domain directory.
            if( check_domain( stack[i], func, path, mask ) )
                continue;
        } else if( path[0..2] == "/p/") {
            // It's a project directory.
            if( check_project( stack[i], func, path, mask ) )
                continue;
        } else {
            // The rest of the mudlib defaults to reading allowed,
            // unless paths are explitcitly locked, which is handled
            // above.
            return ( mask & READ_MASK );
        }
        return 0;
    }

    return 1;

} /* check_permission() */

mapping query_permissions() { return copy(permissions); }

int valid_grant( object euid, string path, int mask ) {
    string domain, *lords;
    int result;

    if( path[0] != '/')
        path = "/" + path;

    result = check_permission( euid, 0, path,
        match_path( permissions, path ), GRANT_MASK );

    if( result || ( mask & (READ_MASK|WRITE_MASK) ) )
        return result;

    if( sscanf( path, "/d/%s/%*s", domain ) != 2 )
        return 0;

    lords = DOMAIN_H->query_leaders(domain);

    return ( lordp(previous_object(-1) + ({ euid }) ) &&
           ( member_array( lords, map(previous_object(-1),
           (: geteuid($1) :) ) ) != -1 ) );

} /* valid_grant() */

int permission_check() {
    if( file_name(PO) != "/secure/cmds/creator/accesstool" &&
        file_name(PO) != DOMAIN_H ) {
        write("Please use accesstool to add/remove access.\n");
        return 0;
    }

    return 1;

} /* permission_check() */

int add_permission( string euid, string path, int mask ) {
//  if( !valid_grant( euid, path, mask ) ) {
    if( !permission_check() )
        return 0;

    if( !permissions[path] )
        permissions[path] = ([ euid : mask ]);
    else
        permissions[path][euid] |= mask;

    save_object(SAVE_FILE);
    return 1;

} /* add_permission() */

int add_read_permission( string euid, string path ) {
    if( !permission_check() )
        return 0;

    if( add_permission( euid, path, READ_MASK ) ) {
        write("Added read permission for "+euid+" to "+path+".\n");
        return 1;
    }

    return 0;

} /* add_read_permission() */

int add_write_permission( string euid, string path ) {
    if( !permission_check() )
        return 0;

    if( add_permission( euid, path, WRITE_MASK ) ) {
        write("Added write permission for "+euid+" to "+path+".\n");
        return 1;
    }

    return 0;

} /* add_write_permission() */

int add_grant_permission( string euid, string path ) {
    if( !permission_check() )
        return 0;

    if( add_permission( euid, path, GRANT_MASK ) ) {
        write("Added write permission for "+euid+" to "+path+".\n");
        return 1;
    }

    return 0;

} /* add_grant_permission() */

int remove_permission( string euid, string path, int mask ) {
//  if( !valid_grant( euid, path, mask ) ) {
    if( !permission_check() )
        return 0;

    if( !permissions[path] || !permissions[path][euid] ) {
        write("The "+euid+" does not have any permissions to remove in "+
            path+".\n");
        return 0;
    }

    permissions[path][euid] &= ~mask;

    if( !permissions[path][euid] )
        if( sizeof(permissions[path] ) == 1 )
            map_delete( permissions, path );
        else
            map_delete( permissions[path], euid );

    save_object(SAVE_FILE);
    return 1;

} /* remove_permission() */

int remove_read_permission( string euid, string path ) {
    if( !permission_check() )
        return 0;

    if( remove_permission( euid, path, READ_MASK ) ) {
        write("Removed read permission for "+euid+" to "+path+".\n");
        return 1;
    }

    return 0;

} /* remove_read_permission() */

int remove_write_permission( string euid, string path ) {
    if( !permission_check() )
        return 0;

    if( remove_permission( euid, path, WRITE_MASK ) ) {
        write("Removed write permission for "+euid+" to "+path+".\n");
        return 1;
    }

    return 0;

} /* remove_write_permission() */

int remove_grant_permission( string euid, string path ) {
    if( !permission_check() )
        return 0;

    if( remove_permission( euid, path, GRANT_MASK ) ) {
        write("Removed write permission for "+euid+" to "+path+".\n");
        return 1;
    }

    return 0;

} /* remove_grant_permission() */

mixed permission_match_path( mapping m, string path ) {
    string p, *bits;
    int i, size;
    mapping found = ([ ]);

    if( !sizeof(m) )
        return 0;

    bits = explode(path, "/") - ({ "", "." });
    p = "";

    if( !undefinedp(m["/"]) )
        found += m["/"];

    size = sizeof(bits);
    for( i = 0; i <= size; i++ ) {
        if( !undefinedp(m[p]) ) {
            mapping old = copy(found);

            if( sizeof( ( found += m[p] ) ) != ( sizeof(old) + sizeof(m[p]) ) ) {
                string euid;
                int mask;

                found = old;
                foreach( euid, mask in m[p] ) {
                    if( !undefinedp(found[euid]) )
                        found[euid] |= mask;
                    else
                        found[euid] = mask;
                }
            }
        }
        if( i < size )
            p = p+"/"+bits[i];
    }

    if( sizeof(found) ) {
        return found;
    } else {
        return 0;
    }

} /* permission_match_path() */
