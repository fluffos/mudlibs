 
//	File	:  /adm/daemons/mand.c
//	Creator	:  Jubal@TMI  (10/20/91)
//	Updated	:  Watcher@TMI  (4/11/93)
//
//	This man daemon emulates the UNIX man system.


#include <config.h>
#include <man.h>
#include <uid.h>

varargs string *find_manpage(string root, mixed arg, string name);


/* valid_man_read() returns 1 if this_player() is allowed to read the
        manpage given as the argument.  This module is mudlib dependent,
        and gods should change it to reflect the local levels of manpage
        access.  The default is to allow access to any manpage by any
        player.
*/

int valid_man_read( string *manentry ) {
        return 1;
}

varargs int man( mixed arg, string name ) {
	string *manent;

	seteuid(ROOT_UID);
	manent = find_manpage (arg, name) ;
	if( manent )
	{
		if( valid_man_read( manent ) )
		{

			this_player()->more(manent[2], 0 ,1);
		}
		else
			write("Man: Permission denied.\n");
	}
	else
	{
		if( name )
			write("Man: " + name + " not found in " + arg + 
			      " section.\n");
		else
			return 0 ;
	}
	return 1 ;
}



/* find_manpage() is a function which is inherited by the manpage
        daemons.
*/

varargs string *find_manpage( mixed arg, string name ) {
        int i;
        string *rv;
	string filetype ;

        rv = allocate( 3 );

        /* check if we are searching in a particular directory */
        if( name )
        {
                rv[0] = arg; rv[1] = name;
			switch (arg) {
				case "efuns" : { filetype = "3" ; break ; }
				case "applies" : { filetype = "4" ; break ; }
				case "misc" : { filetype = "5" ; break; }
				case "simul_efuns" :  { filetype = "2" ; break;}
				case "lfuns" : { filetype = "l" ; break ; }
			}
                rv[2] = man_root + "/" + arg +
                        "/" + name + "." + filetype;
                if( file_size( rv[2] ) <= 0 ) rv = NULL;
        }
        else
        {
                rv[1] = name = arg;
                for( i=0 ; i<sizeof(MAN_DIRLIST) ; i++ )
                {
                        rv[0] = arg = MAN_DIRLIST[i];
			switch (arg) {
				case "efuns" : { filetype = "3" ; break ; }
				case "applies" : { filetype = "4" ; break ; }
				case "misc" : { filetype = "5" ; break ; }
				case "simul_efuns" :  { filetype = "2" ; break;}
				case "lfuns" : { filetype = "l" ; break ; }
			}
                        rv[2] = man_root + "/" + arg +
                                "/" + name + "." + filetype;
                        if( file_size( rv[2] ) > 0 ) break;
                }
                if( i == sizeof( MAN_DIRLIST ) ) rv = NULL;
        }
        return rv;
}
/* EOF */
