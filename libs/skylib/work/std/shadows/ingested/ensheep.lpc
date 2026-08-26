
inherit "/std/effect_shadow";

mixed query_property(string str){
  if(!interactive(player) && str == "determinate"){
    return 0;
  }
  return player->query_property(str);
}

varargs string short(int dark) {
   if (player){
     if(interactive(player))
       return player->query_short()+" the cute fluffy sheep"; 
     return "cute fluffy sheep"; 
   }
   return "sheep curse shadow";
}

string query_short() {
   if (player){
     if(interactive(player))
       return player->query_short()+" the cute fluffy sheep"; 
     return "cute fluffy sheep"; 
   }
   return "sheep curse shadow";
}
mixed query_main_plural() { return "cute fluffy sheep"; }
mixed query_long() { return "This is a cute fluffy sheep.\n"; }
mixed query_plural() { return "cute fluffy sheep"; }


string query_gender_string() {
   switch(player->query_gender()){
     case 1:
       return "ram";
     case 2: 
       return "ewe";
     default:
        return "sheep"; 
   }
}
string query_gender_title() { 
   switch(player->query_gender()){
     case 1:
       return "ram";
     case 2: 
       return "ewe";
     default:
        return "sheep"; 
   }
}

string *query_adjectives(){
 return (player->query_adjectives() + ({"cute", "fluffy"}));
}
int id_adjective( string word ) {
  return ( member_array( word, query_adjectives() ) != -1 );
} /* id_adjective() */
string *parse_command_adjectiv_id_list() { return query_adjectives(); }
string long(string str, int dark) {
   string s;

   s = "You see a cute fluffy sheep of the Woolly Thinker's Guild.\n"
       "It is a fluffy and adorable sheep who really "
       "looks unhappy about something.  ";
/*   if(interactive(player)) {
    switch(something){
      case 0 :
        s += "There is something about the shade of the black wool... "
            "like black light passed through a prism that reminds you of "
            +player->query_short()+"'s garb.\n";
        break;
      case 1 :
        s += "There is something about the squint that reminds you of "+
           player->query_short()+".\n";
        break;
      case 2 :
        s += "There is something about the shifty eyes that reminds you of "+
           player->query_short()+".\n";
        break;
      case 3 :
        s += "There is something about the pointy hat that reminds you of "+
           player->query_short()+".\n";
        break;
      case 3 :
        s += "There is something about the fanatic baaing that reminds you of "+
           player->query_short()+".\n";
        break;
      default:
        s += "There is something about the rippling muscles upon its wooly legs "
           "that reminds you of "+player->query_short()+".\n";
        break;
    }
   } */
   s += capitalize(player->query_pronoun())+" "+
           player->health_string()+".\n";
   s += player->calc_extra_look();
   return s;
}

string smurf( string str ) {
   string str1;
   if ( sscanf( str, "%s,", str ) ) str1 = ",";
   else if ( sscanf( str, "%s.", str ) ) str1 = ".";
   else if ( sscanf( str, "%s!", str ) ) str1 = "!";
   else if ( sscanf( str, "%s;", str ) ) str1 = ";";
   else str1 = "";
   if ( sscanf( str, "%sing", str ) ) str = "baaaaing";
   else if ( sscanf( str, "%sd", str ) ) str = "baaaad";
   else if ( sscanf( str, "%ss", str ) ) str = "baaaa";
   else str = "baa";
   return str + str1;
}

string mangle_speech( string str ) {
   string tmp, *bits;
   int i;
      tmp = player->mangle_speech( str );
   if( !tmp ) tmp = str;
   bits = explode(tmp, " ");
   for (i=0;i<sizeof(bits);i+=(random(4) + 1) ) {
      bits[i] = smurf( bits[i] );
   }
   tmp = implode(bits, " ");
   return tmp;
} /* mangle_speech() */
