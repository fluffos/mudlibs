// This is a customized domain master objects.
// See the original file that this inherits for more information.  -- Buddha

#define STD_ACCESS "/" : "r-", "adm" : "--"

inherit "/adm/obj/master/d_master";

void create() {
    group_list = ([
    getuid() : "objects", // these are the domain's objects.
    "cattt" : "cattt",
    "panzergiest" : "panz",
    "ellie" : "ellie",
    "brienn" : "carnival",
    "ariana" : "carnival",
    "valkyrie" : "valkyrie",
    "herself" : "herself",
    "blood" : "blood",
    "dalceon" : "dalceon",
  ]);

    permission_list = ([
    "admin" : ([ "/" : "rw" ]),
    "objects"     : ([ "logs" : "rw", "data" : "rw", "/" : "r-",
    "Macrosoft/std" : "rw" ]),
    "non-members" : ([ "/" : "r-", "adm" : "--" ]),
    "herself" : ([ STD_ACCESS, "Mall" : "rw" ]),
    "valkyrie" : ([ STD_ACCESS, "Kyrie" : "rw", "Magehouse" : "rw" ]),
    "kyrie" : ([ STD_ACCESS, "Kyrie" : "rw" ]),
    "panz" : ([ STD_ACCESS, "Asylum" : "rw" ]),
    "carnival" : ([ STD_ACCESS, "Carnival" : "rw" ]),
    "dalceon" : ([ STD_ACCESS, "Tokyo" : "rw" ]),
    "blood" : ([ STD_ACCESS, "Magehouse" : "rw" ]),
    "ellie" : ([ "/" : "r-", "adm":"--","Park":"rw" ]),
    "cattt" : ([ "/" : "r-", "Crackhouse" : "rw", "adm" : "--",
    "Sewers" : "rw" ]),
  ]);
}

