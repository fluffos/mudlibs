// This is a customized domain master objects.
// See the original file that this inherits for more information.  -- Buddha

inherit "/adm/obj/master/d_master";

void create() {
    group_list = ([
    getuid() : "objects", // these are the domain's objects.
    "darkangel" : "admin",
    "iuz" : "Iuz",
    "dilligaf" : "Dagaard",
    "draconis" : "Krynn",
    "morrigu" : "Morrigu",
    "kaza" : "Kaza",
  ]);

    permission_list = ([
    "admin" : ([ "/" : "rw" ]),
    "objects" : ([ "logs" : "rw", "data" : "rw", "/" : "r-",
    "Tormeid/data" : "rw", "Tormeid/logs" : "rw" ]),
    "non-members" : ([ "/" : "r-" ]),
    "Kaza" : ([ "/" : "r-", "Kaza" : "rw" ]), 
    "Krynn" : ([ "/" : "r-", "Krynn" : "rw" ]),
    "Oerth" : ([ "/" : "r-", "Oerth" : "rw" ]),
    "Dagaard": ([ "/": "r-", "Dagaard" : "rw" ]),
    "Tormeid" : ([ "Tormeid" : "rw", "/" : "r-" ]) ,
    "Morrigu" : ([ "/":"r-", "Morrigu":"rw" ]),
    "Iuz" : ([ "/" : "r-", "Oerth" : "rw",
    "Toril/Menzoberrazan" : "rw" ]),
  ]);
}

