/*
 *    /www/gateways/source.c
 *
 *    Not sure what Truilkan's code did, but the situation was that this
 *    gateway would be called if the specified URL directory didn't contain
 *    an index.html file.  So, I'm just winging something.  =)
 */

#include <mudlib.h>
#include <config.h>
#include <daemons.h>
#include <commands.h>

inherit DAEMON;


string gateway( string args )
{
    mixed *dirlist;
    string str;
    int i, s;

    dirlist = get_dir(args + "*.html");
    if (sizeof(dirlist)) {
        /* strip off .html extension */
        /*
         * too bad HTML spec doesn't have some standard method of querying
         * an HTML document for a description...*sigh*
         */
        dirlist = map_array(dirlist,
              (: sprintf("<LI><A HREF=\"%s\">%s</A>", $1, $1[0..<6]) :));

        /* present contents of html directory */
        return sprintf( @EndFormat
<HTML><HEAD><TITLE>HTML Finder</TITLE></HEAD>
<BODY><H1>HTML Finder</H1>
The requested URL is incomplete.  Please pick one of the following:
<UL>
%s
</UL>
</BODY></HTML>
EndFormat,
              implode(dirlist, "\n"));
    } else {
        /* error */
        return @EndError
<HTML><HEAD><TITLE>404 Not Found</TITLE></HEAD>
<BODY><H1>404 Not Found</H1>
The requested URL is incomplete and cannot be resolved on this server.<P>
</BODY></HTML>
EndError;
    }
}
