/*
// Val@TMI (Oct 94) <Tero.Pelander@utu.fi>
// If you find a way make the diff routine more effective please mail me.
// ..stickmud changes

// Syntax: diff [-cu[#]] [-o<file>] <file1> <file2>
//  Effect: Finds the differences between two files.  The -c flag will make a
//  context diff, -u will make unified diff.  The default number of common
//  lines in a context and unified diff is 3.  The -o flag will put the output
//  into a file.
*/

// Define this if explode() removes only one of the delimiters
// from the begining.
#undef NEW_EXPLODE


#define MIN(A,B) (((A)<(B))?(A):(B))
#define MAX(A,B) (((A)>(B))?(A):(B))

#include <cmd.h>

#define GUESS_LEN 20
// Returns 0 if no common lines were found.
// Otherwise returns ({ start_of_common_in_1-1, end_of_common_in_1+1,
//                      start_of_common_in_2-1, end_of_common_in_2+1 })
int *
locate_split( string *common1, string *common2, int s1, int e1, int s2, int e2)
{
    int found_len, found_e1, found_e2, len, swapped, unbalanced;
    int x1, x2, y1;
    mixed tmp;

#define SWAP(A,B,T) {T=A;A=B;B=T;}
    if( e2-s2 > e1-s1 ) {
	swapped = 1;
	SWAP(common1,common2,tmp);
	SWAP(s1,s2,tmp);
	SWAP(e1,e2,tmp);
    }

    len = e2-s2+1;
    unbalanced = (e1-s1+1-len) & 1;
    x1 = (e1-s1+1-len) / 2 + 1;
    x2 = x1 - 1;
    y1 = 0;
    while( 1 ) {
	int xx, yy, ll, found_count;

	if( x1 ) x1--;
	else {
	    if( unbalanced ) len--;
	    y1++;
	}
	if( found_len >= len ) break;
	// test for equality 1
	xx = s1 + x1;
	yy = s2 + y1;
	ll = len + 1;
	do {
	    if( --ll && common1[ xx ] == common2[ yy ] ) found_count++;
	    else if( found_count ) {
		if( found_count > found_len ) {
		    found_e1 = xx;
		    found_e2 = yy;	
		    // approximate
		    if( ( found_len = found_count ) >= GUESS_LEN ) {
			len = 0;
			break;
		    }
		}
		found_count = 0;
	    }
	    xx++; yy++;
	} while( ll );

	if( !unbalanced && !x1 ) len--;
	if( found_len >= len ) break;
	// x2++; moved two lines down
	// test for equality 2
	xx = s1 + (++x2);
	yy = s2;
	ll = len + 1;
	do {
	    if( --ll && common1[ xx ] == common2[ yy ] ) found_count++;
	    else if( found_count ) {
		if( found_count > found_len ) {
		    found_e1 = xx;
		    found_e2 = yy;
		    // approximate
		    if( ( found_len = found_count ) >= GUESS_LEN ) {
			len = 0;
			break;
		    }
		}
		found_count = 0;
	    }
	    xx++; yy++;
	} while( ll );
    }

    if( found_len ) {
	if( swapped ) SWAP(found_e1,found_e2,tmp);
	return ({ found_e1 - found_len - 1, found_e1,
	  found_e2 - found_len - 1, found_e2 });
    }
    return 0;
}

// Returns difference locations as array.  Single entry is in format:
// ({ start_in_1, number_of_lines_in_1, start_in_2, number_of_lines_in_2 })
mixed *
split_diff( string *common1, string *common2, int s1, int e1, int s2, int e2)
{
    int *tmp;

    if( e1<s1 || e2<s2 ) {
	if( e1>=s1 || e2>=s2 ) {
	    return ({ ({ s1, e1-s1+1, s2, e2-s2+1 }) });
	}
	return ({ });
    }

    if( tmp = locate_split( common1, common2, s1, e1, s2, e2 ) ) {
	return ( split_diff( common1, common2, s1, tmp[0], s2, tmp[2] ) +
	  split_diff( common1, common2, tmp[1], e1, tmp[3], e2 ) );
    }
    return ({ ({ s1, e1-s1+1, s2, e2-s2+1 }) });
}

// Fix the linenumbers and add the data for lines that were removed
// in the first check.
mixed *
fix_diff( mixed *diff, int *diff1, int *diff2 )
{
    int i, add_i, m, add_m;

    m = sizeof( diff );

    // Fix using diff1
    for( i = add_i = 0, add_m = sizeof( diff1 ); add_i < add_m; add_i++ ) {
	while( i < m && diff[i][0] + add_i <= diff1[add_i] ) {
	    diff[i++][0] += add_i;
	}
	if( i && diff[i-1][0] + diff[i-1][1] >= diff1[add_i] ) {
	    diff[i-1][1]++;
	} else {
	    diff = diff[ 0 .. i-1 ] + ({ ({
		diff1[add_i], 1,
		(i ? diff[i-1][2]+diff[i-1][3]-diff[i-1][0]-diff[i-1][1] : 0)
		+ diff1[add_i],
		0 }) }) + diff[ i .. m-1 ];
	    m++;
	    i++;
	}
    }
    while( i < m ) diff[i++][0] += add_i;

    // Fix using diff2
    for( i = add_i = 0, add_m = sizeof( diff2 ); add_i < add_m; add_i++ ) {
	while( i < m && diff[i][2] + add_i <= diff2[add_i] ) {
	    diff[i++][2] += add_i;
	}
	if( i && diff[i-1][2] + diff[i-1][3] >= diff2[add_i] ) {
	    diff[i-1][3]++;
	} else {
	    diff = diff[ 0 .. i-1 ] + ({ ({
		(i ? diff[i-1][0]+diff[i-1][1]-diff[i-1][2]-diff[i-1][3] : 0)
		+ diff2[add_i], 0,
		diff2[add_i], 1 }) }) + diff[ i .. m-1 ];
	    m++;
	    i++;
	}
    }
    while( i < m ) diff[i++][2] += add_i;

    return diff;
}

// Create the output from differences.
// If <count> != 0 make context diff with <count> common lines.
string *
output_diff( string *lines1, string *lines2, mixed *diff, int count )
{
    string *output;
    int i, max, idx, end;
    int s1, s2, c1, c2, j;

    if( !( max = sizeof( diff ) ) ) {
	return ({ });
    }

    // idx = i = 0;
    output = ({ });
    if( count ) {
	int unified;

	if( count < 0 ) {
	    unified = 1;
	    count = -count;
	}

	do {
	    int k, f1, f2, mode;

	    // Find the starting and end lines of a single run.
	    if( (s1 = diff[i][0] - count) < 0 ) s1 = 0;
	    if( (s2 = diff[i][2] - count) < 0 ) s2 = 0;
	    end = i;
	    f1 = f2 = 0;
	    do {
		c1 = diff[end][0] + diff[end][1] + count - 1;
		c2 = diff[end][2] + diff[end][3] + count - 1;
		f1 += diff[end][1];
		f2 += diff[end][3];
	    } while( ++end < max && ( c1 + count >= diff[end][0] ||
		c2 + count >= diff[end][2] ) );
	    if( c1 >= sizeof( lines1 ) ) c1 = sizeof( lines1 ) - 1;
	    if( c2 >= sizeof( lines2 ) ) c2 = sizeof( lines2 ) - 1;

	    if( unified ) {
		// Create a unified diff.
		output += allocate( 1 + (c2-s2+1) + f1 );
		output[idx++] = sprintf( "@@ -%d,%d +%d,%d @@",
		  s1+1, c1-s1+1, s2+1, c2-s2+1 );
		for( k = diff[i][2], mode = 0; s2 <= c2; s2++ ) {
		    if( k == s2 ) {
			if( !mode ) {
			    for( j = diff[i][0]+diff[i][1]; s1 < j; ) {
				output[idx++] = "-" + lines1[s1++];
			    }
			}
			if( !mode && diff[i][3] ) {
			    k += diff[i][3];
			    mode = 1;
			} else {
			    if( ++i < max ) k = diff[i][2];
			    mode = 0;
			}
		    }
		    if( mode ) {
			output[idx++] = "+" + lines2[s2];
		    } else {
			output[idx++] = " " + lines2[s2];
			s1++;
		    }
		}
	    } else {
		// Create a context diff.
		output += allocate(3+ (f1 ? c1-s1+1 : 0) + (f2 ? c2-s2+1 : 0));
		output[idx++] = "***************";
		output[idx++] = sprintf("*** %d,%d ***", s1+1, c1+1);
		if( f1 ) {
		    for( k = diff[j = i][0], mode = 0; s1 <= c1; s1++ ) {
			if( k == s1 ) {
			    if( !mode && diff[j][1] ) {
				k += diff[j][1];
				mode = diff[j][3] ? 2 : 1;
			    } else {
				if( ++j < max ) k = diff[j][0];
				mode = 0;
			    }
			}
			output[idx++] = ({"  ","- ","! "})[mode] + lines1[s1];
		    }
		}
		output[idx++] = sprintf("--- %d,%d ---", s2+1, c2+1);
		if( f2 ) {
		    for( k = diff[j = i][2], mode = 0; s2 <= c2; s2++ ) {
			if( k == s2 ) {
			    if( !mode && diff[j][3] ) {
				k += diff[j][3];
				mode = diff[j][1] ? 2 : 1;
			    } else {
				if( ++j < max ) k = diff[j][2];
				mode = 0;
			    }
			}
			output[idx++] = ({"  ","+ ","! "})[mode] + lines2[s2];
		    }
		}
	    }
	} while( (i = end) < max );
    } else {
	// Create a regular diff.
	// First count the number of lines to outout.
	i = max;
	while( i-- ) {
	    j += diff[i][1] + diff[i][3] + ( (diff[i][1] && diff[i][3])? 2:1 );
	}
	output = allocate( j );
	i = 0;

	do {
	    string tmp;

	    // Output a single run.
	    s1 = diff[i][0];
	    s2 = diff[i][2];
	    c1 = diff[i][1];
	    c2 = diff[i][3];
	    // DRIVER BUG: mixed x; x = 3; x += "a"; // will bug.
	    // BUT:        mixed x; x = "a"; x += 3; // will work.
	    tmp = (c1 > 1) ? ( (s1 + 1) + "," + (s1 + c1) ) :
	    ( (c1 ? (s1 + 1) : s1) + "" );
	    tmp += c1 ? ( c2 ? "c" : "d" ) : "a";
	    tmp += (c2>1) ? ( (s2+1) + "," + (s2 + c2) ) : c2 ? (s2 + 1) : s2;
	    output[idx++] = tmp;

	    for( j = 0; j < c1 ; j++ ) output[idx++] = "< " + lines1[s1+j];
	    if( c1 && c2 ) output[idx++] = "---";
	    for( j = 0; j < c2 ; j++ ) output[idx++]= "> " + lines2[s2+j];
	} while( ++i < max );
    }

    return output;
}

// The real start of the diff process.  It is public.
string *
make_diff( string *lines1, string *lines2, int count )
{
    mixed *tmp, *tmp_lines;
    string *common1, *common2;
    int *diff1, *diff2;
    int i, j, m, s12, e1, e2;

    // Remove different lines from file 1
    diff1 = allocate( m = sizeof( tmp = lines1 - lines2 ) );

    for( i = s12 = 0, j = -1, tmp_lines = lines1; i < m; i++ ) {
	// Guarding from errors when there are multiple similar 'unique' lines.
	while( ( diff1[i] = member( tmp_lines, tmp[i] ) + s12 ) <= j ) {
	    tmp_lines = lines1[ (s12=j+1) .. sizeof(lines1)-1 ];
	}
	j = diff1[i];
    }

    // This seems to be best way to do this fast.
    common1 = lines1 - tmp;
    tmp = 0;

    // Remove different lines from file 2
    diff2 = allocate( m = sizeof( tmp = lines2 - lines1 ) );

    for( i = s12 = 0, j = -1, tmp_lines = lines2; i < m; i++ ) {
	// Guarding from errors when there are multiple similar 'unique' lines.
	while( ( diff2[i] = member( tmp_lines, tmp[i] ) + s12 ) <= j ) {
	    tmp_lines = lines2[ (s12=j+1) .. sizeof(lines2)-1 ];
	}
	j = diff2[i];
    }

    // This seems to be best way to do this fast.
    common2 = lines2 - tmp;
    tmp = 0;

    // Find the first differences.
    s12 = 0;
    e1 = sizeof( common1 ) - 1;
    e2 = sizeof( common2 ) - 1;
    i = MIN( e1, e2 ) + 1;
    while( i && common1[ s12 ] == common2[ s12 ] ) s12++, i--;
    while( i && common1[ e1  ] == common2[ e2  ] ) e1--, e2--, i--;

    // Do recursive calls to find the differences.
    // Then add the original removed lines back to the diff.
    tmp = fix_diff( split_diff( common1, common2, s12, e1, s12, e2 ),
      diff1, diff2 );
    diff1 = diff2 = 0;

    // Create the textual output from the data.
    return output_diff( lines1, lines2, tmp, count );
}


private string *
get_lines( string file_name )
{
    string file;

    file_name = (string)this_player()->absolute_path( file_name );
    switch( file_size( file_name ) ) {
    case -2: { write( file_name + " is a directory.\n" ); return 0; }
    case -1: { write( file_name + " is not a file or no permission.\n" );
	    return 0; }
    }
    file = read_file( file_name );
    if( !file ) {
	write( file_name + " is unreadable.\n" );
	return 0;
    }
#ifdef NEW_EXPLODE
    if( file[0] == '\n' ) {
	return ({ "" }) + explode( file, "\n" );
    }
#else
    {
	int i;

	while( file[i] == '\n' ) i++;
	if( i ) {
	    string *tmp;

	    tmp = allocate( i );
	    while( i-- ) tmp[i] = "";
	    return tmp + explode( file, "\n" );
	}
    }
#endif
    return explode( file, "\n" );
}

int
diff_cmd( string str )
{
    string file_name1, file_name2, output_file;
    string *lines1, *lines2, *output;
    int context;

    if (!CHECK) return 0;
    //  seteuid( getuid( previous_object() ) );
    if( str ) {
	string tmp;

	while(sscanf( str, "-%s %s", str, tmp ) || sscanf( str, "-%s", str )) {
	    if( str[0] == 'c' ) {
		context = 3;
		sscanf( str, "c%d", context );
	    } else if( str[0] == 'u' ) {
		context = 3;
		sscanf( str, "u%d", context );
		context = -context;
	    } else if( str[0] == 'o' ) {
		sscanf( str, "o%s", output_file );
		if( !sizeof( output_file ) ) {
		    notify_fail( "Flag -o needs an argument.\n" );
		    return 0;
		}
		output_file =(string)this_player()->absolute_path(output_file);
		if( !write_file( output_file, "" ) ) {
		    notify_fail( sprintf( "Can't write to '%s'.\n",
			output_file ) );
		    return 0;
		}
	    } else if( str[0] ) {
		notify_fail( sprintf( "Illegal flag: %s\n", str ) );
		return 0;
	    } else {
		str = tmp;
		break;
	    }
	    str = tmp;
	    tmp = 0;
	}
    }
    if( !str || 2 != sscanf( str, "%s %s", file_name1, file_name2 ) ) {
	notify_fail( "Syntax: diff [-cu[#]] [-o<file>] <file1> <file2>\n" );
	return 0;
    }
    if( file_name1 == file_name2 ) {
	write( "Not comparing file with it self.\n" );
	return 1;
    }
    if( !pointerp( lines1 = get_lines( file_name1 ) ) ||
      !pointerp( lines2 = get_lines( file_name2 ) ) )
    {
	write( "No comparison made.\n" );
	return 1;
    }

    output = make_diff( lines1, lines2, context );
    if( !sizeof( output ) ) {
	write( "The files are identical.\n" );
	return 1;
    }
    if( context ) {
	output = ({ ((context>0) ? "*** " : "--- ") + file_name1,
	  ((context>0) ? "--- " : "+++ ") + file_name2 }) + output;
    }

    if( output_file ) {
	write_file( output_file, implode( output, "\n" ) + "\n" );
	write( sprintf( "Diff written to '%s'.\n", output_file ) );
    } else {
	this_player()->more( output );
    }
    return 1;
}
