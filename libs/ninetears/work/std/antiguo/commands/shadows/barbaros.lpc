inherit "/std/object";

void setup() {
   //set_name("fightcurse");
   set_weight(0);
   set_value(0);
   reset_drop();
}


int query_auto_load() { return 1; }
init() {
   ::init();
   add_action("bingle_tell","t*ell");
   add_action("bingle_tell","tel");

   add_action("bingle_shout","sh*out");
   add_action("bingle_shout","gritar");

   add_action("bingle_shout","shout!");
   add_action("bingle_say","sa*y");
   add_action("bingle_say","decir");

   add_action("bingle_say","'*");
   add_action("bingle_loud_say","lsay");
   add_action("bingle_loud_say","decira");

   add_action("bingle_loud_say","\"*");
   add_action("bingle_whisper","whi*sper");
   add_action("bingle_whisper","susurrar");

  this_player()->add_property("poison",100);
}

wibble_speech(string str)
{
 string *cow;
 int i;
 
   if(!str || str == "") return;
 cow=explode(str," ");
 for(i=0;i<sizeof(cow);i++)
  //cow[i]=capitalize(cow[i]);
 str=implode(cow," ");
   str=replace(str,({"s","z","ch","tz","ca","ka","ce","ze","ci","zi","co","ko","cu","ku",
	"x", "kz", "que", "ke", "qui",
	"ki","ge","je", "gi", "ji", "y", "i",
	"S","Z","CH","TZ","CA","KA","CE","ZE","CI","ZI","CO","KO","CU","KU",
	"X", "KZ", "QUE", "KE", "QUI", "KI","GE", "JE", "GI", "JI", "Y",
	"xD", "xD", "XD","XD","Xd","Xd",
	"I", "Que", "Ke", "Qui", "Ki", "Ca", "Ka", "Ce", "Ze", "Ci", "Zi",
	"Co", "Ko", "Cu", "Ku", "Ge", "Je", "Gi", "Ji",
	"barbaro", "zenior de la guerra", "barbaros",
	"zeniorez de la guerra", "Barbaro", "Zenior de la Guerra",
	"Barbaros", "Zeniorez de la Guerra", "barbaros",
	"zeniorez de la guerra"}));
  return str;
}
 
 
void bingle_loud_say(string arg)
{
 int x;
 
 arg=(string)wibble_speech(arg);
 x=this_player()->do_loud_say(arg);
 return x; // esto no es un void?
}
 
void bingle_say(string arg)
{
 int x;
   string wool;
 
   if(!arg || arg=="") return;
   if( (string)this_player()->query_word_type(arg)=="pregunta")
   wool=({"Wraaag, ","%^BOLD%^%^GREEN%^Waaagh%^RESET%^, ","%^RED%^Groooak! %^RESET%^"})[random(3)];
    else
   wool=({"Wraaag, ","%^BOLD%^%^GREEN%^Waaagh%^RESET%^, ","%^RED%^Groooak! %^RESET%^", "Groargh, ", ""})[random(5)];
   arg=(string)wibble_speech(arg);
  x=this_player()->do_say(wool+arg);
 return x;
}
 
void bingle_tell(string arg)
{
 int x;
    string *cow, woobie;
 
 
   if(!arg || arg == "") return;
   cow=explode(arg," ");
   woobie=cow[0];
    if( (string)this_player()->query_word_type(arg)=="pregunta")
   cow[0]=({"Wraaag, ","%^BOLD%^%^GREEN%^Waaagh%^RESET%^, ","%^RED%^Groooak! %^RESET%^"})[random(3)];
    else
   cow[0]=({"Wraaag, ","%^BOLD%^%^GREEN%^Waaagh%^RESET%^, ","%^RED%^Groooak! %^RESET%^", "Groargh, ", ""})[random(5)];
   arg=implode(cow," ");
 
   arg=(string)wibble_speech(arg);
   arg=woobie+" "+arg;
  x=this_player()->do_tell(arg);
 return x;
}
 
void bingle_shout(string arg)
{
 int x;
   string wool;
 
   if(!arg || arg == "") return;
   if( (string)this_player()->query_word_type(arg)=="pregunta")
   wool=({"Wraaag, ","%^BOLD%^%^GREEN%^Waaagh%^RESET%^, ","%^RED%^Groooak! %^RESET%^"})[random(3)];
    else
   wool=({"Wraaag, ","%^BOLD%^%^GREEN%^Waaagh%^RESET%^, ","%^RED%^Groooak! %^RESET%^", "Groargh, ", ""})[random(5)];
   arg=(string)wibble_speech(arg);
  x=this_player()->do_shout(wool+arg);
 return x;
}
 
void bingle_whisper(string arg)
{
 int x;
    string *cow, woobie;
 
   if(!arg || arg == "") return;
   cow=explode(arg," ");
   woobie=cow[0];
    if( (string)this_player()->query_word_type(arg)=="pregunta")
   cow[0]=({"Wraaag, ","%^BOLD%^%^GREEN%^Waaagh%^RESET%^, ","%^RED%^Groooak! %^RESET%^"})[random(3)];
    else
   cow[0]=({"Wraaag, ","%^BOLD%^%^GREEN%^Waaagh%^RESET%^, ","%^RED%^Groooak! %^RESET%^", "Groargh, ", ""})[random(5)];
   arg=implode(cow," ");
 
   arg=(string)wibble_speech(arg);
   arg=woobie+" "+arg;
  x=this_player()->do_whisper(arg);
 return x;
}
