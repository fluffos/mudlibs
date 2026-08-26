// Coded by Chronos.
// NOTICE: Don't even think about stealing this code and modifying
//         the names and whatnot.  I've worked real hard on this
//          monster, and I don't appreciate people stealing it.  You 
//          can use this file for a reference on HOW to do this sort
//          of thing with a monster, but have some respect- Don't steal it.
// (08-27-96) Modified by Chronos to be a little more efficient and cool.
// (04-05-98) Modified by Chronos again to be even more efficient and to
//            respond to more shit.  Also ported code to the new lib.
// (04-12-98) Modified by Chronos to WORK right.  This new lib is a pain
//            in my fucking ass.
// (04-18-98) Revisions upon revisions.  Supports more speech now.
// (04-21-98) Cyanide added a visible check for the cool init()
//            stuffs, and added a few things.
// (10-20-98) Chronos fixes the process_give() function again.
// (09-17-99) Cyanide MR-ized him a bit.
// (23-06-00) Chronos adds more effects, and the process_item() function.
//            Added more reactions to speech.

#include <mudlib.h>

// This defines the max level you can be and still be a newbie.
#define NEWBIE_LEVEL 5 

int help(string name);
int force_me(string command);
string fix(string msg);
void respond_init(string name) ;
void process_item(object ob) ;

// define stuff to ignore
string *PUNC ;

inherit MONSTER;

void create() {
    seteuid(getuid());
    // Had to define this in here for some unknown reason.  New lib.  *SIGH*
    PUNC=({".","!","?",",","/",";",":","[","]","-","+","_","=", "@","#","$",
    "%","^","&","*","(",")","~","`","'", "|" });
::create();
set("short", "Alucard the Traveler (neutral)") ;
set("author", "chronos") ;
  set("weap_resist", 4) ;
set("prevent_summon", 1 ) ;
set("inquiry", ([
  "classes" : "One's class is his chosen profession, and he cannot leave it "+
  "to pursue another one. Ask me about the classhalls.",

  "classhalls" : "Currently, there are 4 open: the mages, the thieves, the "+
  "sharpshooters, the priests, and the pit fighters. Ask me about any one of them.",

  "mages" : "They cast spells and stuff. Wimps at low levels, "+
  "but later on, watch out! They have a hall 2 north, and 1 east of here.",

  "sharpshooters" : "VERY skilled marksmen. They have a classhall "+
  "4s, 1w, 1 down from here, in the basement of Grik's.", 

  "thieves" : "They do sneaky stuff, like hiding so well they become "+
  "invisible, and backstabbing HARD. They have a classhall 5 south, "+
  "2 east, south, and 3 east from here.",

  "pit fighters" : "Professional gladiators who kick ass in a fight. They "+
  "have a hall 5 south, 2 east, 2 south, and 1 west of here.",

  "priests" : "These are individuals whose power is granted by the powerful "+
  "beings they worship. Currently available priests worship Talos. Ask me about Talos.",

  "talos" : "Talos is the evil god of lightning and storms. His temple "+
  "is located 2 east, 1 south of here. Talos requires that his "+
  "priests have a strength of 13 and a wisdom of 14, as well as be "+
  "of chaotic evil alignment.",

  "hoss" : "Yeah, he's rough.",
  "equipment" : "If you need any, say help.",
  "anything" : "Experimenting with the 'ask' command, huh?",
  "adventuring" : "Ahh, I could tell you stories for days.  All true.",
  "makeriham" : "He finally got a better job.\n",
  "class" : "I have LOTS of it. Ask me about 'classes', too.",
  "newbies" : "Pains in the asses they are.\n",
  "stories" : "They are much too long to be telling you right now.  I have a lot to do here.",
  "underwear" : "I'm not wearing any.",
  "shoes" : "Why do people always wanna know about my shoes?",
  "cyanide" : "He's fuckin' cool!  I wish I could code half as well..",
  "chronos" : "Well, he coded me, so he must be the man.",
  "coding" : "Talk to Chronos about that, not me.",
  "ilzarion" : "Shitty coder.",
  "nightmask" : "That guy tried to kiss me once.  Real weird...",
  "alucard" : "Oh you didn't know?  Your ass better call somebody..",
  "bridge" : "Ever since it closed, the homeless have been living "+
  "there. The cops don't patrol it, and it ain't very safe.",
  "gangs" : "I like 'em, even though I'm WAY too cool for 'em. You "+
  "can get info by typing 'help gangs', or you can found a gang at "+
  "the machine 2s, 2e of here.",
  "hoss" : "He's a heavy pipe hittin' mutha'!",
  "life" : "Life is hard, get a helmet.",
  "wcw" : "The WWF is kicking their lily asses.",
  "wwf" : "If ya smellllllllll-l-l---l what the Rock... is cookin.",
  "wrestling" : "I watch Raw every Monday night, and Smackdown every Thursday night.  You should too.\n",
  "help" : "If you need help, just say so.",
  "mud" : "Gee, that's a real specific question..  How about asking me about \"classes\" for some useful information.\n",
  "sex" : "It's fun.  I get my share.",
  "dying" : "It's not fun.  You should try to avoid doing it.",
  "death" : "He's a mean old bastard that lives at the top of a mountain.",
  "alice in chains" : "Definately, my favorite band.",
  "weapons" : "I can give you some free ones if you are low enough level.",
  "armor" : "I can give you some free shit if you are low enough level.",
  "armour" : "I can give you some free shit if you are low enough level.",
  "experience" : "You need experience to advance levels.  You can advance levels in class halls.",
  "guilds" : "We don't use guilds here, we use classes. Ask me about them.",
  "class halls" : "Some of them are to the east.",
  "infinity" : "You mean the Fisher Price (tm) My First MUD?",
  "tormeid" : "There are some great treasures in that castle.  The king is super-rich.",
  "petting zoo" : "I used to go their and slaughter the children when I was a little newbie punk.",
  "pub" : "There's a nice little pub 1 north, 1 east."  ,
]) );

enable_commands();
set("smell", "He smells musky and manly.") ;
set("long", @ENDLONG
Alucard was once a mighty adventurer.  He has since retired, become the
newbie helper of the mud, and gained a great deal of weight.  Upon his
feet are a beautiful pair of leather shoes that just seem to catch your
eye for no apparent reason. You could probably receive help if you asked
for it.
ENDLONG
);
set_name("alucard");
set("id", ({
  "alucard",
}));
set("damage", ({ 3, 30 }) ) ;
set("attack_strength", 15);
set("race", "human");
set("attrib1", "tall");
set("attrib2", "handsome");
set("gender", "male");
set("weapon_name", "scimitar");
set_verbs( ({
  "swing at",
  "cut at",
  "lunge at",
  "attack",
}));
set_level(99);
set("stat/strength", 19) ;
set("stat/dexterity", 16) ;
set("stat/constitution", 15) ;
set("stat/intelligence", 13) ;
set("stat/wisdom", 9 ) ;
set("stat/charisma", 15) ;
set("armor_class", -14) ;
  set("chat_chance", 3 ) ;
set("chat_output", ({
  "Alucard sighs wistfully.\n",
  "Alucard says [to you]: Remember.. All things are possible, except skiiing\n     through a revolving door.\n",
  "Alucard says: Ask me about \"classes\".\n",
  "Alucard sings the \"Thong Song\" under his breath.\n",
  "Alucard says: If you need help, just ask for it.\n",
}) );
set("natt", 3) ;
set("attack_chat_output", ({
  "Alucard whispers to you: I am immortal.\n",
  "Alucard cackles with glee!\n",
}) );
}

void
receive_message(string Class, string message) {
    string name, msg;
    if (sscanf(message, "%s laughs.", name)==1)  {
	call_out("force_me", random(3) + 1, "laugh");
	return ;
    }
    if (sscanf(message, "%s pokes you in the tummy.", name) == 1 ||
      sscanf(message, "%s ruffles your hair.", name) == 1 
    ) {
	call_out("force_me", random(2) + 1, "do scowl, to "+lower_case(name)+" Cut that out.") ;
	return ;
    }
    if (sscanf(message, "%s admires you.", name ) == 1) {
	call_out("force_me", random(2) +1,
	  "to "+lower_case(name)+" You're too kind.") ;
	return ;
    }
    if (sscanf(message, "%s nods at you.", name ) ==1) {
	call_out("force_me", 1, "smile "+lower_case(name)) ;
	return ;
    }
    if (sscanf(message, "%s bows.", name)==1) {
	call_out("force_me", 1, "clap "+lower_case(name)) ;
	return ;
    }
   if (sscanf(message, "%s makes a short pass to you!", name)==1) {
      call_out("force_me", 1, "grin "+lower_case(name)) ;
      call_out("force_me", 3, "do get nerf, punt") ;
       return ;
    }
    if (sscanf(message, "%s cries.", name)==1) {
	call_out("force_me", random(3) + 1, "comfort "+lower_case(name));
	return ;
    }
    if (sscanf(message, "%s sobs", name)==1) {
	call_out("force_me", random(3) + 1, "comfort "+lower_case(name));
	return ;
    }
    if (sscanf(message, "%s frowns.", name)==1) {
	call_out("force_me", random(3) + 1, "comfort "+lower_case(name));
	return ;
    }
    if (sscanf(message, "%s kisses you.", name)==1) {
	call_out("force_me", 1, "blush") ;
	return ;
    }
    if (sscanf(message, "%s gives you a good spanking!", name)==1) {
	call_out("force_me", random(3) + 1, "grin "+lower_case(name));
	return ;
    }
    if (sscanf(message, "%s says [to you]: %s", name, msg) == 2) {
	call_out("process_say", random(3) + 1, name, msg);
	return ;
    }
    if (sscanf(message, "%s says: %s", name, msg)==2) {
	call_out("process_say", random(3)+1, name,msg);
	return ;
    }
    if (sscanf(message, "%s asks: %s", name, msg) == 2) {
	call_out("process_say", random(3)+1, name, msg) ;
	return ;
    }
    if (sscanf(message, "%s exclaims: %s", name, msg) == 2) {
	call_out("process_say", random(3)+1, name, msg) ;
	return ;
    }
    if (sscanf(message, "%s gives %s to you.", name, msg)==2) {
	call_out("process_give", random(10)+2, name,msg);
	call_out("force_me", 1, "brow") ;
	call_out("examine", 1, "Alucard throroughly examines "+msg+".\n") ;
	return ;
    }
    ::receive_message(Class, message) ;
    return ;
}

int examine(string str) {
    message("blah", str, 
      environment(TO), ({ TO }) ) ;
    return 1; 
}

int process_give(string name, string item) {
    int i;
    string str;
    if (sscanf(item, "%d credit", i)==1) {
	if (i==1) {
	    force_me("say Oh gee, thanks.  1 credit.");
	    force_me("spit in disgust") ;
	    return ;
	}
	force_me("to "+lower_case(name)+" Hey, thanks.  I'll always be more than happy to take your money from you.") ;
	force_me("smile sweetly") ;
	return ;
    }
    if (sscanf(item, "a credit", str)==1) {
	force_me("to "+lower_case(name)+
	  " ONE lousy fucking credit!?") ;
	force_me("spit in disgust") ;  return ; 
    }
    command("to "+lower_case(name)+" Quit giving me all your crap!") ;
    return 1;
}

int force_me(string command) {
    command(command);
    return 1;
}

int process_say(string name, string msg) {
    /* This compiler doesn't like this format.
      msg = msg[0..-2];
    */
    msg = msg[0..<2];
    msg = (string)fix(msg) ;
    switch(msg) {
    case "yo not much al": case "not much al" :
    case "yo nuttin al" :
    case "pimpin aint easy":  
    case "nuttin al" : case "not a whole lot al" :
    case "nothin al" : case "nothing al" :
    case "nuthin al" :
	if (name!="Chronos") {
	    force_me("emote looks around for a moment, confused.") ;
	    break ;
	}
	switch(random(5)) {
	case 1: force_me("to chronos Quit calling me Al.  You know I hate that.");
	    break;
	case 2: force_me("to chronos Word, Brutha.");
	    break ;
	case 3: force_me("to chronos As usual, you bum.") ;
	    break ;
	case 4: force_me("to chronos Keeping busy coding?");
	    break ;
	default: force_me("to chronos Ahh, cool.") ;
	    break ;
	}
	break ;
    case "whatever al":
     if (name!="Chronos") break ;
         call_out("force_me", 3, "do glare chronos, fuckstick chronos") ;
    break;
   case "die bitch": case "die" : case "you die now" :  case "fucking die bitch":
              case "fuckin die bitch" : case "die die die":
        case "fuck you die bitch":
     call_out("force_me", 2, "do snarl, to "+name
             +" Make me.") ;
   break ;
    case "hi": case "hello" : case "hellow" : case "hiya" : case "hi there" :
    case "howdy" : case "hola" : case "wussup": case "wuttup": case "yo":
    case "greetings" : case "heya": case "hey dude" : case "hey dood":
    case "hey duder": case "wussup dude" : case "wuttup g": case "yo dude":
    case "hi alucard" : case "hey alucard" : case "hello alucard" :
    case "greetz" :
	switch(random(12)+1) {
	case 1: force_me("say Hi there."); break; 
	case 2: force_me("say Hi.  What's up?"); break;
	case 3: force_me("say Greetings."); break;
	case 4: force_me("smile "+lower_case(name)); break;
	case 5: force_me("say Hi.  You need something?");break;
	case 6: force_me("say How are you?");break;
	case 7: force_me("say Hello.");break;
	case 8: force_me("wave "+lower_case(name));break;
	case 9: force_me("nod "+lower_case(name));break;
	case 10: force_me("say Wuttup dog."); break ;
	default: force_me("say Hi.");  break;
	}
	break;
    case "help" : case "help me": case "i need help" :
    case "help me al" :  case "help me alucard" :
    case "come on help me out" : case "help me out" : case "help me out here"
	:
    case "need help" : case "need help now" :
    case "equip me" : case "equipme" :
    case "help please" : case "gimme some shit" : 
    case "gimme some shit asshole" : case "gimme some loot": 
    case "give it up fuckface" : case "help a newbie" : case "give it up":
    case "help a homie" : case "i need some help" :
    case "i need some shit" : case "hi can you help me" :
    case "please help me" : case "can you help me out" :
    case "please help" : case "can you help me please":
    case "show me the money" :  case "hook me up" :
	help(name);break;
    case "i love you" : case "i love you alucard" :
    case "i love you man" :
    case "i love alucard" : case "i love ya" : case "i luv you" :
	force_me("to "+lower_case(name)+" You're not the first to tell me that.");
	break ;
    case "shut up" : case "shut the hell up" : case "shut the fuck up":
    case "shut yer trap" : case "shut your mouth" : case "sierra la boca" :
    case "be quiet" : case "hush" :
	force_me("to "+lower_case(name)+" Make me.") ;
	break ;
    case "how are you" : case "how are you doing" :
    case "how are ya doin" : case "how the fuck are you":
    case "how are you hanging" : case "hows it hanging" :
    case "how are ya hanging": case "how the fuck are ya":
    case "hows it hangin" : case "how the hell are you" : 
    case "how the hell are ya?" : case "how r u " :
    case "how are ya?" :  case "how r you" : case "how are u":
	force_me("say Fine, thanks.");  break ;
    case "i hate you" : case "i hate you alucard" :
	force_me("to "+lower_case(name)+" That's because you can't have me.");break;
    case "yo quiero taco bell" :
    case "god bless you taco bell": case "bless you taco bell" :
    case "its a taco revolution" :  case "gordita" : case "gorditas" :
	force_me("to "+lower_case(name)+" I'm gonna kill that little fucking dog.");  break ;
    case "you da man": case "your the man" : case "you the man" :
	force_me("say I know.");  break ;
    case "fuck you" : case "fuck off" : case "eat shit" :
    case "eat shit and die" : case "you suck" :
    case "suck my cock" : case "suck my dick" :
	force_me("to "+lower_case(name)+" Don't make me have to kill you.");break;
    case "nice shoes" : force_me("say Thanks.");break;
    case "lick my ass" : case "lick my nuts" : case "lick my nutsack" :
    case "kiss my ass" : case "kiss my butt" : case "lick my asshole" :
	force_me("say No thanks."); break;
    case "eat me" : case "why don't you eat me" :
    case "eat my shorts" : case "eat a dick up til ya hiccup" :
    case "eat a dick up" : case "eat a dick" :
	force_me("say Why don't you eat *me*?");break ;
    case "bite me" : case "kiss off" : case "bite my crank" :
    case "kiss my arse" : case "bite my ass" :
    case "kiss my ass" :
    case "alucard sucks" : case "al sucks":
	force_me("to "+lower_case(name)+" Bite my crank, Loser.");break;
    case "i like makeriham better" : case "mak was better" :
    case "makeriham is better" : case "i like mak better" : 
	force_me("to "+lower_case(name)+" Tough shit.") ; break ;
    default: 
	if (!random(25)) {
	    switch(random(5)) {
	    case 0: force_me("peer "+lower_case(name)); break ;
	    default: force_me("glance "+lower_case(name)); break ;
	    }
	}
	break;
    }
    return 1;
}

int help(string name) {
    object victim;

    seteuid(getuid());
    victim=present(lower_case(name),environment());
    if (!victim) {
	force_me("be confused");
	force_me("scratch");
	return 1;
    }

    if (wizardp(victim)) {
	force_me("to "+lower_case(name)+" You're a wizard! "+
	  "Go code something you loser!");
	return 1;
    }

    if ((int)victim->query_level()<NEWBIE_LEVEL) {
	if (present("newbie_equipment", victim)) {
	    force_me("to "+lower_case(name)+" You already have some equipment!");
	    return 1;
	}
	tell_object(environment(), @ENDNEWBIE
Alucard casts a spell.  A small hole forms beside him.
He reaches into the hole and pulls out some equipment.
ENDNEWBIE
	);
	tell_object(victim, "Alucard hands you some equipment.\n");
	clone_object("/d/Ancients/obj/boots")->move(TP) ;
	clone_object("/d/Ancients/obj/leaflet")->move(TP) ;
	//clone_object("/d/Ancients/obj/cloak")->move(TP) ;
	clone_object("/d/Ancients/obj/bat")->move(TP) ;
	clone_object("/d/Ancients/obj/armour")->move(TP) ;
	//clone_object("/d/Outer/Sigil/items/map")->move(TP) ;
	message("blah",
	  "Alucard hands "+victim->query("cap_name")+
	  " some equipment.\n", environment(), ({ victim })) ;
	return 1;
    }
    force_me("to "+lower_case(name)+" You are pathetic!");
    force_me("laugh "+lower_case(name));
    return 1;
}

string fix(string msg) {
    string final, work, previous;
    int i;
    if (!msg) return "No message.";
    for(i=0;i<sizeof(msg);i++) {           // Convert it all to lower case.
	work = extract(msg, i, i) ;
	if (member_array(work, PUNC) != -1) continue ;
	if (!work) continue ;
	if (work == " " && previous == " ") continue ;
	if (i==0) final = lower_case(work) ;
	else
	    final = final + lower_case(work) ;
	previous = work ;
	work ="";
	continue ;
    }
    return final;
}

void init() {
    if (userp(TP) && !TP->query_level()) {
	call_out("force_me", 1, "to "+TP->query("name")+" Heya Newbie! "+
	  "If you need anything, just say so. Don't be afraid to "+
	  "\"ask\" me about anything, either!");
    }
    if (!TP->query("invisible")) respond_init(TPN) ;
    add_action("prevent_action", "bang") ;
    add_action("prevent_action", "slap") ;
    add_action("prevent_action", "rape") ;
    add_action("prevent_action", "smack") ;
    add_action("prevent_action", "sodomize") ;
    add_action("prevent_action", "massage") ;
    add_action("prevent_action", "pkiss") ;
    add_action("prevent_action", "grope") ;
    add_action("prevent_action", "fondle") ;
    add_action("prevent_action", "buttkick") ;
    add_action("prevent_action", "tkiss") ;
    add_action("prevent_action", "zrbrt") ;
    add_action("prevent_action", "mcfly") ;
    add_action("prevent_action", "french") ;
    add_action("prevent_action", "excite") ;
    add_action("prevent_action", "doidle") ;
     add_action("prevent_action", "frisk") ;
}

int prevent_action(string name) {
    if (!id(name)) return 0 ;
    write("Alucard won't let you do that to him.\n");
    return 1;
}

void respond_init(string name) {
    switch(name) {
    case "Chronos": call_out("force_me", random(2)+1, "do five chronos, to chronos Wuttup C!");  break ;
    case "Herself": call_out("force_me", random(2)+1,
             "do wink herself, to herself Heya Cutie!"); break ;
    case "Cyanide" : call_out("force_me", random(2)+1,
	  "do five cyanide, to cyanide How's it goin' Admin-dude?"); break;
    case "Minx" : call_out("force_me", random(2)+1, "do to minx Hiya sweetie., wink minx") ; break ;
   case "Nsd": call_out("force_me", random(2)+1,
   "do bow nsd, to nsd Greetings, Lady Nsd."); break ;
    case "Nightmask" : call_out("force_me", random(2)+1, "do bow nightmask, to nightmask Hola ThunderCamel.") ; break ;
    case "Loretta" : call_out("force_me", random(2)+1, "do pat loretta, to loretta Good girl!"); break;
    default: break ;
    }
}

void die() {
    set("hit_points", 90000) ;
    message("combat", 
@ENDMSG
Alucard drops to one knee.
Alucard calls upon the power of Chronos to aid him.
His body is suddenly lifted off the ground, revitalized.

Alucard says: Now I'm really mad.

Alucard lets out a mighty battle cry!

ENDMSG
      ,
      environment(TO), ({ TO }) ) ;
    set("damage", ({ 10 , 90 }) ) ;
    set("weapon_name", "Power of Chronos") ;
    set_verbs( ({ "will damage on", "assault", "bombard" }) ) ;
    return ;
}

void heart_beat() {
   int i ;
   object *inv ;
    inv = all_inventory(TO) ;
   if (inv) {
      for (i=0;i<sizeof(inv);i++) {
        process_item(inv[i]) ;
    }
   }
   command("get all") ;
   ::heart_beat()  ;
}

void process_item(object ob) {
  string filename ;
  object *users ;
   if (!ob->query("short")) return ;
   filename = file_name(ob) ;
  sscanf(filename, "%s#", filename) ;
    switch(filename) {
    case "/u/c/chronos/toys/nerf":
    if (!users()) break ;
    if (!random(5))  {
        command("say Stupid Nerf things!") ;
    if (!random(2)) 
        command("punt") ;
    else command("spike") ;
    }
       break ;
    case "/u/n/nsd/obj/toys/anvil" : 
   if (!random(7)) {
      users=users() ;
     command("throw anvil at "+users[random(sizeof(users))]->query("name")) ;
  }
   break ;
    case "/u/c/cyanide/toys/apple" :
        command("eat apple") ;
    break ;
    case "/u/c/chronos/toys/pie" : 
      if (!random(10)) {
          users = users() ;
        command("pie "+users[random(sizeof(users))]->query("name")) ;
   }
   break ;
   default: 
  if (!random(12)) {
      message("blah", "Alucard thoroughly examines "+ob->query("short")+
               ".\n", environment(), ({ TO }) ) ;
      call_out("destroy_item", 2 + random(4), ob ) ;
   }
       break ;
   }
}

void destroy_item(object ob) {
    message("blah", "Alucard mutters a strange incantation and "+
    ob->query("short")+" bursts into flames.\n", environment(), ({ TO }) ) ;

   ob->remove() ;
  }
