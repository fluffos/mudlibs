#include <kernel.h>
inherit ACCESS;

#include <jobs.h>

void
do_grep_job ( mapping job )
{
    int i, size, already_read, index, lot;
    string *strs, result, str, *lines, expr, filename, *files;
    set_privilege ( job[J_PRIVILEGE] );
    expr = job[GREP_EXPRESSION];
    files = job[GREP_FILES];
    already_read = job["file_offset"];
    result = "";
    for ( i = 0; i < sizeof ( files ); i++ )
    {
	size = file_size ( filename = files[i] );
	if ( size < 0 ) 
	    result += "GREP \""+expr+"\" "+filename+": '"+filename+"'"+
    		( size == -2 ? " is a directory.\n" : " doesn't exist.\n" );
	else 
	{
	    lot = size - already_read;
	    if ( lot > 50000 ) lot = 50000;
	    str = read_bytes ( filename, already_read, lot );
	    already_read += lot;
	    if ( !stringp ( str ) ) 
	    {
		result += "GREP \""+expr+"\" "+filename+": '"+filename+"'"+
    			" isn't readable.\n";
		already_read = 0;
		continue;
	    }
	    if ( already_read < size )
	    {
		index = strlen ( str ) - 1;
		while ( index + 1 && str[index] != '\n' ) 
		    index--, already_read--;
		str = str[0..index-1];	
		job["file_offset"] = already_read;
	    }
	    strs = explode ( str, "\n" );
            if ( already_read <= lot )
		result += "GREP \""+expr+"\" "+filename+":\n"+
		    ("---------------------------------------------------------\
----------------------"[0..9+strlen(expr)+strlen(filename)-1])+"\n";
	    if ( sizeof ( strs = regexp ( strs, expr ) ) ) 
		result += implode ( strs, "\n" ) + "\n";
	    if ( already_read == size ) 
	    {
		result += "\n";
		i++;
		job["file_offset"] = already_read = 0;
	    }
	    break;
	}
    }
    if ( !sizeof ( job[GREP_FILES] = files[i..] ) ) 
    	job[J_FINISHED] = "You could 'view' your grep results now.\n";
    if ( job[J_OUTPUT] != 1 || !job[J_RESULT] ) job[J_RESULT] = result;
    else job[J_RESULT] += result;
}
