
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
                "sage"  : ([ "/": "rw", "/adm": "r-" ]),
                "saulin": (["/":"r-","saulin_temple":"rw", "/adm":"--"]),
                "dragon": (["/":"r-","dragon":"rw", "/adm":"--"]),
                 "monk" : (["/":"r-","data":"rw","saulin_temple":"rw","/adm":"--"]),
	        "mumar" : (["/":"r-","mumar":"rw", "/adm":"--"]),
	        "tomb"  : (["/":"r-","data":"rw","tomb":"rw","saulin_temple":"rw","/adm":"--"]),
	     "volcano"  : (["/":"r-","volcano":"rw", "/adm":"--"]),
	  "goomay_mine" : (["/":"r-","goomay_mine":"rw", "/adm":"--"]),
           "liang_shan" : (["/":"r-","liang_shan":"rw", "/adm":"--"]),
	       "island" : (["/":"r-","island":"rw", "/adm":"--"]), 
	"ianyeu" : (["/":"r-","ianyeu":"rw","/adm":"--"]) ,
	     "beggar"   : (["/":"r-","beggar":"rw","legend":"rw","/adm":"--"]) ,
             "data"     : (["/":"r-","data":"rw","/adm":"--"]),
	     "legend"   : (["/":"r-","legend":"rw","/adm":"--"]) ,
        ]);
}

