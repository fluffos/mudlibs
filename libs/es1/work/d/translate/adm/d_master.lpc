// This is the default domain master object.
// You may wish to customize it.  See the original file
// that this inherits for more information.  -- Buddha
// yeah sure... I'll mess with it...         -- Elon (4-7-94)
// edit to test something.. -- Elon Thu  08-18-94
 
inherit "/adm/obj/master/d_master";
 
void create()
{
        ::create();
        group_list += ([
                "snow": "archwizard",
        ]);
 
        permission_list += ([
          "archwizard": ([ "/": "rw", ]),
                "cwa" : ([ "/": "r-", "cwa" : "rw", ]),
              "nothing" : ([ "/": "r-", ]),
            "general" : ([ "/": "r-", "cwa" : "--", "doc" : "rw",
                                      "tmp" : "rw", ]),
        ]);
}
//                 "elon": ([ "/": "rw", ]),
 
