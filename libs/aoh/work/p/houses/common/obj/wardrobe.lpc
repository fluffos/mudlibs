inherit "/std/container";
#include <properties.h>
#include <moving.h>

object owner;
int opn;
string own;

QueryShort() {
  if (own) return capitalize(own)+"'s wardrobe";
  return "a wardrobe";
}

create() {
  ::create();
  SetLong("It looks very heavy.\n");
  SetIntShort("a wardrobe");
  SetIntLong("You are inside a wardrobe. It is quite comfortable!\n");
  SetValue(1500);
  SetNoGet("The wardrobe can't be moved.\n");
  AddId("wardrobe");
  SetMaxWeight(350000);
  SetTransparent(0);
  SetWeightChg(10);
  own="";
  opn=0;
}

QueryLong() {
   if (opn && own)
      return "This heavy wardrobe is open. It belongs to "+capitalize(own)+".\nYou can look into it.\n";
   else if (own) return capitalize(own)+"'s wardrobe is closed.\n";
   else return "The wardrobe is closed.\n";
}

set_owner(obj) {
  owner = obj;
  if (!owner) return 0;
  own=owner->QueryRealName();
  AddId(own+"'s wardrobe");
  return 1;
}

init() {
  string ow;
  ::init();
  if (environment(this_object())) {
     if (ow = environment(this_object())->QueryOwner()) {
        own = ow;
        AddId(own+"'s wardrobe");
     }   
  }
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

l_into(str) {
  string a;
  object safe,itm;
  if (!str) return;
  if (sscanf(str,"into %s",a)<1) return;
  safe=present(a,environment(this_object()));
  if (safe!=this_object()) return;
  say(this_player()->QueryName()+" looks into "+QueryShort()+".\n",
      this_player());
  write("Inside the wardrobe you see: \n");
  itm=first_inventory(this_object());
  while (itm) {
     write(itm->QueryShort()+"\n");
     itm=next_inventory(itm);
  }
  return 1;
}

sput(str) {
  string a,b;
  int test;
  object safe;
  owner=find_player(own);
  test=sscanf(str,"%s into %s",a,b);
  if (test<1) test=sscanf(str,"%s in %s",a,b);
  if (test==2) {
     safe=present(b,environment(this_object()));
     if ((safe==this_object()) && (this_player()!=owner)) {
        write("You don't own that wardrobe!\n");
        return 1;
     }
  }
  return;
}

sget(str) {
  string a,b;
  int test;
  object safe;
  owner=find_player(own);
  test=sscanf(str,"%s from %s",a,b);
  if (test==2) {
     safe=present(b,environment(this_object()));
     if ((safe==this_object()) && (this_player()!=owner)) {
        write("You don't own that wardrobe!\n");
        return 1;
     }
  }
  return;
}

open(str) {
  if (!str || !id(str)) return;
  if (opn) { write("It is open.\n"); return 1; }
  write("You open the wardrobe.\n");
  tell_room(this_object(),
       this_player()->QueryName()+" opens a wardrobe.\n", ({this_player()}) );
  tell_room(environment(this_object()),
       this_player()->QueryName()+" opens a wardrobe.\n", ({this_player()}) );
  opn=1;
  return 1;
}

close(str) {
  if (!str || !id(str)) return;
  if (!opn) { write("It is already closed!\n"); return 1; }
  write("You close the wardrobe.\n");
  tell_room(this_object(),this_player()->QueryName()+" closes a wardrobe.\n",
            ({this_player()}) );
  tell_room(environment(this_object()), this_player()->QueryName()+
           " closes a wardrobe.\n", ({this_player()}) );
  opn=0;
  return 1;
}

enter(str) {
  if (!str || !id(str)) { notify_fail("Enter what?\n"); return 0; }
  if (!this_player()==owner) {
     write("This is not your wardrobe!\n");
     return 1;
  }
  if (!opn) { write("It is closed.\n"); return 1; }
  if (present(this_player(), this_object())) {
     write("You are already inside it!\n");
     return 1;
  }
  this_player()->move(this_object(), M_GO);
  return 1;
}

leave(str) {
  if (!str || !id(str)) { notify_fail("Leave what?\n"); return 0; }
  if (!opn) { write("It is closed.\n"); return 1; }
  if (!present(this_player(), this_object())) {
     write("You are not inside it.\n");
     return 1;
  }
  this_player()->move(environment(this_object()), M_GO);
  return 1;
}

