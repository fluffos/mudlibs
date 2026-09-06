#include "/players/softly/closed/ansi.h"

id(str) { return str == "book" || str == "newbie book"; }
reset() {}

long() { write(
	       "  A very old leather bound book engraved with golden letters\n\
that say\n\
\t\t" + HIY + "Welcome to Nirvana\n\
\t\tHelp for Newcomers" + NORM + "\n\n\
It is filled with information for newcomers to Nirvana.  You\n\
may 'read' the book here and take it with you.\n");
}

short() { return 
	    ("A leather Newbie help book"); }

init() {
  add_action("read","read");
  add_action("drop_book","drop");
}

read(arg) {
  if(!arg) { write("Read what?\n"); return 1; }
  if(arg == "book" || arg == "newbie book") {
    write(
	  "  Welcome to Nirvana.  This is a game with many players.  The object\n"+
	  "of the game is to play the game.  To do that you will get experience\n"+
	  "while you kill monsters, solve puzzles, and try not to die.  You use\n"+
	  "the experience you gain to raise your level and attributes.\n\n"+
	  "  There are a lot of ideas in that sentence you don't understand yet.\n"+
	  "There is a lot to learn.  This book and a visit to the School of the\n"+
	  "Apprentices will help you get started.  It has a list of areas where\n"+
	  "you can fight right now and information about guilds, healing, places\n"+
	  "you will want to visit, and other things that will help you get started.\n\n"+
	  "  To read the topics in this book type 'read index'.  To go to the\n"+
	  "pages shown in the index type 'read page #' where # is the page you\n"+
	  "want to read.\n\n"+
	  "  There are a lot of 'help' files in the game itself.  You can get\n"+
	  "a list of topics by typing 'help'.  To read the files you see listed\n"+
	  "type 'help <topic>'.  Read them while you are healing.  You will be\n"+
	  "surprised how much you will learn.\n\n"+
	  "  Oh yes, before you 'read index' remember this:  HAVE FUN !!!\n");
    return 1;
  }

  if(arg == "index") 
    { write
	(
	 "  This is the index of the Newbie book.  To read the information on a\n"+
	 "page, type 'read page #' where # is the page number you want to read.\n\n"+BOLD+
	 "                   Index\n"+
	 "     TITLE                        PAGE\n"+NORM+
	 "     ---------------------------------\n"+
	 "     Where am I?.....................1\n"+ 
	 "     Getting Started.................2\n"+
	 "     Where do I fight?...............3\n"+
	 "     How do I heal?..................4\n"+
	 "     Shops and other places..........5\n"+
	 "     About Guilds....................6\n"+
	 "     Guild Listing...................7\n"+
	 "     What do I do now?...............8\n"+
         "     Author: Eurale, updated by Softly & Jaraxle\n"+BOLD+
   "     ---------------------------------"+NORM+"\n"+
    "(To read a specific chapter, 'read page #')\n");
    return 1; 
    }

  if(arg == "page 1") 
    { write
	( "\n\t\t\t"+BOLD+"Where am I?\n\n"+NORM+
	  "  There are a lot of ways you could have gotten here, but\n"+
	  "now you are at 'nirvna.mudservices.com 3500'.  This is a\n"+
	  "MUD that encourages but does not require role playing.\n\n"+
	  "  If you are new to mudding try the School of the Apprentices.\n"+
	  "This school for newbies is north of the main room of the\n"+
	  "Hall of the Apprentices (s, enter hall from the church).\n\n"+
	  "  You will find many different kinds of areas here, and\n"+
	  "some differences from other places you might have played.\n"+
	  "For example here players can have kids that can spend time in\n"+
	  "a local day care center.  Player killing (PK) is optional.\n"+
	  "The equipment you wear does not save on you when you log off.\n"+
	  "However there are lockers and other ways of saving gear.\n\n"+
	  "  You may have more than one character but you may "+HIR+"NEVER"+NORM+" have\n"+
	  "more than one character on line at the same time.  They\n"+
	  "may not help each other in any way.\n\n"+
	  "  Many of the players have been here a very long time.\n"+
	  "Most will help or talk to you if you ask questions.  You\n"+
	  "may ask questions or talk on the 'newbie' channel. Please\n"+
	  "do not use shout which is for emergencies.\n\n"+
	  "  Hang around for a while and see if you like it here.  We\n"+
	  "hope you will feel welcome and stay with us.\n\n");   
    return 1; 
    }

  if(arg == "page 2") 
    { write
	( "\n\t\t"+BOLD+"Getting Started\n\n"+NORM+
	  "  From the church, go south, enter hall, then north to the\n"+
	  "School of the Apprentices.  There you will learn basic commands\n"+
	  "and get a basic weapon, armor, a light, some experience and coins.\n\n"+
	  "  Spend some time reading the help files, exploring town, and\n"+
	  "going to a few low level areas to test your skill.\n"+
	  "  The information you need to play and game rules are covered\n"+
	  "in 'help' files.  You will be much more comfortable if you\n"+
	  "spend time reading them.  Just type 'help' and you will see\n"+
	  "a list of topics.  To read about a topic type 'help <topicname>'.\n"+
	  "If, after reading the help files you can't figure things out\n"+
	  "ask another player.\n\n"+
	  "  The town is located east and west of the Church (where you\n"+
	  "entered).  There are shops, a pub, a weaponsmith, an armorer,\n"+
	  "and the Adventorer's Guild where you go to raise your levels\n"+
	  "and attributes (statistics).\n\n"); 
    return 1; 
    }

  if(arg == "page 3") 
    { write
	("\n\t\t"+BOLD+"Where Do I Fight?\n\n"+NORM+
	 "  There are many places to fight.  This list shows some that\n"+
	 "are good for new players.  Not all of the monsters are easy.\n"+
	 "The directions all start from the 'green' located south of\n"+
	 "the church (where you entered).\n\n"+
	 "  Bandit forest\t5e,3n,w,step rift,in,2w,enter,e,u,s\n"+
	 "  Castle Mael\t\t4w,2n,enter castle\n"+
	 "  Demon missionaries\t e,n\n"+
	 "  Dukes of Hazzard\t4w,5n,enter portal,hazzard\n"+
	 "  Evergloom forest\t7w, walk path\n"+
	 "  Funhouse\t\t4w,3n,e,enter doorway\n"+
	 "  Hades rift\t\t\5e,3n,w,step rift,in,2w,enter,e,u,n\n"+
	 "  House of Horrors\t9e,s,d,s\n"+
	 "  Hut\t\t\t10e,pass,ancient,e,s,hut\n"+
	 "  Imps\t\t\t3e,d,enter portal,2s,4e,n\n"+
	 "  MASH\t\t\t5e,s,enter portal,barracks\n"+
	 "  Path\t\t\t2e,s,d,lay on bed,s,2e\n"+
	 "  Pirates, Jungle\t4w,5n,w,enter shrine,island\n"+
	 "  Rats\t\t\t4w,n,4nw,n,slide cover,crawl down,descend\n"+
	 "  Santa's workshop\t6w,n\n"+
	 "  Snowflakes\t\t4w,4n,w,enter gate,newbie\n"+
	 "  South Park\t\t6w,3s,4w,4s,10w,enter hole\n"+
	 "  Toy store\t\t5e,4n,enter store\n"+
         "  Trixtown daycare\t2n,3w,2n,2e\n"+
    "  Third Earth\t4w,5n,w,enter shrine,tree\n"+
	 "  Whispering woods\t5e,2n,touch wheel,touch woods\n\n");
    return 1; 
    }

  if(arg == "page 4") 
    { write
	("\n\t\t"+BOLD+"How Do I Heal?\n\n"+NORM+
	 "  When you fight you will get injured.  There are many ways to\n"+
	 "help you heal.  You can just wait and you will heal slowly, but\n"+
	 "many monsters heal too.  There are substances you can use to heal\n"+
	 "more quickly.\n\n"+
	 "  Bars and taverns serve alcoholic drinks that will speed healing,\n"+
	 "but there are other less desirable effects.  Shops exist where you\n"+
	 "may buy healing substances that you can take with you.  Prices and\n"+
	 "amounts healed vary.  Below are a few nearby places where you can\n"+
	 "purchase portable heals.  All directions begin at the 'green' (south\n"+
	 "of the church).\n\n"+
	 "\t\tenter hall, w\n"+
	 "\t\tgreen: 5e,3n,w,step rift,in,4s\n"+
	 "\t\t5e,n,e,enter,lockers,w\n"+
	 "\t\t5e,6n,w\n"+
	 "\t\t9e,s,w\n\n");
    return 1; }

  if(arg == "page 5") 
    { write
	("\n\t\t"+BOLD+"Shops and Other Places\n\n"+NORM+
	 "  There are many thousands of places in Nirvana to explore.\n"+
	 "You might want to learn where a few of them are.  One of the\n"+
	 "most important is the Adventurer's Guild where you go to advance\n"+
	 "your level and raise your statistics (attributes).  Here is a map:\n"+
	 "\n"+BOLD+
	 "             ~*~ Nirvana Town Center ~*~\n"+NORM+
	 "\n"+BLK+BOLD+                                      
	 "    N\n"+NORM+
	 "    |                                        Day   Weapon-\n"+
	 " "+BLK+BOLD+" W"+NORM+"-o-"+BLK+BOLD+"E"+NORM+"                                     Care +  smith\n"+
	 "    |                                            | \n"+BLK+BOLD+
	 "    S"+NORM+"                      Chapel          Magic + Hotel\n"+
	 "                             |                   | \n"+BOLD+
	 "  ENTRY-->"+NORM+" Church       Yard + Pub  Shop   Armor + Bank\n"+
	 "             |               |       |           |\n"+
	 "  Bridge -"+HIG+" Green"+NORM+" - Track - Road -  Road   -    Clock - "+RED+"Pizza\n"+NORM+
	 "                 |    |              |         Tower   "+RED+" Hut\n"+NORM+
	 "               Alley            Adventurers\n"+
	 "                      |            Guild\n"+
	 "                    Post\n"+
	 "                   Office\n\n"+
	 "  The"+HIB+" Hall of the Apprentices"+NORM+" is in the Village Green.\n\n");
    return 1; 
    }

  if(arg == "page 6") 
    { write
	("\n\t\t\t"+BOLD+"About Guilds\n\n"+NORM+
	 "  A guild is a group of players who have similar skills, abilities\n"+
	 "and sometimes goals.  You may want to join a guild wnen you have\n"+
	 "been here a little longer.\n\n"+
	 "  Guilds have personalities much like players do.  Before joining you\n"+
	 "can find out about different guilds by talking to the members.  Ask\n"+
	 "about the purpose, strengths, and weaknesses of the guild.  When you\n"+
	 "are sure you are ready choose one that fits the personality of the\n"+
	 "character you are playing.  There are often penalties for leaving\n"+
	 "a guild so try to make a wise choice.\n\n"+
	 "  No guild is 'perfect'.  Each has strengths and weaknesses.  It is\n"+
	 "up to you to do research and see which one best fits you and your\n"+
	 "style of play.\n\n");

    return 1; 
    }

  if(arg == "page 7") 
    { write
	("\n\t\t\t"+BOLD+"Guild Listing\n\n"+NORM+
	 "The guilds of Nirvana are:\n\n"+
	 "Cyberninjas:  Good fighters, guild bionics and weapon, guild mechs\n"+
    " that replace guild pets, honor system, guild heirarchy, PK, weapon/\n"+
   " armor restrictions.\n\n"+
	 "Dervish: Ascetic fighting guild, limited healing spells,\n"+
	 " armor and stat restrictions, dual wielding at high levels.\n\n"+
	 "Fallen: Very good fighters at high levels, spellcasting, strong\n"+
	 " theme, slow to advance, solitary, armor and weapon restrictions.\n\n"+
	 "Healers: Focus on healing, not fighting, experience gained through\n"+
	 " healing, parties.  Rarely fight together, no guild heirarchy.\n\n"+
	 "Knights Templar: Excellent fighters at high level, limited spells,\n"+
	 " alignment restriction, protectors of good.\n\n"+
	 "Polymorphs: Excellent fighters at high level, interesting morphs,\n"+
	 " NO PKing, 'strange' area of existence, few spells.\n\n"+
	 "Power Rangers: Good fighters at high level, team concept, guild\n"+
	 " weapon, spells,  and abilities, alignment, weapon, and armor\n"+
	 " restrictions.\n\n"+
	 "Vampires: Very good  fighters, interesting spells, pets, unique\n"+
   " guild hall, close family atmosphere, slow to get in.\n\n"+
"Servants of Shardak: Very Evil.  Strong influence on player killing.\n"+
" Unique range of spells based on fire and the infernal, pet dragons.\n\n"+
"Necromancers: Very good spellcasters.  Abilities based on realm\n"+
" of the dead.  Heavy use of corpses, wide range of spells.\n\n"+
"Bards: Cheerful, friendly, and helpful guild.  Wide range\n"+
" of defensive and offensive spells.  Singers of song.\n\n");
    return 1; 
    }
                                    
  if(arg == "page 8") 
    { write
	("\n\t\t"+BOLD+"What Do I Do Now?\n\n"+NORM+  
	 "  Of course you want to get going as fast as possible but take\n"+
	 "some time to read the help files and to familiarize yourself\n"+
	 "with the basic set-up and rules of the game.  Other players\n"+
	 "will help you, but you have to do your share.  You can ask\n"+
	 "questions on the newbie channel by saying 'newbie <stuff>'.\n"+
	 "  You can purchase equipment from a shop, weaponsmith or armorer\n"+
	 "or you can get it by killing a monster and taking it from the\n"+
	 "corpse.  You can get coins by killing monsters or players,\n"+
	 "looting their corpses and/or selling things you get from them.\n"+
	 "  Look at and read everything.  Wizards usually give you plenty\n"+
	 "of hints about how to use things.  Rooms often have items that\n"+
	 "you can look at or search.  You never know what interesting\n"+
	 "things you might discover!\n\n"+
	 "  Player killing (pk) is allowed in certain areas.  It is up to\n"+
	 "you to learn where these areas are and avoid them if you are not\n"+
	 "interested in engaging in PK.  Warning: not all players who offer\n"+
	 "help intend to help you so be careful.\n"+
	 "  There are many channels where you may talk to other players.\n"+
	 "In addition to 'newbie', the 'gossip' channel is the general channel.\n"+
	 "It is 'G' rated.  Use channels wisely - 'spamming' or inappropriate\n"+
	 "remarks can earn you a trip to the famous Nirvana jail.\n"+
	 "  There are mini guilds that you can join when you are 6 hours old.\n"+
	 "Each mini guild costs 6000 coins to join and gives you special\n"+
	 "abilities.  Ask someone for a scroll to learn more.\n"+
	 "  Many players have been here for a very long time.  They consider\n"+
	 "this a kind of home.  We hope you enjoy Nirvana and stay with us.\n\n");
    return 1; 
    }
}

get() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }
drop_book(str) {
  if (str == "all") {
    destruct(this_object());
    return 1;
  }
  if (!str || !id(str))
    return 0;
  write("As the Newbie book falls, there is a FLASH and it disappears!\n");
  say(capitalize(this_player()->query_real_name())+" drops a newbie book!\n");
  destruct(this_object());
  return 1;
}

