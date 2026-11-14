/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <moving.h>
inherit "/obj/scroll";

#define TP this_player()
#define TO this_object()
#define MIN_LEVEL 6

int suche(object ob) {
  if(ob->id("doorlist")) { return 1;}
  return 0;
}

int MyCast(string str)
{
  string place, a,s;
  object list;
  int erg;

  if (!str)
  {
    write("You used this spell in a wrong way!\n");
     return CAST_FAIL_NOMSG;
  }
  if(!sizeof(filter(deep_inventory(TP),"suche"))) {
    seteuid(getuid(TO));
    list=clone_object(MAGIC_OBJ_DIR "doorlist");
    list->move(TP);
    write("You recieve a special list.\n");
  }
  else list=filter(deep_inventory(TP),"suche")[0];

  if (sscanf(str,"to %s",a)==1) {
    place=list->QueryDimDoor(a);
    if (place == "no such door") {
      write("Sorry, but you did not open such a door!\n");
      return CAST_FAIL_NOMSG;
   }
  s=QueryTeleportMessage(this_player(),1,MIN_LEVEL);
  if (s)
  {
    Message(s);
    return CAST_FAIL_NOMSG;
  }

    erg=TP->move(place,M_TELEPORT);
    
    switch(erg) {
    case ME_OK:
      TP->SetDeadOb(0);
      return CAST_SUCCESS;
      break;
    case ME_NO_LEAVE:
      write("You can't leave the room.\n");
      return CAST_FAIL_NOMSG;
      break;
    case ME_NO_ENTER:
      write("You are not allowed to enter this room.\n");
      return CAST_FAIL_NOMSG;
      break;
    default:
      write("You are not able to teleport\n");
      return CAST_FAIL_NOMSG;
    }
    return CAST_SUCCESS;
  }

  list->AddDimDoor(str);
  return CAST_SUCCESS;
}

int MyFail() 
{
string *loc;
  loc=({"/d/woodland/common/lorinia/market","/d/woodland/common/lorinia/well",
        "/d/woodland/common/lake/sforst4","/d/woodland/common/city/church",
        "/d/woodland/common/mandukam/church","/d/woodland/common/sandy/shop"
       });
  if (!QueryAllowedTeleport(this_player(),1, this_player()->QueryLevel()))
  {
    write("Oops!\n");
    return CAST_REPULSE;
  }
  write("You are teleported to another place.\n");
  TP->move(loc[random(sizeof(loc))], M_TELEPORT);
  TP->SetDeadOb(0);
  return CAST_SUCCESS;
}

create()
{
  (::create());
  AddSpell("door",ST_TELEPORT,60,#'MyCast,"dimension door",40);
  SetSpellDesc(
"This spell will create a dimension door or let you step to a dimension door\n\
How much doors you can open depends on your level.\n\
With 'cast door XXXX' you can store your current\n\
location and with 'cast door to XXXX' you can teleport to this previous stored\n\
location.\n");
  SetSpellUsage("cast door <name> or cast door to <name>\n");
  SetMemoLevel(GC_CONJURER,10);
  SetMemoLevel(GC_ARCHMAGE,10);
  SetFailFn(#'MyFail);
}




