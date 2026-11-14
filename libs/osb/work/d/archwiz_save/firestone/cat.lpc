#include <properties.h>
#include <moving.h>
inherit "std/npc";

object fellow;
status fol;
string fname,cname;

create() {
  if (::create()) return 0;
  SetName("cat");
  SetShort("a cat");
  SetLong("It's a cute little fighting cat.\n");
  SetRace("cat");
  SetLevel(5);
  SetMaxHP(150);
  SetHP(100);
  SetAlign(200);
  SetHands( ({ ({"left paw",0,8}),({"right paw",0,8}) }) );
  SetAC(1);
  SetDex(10); SetStr(12);
  fol=0;
  cname="cat";
  Set(P_IS_PET, 1);
  Set("RefreshRemoveOk", 1);  // [Just for the time of hunting down offenders, Mateese]
}

catch_tell(str) {
 string a,b;
 if (sscanf(str,"%s died.",a)==1) {
    call_out("eat",3); return; }
 if (sscanf(str,"%s owns the cat.",a)==1) {
    if (fol) write("It's already owned!\n");
    if (!fol) {fellow=this_player();
	 if (fellow) {set_fellow(); write("You own it now.\n"); }
	 return 1;}
 }
 return;
}

pet(str) {
   if (str!="cat") return;
   if (fol) write("It's already owned!\n");
   if (!fol) {fellow=this_player();
	 if (fellow) {set_fellow(); write("You own it now.\n"); }
	 return 1;}
   return 1;
}

init() {
  ::init();
  add_action("hit","hit");
  add_action("hit","kick");
  add_action("name","name");
  add_action("pet","pet");
}

eat() {
 object ob;
 ob= present("corpse",environment());
 if (ob) {
    if (!fellow) return;
    show_room(environment(),add_gen(capitalize(fellow->QueryName()))+
      " cat devours the corpse.\n",({fellow}));
 tell_object(fellow,"Your cat devours the corpse.\n");
 Heal(4);
 call_other(ob,"remove");
 return 1;}
return 1;
}

set_fellow() {
 fname=capitalize(fellow->QueryRealName());
 SetFriendObj(fellow);
  SetShort(add_gen(fname)+" cat");
 SetLong("It's a cute little fighting cat.\n");
 if (!fol) {fol=1; call_out("follow",7);}
}

name(str) {
 string n;
 if (!str) return 0;
 if (sscanf(str,"cat %s",n)!=1) {return 0; }
 if (this_player()!=fellow) {notify_fail("It's not yours!\n"); return 0; }
 cname=capitalize(n);
 SetName(lower_case(n));
 AddId(n);
 SetShort(cname+" ("+fname+"'s cat)");
 AddId("cat");
 write("You name it "+cname+".\n");
 return 1;
}

follow() {
  mixed *ene,*filter;
  object ec,e;
  int i;
  ec=environment(this_object());
/* (1 line) bugfix supposed by Thragor [21Jan94]:
*/  if (!fellow) return;
  if (!living(ec) && !present(fellow)) {
  e=environment(fellow);
  move(e, M_GO, "");
  } else if (!living(ec)) {
    ene=fellow->QueryEnemies();
    filter=filter(ene,"angreifen",this_object());
  }
  call_out("follow",7);
}

angreifen(ob) {
   this_object()->Kill(ob);
   return 1;
}

hit(str) {
     if (str!=cname) return;
     write("You hit the cat to show it it's time to leave you!\n");
     fol=0; remove_call_out("follow");
     fellow=this_object();
     SetShort("A cat");
     SetLong("It's a cute little fighting cat.\n");
     return 1;
}




