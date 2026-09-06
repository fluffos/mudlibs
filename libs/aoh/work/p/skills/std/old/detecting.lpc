//---------------------------------------------------------------------------
// /p/skills/detecting.c
//
// The detect skill handling of OSB
// (c) Softbyte@OSB 18oct97 
// V1.0:  Basic skill handling and functions
//---------------------------------------------------------------------------

#include <config.h>
#include <properties.h>
#include <moving.h>
#include <daemons.h>
#include <msgclass.h>
#include <skills.h>


#define TO this_object()
#define TP this_player()

public mixed Query(string arg); // std/base
public varargs mixed Set(string pn, mixed arg, int sc); // std/base



// ========================= Special skill functions ========================
// ************************    Detecting     ********************************
// Check whether the player detects a new secret or when the player
// remembers a secret
private void CheckSecret(string secret,mixed desc,int difficulty,
                          object *finder,object who,object where,int method)
{
int value;
int nr;
string s;

  if (member(finder, who)>=0)
  {
    msg_object(who,CMSG_GENERIC,
       "You remember a secret ("+secret+") here.\n");
    return;
  }
  
  value=TO->UseSkill(who,SK_DETECT,difficulty);
  if (value<=0) return;  // failed skill check

  if (!desc) return;   // wrong arguments

  // Call the string-function to get the message array
  if (stringp(desc)) 
  {
    s=desc;
  }
  else if (closurep(desc))
  {
    s=funcall(desc,secret,value,who);
  }
  else if (pointerp(desc) )
  {
	nr=sizeof(desc);
	if (nr<1) return;                        // wrong arguments

	// Which indexd should be shown ... depends on skill outcome
	nr=(value*nr)/1000;
	if (nr>=sizeof(desc)) nr=sizeof(desc)-1;
	s=desc[nr];
  }
  else return ;   // Wrong arguments

  if (s)
  {
    msg_object(who,CMSG_GENERIC,process_string(s));
    finder+=({who});
  }
  return;

}


// Will be called a bit delayed when entering the room
void EnterRoomDelayed(object who, object where, int method)
{
mapping m_secret;
  if (environment(who)!=where) return; // player left room

   m_secret=where->Query(P_ROOM_SECRETS);
   if (!m_secret) return;              // no secrets

   walk_mapping(m_secret,#'CheckSecret,who,where,method);



}
// This function will be called by the notify_enter of the room
int EnterRoom(object who, object where, int method)
{
  if (!who || !where) return 0;

  // Only check if the room was entered reasonably
  if (method!=M_GO && method!=M_TELEPORT && method!=M_SPECIAL) return 0;

  // Delay the finding of secrets a bit 1-4 sec
  call_out("EnterRoomDelayed",1+random(3),who,where,method);
  return 1;
}
