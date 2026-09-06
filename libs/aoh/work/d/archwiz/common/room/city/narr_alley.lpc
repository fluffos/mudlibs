#include "path.h"
#include "moving.h"

inherit "std/room";

public int enter(string str)
{
  if (!this_player()) return 0;
  if (str!="well")
    return (int) notify_fail("Enter what?\n") && 0;
  this_player()->move(WELL("well"),M_GO,"down");
  return 1;
}

public void create()
{
  (::create());
  SetIntShort("Narrow alley");
  SetIntLong(
"A narrow alley. There is a well in the middle. East is the entrance to "
"a bank and south is the main post office of Nightfall. To the north "
"you can hear the busy streets of Nightfall. To the west lies the Central "
"Airport of Nightfall.\n");
  AddExit("north", "./vill_road1");
  AddExit("east",  "./bank");
  AddExit("south", "./post");
  AddExit("west",  "./airport1");
  AddExit("down",  WELL("well"));
  HideExit("down",1);
  AddExit("enter", #'enter);
  HideExit("enter",1);
  AddDetail("well",
"You look down the well, but see only darkness. "
"There are some iron handles on the inside.\n");
  AddDetail(({"bank","building","white building",
              "white stone-building","stone-building",
              "gigantic building","gigantic stone-building"}),"\
You are amazed by this gigantic white stone-building. A stair with four "
"steps leads up to the entrance, a wide open portal with two golden leaves. "
"Two big columns hold a part of the roof.\n"
"On each side of the portal is a relief and above each of them there's a "
"small window.\n");
  AddDetail("stair","\
It's made of white marble. You only see a little dirt on it. The owners "
"of the bank seem to take care of the bank.\n");
  AddDetail(({"steps","four steps"}),"\
Four steps of white marble lead up to the entrance, a golden portal.\n");
  AddDetail(({"step","largest step","large step"}),"\
The step right in front of you is the largest one. Up to the top they "
"become smaller.\n");
  AddDetail("entrance","\
The entrance is a big golden portal guarded by two giant flower-pots in "
"which red flowers are growing.\n");
  AddDetail(({"wide open portal","wide portal","portal","open portal",
              "golden portal","big portal","big golden portal"}),"\
Two golden leaves build the portal which must be about 3 metres in height "
"and each of them 1.5 metres in width. The whole portal is an engraving "
"showing a heap of coins of different sorts.\n");
  AddDetail(({"leaves","golden leaves","two leaves","two golden leaves"}),"\
Each of them must be about 3 metres in height and 1.5 metres in width. "
"The heap of coins on them shows a nice art-work.\n");
  AddDetail(({"leaf","golden leaf","leaf of the portal","leaf of portal",
              "golden leaf of the portal","golden leaf of portal"}),"\
It looks very heavy and you wonder who put it there. Perhaps only a "
"magician was able to put it there.\n");
  AddDetail(({"two big columns","columns","big columns",
              "corinthian columns"}),"\
The corinthian columns are made of a white marble with some gray lines "
"inside. They carry a part of the roof which is high above you. "
"On the ceiling you see a colourful painting.\n");
  AddDetail(({"column","big column","corinthian column"}),"\
It carries a part of the roof.\n");
  AddDetail(({"roof","gable","flat triangle","triangle"}),"\
It is high above you and to get a better look at it you take some steps "
"backwards. Then you have a wonderful sight on the gable. It's a very flat "
"triangle completely made out of white marble. A picture in the middle shows "
"a balance and lots of money build to lots of small towers at each side of "
"the balance.\n");
  AddDetail(({"left relief","relief","relief 1"}),"\
The relief hewn into the white marble shows a money-changer who's wearing "
"glasses and actually counting the money in front of him on the table. "
"A money-bag left of him seems to be well filled with money.\n");
  AddDetail(({"right relief","relief 2"}),"\
The relief hewn into the white marble shows a caravan of traders, each of "
"them with different goods like for example carpets, spices and wine. "
"In the background there might be something like a desert, but you only "
"recognize flat hills which might be dunes and high above in the sky "
"there's the sun.\n");
  AddDetail(({"windows","window","small window","small windows"}),"\
Each of the windows has a grating in front of it, made of strong iron.\n");
  AddDetail(({"white marble","marble"}),"\
It's one of the finest sorts of marble you have ever seen. Of course you "
"never did see such a marble anywhere else than in the capital, in Nightfall- "
"City. But that's just normal, isn't it?\n");
  AddDetail(({"bank-owners","owners","owners of bank","owners of the bank"}),"\
You can't find the owners of the bank here or at least no person which looks "
"like someone who might own a bank like this.\n");
  AddDetail(({"pots","flower-pots","giant flower-pots","two pots",
              "two flower-pots","two giant flower-pots",
              "giant pots","two giant pots"}),"\
They are made of white marble just like nearly the whole building ... But "
"something is special with them. -\n"
"Oh, you can't believe it. They seem to have grown directly out of the "
"marble. You can't detect any line at the bottom of the pots where they might "
"be placed onto the marble. It seems as if the artist who build this bank "
"made the whole ground including the pots of one piece of marble.\n");
  AddDetail(({"flowers","red flowers","flower","red flower","roses",
              "red roses","red rose","rose"}),"\
The red flowers are beautiful red roses with a narcotic scent.\n");
  AddSmell(({"flowers","red flowers","flower","red flower","roses",
              "red roses","red rose","rose"}),
    "You nearly loose your consciousness.\n");
  SetExplorable(({"smell:flowers","smell:red flowers","smell:flower","smell:red flower","smell:roses",
                  "smell:red roses","smell:red rose","smell:rose"}));
  AddDetail(({"engraving","art-work"}),"\
The engraving on the portal shows a heap of coins of different sorts from "
"all over Nightfall. Some of them you even didn't know up to now. They seem "
"to be very old coins.\n");
  AddDetail(({"heap of coins","coins"}),"\
The coins on the engraving all look different.\n");
  AddDetail(({"lines","gray lines","grey lines"}),"\
They show that this a different kind of marble.\n");
  AddDetail("ceiling","There's a colourful painting on it.\n");
  AddDetail(({"painting","colorful painting","colourful painting"}),"\
The colours are very saturated. Some parts of the painting are even "
"coloured with gold-leaf.\n"
"The painting itself shows a room filled with carpets, bowls with fruits, "
"sofas with men and women most of them nacked on them. In the middle of "
"the painting is a fountain, where gold-coins come out.\n");
  AddDetail(({"picture","picture on gable","picture on roof"}),"\
The picture shows a balance and lots of money which is build to lots of "
"small towers at each side of the balance.\n");
  AddDetail("balance","It's used to weigh money.\n");
  AddDetail("money",
    "Somehow this place seems to have something to do with money.\n");
  AddDetail(({"towers","small towers"}),
    "They are made out of lots of coins.\n");
  AddDetail("money-changer","\
He looks very friendly and is sorting the money in front of him.\n");
  AddDetail("glasses","The money-changer is wearing them.\n");
  AddDetail(({"money-bag","bag"}),"\
You wish you would have so much money to fill such a bag.\n");
  AddDetail(({"caravan","caravan of traders","traders"}),"\
The caravan seems to be on its way through the desert.\n");
  AddDetail(({"goods","different goods","carpets","spices","wine"}),"\
The caravan has many different goods.\n");
  AddDetail(({"background","desert"}),"\
In the background of the relief you see the desert.\n");
  AddDetail(({"flat hills","hills","dunes"}),"\
They belong to the desert in the background of the picture.\n");
  AddDetail(({"sun","circle"}),"\
The sun on this relief is just a simple circle high above the desert.\n");
  AddDetail("grating","It's made out of strong iron");
  AddDetail(({"strong iron","iron"}),"The iron looks strong.\n");
  

  AddDetail(({"post", "post office", "office"}),
"The post office seems to be a very frequently visited place.\n");
  SetIndoors(0);
}

public void reset()
{
  string *msgs;
  msgs = ({
"A fat man wearing a fur coat of white ermine just leaves the bank.\n",
"An old man, he looks like some kind of janitor, arrives with a broom "
"in his hand and cleans the stairs. Then he vanishes again inside the "
"building.\n",
"Four children arrive at the bank, guided by their father. Each of them "
"has a silver coin in its hand and they seem to be very happy. Their father "
"leads them into the bank, telling them about interest and compound interest. "
"After some time he returns with the children. The children have red cheeks "
"and are laughing. The father takes the smallest child on his arms and "
"carries it down the stairs. Then they leave north.\n"});
  
  tell_room(this_object(),msgs[random(sizeof(msgs))]);
  (::reset());
}
