// This is a customized domain master objects.
// See the original file that this inherits for more information.  -- Buddha

inherit "/adm/obj/master/d_master";

void create() {

    // Group List is the variable that calls to see what group a user
    // belong in for your domain.  The groups are defined in the 
    // permission list.  The permission list is simply a mapping
    // that contains the groups, followed by a maping conainting
    // their access to individual directories.
    // ie - "non-members" : <- Group for non-Domain members.
    //    ([ "-" : "r-",  <-- This line says read access only to /
    //    "adm" : "--", <-- This line says no read or write to "adm"
    //  ]) 
    group_list = ([
    getuid() : "objects", // these are the domain's objects.
    "herself" : "admin",
    "tyran" : "tyran",
    "nemar" : "nemar",
  ]);

    permission_list = ([
    "admin" : ([ "/" : "rw" ]),
    "objects"     : ([ "logs" : "rw", "data" : "rw", "/" : "r-" ]),
    "non-members" : ([ "/" : "r-", "adm" : "--" ]),
    "tyran" : ([ "/" : "r-", "adm" : "--", "City" : "rw" ]),
    "nemar" : ([ "/" : "r-", "adm" : "--" , "City" : "rw" , "Eloria" : "rw"]),
  ]);
}

