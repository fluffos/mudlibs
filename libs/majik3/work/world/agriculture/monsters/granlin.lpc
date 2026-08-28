inherit GUILD;

#include "../path.h";

create_monster()
{
     set_name(({"granlin", "man","short man", "old man"}));
     set_short("granlin, a short elderly Aindar");
     set_long(wrap("Granlin is a short and very old Aindar elf. He stands just over a meter "+
      "high and his long flowing moustache goes all the way down to his waist. He is wearing "+
      "a pair of brown, almost skin tight body suit. Plus, he has a pair of thick spectacles and "+
      "when you look closely, you can see many cuts and scars on his hands.\n"));

     set_language("sartog");

     set_emote(({"Granlin mutters something to himself.",
                 "Granlin strokes his moustache as he ponders some complicated mixture sequence."}));
     
     set_gender (1);
     set_race ("aindar");
     set_levels (([ "fighter" : 8 + random(10), "caster" : 45 + random(15) ]));
     add_money (80 + random(5));
}

create_guild ()
{
  set_guild ("University of Agricultural Mastery");
  set_guild_desc ("A pupul of agricultural mastery becomes "
   + "specialized in the basic skills of planting and gathering "
   + "plants in addition to learning to master plant health "
   + "and its inner power.\n");

  set_titles (({ "master farmer",
                 "fundamental agriculturist",
                 "agriculturist",
                 "advanced agriculturist",
                 "shaman of plantlife" }));

  set_default_train_msg ("You become a bit more adept at [skill_name].\n");
  set_custom_advance_msg ("You feel a bit more wise in the ways of agriculture.\n");

  add_avail_skill ("planting", ({ 60, 65, 70, 75, 80 }));
  add_avail_skill ("harvesting", ({ 60, 65, 65, 65, 75 }));
  add_avail_skill ("gathering", ({ 50, 55, 60, 65, 75 }));
  add_avail_skill ("weeding", ({ 50, 55, 60, 65, 75 }));
  add_avail_skill ("sowing", ({ 50, 55, 60, 65, 75 }));
  add_avail_skill ("seed knowledge", ({ 50, 60, 70, 80, 100 }));
  add_avail_skill ("irrigation", ({ 50, 75, 80, 85, 90 }));
  add_avail_skill ("plant diagnosis", ({ 35, 60, 75, 90, 100 }));
  add_avail_skill ("remedy plantlife", ({ 30, 50, 55, 60, 65 }));
  add_avail_skill ("create equanshear", ({ 0, 5, 10, 25, 50 }));
  add_avail_skill ("create galiom", ({ 0, 0, 5, 20, 45 }));
  add_avail_skill ("create shaltaar", ({ 0, 5, 10, 25, 50 }));
  add_avail_skill ("create amrin", ({ 0, 0, 5, 20, 45}));
  add_avail_skill ("create kappa", ({ 0, 5, 10, 25, 50 }));
  add_avail_skill ("create asthmil", ({ 0, 0, 5, 20, 45 }));
  add_avail_skill ("create takhid", ({ 0, 5, 10, 25, 50 }));
  add_avail_skill ("create sirum", ({ 0, 0, 5, 20, 45 }));
  add_avail_skill ("create tarek", ({ 0, 5, 10, 25, 50 }));
  add_avail_skill ("create tethar", ({ 0, 0, 5, 20, 45 }));
  add_avail_skill ("create zanex", ({ 0, 5, 10, 25, 50 }));
  add_avail_skill ("create pukabase", ({ 0, 0, 5, 20, 45 }));
  add_avail_skill ("create ithallon", ({ 0, 5, 10, 25, 50 }));
  add_avail_skill ("create joelinium", ({ 0, 0, 5, 20, 45 }));
  add_avail_skill ("create draken", ({ 0, 5, 10, 25, 50 }));

  add_req_skill ("planting", ({ 55, 0, 0, 0, 76 }));
  add_req_skill ("harvesting", ({ 46, 50, 0, 0, 60 }));
  add_req_skill ("gathering", ({ 35, 0, 50, 0, 55 }));
  add_req_skill ("weeding", ({ 0, 45, 0, 0, 70 }));
  add_req_skill ("sowing", ({ 0, 0, 50, 60, 65 }));
  add_req_skill ("seed knowledge", ({ 0, 45, 50, 55, 75 }));
  add_req_skill ("irrigation", ({ 0, 45, 0, 0, 80 }));
  add_req_skill ("plant diagnosis", ({ 0, 30, 55, 70, 85 }));
}
