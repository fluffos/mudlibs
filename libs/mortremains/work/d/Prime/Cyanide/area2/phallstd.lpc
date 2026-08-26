// The standard Palace Hall.
// It will get more complex later.
// Cyanide, 4 Jan 2000

inherit ROOM;

int torches;

void create() {
    torches = 3;

    ::create();

    set("light", "@@query_light");
    set("short", "A Hallway in Cyanide's Palace");
    set("long", @EndText
You are in a long torchlit passageway in Cyanide's Palace.
Opulent tapestries and priceless paintings decorate the walls.
EndText
    );
    set("item_desc", ([
      "paintings" : "You see several from Monet and Dali.\n",
      "tapestries" : wrap("They are in a variety of colors and "+
	"represent a vast spectrum of themes."),
      "passageway" : "It's a passageway."
    ]) );
}

int query_light() {
    return(torches > 0);
}

void init () {
    add_action ("exits","exits");
}

int exits() {
    write ("You begin to get a nasty headache.\n");
    say (TPN+" begins to look very confused.\n");
    return 1;
}


/* EOF */
