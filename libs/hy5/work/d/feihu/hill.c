//天寒山
// by steel 

inherit ROOM;

void create()
{
	set("short", "天寒山下");
	set("long", @LONG
	路已到尽头,空气似乎被冻得凝固了,前方有一座山,巍峨挺拔,虽
不很险峻,但触目皆是冰碴子,要想登上似乎比登天还难。这就是极北苦寒
之地有名的天寒山。    
LONG
	);
	
       set("exits", ([
		"northup" : __DIR__"hill1",
		"southwest" : __DIR__"iceroad3",
                "east": __DIR__"iceroad4",      
	]));
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="northup"||dir=="east")
        {
         if((int)me->query_skill("dodge",1)<=70)
           {
         me->add("jing",-50);
         me->add("qi",-50);
          }
          else{
          me->add("jing",-30);
          me->add("qi",-30);
          } 
        } 
     return 1;     
}   
