/*
// File     :  /daemon/politics.c
// Comment  :  Holds the Council's policies
// 94-07-02 :  Pallando @ Nightmare wrote it
*/
#include <std.h>
#include <save.h>
#include <security.h>

inherit DAEMON;

mapping policies;
mapping income;
mapping spending;
mapping personnel;

void save_me()
{
    unguarded((: save_object, SAVE_POLITICS :));
}

void set_up()
{
    policies = ([]);
    income = ([]);
    spending = ([]);
    personnel = ([]);
    save_me();
}

void create()
{
    daemon::create();
    set_no_clean( 1 );
    unguarded((: restore_object, SAVE_POLITICS :));

    if( !personnel )
	set_up();
}

int query_spending( string arg ) { return spending[arg]; }

void set_spending( string arg, int value )
{
    spending[arg] = value;
    save_me();
}

int query_personnel( string arg ) { return personnel[arg]; }

void set_personnel( string arg, int value )
{
    personnel[arg] = value;
    save_me();
}

mapping query_policies() { return policies; }
mapping query_policy( string title ) { return policies[title]; } 

void set_policy( string title, mapping policy )
{
    policies[title] = policy;
    save_me();
}

void repeal_policy( string title )
{
    map_delete( policies, title );
    save_me();
}

/* EOF */
