// _idea.c
// Originally by Sulam@TMI, though the concept is older than that.
// Pallando hacked it to tiny pieces on 2-11-93.
// Mobydick unhacked it from tiny pieces on 3-22-93, even though Pallando
// had already added the ::create() made necessary by a patch elsewhere
//  +
// +++   <-  Cross marking historic battlefield where a war was fought over
//  +         the purity of simplicity vs the ideology of verbiage.
//  +

#include <commands.h>

inherit CMD_PRAISE;

int cmd_idea( string a )
{
	return cmd_report( a );
}

void create()
{
	::create();
	report_type = "idea";
	report_file = "IDEAS";
}

string help()
        {
        return(@HELP
Syntax: idea
 
This command allows you to file a idea report to the admins of the
MUD. The idea should include your idea, and why you think it would
make the MUD better.
 
See also: typo, praise, bug, query
HELP
  );
        }
