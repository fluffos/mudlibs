#include "garden.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid(getuid());
    set ("author", "cyanide");
    set ("arena" ,1);
    set ("light", 0);
    set ("short", "A Dead End");
    set( "long", @EndText
As you wander throughout the hellish maze you feel has been constructed
especially for your personal torture, you meet a sudden and abrupt stop
in the passage you have been travelling. You are at a dead end. You 
must turn back.
EndText
    );
    set ("exit_suppress", ([
    ]) );

    set ("item_desc", ([
      "humm" : "hummmmmmmmmmmmmm...",
      "labyrinth" : "Cyanide says, \"Nice try, dude.\"\n",
      "corridors" : "Wouldn't that make life too easy? That's no fun!\n",
      "passages" : "Umm... they look like corridors to me...\n",
      "wall" : "The nearest wall look just like all the other walls of this maze\n",
      "maze" : "Yeah, right.\n",
      "walls" : "They seem to be made of a polished black basalt. They humm slightly.\n",
    ]) );
}
