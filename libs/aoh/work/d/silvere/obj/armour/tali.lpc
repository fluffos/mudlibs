#include <properties.h>  
#include <combat.h>      
 
inherit "/std/armour";
 
void create () {
  ::create();
 
  SetStandard(AT_CLOAK, 6, PSIZE_GENERIC );
 
  SetShort("Tali's fire cloak");
  AddAdjective("armour");
  AddAdjective("fire"); 
  SetLong( ({"You have never seen material like this before. It "
    "is black but sparkles like fire. Perhaps you should wear it.\n",
    "It is a long cloak of an unknown black material. It sparkles like "
    "fire. You somehow know you will be safer when you wear it.\n"}) );
    Set(P_VALUE,300);
    AddId("cloak");
 
 
}
