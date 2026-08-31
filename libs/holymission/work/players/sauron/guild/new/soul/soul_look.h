//----------------------------------------------------------------------------
// Title:						Author:
//	Monk's soul 'look'.					Sauron.
//
// File:						Started:
//	/players/sauron/guild/soul/soul_look.h		041096.
//
// Purpose:
//	This file defines the 'look' of the guild soul.
//
// History of revisions/fixes:
//
// 041096: Sauron: Started programming.
//
//----------------------------------------------------------------------------

#ifndef __GUILD_SOUL_LOOK_H__

#define __GUILD_SOUL_LOOK_H__

// Preprocessor directives:

#include "/players/sauron/guild/soul/soul_basic.h"

// End preprocessor directives.


// Prototypes:

void extra_look();
int _look(string str);
string robe_type();
string short();
void long();

// End prototypes.

void extra_look() {
  if(query_GM(query_tmp("owner")))
    printf("\n%s is fixing up the Monk's guild...\n",
           CHE(query_tmp("owner")));
  else if(query_protector(query_tmp("owner")))
    printf("\n%s is a %sprotector of the members of the Monk's guild...\n",
           CHE(query_tmp("owner")),
           (query_advanced(query_tmp("owner"))?"famous ":""));
  else if(query_advanced(query_tmp("owner")))
    printf("\n%s is famous amongst the members of the Monk's guild...\n",
           CHE(query_tmp("owner")));
  else if(APPR(query_tmp("owner")))
    printf("\n%s is a freeloader in the Monk's guild!\n",
           CHE(query_tmp("owner")));
}

int _look(string str) {
  if(str)
    sscanf(str,"at %s",str);
  if(id(str)) {
    TO->long();
    return 1;
  }
  else
    return 0;
}
  
string robe_type() {
  string weave,col,type;
  int gen,lvl,rank;
  mixed *imm_cols,*cols;
    
  gen=SEX(query_tmp("owner"));
  if(gen)
    gen--;
  lvl=LEVEL(query_tmp("owner"));
  imm_cols=({
    ({"",""}),  // Appr
    ({"",""}),  // New
    ({"",""}),  // Wiz
    ({"",""}),  // Sage
    ({"",""}),  // Elder
    ({"",""}),  // Arch
    ({"",""}),  // God
  });
  cols=({
    ({"",""}),  //  1 -  9
    ({"",""}),  // 10 - 19
    ({"",""}),  // 20 - 29
    ({"",""}),  // 30 - 39
    ({"",""}),  // 40 - 49
    ({"",""}),  // 50 - 59
    ({"",""}),  // 60 - 69
    ({"",""}),  // 70 - 79
    ({"",""}),  // 80 - 89
    ({"",""}),  // 90 - 99
  });
  
  if(query_GM(query_tmp("owner"))) {
    weave="smooth ";   
    col=(gen?"white ":"purple ");
    type="silk";
  }
  else if(APPR(query_tmp("owner"))) {
    switch(lvl) {
      case L_APPR..L_NEWWIZ-1:
        rank=0;
        break;
      case L_NEWWIZ..L_WIZ-1:
        rank=1;
        break;
      case L_WIZ..L_SAGE-1:
        rank=2;
        break;
      case L_SAGE..L_RETD-1:
        rank=3;
        break;
      case L_RETD..L_ELDER-1:
        rank=4;
        break;
      case L_ELDER..L_ARCH-1:
        rank=5;
        break;
      case L_GOD:
        rank=7;
        break;
      default:   
        rank=6;
        break; 
    }
    weave="soft ";
    col=imm_cols[rank][gen];
    type="velvet";
  }
  else if(lvl>=LVL_AD) {
    weave="soft ";
    col=cols[lvl/10][gen];  
    type="velvet";
  }
  else if(lvl>=10) {
    weave="gentle ";
    col=cols[lvl/10][gen];
    type="lambswool";
  }
  else {
    weave="harsh ";
    col="";
    type="sack-cloth";
  }
  return sprintf("%s%s%s",weave,col,type);
}
     
string short() {
  string tmp;
  if(TP==query_tmp("owner"))
    tmp="Your";
  else 
    tmp=CNAME(query_tmp("owner"))+"'s";
  return sprintf("%s robe",tmp);
}
   
void long() {
  int i,sz;
  object *a;
    
  WRITE(sprintf("%s is made from %s. On it's back you see the symbol of \
the order of the Monks of St. Benedictine.\n",short(),robe_type()));
  if(TP!=query_tmp("owner"))
    return;
  a=all_inventory(TO);
  sz=sizeof(a);
  if(sz) {
    write("Amongst it's folds you feel the following contents:\n\n");
    for(i=0;i<sz;i++)
      
printf("%s.\n",a[i]->short()?CAP(a[i]->short()):CAP(a[i]->query_name()));
  }
  else
    write("It hangs loosely at your sides.\n");
}

#endif // __GUILD_SOUL_LOOK_H__
