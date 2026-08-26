// Privilege handler (/secure/handlers/privilege.c)
// Coded by Donky - 25/09/96
// Modified for use here by Shaydz 14/10/2000

#define SECURITY geteuid(PO)
#define SAVE_FILE "/secure/save/handlers/privilege"

#include <access.h>

mapping privileges;

void save_me() { unguarded( (: save_object, SAVE_FILE :) ); }

void create() {
    string privilege, *people, person;
    int i;

    unguarded( (: restore_object , SAVE_FILE :) );

    if( !mapp(privileges) ) {
        privileges = ([ ]);
    } else {
        foreach( privilege, people in privileges )
            foreach( person in people )
                if( !creatorp( person ) ) {
                    privileges[privilege] -= ({ person });
                    i = 1;
                }
        if( i )
            save_me();
    }

} /* create() */

int query_privilege( string privilege, string privileged ) {
    int flag;
    string *bits, *dirs;

//  TCRE("shaydz",sprintf("privilege=%s, privileged=%s\n",privilege,privileged));

    if( adminp(privileged) )
        return 1;

    // must be at least 2 fields
    if( sizeof( bits = explode( privilege, ".") ) < 2 )
        return 0;

    // allow domain leaders to add & remove members from their domains
    // domain.<domain name>.member.add
    // domain.<domain name>.member.remove
    // allow the leader(s) of the Learning domain to promote creators

    switch( bits[0] ) {
      case "permission":
        // permission.<mask>.<path>.[grant|revoke]
        // e.g. permission.1./secure.add

//        TCRE("shaydz",sprintf("privilege=%s, privileged=%s\n",privilege,privileged));
        if( sizeof(bits) < 4 )
            return 0;

        if( sscanf( bits[1], "%d", flag ) != 1 )
            return 0;

        if( bits[<1] != "grant" && bits[<1] != "revoke")
            return 0;

        dirs = explode( bits[2], "/");
//  TCRE("shaydz",sprintf("flag=%d, dirs=%O\n",flag,dirs));
        // Only admin can grant grant access.
        if( flag & GRANT_MASK )
            return 0;

        if( sizeof(dirs) > 1 ) {
            // A domain leader can grant read and write access to his
            // domain directories, but not grant access.
            if( dirs[0] == "d" &&
                DOMAIN_H->query_leader( dirs[1], privileged ) )
                return 1;

            // A project leader can grant read or write access to his
            // project directories, but not grant access.
            if( dirs[0] == "p" &&
                PROJECT_H->query_leader( dirs[1], privileged ) )
                return 1;

            // A creator can grant read or write access to his home
            // directory but not grant access.
            if( dirs[0] == "w" && dirs[1] == privileged )
                return 1;
        }

        // To grant access of any form, you need to have grant access
        // to the given directory.
        if( master()->valid_grant( privileged, bits[2], to_int(bits[1]) ) )
            return 1;
        return 0;
      case "domain":
        if( bits[2] == "member") {
            if( DOMAIN_H->query_leader( bits[1], privileged ) )
                return 1;
            if( bits[1] == "learning" && lordp(privileged) )
                return 1;
        }
        if( bits[2] == "senior" &&
            DOMAIN_H->query_leader( bits[1], privileged ) )
            return 1;
        break;
      case "project":
        if( bits[2] == "member" &&
            PROJECT_H->query_leader( bits[1], privileged ) )
            return 1;
        if( bits[2] == "senior" &&
            PROJECT_H->query_leader( bits[1], privileged ) )
            return 1;
        break;
      case "creator":
        if( ( bits[1] == "add" || bits[1] == "remove" ) &&
            DOMAIN_H->query_leader("learning", privileged ) )
            return 1;
        break; // The following doesn't work yet.
        if( bits[2] == "p")
            flag = PROJECT_H->query_leader( bits[3], privileged ) ||
                   DOMAIN_H->query_leader("project", privileged );
        else if( bits[2] == "w")
            flag = ( bits[3] == privileged && creatorp(bits[3]) );
        switch( bits[<1] ) {
          case "add":
          case "remove":
          case "modify":
            if( flag )
                return 1;
            break;
        }
        break;
    }

    // If the person is allowed for that privilege, return 1.
    if( arrayp(privileges[privilege]) )
        return member_array( privileged, privileges[privilege] ) != -1;

} /* query_privilege() */

string *query_privileges( string privileged ) {
    string *ret = ({ });
    string privilege, *privilegeds;

    foreach( privilege, privilegeds in privileges )
        if( member_array( privileged, privilegeds ) != -1 )
            ret += ({ privilege });

    return ret;

} /* query_privileges() */

string add_privilege( string privilege, string privileged ) {
    if( !query_privilege("privilege.add", SECURITY) )
        return "Insufficient privilege to grant privileges.";

    if( !arrayp(privileges[privilege]) )
        return "Privilege does not exist.";

    if( query_privilege( privilege, privileged ) )
        return CAP(privileged)+" already has the "+privilege+" privilege.";

    if( !creatorp(privileged) )
        return CAP(privileged) +" is not a creator.";

    privileges[privilege] += ({ privileged });
    save_me();

    return 0;

} /* add_privilege() */

string remove_privilege( string privilege, string privileged ) {
    if( !query_privilege("privilege.remove", SECURITY) )
        return "Insufficient privilege to revoke privileges.";

    if( adminp(privileged) )
        return "You cannot revoke privileges from an admin.";

    if( !arrayp(privileges[privilege]) )
        return "Privilege does not exist.";

    if( member_array( privileged, privileges[privilege] ) == -1 )
        return CAP(privileged)+" does not have the "+privilege+" privilege.";

    privileges[privilege] -= ({ privileged });
    save_me();

    return 0;

} /* remove_privilege() */

string add_privilege_type( string privilege ) {
    if( !query_privilege("privilege.type.add", SECURITY) )
        return "Insufficient privilege to add a privilege type.";

    if( sizeof( explode( privilege, ".") ) < 2 )
        return "Invalid number of fields in privilege name (minimum of 2).";

    if( arrayp(privileges[privilege]) )
        return "Privilege "+ privilege +" already exists.";

    privileges[privilege] = ({ });
    save_me();

    return 0;

} /* add_privilege_type() */

string remove_privilege_type( string privilege ) {
    if( !query_privilege("privilege.type.remove", SECURITY) )
        return "Insufficient privilege to remove a privilege type.";

    if( !arrayp(privileges[privilege]) )
        return "Privilege "+privilege+" does not exist.";

    map_delete( privileges, privilege );
    save_me();

    return 0;

} /* remove_privilege_type() */

string *query_privilege_types() { return keys(privileges); }

nomask void dwep() {
    object my_ob = TO;

    if( my_ob )
        destruct(my_ob);

} /* dwep() */

void dest_me() { dwep(); }
