inherit MONSTER;

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
