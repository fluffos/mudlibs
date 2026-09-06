/* Mudworm
**
** Crawls in every accessible room.
**
**  03-Sep-92 [m]
**  30-Sep-92 [m] Can now carry a checking object.
*/

#include <properties.h>   /* for the property names */
#include <rooms.h>
#include <moving.h>
#include "/obj/lib/stddefs.h"

inherit "/std/npc";

int gen, silent;
object room, chef;
string wormid;
string checker;
mixed do_new_room;

/*-------------------------------------------------------------------------
** Initialize us - as few as possible.
*/

create () {

  if (::create()) return;  /* Ignore the Blueprint */

    /* Initialize Name = Short and Long description */
  SetName ("Worm");
  SetShort ("a mudworm");
  SetLong (
 "A worm, visiting every room.\n"
          );

    /* Set the race. */
  SetRace ("worm");
  SetMaxHP (1000000);
  SetMsgIn ("crawls out of a wormhole");
  SetMMsgIn ("pops out of a wormhole");
  SetMsgOut ("crawls");
  SetMMsgOut ("is sucked into another wormhole");
  wormid = "Worm #"+explode(file_name(ME),"#")[1];
  do_new_room = 0;
}

heart_beat()
{
  mixed args;

  ::heart_beat();
  args = do_new_room;
  do_new_room = 0;
  if (args)
    new_room(args);
}

init() { add_action("fstart", "startworm"); }

tellme (str) { if (chef) tell_object(chef, str); }

new_one (string cmd, mixed dest, int special) {
  object w;
  w=clone_object("/players/mateese/obj/worm");
  w->main(silent,room,gen,chef,cmd,dest,special,checker);
}

main(q,r,g,b,c,d,s,ch) {
  gen = g; chef = b; room = r; silent = q; checker = ch;
  do_new_room = ({ c, d, s }); // new_room() will be called with next HB
}

new_room (mixed arg) {
  string cmd;
  mixed dest;
  int special;
  int rc;
  mixed ctch;

  cmd = arg[0]; dest = arg[1]; special = arg[2];
  if (special) {
    move(room, M_TELEPORT);
    if (ctch = catch(rc=command_me(cmd)))
      tellme ("*** "+file_name(room)+"\n    Special '"+cmd+"': "+ctch);
    else if (!rc)
      tellme ("*** "+file_name(room)+"\n    Special '"+cmd+"': Failed.\n");
    if (ctch || !rc) return Die();
  }
  else {
    if (ctch = catch(rc=move(dest, M_GO, "away")))
      tellme ("*** "+file_name(room)+"\n    '"+cmd+"' -> "+dest
              +"\n    "+ctch);
    else if (!rc)
      tellme ("*** "+file_name(room)+"\n    '"+cmd+"' -> "+dest
              +": Failed.\n");
    if (ctch || !rc) return Die();
  }
  go();
}

Die() {
  say ("A worm giggles and disappears into a wormhole.\n");
  destruct(ME);
}

go() {
  mapping exits;
  mixed *cexits;
  object chk;
  int i;

  if (!(room = environment(this_object()))) { Die(); return; }
  if ((i=room->Query("worm")) >= gen) {
    if (i > gen)
      tellme ("--- "+wormid+": Gen "+gen
              +" met "+room->Query("worm")
              +" in "+file_name(room)+"\n");
    Die(); return;
  }
  if (!silent) tellme (wormid+" in "+file_name(room)+"\n");
  room->Set("worm", gen);
  if (checker && chk = clone_object(checker)) {
    chk->move(room, M_NOCHECK);
    chk->magic();
  }
  exits = room->QueryExits();
  if (exits) {
    cexits = m_indices(exits);
  }
  for (i = 0; exits && i < sizeof(exits); i++) {
    if (exits[cexits[i], EXIT_OBJ] || closurep(exits[cexits[i], EXIT_DEST]))
      new_one(cexits[i], exits[cexits[i], EXIT_DEST], 1);
    else
      new_one(cexits[i], exits[cexits[i], EXIT_DEST], 0);
  }
  Die();
  return 0;
}

fstart(arg) {
  string *args;
  int g, i;
  object ob;
  if (arg == "?") {
    notify_fail(
 "startworm [<generation>] [silent]\n"
+"  Start the worm, optionally with given <generation>.\n"
+"  <silent> worms tell you just the errors.\n"
+"  If the worm carries an object on 'startworm', this object is cloned into\n"
+"  each room it reaches, then the lfun magic() is called in the clone.\n"
               );
    return 0;
  }
  if (room = environment(this_object())) gen = room->Query("worm")+1;
  if (arg) {
    args = explode(arg," ");
    for (i = 0; i < sizeof(args); i++) {
      if (args[i] == "silent") silent = 1;
      else if (sscanf(args[i], "%d", g) && g > 0) gen = g;
    }
  }
  write ("Starting "+(silent?"silent ":"")+"worm generation "+gen+"\n");
  chef = PL;
  if (ob = first_inventory(ME)) checker = explode(file_name(ob),"#")[0];
  go();
  return 1;
}

catch_tell() {}

/*************************************************************************/

