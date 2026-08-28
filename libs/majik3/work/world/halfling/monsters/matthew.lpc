inherit GUILD;

#include "../path.h"
#define say(x) "/command/mortal/say"->main(x)

create_monster()
{
     set_name("matthew");
     set_short("Matthew, Head of the Halfling Traders Union");
     set_long(wrap("Matthew is a handsome halfling. He is wearing a full body robe that goes "+
      "all the way down to his toes. It is dark green and has the symbol of the Halfling "+
      "Traders Union on it. His eyes are also green and he has blonde, almost white, hair.\n"));

     set_gender (1);
     set_language ("sartog");

     set_emote(({"Matthew checks his looks in a small mirror that he carries.",
                 "Matthew lights a small pipe and puffs on it."}));

     set_talk(({"We are now accepting new members in the Union.",
                "The Halfling Traders Union symbol garuantees quality of the product.",
                "Sign up now to get a jump on the competition.",
                "I will give you some more information if you ask me about merchants or contracts."}));

     set_race("halfling");

     set_levels(([ "fighter" : 9 ]));
 
  add_answer ("merchants",
    "The first merchants guild in the realm of Majik is now open. "
  + "You can join the guild here as well as fine tune your skills.");

  add_answer ("contracts",
    "The most important power a merchant can employ is to forge a "
  + "contract with a shop or bank keeper. The merchant must have b"
  + "een trained in the proper knowledge, however, before he or sh"
  + "e can do so. Three things useful in attempting this are 'prop"
  + "ose contract' 'forge contract' and 'check contract' in the pr"
  + "esence of the desired shop or bank keeper.");
}

create_guild ()
{
  set_guild ("Halfling Traders Union");
  set_guild_desc (
    "A member of the Halfling Traders Union learns important skills "
  + "which will allow them to earn money in an efficient manner. Mos"
  + "t importantly, he or she gains the skills necessary to oversee "
  + "the operation of general stores, banks, restaurants and blacksm"
  + "ith shops.\n");

  set_titles (({ "clerk", "middleman", "merchant", "traveler abroad", "tycoon" }));
  set_default_train_msg ("You become slightly more skilled in [skill_name].\n");
  set_custom_advance_msg ("Matthew is pleased with your progress and bestows a "
   + "new title upon you.\n");

  add_avail_skill ("banking", ({ 20, 35, 55, 80, 100 }));
  add_avail_skill ("shopkeeping", ({ 20, 35, 55, 80, 100 }));
  add_avail_skill ("accounting", ({ 20, 35, 55, 80, 100 }));
  add_avail_skill ("bookkeeping", ({ 20, 35, 55, 80, 100 }));
  add_avail_skill ("bargain", ({ 20, 35, 55, 80, 100 }));
  add_avail_skill ("salesmanship", ({ 20, 35, 55, 80, 100 }));
  add_avail_skill ("currency", ({ 20, 35, 55, 80, 100 }));
  add_avail_skill ("appraise", ({ 30, 55, 70, 90, 100 }));

                                    // ##1  ##2  ##3  ##4  ##5
  add_req_skill ("banking",         ({   0,  15,  25,  40,  60 }));
  add_req_skill ("shopkeeping",     ({   0,  15,  25,  40,  60 }));
  add_req_skill ("accounting",      ({   0,   0,  20,   0,  50 }));
  add_req_skill ("bookkeeping",     ({   0,   0,  20,   0,  50 }));
  add_req_skill ("bargain",         ({   0,   0,   5,   0,  25 }));
  add_req_skill ("salesmanship",    ({   0,   5,   0,  30,   0 }));
  add_req_skill ("currency",        ({   0,   5,   0,  30,   0 }));
  add_req_skill ("appraise",        ({   0,  15,   0,  25,  35 }));
}

