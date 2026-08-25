// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <log.h>

inherit CMD;
inherit M_GRAMMAR;


#define SYNTAX  "用法: wall <消息>\n"

void create()
{
    ::create();
    no_redirection();
}

private void main( string arg )
{
    string              broadcast;

    if ( !check_privilege(1) )			//原来是"Admin:system"
        error("只有大神才可以用 wall\n"); //"Must be an admin to use wall.\n");

    if( !sizeof( arg ))
    {
        write( SYNTAX );
        return;
    }

    broadcast = sprintf("%s 于 %s 发出系统信息：\n    %s\n",
      this_body()->query_name(), ctime(time()),
      punctuate(arg) );

    LOG_D->log(LOG_WALL, broadcast);

    tell(users(), broadcast, MSG_INDENT);
}
