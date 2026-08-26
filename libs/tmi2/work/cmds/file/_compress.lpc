/*
// This file is a part of the TMI distribution mudlib.
// Please retain this header if you use this code.
// Devised & Written by Douglas Reay (Pallando @ TMI, Ephemeral Dale, etc)
// Moved to TMI-II (25-11-92)
*/
#include <disclaimer.h>

#include <mudlib.h>

inherit DAEMON;

#define LIMIT 20
#define TAB "	"

int waste_ch( string a );
void compress_lines( mixed a );
void resave_file( mixed new_lines, string file_name, object player );
string help();

int cmd_compress( string a ) /* a is the name of the file to be compressed */
{
  string old_file;
  string *old_lines;
  int number_lines;
  mixed arg;
  string old_file_name, new_file_name;

  if( !a ) { help(); notify_fail( "No argument passed.\n" ); return 0; }
  if( 2 != sscanf( a, "%s to %s", old_file_name, new_file_name ) &&
      2 != sscanf( a, "%s %s", old_file_name, new_file_name )       )
  {
    old_file_name = a;
    new_file_name = a + ".comp";
  }
  seteuid( getuid( previous_object() ) );
  old_file_name = resolv_path( this_player()-> query( "cwd" ), old_file_name );
  new_file_name = resolv_path( this_player()-> query( "cwd" ), new_file_name );
  switch( file_size( old_file_name ) )
  {
    case -2: notify_fail( "compress: " + old_file_name + ": directory\n" ); return 0;
    case -1: notify_fail( "compress: " + old_file_name + ": no such file\n" ); return 0;
  }
  if( !master()-> valid_read( old_file_name,
    (string)this_player()-> query( "name" ), "compress" ) )
  {
    notify_fail( old_file_name + ": Permission denied.\n" );
    return 0;
  }
  old_file = read_file( old_file_name );
  if( !old_file ) { notify_fail( old_file_name + " is empty.\n" ); return 0; }
  if( !master()-> valid_write( new_file_name,
    (string)this_player()-> query( "name" ), "compress" ) )
  {
    notify_fail( new_file_name + ": Permission denied.\n" );
    return 0;
  }
  if( file_size( new_file_name ) != -1 )
  {
    notify_fail( "compress: " + new_file_name + ": already exists.\n" );
    return 0;
  }
  old_lines = explode( old_file, "\n" );
  number_lines = sizeof( old_lines );
  arg = ({
    0,                         /* line number to start on                  */
    number_lines,              /* the number of lines in the file          */
    old_lines,                 /* the file, as an array of its lines       */
    ({ }),                     /* an array for the new version to go into  */
    new_file_name,             /* the file name for the compressed version */
    this_player(),             /* so messages can be given by the call_out */
    0,                         /* so text inside comment marks is unaltered */
  });
  call_out( "compress_lines", 1, arg );
  write( "Please wait " + (number_lines/LIMIT + 1) + " seconds.\n" );
  return 1;
/*
  There is a limit on the number of lines the machine can compress a second.
  If the file has more than this number, call_out must be used to 
  split the processing into chunks to avoid getting the
  "too many executions" error.
*/
}

void compress_lines( mixed a ) /* array a contains a mixture of variables */
{
  string file_name;
  string *old_lines, *new_lines;
  string old_line, new_line;
  int number_lines, line_number, char_number;
  int inside_comment, inside_quotes, line_started, ignore_next;
  int line_ended; // used for this type of comment.
  int limit, add_ch;
  string ch, last_ch, next_ch;
  object player;

  line_number    = a[0];
  number_lines   = a[1];
  old_lines      = a[2];
  new_lines      = a[3]; 
  file_name      = a[4];
  player         = a[5];
  inside_comment = a[6];

  limit = line_number + LIMIT;
  if( limit > number_lines ) limit = number_lines;
  for( ; line_number < limit ; line_number ++ )
  {
/*************** START OF BIT THAT COMPRESSES A SINGLE LINE ****************/
    old_line = old_lines[line_number];
    new_line = "";
    inside_quotes = 0;   /* 0 when outside "" marks, 1 when inside */
    line_started = 0;    /* 0 until the first non-space char in the line */
    line_ended = 0;      // 0 until reach this type of comment.
    ignore_next = 0;     /* Used to cope with \ marks */
    next_ch = old_line[0..0];
    ch = "";
    for( char_number = 0 ; char_number < strlen( old_line ) ; char_number ++ )
    {
      last_ch = ch;
      ch = next_ch;
      next_ch = old_line[(char_number+1)..(char_number+1)];
         /* NB old_line[(char_number+1)] would get a number not a string */
      add_ch = 1;    /* ch gets added to new_line if add_ch remains 1 */
      if( inside_comment || line_ended ) {
        if( ch == "*" && next_ch == "/" ) inside_comment = 0;
         /* If you are inside a comment, check for the end of it. */
         /* add_ch unaltered - text inside coments is copied verbatim */
      } else if( ch != " " && ch != TAB ) {
            /* space and tab are the only chars we delete during compression */
        line_started = 1;  /* we have found a non-space character */
        if( ignore_next ) ignore_next = 0;
        else if( ch == "\\" ) ignore_next = 1;
        else if( ch == "\"" ) inside_quotes = 1 - inside_quotes;
        else if( inside_quotes );
        else if( ch == "/" && next_ch == "*" ) inside_comment = 1;
        else if( ch == "/" && next_ch == "/" ) line_ended = 1;
      } else {
        if( !line_started ) add_ch = 0;
             /* delete all spaces at start of lines */
        else if( !ignore_next && !inside_quotes &&
              /* don't delete spaces inside quotes or comments */
          ( next_ch == " " || next_ch == "" ||
              /* delete more than single spaces and those at end of lines */
            waste_ch( last_ch ) || waste_ch( next_ch ) ||
              /* Delete spaces beside certain characters (see waste_ch() ) */
            next_ch == TAB || last_ch == "<"              ) )
               /* Don't delete spaces before < marks because of includes. */
          add_ch = 0;  /* don't add this ch becuase it is an unwanted space */
      }
      if( add_ch ) new_line += ch;
    }
    new_lines += ({ new_line });
/*************** END OF BIT THAT COMPRESSES A SINGLE LINE ****************/
  }
/* If havn't finished, compress the next bunch of lines */
  if( line_number < number_lines )
  {
    call_out( "compress_lines", 1, ({
      line_number,
      number_lines,
      old_lines,
      new_lines,
      file_name,
      player,
      inside_comment,
    }) );
    tell_object( player, "Lines " + (line_number-LIMIT) + " to " +
      line_number + " compressed.\n" );
    return;
  }
  return resave_file( new_lines, file_name, player );
/* Save the compressed file */
}

/* string array new_lines, string file_name, object player */
void resave_file( mixed new_lines, string file_name, object player )
{
  string new_file;
  mixed err;

  new_file = implode( new_lines, "\n" );
      /* turn the array of lines back into one string */
  new_file += "\n";
  if( err = catch( write_file( file_name, new_file ) ) )
    tell_object( player, "Error: " + err + "\n" );
  else tell_object( player, "Compressed version saved to: " + file_name + "\n");
}

/*
  a is a single character in the form of a string
  This function checks if the ch is one of the characters, next
   to which spaces can be safely deleted.
*/
int waste_ch( string a )
{
  switch( a )
  {
    case "+":  return 1;
    case "-":  return 1;
    case "=":  return 1;
    case ",":  return 1;
    case ";":  return 1;
    case "(":  return 1;
    case ")":  return 1;
    case "{":  return 1;
    case "}":  return 1;
    case ">":  return 1;
    case "|":  return 1;
    case "&":  return 1;
    case "!":  return 1;
    default:   return 0;
  }
/* returns 1 if the space can be deleted, 0 if it can't */
}

string help()
{
  write( ""+
"Syntax: compress <file>[ to <new_file>]\n"+
"Effect: Removes spaces in the file that are unnecessary\n"+
"        for the code to work and copies the version to\n"+
"        <new_file> (which defaults to <file>.comp)\n"+
  "" );
}

