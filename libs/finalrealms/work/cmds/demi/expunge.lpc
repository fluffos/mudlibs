#define SECURE_MASTER "/secure/master"
// global/lord/cmds/demote.c
// demote immortals.
//
// 96 May 23 Laggard    new command.
//
#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;




string query_usage()
{
    return "expunge <name> <reason>";
}


string query_short_help()
{
    return "Depending on the current status of the target,"
            " and the rank of the command user,"
            " will remove an immortal and all the domain permissions.";
}


protected int cmd( string values, object commander )
{
    string name;
    string reason;

    if ( !values  ||  values == "" )
    {
        notify_fail( query_usage() + "\n" );
        return 0 ;
    }
    if (sscanf(values,"%s %s",name, reason) != 2)
    {
        notify_fail("You must give a reason!\n");
        return 0;
    }
    if ( SECURE_MASTER->query_worker(name) )
    {
        return SECURE_MASTER->expunge_creator(name, reason);
    }
    notify_fail(capitalize(name) + " not found.\n");
    return 0;
}



