#include <config.h>
#include <mudlib.h>

inherit PRIVATE_ROOM;
void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set( "short", "Temple");
  set( "long",@EndText
As you enter the Temple you feel the power of your mind reach a
higher state of consciousness. Suddenly your sensitive mind
notices a warmness in the fabric of space. You hear things that
you usualy wouldn't notice, you hear birds singing in the
distance and rivers flowing, you see that there is a blue sky
above you that streches deep into the Temple's Shrine.
EndText
  );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
  ]) );
  set( "item_desc", ([
    "birds" : "Allthough you can't see them you definately hear them.\n",
    "rivers": "The sparkling sound of flowing water announces the presence of water.\n",
    "sky"   : "The sky is made up of the most beautiful shades of blue.\n"
]) );

}


