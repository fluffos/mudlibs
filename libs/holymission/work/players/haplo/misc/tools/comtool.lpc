/*
 * Author    : Galadriel.
 * Date      : 15-DEC-1993.
 * Last work : 15-DEC-1993.
 * (c) YSY-SYS, the Netherlands.
 */

#define FILE    "players/galadriel/library/comtool"
#define VER     "1.8"
#define TP       this_player()
#define TO       this_object()
#define IS_ME    TP->query_real_name()=="galadriel"
#define IS_OWNER creator(TO)==TP->query_real_name()
#define NO_OWNER creator(TO)==0
#define IS_ARCH  TP->query_archwiz()
#define IS_LORD  TP->query_lord()
#define IS_WIZ   TP->query_wizard()
#define IS_NEW   TP->query_newwiz() 
#define IS_APPR  TP->query_immortal()
#define SCREEN_WIDTH 79

int mode,logmode;
string load_name,logfile;

id (str) { return str=="comtool" || str=="messenger" || str=="cc"; }

short () { return "Galadriel's messenger (v"+VER+")"; }

long ()  { 
  write("This messenger is still learning new tricks... Known tricks are:\n\n");
  printf("%-*.2#s\n",SCREEN_WIDTH,
    "fixmode  - change mode of fixer\n"+
    "fix      - the player command\n"+
    "fix <arg>- wizard commands\n"+
    "fhelp    - more help\n"
  );
  write("\n"+
  "...well thats it for today, but I keep learning!\n"+
  "If I do not function properly, please warn my boss :-)\n");
}

init_arg() {
  string tmp1,tmp2;

  if (sscanf(file_name(this_object()),"%s#%s",tmp1,tmp2)==2)
    write("Your personal fixer arrives from "+tmp1+".\n");
}

void reset(int arg) {
  if (arg) return;
  if (!IS_NEW) {
    write("error in loading, contact Galadriel (or mail)\n");
    destruct(TO);
    return;
  }
}

init () {
  string tmp1,tmp2;

  mode = 2;
  if (sscanf(file_name(this_object()),"%s#%s",tmp1,tmp2)==2) {
    load_name = tmp1+":";
  }
  add_action("do_set_mode","fixmode");
  add_action("do_fix","fix");
  add_action("do_fix_help","fhelp");
  add_action("do_send","fixsend");
  add_action("do_update","fixupdate");
}

get ()  { return 1; }  /* no get */
drop () { return 1; }
query_auto_load() { return load_name; }

void fix_chat() {
  "sys/chatd"->reset(0);
}

void fix_poison() {
  int poison;

  poison=TP->query_poisoned();
  if (mode==2) {
    write("Fi tells you: Your poison level was "+poison+".\n"+
          "The fixer cures your poison.\n"+
          "The fixer heals you.\n");
  }
  TP->add_poison(-poison);
  TP->heal_self(100000);
}

void fix_elevator(int arg) {
  object ob;

  if (!arg) {
    write("Fi tells you: This will destruct the following items:\n"+
          "/players/cashimor/rooms/sideroom\n"+
          "/players/cashimor/rooms/elevator\n"+
          "/room/wiz_hall\n"+
          "/room/attic\n"+
          "/players/cashimor/objects/wheel\n"+
          "tell me 'fix elevator all' to do all this\n");
    return;
  }
  if (ob=find_object("players/cashimor/rooms/sideroom"))
    destruct(ob);
  if (ob=find_object("players/cashimor/rooms/elevator"))
    destruct(ob);
  if (ob=find_object("room/wiz_hall"))
    destruct(ob);
  if (ob=find_object("room/attic"))
    destruct(ob);
  if (ob=find_object("players/cashimor/objects/wheel"))
    destruct(ob);
}

void fix_fixer() {
  if (mode==2)
    write("Fi tells you: I am dying, I'll send you my descendant.\n");
  TP->load_object(FILE);
  transfer(clone_object(FILE),TP);
  destruct(TO);
}

int do_fix(string arg)  {
  if (!arg) {
    if (mode==2)
      notify_fail("Fi tells you: I'll call the standard fix command.\n");
    return 0;
  }
  switch (arg) {
    case "chat"         : fix_chat();       break;
    case "poison"       : fix_poison();     break;
    case "elevator"     : fix_elevator(0);  break;
    case "elevator all" : fix_elevator(1);  break;
    case "fixer"        : fix_fixer();      break;
    default             : {
      write("Fi tells you: Sorry, but I don't know how to fix "+arg+" yet.\n");
      write("Fi sighs deeply.\n");          break;
    }
  }
  return 1;
}

int do_fix_help(string arg)  {
  string *man;
  int size_man,i;

  man=({ 
    "fixmode",
    "debug || nodebug",
    "Change mode of fixer. If you choose debug he will give you loads "+
    "of extra information while he works, if you choose nodebug he will "+
    "be a bit more quiet.",
    "fix",
    " ",
    "If you use fix with no arguments, the fixer will pass the command "+
    "to the fix routine that is already defined for players. "+
    "To see what that does use 'help fix'.",
    "fix",
    "poison",
    "Fi will analyze your poison level and cure you. If he is in "+
    "debug mode he will also tell you what your poison level was. "+
    "New: After curing the poison he will heal your wounds.",
    "fix",
    "chat",
    "Fi will patch the chat daemon, _only_ use when one of the chat "+
    "channels gives you error messages.",
    "fix",
    "elevator",
    "You will probably never need this command. It updates the "+
    "elevator in the central village church. Also all wheels and some "+
    "more rooms will be updated. All players in those rooms will be "+
    "thrown to void. Misuse of this request to Fi is not very smart.",
    "fix",
    "fixer",
    "Fi will clone you a new fixer and dispose himself.",
    "fhelp",
    " ",
    "Hmm, you should try this one to see what it does..."
  });
  size_man=sizeof(man);
  if(arg) {
    i=member_array(arg,man);
    if((i!=-1)&&(i+2<size_man))
      printf("%-10=s- %-*=s\n\n",man[i],SCREEN_WIDTH-12,"arguments: "+
             man[i+1]+"\n"+man[i+2]);
    return 1;
  }
  write("Fi tells you all about his tricks:\n");
  for(i-0;i<size_man;i+=3) {
    printf("%-10=s- %-*=s\n\n",man[i],SCREEN_WIDTH-12,"arguments: "+
           man[i+1]+"\n"+man[i+2]);
  }
  write("\n"
  +"\n"
  +"...well thats it for today, but I keep learning!\n"
  +"If I do not function properly, please warn my boss :-)\n");
  return 1;
}

int do_send (string str) {
  object new_ob, player, old_ob;
  int result;

  if (!interactive(TP)) {
    destruct(TO);
    return 1;
  }
  if (!str) return 1;
  player=find_living(str);
  if (!player) return 1;
  if (!player->query_immortal()) {
    write("The fixer tells you:'I dont want to go to a player!'\n");
    return 1;
  }
  if (old_ob=present("fixtool",player))
    destruct(old_ob);
  result=(transfer(new_ob=clone_object(FILE),player));
  if (result != 0) {
    write("The fixer tells you:'I couldnt go! errornr "+result+"'\n");
    return 1;
  }
  tell_object(player,capitalize(TP->query_real_name()) +
      " sent you '"+new_ob->short()+"'\n");
  write("You sent "+new_ob->short()+" to "+capitalize(str)+"\n");
  if (new_ob->short() != TO->short())
    TO->fix_fixer();
  return 1;
}

int do_update (string str) {
  object this_ob, player;
  int result;

  if (!interactive(TP)) {
    destruct(TO);
    return 1;
  }
  if (!str) return 1;
  player=find_living(str);
  if (!player) return 1;
  if (!player->query_immortal()&&TP->query_real_name()!="celeborn") {
    write("The fixer tells you:'I dont want to go to a player!'\n");
    return 1;
  }
  result=(transfer(clone_object(FILE),player));
  if (result != 0) {
    write("The fixer tells you:'I couldnt go! errornr "+result+"'\n");
    return 1;
  }
  write("You sent "+this_object()->short()+" to "+capitalize(str)+"\n");
  return 1;
}

int do_set_mode(string str) {
  if (!interactive(TP)) {
    destruct(TO);
    return 1;
  }
  if (!str) {
    write("The fixer tells you:'I have <debug> and <nodebug>.'\n");
  return 1;
  }
  if (str == "debug") {
    mode = 2;
    write("ok, I 'll tell you all I know *sigh*\n");
    return 1;
  }
  if (str == "nodebug") {
    mode = 1;
    write("ok, I know when I talk too much *sigh*\n");
    return 1;
  }
  write("the fixer tells you:'Sorry, I don't know that mode!'\n");
  return 1;
}

