 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        object con,item;
        set("short", "斩蟒台");
        set("long", @LONG 
昔年佛门高僧苦瓜大师应白云城主之邀，云游至此，行至此台不由大惊，言道此
处实乃白云岛的风水命脉所在，一旦此处有所不测，则白云城危在旦夕，白云城主沉
思数日，历时三年在此兴建了高达百丈的斩蟒台，巍峨入天。而苦瓜再游此台时，脸
色阴郁变幻，缄口不言。
LONG 
           ); 
        set("exits",  
           ([  
       "east" : __DIR__"skystreet",
            ])); 
        set("objects",  
           ([  
       __DIR__"obj/shitai" : 1,
       __DIR__"npc/kugua" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("refresh_all_items", 0);
        set("coor/x",5); 
        set("coor/y",-1800); 
        set("coor/z",20); 
        setup(); 
        con = present("shitai",this_object());
//        replace_program(ROOM); 
}
