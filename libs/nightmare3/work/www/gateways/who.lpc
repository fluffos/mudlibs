/*    /www/gateways/who.c
 *    from Nightmare IV
 *    who WWW gateway
 *    created by Descartes of Borg 940610
 */

#include <std.h>

inherit DAEMON;

string gateway() {
    object *people, *who;
    string ret;
    int i, maxi;

    people = filter_array(users(), "filter_people", this_object());
    ret = "<HTML><HEAD><TITLE>"+mud_name()+" Who Gateway</TITLE></HEAD>"
      "<BODY><H1>The "+sizeof(people)+" Current Members of "+mud_name()+
      "</H1><DL><DT>"+mud_name()+" Arches:<DD><DL>";
    if(!(maxi=sizeof(who=filter_array(people,"filter_admin",this_object()))))
      ret += "<DT>No admins online.";
    else for(i=0; i<maxi; i++) {
        ret += "<DT><A HREF=//nightmare.imaginary.com:1696/gateways/finger/"+
          (string)who[i]->query_name()+">"+(string)who[i]->query_title()+
          "</A>"+(query_idle(who[i]) > 60 ? "(idle)" : "");
    }
    ret += "</DL><DT>"+mud_name()+" Creators:<DD><DL>";
    if(!(maxi=sizeof(who=filter_array(people,"filter_creator",this_object()))))
      ret += "<DT>No creators online.";
    else for(i=0; i<maxi; i++) {
        ret += "<DT><A HREF=//nightmare.imaginary.com:1696/gateways/finger/"+
          (string)who[i]->query_name()+">"+(string)who[i]->query_title()+
          "</A>"+(query_idle(who[i]) > 60 ? "(idle)" : "");
    }
    ret += "</DL><DT>"+mud_name()+" High Mortals:<DD><DL>";
    if(!(maxi=sizeof(who=filter_array(people,"filter_hm",this_object()))))
      ret += "<DT>No high mortals online.";
    else for(i=0; i<maxi;i++) {
        ret += "<DT><A HREF=//nightmare.imaginary.com:1696/gateways/finger/"+
          (string)who[i]->query_name()+">"+(string)who[i]->query_title()+
          "</A>"+(query_idle(who[i]) > 60 ? "(idle)" : "");
    }
    ret += "</DL><DT>"+mud_name()+" Mortals:<DD><DL>";
    if(!(maxi=sizeof(who=filter_array(people,"filter_mortal",this_object()))))
      ret += "<DT>No mortals online.";
    else for(i=0; i<maxi; i++) {
        ret += "<DT><A HREF=//nightmare.imaginary.com:1696/gateways/finger/"+
          (string)who[i]->query_name()+">"+(string)who[i]->query_title()+
          "</A>"+(query_idle(who[i]) > 60 ? "(idle)" : "");
    }
    ret += "</DL></DL><P></BODY></HTML>";
    return ret;
}

protected int filter_people(object ob) {
    if(hiddenp(ob) || (int)ob->query_invis()) return 0;
    if(!((string)ob->query_title())) return 0;
    return 1;
}

protected int filter_admin(object ob) { return archp(ob); }

protected int filter_creator(object ob) {
    return (wizardp(ob) && !archp(ob));
}

protected int filter_hm(object ob) { return high_mortalp(ob); }

protected int filter_mortal(object ob) {
    return (!wizardp(ob) && !high_mortalp(ob));
}
