// This is the default domain master object.
// You may wish to customize it.  See the original file
// that this inherits for more information.  -- Buddha

inherit "/adm/obj/master/d_master";

void create() {
    group_list = ([
        getuid()	: "object", // these are the domain's objects
    ]);

    permission_list = ([
        "object"	: ([ "logs" : "rw", "data" : "rw", "/" : "r-" ]),
        "non-members"   : ([ "/" : "r-" ]),
    ]);
}
