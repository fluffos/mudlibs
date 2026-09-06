string *fire = ({ "orth", "plam", "flam", "helon", "helios", "sol",
   "ogen", "apol", "valk", "vulk", "vulc", "vulcan", "heph", "hef",
   "fir", "akar", "volc", "rous", "roug", "ror", "roj" });

string *water = ({ "aqu", "wod", "vod", "liqu", "pos", "trit", "triton",
   "poseid", "mar", "mer", "aquon", "aqueon", "vodnon" });

string *wind = ({ "vya", "win", "bris", "brees", "brez", "draf",
   "vyat", "lok", "lokin", "aer", "aeron", "arin", "breth", "vent",
   "ven" });

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

string get_human_name() {
   switch( random(5) ) {
      case 0:
      case 1: return get_elf_name();
      case 2: return get_long_elf_name();
      case 3: return get_water_name();
      case 4: return capitalize(get_elf_part() + get_hard_suffix());
   }
   return 0;
}

// Of course, these rules are completely arbitrary and very
// much culturally grounded, but I figure it's an easy way
// for players to figure out gender by names.
int is_name_feminine( string name ) {
   if( name[<1..<1] == "a" ) return 1;
   if( name[<3..<1] == "eth" ) return 1;
   if( name[<1..<1] == "u" ) return 1;
   if( name[<2..<1] == "th" ) return 1;
   if( name[<2..<1] == "sh" ) return 1;
   return 0;
}
