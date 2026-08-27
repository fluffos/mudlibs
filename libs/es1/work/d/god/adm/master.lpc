// This is the default domain master object.
// You may wish to customize it.  See the original file
// that this inherits for more information.  -- Buddha

inherit "/adm/obj/master/d_master";

void create()
{
        ::create();
        group_list += ([
                "moon" : "godadmin",
                "boss" : "godadmin",
        ]);

        permission_list += ([
        "godadmin" : ([ "/" : "rw", "adm" : "rw" ]),
        ]);
}
