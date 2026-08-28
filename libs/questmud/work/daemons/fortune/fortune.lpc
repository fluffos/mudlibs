// By Nalle, December 2003. Fortunes ripped from linux's 'fortune'.
// Don't worry, this is fast.

#define FORTUNE_DIR "/doc/misc/fortune_data/"
#define BUFFER_SIZE 1000

string *categories;

string *query_categories();

/************************************************************************/

string give_fortune(string type)
{
 int n, readat;
 int now_at;
 int type_int, fortune, read_at;
 string *files;
 string buffy, result;

 // Init
 files = query_categories();

 // Make sure the type is legal, else reset it

 if(!type) type = files[random(sizeof(files))];
 type_int = member_array( type, files );
 if(type_int == -1) type_int = random(sizeof(files));

 // The random fortune is the next full fortune from a random byte/filesize

 read_at = random( file_size( FORTUNE_DIR+type ) );

 // Make sure its not a portion of the last fortune.
 // This should be done in a smarter way.

 result = read_bytes( FORTUNE_DIR + files[ type_int ], read_at, BUFFER_SIZE );

 while( strstr(result, "%", strstr(result, "%", 1)+1) == -1) 
  {
   read_at = random( file_size( FORTUNE_DIR+type ) );
   result = read_bytes( FORTUNE_DIR + files[ type_int ], read_at, BUFFER_SIZE );
  }

 result = read_bytes( FORTUNE_DIR + files[ type_int ], read_at, BUFFER_SIZE );

 return result[ strstr(result, "%", 1)+1 .. strstr(result, "%", strstr(result, "%", 1)+1)-1 ];
}

/************************************************************************/
// Different possible categories

string *query_categories()
{
 string *result;
 string *dir;
 int i;

 if(pointerp( categories ) && sizeof( categories ) > 0) return categories;

 result = ({});

 dir = get_dir( FORTUNE_DIR+"*" );

 for(i = 0; i < sizeof(dir); i++)
    {
     if( dir[i] != "." && dir[i] != ".." ) result += ({ dir[i] });
    }
 
 categories = result;
 return result; 
}
