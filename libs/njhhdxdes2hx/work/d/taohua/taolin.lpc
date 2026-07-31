// Room: /d/taohua/taolin.c

inherit ROOM;

void create()
{
	set("short", "桃林");
	set("long", @LONG
一片茂盛的桃林，四周密密的种着很多桃树，树上结满了桃花，往前一望，
粉红的桃花满眼都是，你感觉有点头晕了，分不清来的路了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"taijie1",
  "south" : __DIR__"haibian",
  "east"  : __DIR__"taolin",
  "west"  : __DIR__"taolin",
]));                                                  
       set("item_desc", ([
                "树": "树上的桃枝可以摘(zhai)\n",
                "tree":"树上的桃枝可以摘(zhai)\n",
           ]));
	set("no_clean_up", 0);

	setup();
	
}
int valid_leave(object me, string dir)
{          
      int i;
       
        if ((string)this_player()->query("family/family_name")!="桃花岛")
          i = 0;
        else i =20;
          i = (int)this_player()->query_skill("qimen-bagua",1)+i; 
        if (dir=="north"|| dir=="n") 
        { i=i*10-290;
        if (i<=0)
         {
	   this_player()->set_temp("noway");
           return notify_fail("北边被桃树挡住了去路\n");
          }
         if ((random(i)>8) && !(this_player()->query_temp("noway")))
         { write("你沉思一算,找到了出口\n");
 	   return ::valid_leave(me, dir);
          }
         else
          {this_player()->set_temp("noway");
           return notify_fail("北边被桃树挡住了去路\n");
          }
         }
         return ::valid_leave(me, dir);
}        


 void init()
{
        add_action("do_zhai","zhai");
}
int do_zhai(string arg)
{ object zhi,me;
  me=this_player();
  zhi=new(__DIR__"obj/taozhi");
  zhi->move(me); 
  message_vision( "\n$N将从树上摘下一条桃枝。\n",this_player());  
  return 1;
}
