#include <mudlib.h>
#include "../defs.h"
int studied;
inherit OBJECT;

void create() {
  seteuid(getuid());
  set("short", "an important looking ledger");
  set("long", @ENDLONG
This is a leather bound book labeled 'Ledger' written in a strange font.
You can sense something important in the book, perhaps you should
study it more thoroughly.
ENDLONG
  );
  set("id", ({
    "book",
    "ledger",
    
  }));
  set("bulk", 50);
  set("mass", 20);
  set_value(300);
  set("armor", 0);
}
void init(){
add_action("study", "study");
}

int study(string str){
  if(!str){ write("Study what?\n");
  }
if(studied){
   write("This book's records are completely in line.\n");
   return 1;
}
if(str !="ledger" && "book"){
   write("You notice a bank error in favor of the town!  You easily change it back
and credit your own account for some extra funds.\n");
   TP->credit(200 + random(1300));
   studied = 1;
   return 1;
}
}



