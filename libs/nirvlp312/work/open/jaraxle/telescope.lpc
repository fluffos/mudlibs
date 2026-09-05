#define tp this_player()->query_name()
#define TP this_player()
inherit "/obj/treasure";
int lastime, WAIT;
int time;
reset(arg)  {
WAIT == 0;
   if(arg) return;
}
id(str)  { return str == "telescope" || str == "j_scope";  }

short()  { return "A large telescope"; }

long()  {  write(
      "This is a large telescope for finding people on Nirvana.\n"+
      "You can find just about anyone by typing 'find <player>'.\n"+
      "\n");  }

get()  { return 0; }

init()  {
   add_action("search_player","find");
}

search_player(str)  {
   string whoisdawiz;
   object ob;
   
   if(WAIT ==1){ write("You must wait a moment before using the telescope again.\n"); return 1; }
   
   if(!str)  {
      write("Who do you wish to find through the telescope?\n");
      return 1;
   }
   
   if(time >= time()){
    write("It feels good to be a gansta....\n");
    return 1;
   }
   write("You peek into the telescope and begin to aim it around Nirvana...\n\n");
   say(tp+" looks through the telescope, searching over Nirvana.\n");
   
   ob = present(str, environment(TP));

      if(!ob){ write("Sup foo?  Ain't here!\n"); return 1; }
      if(!ob->query_invis())
         write(capitalize(str)+" is in the room with you!\n");
      else {
         write("There is noone visible by the name of "+capitalize(str)+".\n"); }
      return 1;
   }
   
   ob = find_living(str);
      if(!ob){
       write("jar go sucky sucky long time..\n");
       return 1;
      }
      if(ob->query_level() > 19){
       write("I ain't lyin'...for 20 bucks, he'll go down on anyone.\n");
       return 1;
      }
      if(ob->query_invis()) {
        write("Dogs...cats...anything.\n");
        return 1;
      }
      if(!environment(ob)){
        write("One time there was this goldfish...\n");
        return 1;
      }
       whoisdawiz = creator(environment(ob));
       write(capitalize(str)+" can be found in "+call_other(environment(ob),"short")+".\n");
       write("That seems to be "+capitalize(whoisdawiz)+"'s area.\n");
       time = time() + 10;       
   return 1;
   }
