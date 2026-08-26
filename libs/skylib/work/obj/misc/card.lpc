// A birthday card given to the creators
// Windy, December 2001

inherit OBJECT_OBJ;

int do_open();

void setup()
{
    set_name("card");
    set_short("birthday card");
    set_long("A large white floppy birthday card. It's currently closed.\n");
    set_read_mess("Perhaps you should open the card first?\n");

    set_value(0);
    set_weight(0);
}

void init()
{
    TP -> add_command("open", TO, "card", (: do_open :) );
}

int do_open()
{
    tell_object( TP, "You slowly open the card...\n");
    tell_room( ENV( TP ), TP -> the_short() +" slowly opens "+ TP -> HIS +" "+
      "card...\n", TP );

    call_out("open2", 4 );

    return 1;
}

void open2()
{
    tell_object( TP, "All of a sudden and out of nowhere, a small firecracker "+
      "shoots out of the card, detonating just above your head!\n");

    call_out("open3", 4 );
}

void open3()
{
    string *ret = ({ });

    foreach( string str in DOMAIN_H -> query_creators() )
    ret += ({ CAP( str ) });

    ret -= ({ TP -> query_short() });

    tell_object( TP, "The explosion reshapes and reforms itself until it reads:\n"+
      "\n**** HAPPY BIRTHDAY "+ TP -> query_short() +" ****\n\nLooking down at the "+
      "card once more, you see its insides slowly change. Perhaps you will be able "+
      "to read it now.\n");
    tell_room( ENV( TP ), TP -> the_short() +" looks quite pleased after having "+
      "opened "+ TP -> HIS +" birthday card.\n", TP);

    TO -> set_long("A large white floppy birthday card. It is currently open.\n");
    TO -> set_read_mess("Happy Birthday "+ TP -> query_short() +"!"+
      "\n\nIt is signed:\n\n"+ query_multiple_short( ret ) +".");
}

