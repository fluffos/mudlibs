// This is the default domain master object.
// You may wish to customize it.  See the original file
// that this inherits for more information.  -- Buddha

inherit "/adm/obj/master/d_master";

void create()
{
        ::create();
        group_list += ([
                "sage"     : "monk",
		"creative" : "knight",
        ]);

        permission_list += ([
                "monk"     : ([ "/": "r-", "attack/monk": "rw",
                        "defense/monk": "rw", ]),
                "scholar"  : ([ "/": "r-", "attack/scholar" : "rw",
                        "defense/scholar" : "rw", ]),
                "knight"   : ([ "/": "r-", "attack/knight" : "rw",
                        "defense/knight" : "rw", ]),

                "temp"    : ([ "/": "r-", "attack/scholar" : "rw", ]),  
        ]);
}
