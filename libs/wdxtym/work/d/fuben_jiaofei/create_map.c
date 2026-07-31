#include "include/create_map.h"
void clear_npc(object room);

int create_room(object fb_mem, object fb_system)
{
	string temp1, temp2;
	string *room_file, *team;
	object room, yingdi;
	object *room_obj = ({});
	
	mapping map_exits;
	string *arr_exits;
	object fuben_exits;
	
	int i = 0; //记录城市
	yingdi = new(__DIR__"room/yingdi");
	fb_mem->set("yingdi", yingdi);
	yingdi->set("is_fuben", 1);
	yingdi->set("no_clean_up_fb", 1);
	foreach(temp1 in city_dir)
	{
		room_file = list_dirs(temp1 + "*.c");
		foreach(temp2 in room_file)
		{
			temp2 = replace_string(temp2, ".c", "");
			room = new(temp1 + temp2);
			clear_npc(room);
			room->delete("item_desc");
			room->set("action_list", (["副本指令" : "jiaofei"]));
			room->set("is_fuben", 1);
			room->delete("no_fight");
			room->set("no_clean_up_fb", 1);
			room_obj += ({room});
			fb_mem->set("file_to_obj" + temp1 + temp2, file_name(room));
		}
		map_exits = fb_mem->query("file_to_obj" + temp1);
		arr_exits = keys(map_exits);
		fuben_exits = map_exits[arr_exits[random(sizeof(arr_exits))]];
		yingdi->set("fuben_exits/" + i, fuben_exits);
		i += 1;
	}
	
	room_obj += ({yingdi});
	team = fb_mem->query("team");
	foreach(temp1 in team)
	{
		temp1->set_temp("fb_mem", fb_mem);
		temp1->move(yingdi);
	}
	fb_mem->set("room_obj", room_obj);
	
	return 1;
}

int link_room(object fb_mem)
{
	int i = 0, room_count = 0;
	string temp, dir;
	string *exits;
	mapping room_obj, file_to_obj, map_exit;
	
	room_obj = fb_mem->query("room_obj");
	foreach(dir in city_dir)
	{
    	file_to_obj = fb_mem->query("file_to_obj" + dir);
    	room_count += sizeof(file_to_obj);
    	
    	while(i < room_count)
    	{
    		if (!(map_exit = room_obj[i]->query("exits")))
    		{
    			i += 1;
    			continue;
    		}
    			
    		exits = keys(map_exit);
    		foreach(temp in exits)
    		{
    			if(file_to_obj[replace_string(room_obj[i]->query("exits/" + temp), dir, "")])
    			{
    				room_obj[i]->set("exits/" + temp, file_to_obj[replace_string(room_obj[i]->query("exits/" + temp), dir, "")]);
    			}
    			else
    				room_obj[i]->delete("exits/" + temp);
    		}
    		i += 1;
    	}
	}
	
	return 1;
}

void clear_npc(object room)
{
	object *obj, temp;
	
	obj = all_inventory(room);
	
	foreach(temp in obj)
	{
		destruct(temp);
	}
}