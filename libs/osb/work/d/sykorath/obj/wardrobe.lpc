// take from old nf
// updated and adapted by magictcs - 3 jul 97

#include <properties.h>
#include <moving.h>
#include <sykorath.h>

inherit "/std/container";

int is_open;

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("a wardrobe");
  SetIntLong("You are inside a wardrobe. It is quite comfortable!\n");
  SetValue(1500);
  SetNoGet("The wardrobe can't be moved.\n");
  AddId("wardrobe");
  SetMaxWeight(350000);
  SetTransparent(0);
  SetWeightChg(10);
  is_open=0;
}

//****************
// a special short
//****************
string QueryShort() {
  if (is_open)
    return "a wardrobe (open)";
  return "a wardrobe";
}

//***************
// a special long
//***************
string QueryLong() {
  if (is_open)
    return "This heavy wardrobe is open. You can look into it.\n";
  return "The wardrobe is closed.\n";
}

// look (into) wardrobe
//*********************
int l_into(string str) {
  string a;
  object safe,itm;
  if (!str) return 0;
  if (sscanf(str,"into %s",a)<1) return 0;
  safe=present(a,environment());
  if (safe!=this_object()) return 0;
  show(NAME+" looks into "+QueryShort()+".\n");
  write("Inside the wardrobe you see: \n");
  itm=first_inventory(TO);
  while (itm) {
     write(CAP(itm->QueryShort())+"\n");
     itm=next_inventory(itm);
  }
  return 1;
}

//**********************
// put something into it
//**********************
int sput(string str) {
  int test;
  string a,b;
  if (!str) return 0;
  test=sscanf(str,"%s into %s",a,b);
  if (test<1) test=sscanf(str,"%s in %s",a,b);
  if (test==2) {
     if (!id(b)) return 0;
     if (is_open) return 0;
     write("The wardrobe is closed!\n");
     return 1;
  }
  return 0;
}

//********************************
// get something from the wardrobe
//********************************
int sget(string str) {
  int test;
  string a,b;
  if (!str) return 0;
  test=sscanf(str,"%s from %s",a,b);
  if (test<1) test=sscanf(str,"%s of %s",a,b);
  if (test==2) {
     if (!id(b)) return 0;
     if (is_open) return 0;
     write("The wardrobe is closed!\n");
     return 1;
  }
  return 0;
}

//******************
// open the wardrobe
//******************
int open(string str) {
  if (!str || !id(str)) return 0;
  if (is_open) { write("It is open.\n"); return 1; }
  write("You open the wardrobe.\n");
  show(NAME+" opens a wardrobe.\n");
  is_open=1;
  return 1;
}

//*********
// close it
//*********
int close(string str) {
  if (!str || !id(str)) return 0;
  if (!is_open) { write("It is already closed!\n"); return 1; }
  write("You close the wardrobe.\n");
  show(NAME+" closes a wardrobe.\n");
  is_open=0;
  return 1;
}

//***************
// allow entering
//***************
int enter(string str) {
  if (!str || !id(str)) return 0;
  if (!is_open) { write("It is closed.\n"); return 1; }
  if (present(TP,TO)) return 0;
  TP->move(TO,M_GO);
  return 1;
}

//***************
// leave wardrobe
//***************
int leave(string str) {
  if (!str || !id(str)) return 0;
  if (!is_open) { write("It is closed.\n"); return 1; }
  if (!present(TP,TO)) return 0;
  TP->move(environment(),M_GO);
  return 1;
}

//*************
// add adctions
//*************
init() {
  ::init();
  add_action("sget","get");
  add_action("sget","take");
  add_action("sput","put");
  add_action("open","open");
  add_action("close","close");
  add_action("l_into","look");
  add_action("l_into","l");
  add_action("enter","enter");
  add_action("leave","leave");
}

