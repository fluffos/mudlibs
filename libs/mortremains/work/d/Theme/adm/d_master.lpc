// This is a customized domain master objects.
// See the original file that this inherits for more information.  -- Buddha

inherit "/adm/obj/master/d_master";

void create() {
    group_list = ([
    getuid() : "objects", // these are the domain's objects.
    "spooner" : "admin",
  ]);

    permission_list = ([
    "admin" : ([ "/" : "rw" ]),
    "objects"     : ([ "logs" : "rw", "data" : "rw", "/" : "r-" ]),
    "non-members" : ([ "/" : "r-", "adm" : "--" ]),
  ]);
}

