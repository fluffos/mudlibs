/*
** The Guildobject of the Adventurers
** Authors: Cadra & Thragor
** Update: Thragor@Nightfall, 25aug95
*/

#include <config.h>
#include <combat.h>
#include <moving.h>
#include <magic.h>
#include <properties.h>
#include <secure/wizlevels.h>
#include "path.h"

#define GUILDSTR    "adventurer"
#define IS_PAINTED  "painted"
#define GUILDID     "adv020169"
#define STR         "/lib/string"
#define HITLOG      "KILLER"

inherit "/std/weapon";
//inherit GUILDOBJ("help");
inherit "/obj/lib/guildobj";

public void create()
{
  (::create());
  if (!is_clone()) return;
  seteuid(getuid());
  SetGuild(CITY("adv_guild"));
  SetShort("a runed wandererstaff");
  SetLong(
"The staff is carved and runed all over. It is made of yewwood. Yes, you are "
"right, this wood is too precious to make wandererstaffs out of it, but this "
"staff is a very special one. There is a hilt at one end of it and a small bell "
"is implemented into the hilt. Try to listen to your staff.\n");
  SetWC(3);
  SetResetQuality(100);
  SetNoise(
"You hear the soft ringing of a small bell. It tells you that this staff is "
"your personal one and will work for noone else.\n");
  SetWeaponType(WT_STAFF);
  SetDamType(DT_BLUDGEON);
  SetIds( ({"staff",GUILDID,"wandererstaff"}) );
  SetAds( ({"a","runed","adventurer","my"}) );
  SetNoGive(1);
  Set(P_NOBUY,1);
  Set(P_NOSELL,1);
  SetNoDrop(1);
SetAutoObject(1);
#if 0
  write(
  "This staff is no longer available. Please go back into one\n"
  "guildoffice of the adventurers and you will get another staff.\n"
  "This object is going to self-destruct now. 4 - 3 - 2 - 1 - 0 ...\n");
  call_out("remove",1);
#endif
}


public string InformGShout(object receiver,object sender, string text)
{
  if (receiver==sender)
    return "You shout to all adventurers: "+text+"\n";
  return sender->QueryName()+" shouts to all adventurers shouting: "+text+"\n";
}

public void init() {
  (::init());
/* fighting */
  add_action("missile","missile");     // level 5
  add_action("shock","shock");         // level 10
  add_action("fireball","fireball");   // level 15
  add_action("snowball","snowball");   // level 20
  add_action("lightning","lightning"); // level 25
  add_action("icestorm","icestorm");   // level 30
/* fun */
  add_action("stonekick","stonekick"); // level 5
  add_action("foolsgold","foolsgold"); // level 10
  add_action("paint","paint");         // level 15
  add_action("clean","clean");         // level 15
  add_action("button","button");       // level 20
  add_action("tent","tent");           // level 20
  add_action("travel","travel");       // level 25
/* communication */
  add_action("cmd_gshout","guildshout");  // all
  add_action("cmd_gwho","adventurer");  // all
/* diversa */
  add_action("light","light");  // all
  add_action("dark","dark");    // all
  add_action("leaveguild","leaveguild");  // all
  add_action("advhelp","advhelp");  // all
  add_false_cmds();  // for the guildleaders
}


private string spell_format(string str)
{
  return STR->ladjust(str,12);
}


public string QueryNoise()
{
  int gl;
  gl = this_player()->QueryLevel();
  return "\
The bell starts to ring and you get a secret message: "
"You are an adventurer of level "+to_string(gl)+
" and you know the following spells:\n"+
(gl>4?(spell_format("missile")+
       (gl>9?spell_format("shock"):"")+
       (gl>14?spell_format("fireball"):"")+
       (gl>19?spell_format("snowball"):"")+
       (gl>24?spell_format("lightning"):"")+
       (gl>29?spell_format("icestorm"):"")
      ):"(no combat spells)"
)+"\n"+
(gl>4?(spell_format("stonekick")+
       (gl>9?spell_format("foolsgold"):"")+
       (gl>14?spell_format("paint"):"")+
       (gl>14?spell_format("clean"):"")+
       (gl>19?spell_format("button"):"")+
       (gl>19?spell_format("tent"):"")+
       (gl>24?spell_format("travel"):"")
      ):"(no special spells)"
)+"\n"+spell_format("guildshout")+spell_format("adventurer")+"\n"+
spell_format("light")+spell_format("dark")+"\n"
"You may get a little help about all actions by using 'advhelp <topic>'\n"
"You may always leave the guild by typing 'leaveguild'.\n";
}



public int leaveguild()
{
  return QueryGuild()->cmd_leave("guild");
}


private int failure()
{
  int chance,fail;
  chance = 
    this_player()->QueryInt()+
    this_player()->QueryDex()+
    this_player()->QueryLevel()/2;
  fail = random(101);
  if ((fail <= chance) && (fail != 100)) return 0;
  return 1;
}


private void log_attack(object ob,string descr)
{
 string mylevel,klevel;
 int i;
 if (i=query_user_level(this_player())) mylevel = "w"+i;
 else mylevel = this_player()->QueryLevel()+
                "/"+(RACEMASTER->XPtoLevel(this_player()->QueryXP()));
 if (i=query_user_level(ob)) klevel = "w"+i;
 else klevel = ob->QueryLevel()+
               "/"+(RACEMASTER->XPtoLevel(ob->QueryXP()));
 
 if (!query_once_interactive(ob)) return;
 log_file(HITLOG,ctime()+" "+capitalize(getuid(this_player()))+"("+mylevel+
  ") attacked "+capitalize(getuid(ob))+"("+klevel+") using '"+descr+"'.\n");
}


private int repulse(object enemy,string cname) {
  int lvl, res;
  mixed def;
  if (!this_player()) return 0;
  if (!enemy) return 0;
  lvl = this_player()->QueryLevel();
  def = enemy->Query("Resistance");
  if (def && sizeof(def)) {
     if (member(def,cname) > -1 && enemy != this_player()) {
        say(enemy->QueryName()+" is resistent against that spell.\n",enemy);
        tell_object(enemy, "Luckily you are protected against that spell.\n");
        tell_object(this_player(),
            enemy->QueryName()+" is resistent against that spell.\n");
            return 1;
     }
     else if (member(def,cname) > -1) {
        tell_object(this_player(), "Luckily you are protected against that spell.\n");
        return 1;
     }
  }
  res = enemy->QueryAttribute("MagicDefence");
  if ( (random(100)+lvl > res) && (res < 100) ) return 0;
  if (enemy != this_player()) {
     say(enemy->QueryName()+" is not affected by "+
         this_player()->QueryName()+"'s spell.\n", this_player());
     tell_object(this_player(), enemy->QueryName()+
     " doesn't seem to be affected by your spell.\n");
  }
  else tell_object(this_player(),
       "Luckily you are protected against backfiring spells.\n");   
  return 1;
}

private void dam_message(int dam,int dam_type,object victim)
{
 string plmsg,vicmsg,envmsg,obj,poss,pron;
 obj = victim->QueryObjective();
 poss = victim->QueryPossessive();
 pron = victim->QueryPronoun();
 switch(dam_type)
 {
  case DT_FIRE:
    switch(dam)
    {
     case 0: vicmsg = " but misses you";
             plmsg  = " but miss "+obj;
             envmsg = " but misses "+obj; break;
     case 1: vicmsg = " burn some of your hairs";
             plmsg  = " burn some of "+poss+" hairs";
             envmsg = " burns some of "+poss+" hairs"; break;
     case 2..3: vicmsg = " slightly burns your skin";
                plmsg  = " slightly burn "+poss+" skin";
                envmsg = " slightly burns "+poss+" skin"; break;
     case 4..5: vicmsg = " burns you";
                plmsg  = " burn "+obj; 
                envmsg = " burns "+obj; break;
     case 6..10: vicmsg = " burns you hot";
                 plmsg  = " burn "+obj+" hot";
                 envmsg = " burns "+obj+" hot"; break;
     case 11..20: vicmsg = " burns you very hot";
                  plmsg  = " burn "+obj+" very hot";
                  envmsg = " burns "+obj+" very hot"; break;
     case 21..30: vicmsg = " carbonizes you";
                  plmsg  = " carbonize "+obj;
                  envmsg = " carbonizes "+obj; break;
     default: vicmsg = " carbonizes you to small ashes";
              plmsg  = " carbonize "+obj+" to small ashes";
              envmsg = " carbonizes "+obj+" to small ashes";
    }
    break;
  case DT_COLD:
    switch(dam)
    {
     case 0: vicmsg = " but misses you";
             plmsg  = " but miss "+obj;
             envmsg = " but misses "+obj; break;
     case 1: vicmsg = " makes your skin creeping";
             plmsg  = " make "+poss+" skin creeping";
             envmsg = " makes "+poss+" skin creeping"; break;
     case 2..3: vicmsg = " freezes your skin";
                plmsg  = " freeze "+poss+" skin";
                envmsg = " freezes "+poss+" skin"; break;
     case 4..5: vicmsg = " freezes you";
                plmsg  = " freeze "+obj; 
                envmsg = " freezes "+obj; break;
     case 6..10: vicmsg = " freezes you cold";
                 plmsg  = " freeze "+obj+" cold";
                 envmsg = " freezes "+obj+" cold"; break;
     case 11..20: vicmsg = " freezes you very cold";
                  plmsg  = " freeze "+obj+" very cold"; 
                  envmsg = " freezes "+obj+" very cold"; break;
     case 21..30: vicmsg = " freezes you completely";
                  plmsg  = " freeze "+obj+" completely";
                  envmsg = " freezes "+obj+" completely"; break;
     default: vicmsg = " freezes you to an icecube";
              plmsg  = " freeze "+obj+" to an icecube";
              envmsg = " freezes "+obj+" to an icecube";
    }
    break;
  case DT_PSYCHO:
    switch(dam)
    {
     case 0: vicmsg = " but misses you";
             plmsg  = " but miss "+obj; 
             envmsg = " but misses "+obj; break;
     case 1: vicmsg = " makes your skin creeping";
             plmsg  = " make "+poss+" skin creeping"; 
             envmsg = " makes "+poss+" skin creeping"; break;
     case 2..3: vicmsg = " slighly shocks you";
                plmsg  = " slightly shock "+obj; 
                envmsg = " slightly shocks "+obj; break;
     case 4..5: vicmsg = " you feel scared";
                plmsg  = " "+pron+" feels scared"; 
                envmsg = " "+pron+" feels scared"; break;
     case 6..10: vicmsg = " feel terribly scared";
                 plmsg  = " "+pron+" feels terribly scared"; 
                 envmsg = " "+pron+" feels terribly scared"; break;
     case 11..20: vicmsg = " feel most terribly scared";
                  plmsg  = " "+pron+" feels most terribly scared"; 
                  envmsg = " "+pron+" feels most terribly scared"; break;
     case 21..30: vicmsg = " pushes you into a nightmare";
                  plmsg  = " push "+obj+" into a nightmare"; 
                  envmsg = " pushes "+obj+" into a nightmare"; break;
     default: vicmsg = " pushes you into your most horrible nightmare";
              plmsg  = " push "+obj+" into "+poss+" most horrible nightmare";
              envmsg = " pushes "+obj+" into "+poss+" most horrible nightmare";
    }
    break;
  case DT_ELECTRO:
    switch(dam)
    {
     case 0: vicmsg = " but misses you";
             plmsg  = " but miss "+obj; 
             envmsg = " but misses "+obj; break;
     case 1: vicmsg = " makes your skin creeping";
             plmsg  = " make "+poss+" skin creeping"; 
             envmsg = " makes "+poss+" skin creeping"; break;
     case 2..3: vicmsg = " sends small flashes against you";
                plmsg = " send small flashes against "+obj; 
                envmsg = " sends small flashes against "+obj; break;
     case 4..5: vicmsg = " sends a bolt of lightning against you";
                plmsg  = " send a bolt of lightning against "+obj;
                envmsg = " sends a bolt of lightning against "+obj; break;
     case 6..10: vicmsg = " makes you glowing and trembling";
                 plmsg  = " make "+obj+" trmebling. "+pron+" starts to glow"; 
                 envmsg = " makes "+obj+" trmebling. "+pron+" starts to glow"; break;
     case 11..20: vicmsg = " sends a huge flash against you";
                  plmsg  = " send a huge flash against "+obj;
                  envmsg = " sends a huge flash against "+obj; break;
     case 21..30: vicmsg = " makes large flashes running up and down your skin";
                  plmsg  = " make large flashes running up and down "+poss+" skin"; 
                  envmsg = " makes large flashes running up and down "+poss+" skin"; break;
     default: vicmsg = " sends several bolts of lightning against you";
              plmsg  = " send several bolts of lightning against "+obj;
              envmsg = " sends several bolts of lightning against "+obj;
    }
    break;
 }
 tell_object(this_player()," and"+plmsg+".\n");
 tell_object(victim," and"+vicmsg+".\n");
 tell_room(environment(this_player())," and"+envmsg+".\n",
           ({this_player(),victim}));
}


private int check_cast(int gl,string str,string what,int SP,int dam,
                       int dam_type,int spelltype) {
  object ob,*e;
  string pl_short;
 if ((this_player()->QueryLevel()) < gl) return (int) notify_fail(
    "You don't know that.\n");
 if (this_player()->QueryGhost()) return (int) notify_fail(
    "You can't do this in your current state.\n") && 0;
 if (environment(this_player())->QueryIsMagicForbidden(spelltype))
   return (int) notify_fail(
    "Your magic won't work here.\n") && 0;
 if (!str)
   if (!sizeof(e = (this_player()->QueryEnemies()-({0}))||({})))
      return (int) notify_fail("What do you want to hit?\n") && 0;
     else ob = e[0];
   else ob=present(str,environment(this_player()));
 if (!ob)
    return (int) notify_fail("You don't see that here!\n") && 0;
 if (ob->QueryGhost()) return (int) notify_fail(
    "You can't attack that!\n") && 0;
 if (!living(ob))
    return (int) notify_fail("You can't do any harm to this.\n") && 0;
 if (repulse(ob,what)) return (int) notify_fail("You failed.\n") && 0;
 if (!this_player()->ReduceSP(SP)) return (int) notify_fail(
    "You are too exhausted to try this!\n") && 0;
 if (failure()) return (int) notify_fail(
    "You failed to cast the spell.\n") && 0;
 pl_short = ob->QueryName();
 tell_object(this_player(),"You cast "+what+" at "+pl_short);
 tell_object(ob,this_player()->QueryName()+" casts "+what+" at you");
 tell_room(environment(this_player()),this_player()->QueryName()+
 " casts "+what+" at "+pl_short,({this_player(),ob}));
 dam_message(dam,dam_type,ob);
 log_attack(ob,what);
 ob->Defend(dam,dam_type,0);
 return 1;
}


public int missile(string str) {
  return check_cast(5,str,"a missile",20,random(10),DT_FIRE,ST_FIRE);
}


public int shock(string str) {
  return check_cast(10,str,"shock",40,random(20),DT_PSYCHO,ST_PSYCHO);
}


public int fireball(string str) {
  return check_cast(15,str,"a fireball",60,random(30),DT_FIRE,ST_FIRE);
}


public int snowball(string str) {
  return check_cast(20,str,"a snowball",80,10+random(30),DT_COLD,ST_COLD);
}


public int lightning(string str) {
  return check_cast(25,str,"lightning",100,random(20)+random(30),DT_ELECTRO,
                    ST_DAMAGE);
}


public int icestorm(string str) {
  object ob,*e,*inv;
  int dam,amount;
  string pl_short;
 if ((this_player()->QueryLevel()) < 30) return (int) notify_fail(
    "You don't know that.\n");
 if (this_player()->QueryGhost()) return (int) notify_fail(
    "This is not possible in your current state.\n") && 0;
 if (environment(this_player())->QueryMagicIsForbidden(ST_COLD))
   return notify_fail("You can't cast this inside here.\n"),0;
 amount = 
  sizeof(inv=filter(all_inventory(environment(this_player())),#'living));
 dam=(random(this_player()->QueryLevel())+random(40))/amount;
 if (!str) {
  if (sizeof(e = (this_player()->QueryEnemies()-({0}))||({})))
   ob = e[0];
  }
  else ob=present(str,environment(this_player()));
 if (!this_player()->ReduceSP(140)) return (int) notify_fail(
    "You are too exhausted to try this!\n") && 0;
 if (failure()) return (int) notify_fail(
    "You failed to cast the spell.\n") && 0;
 if (ob) {
 if (ob->QueryGhost()) return (int) notify_fail(
    "You cannot hurt "+ob->QueryName()+".\n") && 0;
 if (!living(ob))
    return (int) notify_fail("You can't do any harm to this.\n") && 0;
 if (repulse(ob,"an icestorm")) return (int) notify_fail("You failed.\n") && 0;
 pl_short = ob->QueryName();
 tell_object(this_player(),"You cast an icestorm at "+pl_short);
 tell_object(ob,this_player()->QueryName()+" casts an icestorm at you");
 tell_room(environment(this_player()),this_player()->QueryName()+
 " casts an icestorm at "+pl_short,({this_player(),ob}));
 dam_message(dam,DT_COLD,ob);
 log_attack(ob,"an icestorm");
 ob->Defend(dam,DT_COLD,0);
 }
 if (amount = sizeof(inv=inv-({ob})-({this_player()})))
   while(amount--) {
    if (inv[amount]->QueryGhost()) continue;
    if (repulse(ob,"an icestorm")) continue;
    tell_object(inv[amount],
     "The icestorm becomes very strong");
    tell_room(environment(this_player()),
     "The icestorm takes effect on "+inv[amount]->QueryName(),({inv[amount]}));
   dam_message((dam*2)/3,DT_COLD,inv[amount]);
   log_attack(inv[amount],"an icestorm (room-attack)");
   inv[amount]->Defend((dam*2)/3,DT_COLD,0);
   }
 if (!repulse(this_player(),"an icestorm")) {
   tell_object(this_player(),"You feel frozen.\n");
   this_player()->DoDamage(dam/2);
 }
 return 1;  
}



/****** FUN-Functions ******/

public int stonekick(string str) {
  object ob,pl;
/*
  if ((this_player()->QueryLevel()) < 5) return (int) notify_fail(
"You are too unexperienced to do that!\n") && 0;
*/
  if (!str)
    return (int) notify_fail("Kick a stone at whom?\n");
  pl=(find_player(str) || present(str,environment(this_player())));
  if (!pl) return (int) notify_fail("That is not here.\n");
  if (!this_player()) return 0;
  if (!environment(this_player())) return 0;
  if (!present(pl,environment(this_player()))) 
    return (int) notify_fail(pl->QueryShort()+" is not here!\n") && 0;
  if (!this_player()->ReduceSP(1)) return (int) notify_fail(
"You feel too exhausted to do so.\n") && 0;
  tell_object(pl,this_player()->QueryName()+" kicks a stone at you.\n");
  ob=clone_object(GUILDOBJ("stone"));
  ob->move(environment(pl),M_SILENT);
  write("You kick a stone at "+pl->QueryName()+".\n");
  return 1;
   }


public int foolsgold(string str) {
  object ob,env;
  if ((this_player()->QueryLevel()) < 10) return (int) notify_fail(
"You are too unexperienced to know this.\n") && 0;
  if (!str) return 0;
  if (!this_player()) return 0;
  if (!ob=present(str,environment(this_player())) || 
     (present(str,this_player()))) return (int) notify_fail(
"You don't find that anywhere.\n") && 0;
  if (!this_player()->ReduceSP(40)) return (int) notify_fail(
"You feel too exhausted to do so.\n");
  if (ob->QueryValue())   
     ob->SetValue(1);
  if (ob->QueryWC())
     ob->SetWC(1);
  if (ob->QueryAC())
     ob->SetAC(0);
  if (!environment(ob)->MayAddWeight(4000)) 
     if (env=environment(environment(ob))) {
     tell_object(environment(ob),"This item is much too heavy for you.\n");
     ob->move(env,M_DROP);
     }
  ob->SetWeight(ob->QueryWeight()+4000);
  write("You succeed.\n");
  return 1;
}


public int paint(string str) {
  object ob,env;
  string what,color;
  string pl_short;
  if ((this_player()->QueryLevel()) < 15) return (int) notify_fail(
"You are too unexperienced to know this.\n") && 0;
  if (!str) return (int) notify_fail(
"What do you want to paint how?\n") && 0;
  if (!this_player()) return 0;
  if (sscanf(str,"%s in %s",what,color) != 2)
     if (sscanf(str,"%s %s",what,color) != 2)
     return (int) notify_fail(
"Paint what in what color?\n");
  if (!sscanf(color,"%s color",str))
     if (!sscanf(color,"%s colour",str))
     str=color;
  if (strlen(color) > 15) return (int) notify_fail(
"You do not know how to mix this color.\n") && 0;
     color=lower_case(str);
  if (!ob=present(what,environment(this_player())) || 
     (present(what,this_player()))) return (int) notify_fail(
"You don't find that anywhere.\n") && 0;
  if (ob->Query(IS_PAINTED)) return (int) notify_fail(
"You do not want to destruct that beautiful sight.\n") && 0;
  if (!this_player()->ReduceSP(15)) return (int) notify_fail(
"You are too exhausted to do so.\n") && 0;
  pl_short=ob->QueryShort();
  if (!pl_short) return (int) notify_fail("You don't see that here!\n");
  if (query_once_interactive(ob)) {
  pl_short=ob->QueryPresay()+ob->QueryName()+" "+ob->QueryTitle();
  ob->SetShort(pl_short+" painted "+color+" by "+this_player()->QueryName());
  ob->Set(IS_PAINTED,1);
  tell_object(ob,this_player()->QueryName()+" paints you "+color+".\n");
  tell_object(this_player(),"You paint "+pl_short+" in "+color+".\n"); 
  tell_room(environment(ob),this_player()->QueryName()+" paints "+pl_short+" "+color+".\n",({this_player(),ob}));
  return 1;
  }
  ob->SetShort(pl_short+" painted "+color+" by "+this_player()->QueryName());
  ob->Set(IS_PAINTED,1);
  ob->AddAdjective(color);
  tell_object(this_player(),"You paint "+pl_short+" in "+color+".\n"); 
  tell_room(environment(ob),this_player()->QueryName()+" paints "+pl_short+" "+color+".\n",({this_player(),ob}));
  return 1;
}


public int clean(string what) {
  object ob,env;
  string origshort,how;
  string pl_short;
  if ((this_player()->QueryLevel()) < 15) return (int) notify_fail(
"You are too unexperienced to know this.\n") && 0;
  if (!what) return (int) notify_fail(
"What do you want to clean?\n") && 0;
  if (!this_player()) return 0;
  if (!ob=present(what,environment(this_player())) || 
     (present(what,this_player()))) return (int) notify_fail(
"You don't find that anywhere.\n") && 0;
  if (!ob->Query(IS_PAINTED)) return (int) notify_fail(
"Nothing to clean.\n") && 0;
  if (!this_player()->ReduceSP(15)) return (int) notify_fail(
"You are too exhausted to do so.\n") && 0;
  pl_short=ob->QueryShort();
  if (!pl_short) return (int) notify_fail("You don't see that here!\n");
  if (sscanf(pl_short,"%s painted %s",origshort,how)!=2)
   return (int)notify_fail("Nothing to clean.\n")&&0;
  ob->SetShort(origshort);
  ob->Set(IS_PAINTED,0);
  tell_object(this_player(),"You clean "+origshort+".\n");
  tell_room(environment(ob),this_player()->QueryName()+" cleans "+origshort+".\n",({this_player(),ob}));
  if (query_once_interactive(ob)) 
  tell_object(ob,this_player()->QueryName()+" cleans you.\n");
  return 1;
}



public int button(string str) {
  object button;
  if (!str) return (int) notify_fail(
"You should really have more ideas what kind of button it should be!\n");
  if (!this_player()) return 0;
  if ((this_player()->QueryLevel()) < 15) return (int) notify_fail(
  "You don't know how to cast this spell!\n") && 0;
  if (!this_player()->ReduceSP(15)) return (int) notify_fail(
"You are too exhausted to do so.\n") && 0;
  tell_object(this_player(),"You create a BIG button.\n");
  button=clone_object(GUILDOBJ("button"));
  button->SetText(str);
  if ( (button->move(this_player(),M_GET)) != ME_OK) {
    button->move(environment(this_player()),M_DROP);
    tell_object(this_player(),"The button is too much to carry.\n");
  }
    return 1;  
}



public int tent() {
  object ob;
  if (!this_player()) return 0;
  if (!environment(this_player())->id("advguild"))
    return (int) notify_fail("You could never get that here.\n") && 0;
  if ((this_player()->QueryLevel()) < 20)
     return (int) notify_fail(
"You would not know how to use it. Wait until you are more experienced!\n")&& 0;
  if (present("tent",this_player()))
    return (int) notify_fail(
"You already got a tent. That is enough for you!\n") && 0;
  if (!this_player()->ReduceSP(202)) return (int) notify_fail(
"You can't do this now, you look too tired.\n") && 0;
  ob=clone_object(GUILDOBJ("advtent"));
  ob->move(this_player(),M_GET);
  return 1;
}



public int travel() {
  if (!this_player()) return 0;
  if (!environment(this_player())->id("advguild"))
    return (int) notify_fail(
"You can't do it here magically. Use your own feet.\n") && 0;
  if ((this_player()->QueryLevel()) < 25)
     return (int) notify_fail(
"You don't know how to travel magically it. Wait until you are more "
"experienced!\n")&& 0;
  if (!this_player()->ReduceSP(50)) return (int) notify_fail(
"You are too exhausted to travel right now.\n") && 0;
  this_player()->move(GUILDOBJ("tportroom"),M_GO,"travelling");
  return 1;
}



public int light(string str) {
  object ob;
  if (str) return 0;
  if (!this_player()->ReduceSP(5)) return (int) notify_fail(
"You find no power to light this place.\n") && 0;
  if (!this_player()) return 0;
  if (!environment(this_player())) return 0;
  ob=clone_object(GUILDOBJ("light"));
  ob->move((environment(this_player())),M_SILENT);
  return 1;
}



public int dark(string str) {
  object ob;
  if (str) return 0;
  if (!this_player()->ReduceSP(5)) return (int) notify_fail(
"You find no power to darken this place.\n") && 0;
  if (!this_player()) return 0;
  if (!environment(this_player())) return 0;
  ob=clone_object(GUILDOBJ("dark"));
  ob->move((environment(this_player())),M_SILENT);
  return 1;
}
