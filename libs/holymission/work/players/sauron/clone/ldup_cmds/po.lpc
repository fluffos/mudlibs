#include "/obj/adjust.h"
#include "/sys/levels.h"

#pragma strict_types
#pragma save_types

#define maxlvlchr   3
#define maxnamechr 10
#define maxidlechr  3
#define maxsexchr   3
#define maxguildchr 4 
#define maxracechr 10

int idlc;

string level(object ob) {
  int lv,l_lv;
  lv=(int)ob->query_level();
  l_lv=(int)ob->query_legend_level();
  if(ob->query_testchar())
    return ladjust(capitalize((string)ob->query_testchar()),maxlvlchr);
  else if(l_lv && !ob->query_immortal()) {
           if(l_lv<10)
      return radjust("L "+l_lv,maxlvlchr);
    else
      return radjust("L"+l_lv,maxlvlchr);
  }
  else
    return radjust(to_string(lv),maxlvlchr);
/*
  else {
    switch(lv) {
      case -1..L_PLAYER:
        return radjust(to_string(lv),maxlvlchr);
        break;
      case L_APPR..L_NEWWIZ-1:
        return radjust("App",maxlvlchr);
        break;
      case L_NEWWIZ..L_WIZ-1:
        return radjust("New",maxlvlchr);
        break;
      case L_WIZ..L_SAGE-1:
        return radjust("Wiz",maxlvlchr);
        break;
      case L_SAGE..L_RETD-1:
        return radjust("Sge",maxlvlchr);
        break;
      case L_RETD..L_ELDER-1:
        return radjust("Rtd",maxlvlchr);
        break;
      case L_ELDER..L_ARCH-1:
        return radjust("Eld",maxlvlchr);
        break;
      case L_ARCH..L_GOD-1:
        return radjust("Arc",maxlvlchr);
        break;
      case L_GOD:
        return radjust("God",maxlvlchr);
        break;
      default:
        return radjust("?",maxlvlchr);
        break;
    }
  }
*/
}

string idle(object ob) {
  int i,j;
  string str;
  i=query_idle(ob);
  switch(i) {
    case 0..59:
      str=" - ";
      break;
    case 60..3599:
      j=i/60;
      idlc++;
      str=sprintf("%dm",j);
      break;
    default:
      j=i/3600;
      idlc++;
      str=sprintf("%dh",j);
      break;
  }
  return str;
}

string sex(object ob) {
  if((int)ob->query_gender()==1)
    return (" m ");
  else if((int)ob->query_gender()==2)
    return (" f ");
  else
    return (" x ");
}

string guild(object ob) {
  int g;

  g=(int)ob->query_real_guild();
  return capitalize((string)"/guild/master"->query_name(g));
}

string race(object ob) {
  string r;

  r=(string)ob->query_race();
  if(!r || r=="")
    r="-";

  if((string)ob->query_real_name()=="thorm")
    return ":)";
  else
    return capitalize(r);
}

int hostsort(object p1,object p2) {
  return (query_ip_number(p1)>query_ip_number(p2));
}

int _po() {
  object *u,ob;
  int i,j,max;
  u=sort_array(users(),"hostsort",this_object());
  max=sizeof(u);
  idlc=0;
  if(max==1) {
    printf("%|'='78s\n",
           sprintf(" Holy Mission: %s ",ctime()));
    printf("%s %s Idl Sex %s %s\n",
           ladjust("Lvl",maxlvlchr),
           ladjust("Name",maxnamechr),
           ladjust("Gld",maxguildchr),
           ladjust("Race",maxracechr));
  }
  else {
    printf("%|'='78s\n",
           sprintf(" Holy Mission: %s ",ctime()));
    printf("%s %s Idl Sex %s %s %s %s Idl Sex %s %s\n",
           ladjust("Lvl",maxlvlchr),
           ladjust("Name",maxnamechr),
           ladjust("Gld",maxguildchr),
           ladjust("Race",maxracechr),
           ladjust("Lvl",maxlvlchr),
           ladjust("Name",maxnamechr),
           ladjust("Gld",maxguildchr),
           ladjust("Race",maxracechr));
  }
  printf("%|'-'78s\n","-");
  for(i=0;i<max;i+=2) {
    printf("%s %s %s %s %s %s",
           level(u[i]),
           ladjust(capitalize((string)u[i]->query_real_name()),maxnamechr),
           radjust(idle(u[i]),maxidlechr),
           sex(u[i]),
           ladjust(guild(u[i]),maxguildchr),
           ladjust(race(u[i]),maxracechr));
    if(i+1<max)
      printf(" %s %s %s %s %s %s",
             level(u[i+1]),
             ladjust(capitalize((string)u[i+1]->query_real_name()),maxnamechr),
             radjust(idle(u[i+1]),maxidlechr),
             sex(u[i+1]),
             ladjust(guild(u[i+1]),maxguildchr),
             ladjust(race(u[i+1]),maxracechr));
    write("\n");
  }
  printf("%|'='78s\n",sprintf(" %d player%s online (%d active) ",
                              max,max==1?"":"s",max-idlc));
  return 1;
}
