/* Do not remove the headers from this file! see /USAGE for more info. */

inherit LIVING;
inherit M_CONVERSATION;

int ive_talked = 0;
int days_since_arrival = 28 + random(20);
int bag_given = 0;
int quest_given = 0;
void select_bag(int bag_num);
void begin_quest();

void setup()
{
   set_gender(1);
   set_name("Dr. Gerald Green");
   add_id("doctor", "doc", "gerald", "dr", "ger", "doc_green");
   set_proper_name("Dr. Green");
   set_in_room_desc("Dr. Green, a tall lanky man in a mostly white labcoat.");
   set_long("'Dr. Gerald Green' his name tag says, is a tall wirey man currently sitting on an office"
            " chair with a slight smile on his face.");

   set_options((["hello":"Hello, who are you again?",
                 "while":"Uh.. quite a while?", "blood":"I had lost blood?", "hypo1":"What is hypothermia?",
                 "hypo2":"I had hypothermia?",
                    "id":"I still cannot remember who I am, did I have any identification on me?",
              "mythings":"I dunno, it might trigger something I guess",
                 "5bags":"So 5 bags? What if I select the wrong one?",
                  "bag1":"Bag 1: A red leather bag containing medical supplies.",                        // Medic
                  "bag2":"Bag 2: A backpack, that when opened reveals a laser drill and pair goggles.",  // Miner
                  "bag3":"Bag 3: An attache briefcase containing product samples and a small notebook.", // Merchant
                  "bag4":"Bag 4: A worn leather belt, holding various wrenches and tools.",              // Mechanic
                  "bag5":"Bag 5: A plastic bag containing 3 electronic tokens and some pistol.",         // Mercenary
                  "ays1":"Yes, bag number 1 it is.", "ays2":"Yes, I am going for bag number 2.",
                  "ays3":"Yes, bag number 3 surely mine.", "ays4":"Yes, it's bag number 4.",
                  "ays5":"Yes, number 5 seems to be the right one.",
                    "ns":"On a second thought, it does not seem like my bag",
              "anything":"So what now? You have a task for me?",
               "cardyes":"Sure, I'll get your card signed. Where are these colleagues?",
                "cardno":"Sorry no, I just cannot do that right now."]));

   set_responses(
       (["hello":({"I am Dr. Gerald Green.", "!point his badge on the labcoat", "Pleased to meet finally you.",
                   "You have been sleeping for quite a while, but I was hoping you would wake up today.@@while"}),
              "while":({"Umm yes, let me see...", "!flip around in the papers on the desk",
                        "You arrived here at Omega station " + days_since_arrival +
                            " days ago while unresponsive. You had various bitemarks on your person, and had suffered "
                            "from hypothermia and severe blood loss. That's all better now.@@blood,hypo1,hypo2"}),
              "blood":"Yes, you had a lot of small indentations, reminiscant of bites ... basically everywhere.",
              "hypo1":({"Hypothermia is caused by prolonged exposures to very cold temperatures. When exposed to cold "
                        "temperatures, your body begins to lose heat faster than it's produced. Lengthy exposures will "
                        "eventually use up your body's stored energy, which leads to lower body temperature.",
                        "And yes, you had it. You were discovered in the cargo hold of a larger freighter that docked "
                        "here " +
                            days_since_arrival + " days ago.@@id@@hypo2"}),
              "hypo2":"You were discovered in the cargo hold of a larger freighter that docked here " +
                          days_since_arrival + " days ago - hence the hypothermia.@@id@@hypo1",
                 "id":({"No, papers or ID chips sadly. But you did carry a bag ... the only issue is that my colleague "
                        "got "
                        "your bag mixed in with 4 other bags from other travellers that arrived during the same week.",
                        "So, I was kind of hoping you could remember which things belonged to you when you saw "
                        "them?@@mythings,5bags"}),
              "5bags":"Trust your subconsciousness! I'll assume good faith on your part, and "
                      "trust you remember which one is yours. Perhaps this can set you down the right path? ...",
           "mythings":({"Great! I'll find the bags ...@@bag1,bag2,bag3,bag4,bag5@@5bags,blood",
                        "!emote pulls out 5 bags from under the desk.",
                        "Look at all the bags. Take only the bag you believe is yours... and no backsies.",
                        "!grin widely"}),
               "bag1":"Are you sure you want to select bag 1?@@ays1,ns@@bag2,bag3,bag4,bag5",
               "bag2":"Are you sure you want to select bag 2?@@ays2,ns@@bag1,bag3,bag4,bag5",
               "bag3":"Are you sure you want to select bag 3?@@ays3,ns@@bag1,bag2,bag4,bag5",
               "bag4":"Are you sure you want to select bag 4?@@ays4,ns@@bag1,bag2,bag3,bag5",
               "bag5":"Are you sure you want to select bag 5?@@ays5,ns@@bag1,bag2,bag3,bag4",
               "ays1":({"Okay then, here you go. Bag number 1.@@@@ns", (
                                                                           : select_bag, 1
                                                                           :)}),
               "ays2":({"Okay then, here you go. Bag number 2.@@@@ns", (
                                                                           : select_bag, 2
                                                                           :)}),
               "ays3":({"Okay then, here you go. Bag number 3.@@@@ns", (
                                                                           : select_bag, 3
                                                                           :)}),
               "ays4":({"Okay then, here you go. Bag number 4.@@@@ns", (
                                                                           : select_bag, 4
                                                                           :)}),
               "ays5":({"Okay then, here you go. Bag number 5.@@@@ns", (
                                                                           : select_bag, 5
                                                                           :)}),
                 "ns":"Okay, so which one seems more familiar?@@bag1,bag2,bag3,bag4,bag5@@ays1,ays2,ays3,ays4,ays5",
           "anything":({"Yeah, there is one thing actually. I have this birthday card I need signed for Dr. Ellin from "
                        "all her colleagues around the station. This would be a great opportunity for you to check out "
                        "the different areas of the station as well as doing me a quick favour.",
                        "Would you be kind enough to help me out?@@cardyes,cardno"}),
             "cardno":"Sorry to hear that, I'll handle it myself then.@@@@cardyes",
            "cardyes":({"That's great! Take this note, it contains the location of the other medical staff that still "
                        "needs to sign, and here's the birthday card.@@@@cardno",
                        "!smile",
                        (
                            : begin_quest:)}),
   ]));

   set_start(({"hello"}));
   call_out("talk_to_me", 3 + random(4));
}

void talk_to_me()
{
   if (bag_given && !quest_given)
   {
      do_game_command("say I have a task for you, talk to me again when you're ready, so we can send you on your way.");
      call_out("talk_to_me", 30 + random(4));
   }
   if (!ive_talked)
   {
      do_game_command("say We need to talk. If you're not sure how to do this, type 'hints on'.");
      call_out("talk_to_me", 10 + random(4));
   }
}

void begin_conversation()
{
   ive_talked = 1;
   if (bag_given && !quest_given)
      quest_given = 1;
   ::begin_conversation();
}

void begin_quest()
{
   object token = present("hint_token", this_body());
   object tmp = new ("/domains/omega/item/birthday_todo");
   if (objectp(token))
      token->hint_from(tmp);
   tmp->move(this_body());
   tmp = new ("/domains/omega/item/birthday_card");
   tmp->move(this_body());
   present("door")->set_locked(0);
   this_object()->simple_action("$N $vget up and $vunlock the door.");
   QUEST_D->begin_quest(this_body(), "omega", "birthdaycard");
}

private
void set_skill(string name)
{
   int part = 0;
   string *parts = explode(name, "/");
   while (part < sizeof(parts))
   {
      if (part + 1 < sizeof(parts))
         this_body()->set_skill(implode(parts[0..part],"/"), 0);
      part++;
   }
   this_body()->set_skill(name, 250);
}

void select_bag(int bag_num)
{
   object bag = new ("/domains/omega/item/bag" + bag_num);
   object item;

   set_start(({"anything"}));
   bag_given = 1;

   switch (bag_num)
   {
   case 1: // Medic
      nnew(3, "/domains/std/consumable/bandage")->move(bag);
      new ("/domains/std/consumable/pain_killers")->move(bag);
      new ("/domains/std/consumable/chemo_satchel")->move(bag);
      set_skill("misc/crafting/medicine");
      set_skill("misc/challenge/investigation");
      set_skill("combat/defense/dodge");
      break;
   case 2: // Miner
      // Laser drill
      // Goggles
      set_skill("combat/melee/mace");
      set_skill("misc/gathering/assaying");
      set_skill("misc/gathering/mining");
      break;
   case 3: // Merchant
      // Product samples (quest item)
      // Notebook (quest item)
      set_skill("combat/defense/disarm");
      set_skill("combat/melee/unarmed");
      set_skill("misc/life/haggle");
      break;
   case 4: // Mechanic
      new ("/domains/common/weapon/wrench")->move(bag);
      new ("/domains/common/weapon/screwdriver")->move(bag);
      new (COINS, (random(10) + 20), "credit")->move(bag);
      set_skill("misc/crafting/electronics");
      set_skill("misc/crafting/mechanics");
      set_skill("combat/melee/improv");
      break;
   case 5: // Mercenary
   default:
      new ("/domains/std/weapon/mantis_eagle_m25")->move(bag);
      if (random(2)) // 50% chance it comes with a clip
         new ("/domains/std/ammo/11mm_pistol")->move(bag);
      // 3 tokens
      set_skill("combat/ranged/pistol");
      set_skill("combat/defense/dodge");
      set_skill("misc/life/boozing");
      break;
   }
   write("<226>[You learned 3 new skills]<res>\n");
   bag->move(this_body());
   this_object()->targetted_action("$N $vhand $t a $o.", this_body(), bag);
   talk_to_me();
}

string query_hint(int level)
{
   object door = present("door");
   return door->query_locked() ? "Use 'talk to doc' to talk to the doctor. Not all people you meet here might be "
                                 "talkative, but many are."
                               : "The door is open now, best of luck on your quest.";
}
