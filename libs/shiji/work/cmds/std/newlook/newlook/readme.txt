此程序由老步(amanda)制作,于风云中测试通过,如果你的mudlib是风云,那么可以直接用这两个程序覆盖原程序,如果你的mud不是风云.请参见以下说明:

1.实际上该程序只是简单的用到了ansi.h原来没有定义的部分
2.如果要应用到其他MUD中间只要简单的加上下面的东西就可以了：
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
          
          write(SETDISPLAY(4,70)+clean_color(env->query("short")));
          for (i=0;i<sizeof(dirs);i++)
          switch(dirs[i])     {
          case "north":
                 write(SETDISPLAY(3,72)+"┃┃");
                 room=load_object(exits["north"]);
                 write(SETDISPLAY(2,70)+clean_color(room->query("short")));
                 break;
          case "south":
                 write(SETDISPLAY(5,72)+"┃┃");
                 room=load_object(exits["south"]);
                 write(SETDISPLAY(6,70)+clean_color(room->query("short")));
                 break;
          case "east":
                 
                 room=load_object(exits["east"]);
                 write(SETDISPLAY(4,80)+clean_color(room->query("short")));
                 write(SETDISPLAY(4,78)+"━");
                 break;
          case "west":
                 
                 room=load_object(exits["west"]);
                 write(SETDISPLAY(4,60)+clean_color(room->query("short")));
                 write(SETDISPLAY(4,68)+"━");
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
                 write(SETDISPLAY(3,72)+"↑↑");
                 room=load_object(exits["northup"]);
                 write(SETDISPLAY(2,70)+clean_color(room->query("short")));
                 break;
          case "southup":
                 write(SETDISPLAY(5,72)+"↓↓");
                 room=load_object(exits["southup"]);
                 write(SETDISPLAY(6,70)+clean_color(room->query("short")));
                 break;
          case "southdown":
                 write(SETDISPLAY(5,72)+" ││ ");
                 room=load_object(exits["southdown"]);
                 write(SETDISPLAY(6,70)+clean_color(room->query("short")));
                 break;
          case "northdown":
                 write(SETDISPLAY(3,72)+" ││ ");
                 room=load_object(exits["northdown"]);
                 write(SETDISPLAY(2,70)+clean_color(room->query("short")));
                 break;
          case "eastdown":
                 
                 room=load_object(exits["eastdown"]);
                 write(SETDISPLAY(4,80)+clean_color(room->query("short")));
                 write(SETDISPLAY(4,78)+"=─");
                 break;
          case "westdown":
                 
                 room=load_object(exits["westdown"]);
                 write(SETDISPLAY(4,60)+clean_color(room->query("short")));
                 write(SETDISPLAY(4,68)+"-=");
                 break;
          case "northwest":
                 write(SETDISPLAY(3,68)+"\\\\");
                 room=load_object(exits["northwest"]);
                 write(SETDISPLAY(2,60)+clean_color(room->query("short")));
                 break;
          case "southwest":
                 write(SETDISPLAY(5,68)+"////");
                 room=load_object(exits["southwest"]);
                 write(SETDISPLAY(6,60)+clean_color(room->query("short")));
                 break;
          case "northeast":
                 write(SETDISPLAY(3,76)+"////");
                 room=load_object(exits["northeast"]);
                 write(SETDISPLAY(2,80)+clean_color(room->query("short")));
                 break;
          case "southeast":
                 write(SETDISPLAY(5,76)+"\\\\");
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
记住该段一定要应用到显示原来房间的描述后面，因为涉及到了保存光标位置，只有那样才能正常的显示其他信息。
在ansi.h中间加入如下定义：
#define SETDISPLAY(x,y)  (ESC+"["+x+";"+y+"f")        /*设定光标位置*/
#define DELLINE	ESC+"[K"               /*删除光标所在的行*/
#define SAVEC ESC+"[s"           /* Save cursor position */
#define REST ESC+"[u"            /* Restore cursor to saved position */
我们可以根据这个做出很多新的东西来，以上只是简单的，比如我们可以在战斗时在一个位置显示玩家的气血状态等等
                                                                      amanda
                                                                      amanda_tnt@263.net

星月传奇提供下载
http://www.lywin.com
中国泥巴资源下载第一站

星月社区
http://www.lywin.com/club
中国最大的泥巴交流社区