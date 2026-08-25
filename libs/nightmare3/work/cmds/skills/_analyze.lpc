//Analyze spell coded by Drakken for Nightmare

#include <std.h>
 
inherit DAEMON;

mapping al_col;
 
void create() {
    ::create();

    al_col = ( ([
	"saintly" : "%^YELLOW%^",
	"righteous" : "%^BOLD%^%^WHITE%^",
	"good" : "%^BOLD%^%^WHITE%^",
	"benevolent" : "%^BOLD%^%^CYAN%^",
	"nice" : "%^RESET%^%^CYAN%^",
	"neutral" : "%^RESET%^",
	"mean" : "%^RESET%^%^ORANGE%^",
	"malevolent" : "%^RESET%^%^ORANGE%^",
	"bad" : "%^RESET%^%^RED%^",
	"evil" : "%^RESET%^%^RED%^",
	"demonic" : "%^BOLD%^%^RED%^",
    ]) );
}
 
int cmd_analyze(string str){
   string name,Class,align;
   object ob, tp;
   int calc;
   
   tp=this_player();
   Class = (string)tp->query_class();
   
   if(!str){
     notify_fail("Correct syntax: analyze [whom]\n");
     return 0;
   }
 
   if(Class != "kataan" && Class != "monk" && Class != "cleric"){
        notify_fail("You do not have the right class to cast this spell!\n");
        return 0;
   }
   calc=(int)tp->query_skill("faith");
   if(calc<15){
     notify_fail("You are not skilled enough to cast this spell!\n");
     return 0;
     }
   
   if((int)tp->query_mp()<10){
     notify_fail("You do not have the magic strength to do that right now.\n");
     return 0;
   }
 
   ob=find_living(str);
   if(!ob || !present(ob,environment(this_player()))){
     notify_fail(capitalize(str)+" is not around here.\n");
     return 0;
   }
   
   if(ob->query_ghost()){
     notify_fail("You are not able to analyze yourself at the moment right now!\n");
     return 0;
   }
 
   tp->add_mp(-10);
   if(Class == "kataan")
     message("other_action",tp->query_cap_name()+" prays to the demons of the underworld!",environment(tp),tp);
   else message("other_action",tp->query_cap_name()+" prays to the powers of the goodness!",environment(tp),tp);
 
   if(calc-random(40)<0){
     message("my_action","Its seems that your prayer was not heard!",tp);
     return 1;
   }
   tp->add_skill_points("faith",10);
   align = (string)ob->query_al_title();
   message("my_action","%^RESET%^%^CYAN%^You sense that "+ob->query_cap_name()+" has a "+al_col[align]+align+"%^RESET%^%^CYAN%^ alignment.%^RESET%^",tp);
   if (tp != ob)
       message("info","%^YELLOW%^"+tp->query_cap_name()+" mutters a prayer and tries to sense your alignment!",ob);
   return 1;
}
 
void help(){
    message("my_action","syntax: analyze [whom]\nThis spell allows the faithfull one to sense the goodness or the "
	"badness of others.",this_player());
}
