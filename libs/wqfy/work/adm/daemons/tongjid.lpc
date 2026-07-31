#pragma save_binary
mapping *quests;
mapping *read_table(string file);
string *roomlines;
varargs void init_dynamic_quest(int hard);
varargs int spread_quest(mapping one_quest, int hard);
object find_env(object ob);
varargs int already_spreaded(string str, int hard);
string dyn_quest_list();
#define MAX_DIS 7
#define MAX_ALT  2
#define MAX_DIR  8

void create()
{
	string file;
	quests = read_table("/tongji/dynamic_quest");
	file = read_file("/tongji/dynamic_location");
	roomlines = explode(file,"\n");	
	CRON_D->set_last_hard_dis();
	init_dynamic_quest(1);
}

varargs void init_dynamic_quest(int hard)
{
	int i;
	for( i=0; i < sizeof(quests); i++)
		spread_quest(quests[i],hard);
}

varargs int spread_quest(mapping quest, int hard)
{
	object obj0,obj1,obj2,obj3;
	object cur_obj;
	object next_obj;
	object tar;
	object *inv;
	object *target=({});
	int i;
	string location;
	if(already_spreaded(quest["file_name"],hard)) return 0;
	reset_eval_cost();
	location = roomlines[random(sizeof(roomlines))];
	obj0=find_object(location);
	if(obj0)
	obj0->reset();
	else
	obj0=load_object(location);
	cur_obj =obj0;
	if(cur_obj)
	{
	inv = all_inventory(cur_obj);
	for(i=0; i<sizeof(inv); i++) {
	if(inv[i]->is_character() && !userp(inv[i]))
	target += ({ inv[i] });
	if(inv[i]->is_container()) target += ({ inv[i] });
		}
	}
	if(sizeof(target)) cur_obj = target[random(sizeof(target))];
	if(cur_obj)
	{
        tar = new(quest["file_name"]);
        tar->set("value",0);
	tar->set("dynamic_quest",quest);
	tar->move(cur_obj);		
	}
return 1;
}

varargs int already_spreaded(string str,int hard)
{
        object ob,*ob_list;
        int i;
        if(!str) return 0;
	if(hard)
	{
        ob_list = children(str);
        for(i=0; i<sizeof(ob_list); i++) {
                ob=find_env(ob_list[i]);
                if(ob)
		{ ob_list[i]->move(VOID_OB);
		 destruct(ob_list[i]);
		}
	}
	return 0;
	}
	else
	{
	if(!str) return 0;
	ob_list = children(str);
	for(i=0; i<sizeof(ob_list); i++) {
                ob=find_env(ob_list[i]);
                if(ob)
			return 1;
	}
	return 0;
	}
}

object find_env(object ob)
{
        while(ob)
        {
        if(ob->query("coor") ) return ob;
        else ob=environment(ob);
        }
        return ob;
}
mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}

void execute_accept_object(object me, object who, object item)
{
	who->accept_object(me,item);
}
