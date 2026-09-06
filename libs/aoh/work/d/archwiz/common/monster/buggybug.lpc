/*
* A buggy bug
* by tired Thragor, 16nov94, 01:00am
*/

inherit "/std/npc";

#include <moving.h>
#include "path.h"

#define DEBUGTOOL MONSTER("debugtool")

public int create()
{
  if (::create()) return 1;
  SetName("a buggy bug");
  SetRace("bug");
  SetCorpse(OBJ("core_corpse"));
  SetWeight(50000);
  SetLong("\
This is a buggy bug, not a big bug, only a small annoying bug.\n");
  SetHands(
   ({
     ({"a 'Your sensitive mind'-message",0,8}),
     ({"a 'Too long evaluation'",0,8}),
     ({"a syntax error",0,8}),
     ({"an illegal LHS",0,8}),
     ({"a bad argument 1 to call_other",0,8}),
     ({"a newline in string",0,8})
   }) );
  SetIds(({"bug","bug100970","feature"}));
  SetAds(({"buggy","a","the","an","annoying","small","not","big"}));
  SetAlign(-100);
  SetLevel(10);
  SetDex(14);
  SetInt(5);
  SetCon(16);
  SetStr(8);
  SetAttribute("MagicDefence",80);
  SetWimpy(30);
  SetGoChance(10);
  SetMsgOut("bugs out");
  SetMsgIn("bugs in");
  InitChats(15,
    ({
       "Your sensitive mind notices a wrongness in the bug.\n",
       "Harry says: I hate rain.\n",
       "Nervi admires you.\n",
       "No way.\n",
       "An orc says: PAY the TOLL!\n",
       "You don't have enough free hands.\n",
       "It's too dark.\n",
       "It's too bright.\n",
       "Harry arrives in a puff of bugs.\n",
       "You are in a maze.\n"
       "There are no obvious exits.\n",
       "Harry leaves east.\n",
       "[news:A buggy bug bugs you.]\n",
       "BB proudly presents: It's not a bug, it's a feature!\n",
       "Nervi arrives from westsouthwest.\n",
       "Someone starts changing a bit of the bug.\n",
       "Autoshave.\n",
       "Tired Thragor arrives in a puff of nonsense.\n",
       "Nervi says: I love you, Someone!\n",
       "Type: bug this buggy bug is annoying\n",
       "The buggy bug says: Don't use the 'bug' command.\n"
       "  The debugging tool will find me, if you do it.\n"
     }) );
  return 0;
}

public void init()
{
  (::init());
  add_action("catch_bug","bug");
}

public void catch_bug(string str)
{
  object *obs;

  tell_room(environment(),
    "The buggy bug says: Oh no!\n");
  if (sizeof(obs = find_clones(DEBUGTOOL)))
    obs[0]->move(environment(),M_TELEPORT);
}

public int move(mixed dest,int method,mixed extra)
{
  int rc;
  object env;
  
  env = environment();
  rc = (int)::move(dest,method,extra);
  if (!sizeof(regexp(({object_name(environment())}),"/d/archwiz/")))
    {
      if (!env)
        {
          destruct(this_object());
          return rc;
        }
      rc = (int)::move(env,M_SPECIAL,({"immediately returns",
                                  "immediately returns"}));
    }
  return rc;
}

public void second_life()
{
  say  ("Segmentation fault. Core dumped.\n");
}
