// By Nalle, December 2003. Fortunes ripped from linux's 'fortune'.

#define FORTUNE_DIR "/wizards/nalle/fortune/"
#define BUFFER_SIZE 5000

string give_fortune(string type)
{
 int n, readat;
 int now_at;
 int type_int, fortune, read_at;
 string buffy, result;

 // Init
 files = get_dir( FORTUNE_DIR+"*" );

 // Checks and sanity
 if(!type) type = files[random(sizeof(files))];
 type_int = member_array( type, files );
 if(type_int == -1) type_int = random(sizeof(files));

 fortune = random( file_size( FORTUNE_DIR+type );

 read_at = 0;
 n 	 = 0;
 now_at  = 0;

 while( n < 5000000 && n < fortune)
 {
  buffy = read_bytes( FORTUNE_DIR + files[ type_int ], read_at, BUFFER_SIZE );

  if(!buffy) 
    { 
     write("File read error. (read_at == "+read_at+", n == "+n+" fortune == "+fortune+")\n"); 
     break; 
    }

  for( now_at = 0; n < fortune; n++ )
  {
   if( strstr( buffy, "%", now_at + 1 ) == -1 )
     {
      read_at += BUFFER_SIZE; // Buffer spent
      break;
     }
      else
     {
      now_at = strstr( buffy, "%", now_at + 1 );
     }
  }
 }

 result = read_bytes( FORTUNE_DIR + files[ type_int ], read_at+now_at, 1000 );

 write("read_at == "+read_at+", n == "+n+", fortune == "+fortune+", now_at == "+now_at+" type == "+type+"\n"); 

 return result[ 0 .. strstr(result, "%", 1) ];
// return result;
}

string *query_categories()
{
 return files;
}
