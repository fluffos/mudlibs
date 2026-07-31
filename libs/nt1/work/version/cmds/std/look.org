// look.c
// Modified by lonely for NT
// 加入移动动态小地图和战斗地图(03/17/2002)

#pragma optimize
#pragma save_binary

#include <room.h>
#include <ansi.h>
#include <combat.h>
#include <armor.h>

// flag of func:look_all_inventroy_of_room/ret_str
#define SHOW_IMMEDIATELY        0
#define RETURN_RESULT           1

inherit F_CLEAN_UP;

int look_room(object me, object env, int brief);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string look_equiped(object me, object obj, string pro);
string look_all_inventory_of_room(object me, object env, int ret_str);
string draw_map(string *dirs,mapping exits,object me);
string cdir( string dir );
string cterrain( string terrain );
string *all_exits = ({
    "east",
    "south",
    "west",
    "north",
    "eastup",
    "southup",
    "westup",
    "northup",
    "eastdown",
    "southdown",
    "westdown",
    "northdown",
    "northeast",
    "northwest",
    "southeast",
    "southwest",
    "up",
    "down",
    "enter",
    "out",
});
int abs(int x)
{
    if (x>=0) return x;
    else return -x;
}

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        object env;
        int result;
        string objid, where;

        if (! arg) result = look_room(me, environment(me), 0);
        else
        {
                if (sscanf(arg, "%s of %s", objid, where) == 2)
                {
                        if (where == "here")
                                obj = present(objid, environment(me));
                        else
                        if (where == "me")
                                obj = present(objid, me);
                        else
                        {
                                env = present(where, environment(me));
                                if (! objectp(env))
                                        return notify_fail("你要看哪里的东西？\n");
                                obj = present(objid, env);
                                if (env->is_character() && env != me)
                                {
                                        if (! objectp(obj) ||
                                            ! obj->query("equipped") &&
                                            env->query_temp("handing") != obj)
                                                return notify_fail("这人好像并没有漏出来你想看的东西啊。\n");
                                        message("vision", me->name() + "盯着你的" + obj->name() +
                                                "看了一会儿，不知道在打什么主意。\n", env);
                                        message("vision", me->name() + "盯着" + env->name() + "的" +
                                                obj->name() + "看了一会儿，不知道在打什么主意。\n",
                                                environment(me), ({ me, env }));
                                }
                        }

                        if (! obj)
                                return notify_fail("那里没有这样东西。\n");
                }        

                if( obj || (obj = present(arg, environment(me))) || (obj = present(arg, me)) )
                {
                        if( obj->is_character() && ! obj->is_corpse()) result = look_living(me, obj);
                        else result = look_item(me, obj);
                } else result = look_room_item(me, arg);
        }

        return result;
}

string clean_color(string arg)
{
        if(!arg)
                return "";
        arg = replace_string(arg, BLK, "");
        arg = replace_string(arg, RED, "");
        arg = replace_string(arg, GRN, "");
        arg = replace_string(arg, YEL, "");
        arg = replace_string(arg, BLU, "");
        arg = replace_string(arg, MAG, "");
        arg = replace_string(arg, CYN, "");
        arg = replace_string(arg, WHT, "");
        arg = replace_string(arg, HIR, "");
        arg = replace_string(arg, HIG, "");
        arg = replace_string(arg, HIY, "");
        arg = replace_string(arg, HIB, "");
        arg = replace_string(arg, HIM, "");
        arg = replace_string(arg, HIC, "");
        arg = replace_string(arg, HIW, "");
        arg = replace_string(arg, NOR, "");
        arg = replace_string(arg, BLINK,"");
        return arg;
}


int sort_exits(string str1,string str2)
{
    int i,j;
     if (strcmp(str1,"a")<0 && strcmp(str2,"a")<0){
         if (strlen(str1) < strlen(str2)) return -1;
         if (strlen(str1) == strlen(str2)) return strcmp(str1,str2);
         return 1;
     }else{
         i=member_array(str1, all_exits);
         j=member_array(str2, all_exits);
         if (i>0 && j>0) return i-j;
         else return strcmp(str1,str2);
     }
}


string look_fight(object me,object env,object * inv,mapping exits)
{
    object ot;
    int i,j;
    string str;
    str="";
    if(!me->query("env/olddisplay")) return "";//取消
    //如果玩家身上没有设置olddisplay这个参数,表示对方愿意使用现在的战斗显示.
    //反之,还是返回原来的显示.
    if (me->is_fighting())
    {
        mixed map;
        int mx,my;
        mx=env->get_matrix_x();
        my=env->get_matrix_y();
        map=allocate(mx*my);
        foreach(ot in inv)
        {
            if (ot->query_temp("map"))
            {
                if (ot->query_temp("map/x")<=mx
                &&ot->query_temp("map/x")>=1
                &&ot->query_temp("map/y")<=my
                &&ot->query_temp("map/y")>=1)
               map[ot->query_temp("map/x")-1+(ot->query_temp("map/y")-1)*mx]=ot->query("id");
            }
        }
        for(i=0;i<my;i++)
        {
        for(j=0;j<mx;j++)
        {
            if (map[i*mx+j])
            str+=sprintf(HIY"%|10.8s"NOR,map[i*mx+j]);
            else
            if (mapp(exits) && ( stringp(exits["west"]) && j==0 && abs((i+1)*2-my-1)<=1
              ||stringp(exits["east"]) && j==mx-1 && abs((i+1)*2-my-1)<=1
              ||stringp(exits["north"]) && i==0 && abs((j+1)*2-mx-1)<=1
              ||stringp(exits["south"]) && i==my-1 && abs((j+1)*2-mx-1)<=1
              ||stringp(exits["southeast"]) && i==my-1 && j==mx-1
              ||stringp(exits["southwest"]) && i==my-1 && j==0
              ||stringp(exits["northeast"]) && i==0 && j==mx-1
              ||stringp(exits["northwest"]) && i==0 && j==0
              ))
                str+=sprintf(HIG"%|10s"NOR,"出口");
            else
            str+=sprintf(HIR"%|10s"NOR,"--");
        }
        str+="\n";
        }
    }
    //printf("\e[256D%s>" NOR, ctime(time())[11..18]);
        
    return str;
}

int look_room(object me, object env, int brief)
{
        int i;
        object *inv;
        object obj,room;
        mapping buffo = ([]), buffobj = ([]);
        string bfile, stt;
        object ot;
        mapping exits,my;
        string str, *dirs,str2;

        if( !env ) {
                tell_object(me, "你的四周灰蒙蒙地一片，什么也没有。\n");
                return 1;
        }

        if(env->query("outdoors",1))
                str2 = NOR+HIC"室外"NOR;
        if(!env->query("outdoors",1))
                str2 = NOR+HIC"室内"NOR;
        if( !brief )
        {
          str = sprintf( HIC"〖"HIW"%s"HIC"〗　%s-"HIR"%s"
                        +NOR RED+"%s\n"+NOR+"    %s%s",
          env->query("short"),str2,
          cterrain( (string)env->query("terrain") ),
                        wizardp(me)? " - " + file_name(env): "",
          env->query("long"),
                        env->query("outdoors") ? NATURE_D->outdoor_room_description() : "");
         }else
             {
              str = sprintf( HIC"〖"HIW"%s"HIC"〗　%s-"HIR"%s" +NOR RED+"%s\n"+NOR,
              env->query("short"),str2,cterrain( (string)env->query("terrain") ),
                        wizardp(me)? " - " + file_name(env): "");
        }

        if (mapp(exits = env->query("exits")))
	{
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
                        if ((int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });
                if (sizeof(dirs) == 0)
                        str += "    这里没有任何明显的出路。\n";
/*
                else if (sizeof(dirs) == 1)
                        str += "    这里唯一的出口是 " + BOLD +
			       dirs[0] + NOR + "。\n";
*/
                else {
                      if( wizardp(me) ) {
                        str +=NOR"　　这里的出口有：\n";
                        for (i=0;i<sizeof(dirs);i++){
                        if (!room=find_object(exits[dirs[i]]))
                           room=load_object(exits[dirs[i]]);
                           str+=sprintf(BOLD"　　%-12s"+NOR+YEL+" --> "+CYN+"%-10s"
                           +RED+"%s.c\n"+NOR,cdir( dirs[i] ),room->query("short"),exits[dirs[i]]);
                           }
                       }
                     if(!wizardp(me)&&!me->is_fighting() ) {
                       str +=NOR"　　这里的出口有：";
                       for (i=0;i<sizeof(dirs);i++)
                       str += HIW+dirs[i]+"  "NOR;
                       str += "\n"NOR;
//                       if( !brief && !this_player()->query("env/no_map") )
//                       str+=draw_map(dirs,exits,env);
                     }
                }
        }

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) 
        {
                if( inv[i]==me ) continue;
                if( inv[i]->query("no_shown")) continue;
                if( !me->visible(inv[i]) ) continue;
                if (userp(inv[i]))
                {
                        str +="    "+inv[i]->short()+"\n";
                        continue;
                }
                bfile=base_name(inv[i])+"-$-"+inv[i]->short();
                if ( member_array(bfile,keys(buffo)) == -1 )
                {
                        buffo[bfile]=1;
                        buffobj[bfile]=inv[i];
                }
                else 
                        buffo[bfile]+=1;
                
        }
        
        for (i=0 ; i <sizeof(keys(buffo)); i ++)
        {
                stt = keys(buffo)[i];
                ot = buffobj[stt];
                if ( !objectp(ot) )  continue;
                if ( ot ->query("combined_item") != 1 && buffo[stt] > 1 )
                     str+=sprintf("    %s%s",chinese_number(buffo[stt]),
                     !ot->query("unit")?"个":ot->query("unit"))+ot->short()+"\n";
                else str +="    "+ot->short()+"\n";
        }
        str+=look_fight(me,env,inv,exits);

//        str += look_all_inventory_of_room(me, env, RETURN_RESULT);
        tell_object(me, str);
        
        if (!me->query("env/brief")&&!me->is_fighting()&&!me->query("env/no_map"))
        {
        if( mapp(exits =env->query("exits")) ) {
        dirs=keys(exits);
        for(i=0; i<sizeof(dirs); i++)
                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });
        if (sizeof(dirs)!=0)
        {
          write(SAVEC);

          write(SETDISPLAY(7,0)+DELLINE);
          write(SETDISPLAY(1,0)+DELLINE);
          write(SETDISPLAY(2,0)+DELLINE);
          write(SETDISPLAY(3,0)+DELLINE);
          write(SETDISPLAY(4,0)+DELLINE);
          write(SETDISPLAY(5,0)+DELLINE);
          write(SETDISPLAY(6,0)+DELLINE);
          
          write(SETDISPLAY(4,70)+HIR+clean_color(env->query("short"))+NOR);
          for (i=0;i<sizeof(dirs);i++)
          switch(dirs[i])     {
          case "north":
                 write(SETDISPLAY(3,72)+"│");
                 room=load_object(exits["north"]);
                 write(SETDISPLAY(2,70)+clean_color(room->query("short")));
                 break;
          case "up":
                 write(SETDISPLAY(3,72)+"│");
                 room=load_object(exits["up"]);
                 write(SETDISPLAY(2,70)+clean_color(room->query("short")));
                 break;
          case "down":
                 write(SETDISPLAY(5,72)+"│");
                 room=load_object(exits["down"]);
                 write(SETDISPLAY(6,70)+clean_color(room->query("short")));
                 break;
          case "south":
                 write(SETDISPLAY(5,72)+"│");
                 room=load_object(exits["south"]);
                 write(SETDISPLAY(6,70)+clean_color(room->query("short")));
                 break;
          case "east":
                 room=load_object(exits["east"]);
                 write(SETDISPLAY(4,80)+clean_color(room->query("short")));
                 write(SETDISPLAY(4,78)+"─");
                 break;
          case "west":
                 room=load_object(exits["west"]);
                 write(SETDISPLAY(4,60)+clean_color(room->query("short")));
                 write(SETDISPLAY(4,68)+"─");
                 break;

          case "westup":
                 room=load_object(exits["westup"]);
                 write(SETDISPLAY(4,60)+clean_color(room->query("short")));
                 write(SETDISPLAY(4,68)+"←");
                 break;
          case "eastup":
                 room=load_object(exits["eastup"]);
                 write(SETDISPLAY(4,80)+clean_color(room->query("short")));
                 write(SETDISPLAY(4,78)+"→");
                 break;
          case "northup":
                 write(SETDISPLAY(3,72)+"↑");
                 room=load_object(exits["northup"]);
                 write(SETDISPLAY(2,70)+clean_color(room->query("short")));
                 break;
          case "southup":
                 write(SETDISPLAY(5,72)+"↓");
                 room=load_object(exits["southup"]);
                 write(SETDISPLAY(6,70)+clean_color(room->query("short")));
                 break;
          case "southdown":
                 write(SETDISPLAY(5,72)+" ↑ ");
                 room=load_object(exits["southdown"]);
                 write(SETDISPLAY(6,70)+clean_color(room->query("short")));
                 break;
          case "northdown":
                 write(SETDISPLAY(3,72)+" ↓ ");
                 room=load_object(exits["northdown"]);
                 write(SETDISPLAY(2,70)+clean_color(room->query("short")));
                 break;
          case "eastdown":
                 room=load_object(exits["eastdown"]);
                 write(SETDISPLAY(4,80)+clean_color(room->query("short")));
                 write(SETDISPLAY(4,78)+"←");
                 break;
          case "westdown":
                 room=load_object(exits["westdown"]);
                 write(SETDISPLAY(4,60)+clean_color(room->query("short")));
                 write(SETDISPLAY(4,68)+"→");
                 break;
          case "northwest":
                 write(SETDISPLAY(3,68)+"＼");
                 room=load_object(exits["northwest"]);
                 write(SETDISPLAY(2,60)+clean_color(room->query("short")));
                 break;
          case "southwest":

                 write(SETDISPLAY(5,68)+"／");
                 room=load_object(exits["southwest"]);
                 write(SETDISPLAY(6,60)+clean_color(room->query("short")));
                 break;
          case "northeast":
                 write(SETDISPLAY(3,76)+"／");
                 room=load_object(exits["northeast"]);
                 write(SETDISPLAY(2,80)+clean_color(room->query("short")));
                 break;
          case "southeast":
                 write(SETDISPLAY(5,76)+"＼");
                 room=load_object(exits["southeast"]);
                 write(SETDISPLAY(6,80)+clean_color(room->query("short")));
                 break;
           }
         
          write(SETDISPLAY(1,58)+"┏━━━━━━━━━━━━━━┓");
          write(SETDISPLAY(2,58)+"┃");
          write(SETDISPLAY(3,58)+"┃");
          write(SETDISPLAY(4,58)+"┃");
          write(SETDISPLAY(5,58)+"┃");
          write(SETDISPLAY(6,58)+"┃");
          write(SETDISPLAY(7,58)+"┗━━━━━━━━━━━━━━┛");
          write(SETDISPLAY(2,88)+"┃");
          write(SETDISPLAY(3,88)+"┃");
          write(SETDISPLAY(4,88)+"┃");
          write(SETDISPLAY(5,88)+"┃");
          write(SETDISPLAY(6,88)+"┃");
          
          write(REST);
        }
        }
        }
        return 1;
}

string draw_map(string *dirs,mapping exits,object env)
{
      string str="";
      object room;
      string dir1="",dir2="",dir3="",dir4="",
                  dir5="",dir6="",dir7="",dir8="";
      string sign1="",sign2="",sign3="",sign4="",
                  sign5="",sign6="",sign7="",sign8=""; 

      if( member_array("northwest",dirs)!=-1 )
      {
       if (!room=find_object(exits["northwest"]))
                   room=load_object(exits["northwest"]);
       if (room)
                   dir1=clean_color(room->query("short"));
              else
                   dir1=RED"没有正常出口。"NOR;

       sign1=HIW"\\"NOR;
      }
      if( member_array("up",dirs)!=-1 )
      {
       if (!room=find_object(exits["up"]))
                   room=load_object(exits["up"]);
       if (room)
                   dir2=clean_color(room->query("short"));
              else
                   dir2=RED"没有正常出口。"NOR;

       sign2=HIW"|"NOR;
      }
      if( member_array("northup",dirs)!=-1 )
      {
       if (!room=find_object(exits["northup"]))
                   room=load_object(exits["northup"]);
       if (room)
                   dir2=clean_color(room->query("short"));
              else
                   dir2=RED"没有正常出口。"NOR;

       sign2=HIW"|"NOR;
      }
      if( member_array("northdown",dirs)!=-1 )
      {
       if (!room=find_object(exits["northdown"]))
                   room=load_object(exits["northdown"]);
       if (room)
                   dir2=clean_color(room->query("short"));
              else
                   dir2=RED"没有正常出口。"NOR;

       sign2=HIW"|"NOR;
      }                   
      if( member_array("north",dirs)!=-1 )
      {
       if (!room=find_object(exits["north"]))
                   room=load_object(exits["north"]);
       if (room)
                   dir2=clean_color(room->query("short"));                  
              else
                   dir2=RED"没有正常出口。"NOR;

       sign2=HIW"|"NOR;
      }
      if( member_array("northeast",dirs)!=-1 )
      {
       if (!room=find_object(exits["northeast"]))
                   room=load_object(exits["northeast"]);
       if (room)
                   dir3=clean_color(room->query("short"));
              else
                   dir3=RED"没有正常出口。"NOR;

       sign3=HIW"/"NOR;
      }
      if( member_array("out",dirs)!=-1 )
      {
       if (!room=find_object(exits["out"]))
                   room=load_object(exits["out"]);
       if (room)
                   dir4=clean_color(room->query("short"));
              else
                   dir4=RED"没有正常出口。"NOR;

       sign4=HIW"—"NOR;       
      }
      if( member_array("westup",dirs)!=-1 )
      {
       if (!room=find_object(exits["westup"]))
                   room=load_object(exits["westup"]);
       if (room)
                   dir4=clean_color(room->query("short"));
              else
                   dir4=RED"没有正常出口。"NOR;

       sign4=HIW"—"NOR;
      }
      if( member_array("westdown",dirs)!=-1 )
      {
       if (!room=find_object(exits["westdown"]))
                   room=load_object(exits["westdown"]);
       if (room)
                   dir4=clean_color(room->query("short"));
              else
                   dir4=RED"没有正常出口。"NOR;

       sign4=HIW"—"NOR;
      }
      if( member_array("west",dirs)!=-1 )
      {
       if (!room=find_object(exits["west"]))
                   room=load_object(exits["west"]);
       if (room)
                   dir4=clean_color(room->query("short"));
              else
                   dir4=RED"没有正常出口。"NOR;

       sign4=HIW"—"NOR;
      }
      if( member_array("enter",dirs)!=-1 )
      {
       if (!room=find_object(exits["enter"]))
                   room=load_object(exits["enter"]);
       if (room)
                   dir5=clean_color(room->query("short"));
              else
                   dir5=RED"没有正常出口。"NOR;

       sign5=HIW"—"NOR;
      }
      if( member_array("eastup",dirs)!=-1 )
      {
       if (!room=find_object(exits["eastup"]))
                   room=load_object(exits["eastup"]);
       if (room)
                   dir5=clean_color(room->query("short"));
              else
                   dir5=RED"没有正常出口。"NOR;

       sign5=HIW"—"NOR;
      }
      if( member_array("eastdown",dirs)!=-1 )
      {
       if (!room=find_object(exits["eastdown"]))
                   room=load_object(exits["eastdown"]);
       if (room)
                   dir5=clean_color(room->query("short"));
              else
                   dir5=RED"没有正常出口。"NOR;

       sign5=HIW"—"NOR;
      }                   
      if( member_array("east",dirs)!=-1 )
      {
       if (!room=find_object(exits["east"]))
                   room=load_object(exits["east"]);
       if (room)
                   dir5=clean_color(room->query("short"));
              else
                   dir5=RED"没有正常出口。"NOR;

       sign5=HIW"—"NOR;
      }
      if( member_array("southwest",dirs)!=-1 )
      {
       if (!room=find_object(exits["southwest"]))
                   room=load_object(exits["southwest"]);
       if (room)
                   dir6=clean_color(room->query("short"));
              else
                   dir6=RED"没有正常出口。"NOR;

       sign6=HIW"/"NOR;
      }
      if( member_array("down",dirs)!=-1 )
      {
       if (!room=find_object(exits["down"]))
                   room=load_object(exits["down"]);
       if (room)
                   dir7=clean_color(room->query("short"));
              else
                   dir7=RED"没有正常出口。"NOR;

       sign7=HIW"|"NOR;
      } 
      if( member_array("southup",dirs)!=-1 )
      {
       if (!room=find_object(exits["southup"]))
                   room=load_object(exits["southup"]);
       if (room)
                   dir7=clean_color(room->query("short"));
              else
                   dir7=RED"没有正常出口。"NOR;

       sign7=HIW"|"NOR;
      }
      if( member_array("southdown",dirs)!=-1 )
      {
       if (!room=find_object(exits["southdown"]))
                   room=load_object(exits["southdown"]);
       if (room)
                   dir7=clean_color(room->query("short"));
              else
                   dir7=RED"没有正常出口。"NOR;

       sign7=HIW"|"NOR;
      }
      if( member_array("south",dirs)!=-1 )
      {
       if (!room=find_object(exits["south"]))
                   room=load_object(exits["south"]);
       if (room)
                   dir7=clean_color(room->query("short"));
              else
                   dir7=RED"没有正常出口。"NOR;

       sign7=HIW"|"NOR;
      }
      if( member_array("southeast",dirs)!=-1 )
      {
       if (!room=find_object(exits["southeast"]))
                   room=load_object(exits["southeast"]);
       if (room)
                   dir8=clean_color(room->query("short"));
              else
                   dir8=RED"没有正常出口。"NOR;

       sign8=HIW"\\"NOR;
      }


     str = sprintf("        %s"HIG"%-12s"NOR, str, dir1);
     str = sprintf("%s   "HIG"%-12s"NOR, str, dir2);
     str = sprintf("%s   "HIG"%-12s\n"NOR, str, dir3);
     str = sprintf("%s                   %-2s", str, sign1);
     str = sprintf("%s     %-2s", str, sign2);
     str = sprintf("%s       %-2s\n", str, sign3);
     str = sprintf("%s        "HIG"%-12s"NOR, str, dir4);
     str = sprintf("%s%-2s", str, sign4);
     str = sprintf("%s "HIR"%-12s"NOR, str,env->query("short")); 
     str = sprintf("%s%-2s", str,sign5);
     str = sprintf("%s  "HIG"%-12s\n"NOR, str,dir5);
     str = sprintf("%s                   %-2s", str, sign6);
     str = sprintf("%s     %-2s", str, sign7);
     str = sprintf("%s       %-2s\n", str, sign8);
     str = sprintf("%s        "HIG"%-12s"NOR, str, dir6);
     str = sprintf("%s   "HIG"%-12s"NOR, str, dir7);
     str = sprintf("%s   "HIG"%-12s\n"NOR, str, dir8);

     return str;
}

string desc_of_objects(object *obs)
{
        int i;
        object ob;

        string  str;
        string  ustr;
        mapping count;
        mapping unit;
        string  short_name;
        string  *dk;

        if (obs && sizeof(obs) > 0)
        {
                str = "";
                count   = ([]);
                unit    = ([]);
    
                foreach (ob in obs)
                {
                        short_name = ob->short();
                        if (undefinedp(count[short_name]))
                        {
                                if (ob->query_amount() > 1)
                                        ustr = "批";
                                else
                                        ustr = ob->query("unit");
                                count += ([ short_name : 1 ]);
                                unit += ([ short_name : ustr ]);
                        }
                        else
                                count[short_name] += 1;
                }
    
                dk = sort_array(keys(count), 1);
                for (i = 0; i < sizeof(dk); i++)
                {
                        str += "  ";
                        if (count[dk[i]] > 1)
                                str += chinese_number(count[dk[i]]) + unit[dk[i]];
                        str += dk[i] + "\n";
                }
                return str;
        }

        return "";
}

string look_all_inventory_of_room(object me, object env, int ret_str)
{
        object *inv;
        object *obs;

        string  str;

        if (! env || ! me) return "";

        str = "";

        inv = all_inventory(env);
        if (! sizeof(inv)) return str;

        obs = filter_array(inv, (: $(me) != $1 && userp($1) && $(me)->visible($1) :));
        str += desc_of_objects(obs);

        obs = filter_array(inv, (: $(me) != $1 && ! userp($1) && $1->is_character() &&
                                   $(me)->visible($1) :));
        str += desc_of_objects(obs);

        obs = filter_array(inv, (: ! $1->is_character() :), me);
        str += desc_of_objects(obs);

        if (! ret_str)
                tell_object(me, str);

        return str;
}

int look_item(object me, object obj)
{
        object hob;
        mixed *inv;
        mapping count;
        mapping equiped;
        mapping unit;
        string short_name;

        string str;
        string *dk;
        int i;

        count   = ([]);
        unit    = ([]);
        equiped = ([]);

        str = obj->long();
        while (mapp(obj->query_temp("daub")))
        {
                if (! obj->query_temp("daub/poison/remain"))
                        // no poison remain now
                        break;

                if (obj->query_temp("daub/poison/id") == me->query("id"))
                {
                        str += HIG "你发现这上面还有你炼制的" +
                               obj->query_temp("daub/poison/name") +
                               HIG "呢。\n" NOR;
                        break;
                }

                if (obj->query_temp("daub/who_id") == me->query("id"))
                {
                        str += HIG "这上面还有你亲手布下的" +
                               obj->query_temp("daub/poison/name") +
                               HIG "呢。\n" NOR;
                        break;
                }

                if (random(4) && random((int)me->query_skill("poison", 1)) < 30)
                        // nothing was worked out
                        break;

                str += HIG "忽然间你发现上面似乎泛着一些奇异荧光";
                if (me->query_skill("poison", 1) >= 120)
                {
                        str += "，可能是" + obj->query_temp("daub/poison/name");
                }

                str += "。\n" NOR;
                break;
        }

        if (obj->query("consistence"))
                str += sprintf("耐久度：" WHT "%d%%\n" NOR, obj->query("consistence"));

        inv = all_inventory(obj);
        if (! sizeof(inv))
        {
                message("vision", str, me);
                return 1;
        }

        if (obj->is_corpse())
        {
                if (objectp(hob = obj->query_temp("handing")))
                {
                        if (hob->query_amount())
                                str += "手中还死死握着一" + hob->query("base_unit") +
                                       hob->name() + "，";
                        else
                                str += "手中还死死握着一" + hob->query("unit") +
                                       hob->name() + "，";
                        inv -= ({ hob });
                        if (! sizeof(inv))
                                str += "没有什么其他遗物了。\n";
                        else
                                str += "里面的遗物有：\n";
                } else
                        str += "里面的遗物有：\n";
        } else
                str += "里面有：\n";

        for (i = 0; i < sizeof(inv); i++)
        {
                short_name = inv[i]->short();
                if (undefinedp(count[short_name]))
                {
                        count += ([ short_name : 1 ]);
                        unit += ([ short_name : inv[i]->query("unit") ]);
                }
                else
                        count[short_name] += 1;

                if (inv[i]->query("equipped"))
                        equiped[short_name] = 1;
        }

        dk = keys(count);
        dk = sort_array(dk, 1);
        for (i = 0; i < sizeof(dk); i++)
        {
            if (equiped[dk[i]])
                str += HIC "  □" NOR;
            else
                str += "    ";

            if (count[dk[i]] > 1)
                str += chinese_number(count[dk[i]]) + unit[dk[i]];
            str += dk[i] + "\n";
        }

        if (strlen(str) > 4096)
                me->start_more(str);
        else
                message("vision", str, me);
        return 1;
}

string look_equiped(object me, object obj, string pro)
{
        mixed *inv;
        string str;
        string subs;
        object hob;
        int i;
        int n;

        inv = all_inventory(obj);
        n = 0;

        str = "";
        subs = "";
        for (i = 0; i < sizeof(inv); i++)
        {
                switch (inv[i]->query("equipped"))
                {
                case "wielded":
                        n++;
                        subs = HIC "  □" NOR + inv[i]->short() + "\n" + subs;
                        break;

                case "worn":
                        n++;
                        subs += HIC "  □" NOR + inv[i]->short() + "\n";
                        break;

                default:
                        break;
                }
        }

        if (n)
                str += pro + "装备着：\n" + subs;

        if (objectp(hob = obj->query_temp("handing")) &&
            (me == obj || obj->query_weight() > 200))
        {
                int mad;

                // dress nothing but handing a cloth !
                mad = (! objectp(obj->query_temp("armor/cloth")) &&
                       hob->query("armor_type") == "cloth");

                str = pro + "手中" + (mad ? "却" : "" ) + "握着一" +
                      (hob->query_amount() ? hob->query("base_unit")
                                           : hob->query("unit")) +
                      hob->name() +
                      (mad ? "，疯了，一定是疯了！\n" : "。\n") + str;
        }

        if (playerp(obj) &&
            ! objectp(obj->query_temp("armor/cloth")))
        {
                str = pro + "身上没有穿衣服啊！\n" + str;
        }

        return str;
}

string description(object obj)
{
        if (playerp(obj))
        {
            int per;
            int age;
            per = obj->query_per();
            age = obj->query("age");
            if (obj->query("special_skill/youth")) age = 14;
            if ((string) obj->query("gender") == "男性" || (string) obj->query("gender") == "无性")
            {
                    if (per >= 30) return "长得宛如玉树临风，风流倜傥，顾盼之间，神采飞扬。真正是人中龙凤！\n";
                    if (per >= 26) return "英俊潇洒，气宇轩昂，风度翩翩，面目俊朗，貌似潘安。\n";
                    if (per >= 22) return "相貌英俊，仪表堂堂。骨格清奇，丰姿非俗。\n";
                    if (per >= 18) return "五官端正。\n";
                    if (per >= 15) return "相貌平平。没什么好看的。\n";
                                   return "长得... 有点对不住别人。\n";
            } else
            {
                    if (per >= 30) return "有倾国倾城之貌，容色丽郁，娇艳绝伦，堪称人间仙子！\n长发如云，肌肤胜雪，风华绝代，不知倾倒了多少英雄豪杰。\n";
                    if (per >= 28) return "清丽绝俗，风姿动人。有沉鱼落雁之容，避月羞花之貌！\n俏脸生春，妙目含情，顾盼神飞，轻轻一笑，不觉让人怦然心动。\n";
                    if (per >= 26) return "肤如凝脂，眉目如画，风情万种，楚楚动人。当真是我见犹怜！\n";
                    if (per >= 24) return "容色秀丽，面带晕红，眼含秋波。举手投足之间，确有一番风韵。\n";
                    if (per >= 21) return "气质高雅，面目姣好，虽算不上绝世佳人，也颇有几份姿色。\n";
                    if (per >= 18) return "相貌平平，还看得过去。\n";
                    if (per >= 15) return "的相貌嘛... 马马虎虎吧。\n";
                                   return "长得和无盐有点相似耶。\n";
            }
        } else
        if (! obj->query("can_speak") && living(obj))
        {
                if (! obj->query_temp("owner"))
                        return "是一只未被驯服的畜生，眼光里满是戒心和敌意。\n";
                else
                        return "是一只被" + obj->query_temp("owner_name") +
                               "驯服的畜生，一副很温驯的样子。\n";
        }

        return "";
}

int look_living(object me, object obj)
{
        int per;
        int spi;
        int age;
        int weight;
        string str, limb_status, pro, desc;
        mixed *inv;
        mapping my_fam, fam;
        int me_shen, obj_shen;

        obj_shen = (int)obj->query("shen");
        per = obj->query_per();
        age = obj->query("age");
        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

        if (playerp(obj) && ! (obj->query("born")))
        {
                tell_object(me, pro + "还没有投胎，只有一股元神，什么都看不到耶！\n");
                return 1;
        }

        me_shen = (int)me->query("shen");
        if (me != obj)
	{
                message("vision", me->name() + "正盯著你看，不知道在打"
			"什么主意。\n", obj);
		message("vision", me->name() + "盯着" + obj->name() +
			"看了一会儿，不知道在打什么主意。\n", 
			environment(me), ({ me, obj }));
	}

        str = obj->long();
        if (me != obj && objectp(obj->query_temp("is_riding")))
                str += sprintf("%s正骑在%s上，低头看着你。\n", pro, obj->query_temp("is_riding")->name());

        if (obj->is_character() &&
            obj->query("can_speak"))
        {
                // 是人物角色
                if (age >= 25 && obj->query("special_skill/youth"))
                        str += pro + "看不出年纪的大小，好像只有二十多岁。\n";
                else
                {
                        if (age >= 200)
                                str += pro + "看起来年纪很大了，难以估计。\n";
                        else
                        if (age < 10)
                                str += pro + "看起来年纪尚幼。\n";
                        else
                                str += pro + "看起来有" + chinese_number(age / 10 * 10) +
                                       "多岁。\n";
                }
        }

        desc = description(obj);
        if (desc && desc != "")
                str += pro + desc;

        //check about wife and husband
        if (obj->query("id")== me->query("couple/id"))
        {
                // 夫妻关系
                if ((string)me->query("gender") == "女性")
                        str += sprintf("%s就是你的夫君。\n", pro);
                else
                        str += sprintf("%s就是你的妻子。\n", pro);
        } else
        if (obj->is_brother(me))
        {
                // 兄弟
                if (obj->query("gender") == "女性")
                {
                        if (obj->query("mud_age") > me->query("mud_age"))
                                str += sprintf("%s是你的义姐。\n", pro);
                        else
                                str += sprintf("%s是你的结义妹子。\n", pro);
                } else
                {
                        if (obj->query("mud_age") > me->query("mud_age"))
                                str += sprintf("%s是你的结义兄长。\n", pro);
                        else
                                str += sprintf("%s是你的义弟。\n", pro);
                }
        } else
        if (obj != me && obj->query("league") &&
            obj->query("league/league_name") == me->query("league/league_name"))
        {
                str += sprintf("%s和你均是%s的同盟义士。\n", pro,
                               obj->query("league/league_name"));
        }

        // If we both has family, check if we have any relations.
        if (obj != me &&
            mapp(fam = obj->query("family")) &&
            mapp(my_fam = me->query("family")) &&
            fam["family_name"] == my_fam["family_name"])
        {

                if (fam["generation"] == my_fam["generation"])
                {

                        if ((string)obj->query("gender") == "男性" ||
                                (string)obj->query("gender") == "无性")
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"]? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
                        else
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"]? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
                } else
                if (fam["generation"] < my_fam["generation"])
                {
                        if (my_fam["master_id"] == obj->query("id"))
                                str += pro + "是你的师父。\n";
                        else
                        if (my_fam["generation"] - fam["generation"] > 1)
                                str += pro + "是你的同门长辈。\n";
                        else
                        if (fam["enter_time"] < my_fam["enter_time"])
                                str += pro + "是你的师伯。\n";
                        else
                                str += pro + "是你的师叔。\n";
                } else
                {
                        if (fam["generation"] - my_fam["generation"] > 1)
                                str += pro + "是你的同门晚辈。\n";
                        else
                        if (fam["master_id"] == me->query("id"))
                                str += pro + "是你的弟子。\n";
                        else
                                str += pro + "是你的师侄。\n";
                }
        }

        if (obj->is_chatter())
        {
                message("vision", str, me);
                return 1;
        }

        if (stringp(obj->query_temp("eff_status_msg")))
        {
                str += obj->query_temp("eff_status_msg") + "\n";
        } else
        if (obj->query("max_qi"))
                str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi")* 100 / (int)obj->query("max_qi")) + "\n";

        if (obj->query_temp("daub/poison/remain") &&
            (me == obj || random((int)me->query_skill("poison", 1)) > 80))
        {
                str += pro + HIG "身上现在" + (me == obj ? "" : "似乎") +
                       "淬了" + (me == obj ? obj->query_temp("daub/poison/name") : "毒") +
                       NOR "。\n";
        }

        str += look_equiped(me, obj, pro);
        message("vision", str, me);

        if (obj != me && living(obj) &&
            ! me->is_brother(obj) &&
            me->query("couple/id") != obj->query("id") &&
            (me_shen < -1000 && obj_shen > 1000 ||
             me_shen > 1000  && obj_shen < -1000))
        {
                tell_object(me, obj->name() + "突然转过头来瞪你一眼。\n");
                if (obj->query("total_hatred") > 4 * obj->query_skill("force") &&
                    ! wizardp(obj) && ! wizardp(me))
                        COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}

int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if (! objectp(env = environment(me)))
                return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");
        if (mapp(item = env->query("item_desc")) && !undefinedp(item[arg]))
	{
                if (stringp(item[arg]))
                        tell_object(me, item[arg]);
                else
		if(functionp(item[arg]))
                        tell_object(me, (string)(*item[arg])(me));

                return 1;
        }
        if (mapp(exits = env->query("exits")) && ! undefinedp(exits[arg]))
	{
                if (objectp(env = find_object(exits[arg])))
                        look_room(me, env, 0);
                else
		{
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]), 0);
                }
                return 1;
        }
        return notify_fail("你要看什么？\n");
}

string cdir( string dir )
{
        switch( dir ) {
                case "east":
                        return "东方(e)";
                case "west":
                        return "西方(w)";
                case "south":
                        return "南方(s)";
                case "north":
                        return "北方(n)";
                case "up":
                        return "上方(u)";
                case "down":
                        return "下方(d)";
                case "northeast":
                        return "东北方(ne)";
                case "southeast":
                        return "东南方(se)";        
                case "southwest":
                        return "西南方(sw)";        
                case "northwest":
                        return "西北方(nw)";
                case "eastup":
                        return "东上方(eu)";        
                case "eastdown":
                        return "东下方(ed)";        
                case "westup":
                        return "西上方(wu)";        
                case "westdown":
                        return "西下方(wd)";                
                case "southup":
                        return "南上方(su)";
                case "southdown":
                        return "南下方(sd)";        
                case "northup":
                        return "北上方(nu)";
                case "northdown":
                        return "北下方(nd)";        
                case "out":
                        return "出口(out)";        
                case "enter":
                        return "进口(ENTER)";                        
                default:
                        return dir;
        }
}
string cterrain( string terrain )
{
        switch( terrain ) {
                case "plain":
                        return "平地";
                case "hill":
                        return "丘陵";
                   case "shop":
                         return "商店";
                case "mountain":
                        return "山岳";
                case "river":
                        return "河川";
                case "ocean":
                        return "海洋";
                case "atmosphere":
                        return "大气圈";
                case "space":
                        return "宇宙空间";
                default:
                        return "平地";
        }
}

int help(object me)
{
        write(@HELP
指令格式: look [<物品>|<生物>|<方向>]

这个指令让你查看你所在的环境、某件物品、生物、或是方向。如果
在look指令后面有参数，将先察看身上是否有该物品，如果没有则察
看你所在的环境中是否有该物品或人物。如果你身上的物品和你所在
的环境有ID相同的物品，你可以指明look ??? of me/here 以指明你
想要察看自己身上的物品还是附近环境中的物品。同时，如果使用命
令 look ??? of <id> 可以看他人的装备或是亮出来的物品。

HELP
);
        return 1;
}

