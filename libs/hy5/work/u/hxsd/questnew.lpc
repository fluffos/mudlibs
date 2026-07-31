//Heart of fy3 -- Tie
#pragma save_binary
//#pragma optimize all
mapping *quests;
mapping *read_table(string file);
string *roomlines;
varargs void init_dynamic_quest(int hard);
varargs int spread_quest(mapping one_quest, int hard);
object find_env(object ob);
varargs int already_spreaded(string str, int hard);
int quest_reward( object me, object who,object quest_item);
string dyn_quest_list();
#define MAX_DIS 7
#define MAX_ALT  2
#define MAX_DIR  8
string locate_obj(object me,string str);
void create()
{
	string file;
	quests = read_table("/quest/dynamic_quest");
	file = read_file("/quest/dynamic_location");
	roomlines = explode(file,"\n");	
	//CRON_D->set_last_hard_dis();
	init_dynamic_quest(1);
}
int quest_reward(object me, object who,object quest_item)
{
	mapping quest;
	int exp,pot,score;
	quest = quest_item->query("dynamic_quest");
	if(base_name(who) != quest["owner_name"]) return 0;
        exp =200+random(1000);
        pot = exp/7;
        score = random(10)+1;
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->add("score",score);
	tell_object(me,"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n" +
        chinese_number(score)+"点综合评价\n");
	me->add("TASK",1);
	if( !undefinedp(quest["fin_func"]))
	call_other(this_object(),quest["fin_func"],me,who,quest_item);
	if(quest_item)
	destruct(quest_item);
	return 1;
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
string dyn_quest_list()
{
	string output="";
	object owner,item;
        int i;
        for( i=0; i < sizeof(quests); i++)
	{
	reset_eval_cost();
	if(!objectp(owner= find_object(quests[i]["owner_name"])))
	owner = load_object(quests[i]["owner_name"]);
        if(!objectp(item= find_object(quests[i]["file_name"])))
        item = load_object(quests[i]["file_name"]);
	if(already_spreaded(quests[i]["file_name"]))
	{
	if(random(2))
	output += sprintf("%s的%s（%s）\n",owner->query("name"),item->query("name"),item->query("id"));
	else
	output = sprintf("%s的%s（%s）\n",owner->query("name"),item->query("name"),item->query("id")) + output;
	}
	else
	{
	if(random(2))
	output += sprintf("%s的%s（%s）〔已完成〕\n",owner->query("name"),item->query("name"),item->query("id"));
	else
	output = sprintf("%s的%s（%s）〔已完成〕\n",owner->query("name"),item->query("name"),item->query("id")) + output;
	}
	}
	return output;
}
string locate_obj(object me,string strr)
{
        string *distance = ({
"极近", "很近", "比较近", "不远",
"不近", "比较远", "很远", "极远"
        });
        string *altitude =({
"高处", "地方", "低处"
        });
        string *directions=({
"周围","北方", "南方", "东方","西方",
"东北方","西北方","东南方","西南方"
        });
        object ob, tmpobj,where, *ob_list;
        object item,room;
        string output,dis,alt,dir;
        int i;
        int x,y,z,x0,y0,z0;
        int realdis;
        int tmp;
	    mixed map;
		string str="";
	reset_eval_cost();
        for( i=0; i < sizeof(quests); i++)
	{
        if(!objectp(item= find_object(quests[i]["file_name"])))
        item = load_object(quests[i]["file_name"]);
	if(item->query("id") == strr || item->query("name") == strr) str = quests[i]["file_name"];
	}
	if(str != "") {
                room = environment(me);
                ob_list = children(str);
                for(i=0; i<sizeof(ob_list); i++) {
                ob=find_env(ob_list[i]);
                if(ob)
                {
                  /*    x0= (int)room->query("coor/x");
                        y0= (int)room->query("coor/y");
                        z0= (int)room->query("coor/z");
                        x=(int)ob->query("coor/x")-x0;
                        y=(int)ob->query("coor/y")-y0;
                        z=(int)ob->query("coor/z")-z0;
                        realdis=0;
                        if(x<0)realdis-=x; else realdis+=x;
                        if(y<0)realdis-=y; else realdis+=y;
                        if(z<0)realdis-=z; else realdis+=z;
                        tmp =(int)  realdis/50;
                        if(tmp>MAX_DIS) tmp = MAX_DIS;
                        dis=distance[tmp];
                        if(z>0) alt=altitude[0];
                        if(z<0) alt=altitude[2];
                        if(z==0) alt=altitude[1];
                        if(x==0&&y==0) dir=directions[0];
                        if(x==0&&y>0) dir=directions[1];
                        if(x==0&&y<0) dir=directions[2];
                        if(x>0&&y==0) dir=directions[3];
                        if(x<0&&y==0) dir=directions[4];
                        if(x>0&&y>0) dir=directions[5];
                        if(x<0&&y>0) dir=directions[6];
                        if(x>0&&y<0) dir=directions[7];
                        if(x<0&&y<0) dir=directions[8];
        output = "『"+ob_list[i]->query("name")+"』似乎在"+dir+dis+"的"+alt+"。\n";*/
	
	map=values(ob->query("exits"));
    map=values(map[random(sizeof(map))]->query("exits"));//add by zzz for random locate
    output="『"+ob_list[i]->query("name")+"』似乎在"+ob->query("outdoors")+map[random(sizeof(map))]->query("short");
	
	
	return output;
                }
                }
	}
	else 
	if(wizardp(me) || me->query("class") == "official")
	{
        tmpobj = find_player(strr);
        if(!tmpobj) tmpobj = find_living(strr);
        if(!tmpobj) return "";
	ob = find_env(tmpobj);
	room = environment(me);
	if(ob)
	{
                        x0= (int)room->query("coor/x");
                        y0= (int)room->query("coor/y");
                        z0= (int)room->query("coor/z");
                        x=(int)ob->query("coor/x")-x0;
                        y=(int)ob->query("coor/y")-y0;
                        z=(int)ob->query("coor/z")-z0;
                        realdis=0;
                        if(x<0)realdis-=x; else realdis+=x;
                        if(y<0)realdis-=y; else realdis+=y;
                        if(z<0)realdis-=z; else realdis+=z;
                        tmp =(int)  realdis/50;
                        if(tmp>MAX_DIS) tmp = MAX_DIS;
                        dis=distance[tmp];
                        if(z>0) alt=altitude[0];
                        if(z<0) alt=altitude[2];
                        if(z==0) alt=altitude[1];
                        if(x==0&&y==0) dir=directions[0];
                        if(x==0&&y>0) dir=directions[1];
                        if(x==0&&y<0) dir=directions[2];
                        if(x>0&&y==0) dir=directions[3];
                        if(x<0&&y==0) dir=directions[4];
                        if(x>0&&y>0) dir=directions[5];
                        if(x<0&&y>0) dir=directions[6];
                        if(x>0&&y<0) dir=directions[7];
                        if(x<0&&y<0) dir=directions[8];
        
		output = "『"+tmpobj->query("name")+"』似乎在"+dir+dis+"的"+alt+"。\n";
        return output;
	}
        }
                return "";

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
        if(ob->query("exits") ) return ob;
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
void big_reward(object me, object who, object item)
{
	tell_object(me,"你真行！！\n");
}

void execute_accept_object(object me, object who, object item)
{
	who->accept_object(me,item);
}
