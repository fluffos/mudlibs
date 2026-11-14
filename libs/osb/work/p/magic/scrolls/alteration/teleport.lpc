/* Adapted and improved by Softbyte 1995 */
#include <secure/wizlevels.h>
#include <properties.h>
#include <moving.h>
#include <magic.h>
#include <guild.h>
inherit "obj/scroll";
#define TP this_player()
#define TO this_object()

#define MIN_LEVEL 6

int MyCast(string str) 
{
  string place,a,s;
  object pl, amulet;
  int erg;

  if (!str)
  {
    write("You used this spell in a wrong way!\n");
     return CAST_FAIL_NOMSG;
  }

  if (sscanf(str,"to %s",a)==1) {
    write("This is not allowed any longer!\n");
    return CAST_FAIL_NOMSG;
  /*     
     pl=find_player(a);
     if (!pl) {
     write("There is no such player!\n");
     return CAST_FAIL_NOMSG;
     }
     if (call_other("/players/loco/lib/testylib","CheckTesty",pl)) {
       write("Something blocks your magic.\n");
       return CAST_FAIL_NOMSG;
     }
     if (IS_WIZARD(pl)) {
       write("You can't teleport to a wizard!\n");
       return CAST_FAIL_NOMSG;
     }
     place=object_name(environment(pl));
     if (place->Query(P_TPORT)<3) {
       write("That room blocks teleportation.\n");
       return CAST_FAIL_NOMSG; 
     }
     if (environment(this_player())->Query(P_TPORT)<3) {
       write("This room blocks teleportation.\n");
       return CAST_FAIL_NOMSG;
     }
     write("You are teleported to another place.\n");
     this_player()->move(place, M_TELEPORT);
     return CAST_SUCCESS;
     */
   }

  pl=find_player(str);
  if (!pl) {
    write("There is no such player!\n");
    return CAST_FAIL_NOMSG;
  }
  amulet=present("tportamulet",pl); 
  s=QueryTeleportMessage(pl,1,MIN_LEVEL);
  if (s)
  {
    Message(s);
    return CAST_FAIL_NOMSG;
  }
  place=object_name(environment(this_player()));

  erg=pl->move(place,M_TELEPORT);
 
  switch(erg) {
  case ME_OK:
    pl->SetDeadOb(0);
    return CAST_SUCCESS;
    break;
  case ME_NO_LEAVE:
    write(capitalize(pl->QueryName())+ " can't leave the room.\n");
    if (amulet) amulet->glow(pl,this_player()->QueryName());
    return CAST_FAIL_NOMSG;
    break;
  case ME_NO_ENTER:
    write(capitalize(pl->QueryName())+" is not allowed to enter this room.\n");
    if (amulet) amulet->glow(pl,this_player()->QueryName());
    return CAST_FAIL_NOMSG;
    break;
  default:
    write("You are not able to teleport\n");
    return CAST_FAIL_NOMSG;
  }
  return CAST_SUCCESS;
}

int MyFail() 
{
string *loc;
  loc=({"/d/woodland/common/lorinia/market","/d/woodland/common/lorinia/well",
        "/d/woodland/common/lake/sforst4","/d/woodland/common/city/church",
        "/d/woodland/common/mandukam/church","/d/woodland/common/sandy/shop"
       });
  if (!QueryAllowedTeleport(this_player(),1,MIN_LEVEL ))
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
 ::create();
 AddSpell("teleport",ST_TELEPORT,70,#'MyCast,"teleportation",40);
 SetSpellDesc(
"With this spell you are able to teleport a player or to teleport\n\
to a player. (Teleporting to players is disabled again)\n");
 SetSpellUsage("cast teleport <name> or cast teleport to <name>\n");
 SetMemoLevel(GC_SORCERER,12);
 SetMemoLevel(GC_ARCHMAGE,12);
 
 //SetFailFn(#'MyFail);
}

