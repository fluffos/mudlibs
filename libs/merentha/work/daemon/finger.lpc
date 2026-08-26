// Petrarch
// Merentha Lib 1.0
// finger.c

#include <std.h>
inherit USER;

varargs string get_player_info(string name, int x) { 
    object ob=this_object();
    string ret, e;
    string cname, gender, _class, race, level;

    if(!file_exists("/save/users/"+name[0..0]+"/"+name+".o")) return "No such player named "+name+" in "+mud_name()+".";
    if(e=catch(
        restore_object("/save/users/"+name[0..0]+"/"+name+".o")
      )) return "Error retreaving data: "+e;

    cname=query_cap_name();
    gender=query_gender();
    _class=query_class();
    race=query_race();
    level=""+query_level();

    if(!x) x=75;
    ret=center("%^RED%^"+
      arrange_string(cname?cname:"",x/4)+
      "%^GREEN%^"+
      arrange_string(gender?gender:"",7)+
      arrange_string(race?race:"",7)+
      "%^ORANGE%^"+
      arrange_string("level "+(level?level:"1"),9)+
      arrange_string(_class?_class:"",x/4),x-4);
    call_out("remove",0);
    return border(ret,"Finger Information for "+cname, x); 
}

varargs string get_player_list(int x) { 
    object *people=users();
    string ret="";
    int i=sizeof(people);
    if(!x) x=75;
    while(i--) {
        ret+=center("%^RED%^"+
          arrange_string(people[i]->query_cap_name(),x/4)+
          "%^GREEN%^"+
          arrange_string(people[i]->query_gender(),7)+
          arrange_string(people[i]->query_race(),7)+
          "%^ORANGE%^"+
          arrange_string("level "+people[i]->query_level(),9)+
          arrange_string(people[i]->query_class(),x/4),x-4)+"\n";
    }
    return border(ret,mud_name()+" Players Online", x); 
}
