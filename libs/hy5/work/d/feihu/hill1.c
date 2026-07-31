//天寒山
// by steel 

inherit ROOM;

void create()
{
	set("short", "天寒山腰");
	set("long", @LONG
	你以超乎常人的毅力爬到了半山腰。定了定神，向山下望去，只
见万里冰封，好一幅银装素裹的景象。    
LONG
	);
	
       set("exits", ([
		"northup" : __DIR__"hill2",
		"southdown" : __DIR__"hill",
	]));
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="northup")
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
