#include <config.h>
#include <mudlib.h>

inherit PRIVATE_ROOM;


void init(){
::init();
add_action("sit_hammock","sit");
add_action("flop_hammock","flop");
add_action("swing_hammock","swing");
add_action("read_heart","read");
}

int sit_hammock(string str){
if (!str ||str!= "hammock"){
write("Sit where?\n");
return 1;
}

say(TPN+" sits down in the large hammock and rests.\n");
write(wrap(
"You sit down in the hammock and wrap yourself up with the blanket\n"+
"There is room for more than one person here.\n"));
return 1;
}

int flop_hammock(string str){
if (!str || str!= "hammock"){
write("Flop where?\n");
return 1;
}

say (TPN+ " flops on the hammock and falls backwards on their head!\n");
write(wrap("You rush over to the hammock and flop on it. Sadly, you \n" +
"can not maintain your balance and it pitches you backwards on to \n"+
"your head.\n"));
return 1;
}

int read_heart(string str){
if (!str || str!= "heart"){
write("Read what?\n");
return 1;
}

say (TPN+ " takes a look at the heart carved in the tree.\n");
write(wrap("You take a look at the heart carved in the tree. The \n" +
"information has faded over the years but you think you can make \n"+
"out the initials SW + RH 1919. \n"));
return 1;
}

int swing_hammock(string str){
if(!str || str!= "hammock") {
write ("Swing what?\n");
return 1;
}

say (TPN+ " lays back in the hammock and swings back and forth \n" +
"in the sunlight causing the tension to fade from their body. \n");
write(wrap("You lean back in the hammock and swing it in the breeze. \n" +
"You soon feel your eyes get heavy and you drift off into a \n" +
"relaxing slumber. \n"));
return 1;
}

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set("short","An open spot in the Forest");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set("c_long",@EndLong
You have entered a break in the woods. It is clear that many
people come here to relax and enjoy nature. There are trees
all around you and the weather is simply perfect. You can see
a hammock hanging between two of the trees and some writing
on the big oak near by.
EndLong
    );
    set( "exits", ([
      "start" : START,
      "void"  : VOID,
    ]) );

set ("item_desc", ([
"hammock":"This is a sturdy hammock which has been left up. There are pillows \n"+
"and blankets on it. You can probably sit or flop on it.\n",
"tree":"This is and old, sturdy oak tree. It looks like some long \n" +
"lost lovers once carved their initials on it in a heart.\n",
"oak":"This is an old, sturdy oak tree. It looks like some long \n" +
"lost lovers once carved their initials in it. You might be able \n" +
"read the heart.\n",
"heart":"This heart has faded over the years. Maybe you can read it \n"+
"and find out who these lovers were from so long ago.\n",
]));
}
