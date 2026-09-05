// room.c

#pragma save_binary

inherit F_DBASE;
inherit F_CLEAN_UP;

#include <dbase.h>
#include <room.h>
#include <map.h>

nosave mapping doors;

int query_max_encumbrance() { return 100000000000; }

varargs object make_inventory(string file, int num)
{
  object ob;

  ob = new(file);
  if(objectp(ob)) {

  if ( num>1 && ob->query_amount()>0 )
    ob->set_amount(ob->query_amount()*num);
  ob->set("startroom", base_name(this_object()));
  ob->move(this_object());
  //log_file("refresh",base_name(this_object())+" reload "+file+" at "
  //+ctime(time())+"\n");
  	}
  return ob;
}

void m_inv(string file)
{  
  object ob;

  ob = new(file);
  ob->move(this_object());
  ob->set("startroom", base_name(this_object()));
}

int exclude_reset(object ob)
{
    if (ob->query("startroom") == base_name(this_object())) return 1;
    if (ob->query("env/invisibility")) return 1;
    if (inherits(CHARACTER, ob)) 
    {
        switch (base_name(ob))
        {
        case "/d/luoyang/npc/xiaofeng":
        case "/d/luoyang/npc/xiaobanhe":
        case "/d/changbai/npc/huyidao":
        case "/clone/npc/han-yuanwai":
        case "/d/jiangzhou/npc/diaoyuren":
        case "/d/city/npc/identifier":
        case "/d/hangzhou/npc/han":
        case "/kungfu/class/murong/murongfu":
            return 0;
        default:
            return 1;
        }
    }
    if (ob->query("board_id")) return 1;
    return 0;
}

void reset()
{
  mapping ob_list, ob;
  object tem_ob,camelob;
  string *list;
  object *inv;
  int i,j;

  //
  // Check loaded objects to match the objects specified in "objects"
  // while query("objects") is 
  // ([ <object filename>: <amount>, ..... ])
  // and query_temp("objects") is
  // ([ <object filename>: ({ob1, ob2, ...}), .... ])
  //
  //log_file("refresh",base_name(this_object())+" reset at "+
  //ctime(time())+"\n");
  //
/***********
 * 似乎会引起定时更新时的lag，去掉，相应功能放到go.c里
//  inv=all_inventory();
//  if (sizeof(inv) > 100)
//  {
//    camelob = load_object("/clone/npc/camel1");
//    camelob->move(this_object());
//    camelob->init();
//  }
**************/
    switch (query("no_reset"))
    {
      case 0:
        set("no_clean_up", 0);
        break;
      case 1:
        break;
      default:
        return;
    }

    if (undefinedp(query("reset_tag"))) set("reset_tag", random(2));
    else set("reset_tag", !query("reset_tag"));

    if(query("reset_tag") && !AUTOSAVE_D->is_destnum_limit())
    {
        inv=all_inventory();
        reset_eval_cost();
        for (i=0;i<sizeof(inv);i++)
        {
            if (AUTOSAVE_D->is_dest_limit()) break;
            if (!exclude_reset(inv[i]))
            {
                if (inv[i]->query_temp("reset/times")>=1 && inv[i]->query_temp("reset/place")==this_object())
                {
                    AUTOSAVE_D->add_destnum();
                    destruct(inv[i]);
                    continue;
                }
                if (inv[i]->query_temp("reset/place")!=this_object())
                {
                    inv[i]->set_temp("reset/place", this_object());
                    inv[i]->set_temp("reset/times", 1);
                }
                else
                {
                    inv[i]->add_temp("reset/times", 1);
                }
            }
        }
    }

  if (query("no_dig")) delete("no_dig");//added by vast,让寻宝任务中挖过的房间更新
    if( query_temp("changxi")) set_temp("changxi",0);//added by vast,让唱戏任务中去过的房间更新

  ob_list = query("objects");
  if( !mapp(ob_list) ) return;
  
  if( !mapp(ob = query_temp("objects")) )
    ob = allocate_mapping(sizeof(ob_list));
/*
  for(int k=0;k<sizeof(inv);k++)
  {
    if(!userp(inv[k])&&inv[k]->query("no_clean_up")&&inv[k]->is_character())
    {
      add("no_clean_up",1);
      return;
    }
  }
*/
  
  list = keys(ob_list);
  for(i=0; i<sizeof(list); i++) {
    // Allocate an array if we have multiple same object specified.
    if(  undefinedp(ob[list[i]])
    &&  intp(ob_list[list[i]])
    &&  ob_list[list[i]] > 1 )
      ob[list[i]] = allocate(ob_list[list[i]]);

    switch(ob_list[list[i]]) {
    case 1:
      
      if( ob[list[i]] ) {
        
      if( environment(ob[list[i]]) != this_object())
        if(!ob[list[i]]->return_home(this_object()))
        {
          ob[list[i]]->delete("startroom");
          ob[list[i]] = make_inventory(list[i]);
        }
          //icer modified 
          //如果npc不return_home，则new出新的，
          //有利于丰富npc资源
                
      }  else
        ob[list[i]] = make_inventory(list[i]);
      break;
    default:
      //Jason:北侠从打鸡腿时代改到任务时代，大量的重复npc已经没有意义了。
      //以前的目的是为了让玩家有npc可以打。现在这些npc几乎没用。参与谜题，
      //门忠的npc绝大多数都是独特的，不会出现多个。而由于任务系统产生大量
      //随机npc，物品，而且导致全地图永远不cleanup，对象太多。所以在这里
      //适当减少npc数量，相应也减少了物品数量。
      if(ob_list[list[i]] > 2) ob_list[list[i]] = 2;
      for(j=0; j<ob_list[list[i]]; j++) {
        // If the object is gone, make another one.
        if( ! objectp(ob[list[i]][j]) ) {  
          ob[list[i]][j] = make_inventory(list[i], ob_list[list[i]]);
          if ( ob[list[i]][j]->query_amount()>0 )
            break;
          else
            continue;
        }
        // Try to call the wandering npc come back here.
        if( environment(ob[list[i]][j]) != this_object()) 
        {
          if(!ob[list[i]][j]->return_home(this_object()))
          {
            ob[list[i]][j]->delete("startroom");
            ob[list[i]][j] = make_inventory(list[i], ob_list[list[i]]);
            if ( ob[list[i]][j]->query_amount()>0 )
              break;
          }
              //icer modified
              //同上
        }
        else if ( ob[list[i]][j]->query_amount()>0 )
          break;
      }
    }
  }
  set_temp("objects", ob);
}

// Redirect item_desc of the door to this function in default.
string look_door(string dir)
{
  if( !mapp(doors) || undefinedp(doors[dir]) )
    return "你要看什么？\n";
  if( doors[dir]["status"] & DOOR_CLOSED )
    return "这个" + doors[dir]["name"] + "是关着的。\n";
  else
    return "这个" + doors[dir]["name"] + "是开着的。\n";
}

varargs int open_door(string dir, int from_other_side)
{
  mapping exits;
  object ob;

  if( !mapp(doors) || undefinedp(doors[dir]) )
    return notify_fail("这个方向没有门。\n");

  if( !(doors[dir]["status"] & DOOR_CLOSED) )
    return notify_fail( doors[dir]["name"] + "已经是开着的了。\n");

  exits = query("exits");
  if( !mapp(exits) || undefinedp(exits[dir]) )
    error("Room: open_door: attempt to open a door with out an exit.\n");

  if( from_other_side )
    message("vision", "有人从另一边将" + doors[dir]["name"] + "打开了。\n", this_object());
  else if( objectp(ob = find_object(exits[dir])) ) {
    if( !ob->open_door(doors[dir]["other_side_dir"], 1) ) return 0;
  }

  doors[dir]["status"] &= (!DOOR_CLOSED);
  return 1;
}

varargs int close_door(string dir, int from_other_side)
{
  mapping exits;
  object ob;

  if( !mapp(doors) || undefinedp(doors[dir]) )
    return notify_fail("这个方向没有门。\n");

  if( (doors[dir]["status"] & DOOR_CLOSED) )
    return notify_fail( doors[dir]["name"] + "已经是关着的了。\n");

  exits = query("exits");
  if( !mapp(exits) || undefinedp(exits[dir]) )
    error("Room: close_door: attempt to open a door with out an exit.\n");

  if( from_other_side )
    message("vision", "有人从另一边将" + doors[dir]["name"] + "关上了。\n", this_object());
  else if( objectp(ob = find_object(exits[dir])) ) {
    if( !ob->close_door(doors[dir]["other_side_dir"], 1) ) return 0;
  }

  doors[dir]["status"] |= DOOR_CLOSED;
  return 1;
}

int check_door(string dir, mapping door)
{
  // If we have no responding door, assume it is correct.
  if( !mapp(doors) || undefinedp(doors[dir]) ) return 1;

  door["status"] = doors[dir]["status"];
  return 1;
}

varargs void create_door(string dir, mixed data, string other_side_dir, int status)
{
  mapping d, exits, item_desc;
  object ob;

  exits = query("exits");
  if( !mapp(exits) || undefinedp(exits[dir]) )
    error("Room: create_door: attempt to create a door without exit.\n");

  // Compact mode.
  if( stringp(data) ) {
    d = allocate_mapping(4);
    d["name"] = data;
    d["id"] = ({ dir, data, "door" });
    d["other_side_dir"] = other_side_dir;
    d["status"] = status;
  } else if( mapp(data) )
    d = data;
  else
    error("Create_door: Invalid door data, string or mapping expected.\n");

  set("item_desc/" + dir, (: look_door, dir :) );

  if( objectp(ob = find_object(exits[dir])) ) {
    if( !ob->check_door(other_side_dir, d) )
      return;
  }

  if( !mapp(doors) ) doors = ([ dir: d ]);
  else doors[dir] = d;
}

mapping query_doors() { return doors; }

mixed query_door(string dir, string prop)
{
  if( !mapp(doors) || undefinedp(doors[dir]) ) return 0;
  else return doors[dir][prop];
}

int valid_leave(object me, string dir)
{              
        object room = this_object();
        object guarder;
        object *inv;
        object real=load_object("/d/parties/public/obj/real");
        mapping real_estate,*entry;
        int i;
 
  if( mapp(doors) && !undefinedp(doors[dir]) ) {
    if( doors[dir]["status"] & DOOR_CLOSED )
      return notify_fail("你必须先把" + doors[dir]["name"] + "打开！\n");
    // if ( door[dir]["status"] & DOOR_HAS_TRAP ) ....
  }  
        if (room->query("self_build_entry"))
        {
            entry=real->real_estate();
            for (i=0;i<sizeof(entry);i++)
            {
                if (base_name(room)==entry[i]["file"])
                {
                    real_estate=entry[i];
                    break;
                }
            }
            if (real_estate && dir==real_estate["entry_direction"] && me->query("id")!=real_estate["owner"])
            {
                return notify_fail("你既不是此间的主人，也不在主人允许的名单之列，还是不要去叨扰人家了。\n");
            }

        }
        if (room->query("no_fight")==1)
        {
            return 1;
        }
        inv = all_inventory(room);  
        for(i=0;i<sizeof(inv);i++)
           { 
            if( !living(inv[i]) || !interactive(inv[i]) ) continue;
      else if(inv[i] != me && inv[i]->query_temp("guards/exit") == dir )
                   {
                        if ((int)inv[i]->query_skill("dodge") > random((int)me->query_skill("dodge")*2))
                return notify_fail(inv[i]->query("name")+"正在看守"+dir+"这个方向，你无法通过！\n");  
                   }
           }                
  me->delete_temp("guards/exit");
  me->delete_temp("guards/object");
  return 1;
}

void setup()
{
  seteuid(getuid());
        this_object()->reset();
}

int isroom()
{
    return 1;
}

//返回房间的位置信息，一般来说/d目录下的二级目录就是他们的位置信息
//比如扬州城内的房间，则/d/city/就是他们的位置识别信息
//但是有些例外房间可以通过提取房间内的room_location属性来获得位置信息
string query_location()
{
  object ob=this_object();
  string *s_dirs, *s_path, rloc;

//如果房间设置了room_location属性，则房间所属区域和房间源代码文件的位置就没有任何关系
//按照room_location属性设置的位置信息走  
  if ( stringp(rloc=ob->query("room_location")) &&
       member_array(rloc, keys(ok_dir))>=0 )
    return rloc;
  
  s_dirs=explode(base_name(ob),"/");
  s_path=allocate(sizeof(s_dirs)-1);
  s_path[0]="/";
  
  for(int lp=0;lp<sizeof(s_dirs)-1;lp++)
  {
    if ( !lp )
      s_path[lp]=sprintf("%s%s/", s_path[lp], s_dirs[lp]);
    else
      s_path[lp]=sprintf("%s%s/", s_path[lp-1], s_dirs[lp]);
  }
  
  if ( s_dirs[0]=="d" )
  {
    for(int lp=sizeof(s_path)-1;lp>=0;lp--)
    {
      if ( local_belong[s_path[lp]] ) s_path[lp] = local_belong[s_path[lp]];
      if ( member_array(s_path[lp], keys(ok_dir) )>=0 )
        return s_path[lp];
    }
  }
  

  MAP_D->set_quest_reg(s_path[sizeof(s_path)-1]);
  return s_path[sizeof(s_path)-1];
}

//获得房间的区域信息，这里的区域指的是大区域，比如
//中原，长江以南，黄河以北之类
int query_region()
{
  object ob=this_object();
  string path;
  
  path=ob->query_location();
  if ( arrayp(ok_dir[path]) )
    return ok_dir[path][1];
  else
    return QUESTREG;
}

//获得房间的区域信息，这里的区域指的是大区域，比如
//中原，长江以南，黄河以北之类
int query_location_name()
{
  object ob=this_object();
  string path;
  
  path=ob->query_location();
  if ( arrayp(ok_dir[path]) )
    return ok_dir[path][0];
  else
    return MAP_D->query_quest_reg(path);
}

//获得房间的区域级别
int query_region_level()
{
  object ob=this_object();
  string path;
  
  path=ob->query_location();
  if ( arrayp(ok_dir[path]) )
    return ok_dir[path][2];
  else
    return USER_LEVEL5;
}
