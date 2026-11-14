/*
** Hartward, Shopkeeper of the NF City-Shop
** Author: Thragor@Nightfall, 22may96
** Update: Thragor@Nightfall, 17jun96
*/

#include <spellmonster.h>
#include <combat.h> // DT_...
#include <magic.h>
#include <living.h>

#define SF(x) #'x //'
#define D(x,y) "/players/thragor/lib/debug"->debug("thragor",x,y)
#define ME this_object()

inherit "/obj/monster/spellmonster";

public status check_sp()
     // Only suck sp, when own sp are low.
{
  return (int)QuerySP()<30;
}

public mapping spell_sucksp(mapping spell)
     // Suck the SP, but don't change the spell-mapping, as this
     // function only performs the action.
{
  object *vic,env;
  int sp,current_sp,i,sum;
  if (!env = environment()) return 0;
  i = sizeof(vic = filter(all_inventory(env),SF(living))-({ME}));
  show_room(env,map(({"@@MyName|1@@ concentrates for a moment. "
			      "@@MyPronoun|1@@ sweats blood.\n"}),
			  SF(parse_string)));
  while(i--)
    {
      current_sp = vic[i]->QuerySP();
      if (current_sp>30) current_sp = 30;
      sum+=current_sp;
      vic[i]->ReduceSP(current_sp);
      tell_object(vic[i],
		  parse_string("You feel a drain in your magic power.\n"));
    }
  HealSP(sum);
  return spell;
}

public void create()
{
  if (::create()) return;
  SetRace("human");
  SetName("Hartward");
  SetShort("Hartward, the shopkeeper");
  SetLong("He has bright blue eyes and a dark bronze skin. Under his "
	  "coat you can have a presentiment of many muscles but although "
	  "he looks quite strong and not thin at all, his movements look "
	  "like those of a cat.\n");
  SetGender(GENDER_MALE);
  SetIds(({"hartward","shopkeeper"}));
  SetAds(({"strong"}));
  SetLevel(70);
  SetCon(60);
  SetDex(75);
  SetStr(70);
  SetInt(65);
  SetAlign(435);
  SetMaxHP(1500);
  SetHP(1500);
  SetMaxSP(1000);
  SetSP(1000);
  SetKillXP(250000);
  SetNoise("You don't hear anything while he moves.\n");
  SetSmell("He uses a strange oriental parfume.\n");
  AddQuestion("hartward","Hartward says: That's me, stranger.\n");
  AddQuestion("shopkeeper",
	      "Hartward says: Well, I'm the shopkeeper of THIS shop and\n"
	      "  I'm the guildleader of the guild of shopkeepers.\n");
  AddQuestion("muscles",
	      "Hartward says: Just east enough and train them, then you'll\n"
	      "  soon get as strong muscles as I have.\n");
  AddQuestion(({"rumours","rumour"}),
	      "Hartward says: Don't believe in those lies.\n");
  AddQuestion(({"guild","guild of shopkeepers"}),
	      "Hartward says: This guild can only be joined by the\n"
	      "  shopkeepers in Nightfall. The guildleader, which is me\n"
	      "  at the moment, is automatically responsible for all general\n"
	      "  changes/decisions in the guilds.\n");
  SetCastChance(60); // 60% of Hartward's Attacks will be magic
  AddSpell("thunder",
	   ([
	     S_CHANCE:40, // chance of 40% that this spell is cast
	     S_COMBAT_DELAY:2, // wait 2 hbs after spell got cast
	     S_SIMULT:0, // don't do a physical attack when this spell gets cast
	     S_VICTIMS:1, // only one victim
	     S_DELAY:5, // only cast this spell every 10 rounds
	     S_DAMTYPE:DT_PSYCHO, // what kind of damage
	     S_MINDAM:10, // minimum amount of damage
	     S_MAXDAM:40, // maximum amount of damage
	     S_SP:10, // how much spellpoints this spell costs
	     S_GLOBAL_ENVMSG:({"Hartward's eyes sparkle in a bright blue "
			       "light",""}),
	     S_ENVMSG:([
			MSG_NORMAL:
			({"@@MyName|1@@ turns towards @@VicName@@ and points "
			  "at @@VicObjective@@.\n"
			  "You hear a loud thunder from far away and "
			  "suddenly @@VicName@@ starts to scream.\n",
			  "You hear a thunder from far away and suddenly "
			  "someone is screaming.\n"
		        }),
			MSG_DEAD:
			({"@@MyName|1@@ laughs at @@VicName@@.\n",
			  "Someone laughs.\n"
			})
		      ]),
	     S_VICMSG:([
			MSG_NORMAL:
			({"@@MyName|1@@ turns towards you and points at you.\n"
			  "Suddenly you hear a loud thunder from far away.\n"
			  "The thunder comes closer and closer and suddenly "
			  "you feel a great pain in your head.\n",
			  "Suddenly you hear a loud thunder from far away.\n"
			  "The thunder comes closer and closer and suddenly "
			  "you feel a great pain in your head.\n"
		        }),
			MSG_DEAD:
			({"@@MyName|1@@ laughs at you.\n",
			  "Someone laughs.\n"
			})
		     ])
	   ])
	  );
  AddSpell("sucksp",
	   ([
	     S_CHECKFUN:SF(check_sp),
	     S_FUN:SF(spell_sucksp),
	     S_CHANCE:10,
	     S_SIMULT:0,
	     S_VICTIMS:30,
	     S_DELAY:5,
	     S_MAXDAM:0
	   ])
	  );
  AddSpell("torture",
	   ([
	     S_CHANCE:30,
	     S_COMBAT_DELAY:0, // this doesn't take time for Hartward
	     S_SIMULT:1, // Hartward may do a physikal attack this turn, too
	     S_VICTIMS:2, // Hartward may take two opponents at once
	     S_DELAY:10,
	     S_DAMTYPE:DT_PSYCHO,
	     S_MINDAM:20,
	     S_MAXDAM:50,
	     S_SP:20,
	     S_GLOBAL_ENVMSG:({"@@MyName|1@@ concentrates for a moment.\n",""}),
	     S_ENVMSG:([
			MSG_NORMAL:
			({"Suddenly @@VicName@@ screams in agony.\n",
			  "Someone screams loudly.\n"
		        }),
		      ]),
	     S_VICMSG:([
			MSG_NORMAL:
			"You feel as if someone just has put you into a giant "
			"thumbscrew.\n"
			// The message for those victims who see and those
			// victims who can't see, is the same in this case.
		      ])
	   ])
	  );
  AddSpell("comment", // this spell is not a spell but just a comment to
	              // the player, Hartward is fighting at.
	   ([
	     S_CHANCE:5,
	     S_SIMULT:1,
	     S_VICTIMS:30, // well, this should hit all victims
	     S_DELAY:10,
	     S_MAXDAM:0, // this ensures, that it's really just a message
	     S_GLOBAL_ENVMSG:({"@@MyName|1@@ laughs scornfully at "
			       "@@VicName@@.\n",
			       "Someone laughs scornfully.\n"
			     })
	   ])
	  );
  AddSpell("mindbomb",
	   ([
	     S_CHANCE:15, // Now sum 100 is complete. This doesn't need to
	                  // be, but the code is easier to understand.
	                  // If it is not 100, it will be modified so it
	                  // fits to 100, all other values adjusted in the
	                  // same way, i. e. you just specify a region, where
	                  // random can hit.
	     S_COMBAT_DELAY:3,
	     S_SIMULT:0,
	     S_VICTIMS:30,
	     S_DELAY:15,
	     S_DAMTYPE:DT_PSYCHO,
	     S_MINDAM:20,
	     S_MAXDAM:80,
	     S_SP:50,
	     S_GLOBAL_ENVMSG:({"@@MyName|1@@ concentrates for a moment.\n",""}),
	     S_ENVMSG:([
			MSG_NORMAL:
			({"Suddenly @@VicName@@ screams in agony.\n",
			  "Someone screams loudly.\n"
			}),
			MSG_DEAD:
			({"@@MyName|1@@ grins evilly.\n"
			  "@@MyPronoun|1@@ takes @@VicGenitive@@ head and "
			  "kicks against it.\n",""
			})
		      ]),
	     S_VICMSG:([
			MSG_NORMAL:"You feel your mind exploding.\n",
			MSG_DEAD:
			({"@@MyName|1@@ grins evilly.\n"
			  "@@MyPronoun|1@@ takes your head and "
			  "kicks against it.\n",
			  "Someone takes your head and kicks against it.\n"
			})
                      ])
	   ])
	  );
  SetAC(12);
  AddResistance(ST_FIRE,20);
  AddResistance(ST_COLD,20);
  AddResistance(ST_WATER,40);
  AddResistance(ST_GAS,10);
  AddResistance(ST_POISON,60);
  AddResistance(ST_ZAP,100);
  AddResistance(ST_ELECTRO,10);
  AddResistance(ST_ACID,20);
  AddResistance(ST_PSYCHO,100);
  AddResistance(ST_KNOW,100);
  AddResistance(ST_PROTECT,0);
  AddResistance(ST_HEAL,0);
  AddResistance(ST_CREATE,40);
  AddResistance(ST_SUMMON,50);
  AddResistance(ST_TELEPORT,100);
  AddResistance(ST_LIGHT,0);
  AddResistance(ST_DARK,100);
  AddResistance(ST_CHANGE,90);
  AddResistance(ST_DESTRUCT,100);
  AddResistance(ST_FUN,30);
  AddDefence(DT_SLASH,2);
  AddDefence(DT_BLUDGEON,3);
  AddDefence(DT_PIERCE,1);
  AddDefence(DT_FIRE,20);
  AddDefence(DT_COLD,20);
  AddDefence(DT_WATER,40);
  AddDefence(DT_GAS,5);
  AddDefence(DT_ZAP,100);
  AddDefence(DT_ELECTRO,10);
  AddDefence(DT_ACID,20);
  AddDefence(DT_POISON,50);
  AddDefence(DT_PSYCHO,80);
  AddDefence(DT_NOAIR,100);
}

private status valid_enemy(object pl)
{
  if (!pl) return 0;
  if (!pl->QueryIsPlayer()) return 0;
  if (pl->QueryLevel()<5)
    {
      if (environment())
	tell_room(environment(),
		  "Hartward says: Hey, "+pl->QueryName()+"! Don't you think "
		  "you're a bit too small to fight\n"
		  "  against me? Better stop that.\n");
      pl->StopHunting(this_object());
      StopHunting(pl);
      return 0;
    }
  return 1;
}
	  
public void Attack()
{
  filter(QueryEnemies()||({}),SF(valid_enemy));
  HealHP(3);
  (::Attack());
}
