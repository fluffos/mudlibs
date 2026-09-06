/* std/npc/cmds
**
**  Miscellaneous commands.
*/

#include <attributes.h>
#include <secure/wizlevels.h>

#define THIS this_object()
#define TP   this_player()
#define ENV  environment
#define PREV previous_object()

#define NETDEAD  (!interactive() && query_once_interactive(THIS))

/*--------------------------------------------------------------------------*/

// std/living/attributes

public varargs mixed QueryAttr(string aname, int sc);
public varargs mixed SetAttr(string aname, mixed value, int sc);

// std/living/moving

public void Wimpy();

//--------------------------------------------------------------------------
public varargs int finvis (string arg)
{
  int invis;
  mixed mmsgout;
  string name;

  if (arg)
    return 0;

  invis = QueryAttr(A_INVIS);
  if (invis) {
    tell_object(this_object(), "You are already invisible.\n");
    return 1;
  }
  mmsgout = QueryAttr(A_MMSGOUT);
  if (!pointerp(mmsgout))
    mmsgout = ({ mmsgout, "disappears" });
  name = QueryAttr(A_NAME);
  show ( ({ name+" "+mmsgout[0]+".\n", name+" "+mmsgout[1]+".\n" })
       , this_object());
  SetAttr(A_INVIS, 1);
  tell_object(this_object(), "You are now invisible.\n");
  return 1;
}

//--------------------------------------------------------------------------
public varargs int fvis (string arg)
{
  int invis;
  mixed mmsgin;
  string name;

  if (arg)
    return 0;

  invis = QueryAttr(A_INVIS);
  if (!invis) {
    tell_object(this_object(), "You are not invisible.\n");
    return 1;
  }
  SetAttr(A_INVIS, 0);
  tell_object(this_object(), "You are now visible.\n");
  mmsgin = QueryAttr(A_MMSGIN);
  if (!pointerp(mmsgin))
    mmsgin = ({ mmsgin, "disappears" });
  name = QueryAttr(A_NAME);
  show ( ({ name+" "+mmsgin[0]+".\n", name+" "+mmsgin[1]+".\n" })
       , this_object());
  return 1;
}

//--------------------------------------------------------------------------
public varargs int fflee (string arg)
{
  if (arg)
    return 0;

  Wimpy();
  return 1;
}

//--------------------------------------------------------------------------
public void add_npc_cmds () {
  if (!({int})THIS->QueryIsPlayer() || IS_IMMORTAL(THIS))
  {
    add_action("finvis", "invis");
    add_action("fvis",   "vis");
  }
  add_action("fflee",  "flee");
}

/****************************************************************************/
