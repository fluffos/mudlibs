//  Rust for GUELib    (ZorkMud)
// Ported to TMI-2 4-21-94
#define BLANKLINE " \
                                                                                        "
#define PROMPT "*"
string verb;
 
 
int cmd_pipe( string arg )
{
 
  object        pipe_server;
 
  if(! arg)
    write("Note:  No verb supplied, each line will be treated as its own command
.\n");
  seteuid( getuid( previous_object() ) );
  pipe_server = clone_object( file_name( this_object() ) );
  pipe_server->_main( arg );
  return 1;
}
 
private void show_prompt()
{
  write("\r"BLANKLINE"\r"PROMPT"\r");
}
 
void _main( string arg )
{
  if( base_name( this_object() ) != file_name( previous_object() ) )
    return;
 
  verb = arg;
 
  write("Entering pipe mode. Type '**' to quit.\n");
  input_to( "handle_piping" );
  show_prompt();
 
}
 
protected
void handle_piping( string arg )
{
 
  if( arg == "**" )
  {
    write( "Done.\n" );
    destruct( this_object() );
    return;
  }
 
  this_player()->force_me( sprintf("%s %s", verb, arg) );
 
  input_to( "handle_piping" );
  show_prompt();
}
 
int help()
{
  write(wrap(
"Syntax:  pipe [command]\n"
"The pipe command is a more powerful version of the old converse command."
" Whatever argument you supply to pipe gets appended to everything you type "
"until you type '**' on a line by itself, at which time the pipe ends. "
"This is meant for people with cut-and-paste, so that you can do "
"'pipe tell rust' and enter a big block of text, without having to type "
"'tell rust' every line, and cut-and-pasting every single line you want to pipe.
\n"
));
 
 return 1;
}
