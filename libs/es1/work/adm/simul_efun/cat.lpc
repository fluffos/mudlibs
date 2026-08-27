// cat.c
// By Annihilator (1-8-94)
// Elon 12-08-94 : attempt to fix it..
 
varargs int cat( string path, int start, int num )
{
	string msg ;
        if( file_size(path) > 0 ) {
		msg = read_file( path, start, num );
	if ( msg ) {
		message( "write", msg, this_player() );
                return 1;
	}
}
        return 0;
}
