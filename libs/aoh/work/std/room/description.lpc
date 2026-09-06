//---------------------------------------------------------------------------
// room/description.c
//
// The basic description handling of a room.
//---------------------------------------------------------------------------

#include <config.h>
#include <rooms.h>
#include <properties.h>
#include <msgclass.h>
#include <daemons.h>

#define TO this_object()
#define TP this_player()
#define THIS this_object()

public string * filterExtra (string prop); // std/thing/description
public void SetExtraEntry (mixed name, string prop, mixed data);
                                           // std/thing/description
public void RemoveExtraEntry (mixed name, string prop);
                                           // std/thing/description

//--- global variables ------------------------------------------------------

private nosave mixed Pintshort, Pintnoise, Pintsmell, Pprecont;
private nosave mixed Pintlong, Phelpmsg;
private nosave mixed Pexplorable;

//--- the querying and setting functions ------------------------------------

public mixed QueryExplorable()         { return Pexplorable; }
public mixed SetExplorable(mixed m)    { return Pexplorable = m; }

public mixed QueryIntShort()         { return Pintshort; }
public mixed SetIntShort(mixed s)   { return Pintshort = s; }

public mixed QueryIntNoise()         { return Pintnoise; }
public mixed SetIntNoise(mixed s)   { return Pintnoise = s; }

public mixed QueryIntSmell()         { return Pintsmell; }
public mixed SetIntSmell(mixed s)   { return Pintsmell = s; }

public string QueryPreContent()       { return Pprecont; }
public string SetPreContent(string s) { return Pprecont = s; }

public varargs mixed QueryIntLong()   { return Pintlong; }
public mixed SetIntLong(mixed s)      { return Pintlong = s; }

public mixed QueryHelpMsg()         { return Phelpmsg; }
public mixed SetHelpMsg(mixed s)    { return Phelpmsg = s; }

public string SetRoomShort(string str) {
  CHANNEL_D->SendTell( "error", object_name( this_object()),
         sprintf("Obsolete function SetRoomShort() called by %O."
         , previous_object()),1);
  return SetIntShort(str);
}
public string SetRoomLong(string str) {
  CHANNEL_D->SendStr("error", object_name(this_object()),
    sprintf("Obsolete function SetRoomLong() called by %O."
           , previous_object()),1);
  return SetIntLong(str);
}

//--- Actual appearance -----------------------------------------------------

public varargs string IntLong(string what)  {
  mixed rc;
  return process_string((pointerp(rc = QueryIntLong()) ? rc[0] : rc)
         +implode(filterExtra(P_INT_LONG), ""));
}
public varargs string ExaIntLong(string what)  {
  mixed rc;
  return process_string((pointerp(rc = QueryIntLong()) ? rc[1]
                                       : "You see nothing special.\n"+rc)
         +implode(filterExtra(P_INT_LONG), ""));
}
public varargs string IntShort(string what) {
  string sh;
  if (!(sh = QueryIntShort()) || sh == "")
    return sh;
  return sh+implode(filterExtra(P_INT_SHORT), "");
}

/* IntNoise/IntSmell, with closure handling (hopefully)
** added 17-May-1999 by Sonic
*/
public varargs string IntNoise(string what)
{
   if(what)
      THIS->GetNoise(what);
   else
   {
      mixed noise;
      string extra, desc;

      noise = QueryIntNoise();
      extra = implode(filterExtra(P_INT_NOISE), "");
      if(closurep(noise)) noise = funcall(QueryIntNoise());
      desc = ( noise || "" ) + extra;
      return desc != "" ? desc : 0;
   }
}
public varargs string IntSmell(string what)
{
   if(what)
      THIS->GetSmell(what);
   else
   {
      mixed smell;
      string extra, desc;

      smell = QueryIntSmell();
      extra = implode(filterExtra(P_INT_SMELL), "");
      if(closurep(smell)) smell = funcall(QueryIntSmell());
      desc = ( smell||"") + extra;
      return desc != "" ? desc : 0;
   }
}

public varargs object * MakeExcl(mixed excl, mixed add) {
  if (closurep(excl))
    excl = filter(all_inventory(), excl);
  else if (objectp(excl))
    excl = ({ excl });
  else if (excl)  // TODO: document this special feature
    excl = ({ this_player() });

  if (add)
  {
    if (!pointerp(add))
      add = ({ add });
    if (!excl)
      excl = add + ({});
    else
      excl += add;
  }

  return excl;
}

public varargs string Content(string what, mixed excl, object pl) {
  string *strs;
  int i;

  excl = MakeExcl(excl, pl || TP);
  strs = map_objects(all_inventory() - excl, "InvShort") - ({ "" });
  if (sizeof(strs))
  {
    for (i = sizeof(strs); i--; )
      if (-1 == member(".!?", strs[i][<1]))
       strs[i] += ".";
    return (QueryPreContent() || "") + implode(strs, "\n") + "\n";
  }
  return "";
}

public varargs string GetIntDesc(int nolong, mixed excl, object pl) {
  string desc,s1,s2;

  if (!pl)
    pl = TP;
  s1=({string})COLOUR_D->ClassToToken(CMSG_ROOM_EXIT);
  s2=({string})COLOUR_D->ClassToToken(CMSG_GENERIC);
  desc = nolong ? "" : IntLong();
  if (({int})pl->QueryObvious())
    desc += (({int})pl->QueryBrief() ?
       "[" + s1 + (({string})THIS->Exits(1, pl) || "") + s2 + "]\n" :
       ( (s1+({string})THIS->Exits(0, pl)+s2) || "")
            ) + ( (s1+({string})THIS->Doors(0, pl)+s2) || "");
  return desc + Content(0, excl, pl);
}

public varargs string GetExaIntDesc(mixed excl, object pl) {
  string desc,s1,s2;

  if (!pl)
    pl = TP;
  s1=({string})COLOUR_D->ClassToToken(CMSG_ROOM_EXIT);
  s2=({string})COLOUR_D->ClassToToken(CMSG_GENERIC);
  desc = ExaIntLong();
  if (({int})pl->QueryObvious())
    desc += (({int})pl->QueryBrief() ?
       "[" + s1 + (({string})THIS->Exits(1, pl) || "") + s2 + "]\n" :
       ( (s1+({string})THIS->Exits(0, pl)+s2) || "")
            ) + ( (s1+({string})THIS->Doors(0, pl)+s2) || "");
  return desc + Content(0, excl, pl);
}

//--- Exploration -----------------------------------------------------

public mixed AddExplorable (mixed new)
{
  if (!Pexplorable)
    return Pexplorable = new;
  if (!new) return Pexplorable;
  if (!pointerp(new))
  new = ({ new });
  if (!pointerp(Pexplorable))
  Pexplorable = ({ Pexplorable });
  Pexplorable -= new;
  return Pexplorable += ({ new });
}

public varargs int DoExplore (mixed arg)
{
  if (   !Pexplorable
      || (!pointerp(Pexplorable) ? (arg != Pexplorable)
                                 : (-1 == member(Pexplorable, arg))
         )
      || !TP
      || (-1 == member(deep_inventory(THIS), TP))
     )
    return 0;
  TP->SetExplored();
  return 1;
}
