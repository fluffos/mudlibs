inherit ROOM;

void create()
{
  set("short","练功室");
  set("long",
      "这里是白驼山弟子的练功室。有陪练童子陪你练功。\n"
  );
  
  set("exits",([
      "out" : __DIR__"fang",
  ]));
  
  set("objects",([
     __DIR__"npc/tongzi" : 1,
  ]));

  set("no_task",1);
  set("lingwu_family", "白驼山"); 
  setup();
  call_out("check_room", 15);
}

void check_room()
{
  object *inv=all_inventory();
  
  for(int lp=0;lp<sizeof(inv);lp++)
  {
    if ( userp(inv[lp]) )
    {
      call_out("check_room", 15);
      return;
    }
  }
  
  destruct(this_object());
}