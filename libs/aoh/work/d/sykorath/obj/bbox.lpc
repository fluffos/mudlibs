// a special box - made by magictcs - 11 jun 97
// can contain exactl 10 items, all items are thrown into another 'dimension'
// and have no weight then, if you carry the box

#include <properties.h>
#include <sykorath.h>

inherit "/obj/chest";

int num_items;

//*******************
// property handling:
//*******************
int QueryNumItems() { return num_items; }
int SetNumItems(int c) { num_items=c; return num_items; }

string QueryLong() {
  string ret;
  ret=
  "This black box will move all items dropped into it into another "
  "dimension. The items will become weightless in this dimension.\n";
  if (num_items<9) ret+=
    "The box will hold "+itoa(10-num_items)+" additional items.\n";
  else if(num_items==9)
    ret+="The box will hold one additional item.\n";
  else
    ret+="The box can't hold any more.\n";
  return ret;
}

//*******
// create
//*******
create() {
  ::create();
  num_items=0;
  SetIntShort("inside a black box");
  SetShort("a black box");
  SetIds(({"box"}));
  AddAdjective(({"black"}));
  SetWeightChg(0);
  SetTransparency(0);
}

//************************
// entering/leave handling
//************************
void notify_leave(object dest,int method,mixed extra) {
  num_items--;
  ::notify_leave(dest,method,extra);
}

void notify_enter(object oldenv,int method,mixed extra) {
  ::notify_enter(oldenv,method,extra);
  num_items++;
}

int allow_enter(int method,mixed extra) {
  if (num_items >= 10) return 0;
  return ::allow_enter(method,extra);
}

