// Christmas Tree
// Windy, December 2001

#define SAVE "/save/misc/tree"

inherit OBJECT_OBJ;

mapping d;
nosave string name, long;

int query_decorations() { return sizeof( d ); }
void add_2( string str );
void add_final( string long, string name );
int do_look( string name );
void save_me();
void load_me();


void create()
{
    d = ([ ]);

    load_me();

    ::create();
}

void setup()
{
    set_name("tree");
    set_short("%^BOLD%^Christmas Tree%^RESET%^");
    set_long("A beautiful Christmas Tree. It is adorned with various little items "+
      "that have been added by passers-by. It now has "+ query_decorations() +" "+
      "decoration"+(sizeof(d) != 1 ? "s" : "" )+" on it!\n\n"+
      "Read the sign for details!\n");

    reset_get();
}

void init()
{
    TP -> add_command("add", TO, "decoration" );
    TP -> add_command("browse", TO, "decorations");
    TP -> add_command("look", TO, "[at] <string'playername'> decoration",
      (: do_look( $4[0] ) :) );
}

int do_add()
{
    tell_object( TP, "What is the name of your decoration?\n");
    input_to( (: add_2 :) );

    return 1;
}

void add_2( string str )
{
    tell_object( TP, "What is the description of your decoration?\n");
    input_to( (: add_final :), 0, str );
}

void add_final( string long, string name )
{
    d[TP -> query_name()] = ([ name : long ]);

    tell_object( TP, "You add to the tree "+ name +" that looks like: "+ long +".\n");
    setup();
    save_me();
}

int do_browse()
{
    string s, ret = "";
    mapping j;

    if( !sizeof( d ) )
        return notify_fail("There are no decorations on the tree!\n");

    foreach( string str in keys( d ) )
    {
        s = CAP( str ) +": ";
        j = d[str];

        s += keys( j )[0] +"\n";

        ret += s;
    }

    tell_object( TP, "You see "+ query_decorations() +" "+
      (sizeof(d) != 1 ? "decorations" : "decoration" ) +":\n"+ ret +"");
    tell_room( ENV( TP ), TP -> the_short() +" looks at the tree to see what "+
      "decorations it has.\n", TP );
    return 1;
}

int do_look( string name )
{
    mapping m;
    name = lower_case(name);

    if( name[<2..] == "'s" )
        name = name[0..<3];

    if( !m = d[name] )
    {
        add_failed_mess( CAP( name ) +" doesn't have a decoration on the tree!\n");
        return 0;
    }

    tell_object( TP, "You look at "+ CAP( name ) +"'s "+
      keys( m )[0] +":\n"+ values( m )[0] +"\n");
    tell_room( ENV( TP ), TP -> the_short() +" looks at "+ CAP( name ) +"'s "+
      "decoration.\n", TP );

    return 1;
}


void save_me()
{
    unguarded( (: save_object, SAVE, 1 :) );
}

void load_me()
{
    unguarded( (: restore_object, SAVE, 1 :) );
}
