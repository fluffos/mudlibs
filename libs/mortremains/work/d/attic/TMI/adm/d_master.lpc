// This is a customized domain master object.
// See the original file that this inherits for more information.  -- Buddha

inherit "/adm/obj/master/d_master";

void create() {
    group_list = ([
        getuid()    : "objects", // these are the domain's objects
    ]);

    permission_list = ([
        "objects"     : ([ "logs" : "rw", "data" : "rw", "/" : "r-" ]),
        "non-members" : ([ "/" : "r-" ]),
    ]);
}
