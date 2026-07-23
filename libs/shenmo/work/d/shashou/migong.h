int i,j,size;
string *dyna_room,dir1,rev_dir1,*dirs,*rev_dirs,home,entry,exit;
object *room_object,cur_room,room;
mixed *room_list,*add_room=({}),*add_obj=({});

private int r_map();

private int r_map()
{
	object *inv;
	string *di,*rd;
	remove_call_out("r_map");
	call_out("r_map",1200+random(600));
        message("channel:job",WHT"杀手楼：动态地图已经启动。\n"NOR,users());  
//   message("wiz",HBBLU+"【一品堂】赫连铁树(Helian tieshu):杀手楼"+HIR"天地绝杀阵"NOR+HBBLU"已经启动!\n"NOR,wizard());  
	
	home="/d/shashou/migong/";  //ROOM所在目录
       room_list = get_dir(home+"*.lpc");        
       for(i=0;i<sizeof(room_list);i++)
       room_list[i] = home+room_list[i];
       add_room-=({0});
       if(!sizeof(add_room))
       add_room=({});
       room_list += add_room;                              

       dyna_room = ({});
        while(sizeof(room_list))
        {
                j = random(sizeof(room_list));
                if(!objectp(room=load_object(room_list[j]))
                ||!inherits(ROOM,room))
                {
                        room_list-=({room_list[j]});
                        continue;
                }               
                dyna_room += ({room_list[j]});
                room_list -= ({room_list[j]});
        }
        //随机分配位置完毕                                              
       
        size = sizeof(dyna_room);
        room_object = ({});
        for(i=0;i<size;i++)
        {
        if( !(cur_room = find_object(dyna_room[i])) )
                cur_room = load_object(dyna_room[i]);
                inv=all_inventory(cur_room);
                if(sizeof(inv))
                for(j=0;j<sizeof(inv);j++)
                {
                        if(!clonep(inv[j]))
                        continue;
                        if(userp(inv[j])) 
                        continue;
                        if(!random(2))
                        reload_object(inv[j]);
                        else destruct(inv[j]);
                }
                else if(!random(2)&&sizeof(add_obj)) {
                j=random(sizeof(add_obj));
                if(objectp(new(add_obj[j])))    
                new(add_obj[j])->move(cur_room);        
                }
        
                cur_room->delete("exits");
                cur_room->delete("blocks");
                cur_room->set("no_clean_up",1);
                room_object += ({cur_room});
                tell_room(cur_room,HIY
                "\n  星光一闪，\n"
               "  你觉得天旋地转...\n\n"NOR);
                
        }
                dirs =  ({      "northeast","northwest","southdown","southup","northup","northdown",
                                "southwest","southeast","east","west",    
                                "up","down","enter","out",
                                "northup","northdown","eastup","eastdown",
                                "westup","westdown","southup","southdown",
                        });

                rev_dirs = ({   "southwest","southeast","northup","northdown","southdown","southup",
                                "northeast","northwest","west","east",
                                "down","up","out","enter",
                                "southdown","southup","westdown","westup",
                                "eastdown","eastup","northdown","northup",
                           });  
        di=dirs;
        rd=rev_dirs;
                           
        //开始生成路径
        for(i=0;i<size;i++)
        {               
                j= random(sizeof(di));
                  if ( j<=0 || j>=22 ) j=1+random(20);
                if ( j >= sizeof(di) )
                {
                    j= random(sizeof(di));
                }
                dir1 = di[j];
                rev_dir1 = rd[j];               
                di=dirs;
                rd=rev_dirs;
                di-=({rev_dir1});
                rd-=({dir1});
                   if(i>0) 
                   { 
                (room_object[i])->set("exits/"+dir1,dyna_room[i-1]);
                (room_object[i-1])->set("exits/"+rev_dir1,dyna_room[i]);
                   } else { 
                  (room_object[0])->set("exits/enter",dyna_room[size-1]); 
                  (room_object[size-1])->set("exits/out",dyna_room[0]); 
                   }
        tell_room(room_object[i],HIW
        "  ...终于声止尘定，你发现一切都已经变了...\n"NOR);
        }       
        j=random(sizeof(room_object));
	 if ( j< 0 || j>5 ) j=1+random(4);	
        room=load_object(entry);                                    
        room->set("exits/",([ ]));
        room->set("exits/"+dirs[random(sizeof(dirs))],dyna_room[j]);
        (room_object[j])->set("exits/"+dirs[random(sizeof(dirs))],entry);
        j=random(sizeof(room_object));
        room=load_object(exit);
        room->set("exits/",([ ]));
//        room->set("exits/",([ "north" : "/d/shashou/shashou", ]));
        room->set("exits/north","/d/shashou/shashou");
        room->set("exits/"+dirs[random(sizeof(dirs))],dyna_room[j]);
        (room_object[j])->set("exits/"+dirs[random(sizeof(dirs))],exit);
        return 1;
} 
