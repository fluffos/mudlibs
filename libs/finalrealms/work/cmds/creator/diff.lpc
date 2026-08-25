#pragma strict_types
//#define SAO  1           // Stop after x matches.
//#define DEBUG            // Activates debuging output.
#define BLOCK 20           // How many lines are searched at a time.
#define DISP_MATCHED_LINE  // Show line where match found.

#include <cmd.h>
inherit CMD_BASE;

int *find_next_match( string, string, int, int );
void display_report( string, string, string *, string *, int, int, int, int );
int same_string( string, string );
string *my_explode( string );

void setup()
{
    position = 1;
}

int cmd(  string str, object me )
{

    string file1, file2, // Files.
    strx, stry;  // Information from files
    int x, y;  // File pointers.
#ifdef SAO
    int saoc;
#endif
    mixed tmp;

    notify_fail( "diff <file1> <file2>\n" );

    if( !str ) return 0;
    if( sscanf( str, "%s %s", file1, file2 ) != 2 )
	return 0;
    file1 = TP->get_path(file1);
    if( file_size( file1 ) <= 0 )
    {
	notify_fail( file1 +" does not exist.\n" );
	return 0;
    }
    file2 = me->get_path(file2);
    if( file_size( file2 ) <= 0 )
    {
	notify_fail( file2 +" does not exist.\n" );
	return 0;
    }


    x = 1; y = 1;

    do
    {
	strx = read_file( file1, x, 1 );
	stry = read_file( file2, y, 1 );
	if( strx != stry )
	{
	    tmp = find_next_match(file1, file2, x, y);
	    x = tmp[0]; y = tmp[1];
#ifdef SAO
	    saoc++;
	    if( saoc == SAO )
		return 1;
#endif                        
	}
	else
	{
	    x++; y++;
	}
    } while( !intp( strx ) && !intp( stry ) );
    write( "Diff complete.\n" );
    return 1;
}

int *find_next_match( string file1, string file2, int x, int y )
{
    string *linesx, *linesy;
    int i, j, off;
    int xsize, ysize;
    mixed flag;

    off = 0;
    linesx = ({ }); linesy = ({ });
    while( !arrayp( flag ) )
    {
	linesx += my_explode( read_file( file1, x+off, 
	    BLOCK ) );
	linesy += my_explode( read_file( file2, y+off, 
	    BLOCK ) );
	/* *sigh* Explode doesn't work for this.
			linesx += explode( read_file( file1, x+off, x+off+BLOCK ), "\n" 
	);
			linesy += explode( read_file( file2, y+off, y+off+BLOCK ), "\n" 
	);
	*/
	xsize = sizeof( linesx );
	ysize = sizeof( linesy );

	// Backtests the array.
	for( i=0;i<off;i++ )
	    for( j=off;j<(off+BLOCK);j++)
	    {
		if( xsize <= BLOCK )
		{
		    if(same_string( linesx[i], linesy[j] ))
		    {
#ifdef DEBUG
			write( "%^BLUE%^"+sprintf( "\n%d.%d.%d\n%s\n%s\n", i,j,off,linesx[i], linesy[j] 
			  ) );
#endif
			display_report(file1,file2,
			  linesx, linesy,
			  x, x+i,
			  y, y+j);
			return ({x+i,y+j});
		    }
		}
		if( ysize <= BLOCK )
		{
		    if(same_string( linesx[j], linesy[i] ))
		    {
#ifdef DEBUG
			write( "%^CYAN%^"+sprintf( "\n%d.%d.%d\n%s\n%s\n", i,j,off,linesx[j], linesy[i] 
			  ) );
#endif
			display_report(file1,file2,
			  linesx,linesy,
			  x, x+j, y, y+i);
			return ({x+j, y+i});
		    }
		}
	    }
#ifdef DEBUG
	write( sprintf( "%O %O", linesx, linesy ) +
	  "\n%^RED%^"+ xsize +":"+ysize+":"+off+"\n" );
#endif
	for( i=off;i<(off+BLOCK);i++ )
	    for( j=i;j<(off+BLOCK);j++ )
	    {
		if( i >= xsize ) continue;
		if( j >= ysize ) continue;

		if( same_string( linesx[i], linesy[j] ) )
		{
#ifdef DEBUG
		    write( "%^RED%^"+sprintf( "\n%d.%d.%d\n%s\n%s\n",i,j,off, linesx[i], linesy[j] )
		    );
#endif
		    display_report(file1,file2,linesx,linesy,
		      x,x+i,y,y+j);
		    return ({x+i,y+j});
		}

		if( i >= ysize ) continue;
		if( j >= xsize ) continue;

		if( same_string( linesx[j], linesy[i] ) )
		{
#ifdef DEBUG
		    write( "%^YELLOW%^"+sprintf( "\n%d.%d.%d\n%s\n%s\n", i,j,off,linesx[j], linesy[i
			] ) );
#endif
		    display_report(file1,file2,linesx,linesy,
		      x,x+j,y,y+i );
		    return ({x+j, y+i});
		}
	    }

	if( off+BLOCK > xsize || off+BLOCK > ysize ) // No match to end
	{
#ifdef DEBUG
	    write( "%^GREEN%^Bing!!" );
#endif
	    display_report( file1, file2, linesx, linesy, 
	      x, x+off+xsize, y, y+off+ysize );
	    return ({ x+xsize, y+ysize });
	}
	off += BLOCK;
    }
}


void display_report( string f1, string f2, string *linesx, string *linesy, 
  int x, int xend, int y, int yend )
{
    printf( "%s: %d-%d\n", f1, x, xend );
#ifndef DISP_MATCHED_LINE
    x++;
#endif
    if( xend-x >= 0 )
	write( "1> "+implode( linesx[0..(xend-x)], "\n1> " )+"\n" );

    printf( "%s: %d-%d\n", f2, y, yend );
#ifndef DISP_MATCHED_LINE
    y++;
#endif
    if( yend-y >= 0 )
	write( "2> "+implode(linesy[0..(yend-y)], "\n2> " )+"\n" );
}

int same_string( string s1, string s2 )
{
    if( s1 == s2 )
    {
	if( !s1 || s1 == "" ) return 0;
	return 1;
    }
}

string *my_explode( string mess )
{
    int p;
    string *ret = ({ });
    while( strlen( mess ) )
    {
	p = strsrch( mess, "\n" );
	if( p == 0 ) ret += ({ "" });
	else         ret += ({ mess[0..(p-1)] });
	mess = mess[(p+1)..<1];
    }
    return ret;
}

