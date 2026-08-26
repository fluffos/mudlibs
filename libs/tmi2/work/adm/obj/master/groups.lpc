/*
 * parse and load in the group file
 * 
 * wayfarer 2/20/92
 */

// Blue, 950528: added domain EUID to group when domains are
//               in group file, as well as domain members' EUIDs.


#include <config.h>
#include <uid.h>
#include <driver/origin.h>

#define GROUP_FILE "/adm/etc/groups"

private mapping groups;

string remove_whitespace(string members) {
    return ( replace_string(replace_string(members, " ", ""), "\t", "") );
}

int load_groups() {
    string *lines, *tmp, *tmplist, *memlist;
    string str, tmpstr, name, members;
    mapping newgroups;
    object link;
    int i, j, s;

    /*
     * don't reload unless object is updated
     */
    if (groups)
        return 1;

    seteuid(getuid());
#ifdef DEBUG
    write("Seteuid stage completed.  Euid is now " + 
          geteuid(this_object()) + ".\n");
#endif

#ifdef DEBUG
    write("Reading group file.\n");
#endif
    lines = explode(read_file(GROUP_FILE), "\n");

    newgroups = ([ ]);
    str = 0;

#ifdef DEBUG
    write("Processing group file contents.\n");
#endif
    for (i = 0, s = sizeof(lines); i < s; i++) {
        if (lines[i][0] == '#' || lines[i][0] == '\n' || lines[i] == "")
	    continue;

        if (!str)
	    str = lines[i];
        else 
	    str += lines[i];

        if (lines[i][<1] != ':')  {
            if (sscanf(str, "(%s)%s", name, members) == 2) {
                tmp = explode(remove_whitespace(members) + ":", ":");
                memlist = ({ });

                j = sizeof(tmp);
                while (j--) {
                    if (tmp[j][0] == '(') {
                        /*
                         * process groups
                         */
	                sscanf(tmp[j], "(%s)", str);
                        
                        if (!newgroups[str]) {
                            write(sprintf(
"Parse error in group: %s\nGroup %s not defined.\nAborting parse.\n",
                                  name, tmp[j]));
		            return 0;
                        }

                        tmplist = newgroups[str];
                        memlist += tmplist - (memlist & tmplist);
        	    } else if (tmp[j][0] == '[') {
        	        /*
        	         * process domains
        	         */
                        sscanf(tmp[j], "[%s]", str);
                        if (!(tmpstr = domain_master(lower_case(str))))
                            tmpstr = domain_master(capitalize(str));

                        if (!tmpstr || !(link = load_object(tmpstr))) {
                            write(sprintf(
"Parse error in group: %s\nDomain %s not defined.\nAborting parse.\n",
                                  name, tmp[j]));
		            return 0;
                        }

                        tmplist = link->query_domain_members();
                        memlist += tmplist - (memlist & tmplist) + ({ capitalize(str) });
#ifdef DEBUG
                        write(sizeof(memlist)+" elements in memlist: \n"+identify(memlist));
#endif
                    } else {
                        /*
                         * check user hasn't been purged
                         */
                        if (member_array(tmp[j], memlist) == -1) {
                            if (file_size(sprintf(PDATA_DIR "%c/%s.o",
                                  tmp[j][0], tmp[j])) > 0 )
    	                        memlist += ({ tmp[j] });
    	                    else {
                                write(sprintf(
"Parse error in group: %s\nUser %s not found.\nContinuing parse.\n",
                                  name, tmp[j]));
                            }
                        }
                    }
                }
            }

#ifdef DEBUG
            write("Adding a new mapping to the group mapping.\n");
#endif
            newgroups += ([ name : memlist]);
            str = 0;
	}
    }

    // overwrite "groups" mapping only if everything succeeded
    groups = newgroups;

    return 1;
}

mapping query_groups() {
#if 0
    // optimization?
    if (origin() != ORIGIN_LOCAL && geteuid(previous_object()) == ROOT_UID)
        return groups;
#endif
    return ( copy(groups) );
}

int query_member_group(string member, string group) {
    if (!load_groups()) {
        write("*Error in loading groups list\n");
        return 0;
    }

    if (groups[group])
        return ( member_array(member, groups[group]) + 1 );
    else
        return 0;
}
