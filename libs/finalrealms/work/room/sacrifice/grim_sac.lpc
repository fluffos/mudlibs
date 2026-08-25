/* Hamlet August 1995.  Room where sacrifices occur. */
/* Generic.  shouldn't be cloned directly. */
inherit "/std/raiseroom";
#define GOD_HAND "/obj/handlers/god_handler"
#define OBJS "/baseobs/misc/"
#define ART_PATH "/baseobs/misc/gods/"

string mydeity = "nobody";               
object altar;
object bust;
int artifact_dispatched = 0;

int clean_up(int flag) { return 1; }

void set_god_here(string which) { 
  mydeity = lower_case(which); 
  if(GOD_HAND->is_deity(which)) {
    altar = clone_object(OBJS+"altar");
    altar->set_long(GOD_HAND->altar_long(which));
    altar->move(this_object());
    if(GOD_HAND->query_high_priest(which)) {
      bust = clone_object(OBJS+"bust");
      bust->subject(GOD_HAND->query_high_priest(which)[0],
                    GOD_HAND->query_high_priest(which)[3],mydeity);
      bust->move(this_object());
    }
  }
}

void setup() {
  set_short(mydeity+"'s Hall of Sacrifice");
  set_long("I would really like to be changed, please.\n");
  set_light(60);
}

void init() {
  add_action("worship","worship");
  add_action("sacrifice","sacrifice");
  add_action("bless_me","bless");
  ::init();
}

void dest_me() {
  if(altar)
    altar->dest_me();
  if(bust)
    bust->dest_me();
}

void begin_worship(string rabbit);

void worship(string who) {
  string himher;
  
  if(GOD_HAND->deity_gender(mydeity) == 1)
    himher = "him";
  else if(GOD_HAND->deity_gender(mydeity) == 2)
    himher = "her";
  else
    himher = "it";
    
  if( !who || (lower_case(who) != mydeity) ) {
    tell_object(this_player(),capitalize(mydeity)+" would be considerably "
                "more impressed if you worshipped only "+himher+" here.\n");
    return 1;
  }
  
  if( this_player()->query_deity() == mydeity ) {
    tell_object(this_player(),"You throw yourself to the floor and dedicate "
                "your life to serving "+capitalize(mydeity)+".\n");
    tell_room(environment(this_player()),this_player()->query_cap_name()+
              " bows before the altar.\n",
              ({this_player()}));
    return 1;
  }
  
  if( this_player()->query_deity() && 
      (this_player()->query_deity() != "none") ) {
    tell_object(this_player(),capitalize(this_player()->query_deity())+
                " is not likely to be impressed with you.\n");
  }
  
  if(!(GOD_HAND->race_can_worship(mydeity,this_player()->query_race()))) {
    tell_object(this_player(),capitalize(mydeity)+" does not accept your "
                "kind as followers.\n");
    return 1;
  }
  
  tell_object(this_player(),"Are you sure you wish to begin worshipping "+
              capitalize(mydeity)+"?  ");
  input_to("begin_worship",0);
  return 1;
}

void begin_worship(string rabbit) {
  if(!rabbit || rabbit == "") {
    tell_object(this_player(),"Type yes or no, please:  ");
    input_to("begin_worship",0);
    return 1;
  }  
  
  if( (lower_case(rabbit) == "yes") || (lower_case(rabbit) == "y") ) {
    if( this_player()->query_deity() && 
        (this_player()->query_deity() != "none") ) {
      tell_object(this_player(),"Thunder deafens you as lightning descends "
                                "from the sky, knocking you\nunconscious.  "
                                "When your mind returns from its voyage, "
                                "you have a splitting\nheadache and feel "
                                "extremely guilty.\n");
      tell_room(environment(this_player()),this_player()->query_cap_name()+
                " is smitten by lightning from the heavens.\n",
                ({this_player()}));
      this_player()->add_property("SWITCHED_DEITIES",time());
      GOD_HAND->remove_sacrifices(this_player());
      this_player()->set_xp(0);
      this_player()->clear_deity();
    }
    tell_object(this_player(),"Your worship of "+capitalize(mydeity)+
                " has begun.\n");
    tell_room(environment(this_player()),this_player()->query_cap_name()+
              " bows before the altar.\n",
              ({this_player()}));
    this_player()->set_deity(mydeity);
  }
  else {
    tell_object(this_player(),"Fine.  "+capitalize(mydeity)+" does "
                "not much care for you either.\n");
  }

  return 1;
}  

void sacrifice(string what) {
  string *stuff;
  int i;
  int XP = 0;
  int amt;
  int credits;
  string pr;
  
  if( !what || (what == "items") ) {
    if(!sizeof(all_inventory(altar))) {
      tell_object(this_player(),"Sacrifice what?\n");
      return 1;
    }
    /* else */
    what = "trees";
  }
  
  stuff = explode(what," ");
   
  for(i=0;i<sizeof(stuff);i++)
    if( (lower_case(stuff[i]) == "experience") || 
        (lower_case(stuff[i]) == "xp") || (lower_case(stuff[i]) == "exp") ) {
      XP = 1;
      break;
    }
    
  if(XP) {
    if(i>0) {
      sscanf(stuff[i-1],"%d",amt);
      if(amt > this_player()->query_xp())
        amt = this_player()->query_xp();
      tell_object(this_player(),"You are sacrificing "+amt+" experience.\n");
      
      GOD_HAND->sacrifice_xp(this_player(),amt,mydeity);
    }
    else {
      tell_object(this_player(),"How much?\n");
      return 1;
    }
  }
  else {
    if(what != "trees")
      this_player()->give(what+" on altar");
    credits = GOD_HAND->sacrifice_all_items(this_player(),altar,mydeity);
    
    if(!credits) 
      tell_object(this_player(),"You sense that "+capitalize(mydeity)+
                                " is unimpressed with your sacrifice.\n");
    else
      tell_object(this_player(),"You sense that "+capitalize(mydeity)+
                                " is pleased with your sacrifice.\n");
  }
  
  if(GOD_HAND->query_high_priest(mydeity) &&
     (GOD_HAND->query_high_priest(mydeity)[0] == this_player()->query_name()))
  {
    if(GOD_HAND->query_high_priest(mydeity)[3] == 2)
      pr = "priestess";
    else
      pr = "priest";
      
    tell_object(this_player(),"Hail high "+pr+" of "+capitalize(mydeity)+
                              "!  You may ask for a special item with "
                              "'bless me'.\n");
  
  }     
  return 1;
}

void bless_me(string arg) {
  string pr;
  
  notify_fail("The high priest may ask for a special item with 'bless me'.\n");
  if(!arg || (arg != "me"))
    return 0;
    
  if(this_player()->query_deity() != mydeity) {
    tell_object(this_player(),"You do not worship "+capitalize(mydeity)+"!\n");
    return 1;
  }
  
  if(GOD_HAND->query_high_priest(mydeity) &&
    (GOD_HAND->query_high_priest(mydeity)[0] != this_player()->query_name())) {
    tell_object(this_player(),capitalize(mydeity)+" does not consider you "
                "sufficiently worthy.\n");
    return 1;
  }
  
  if(artifact_dispatched) {
    tell_object(this_player(),"There is already a special item in "
                              "existence!\n");
    return 1;
  }
  
  clone_object(ART_PATH+mydeity)->move(this_player());
  
  if(GOD_HAND->query_high_priest(mydeity)[3] == 2)
    pr = "priestess";
  else
    pr = "priest";
    
  tell_object(this_player(),capitalize(mydeity)+" honors you with a gift!  "
              "Hail, brave high "+pr+".\n");
  tell_room(environment(this_player()),"The air suddenly feels charged.  "
            "You sense "+capitalize(mydeity)+"'s presence.\n",
            ({this_player()}));
  artifact_dispatched = 1;
  return 1;
}
