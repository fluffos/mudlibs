//Heart of fy3 -- Tie
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
#include <ansi.h>
string locate_obj(string str);
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
	int color;
	quest = quest_item->query("dynamic_quest");
	if(base_name(who) != quest["owner_name"]) return 0;
        exp =200+random(300);
        pot = exp/7;
        score = random(10)+1;
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->add("score",score);
	color=random(5);
	if (color>3)
	{tell_object(me,HIR"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n" +
        chinese_number(score)+"点江湖阅历\n"NOR);}
	else if (color>2)
	{tell_object(me,HIB"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n" +
        chinese_number(score)+"点江湖阅历\n"NOR);}
	else if (color>1)
	{tell_object(me,HIM"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n" +
        chinese_number(score)+"点江湖阅历\n"NOR);}
	else if (color>0)
	{tell_object(me,HIY"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n" +
        chinese_number(score)+"点江湖阅历\n"NOR);}
	else 
	{tell_object(me,HIC"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n" +
        chinese_number(score)+"点江湖阅历\n"NOR);}
	me->add("TASK",1);
	if( !undefinedp(quest["fin_func"]))
	call_other(this_object(),quest["fin_func"],me,who,quest_item);
	if(quest_item)
	destruct(quest_item);destruct(present("xdshi",me));
	tell_object(me,HIW"你身上的"+HIR+"七"+HIC+"彩"+HIY+"向"+HIM+"导"+HIG+"石"HIW"跟着神书一起消失了。\n"NOR);
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
string locate_obj(string strr)
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
	 mixed map;
        int tmp;
	string str="";
	reset_eval_cost();
        for( i=0; i < sizeof(quests); i++)
	{
        if(!objectp(item= find_object(quests[i]["file_name"])))
        item = load_object(quests[i]["file_name"]);
	if(item->query("id") == strr || item->query("name") == strr) str = quests[i]["file_name"];
	}
	if(str != "") {
                //room = environment(me);
                ob_list = children(str);
                for(i=0; i<sizeof(ob_list); i++) {
                ob=find_env(ob_list[i]);
                this_player()->add("jing",-5);
                if(ob)
                {
                map=values(ob->query("exits"));
                map=values(map[random(sizeof(map))]->query("exits"));//add by zzz for random locate
       if (ob->query("outdoors")=="baituo")  
	output="『"+ob_list[i]->query("name")+"』似乎在白驼山的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="binghuodao")  
	output="『"+ob_list[i]->query("name")+"』似乎在冰火岛的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="city")  
	output="『"+ob_list[i]->query("name")+"』似乎在扬州的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="yangzhou")  
	output="『"+ob_list[i]->query("name")+"』似乎在扬州郊外的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="city2")  
	output="『"+ob_list[i]->query("name")+"』似乎在京城的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="chengdu") 
	output="『"+ob_list[i]->query("name")+"』似乎在成都的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="changan")  
	output="『"+ob_list[i]->query("name")+"』似乎在长安城的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="dali")  
	output="『"+ob_list[i]->query("name")+"』似乎在大理的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="emei")  
	output="『"+ob_list[i]->query("name")+"』似乎在娥眉山的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="foshan")  
	output="『"+ob_list[i]->query("name")+"』似乎在佛山的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="gaibang")  
	output="『"+ob_list[i]->query("name")+"』似乎在丐帮的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="gaochang")  
	output="『"+ob_list[i]->query("name")+"』似乎在高昌的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="guanwai")  
	output="『"+ob_list[i]->query("name")+"』似乎在关外的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="guiyun")  
	output="『"+ob_list[i]->query("name")+"』似乎在归云庄的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="gumu")  
	output="『"+ob_list[i]->query("name")+"』似乎在古墓派的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="hangzhou")  
	output="『"+ob_list[i]->query("name")+"』似乎在杭州的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="heimuya")  
	output="『"+ob_list[i]->query("name")+"』似乎在黑木崖的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="hengshan")  
	output="『"+ob_list[i]->query("name")+"』似乎在恒山的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="henshan")  
	output="『"+ob_list[i]->query("name")+"』似乎在衡山的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="huanggon")  
	output="『"+ob_list[i]->query("name")+"』似乎在皇宫的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="huanghe")  
	output="『"+ob_list[i]->query("name")+"』似乎在黄河九曲的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="xx")  
	output="『"+ob_list[i]->query("name")+"』似乎在华山的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="jinshe")  
	output="『"+ob_list[i]->query("name")+"』似乎在金蛇山洞的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="lingjiu")  
	output="『"+ob_list[i]->query("name")+"』似乎在灵鹫宫的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="lingzhou")  
	output="『"+ob_list[i]->query("name")+"』似乎在灵洲的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="meizhuang")  
	output="『"+ob_list[i]->query("name")+"』似乎在梅庄的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="mingjiao")  
	output="『"+ob_list[i]->query("name")+"』似乎在明教的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="qingcheng")  
	output="『"+ob_list[i]->query("name")+"』似乎在青城山的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="quanzhen")  
	output="『"+ob_list[i]->query("name")+"』似乎在重阳宫的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="quanzhou")  
	output="『"+ob_list[i]->query("name")+"』似乎在泉洲的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="shaolin")  
	output="『"+ob_list[i]->query("name")+"』似乎在少林寺的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="shenlong")  
	output="『"+ob_list[i]->query("name")+"』似乎在神龙岛的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="songshan")  
	output="『"+ob_list[i]->query("name")+"』似乎在嵩山的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="suzhou")  
	output="『"+ob_list[i]->query("name")+"』似乎在苏州的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="taishan")  
	output="『"+ob_list[i]->query("name")+"』似乎在泰山的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="taohua")  
	output="『"+ob_list[i]->query("name")+"』似乎在桃花岛的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="tianlongsi")  
	output="『"+ob_list[i]->query("name")+"』似乎在天龙寺的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="wanjiegu")  
	output="『"+ob_list[i]->query("name")+"』似乎在万劫谷的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="wudang")  
	output="『"+ob_list[i]->query("name")+"』似乎在武当山的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="xiakedao")  
	output="『"+ob_list[i]->query("name")+"』似乎在侠客岛的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="xiangyang")  
	output="『"+ob_list[i]->query("name")+"』似乎在襄阳城的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="xiaoyao")  
	output="『"+ob_list[i]->query("name")+"』似乎在逍遥林的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="xingxiuhai")  
	output="『"+ob_list[i]->query("name")+"』似乎在星宿海的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="xueshan")  
	output="『"+ob_list[i]->query("name")+"』似乎在雪山寺的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="mr")  
	output="『"+ob_list[i]->query("name")+"』似乎在慕容世家的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="kunlun")  
	output="『"+ob_list[i]->query("name")+"』似乎在昆仑山的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else if (ob->query("outdoors")=="tiezhang")  
	output="『"+ob_list[i]->query("name")+"』似乎在铁掌门的"+map[random(sizeof(map))]->query("short")+"附近。\n";
else 	output="『"+ob_list[i]->query("name")+"』似乎在某个地方的"+map[random(sizeof(map))]->query("short")+"附近。\n";
	return output;
                }
                }
	}
                return "确定不了"+strr+"的大概位置.\n";

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
