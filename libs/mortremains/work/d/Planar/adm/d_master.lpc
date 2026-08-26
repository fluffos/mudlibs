// This is a customized domain master objects.
// See the original file that this inherits for more information.  -- Buddha

#define STD_ACCESS "/" : "r-", "adm" : "--"

inherit "/adm/obj/master/d_master";

void create() {
    group_list = ([
    getuid() : "objects", // these are the domain's objects.
    "nsd" : "nazi",
  ]);

    permission_list = ([
    "admin" : ([ "/" : "rw" ]),
    "objects"     : ([ "logs" : "rw", "data" : "rw", "/" : "r-",
    "Macrosoft/std" : "rw" ]),
    "non-members" : ([ "/" : "r-", "adm" : "--" ]),
    "nazi" : ([ STD_ACCESS, "Abyss/Nazi" : "rw" ]),
  ]);
}

