/*
// This file is a part of the TMI distribution mudlib.
// Please retain this header if you use this code.
// Devised & Written by Douglas Reay (Pallando @ TMI, Ephemeral Dale, etc)
// (25-11-92): Moved to TMI-II
// (28-11-92): env vars, runtime options and tab indenting added.
// (11-12-92): type given for argument of cmd_uncompress()
// (30-12-92): function type vars delt with.
// NB Does not handle @ENDTEXT ENDTEXT constructions.
//    See entry in TMI's ideas file
*/
#include <disclaimer.h>

#include <mudlib.h>

inherit DAEMON;

void uncompress_lines( mixed a );
void resave_file( mixed new_lines, string file_name, object player );
int is_letter( string a );
int sum( mixed overhang, int levels );
string stripped( string a );
string help();

#define STATIC_VARIABLES   a[0]
#define SV_big_indent      STATIC_VARIABLES[0]
#define SV_little_indent   STATIC_VARIABLES[1]
#define SV_file_name       STATIC_VARIABLES[2]
#define SV_player          STATIC_VARIABLES[3]
#define SV_limit           STATIC_VARIABLES[4]
#define SV_screen_width    STATIC_VARIABLES[5]
#define PAST_LINES         a[1]
#define PL_overhang        PAST_LINES[0]
#define PL_bracket_stack   PAST_LINES[1]
#define PL_bracket_stack_pointer PAST_LINES[2]
#define PL_nested_cbs      PAST_LINES[9]
#define PL_nested_rbs      PAST_LINES[10]
#define PL_pre_proc_mode   PAST_LINES[3]
#define PL_inside_comment  PAST_LINES[4]
#define PL_last_rbs        PAST_LINES[5]
#define PL_last_cbs        PAST_LINES[6]
#define PL_last_overhang   PAST_LINES[7]
#define PL_last_comment    PAST_LINES[8]
/*
  NB the limit is necessary to stop error: too long execution.
     the static_variables and the past_lines are necessary in order to
     stop the error: too many local variables.
  static_variables are ones whose values arn't changed in the central
  function uncompress_lines();  past_lines are variables whose values
  depend on what has happened in the lines already uncompressed.
  last_cbs, etc refer to the previous line's value of cbs, etc.
  cbs stands for curly brackets
  rbs stands for round brackets
  overhang is the sort of indentation you get after an if statement without
  curly brackets.
*/
#define SPACES "                                                            \
                                                                            \
                                                                            \
               "
#define WIDTH( x )         ( SPACES )[1..( x )]
#define TAB                "\t"
#define TAB_WIDTH( x )     ( "\
\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\
\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\
\t\t\t\t\t\t\t\t\t\t\t\t\t" )[1..( x )]
#define START_CH           new_line[0..0]
#define SYNTAX ""+\
  "Syntax: uncompress <old_file>[ to <new_file>][ @ <speed>][ \" <size>]"+\
  "[ < <width>]\n"
#define OPTIONS ({ "to", "@", "\"", "<" })
#define DEFAULT_SCREEN_WIDTH 80

int cmd_uncompress( string a )
{
  string old_file;
  string *old_lines;
  string old_file_name, new_file_name;
  int number_lines;
  string * options;
  int number_options;
  int i;
  mixed arg;
  mixed screen_width;
  mixed max_limit, big_indent, little_indent;
  object player;
  
// GET THE PLAYERS OPTIONS FROM a AND FROM THEIR env vars
// THEN CHECK THE VALIDITY OF THOSE OPTIONS
  if( !a ) { notify_fail( SYNTAX ); return 0; }
  options = explode( a, " " );
  number_options = sizeof( options );
  old_file_name = options[0];
  if( -1 != member_array( old_file_name, OPTIONS ) )
    { notify_fail( SYNTAX ); return 0; }
  player = this_player();
  if( ( i = ( 1 + member_array( "to", options ) ) ) && i < number_options )
    new_file_name = options[i];
  if( !new_file_name && number_options > 1 && 
    -1 == member_array( options[1], OPTIONS ) )
    new_file_name = options[1];
// incase someone gets the syntax wrong and leaves the "to" out
  if( !new_file_name ) new_file_name = old_file_name + ".uncomp";
  if( ( i = ( 1 + member_array( "@", options ) ) ) && i < number_options )
    max_limit = options[i];
  if( !max_limit ) max_limit = player-> getenv( "INDENT_SPEED" );
  if( !max_limit || !sscanf( max_limit, "%d", max_limit ) ) max_limit = 20;
  if( ( i = ( 1 + member_array( "\"", options ) ) ) && i < number_options )
    big_indent = options[i];
  if( !big_indent ) big_indent = player-> getenv( "INDENT_SIZE" );
  if( big_indent ) sscanf( big_indent, "%d", big_indent );
  if( !big_indent ) big_indent = 2;
  if( big_indent == 1 ) little_indent = 1;
  else if( big_indent > 1 ) little_indent = 2;
  else little_indent = -1;
// NB negative indent size means use tabs
  if( i = ( 1 + member_array( "<", options ) ) )
  {
    if( i < number_options ) screen_width = options[i];
    else screen_width = "";
  }
  if( !screen_width ) screen_width = player-> getenv( "INDENT_WIDTH" );
  if( screen_width == "" )
  {
    screen_width = player-> getenv( "INDENT_WIDTH" );
    if( !screen_width ) screen_width = "";
  }
  if( screen_width )
    if( !sscanf( screen_width, "%d", screen_width ) )
      screen_width = DEFAULT_SCREEN_WIDTH;
  seteuid( getuid( previous_object() ) );
  old_file_name = resolv_path( this_player()-> query( "cwd" ), old_file_name );
  switch( file_size( old_file_name ) )
  {
    case - 2: notify_fail( "uncompress: " + old_file_name + ": directory\n" ); return 0;
    case - 1: notify_fail( "uncompress: " + old_file_name + ": no such file\n" ); return 0;
  }
  if( !master()-> valid_read( old_file_name,
    ( string ) this_player()-> query( "name" ), "uncompress" ) )
  {
    notify_fail( old_file_name + ": Permission denied.\n" );
    return 0;
  }
  new_file_name = resolv_path( this_player()-> query( "cwd" ), new_file_name );
  if( !master()-> valid_write( new_file_name,
    ( string ) this_player()-> query( "name" ), "uncompress" ) )
  {
    notify_fail( new_file_name + ": Permission denied.\n" );
    return 0;
  }
  if( file_size( new_file_name ) !=  - 1 )
  {
    notify_fail( "uncompress: " + new_file_name + ": already exists\n" );
    return 0;
  }
  old_file = read_file( old_file_name );
  if( !old_file ) { notify_fail( old_file_name + " is empty.\n" ); return 0;  }
/* END OF VALIDITY CHECKING */
  old_lines = explode( old_file, "\n" );
  number_lines = sizeof( old_lines );
  arg = ({
    ({ //                    static_variables who values don't change
      big_indent, //         number of spaces on next line after a {
      little_indent, //      number of spaces on next line after if()
      new_file_name, //      the uncompressed version's file name
      player, //             so messages can be given by the call_out
      max_limit, //              Max lines to process per second.
      screen_width, //       Whether to chop off lines that would go over it
    }),
    ({ allocate( 40 ) }) + //overhang per level of curly brackets
    ({ allocate( 40 ) }) + //order of ([ and [ that have appeared
    allocate( 40 ), //       information dependant on past lines
    0, //                    line number to start on
    number_lines, //         the number of lines in the file
    old_lines, //            the file, as an array of its lines
    ({  }), //               an array for the new version to go into
  });
  call_out( "uncompress_lines", 1, arg );
  write( "Uncompressing in stages ...\n" );
  write( "Please wait " + ( number_lines/max_limit + 1 ) + " seconds.\n" );
  return 1;
}

void uncompress_lines( mixed a )
{
  string *old_lines;
  string *new_lines;
  string old_line, new_line;
  int number_lines, line_number, char_number;
  int inside_quotes, ignore_next, end_line;
  int line_length, indent, limit;
  string ch, last_ch, next_ch, add_ch, end_ch;
  
  line_number = a[2];
  number_lines = a[3];
  old_lines = a[4];
  new_lines = a[5];
  
  limit = line_number + SV_limit;
  if( limit> number_lines ) limit = number_lines;
  for( ; line_number <limit; line_number++ )
  {
    
/************ START OF PART THAT PROCESSES A SINGLE LINE ************/
    old_line = old_lines[line_number];
    new_line = "";
    line_length = strlen( old_line );
    inside_quotes = 0;
    end_line = 0;
    ignore_next = 0;
    next_ch = old_line[0..0];
    ch = "";
    end_ch = "";
    for( char_number = 0; char_number <line_length; char_number++ )
    {
      last_ch = ch;
      ch = next_ch;
      next_ch = old_line[( char_number + 1 )..( char_number + 1 )];
      add_ch = 0;
      // deep magic starts here
      if( PL_inside_comment || end_line )
      {
        if( ch + next_ch == "*/" ) PL_inside_comment = 0;
        add_ch = ch;
      } else if( ignore_next == 2 ) {
        ignore_next = 0;
        add_ch = "";
      } else if( ignore_next ) {
        ignore_next = 0;
        add_ch = ch;
      } else if( ch == "\\" ) {
        ignore_next = 1;
        add_ch = ch;
      } else if( ch == "\"" ) {
        inside_quotes = 1 - inside_quotes;
        add_ch = ch;
      } else if( inside_quotes ) {
        add_ch = ch;
      } else switch( ch + next_ch ) {
        case "==": add_ch = " == "; ignore_next = 2; break;
        case "<=": add_ch = " <= "; ignore_next = 2; break;
        case ">=": add_ch = " >= "; ignore_next = 2; break;
        case "!=": add_ch = " != "; ignore_next = 2; break;
        case "+=": add_ch = " += "; ignore_next = 2; break;
        case "-=": add_ch = " -= "; ignore_next = 2; break;
        case "||": add_ch = " || "; ignore_next = 2; break;
        case "&&": add_ch = " && "; ignore_next = 2; break;
        case "()": add_ch = "()"; ignore_next = 2; break;
        case "++": add_ch = "++"; ignore_next = 2; break;
        case "--": add_ch = "--"; ignore_next = 2; break;
        case "->": add_ch = "-> "; ignore_next = 2; break;
        case "({": add_ch = "({ "; ignore_next = 2; PL_nested_cbs++; break;
        case "})": add_ch = " })"; ignore_next = 2; PL_nested_cbs--; break;
        case "(:": add_ch = "(: "; ignore_next = 2; PL_nested_cbs++; break;
        case ":)": add_ch = " :)"; ignore_next = 2; PL_nested_cbs--; break;
        case "([":
        {
          ignore_next = 2;
          PL_nested_cbs++;
          add_ch = "([ ";
          PL_bracket_stack_pointer++;
          PL_bracket_stack[PL_bracket_stack_pointer] = "])";
          break;
        }
        case "])":
        {
          if( PL_bracket_stack[PL_bracket_stack_pointer] == "])" )
          {
            add_ch = " ])";
            ignore_next = 2;
            PL_nested_cbs--;
            PL_bracket_stack[PL_bracket_stack_pointer] = 0;
            PL_bracket_stack_pointer--;
            break;
          }
/* treat as seperate ] and ) */
          break;
        }
        case "/*": add_ch = "/"; PL_inside_comment = 1; break;
        case "//": add_ch = "/"; end_line = 1; break;
      } if( !add_ch ) switch( ch ) {
        case "(": add_ch = "( "; PL_nested_rbs++; break;
        case ")":
        {
          PL_nested_rbs--;
          add_ch = " )";
          if( is_letter( next_ch ) ) add_ch += " ";
          break;
        }
        case "{": add_ch = " { "; PL_nested_cbs++; break;
        case "}":
        {
          add_ch = " } ";
          PL_overhang[PL_nested_cbs] = 0;
          PL_nested_cbs--;
          break;
        }
        case "+": add_ch = " + "; break;
        case "-": add_ch = " - "; break;
        case "=": add_ch = " = "; break;
        case ">":
        {
          add_ch = "> ";
          if( !is_letter( last_ch ) ) add_ch = " > ";
          break;
        }
        case "<":
        {
          add_ch = "<";
          if( last_ch != " " ) add_ch = " <";
          if( !is_letter( next_ch ) ) add_ch += " ";
          break;
        }
        case ";": add_ch = "; "; break;
        case ",": add_ch = ", "; break;
        case "[":
        {
          PL_bracket_stack_pointer++;
          PL_bracket_stack[PL_bracket_stack_pointer] = "]";
          add_ch = "[";
          break;
        }
        case "]":
        {
          PL_bracket_stack[PL_bracket_stack_pointer] = 0;
          PL_bracket_stack_pointer--;
          add_ch = "]";
          break;
        }
        default: add_ch = ch; break;
      }
      if( !end_line && !PL_inside_comment &&
        ch != " " && ch != "" && ch != TAB )
        end_ch = ch;
      new_line += add_ch;
    }
    if( !PL_last_comment )
      new_line = stripped( new_line ); /* gets rid of spaces at start and end */
    if( PL_last_comment || START_CH == "/" )
    {
      indent = 0;
    } else if( PL_pre_proc_mode ) {
      if( end_ch != "\\" ) PL_pre_proc_mode = 0;
      indent = SV_big_indent;
    } else if( START_CH == "#" ) {
      if( end_ch == "\\" ) PL_pre_proc_mode = 1;
      indent = 0;
    } else {
      indent = SV_big_indent *
      ( PL_nested_cbs <PL_last_cbs ? PL_nested_cbs : PL_last_cbs );
      if( PL_nested_cbs> PL_last_cbs )
      {
        if( PL_overhang[PL_last_cbs] ) PL_overhang[PL_last_cbs]--;
      }
      indent += SV_big_indent * sum( PL_overhang, PL_nested_cbs );
      if( PL_nested_cbs == PL_last_cbs && START_CH == "}" )
        indent -= SV_big_indent;
      if( PL_last_rbs ) indent += SV_little_indent;
      if( PL_nested_rbs || end_ch == "+" || end_ch == "-" )
      {
        PL_last_rbs = 1;
      } else {
        PL_last_rbs = 0;
        if( end_ch == ")" || end_ch == "e" ) {
          PL_last_overhang = PL_nested_cbs;
          PL_overhang[PL_nested_cbs]++;
        } else {
          PL_overhang[PL_nested_cbs] = 0;
        }
      }
      PL_last_cbs = PL_nested_cbs;
    }
    if( SV_screen_width )
    {
      if( START_CH == "\"" && end_ch == "+" ) indent = 0;
/*
// the next few lines temporarily removed until someone transferres them
// to yet another option
      if( SV_screen_width >= strlen( new_line ) && SV_screen_width <
        ( strlen( new_line ) + ( ( indent > 0 ) ? indent : (-8 * indent) ) ) )
        indent = 0;
*/
    }
    PL_last_comment = PL_inside_comment;
    new_line = ( ( indent < 0 ) ? TAB_WIDTH( (-indent) ) : WIDTH( indent ) ) +
      new_line;
    new_lines += ({ new_line });
/************ END OF PART THAT PROCESSES A SINGLE LINE ************/
    
  }
  if( line_number <number_lines )
  {
    call_out( "uncompress_lines", 1, ({
        STATIC_VARIABLES,
        PAST_LINES,
        line_number,
        number_lines,
        old_lines,
        new_lines,
      }) );
    tell_object( SV_player, "Lines " + ( line_number - SV_limit ) + " to " +
      line_number + " uncompressed.\n" );
    return;
  }
  return resave_file( new_lines, SV_file_name, SV_player );
}

void resave_file( mixed new_lines, string file_name, object player )
{
  string new_file;
  mixed err;
  
  new_file = implode( new_lines, "\n" );
  new_file += "\n";
  if( err = catch( write_file( file_name, new_file ) ) )
    tell_object( player, "Error: " + err + "\n" );
  else
    tell_object( player, "Compressed version saved to: " + file_name + "\n" );
  return;
}

// totals the overhang upto the current cbs level
int sum( mixed overhang, int levels )
{
  int i, s;
  
  for( i = 0; i  <= levels; i++ )
    s += overhang[i];
  return s;
}

string stripped( string a )/* removes spaces from start and end of a */
{
  int i, s, start_line, end_line;
  
  if( !a || a == "" ) return "";
  s = strlen( a );
  for( i = 0; i <s; i++ )
  {
    if( a[i] != ' ' )
    {
      end_line = i;
      if( !start_line ) start_line = i + 1;
    }
  }
  return a[( start_line - 1 )..( end_line )];
}

int is_letter( string a )
{
  return( a[0] >= 'a' && a[0] <= 'z' ) || ( a[0] >= 'A' && a[0] <= 'Z' );
}

string help()
{
  return( "" +
    SYNTAX +
"Effect: If you have used the mud's compress command to create a file <old_file>\n"+
"  then uncompress will put a more readable version in the file <new_file>\n"+
"  <size> determines how many spaces are used to indent each line.\n"+
"  if <size> is negative then tabs are used.\n"+
"  <speed> determines how many lines per second are uncompressed.\n"+ 
"  The maximum speed the command will work at depends on how short the lines\n"+
"  are and how high an evaluation cost your driver allows.\n"+
"  <new_file> defaults to <old_file>.uncomp\n"+
"  <size> can be specified by an environmental variable INDENT_SIZE\n"+
"  otherwise <size> defaults to 2 spaces per level of bracket nesting.\n"+
"  <speed> can be specified by an environmental variable INDENT_SPEED\n"+
"  otherwise <speed> defaults to 20 lines per second.\n"+
"  If <width> is specified, then lines arn't indented if that would put\n"+
"  them over the specified screen width.  If just the < mark is given it\n"+
"  will default to 80 characters ( or env INDENT_WIDTH if set).\n"+
"  eg:\n"+
"  uncompress file1.c file2.c \" -1 @ 30 <\n"+
"  would put an uncompressed version of file1.c into file2.c, using tabs\n"+
"  for indentation, at 30 lines per second, trying to fit lines into an 80\n"+
"  character width screen!\n"+
"  NB if a file is particularly dense (man characters per line) use a low speed.\n"+
    "" );
}

