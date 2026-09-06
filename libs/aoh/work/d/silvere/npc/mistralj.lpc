/*
   A mistral jr. - the baby of Mistral and Joan
   introduced by Joan
   coded by Magictcs
*/

#include <properties.h>
#include <rooms.h>
#include <moving.h>

inherit "/std/npc";

int shrug;
string old_question;
int bandaging;
int silence;

string help_msg() {
    if (({string})this_player()->QueryRealName()!="mistral" &&
          ({string})this_player()->QueryRealName()!="joan") return "";
  return
  "tell jr return  --> returns into the room where you are.\n"
  "tell jr silence --> be silent\n"
  "tell jr verbose --> be verbose\n"
  "tell jr :emote  --> let junior doing something\n"
  "tell jr xxxx    --> cry for Mama/Dada\n";
}

// chat strings:
string *chats = ({
  "Dada\n",
  "Mama\n",
  "Mistral Jr. tries to bandage you but fails.\n",
  "Mistral Jr. does a very bad job bandaging you.\n",
  "Mistral Jr. cries ah ah ah. (A bad smell reaches your nose....)\n",
  "Mistral Jr. takes his fingers out of mouth then screams like only a\n"
    "warrior can. You are stunned.\n",
  "Mistral Jr. drools and slobbers all over his tiny Maul of the Titans.\n",
  "Mistral Jr. smashes his toy titan with his tiny maul of the titans making\n"
    "a bonecrushing sound and massacres his toy titan to tiny bits.\n",
  "Mistral Jr. looks at a tiny maul of the titans and nods knowingly.\n",
  "Mistral Jr. wields the hammer like a real master of forging. In a\n"
    "few minutes a tiny maul of the titans glows in a distant light \n"
    "and looks better than ever before.\n"
    "Mistral Jr. does an excellent job repairing a tiny maul of the titans.\n",
  });

// bandage strings: (need a little bit more overworking)
string *bandage = ({
    "",
    "Mistral Jr. unwears Mistral Jr.'s winged helmet.\n",
    "Mistral Jr. does an excellent job bandaging Mistral Jr.\n",
    "Mistral Jr. wears a white bandage.\n",
    "The bandage warms a bit.\n",
    "The bandage warms a bit.\n",
    "The bandage warms a bit.\n",
    "The bandage becomes lose.\n"
    });

// return a string for the chat function
// depends on some variables
string getchats() {
  string ret;
  if (silence==1) return "";
  if (bandaging>0) {
    ret=bandage[bandaging++];
    if (bandaging>=sizeof(bandage)) bandaging=0;
    return ret;
  }
  if (random(20)>15) {
    bandaging=1;
  }
  ret=chats[random(sizeof(chats))];
  return ret;
}

// new shrug function :))
// maybe logg the questions here?!
string do_shrug(string str) {
  if (old_question==str)
    return "Hey I'm young but not stupid - you asked me that already!\n";
  old_question=str;
  // log questions:
  log_file("",({string})this_player()->QueryRealName()+
    " asks about "+str+"\n");
  switch (shrug) {
    case 0:
      shrug++;
      return "Mmmh I doesn't heared something about it.\n";
    case 1:
      shrug++;
      return "I doesn't know anything about it.\n";
    case 2:
      shrug++;
      return
      "Well in my short life I heared many many things - but this one?\n"
      "I don't know nothing about it!\n";
    case 3:
      shrug++;
      return "Mmmh - maybe you should try to ask someone else?\n";
    default:
      shrug=0;
      return "The tiny barbarian cries.\n";
  }
  shrug=0;
  return "The tiny barbarian cries.\n";
}

// standard create function (a little bit longer than normal)
// hihi
void create() {
  ::create();
  seteuid(getuid());
  shrug=0;
  old_question="";
  bandaging=0;
  silence=0;
  SetName("jr");
  SetShort("Mistral jr. - Mistral and Joan's first child");
  SetLong(
    "Mistral Jr. is a human toddler. He is only two years old.\n"
    "When he was born he turned to Dr. MagicTcs and screamed as only\n"
    "a warrior can.\n");
  SetLevel(2);
  SetGender(GENDER_MALE);
  AddId(({"jr.","jr","child","mistral jr","mistral jr.","human"}));
  SetAds(({"first"}));
  SetRace("toddler");
  SetAlign(100);
  SetAC(2);
  SetNoGet(0);             // allow take and get
  SetNoSell("You want to sell you beloved Mistral jr.?\n");
  SetGoChance(30);
  SetWeight(2045);
  SetMsgIn("crawls in");
  SetMsgOut(({"crawls out"}));
  SetMMsgIn("crawls in");
  SetMMsgOut(({"crawls"}));

  // armours:
  AddItem("/std/armour",REFRESH_REMOVE,#'wearme /*'*/,({
    ([ P_STANDARD: ({AT_HELMET,0,PSIZE_SMALL}) ]),
    ([ P_SHORT: "a winged helmet",
       P_LONG:
       "A winged helmet for baby barbarians.\n",
       P_IDS: ({"helmet"}),
       P_ADS: ({"winged","small"}),
       P_WEIGHT: 1200,
       P_VALUE: 800 ]) }) );
  AddItem("/std/armour",REFRESH_REMOVE,#'wearme /*'*/,({
    ([ P_STANDARD: ({AT_TROUSERS,0,PSIZE_SMALL}) ]),
    ([ P_SHORT: "a damper diaper",
       P_LONG:
       "You don't want to change the damper diaper.\n",
       P_IDS: ({"diaper"}),
       P_ADS: ({"damper"}),
       P_WEIGHT: 3500,
       P_VALUE: 38 ]) }) );
  AddItem("/std/armour",REFRESH_REMOVE,#'wearme /*'*/,({
    ([ P_STANDARD: ({AT_MAIL,0,PSIZE_SMALL}) ]),
    ([ P_SHORT: "a tiny warrior sleepers",
       P_LONG:
       "A tiny warrior sleepers made by Dr. Magictcs industrials.\n"
       "Warm and comfy - all what baby needs.\n",
       P_IDS: ({"sleepers"}),
       P_ADS: ({"tiny","warrior"}),
       P_WEIGHT: 3500,
       P_VALUE: 389 ]) }) );

  // weapons:
  AddItem("/std/weapon",REFRESH_REMOVE,#'wieldme /*'*/,({
    ([ P_STANDARD: ({WT_CLUB,1,PSIZE_GENERIC}) ]),
    ([ P_SHORT: "a tiny Maul of the Titans",
       P_LONG:
       "This is a tiny Maul of the Titans, made for baby titans.\n",
       P_IDS: ({"maul"}),
       P_ADS: ({"tiny"}),
       P_WEIGHT: 100,
       P_VALUE: 30,
       P_RESET_QUALITY: 55 ]) }) );
  AddItem("/std/weapon",REFRESH_REMOVE,#'wieldme /*'*/,({
    ([ P_STANDARD: ({WT_CLUB,1,PSIZE_GENERIC}) ]),
    ([ P_SHORT: "a dangerous looking cookie",
       P_LONG:
       "A dangerous looking cookie - one of the best weapon for babies.\n",
       P_IDS: ({"cookie"}),
       P_ADS: ({"dangerous","looking"}),
       P_WEIGHT: 100,
       P_VALUE: 40 ]) }) );

  // equipment:
  AddItem("/std/thing",REFRESH_REMOVE,({
    ([ P_SHORT: "a tiny toy titan",
       P_LONG:
       "A tiny toy for barbarians.\n",
       P_IDS: ({"toy","titan"}),
       P_ADS: ({"tiny","toy"}),
       P_WEIGHT: 100,
       P_VALUE: 40 ]) }) );
  AddItem("/std/food",REFRESH_REMOVE,({
    ([ P_SHORT: "a bottle of apple juice",
       P_LONG:
       "A bottle of Dr. MagicTcs' vitamin rich Jr. Apple Juice.\n",
       P_FOOD_HEAL: 1,
       P_FOOD_KIND: "drink",
       P_FOOD_ALC: 0,
       P_FOOD_MSGS: ({"Ahhhh... that tastes cool.\n",
                        "@@Pl_Name@@ drinks a apple juice.\n"}),
       P_IDS: ({"juice","bottle"}),
       P_ADS: ({"apple"}),
       P_WEIGHT: 10,
       P_VALUE: 40 ]) }) );

  InitChats(10,#'getchats /*'*/);
  SetWimpy(QueryMaxHP()-5);     // run fast away
  SetHelpMsg(#'help_msg /*'*/);

  // Questions
  AddQuestion(({"name"}),"The child cries Mistral jr.\n");
  SetShrugMsg(#'do_shrug /*'*/);
}

// for the callout
void write_msg(string str) {
  tell_room(environment(),str);
}

// for the catch of tell (emotes??)
void catch_tell(string str) {
  string msg,name;
  object ob;
  if (!str) return;
//  dtell("magictcs","Jr: "+str);
  if (sscanf(str,"%s tells you: %s",name,msg)==2) {
    if (({string})this_player()->QueryRealName()!="mistral" &&
          ({string})this_player()->QueryRealName()!="joan") return;
    if (strstr(msg,"home")!=-1 || msg=="return\n") {
        this_object()->move(environment(this_player()),M_TELEPORT);
      return;
    }
    if (msg[0]==':') {         // emote
      msg[0]=' ';
      tell_room(environment(this_object()),"Mistral Jr."+msg);
      return;
    }
    if (msg=="silence\n") {
      silence=1;
      return;
    }
    if (msg=="verbose\n") {
      silence=0;
      return;
    }
    call_out("write_msg",1,"Mama?? Dada???\n");
    return;
  }
}

// forbid leaving the area of the house
varargs int move(mixed dest, int method, mixed extra)
{
    int result;
    string d1,d2;

    if (method != M_GO) return ::move(dest, method, extra);
    if (!dest) return ME_NO_MOVE;
    if (objectp(dest)) dest = file_name(dest);
    if ( (sscanf(dest,"%swoodland/common/beach/joan/%s",d1,d2)==2) ) {
        result=::move(dest,method,extra);
        return(result); }
    return ME_NO_MOVE;
}


// resets some variables
varargs void reset() {
  if (!clonep()) return;        // prevent lag of the nf-server
  ::reset();
  shrug=0;
  old_question="";
  bandaging=0;
  silence=0;
}

