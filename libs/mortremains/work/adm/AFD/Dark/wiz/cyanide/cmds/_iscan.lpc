#include <mudlib.h>

inherit DAEMON;

int cmd_iscan() {
  object *list;
  int i,players,wizards;
  list=users();
  players=0;
  wizards=0;

write ("The following people are invisable:\n");
for (i=0;i<sizeof(list);i++) {
  if ((string)list[i]->query("invisible")==1) {
    write("\t"+list[i]->query("cap_name")+
      " is invisible to players only.\n");
  players=1;
    }
   }
if (players==0)
    write ("\tThere is nobody invisible to players.\n");
for (i=0;i<sizeof(list);i++) {
  if ((string)list[i]->query("invisible")==2) {
    write("\t"+list[i]->query("cap_name")+
      " is invisible to wizards.\n");
  wizards=1;
   }
}
  if (wizards==0)
    write ("\tThere is nobody invisible to wizards.\n");
return 1;
}
