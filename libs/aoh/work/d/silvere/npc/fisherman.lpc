// fisherman walking around in the harbour of Silvere
// created by Taurec [8-3-98]

// TODO: Sollte bei Kampf nicht weiterlaufen.. aber wie?
//       Spare fish

#include <properties.h>
#include <macros.h>


inherit "/std/npc";

void call_go(int timer){
  call_out("go_home",timer);
}

void go_home(){
  say(NAME(TO)+" says: Ahhhh, enough work for today! I'm going "
   "home to my wonderful wife now. Bye!\n");
  say(NAME(TO)+" waves happily and sets out for the city.\n");
  if (!remove()) destruct(TO);
}

string choose_name(){
  string *names,name;
  names=({"carallo","perthoran","lyden","dyrian","loxineyo","taslon",
          "kortar","daran","mieral","aston","olgrin","ubridar"});
  do {
    name=random_select(names);
    names-=({name});
  } while (find_living(name)&&(sizeof(names)));
  return CAP(name);
}

void create()
{
  ::create();
  Set(P_GO_CHANCE,50);
  Set(P_LEVEL,10);
  Set(P_GENDER,GENDER_MALE);
  Set(P_NAME,choose_name());
  Set(P_RACE, "human");
  Set(P_ALIGN, 100);
  Set(P_IDS,({"fisher","fisherman"}));
  Set(P_ADS,({"weatherbeaten","happy"}));
  Set(P_SHORT,CAP(NAME(TO))+", the fisherman");  
  Set(P_LONG,CAP(NAME(TO))+" wears the typical knee-high boots, a "
   "waterproof jacket and a bigbrimmed (also waterproof) cap. From under "
   "that cap, two bright shining blue eyes that contrast sharply to the "
   "weather-bronzened face watch you straightly. A faint smell of - "
   "guess what - fish, salt-water and fresh wind surrounds "+HIMHER(TO)+
   ". You could ask him if he's got a spare fish for you.\n"); 
  Set(P_MSGOUT,({"walks","Someone walks"}));
  Set(P_SMELL,"It's a smell-coctail of salt water, fish and fresh wind.\n");

// *** CHAT SETTINGS ***
  Set(P_CHAT_CHANCE,4);
  Set(P_CHATS,({
    NAME(TO)+" watches the sky suspiciously.\n",
    NAME(TO)+" whistles a happy tune.\n",
    NAME(TO)+" repairs a torn sail with awesome skill.\n",
    NAME(TO)+" moistens one finger and holds it up into the wind.\n",
    NAME(TO)+" prepares a net.\n",
    NAME(TO)+" says: There's no better life than a fisher's life! You've "
     "got the sun, the wind and the sea; what could I wish more?\n",
    NAME(TO)+" says: I hope the next catch will be a success...\n",
    NAME(TO)+" sings a merry song.\n"
  }));
}

varargs void Die (int silent)
{
  if (!silent)
  tell_room(environment(),"The fisher stumbles, and falls "
   "to the floor. With a final effort "+HESHE(TO)+" exhales: \"Please, "
   "let the sea have my b-body...\" "+HESHE(TO)+" spits some blood. \"It's "
   "her I belong to...\"\n");
  ::Die(silent);
}
