/* Rewritten by Softbyte August 1995 */
#include <magic.h>
#include <guild.h>
#include <moving.h>
inherit "/obj/scroll";
#define TP this_player()


object GetRoomFile(string dir,object ob)
{
mapping dest;
string *index;
object npc;
int j;
string tmp;
object target;
 seteuid(getuid(this_object()));
  if (!ob || !dir) return 0;
  dest=ob->QueryExitsDest();
  if (dest) index=m_indices(dest);
  else index=({});
  j=member(index, dir);
  if (j>=0)
  {
    if (!stringp(dest[index[j]]))
    {
      tmp=ob->QueryNoteExit(index[j]);
      if (tmp) return load_object(tmp);
      else
      {
        npc=clone_object("/std/npc");
        npc->SetShort(0);
        npc->SetName("");
	npc->move(ob,M_NOCHECK);
	if (catch(npc->command_me(index[j]))) 
	   {npc->remove();return 0;}
	if (ob!=environment(npc)) 
	   {target=environment(npc);npc->remove();return target;}
        npc->remove();
      } /* end else NPC move */
    } /* end if stringp */
    else return load_object(dest[index[j]]);
  }
  dest=ob->QueryCommands(ob);
  if (dest) index=m_indices(dest);
  else index=({});
  j=member(index, dir);
  if (j>=0)
  {
    tmp=ob->QueryNoteExit(index[j]);
    if (tmp) return load_object(tmp);
    else
    {
      npc=clone_object("/std/npc");
      npc->SetShort(0);
      npc->SetName("");
      npc->move(ob,M_NOCHECK);
      if (catch(npc->command_me(index[j]))) 
          {npc->remove();return 0;}
      if (ob!=environment(npc)) 
          {target=environment(npc);npc->remove();return target;}
      npc->remove();
    } /* end else NPC move */
  }
  return 0;
}

int Failed() {
    write("I can't look into that direction.\n");
    return CAST_FAIL_NOMSG;
}

int MyCast(string str) 
{
object room;
 if (!str)
 {
   write("Where do you want to look?\n");
   return CAST_FAIL_NOMSG;
 }
 room=GetRoomFile(str,environment(TP));
 if (!room) return Failed();
 if (!call_other(room, "QueryIntLong")) return Failed();
 Message(({"You look "+str+" and see:\n",
     TP->QueryName()+" looks "+str+".\n"}));
 Message(call_other(room, "QueryIntLong")||"");
 Message(call_other(room, "Content")||"");
 return CAST_SUCCESS;
}

int MyFail()
{
   Message(({"You see nothing.\n",
       TP->QueryName()+" looks puzzled.\n"}));
   return CAST_SUCCESS;
}
create()
{
 ::create();
 AddSpell("eye",ST_KNOW,10,#'MyCast,"magic eye",30);
 SetSpellDesc("This spell lets you have a look into directon <dir>.\n");
 SetSpellUsage("cast eye <dir>\n");
 SetMemoLevel(GC_SORCERER,17);
 SetMemoLevel(GC_ARCHMAGE,17);
 SetFailFn(#'MyFail);
}

