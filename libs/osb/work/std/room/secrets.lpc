//---------------------------------------------------------------------------
// room/secrets.c
//
// The basic secret handling of a room.
// (c) Softbyte@OSB 3oct97 
// V1.0:  Basic secret handling and functions
//---------------------------------------------------------------------------

#include <config.h>
#include <rooms.h>
#include <properties.h>
#include <skills.h>

#define TO this_object()
#define TP this_player()
#define THIS this_object()

public mixed Query(string arg); // std/base
public varargs mixed Set(string pn, mixed arg, int sc); // std/base



//--- secret functions ------------------------------------------------------
// Add a Secret to a room. Its short name is 'name'. Usual "door" or 
// "exit" or "trap door". 
// The 'difficulty' detemines how difficult a Secret is to detect (0-1000).
// It is related to the secret skill 
// The next argument is the description  of that secret, i.e. what a player
// will see when detecting it. It can be a string or string array  or a
// closure returning a string. If given a string array the text shown to
// the player depends on the output of the skill check. A low value will
// show the first string of the array and higher values will show latter
// strings providing more inforamtion for the player.
// The closure function will get 'secret' && 'player' && 'skillvalue'
// as arguments, i.e.
// varargs string MyFun(string secret,object player,int skillvalue)
// where secret is the name given to the secret in AddSecret skillvalue
// a number 0..1000 showing how well the player did detect the secret
varargs int AddSecret(string secret, int difficulty,mixed desc)
{
mapping m_secret;
   if (!secret || !desc) return 0;
   if (!stringp(desc) && !pointerp(desc) && !closurep(desc) ) return 0;

   m_secret=Query(P_ROOM_SECRETS);
   if (!m_secret) m_secret=([]);

   if (member(m_secret,secret))
      m_secret=m_delete(m_secret,secret);

   m_secret+=([secret:desc;difficulty;({}) ]);
   Set(P_ROOM_SECRETS,m_secret);
   return 1;
}

// Removes a secret from the list of secrets in this room
int RemoveSecret(string secret)
{
mapping m_secret;
   if (!secret) return 0;
   m_secret=Query(P_ROOM_SECRETS);
   if (!m_secret) m_secret=([]);

   if (member(m_secret,secret))
      m_secret=m_delete(m_secret,secret);

   Set(P_ROOM_SECRETS,m_secret);
   return 1;
}

