// Chronos coded this off a template, basically.
#include <mudlib.h>
#include "../central.h"

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid());
    set("race", "human") ;
    set_size(6) ;
   set("short", "a psychotic drug dealer") ;
    set("long", @ENDLONG
This guy is totally insane from all the drugs he's taken over the years.
He's one of the major drug dealers in the area and he's also
one of the best guns around.
It looks like "homicidal drug dealer" would be an appopriate
name too, since he's high on PCP most of the time.
ENDLONG
   );    
    set_name("dealer") ;
    set("prevent_summon", 1);
  set("ammo", ([
    "9mm" : 100000 
  ]) ) ;
   credit(1000 + random(1450) ) ;
   set("gender", "male");
   set("id", ({ "dealer", "psycho", "drug dealer" }) ) ;
    set("author", "Chronos") ;
    set ("damage", ({ 4,6 }) ) ;
    set ("weapon_name", "fists") ;
    set_verbs( ({ "swing at", "attack", "punche at" }) );
   set("chat_chance", 5) ;
   set("chat_output", ({
    "The psychotic drug dealer cleans his guns slowly.\n",
       "The psychotic drug dealer raps out loud.\n",
   "Psychotic Drug Dealer says [to you]: You'z a bitch.\n",
    "The psychotic drug dealer talks to himself.\n",
  "The psychotic drug dealer fires a couple rounds into the mattress.\n",
  }) ) ;
   set_skill("Small Arms", 5, "strength") ;
   set("stat/strength", 25) ;
  set("att_chat_output", ({
     "Psychotic drug dealer says: Yea yea yea!!!\n",
     "Psychotic drug dealer says: Yea, fuck you!\n",
     "Psychotic drug dealer says: Die bitch!\n",
     "Psychotic drug dealer says: Youz gonna be in a casket soon, beee yatch!\n",
     "Psychotic drug dealer says: Pop! pop!  Another sucka DROPZ!\n",
       "Psychotic drug dealer says: THUG LIFE! YEaaaaaaaaa!\n",
     "Psychotic drug dealer twirls his guns expertly.\n",
    "A bullet grazes your head.\n",
   }) ) ;
  set_level(25) ;
  set("hasted", 1) ;
  set_skill("Two Weapon Style", 4, "strength") ;
    arm(M_WEAP+"beretta") ;
   arm(M_WEAP+"m_kahrk9") ;
    wear(M_OBJ+"bp_vest") ;
    set("stat/dexterity", 19) ;
  }            

void init () {
  command("wear all SILENT") ;
   command("wield rk9") ;
}

void die() {
    set("ammo", ([ "9mm" : random(300), ]) ) ;
   tell_object(environment(), 
    "Psychotic drug dealer says: Only God Can Judge Me.  WEST SAHHHIIIIIIID!\n") ;
  ::die() ;
}
