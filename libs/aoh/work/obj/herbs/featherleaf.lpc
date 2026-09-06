
#include <properties.h>
#include <herbs.h>

inherit HERB;

varargs void create()
{
  ::create();
  
  SetShort("a green herb");
  SetLong("A pleasantly fragrant herb with green leaves.\n");
  
  SetPluralShort("several green herbs");
  SetPluralLong("Some pleasantly fragrant green herbs.\n");
  
  AddId("leaf");
  AddPluralId("leaves");
  
  AddAdjective(({"green","slender-stalked","delicate","thin","light","long"}));
  
  
  SetStandard( HERB_HEAL_SP, "featherleaf", 55,
    "You feel bubbles tingle and race through your veins. Lightheaded "
    "and giddy, you stop for a moment to breathe deeply.\n");
    

  SetFoodMsgs(({"You eat the delicate green herb.\n",         // msg to player
                "@@Pl_Name@@ eats a green herb.\n",   // to environment (seeing)
				"Someone eats something.\n"}));       // to environ. (not see.)
				
  SetHerbLong(
        "A long, slender-stalked herb, with delicate, thin light "
        "green leaves.\n");

  AddHerbInfo(20,
	   "The green leaf seems to be from a medicinal herb.\n",
	   "The green leaves seem to be from a medicinal herb.\n");
  AddHerbInfo(40,
	   "The green leaf appears to be a healing herb.\n",
	   "The green leaves appears to be healing herbs.\n");
  AddHerbInfo(60,
	   "The green leaf is featherleaf. It is a weak healing herb.\n",
	   "The green leaves are featherleaf. It is a weak healing herb.\n");
}
