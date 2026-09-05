#include <dbase.h>
#include <move.h>
#include <ansi.h>
inherit ROOM;

int do_modify(string);
int do_modify_short( string arg);
void create()
{
     set("short",GRN""NOR);
     set("long","\n空空如也的书房\n");     
     set("exits", ([
              ]));
     set("change_name",0);
     setup();
}
void init()
{   
    add_action("do_modify","modify");
    add_action("do_modify_short","modify_short");
}

int do_modify_short( string arg)
{ if (!arg) 
  {   write("要给你的书房取个什么名字？\n");
      return 1;
  }
  if (this_player()->query("id")==this_object()->query("owner"))
  {   
      arg = replace_string(arg, "$BNK$", BNK);
      arg = replace_string(arg, "$BLK$", BLK);
      arg = replace_string(arg, "$RED$", RED);
      arg = replace_string(arg, "$GRN$", GRN);
      arg = replace_string(arg, "$YEL$", YEL);
      arg = replace_string(arg, "$BLU$", BLU);
      arg = replace_string(arg, "$MAG$", MAG);
      arg = replace_string(arg, "$CYN$", CYN);
      arg = replace_string(arg, "$WHT$", WHT);
      arg = replace_string(arg, "$HIR$", HIR);
      arg = replace_string(arg, "$HIG$", HIG);
      arg = replace_string(arg, "$HIY$", HIY);
      arg = replace_string(arg, "$HIB$", HIB);
      arg = replace_string(arg, "$HIM$", HIM);
      arg = replace_string(arg, "$HIC$", HIC);
      arg = replace_string(arg, "$HIW$", HIW);
      arg = replace_string(arg, "$NOR$", NOR);
      this_player()->set("myroom/srshort",arg+NOR);
      this_object()->set("short",arg+NOR);
      write("ok!\n");
  }
  else 
  { write("别人的房你也要搀和搀和？\n");}
  return 1;
}
int do_modify( string arg)
{ if (!arg) 
  {   write("要把你的书房修饰成什么样子呢？\n");
      return 1;
  }
  if (this_player()->query("id")==this_object()->query("owner"))
  {   
      arg = replace_string(arg, "$BNK$", BNK);
      arg = replace_string(arg, "$BLK$", BLK);
      arg = replace_string(arg, "$RED$", RED);
      arg = replace_string(arg, "$GRN$", GRN);
      arg = replace_string(arg, "$YEL$", YEL);
      arg = replace_string(arg, "$BLU$", BLU);
      arg = replace_string(arg, "$MAG$", MAG);
      arg = replace_string(arg, "$CYN$", CYN);
      arg = replace_string(arg, "$WHT$", WHT);
      arg = replace_string(arg, "$HIR$", HIR);
      arg = replace_string(arg, "$HIG$", HIG);
      arg = replace_string(arg, "$HIY$", HIY);
      arg = replace_string(arg, "$HIB$", HIB);
      arg = replace_string(arg, "$HIM$", HIM);
      arg = replace_string(arg, "$HIC$", HIC);
      arg = replace_string(arg, "$HIW$", HIW);
      arg = replace_string(arg, "$NOR$", NOR);
      this_object()->set("long","\n"+arg+NOR+"\n");  
      this_player()->set("myroom/srlong","\n"+arg+NOR+"\n");
      write("ok!\n");
  }
  else 
  { write("别人的房你也要搀和搀和？\n");}
  return 1;
}
