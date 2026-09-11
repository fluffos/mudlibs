// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#ifdef USE_STATUS_LINE

#include <mudlib.h>
inherit CMD;
 
private void main( string arg )
{
    if( !arg )
    {
        if( this_body()->query_shell_ob()->get_variable( "status" ))
            arg = "off";
        else arg = "on";
    }

    switch( arg )
    {
        case "on":
            this_body()->query_shell_ob()->set_variable( "status", 1 );
            this_body()->update_status_line();
            break;
        case "off":
            this_body()->query_shell_ob()->unset_variable( "status" );
            this_body()->remove_status_line();
            break;
        default:
            out( "用 \"sline on\", \"sline off\", or just \"sline\" 来转换。\n");
    }
}

#endif
