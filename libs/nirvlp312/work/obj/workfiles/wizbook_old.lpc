/* a Wizard Book for new wizards - Eurale (29 Sep 02)  */

inherit "obj/treasure";
#include "/players/eurale/defs2.h"

id(str) { return (::id(str) || (str=="eurale's funky wizbook")); }
drop() { return 1; }
reset(arg) {
  if(arg) return;

set_id("book");
set_alias("handbook");
set_short(HIR+"Wizard Handbook"+NORM);
set_long(
  "  This is the standard "+HIR+"Wizard Handbook."+NORM+
  "  It is full of important information\n"+
  "that all wizards should know.  You can "+HIR+"'read index'"+NORM+
  " to find out the topics\n"+
  "covered in this handbook and then "+HIR+"'read <topic>'"+NORM+
  " to get specifics about that\n"+
  "topic.  You should familiarize yourself completely with this handbook before\n"+
  "you begin coding anything.\n");

set_weight(1);
set_value(1);
set_save_flag();
}

init() {
  ::init();
  add_action("Read","read");
}

Read(str) {
if(!str) { write("The book whispers, 'Read what?'\n"); return 1; }
if(TPL < 21) { write("The pages are too blurry to read.\n"); return 1; }
if(str == "index") { write(
"\nThe "+HIR+"Wizard Handbook"+NORM+" index:\n\n"+
  "welcome  rules1  creativity1  interaction1  area1  terms1\n"+
  "         rules2  creativity2  interaction2  area2\n"+
  "         rules3               interaction3  area3\n"+
  "                                            area4\n\n"+
  "The information in this handbook has been written by many\n"+
  "wizards over the years, most recently by Vertebraker.  This\n"+
  "compilation was done by Eurale on 9/29/02.\n\n");
  return 1; }

if(str == "welcome") { write(
  "  The immortal staff of Nirvana wants to congratulate you on your\n"+
  "accomplishment and welcome you aboard.  You should know right off that\n"+
  "your efforts will not always be welcomed by all the players but that\n"+
  "should not dampen your enthusiasm to make Nirvana a better and more\n"+
  "exciting place.  In most cases any of us will be more than willing to\n"+
  "assist you as you get started or guide you along when you have specific\n"+
  "questions about how to do or deal with something.  There will be lots for\n"+
  "you to learn and it takes time to become comfortable dealing with the many\n"+
  "issues that may confront you.  We were all where you are once and we try\n"+
  "to be sympathetic and understanding as you progress through your learning\n"+
  "process.  Most of all, we want you to enjoy your wizard experience and hope\n"+
  "that you leave a little piece of yourself somewhere in the land of Nirvana\n"+
  "for the future players to explore and enjoy.  Don't be afraid to ask about\n"+
  "anything as it's the way most of us learned.  You can see a list of wizard\n"+
  "commands by typing "+HIR+"'help wizard'"+NORM+".  "+
  "Again, we want to congratulate you and\n"+
  "say 'welcome aboard'.     -Boltar and his immortal staff\n\n");
  return 1; }

if(str == "terms1") { write(
  "wiztool - this object has many built-in commands to help wizards when dealing\n"+
  "           with players.  It facilitates changes in the player stats and/or\n"+
  "           string variables.  Exercise caution when making player changes.\n\n"+
  "test character - In order to test the various objects that one codes and to\n"+
  "                 avoid using the player base, wizzes sometimes create another\n"+
  "                 character that they use specifically to test these objects.\n"+
  "                 Be sure all test characters are clearly labeled as such.\n\n");
  return 1; }

if(str == "interaction1") { write(
  "  *The wizard structure here is by levels.  If a wizard of higher level asks\n"+
  "you to do or not to do something, respect their level and comply with their\n"+
  "requests.  If you feel that the request was unreasonable, mail your sponsor or\n"+
  "the appropriate senior wizard about it.  Wizards here have attained their\n"+
  "levels through their contributions and/or expertise.  Lower level wizards are\n"+
  "expected to respect their requests unless they are superceded by a higher level\n"+
  "wizard.\n\n"+
  "  *Public bickering among wizards will not be tolerated.  If you have an issue\n"+
  "with a wizard that is higher level than you, mail your sponsor or their sponsor.\n"+
  "You might even mail Boltar but the 'chain of command' is here for a reason so\n"+
  "continuing the fight because you didn't get your way may do you more harm than\n"+
  "good.  Almost anything can be worked out with a little understanding.  We are\n"+
  "all here because we want to make Nirvana a better place so keep that in mind.\n\n");
  return 1; }

if(str == "interaction2") { write(
  "  *Although you came from the player ranks and probably have friends there,\n"+
  "it is important that you keep wizard/player interaction to a minimum.  Do not\n"+
  "give out information that the players cannot find out themselves by playing\n"+
  "the game.  As a wizard you have access to much more information than the\n"+
  "player base and we do not expect that information to be shared.  If you're\n"+
  "not sure what should be shared, tell the player to ask a senior or higher level\n"+
  "wizard about it.  Simple rule:  When in doubt, pass the buck.\n\n"+

  "  *Do not share wizard information with players either.  You may know who is\n"+
  "about to be promoted or demoted or which wizards are arguing about something\n"+
  "but that is not for players to know.  Wizard business should remain wizard\n"+
  "business without exception.  Sharing of this kind of information will almost\n"+
  "surely mean a demotion back to player status permanently.\n\n"+

  "  *Every wizard's code is their property and should be treated as such.  Do\n"+
  "not copy/borrow anyone's code without their permission.  Most wizards put a\n"+
  "great deal of time into their work and will almost always share their efforts\n"+
  "with you if you but ask.  So, respect their efforts by asking first and if they\n"+
  "tell you no, maybe you can get something similar from someone else.\n\n");
  return 1; }

if(str == "interaction3") { write(
  "  *If a player is misbehaving, annoying other players purposely, spamming any\n"+
  "of the channels, cursing over public channels (except risque) or in any way\n"+
  "disrupting the game play of others and they will not stop after you've\n"+
  "asked them to, do NOT dest them but move them to /room/prison.  They should\n"+
  "remain there until the punishment has been sufficient enough to deter them\n"+
  "from future repetition of the offensive behavior.  The hardest part about \n"+
  "dealing with players is that sometimes we don't like what they're doing but\n"+
  "it is within the game rules for them to do it.  Any time you deal with players,\n"+
  "you should log your actions and reason so that later they cannot come back and\n"+
  "claim something that isn't accurate or didn't happen.  Keeping a log of all\n"+
  "your actions is also a great way to protect yourself.\n\n"+

  "  *We want you to be excited about the things you code.  Nothing you code\n"+
  "should be shown to or shared with the player base until it has been approved,\n"+
  "however.  Trying to explain why your 'cool item' isn't in the game because it\n"+
  "was illegal is hard after you've already shown it to all your friends. So just\n"+
  "hold your horses until it's approved.  They'll all love it just as much a few\n"+
  "days later.\n\n");
  return 1; }

if(str == "rules1") { write(
  "  *Wizards are supposed to be an example to players.  The higher the\n"+
  "level you attain, the better the example you set should be.  Remember,\n"+
  "you have chosen to ascend to the wizard ranks.  Most importantly, use\n"+
  "your common sense and use decency when dealing with both players and\n"+
  "your fellow wizards.\n\n"+

  "  *All wizards below level 40 must use '/obj/wiz_tool' as their\n"+
  "wizard tool.  After level 40 you may code your own version but it\n"+
  "may not include 'snooping' capability.  NO wiz tool is to autoload.\n\n"+

  "  *All wizards are expected to adhere to the behavior standards in\n"+
  "'help wiz_behavior'.  These guidelines were established to remind\n"+
  "wizards that our main goal on Nirvana is to create new things and\n"+
  "help out players when they truly need it.  Being an annoyance to\n"+
  "other wizards or players negates the reason to have you here as a\n"+
  "wizard.  Your job is to contribute positively to the game and to\n"+
  "foster trust between the player/wizard ranks.\n\n");
  return 1; }

if(str == "rules2") { write(
  "  *If there is no command to do what you want to do in either 'help\n"+
  "wiz_levels' or '/obj/wiz_tool' then do not attempt to do that action.\n"+
  "As you gain levels you will be given more freedom to do other things.\n"+
  "Always try to consider your fellow wizards and players collectively when\n"+
  "trying to figure out what to do.  In the end, you should always try to do\n"+
  "what is best for everyone involved and most of all, be fair.\n\n"+

  "  *Wizard test characters should be clearly titled so that noone can mistake\n"+
  "them for part of the player base.  The excuse that 'I thought everyone knew'\n"+
  "will not be acceptable.  No test character should be created that will affect\n"+
  "the top players list nor should any test character be given to any other player\n"+
  "to play or experiment with.  Use your head.\n\n");
return 1; }

if(str == "rules3") { write(
  "  *There is a wizard board located south of the advance room.  Items of interest\n"+
  "are posted there for discussion or general knowledge so it is expected that all\n"+
  "wizards read these messages on a regular basis.\n\n"+

  "  *As a new wizard you should try to stay visible the majority of the time.\n"+
  "We know players can be pests but being visible does a couple of things.  First,\n"+
  "it lets the players get used to seeing you in a wizard position and become\n"+
  "comfortable with contacting you.  Second, it allows the senior wizards a chance\n"+
  "to observe your interaction with players.  We've all been involved with players\n"+
  "that test our resolve and learning to deal with them fairly is something that\n"+
  "sometimes requires help.  If you really need to be invisible to work, please do\n"+
  "not hesitiate to do so.\n\n");
  return 1; }

if(str == "creativity1") { write(
  "  *Creativity is a very important asset.  If you would like to try something\n"+
  "that you think would be interesting and/or beneficial to Nirvana, but you\n"+
  "are concerned about whether or not it is legal, be sure to have it checked\n"+
  "out by a senior wizard.  Usually a compromise can be worked out so that\n"+
  "Nirvana and its players can benefit from your efforts.  Try to keep in mind\n"+
  "that game balance is essential and that new and creative ideas do not have to\n"+
  "always be something that pushes the envelope of protection or power.\n\n"+

  "  *Every wizard is responsible for his or her own code.  If something illegal\n"+
  "is found, it will not be blamed on the approving wizard but on the coder who\n"+
  "coded it.  You will be expected to follow the '/doc/build/RULES' for all items\n"+
  "that you code.  Again, if you're unsure about the legality of an item you've\n"+
  "coded, get approval from a senior wizard.\n\n");
  return 1; }

if(str == "creativity2") { write(
  "  *For the most part you will be given the benefit of the doubt.  If your\n"+
  "item/guild/monster/whatever is approved, it is assumed to be legal.  However,\n"+
  "if it is discovered that it is not within the confines of the rules you can\n"+
  "expect serious repercussions.  All reports of illegal objects are investigated\n"+
  "so it is vitally important that you police yourself and your code.\n\n"+

  "  *Any wizard, including senior wizards, that code an item/monster/room that\n"+
  "falls outside the /doc/build/RULES guidelines must have it approved by another\n"+
  "senior wizard and/or Boltar.  Our biggest problems have arisen because we let\n"+
  "one person code something 'outside' the rules and that quickly becomes the\n"+
  "'norm' for all the code that follows.  Being creative doesn't mean making the\n"+
  "the game easier for everyone, it's convincing the players that what you've\n"+
  "coded is unique, useful and something worth getting.\n\n");
return 1; }

if(str == "area1") { write(
  "  Everyone is usually excited about coding their first area and getting it\n"+
  "into play.  This sometimes leads to problems such as bad or not thought out\n"+
  "ideas, duplication of area theme, poor looking room descriptions, etc.  In\n"+
  "order to make sure there is some sort of uniformity in code here, your first\n"+
  "area should meet the following requirement:\n\n"+

  "  15 - 20 rooms.  Each room should have its own room description.  Nothing\n"+
  "is more boring to players than to read the same description over and over.\n"+
  "Proper grammar and punctuation should be used and that includes 1-2 spaces \n"+
  "after the end of sentence punctuation and two spaces indentation to start a\n"+
  "room description or new paragraph.  The room description should be from 3-6\n"+
  "lines long and each line should be approximately 70 characters in length.\n"+
  "Short or mismatched line length in room descriptions will not be approved.\n"+
  "You might also include a search function in every room so that if you want\n"+
  "them to search to find something, it is not obvious because you only have\n"+
  "a search function in those special rooms.  The same holds true with smell\n"+
  "and listen.  Pay attention to your room description and make appropriate\n"+
  "things happen.\n\n");
  return 1; }

if(str == "area2") { write(
  "  7 - 10 monsters.  Your first area should be a low to mid level area so keep\n"+
  "your monsters straight forward.  You should get used to coding approximately\n"+
  "one monster for every two rooms.  We are trying to avoid 'slaughter houses'\n"+
  "where players can stay in one location and kill continuously.  Each monster\n"+
  "should be unique and if they wouldn't normally be carrying money, then they\n"+
  "shouldn't have any.  Code some treasure instead that players can sell for the\n"+
  "coins.  Put some thought into this process and you'll find players will visit\n"+
  "more often just because it's entertaining.  Pay particular attention to the\n"+
  "monster's alignment as doing what comes naturally doesn't necessarily make them\n"+
  "evil or good.\n\n"+

  "  It is not uncommon for new wizards to code way too many monsters that don't\n"+
  "make sense for the area.  For example, you wouldn't find dinosaurs in outer\n"+
  "space carrying money so think about it.  Once you've made an appropriately\n"+
  "named directory for the area, make sub directories called NPC and OBJ in it\n"+
  "to keep track of all the monsters and other objects that go with the area.\n"+
  "That will make it much easier for the wizards who have to approve your stuff\n"+
  "and speed up the approval process to boot.  You might also include a README\n"+
  "file with a general description of the area and anything special one might\n"+
  "expect to find.\n\n");
  return 1; }

if(str == "area3") { write(
  "  The biggest problem with new areas is the descriptions.  When you 'look' at\n"+
  "something, you should get a description of what you see.  Too often you get\n"+
  "all kinds of information EXCEPT what the item looks like.  When someone walks\n"+
  "into a room, they want to see what the room looks like, what items are in the\n"+
  "the room, what hangs on the walls.  They shouldn't see a description of any\n"+
  "items in the room.  The same should hold true for any monsters or items.  By\n"+
  "looking at an item they shouldn't be told how they feel or where it might be\n"+
  "headed.  It is up to you as the coder to MAKE the players see exactly the same\n"+
  "thing as you envision.  Pretend you are the eyes of the player.  Look at every\n"+
  "noun in the room and make sure they have a description.  If you mention another\n"+
  "different noun in the item description, you should have a description for that\n"+
  "as well.  It's very frustrating for both the coder and the checker when things\n"+
  "are not done properly.  Here's a suggestion.  Only do 3 or 4 complete rooms and\n"+
  "then ask for someone to look at them.  That way, if you're not on the right\n"+
  "track, you won't have so much to fix.\n\n"+

  "  Don't try to get too fancy with your first area.  You'll have plenty of time\n"+
  "to dazzle everyone later.  We're more interested in seeing a sample of both the\n"+
  "quality and creativity you are going to bring to Nirvana.  You are surely going\n"+
  "to want to look at examples and your sponsor should be able to provide those\n"+
  "for you or you can look at '/open/examples.'  Consider this first area a test.\n\n");
  return 1; }

if(str == "area4") { write(
  "  For those that are experienced coders and want to work off-line, you can\n"+
  "use port 3000 to FTP your work to and from Nirvana.  You will need some sort\n"+
  "of FTP tool but they can be downloaded from many places so just look for one\n"+
  "that does what you want it to do.\n\n"+

  "  Much of the information you will need to complete your first area can be\n"+
  "found in /doc/build/RULES.  Get familiar with this information before you\n"+
  "start rather than have to go back and redo lots of your work when it could\n"+
  "have been avoided.  Your sponsor should be a valuable source of information\n"+
  "as well as many of the other immortal staff.  We all made mistakes so you're\n"+
  "bound to as well.  The secret is how you handle your failures.  We're glad you\n"+
  "have elected to join us and look forward to your success so good luck.\n\n");
  return 1; }

return 1; }
