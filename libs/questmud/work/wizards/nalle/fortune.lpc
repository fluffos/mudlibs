// By Nalle, December 2003. Fortunes ripped from linux's 'fortune'.

#define FORTUNE_DIR "/wizards/nalle/fortune/"
#define BUFFER_SIZE 5000

string give_fortune(string type)
{
 int n, readat;
 int now_at;
 int type_int, fortune, read_at;
 string *files;
 string buffy, result;

 // Init
 files = get_dir( FORTUNE_DIR+"*" );

 // Checks and sanity
 if(!type) type = files[random(sizeof(files))];
 type_int = member_array( type, files );
 if(type_int == -1) type_int = random(sizeof(files));

 read_at = random( file_size( FORTUNE_DIR+type ) );
 while(file_size( FORTUNE_DIR+type ) - read_at < 1000 ) 
  {
   read_at = random( file_size( FORTUNE_DIR+type ) );
  }

 result = read_bytes( FORTUNE_DIR + files[ type_int ], read_at, BUFFER_SIZE );

 return result[ strstr(result, "%", 1) .. strstr(result, "%", strstr(result, "%", 1)+1) ];
}

string *query_categories()
{
 return get_dir( FORTUNE_DIR+"*" );
}
