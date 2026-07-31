//xiaolu.c by:pipip
inherit ROOM;
void create()
{
  set("short","石头小路");
  set("long",
      "这是一条小石头铺成的小路，东边好像是通往\n"
      "玄天派的面壁间，而西边则是到玄天派黑水池子的路。\n"
    );
  set("exits",([
      "west" : "d/xuantian/chi",
      "east" : "d/xuantian/lian",    
     ]));
 setup();
}
int valid_leave(object who ,string dir)
{
 if((string)who->query("family/family_name")!="玄天派"
    &&(dir!="west"))
   return notify_fail("你不是玄天派弟子，想面壁还是回家面吧。\n");
 return 1 ;
}

