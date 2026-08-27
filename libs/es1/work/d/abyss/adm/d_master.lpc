
// This is the default domain master object.
// You may wish to customize it.  See the original file
// that this inherits for more information.  -- Buddha
// 2-18-95 Elon set up island permission 
inherit "/adm/obj/master/d_master";
 
void create()
{
        ::create();
        group_list += ([
		"snow" : "admin",
		"moon" : "archwizard",
        ]);
 
        permission_list += ([
                "archwizard": ([ "/": "rw", "/adm": "rw" ]),
        ]);
}

