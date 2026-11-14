/*
* A debugging tool, hunting for the buggy bug
* by tired Thragor, 16nov94, 01:00am
*/

#include <moving.h>

inherit "/std/npc";

public int create()
{
  if (::create()) return 1;
  SetName("a debugging tool");
  SetRace("tool");
  SetLong(
"You see a large debugging tool with sharp teeth. There are no eyes, no "
"arms ... just these horrible sharp teeth.\n"
"The tool seems to search for something.\n");
  SetHands(
    ({
      ({"sharp teeth",0,25})
    }) );
  SetIds(({"tool","debugger"}));
  SetAds(({"debugging","debug","large","a","the"}));
  SetLevel(10);
  SetDex(9);
  SetInt(13);
  SetCon(9);
  SetStr(16);
  SetGoChance(5);
  SetMsgOut("leaves searching for the buggy bug");
  SetMsgIn("arrives searching for the buggy bug");
  SetMMsgOut("leaves with a big grin on its teeth");
  SetMMsgIn("arrives with a big grin on its teeth");
  InitChats(15,
    ({
       "Crunch.\n",
       "Cruuuunnsch.\n",
       "Crunch. Crunch.\n",
       "The debugging tool says: I like these crunchy bugs.\n"
     }) );
  return 0;
}

public void kill_bug(object pl)
{
  if (!pl) return;
  if (environment(pl)!=environment()) return;
  tell_room(environment(),
    "The debugger says: Ah! There you are, you evil bug!\n");
  Kill(pl);
}

public void init()
{
  (::init());
  if (!this_player()) return;
  if (this_player()->id("bug100970")) call_out(#'kill_bug,3,this_player());
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

