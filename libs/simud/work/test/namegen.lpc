string *fire = ({ "orth", "plam", "flam", "helon", "helios", "sol",
   "ogen", "apol", "valk", "vulk", "vulc", "vulcan", "heph", "hef" });

string *water = ({ "aqu", "wod", "vod", "liqu", "pos", "trit", "triton",
   "poseid", "mar", "mer", "aquon", "aqueon", "vodnon" });

string *elf = ({ "ish", "lath", "loth", "alan", "landr", "orl", "orel",
   "kalon", "derin", "palan", "thir", "thon", "nath", "dal" });

string *soft_connector = ({ "on", "an", "in", "al", "ul", "iod",
   "olor", "or", "ar", "er", "ier", "oar", "url", "alr", "il" });

string *soft_suffix = ({ "ion", "us", "as", "eos", "ios", "ao", "ero",
   "aos", "ia", "ara", "alad", "iba", "ibar", "inu", "inn", "al", "alla",
   "atha", "ith", "eth" });

string *hard_suffix = ({ "ix", "ucht", "azesh", "eryos", "int", "artch", "et",
   "ashok", "ik", "apt", "adrez", "iz", "itlik", "inak", "asp", "oserp", "ash",
   "okol", "ofir", "ef" });

string get_fire_part() {
   return fire[random(sizeof(fire))];
}

string get_water_part() {
   return water[random(sizeof(water))];
}

string get_elf_part() {
   return elf[random(sizeof(elf))];
}

string get_soft_connector() {
   return soft_connector[random(sizeof(soft_connector))];
}

string get_soft_suffix() {
   return soft_suffix[random(sizeof(soft_suffix))];
}

string get_hard_suffix() {
   return hard_suffix[random(sizeof(hard_suffix))];
}

string get_elf_name() {
   return capitalize(get_elf_part() + get_soft_suffix());
}

string get_long_elf_name() {
   return capitalize(get_elf_part() + get_soft_connector() + get_soft_suffix());
}

string get_water_name() {
   return capitalize( get_water_part() + get_soft_suffix() );
}

string get_dark_name() {
   return capitalize( get_fire_part() + get_hard_suffix() );
}
