// Room: /u/cuer/emei/shkrkou.c

inherit ROOM;

void create()
{
	set("short", "蛇窟入口");
	set("long", @LONG
这里是蛇窟的入口，你面对着一个黑暗的洞穴入口，
一阵阵阴风从里吹出来，令人不寒而栗，还是回去吧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sheku",
  "south" : __DIR__"xdao2",
]));
	set("no_clean_up", 0);

	setup();

}

int valid_leave(object me,string dir)
{object ob,obj,ob1,ob2,ob3,ob4;
 if(dir == "north" && me->query_temp("xia1") == 1)
    {message_vision("从黑暗中走出一个老妇人对$N说：“很好，你经过掌门的同意，可以进蛇窟了。”\n",me);
     if(!ob = find_object(__DIR__"sheku"))
         ob=load_object(__DIR__"sheku");
     for(;;)
       {if(obj = present("snake",ob))
           destruct(obj);
        else break;
       }
       if (sizeof(all_inventory(ob)) < 100) { 
     ob1=new(__DIR__"npc/snake");
     ob2=new(__DIR__"npc/snake");
     ob3=new(__DIR__"npc/snake");
     ob4=new(__DIR__"npc/snake");
     ob1->move(__DIR__"sheku");
     ob2->move(__DIR__"sheku");
     ob3->move(__DIR__"sheku");
     ob4->move(__DIR__"sheku");
	}
     return ::valid_leave(me,dir);
    }
 else if(dir == "north")
    
     return notify_fail("从黑暗中走出一个老妇人挡住你，说：“你没有经过掌门的同意，不能进蛇窟。”\n");
 else
  return ::valid_leave(me,dir);  
}
