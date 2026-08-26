// Moves you to the common room. It's an extremely complicated command, and
// should you require any help understanding the various algorithms that go
// into its structure, please don't hesitate to ask an admin.
// Windy, Feb '01

inherit COMMAND_BASE;

int cmd( string str )
{
    if( file_name( ENV( TP ) ) == "/w/common" )
        return notify_fail("You look around and realise you are already there.\n");
    else
        TP -> move_with_look("/w/common",
          TP -> query_cap_name() +" arrives in the commons.",
          TP -> query_cap_name() +" transports to the commons.");
    write("You transport to the creator commons.\n");
    return 1;
}
