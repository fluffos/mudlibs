// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust/Belboz

#include <mudlib.h>

inherit CMD;

void create()
{
  ::create();
  no_redirection();
}

#define USAGE   "用法:  times <#> <command>\n"
private void main( string orig_input, mixed *arg )
{
    int repeats;
    string      command;


    command = implode(arg[1]," ");
    repeats = arg[0];

    if( repeats <= 0 || ( repeats > 10 && !check_privilege(1)) )
    {
        out( "times:  参数超出范围。\n" );
        return;
    }

    while( repeats-- )
        this_user()->force_me( command );
}

