// Whogot command. Whogot this?
// Windy

inherit COMMAND_BASE;

int cmd( string str )
{
    string ret;
    int flag = 0;
    int count = 0;

    if( !str )
        return notify_fail("Usage: whogot <object name>\n");

    str = lower_case( str );

    ret = "The following people have a(n) "+ str +":\n\n";

    foreach( object player in users() )
    {
        foreach( object ob in deep_inventory( player ) )
        {
            if( ob -> query_short() && ob -> query_name() )
                if( ob -> query_name() == str || ob -> query_short() == str ||
                  ( member_array( str, ob -> query_alias() ) != -1 ) ||
                  strsrch( ob -> query_short(), str ) != -1 )
                {
                    flag = 1;
                    ret += player -> query_cap_name() +": "+ ob -> a_short() +"\n";
                    count++;
                }
        }
    }

    if( !flag )
        return notify_fail("Nobody in "+ mud_name() +" has a(n) "+ str +".\n");

    ret += "\n\nTotal number of \""+ str +"\": "+ count;

    tell_object( TP, ret +"\n" );

    return 1;
}

