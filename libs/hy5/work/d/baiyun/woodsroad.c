 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "林中小路"); 
        set("long", @LONG 
从这里往南，地势略略向上倾斜。路两旁的茅草渐渐稀疏，灌木渐渐换成乔木， 
越走道路越开阔，再走下去显然要走到大道上去了。而莽林中令人毛骨耸然的叫声 
似乎也渐渐听不到了。 
LONG 
           ); 
        set("exits",  
           ([  
             "northdown" : "/d/manglin/edge4", 
             "south" : __DIR__"plainroad", 
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-610); 
        set("coor/z",0); 
        setup(); 
} 
int valid_leave(object who,string dir) 
{ 
        if(userp(who) && random(3)) 
          { 
           who->move(this_object()); 
           return notify_fail("");  
          } 
        return 1; 
}      
