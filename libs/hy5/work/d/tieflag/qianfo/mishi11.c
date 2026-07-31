 inherit ROOM;
void create()
{
  set("short","藏经阁");
  set("long",@LONG
这里只有书，各式各样的书．．．。
LONG
  );
  set("exits",([
         "south":__DIR__"yezhang.c",
               ]));
/*          set("objects", ([
                __DIR__"obj/book1" : 1,
                __DIR__"obj/book2" : 1,
                __DIR__"obj/book3" : 1,
                __DIR__"obj/book4" : 1,
                __DIR__"obj/book5" : 1, 
       ]) );*/
//      create_door("south","石门","north",DOOR_CLOSED);
        set("coor/x",51);
        set("coor/y",2110);
        set("coor/z",30);
//      set("refresh_all_items", 1);
        setup();
}  
void reset() {
        string *item= ({"book1","book2","book3","book4","book5" });
        object ob;
        
        :: reset();
        
        foreach (string x in item) 
        {
                ob = new(__DIR__"obj/"+x);
                if (present(ob,this_object())) destruct(ob);
                        else ob->move(this_object());
        }
}
