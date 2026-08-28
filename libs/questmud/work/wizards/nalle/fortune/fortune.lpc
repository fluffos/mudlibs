// By Nalle, December 2003. Fortunes ripped from linux's 'fortune'.
// Don't worry, this is fast.

#define FORTUNE_DIR "/wizards/nalle/fortune/data/"
#define BUFFER_SIZE 1000

string give_fortune(string type)
{
 int n, readat;
 int now_at;
 int type_int, fortune, read_at;
 string *files;
 string buffy, result;

 // Init
 files = get_dir( FORTUNE_DIR+"*" );

 // Make sure the type is legal, else reset it
 if(!type) type = files[random(sizeof(files))];
 type_int = member_array( type, files );
 if(type_int == -1) type_int = random(sizeof(files));

 // The random fortune is the next full fortune from a random byte
 read_at = random( file_size( FORTUNE_DIR+type ) );

 // Make sure its not a portion of the last fortune.
 // This should be done in a smarter way.

 while(file_size( FORTUNE_DIR+type ) - read_at < BUFFER_SIZE ) 
  {
   read_at = random( file_size( FORTUNE_DIR+type ) );
  }

 result = read_bytes( FORTUNE_DIR + files[ type_int ], read_at, BUFFER_SIZE );

 return result[ strstr(result, "%", 1) .. strstr(result, "%", strstr(result, "%", 1)+1) ];
}

// Different possible categories
string *query_categories()
{
 return get_dir( FORTUNE_DIR+"*" );
}
