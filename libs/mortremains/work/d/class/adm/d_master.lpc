// This is a customized domain master object.
// See the original file that this inherits for more information.  -- Buddha

#define STD_ACCESS "/" : "r-", "wizard/undone" : "--"
inherit "/adm/obj/master/d_master";

void create() {
    group_list = ([
    getuid()    : "objects", // these are the domain's objects
    "uliver" : "rogue",
  ]);

    permission_list = ([
    "objects"     : ([ "logs" : "rw", "data" : "rw", "/" : "r-" ]),
    "non-members" : ([ "/":"r-", "wizard/undone":"--"]),
    "admin" : ([ "/" : "rw" ]),
    "rogue" : ([ STD_ACCESS, "rogue" : "rw" ]),
  ]);
}
