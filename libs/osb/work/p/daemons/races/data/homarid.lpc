#include <races.h>
#include <attributes.h>
#include <nightday.h>
#include <properties.h>
#include <stdrooms.h>

inherit RACEOBJ;

/*-------------------------------------------------------------------------*/

void create() {
  ::create();
  SetAlign(0);  // homarids are supposed to be neutral
  SetFood(100);
  SetDrink(100);
  SetSize(PSIZE_NORMAL);
  SetAlc(50);  // cannot stand much alc
  SetWeight(100000); // not the lightest race
  AddHand("big pincher", 5);
  AddHand("small pincher", 1);
  SetDef(3);
  SetHome(STARTROOM);
  SetLong(
"@@Pl_Name@@ is a strong looking creature. After a few seconds of thought\n\
you remember that these creatures are called 'homarids'. @@Pl_Pro@@ has a skin as\n\
strong as a good armour and a really big pincher where humans would have\n\
their right hand. On @@Pl_Poss@@ head  are two large antenae which perhaps\n\
will prevent @@Pl_Name@@ from using a helmet.\n");
  AddAttr("MagicDefence",35);
  AddStat (A_CON,-10); // bad constitution
  AddStat (A_DEX,-8);  // not very dextrous
  AddStat (A_INT,6); // intelligent
  AddStat (A_STR,5);
  AddStat (A_IVISION, -(MAX_SUNBRIGHT/2));  /* can see in the darkness */ 
  AddStat (A_UVISION, (MAX_SUNBRIGHT/4*3));
  SetDesc(
"Homarids are a race of strong and intelligent beings. Their naturally tough\n\
and horny skin makes them less dextrous than most other races. As they are\n\
not used to living above the surface, their constitution is lower than one\n\
would imagine for such a strong creature. They can become strong fighters\n\
(but think about the bad constitution) and intelligent magic user. Also\n\
consider that anything that needs high dexterity will not be a good job for\n\
them.\n");
  AddEquipment("sunglasses", "/obj/sunglasses", 0, 0, ({ "glasses" }));
}
