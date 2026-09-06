/* obj/detailserver
*
*  Records the use of details in rooms which had been looked at but
*  are not defined
*
*   26-Dez-96 [Softbyte]
*
*  V0.1: Standard object created to save and administrate missing details
*  V0.2: Added time() to dump old details to file
*  TODO: If details have expired write them to a file and clear them
*        from the mapping to save memory
*/

#include <secure/wizlevels.h>

#define VERSION 0.2


#define MAXSAVECNT 10
#define DETAILLIST "/log/rep/MissingDetails"

mapping misdetails;
mapping toplist;
private nosave int savecnt=0;

mapping QueryMisdetails() {return misdetails;}
mapping QueryToplist() {return toplist;}

int Debug(string str)
{
object ob;
  ob=find_player("softbyte");
  if (!ob) return 0;
  tell_object(ob,blueprint(this_object())+"::"+str);
  return 1;
}

// Saves this object to a file
int SaveData()
{
  savecnt=0;
  save_object(DETAILLIST);
  Debug("Saving "+DETAILLIST+"\n");
  return(1);
}

int sort_it(string a,string b)
{
  if (toplist[a,0]+toplist[a,1]<toplist[b,0]+toplist[b,1]) return 1;
  return 0;
}
// Gives the toplist as string back
string WriteToplist()
{
string s,name;
string *idx;
int i,flag;
  if (this_player()->QueryRealName()=="softbyte"
      && this_player()->Query("Debug") ) flag=1;
  else flag=0;
  idx=m_indices(toplist);
  idx=sort_array(idx,#'sort_it/*'*/);
  s="Toplist of the detail fixes:\n";
  s+=sprintf("%-2.2s: %-11.11s %-7.7s %-7.7s (%s)\n",
     "##","Name","Details","Quest.","Sum");
  for (i=0;i<sizeof(idx);i++)
  {
    name=idx[i];
    if (toplist[name,2]==0 && flag==0)
    {
      s+=sprintf("%2d: %-11.11s %7d %7d  (%d)",
        i,name,toplist[name,0],toplist[name,1],toplist[name,0]+toplist[name,1]);
      if (flag) s+=(toplist[name,2]?" (silent)":" (normal)");
      s+="\n";
    }
  }
  return s;
}

// Add a wizards (tp) with his entries for detail and questioncount
// to the toplist or updates his entry..nologgin=1 means not to display
// his entries in the toplist
varargs int AddToplist(mixed tp,int d_cnt,int q_cnt,int nologging)
{
string name;
  if (!toplist) toplist=m_allocate(100,3);
  if (!tp) return 0;
  if (objectp(tp)) name=tp->QueryRealName();
  else if (stringp(tp)) name=tp;
  else return -1;
  if (member(toplist,name))
  {
    toplist[name,0]=d_cnt;
    toplist[name,1]=q_cnt;
    toplist[name,2]=nologging;
  }
  else
  {
    toplist+=([name:d_cnt;q_cnt;nologging]);
  }
  savecnt++;
  if (savecnt>MAXSAVECNT) SaveData();  // savecnt IS reset !
  return 1;
}

// Puts the detail of room into the mapping of missing details
varargs int RecordDetail(string detail,mixed room)
{
mapping troom;
  if (!room)
  {
     room=previous_object();
     if (room && interactive(room)) room=environment(room);
  }
  if (!room || !detail) return 0;
  if (!misdetails) misdetails=m_allocate(100,3);
  if (!stringp(room)) room=blueprint(room); 
  // Debug("Adding missing '"+detail+"' in "+room+"\n");
  troom=misdetails[room,0];
  if (!troom)
  {
    troom=([detail:1]);
    misdetails+=([room:troom;1;time()]);
  }
  else
  {
    if (troom[detail]) troom[detail]++;
    else troom+=([detail:1]);
    misdetails[room,0]=troom;
    misdetails[room,1]++;
    misdetails[room,2]=time();
  }
  savecnt++;
  if (savecnt>MAXSAVECNT) SaveData();  // savecnt IS reset !
  return 1;
}

// Removes the detail from the missing detail list of room
// If force==1 then all details from the room are removed
varargs int RemoveDetail(string detail,mixed room,int force)
{
mapping troom;
  if (!room)
  {
     room=previous_object();
     if (room && interactive(room)) room=environment(room);
  }
  if (!room || (!detail && !force) ) return 0;
  if (!misdetails) misdetails=m_allocate(100,3);
  if (!stringp(room)) room=blueprint(room); 
  if (force)
  {
    // Debug("Removing all missing details from "+room+" (forced)\n");
    if (member(misdetails,room))
    {
      m_delete(misdetails,room);
      return 1;
    }
    else return -1;
  }
  // Debug("Removing missing '"+detail+"' in "+room+"\n");
  troom=misdetails[room,0];
  if (!troom ) return -2;  // Nothing to be done
  else  if (member(troom,detail))
  {
    misdetails[room,1]-=troom[detail];
    if (misdetails[room,1]<=0) // No details missing in the room anymore
      m_delete(misdetails,room);
    else                                 // Remove the detail from the room
    {
      m_delete(troom,detail);
      misdetails[room,0]=troom;
      misdetails[room,2]=time();
    }
  }
  else return -3;   // nothing to be done
  savecnt++;
  if (savecnt>MAXSAVECNT) SaveData();  // savecnt IS reset !
  return 1;
}

// Compares the number of missing details in two rooms
int sort_number(string a,string b)
{
  if (misdetails[a,1]<misdetails[b,1]) return 1;
  return 0;
}

varargs string *QueryIndex(int sorted)
{
string *roomindex;
  if (!misdetails) misdetails=m_allocate(100,3);
  roomindex=m_indices(misdetails); 
  if (!roomindex || !sizeof(roomindex) ) return ({});
  if (!sorted) return roomindex;
  return sort_array(roomindex,#'sort_number /*'*/);
}


// Returns the mapping [detail:number] of missing details in a room
// Room can be either the object room or its filename/blueprint
varargs mapping QueryDetails(mixed room)
{
mapping troom;
  if (!room) room=environment(this_player())||previous_object();
  if (!room)
  {
    write("No room given!\n");
    return 0;
  }
  if (!stringp(room)) room=blueprint(room);

  if (!misdetails) misdetails=m_allocate(100,3);
  troom=misdetails[room,0]||([]);
  return troom;
}

// Returns the number of details which are missing in a room
// Room can be either the object room or its filename/blueprint
varargs int QueryNumberOfDetails(mixed room)
{
int nr;
  if (!room) room=environment(this_player())||previous_object();
  if (!room)
  {
    write("No room given!\n");
    return 0;
  }
  if (!misdetails) misdetails=m_allocate(100,3);
  if (!stringp(room)) room=blueprint(room);
  nr=misdetails[room,1];
  return nr;
}

// Deletes all missing details !
int ResetDetails()
{
  if (!IS_WIZARD(this_player()))
  {
    write("You are not allowed to do that.\n");
    return 0;
  }
  write("Resetting ALL missing details...\n");
  misdetails=([]);
  SaveData();
  return 1;
}

void create()
{
  if (member(object_name(this_object()), '#') != -1) 
  {
    destruct (this_object());
    return;
  }
  seteuid(getuid());
  if (file_size(DETAILLIST+".o")>=0) restore_object(DETAILLIST);
  else
  {
    misdetails=m_allocate(100,3);
    toplist=m_allocate(100,3);
  }
  Debug("Init detailserver with "+sizeof(m_indices(misdetails))+" rooms.\n");
  savecnt=0;
}

public varargs int remove(int arg)
{
  Debug("Remove Called with "+arg+"\n");
  SaveData();
  destruct(this_object());
  return 1;
}
