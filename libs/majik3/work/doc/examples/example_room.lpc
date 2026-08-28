inherit ROOM;

create_room ()
{
    set_no_wrap ();
    //include this in your code if you are using ansi colors in your rooms

    set_area ("string");
    //string is the name of your areas where the shout can be heard.
    //ie. if it is "sinister_tunnel" it can be heard in all places which
    //are set_area ("sinister_tunnel") 
    //make sure that you specify the name of the places, so don't just set
    //"tunnel" or "street" as your set_area

    set_light (1);
    //you dont need this line if you want your room to be dark

    set_short ("This is the name of a room. Shouldn't be longer than one line");

    set_long (
      "This is the long description of a room. This should be at least few lines\n"+
      "long, more than just two lines but shouldn't be longer than ten lines. Use\n"+
      "add_items for describing items instead than using long_desc for that purpose\n"+
      "In this room there is a brown wooden table and an item.\n");

    set_sounds (60,"the sounds you want your room to emote");
    //'60' is the amount of seconds during which this emote is "played"

    add_exit ("exit","directory/room");
    add_exit ("south","home/name/room2");
    //you can have as many exits in your room as you want. don't use
    //'s' for south, 'w' for west or stuff, use 'west' and 'south' etc.

    add_item ("item","description of an item");
    add_item (({"brown wooden table","wooden table","table","brown table"}),
      "description of an item. for example: this is a brown wooden table that\n"+
      "is in this room just for an example. it is made of oak etc.\n"); 
    //usually you should have "aliases" for an item like the wooden table
    //above and those aliases should be those that you have mentioned in
    //room desc.
}
