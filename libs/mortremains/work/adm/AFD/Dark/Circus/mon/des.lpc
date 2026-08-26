inherit MONSTER;

void create() {
  set("short", "desmeralda, the gypsy");
  set("long", @ENDLONG
Desmeralda is dressed in a colorful outfit.
She wears a long dark blue, tough-knit skirt
topped with a bright yellow blowse.  She
wears a red scraf about her head, like a hat.

If you would like to know your fortune type [ fortune ].
         -= For the cost of 35 coins =-
ENDLONG
  );
  set_alignment(120);
  set_name("desmeralda");
  set("id", ({
    "gypsy",
    "desmeralda",
  }));
  set("damage", ({ 200, 800 }) );
  set("armor_class", 35);
  set("attack_strength", 50);
  set("race", "human");
  set("attrib1", "youthful");  set("attrib2", "hazel-eyed");
  set("gender", "female");
  set("weapon_name", "fists");
  set_verbs( ({
    "beat",
    "jab",
}));
  set_skill("defense", 50, "dexterity");
  set_skill("attack", 50, "strength");
  set_level(50);
  set("chat_chance", 3);
  set("chat_output", ({
   "Desmeralda asks: \"Could I help you with something?\"\n",
}) );
  set("forgetful", 1);
  
}

void init(){ add_action("fart","fortune"); }

int fart(){
if(wizardp(TP)){ write("Desmeralda looks at you and sighs.\n"); write("Don't You have some coding to do?\n"); return 1; }
if(!TP->debit(35)){

    write("Desmeralda says: \"My wisdom comes at a price, young one.\"\n"); return 1; }
if(TO->query("telling")){ write("Desmeralda is busy right now.\n"); return 1; }
TO->set("telling", 1);
write("Desmeralda stares into her crystal ball.\n");
call_out("fart2", 5);
return 1;
}

int fart2(){
if(!present(TP, environment(TO))){ return 1; }
write("Desmeralda says: \"Let's see what we have here.\"\n");
call_out("end_fart", 10);
return 1;
}

int end_fart(){
write("Desmeralda says:\"It's coming through now.\"\n");
call_out("doit", 10);
return 1;
}

int doit(){
  int lev;
  int nmbr;
lev = TP->query_level();
nmbr = random(20);



switch(nmbr + lev){

    case 1..10:  write("Your future looks bleak indeed.\n"); break;
    case 11..16:  write("You should consider early retirement.\n"); break;
    case 17..20: write("Your career as a "+TP->query("guild")+" doesn't look very promising.\n"); break;
  case 21..25: write("Your future is uncertain to me, come back at another time.\n"); break;
  case 26..36: write("It is possible for your future to show some promise.\n"); break;
 case   37..45: write("You have a promising future.\n"); break;
  case  46..56: write("You will be revered by your peers.\n"); break;
  case  57..62: write("Your name will be a legend in these parts.\n"); break;
  case  63..80: write("Your name will be recorded in the annuls of history,you will be a
legend for all time.\n");  break;
  case  81..10001:  command("worship "+TPn); break;
    default: write("You would be lucky to survive your next battle.\n"); break;
}
TO->delete("telling");
return 1;
}