
#define DOOR_LOCK       2
#define DOOR_CLOSE      1
#define DOOR_OPEN       0
#define NOKEY           0

int look_door(string dir,string str)
{
  object room;
  int status;
  string door;
  room = this_object();
  if (str == "door")
  {
    status = (int)room->query("door/"+dir+"/status");
    if (status == DOOR_LOCK ) 
    {
      if (!(room->query("door/"+dir+"/lock"))) door="这"+(string)room->query("door/"+dir+"/name")+"正锁着！\n";
      else door=(string)room->query("door/"+dir+"/lock");
    }
    if (status == DOOR_CLOSE) 
    {
      if (!(room->query("door/"+dir+"/lock"))) door="这"+(string)room->query("door/"+dir+"/name")+"是关着的。\n";
      else door=(string)room->query("door/"+dir+"/close");
    }
    if (status == DOOR_OPEN ) 
    {
      if (!(room->query("door/"+dir+"/lock"))) door="这"+(string)room->query("door/"+dir+"/name")+"是开着的。\n";
      else door=(string)room->query("door/"+dir+"/open");
    }  
    write (door);
    return 1;
  }
  else return 0; 
}


int open_door(string dir,string str)
{
  object room;
  int status;
  string relation,connect;
  room = this_object();
  connect  = (string)room->query("door/"+dir+"/connect");
  if ( str == "door" )
  {
    status = (int)room->query("door/"+dir+"/status");
    if (status == DOOR_LOCK ) write((string)room->query("door/"+dir+"/name")+"被锁的很紧，你无法打开它！\n");
    if (status == DOOR_OPEN ) write((string)room->query("door/"+dir+"/name")+"己经是开着的了。\n");
    if (status == DOOR_CLOSE) 
    {
      write("你把"+(string)room->query("door/"+dir+"/name")+"打开！\n");
      say (this_player()->query("name")+"把"+(string)room->query("door/"+dir+"/name")+"打开！\n");
      room->set("exits/"+dir , (string)room->query("door/"+dir+"/connect"));
      room->set("door/"+dir+"/status" , DOOR_OPEN);
      if ((room->query("door/"+dir+"/relation")))
      {
        relation = (string)room->query("door/"+dir+"/relation");
        connect->set("door/"+relation+"/status" , DOOR_OPEN);
        connect->set("exits/"+relation , (string)connect->query("door/"+relation+"/connect"));
      }
    }
    return 1;
  }
  return 0;
}

int close_door(string dir,string str)
{
  object room;
  int status;
  string relation , connect;
  room = this_object();
  relation = (string)room->query("door/"+dir+"/relation");
  connect  = (string)room->query("door/"+dir+"/connect");
  if ( str == "door" )
  {
    status = (int)room->query("door/"+dir+"/status");
    if (status == DOOR_LOCK || status == DOOR_CLOSE) 
      write((string)room->query("door/"+dir+"/name")+"早己关着了。\n");
    if (status == DOOR_OPEN ) 
    {
      write("你把"+(string)room->query("door/"+dir+"/name")+"关上。\n");
      say (this_player()->query("name")+"把"+(string)room->query("door/"+dir+"/name")+"关上。\n");
      room->delete("exits/"+dir );
      room->set("door/"+dir+"/status" , DOOR_CLOSE);
      if ((room->query("door/"+dir+"/relation")))
      {
        relation = (string)room->query("door/"+dir+"/relation");
        connect->set("door/"+relation+"/status" , DOOR_CLOSE);
        connect->delete("exits/"+relation );
      }
    }
    return 1;
  }
  return 0;
}

int lock_door(string dir,string str)
{
  object room,me,key;
  int status;
  string connect,relation;
  if (str != "door") return notify_fail("你要锁什么？\n");
  key = this_object();
  me = this_player();
  room = environment(me);
  if (!room->query("door/"+dir)) return 0;
  connect =  (string)room->query("door/"+dir+"/connect");
  status = (int)room->query("door/"+dir+"/status");
  if (status == DOOR_OPEN ) write("请先关门\n");
  if (status == DOOR_LOCK ) write("它己经上锁了！没必要锁两层吧……\n");
  if (status == DOOR_CLOSE)
  {
    if( (string)key->query("keyflag") == (string)room->query("door/"+dir+"/key") )
    {
      write((string)key->query("lock"));
      room->set("door/"+dir+"/status",DOOR_LOCK);
      if ((room->query("door/"+dir+"/relation")))
      {
        relation = (string)room->query("door/"+dir+"/relation");
        connect->set("door/"+relation+"/status" , DOOR_LOCK);
      }
      return 1;  
    }
    else
    {
      write("你的"+(string)key->query("name")+"不能把这个门上锁\n");
      return 0;
    }
  }  
}

int unlock_door (string dir,string str)
{
  object room,me,key;
  int status;
  string connect,relation;
  if (str != "door") return notify_fail("你要开什么？\n");
  key = this_object();
  me = this_player();
  room = environment(me);
  if (!room->query("door/"+dir)) return 0;
  connect =  (string)room->query("door/"+dir+"/connect");
  status = (int)room->query("door/"+dir+"/status");
  if (status == DOOR_OPEN ) write ("它己经打开啰！\n");
  if (status == DOOR_CLOSE) write ("它没上锁啊！\n");
  if (status == DOOR_LOCK )
  {
    if( (string)key->query("keyflag") == (string)room->query("door/"+dir+"/key") )
    {
      write((string)key->query("unlock"));
      room->set("door/"+dir+"/status",DOOR_CLOSE);
      if ((room->query("door/"+dir+"/relation")))
      {
        relation = (string)room->query("door/"+dir+"/relation");
        connect->set("door/"+relation+"/status" , DOOR_CLOSE);
      }
      return 1;  
    }
    else
    {
      write("你的"+(string)key->query("name")+"无法打开这个锁\n");
      return 0;
    }
  }  
}

