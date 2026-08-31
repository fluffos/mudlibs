#include "/players/shadowmonk/include/defs.h"
#include "/players/shadowmonk/include/vt100.h"

// maximum steps
#define MAXS  30   
// maximum direct calls
#define MAXC  15   


// #define WORK  "- \\\ | /"
// string  *chars;

// Busy counter... for every extra path .. an extra busy counter
int      busy;

// The recursive function
void     find_path( mixed *vars );

// An array storing the rooms
string  *path;

// The name of where to save the rooms
string   pathlog;

// This is the mapping containing all data 
// the structure is:
// data([ "begin"   : "room_file",             // begin room (file)
//          "end"     : "room_file",             // end room (file)
//          "min"     : int,                     // minumum steps 
//          "max"     : int,                     // maximum steps
//          "allow"   : ({ "north", "south" }),  // array with allowed exits commands
//          "nallow"  : ({ "room_file" }),       // array with not allowed rooms
//          "tried"   : ([ level(int) : ({ "tried-room on that level" }) ]),
//                                               // used to reduce calculation
//          "tries"   : int                      // counter
//          level(int): ({ "room_name", ({ "exits_not_tried_yet" }) })
//        ]);
mapping  data;

void filter_path() {
    int i;

//  if the file defined by pathlog exits, then a part of the path already exits
//  so read the files.
    if( file_size( pathlog ) > 0 )
        path += explode( read_file( pathlog ), " " );

//  Delete all the double rooms.
    for( i=sizeof( ( path = sort_array( path, #'> ) ) )-2; i>=0; i-- )
        if( path[i] == path[i+1] )
            del_array( path, i );

//  save the file once again
    write_file( pathlog, implode( path, " " ) );

//  Remove one busy counter
    busy--;
//    if( busy <= 0 )
//        TME( "All done and ready!" );
}

//  this function returns allowed exits
//  nmb   = number of path
//  level = recursive level searching on
//  room  = room of which the get exits off
varargs string *get_exits( int nmb, int level, string room ) {
    int     i, j, sz;
    string *exits, *texits;
    exits = texits = ({});

//  texits will be the rooms that are in the path currently
//  it will be every indici in data([]) that is an int
    for( i=sizeof( ( exits=m_indices( data[nmb] ) ) )-1; i>=0; i-- )
        if( intp( exits[i] ) )
            texits += ({ data[nmb][exits[i]][0] });

//  retrieve exits
    exits = call_other( room, "query_dest_dirs" );
    for( i=sizeof( exits )-2; i>=0; i-=2 ) {
        if( sizeof( texits ) )

//  if exit room in path already, delete it
            if( member_array( exits[i], texits ) != -1 ){
                exits = del_array( exits, i );
                exits = del_array( exits, i );
                continue;
            }

//  if exit room already tried on this level delete it
        if( data[nmb]["tried"][level+1] )
            if( member_array( exits[i], data[nmb]["tried"][level+1] ) != -1 ) {
                exits = del_array( exits, i );
                exits = del_array( exits, i );
                continue;
            }

//  if exit command not in allow({}) && sizeof( allow ) > 0 delete it
        if( sizeof( data[nmb]["allow"] ) )
            if( member_array( exits[i+1], data[nmb]["allow"] ) == -1 ) {
                exits = del_array( exits, i );
                exits = del_array( exits, i );
                continue;
            }

//  if exit room in nallow({}) delete it
        if( sizeof( data[nmb]["nallow"] ) )
            if( member_array( exits[i], data[nmb]["nallow"] ) != -1 ) {
                exits = del_array( exits, i );
                exits = del_array( exits, i );
                continue;
            }
    }

//  remove all exit commands
    for( i=sizeof( exits )-1; i>=0; i-=2 )
        exits=del_array( exits, i );

//  randomize exits left
    texits = ({});
    for( i=sizeof( exits )-1; i>=0; i-- ) {
        texits += ({ exits[ ( j=random( i+1 ) ) ] });
        exits = del_array( exits, j );
    }
    if( sizeof( texits ) > 0 )
        return texits;
    return ({});
}

//  this function regulates if the next call to the recursive function
//  find_path should be a direct one or one through call_out thus 
//  avoiding the too long evaluation error. 
//  nmb   = number of path
//  level = level working on 
//  count = counter
//  room  = current room
varargs void do_call( int nmb, int level, int count, string room ) {
    if( level < 0 ) {
        TME( "Cannot find a path! ");
        return;
    }
    if( ( data[nmb]["tries"]++ ) > 999 ) {
        TME( "Toooo many tries!" );
        return;
    }

//  no room is given when going a level down
    if( !room )
        room = data[nmb][level][0];

//  If counter hits 0, a call_out is done, thus avoiding too long evaluation
    if( count-- <= 0 ) {
//        TMEN( VT_SC+VT_CEOL+"Working "+chars[0]+VT_RC );
//        chars += ({ chars[0] });
//        chars = del_array( chars, 0 );
        call_out( "find_path", 0, ({ nmb, level, MAXC, room }) );
    }
    else find_path( ({ nmb, level, count, room }) );
    return;
}

void find_path( mixed *vars ) {
    int    i, nmb, level, count;
    string room, exit, *tpath;
    nmb   = vars[0]; // number of path
    level = vars[1]; // level on which a path is searched
    count = vars[2]; // counter
    room  = vars[3]; // current room
//    TME( nmb+" "+level+" "+count+" "+room+"." );
    if( !data[nmb]["tried"][level] )
        data[nmb]["tried"][level] = ({});

//  if end room is found and the level is right too, save it
    if( room == data[nmb]["end"] &&
         ( level >= data[nmb]["min"] && level <= data[nmb]["max"] ) )  {
        for( i=sizeof( ( tpath=m_indices( data[nmb] ) ) )-1; i>=0; i-- )
            if( intp( tpath[i] ) )
                path += ({ data[nmb][tpath[i]][0] });
        path += ({ room });
        filter_path();
        return;
    }

//  if no data exits on this level, get the data
    if( !data[nmb][level] )
        data[nmb][level] = ({ room, get_exits( nmb, level, room ) });
//    save_object( HOME+"inherit/test" );

//  when certain vars pass certain values, no calculation is needed
//  and can return a level lower
    if( !sizeof( data[nmb][level][1] ) || level > MAXS ||
                                        level > data[nmb]["max"] ) { 
        data[nmb] = m_delete( data[nmb], level );
        data[nmb]["tried"][level] += ({ room });
        do_call( nmb, level-1, count );
        return;
    }

//  lets go to the next level
    exit = data[nmb][level][1][0];
    data[nmb][level][1] = del_array( data[nmb][level][1], 0 );
    do_call( nmb, level+1, count, exit );
    return;
}


// this function is used to reset the file in which the array of
// room is saved too
void add_path(string filename) {
    busy = 0;
    pathlog = filename;
//    chars   = explode( WORK, " " );
    if( file_size( pathlog ) >=0 ) 
	rm(pathlog);
}

// This function does the formatting the vars into the structure data
// and also starting the recursive search.
void add_pathvars(mixed *arr) {
    int i, sz;
    if( !path )
        path = ({});
    if( !data )
        data = ([]);
    for( i=sizeof( arr )-1; i>=0; i-=6 ) {
        data[ ( sz=sizeof(data) ) ] = ([ 
            "begin" : arr[i-5],		// begin room..
            "end"   : arr[i-4],		// end room..
            "min"   : arr[i-3]-1,	// the following allowed structures are:
            "max"   : arr[i-2]-1,	//  min   max  
					//   0     0   the first found path will be taken
					//		regardless of number of steps...
					//		can be between 2 and MAXS.
					//   x  =  y   a path with a set number of steps
					//   x  <  y   a path wll be found with # steps
					//		between x and y
            "allow" : arr[i-1],		// array with allowed exits commands
            "nallow": arr[i],		// array with not allowed rooms
            "tried" : ([]),		// to reduce caculations.. If a room is tried before...
					// and failed to reach the end from that.. it does not
					// need to be tried again through a different way..
            "tries" : 0                 // used for killing proces if nothing is found..
        ]);
        if( data[sz]["max"] <= 0 || data[sz]["max"] >= MAXS )
            data[sz]["max"] = MAXS-1;
        if( data[sz]["min"] < 0 )
            data[sz]["min"] = 0;
        busy++;
        call_out( "find_path", 0, ({ sz, 0, 0, data[sz]["begin"] }) );
    }
}

status check() {
    if( file_size( pathlog ) <= 0 ) {
	TTP("UNABLE TO COMPLY!");
	return 0;
    }
    return 1;
}
