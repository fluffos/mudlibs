// cat.c
// By Annihilator (1-8-94)

varargs int cat( string path, int start, int num )
{
	if( file_size(path) > 0 )
		message( "write", read_file(path, start, num), this_player() );
	else
		error("Cat: file " + path + " not found or zero length.\n");
	return 1;
}
