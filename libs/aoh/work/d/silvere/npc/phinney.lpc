/* Phinney - The old Oglon - 12/12/1997 - Mistral and Joan  */
/* Phinney rests in the palace fig garden .*/
/* Phinney is an old tired adventurer.  */
/* Updated and added to Silver [05-Sept-2001]
 
#include <moving.h>                  
#include <npc.h>                     /* Phinney */
#include <properties.h>              /* Phinney */
 
 
#define GARDEN  "/d/silvere/rooms/center/garden2"   /* Thanks to Sonic */
 
inherit "/std/npc";
 
int check_garden()
{
   if(environment(this_object()) == find_object(GARDEN))
      return 1;  // Phinney is in the garden
   return 0; 
}
 
string garden_chats()
{   
  if(check_garden())
    return random_select( ({
      "Phinney stretches out on the soft grass.\n",
      "Nodding his head, Phinney doses for a brief moment then wakes.\n", 
      "Lazily, Phinney reaches out a great paw and swats and at insect.\n",
      "Phinney stretches and yawns.\n",
      "Phinney shakes his great head and scratches his ear.\n"
    }) );
  return "0";  
}
 
string my_questions(string s); 
 
void create()
{ 
    
  ::create();
 
     
  SetName("Phinney");
  
  SetShort("Phinney, The Old Oglon, lazing on the soft cool grass.");
 
  SetLong("Phinney is a large ancient oglon. Though he is old "
  "and arthritic, his frame is still muscular. His light movements "
  "speak of the great speed he still possesses. His eyes gleam with "
  "great intelligence and his ancient face speaks of the wisdom "
  "that only the very old possess. He is battle scarred from head to "
  "toe and his once jet black fur is sprinkled with grey. He spends "
  "most of his time relaxing in the palace gardens, now. Maybe, if "
  "you ask him nicely, Phinney will tell you stories about his "
  "adventures.\n");  
  
  SetGender(GENDER_MALE);
  SetLevel(8);
  SetRace("oglon");
  
  SetShrugMsg(
    "Phinney stares at you with bright understanding eyes and shakes "
    "his head and says: \n"
    "Slow down. I don't understand what you are asking me.\n");
 
  AddId("storyteller"); 
 
  Set(P_MSGIN,   ({ "hobbles in", "is here" }) );
  Set(P_MSGOUT,  ({ "hobbles out", "goes away" }) );
 
  Set(P_MMSGIN,  ({ "flashes in", "is here" }) );
  Set(P_MMSGOUT, ({ "flashes away", "goes away" }) );
  
  Set(P_CHAT_CHANCE, 0);
  Set(P_CHATS,  
      ({
         #'garden_chats
      }) );
 
  Set(P_GO_CHANCE, 0);
  Set(P_DEX,1000);
  Set(P_WIMPY, Query(P_MAX_HP)/2);
 
// Help Phinney remember stories. Add good logical questions and hints 
// to his story collection.
// Just please document them. 
// This is all he knows for now. Please give Phinney a tale to tell. //
 
 
  AddQuestion( ({"adventure","adventures","quests", "quest", 
  "stories","story"}),
              "Phinney answers softly: I can tell you about these tales: \n "
              "Guardians, Harbourmaster, King, Mistral, "
              "Palace, Silvere, Sonic, Sykorath, Wessex and Xanadu.\n" 
              "Just ask me about one of them and I will give you a bit "
              "of information.");
 
 
  AddQuestion("guardians",({
           "Phinney softly whispers: \n" 
           "At cardinal points along the palace walls "
           "are the statues of the great Guardians. Visit the statues of "
           "Kyrie, Tali, Sarykan and Rilana. If they think you are worthy, "
           "they just might give you something. ",
           "Phinney whispers something."}));
  
  AddQuestion("harbourmaster", 
           "Phinney nods his great head, smiles and says: \n"
           "The old harbourmaster, Gregore d'Angelina, he is  "
           "my good friend. He is an old sea captain and adventurer. "
           "We shared many dangerous adventures. Retired from the "
           "sea now, he manages the harbour. Don't be shy about asking "
           "him for help; he has forgotten more about this "
           "world than you will ever know. " ,0);
  
  AddQuestion("mistral", 
           "Phinney whispers: \n"
           "Mistral is a great warrior. He fought many "
           "dangerous battles.  Maybe you "
           "can find him at his house. Mistral's house is "
           "west of here. You should visit his house. All are "
           "always welcome there.\n", 0);         
  
  AddQuestion("silvere", ({ 
          "Phinney answers with pride: \n" 
          "Silvere! It is my world! We all fled here when the "
          "evil dragon froze our old world! It is a magical city, "
          "ripe with adventure and intrigue. It is a good place "
          "for a young adventurer to begin his journeys.",
          "Phinney whispers something.\n"}));
  
  AddQuestion("sonic",({
           "Phinney smiles and replies: \n"
           "Ah! Great Wizard that Sonic. He is the Lord of all "
           "Silvere. Remember it is not wise to anger Hedgehogs. "
           "Treat all hedgehogs with great respect. The hedgehog "
           "you meet could be Sonic.\n ","Phinney whispers something.\n"}));
 
  AddQuestion("sykorath",({
           "Phinney whispers hoarsely: \n" 
           "Sykorath is a city of great evil. Dirty gargoles "
           "and creatures of the night still live and govern there. "
           "Oh, it was once much worse. Good king BLAH BLAH, waged a "
           "great battle there a long time ago. I was at his side. "
           "Though we won the battle and the war, we never succeeded "
           "in completely vanquishing the evil. It is still there. "
           "If you travel to Sykorath, go carefully. ",
           "Phinney whispers something.\n"}));
  
 
 
  AddQuestion("wessex",({
           "Phinney proudly answers: \n"
           "Wessex is our GOD. He is a cuddly cute bear. Remember, "
           "though, bears can be nasty. It is better to do good "
           "so Wessex doesn't eat you. Wessex looks for mean "
           "adventurers and wizards. When he finds them....well, "
           "just hope he cooks them before he eats them. Wessex is ever "
           "vigilant is his watch over Beyond. \n", "Phinney "
           "whispers something.\n"}));
  
 
  AddQuestion("xanadu", 
           "Phinney shakes his head and whispers: \n" 
           "That is a secret. You should ask Mistral about it\n", 1);
 
}
