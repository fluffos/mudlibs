#include <lib.h>

inherit LIB_DAEMON;

int
cmd(string str) {
    return new("/secure/lib/rn")->start_up(str);
}

int help() {
    write(@HELP

syntax:
    rn [-all] [-poster name] [group]
    rn -post group
    rn -list

'rn' starts up an newsreader similar to UNIX rn.  Just typing rn by
itself reads the unread news.  'rn -all' reads all the news.
'rn group' reads the unread posts in a specific group.
'rn -all group' reads all the posts in a group.  To post,
use 'rn -post group', or do followups from within rn.
'rn -list' lists all the groups, similar to the 'L' command
within rn.  '-poster whoever' restricts the posts to be read
to the posts made by 'whoever'.
While in rn, the 'h' command can be used to get a list of options at
most prompts.
HELP);
return 1;
}
