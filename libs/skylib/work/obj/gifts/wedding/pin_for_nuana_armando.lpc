// My wedding gift to Armando and Nuana. I wish them
// the best in the future.
// Windy Wibbles, March 2002

inherit ARMOUR_OBJ;

int suggest( string str );
int send( string mess );
void update_other();
string parse_mess( string mess );

object other = ( TP -> query_name() == "armando" ?
  find_player("nuana") : find_player("armando") );
string prop = TP -> query_property("wedding_pin");
string prop2;

void setup()
{
    set_name("pin");
    set_short("small silver pin");
    set_long("This small silver pin, while little more than a "+
      "heart-shaped piece of silver, seems to radiate feelings of warmth "+
      "and love. It must truly be something valuable to someone.\n");
    set_type("badge");
    set_cond(1000);
    set_damage_chance(0);
    set_weight(0);
    set_value(0);
    set_read_mess("This pin is very special. It allows those who have "+
      "developed the ultimate bond to be able to express their feelings "+
      "even more than they have already. You and your lover will have a special "+
      "channel to communicate on, reserved for just the two of you. Use the "+
      "command 'mychan <name>' to suggest a channel name - when your spouse "+
      "uses the command with the same name, the name will be finalised and your "+
      "channel will be created. Then, just use <name> <message>, just like a "+
      "normal channel would be used to communicate. You may emote over your "+
      "channel with the @ key. If you wish to change your channel name, "+
      "all you need to do is suggest a new name and have your spouse "+
      "approve it.\n");
}

void init()
{
    update_other();

    if( TP -> query_name() != "armando" && TP -> query_name() != "nuana" &&
      TP -> query_name() != "windy" )
    {
        tell_object( TP, "You somehow feel that the pin has deemed you unworthy of "+
          "holding it. It disappears.\n");
        TO -> move("/room/rubbish");
    }


    TP -> add_command("mychan", TO, "<string'name'>",
      (: suggest( $4[0] ) :) );
    if( ( prop && prop2 ) && ( prop == prop2 ) )
        TP -> add_command( prop, TO, "<string'message'>",
          (: send ( $4[0] ) :) );
}


int suggest( string str )
{
    update_other();

    if( !other )
        return notify_fail("Unfortunately, your spouse is not online to receive your "+
          "suggestion.\n");

    tell_object( TP, "You suggest to "+ other -> query_short() +" that your "+
      "private channel be named "+ str +".\n");
    // tell the other spouse in here
    if( other )
        tell_object( other, TP -> query_short() +" has suggested that your private "+
          "channel be named "+ str +".\n");

    TP -> add_property("wedding_pin", str );

    update_other();

    if( ( prop && prop2 ) && ( prop == prop2 ) )
    {
        tell_object( TP, "With both of you having agreed on the channel name, the "+
          "channel is created.\n");
        tell_object( other, "With both of you having agreed on the channel name, "+
          "the channel is created.\n");
        init();
    }

    return 1;
}

int send( string mess )
{
    update_other();

    mess = parse_mess( mess );

    tell_object( TP, mess );
    if( other )
        tell_object( other, mess );
    return 1;
}

void update_other()
{
    other = ( TP -> query_name() == "armando" ?
      find_player("nuana") : find_player("armando") );
    prop = TP -> query_property("wedding_pin");

    if( other )
        prop2 = other -> query_property("wedding_pin");
}

string parse_mess( string mess )
{
    string ret = "%^MAGENTA%^";

    ret += "("+prop+") "+ TP -> query_cap_name();

    if( mess[0..0] == "@" )
        ret += " " + mess[1..strlen(mess)-1];
    else
        ret += ": "+ mess;

    return ret + "%^RESET%^\n";
}
