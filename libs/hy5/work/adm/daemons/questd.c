//Heart of fy3 -- Tie

//#pragma optimize all

mapping *quests;

mapping *read_table(string file);

string *roomlines;

varargs void init_dynamic_quest(int hard);

varargs int spread_quest(mapping one_quest, int hard);

object find_env(object ob);
object find_book(object ob);

varargs int already_spreaded(string str, int hard);

int quest_reward( object me, object who,object quest_item);

string dyn_quest_list();

#define MAX_DIS 7

#define MAX_ALT  2

#define MAX_DIR  8

#include <ansi.h>

string locate_obj(string str);

#include "/quest/givetaskgift.c"

int random_move()
{
        mapping exits;
        string *dirs;
        object me = this_object();

//        if (!query_heart_beat(me)) return 0;
	if( !environment(me) ) return 0;
        if( me->query_temp("is_unconcious") ) return 0;

	if( !living(me)) return 0;

	if( !mapp(exits = environment()->query("exits")) ) return 0;
        if( !environment() 
        || !mapp(exits = environment()->query("exits")) 
        || me->is_busy())
// || me->is_fighting()
        return 0;                 
//        if( !mapp(exits = environment()->query("exits")) 
//        || me->is_busy()) return 0;
        dirs = keys(exits);
        if (!dirs)  return 0;
        if (sizeof(dirs) < 1) return 0;
        command("go " + dirs[random(sizeof(dirs))]);
}

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

  object ob;
	quest = quest_item->query("dynamic_quest");

	if(base_name(who) != quest["owner_name"]) return 0;

        exp =1288+random(888);

        pot = exp*0.9;

        score = random(50)+50;

        addnl(me,"exp",exp);

        addnl(me,"score",score);

	color=random(5);

	
me->add_temp("nbjob49",1);
	me->add("TASK",1);
    if (me->query("4zhuan")
    || me->query("5zhuan"))
{
if (random(5)==1)
{

me->add("expmax",1);

tell_object(me,HIR"ÄãµÄ³É³¤×ÊÀú»ñµÃ³É¹¦!\n"+NOR);
}
}

if (random(12)==1)
{
        ob=new("/quest/shenshu/sdan2");
        ob->move(me);
message("channel:chat", HIC"¡¾½­ºþ´«ÎÅ¡¿"GRN + me->query("name")+"µÃµ½Ò»¿Å"+HIY":" + ob->query("name")+HIG"À²£¡\n"NOR,users() );
}

	if( !undefinedp(quest["fin_func"]))

	call_other(this_object(),quest["fin_func"],me,who,quest_item);

	if(quest_item)

	destruct(quest_item);
//	destruct(present("xdshi",me));
//	tell_object(me,HIW"ÄãÉíÉÏµÄ"+HIR+"Æß"+HIC+"²Ê"+HIY+"Ïò"+HIM+"µ¼"+HIG+"Ê¯"HIW"¸ú×ÅÉñÊéÒ»ÆðÏûÊ§ÁË¡£\n"NOR);

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

	object obj0,obj1,obj2,obj3,jobnpc;

	object cur_obj;

	object next_obj;

	object tar;

	object *inv;

	object *target=({});

	int i,isk;

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
isk=0;
	if(!sizeof(target)) 
{
		jobnpc = new("/quest/shenshu/npc/man");
		jobnpc->move(cur_obj);
		jobnpc = new("/quest/shenshu/npc/man");
		jobnpc->move(cur_obj);
		jobnpc = new("/quest/shenshu/npc/man");
		jobnpc->move(cur_obj);
		jobnpc = new("/quest/shenshu/npc/man");
		jobnpc->move(cur_obj);
if (random(3)==0)
{
isk=1;
		jobnpc = new("/quest/shenshu/npc/man2");
		jobnpc->move(cur_obj);
	tar = new(quest["file_name"]);
	tar->set("value",0);
	tar->set("dynamic_quest",quest);
	tar->move(jobnpc);	
}
}
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

	if(cur_obj && isk==0)

	{

	tar = new(quest["file_name"]);

	tar->set("value",0);

	tar->set("dynamic_quest",quest);

	tar->move(cur_obj);		
cur_obj->set_temp("apply/attack", 30);
cur_obj->set_temp("apply/defense",130);
cur_obj->set_temp("apply/armor", 100);
cur_obj->set_temp("apply/damage", 160+random(80));
cur_obj->set("dex",150);
cur_obj->set("no_get",1);
cur_obj->set("qi",8000);
cur_obj->set("jing",8000);
cur_obj->set("eff_qi",8000);
cur_obj->set("eff_jing",10000);
cur_obj->set("max_qi",8000);
cur_obj->set("max_jing",15000);
cur_obj->set_skill("dodge",300);
cur_obj->set("chat_chance_combat", 90);
cur_obj->set("chat_msg_combat", ({ (: random_move :), }) );
cur_obj->set("chat_chance", 50);
cur_obj->set("chat_msg", ({(: random_move :),}) );
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

	output += sprintf(HIG"%10s"NOR"µÄ"HIW"%10s"NOR"£¨%s£©\n",owner->query("name"),item->query("name"),item->query("id"));

	else

	output = sprintf(HIG"%10s"NOR"µÄ"HIW"%10s"NOR"£¨%s£©\n",owner->query("name"),item->query("name"),item->query("id")) + output;

	}

	else

	{

	if(random(2))

	output += sprintf(HIG"%10s"NOR"µÄ"HIY"%10s"NOR"£¨%s£© [1;31m¡¼ [32mÒÑÍê³É[31m ¡½[m\n",owner->query("name"),item->query("name"),item->query("id"));

	else

	output = sprintf(HIG"%10s"NOR"µÄ"HIY"%10s"NOR"£¨%s£©[1;31m ¡¼ [32m ÒÑÍê³É[31m ¡½[m\n",owner->query("name"),item->query("name"),item->query("id")) + output;

	}

	}

//            if(random(2))output += sprintf(HIG"%10s"NOR"µÄ"HIW"%10s"NOR"£¨%s£©\n",item->query("owner_name"),item->query("name"),item->query("id"));
//            else output=sprintf(HIG"%10s"NOR"µÄ"HIW"%10s"NOR"£¨%s£©\n",item->query("owner_name"),item->query("name"),item->query("id"))+output;
//        else
//            if(random(2))output += sprintf(HIG"%10s"NOR"µÄ"HIY"%10s"NOR"£¨%s£© [1;31m¡¼ [32mÒÑÍê³É[31m ¡½[m\n",item->query("owner_name"),item->query("name"),item->query("id"));
//            else output=sprintf(HIG"%10s"NOR"µÄ"HIY"%10s"NOR"£¨%s£©[1;31m ¡¼ [32m ÒÑÍê³É[31m ¡½[m\n",item->query("owner_name"),item->query("name"),item->query("id"))+output;

	return output;

}

string locate_obj(string strr)

{

        string *distance = ({

"¼«½ü", "ºÜ½ü", "±È½Ï½ü", "²»Ô¶",

"²»½ü", "±È½ÏÔ¶", "ºÜÔ¶", "¼«Ô¶"

        });

        string *altitude =({

"¸ß´¦", "µØ·½", "µÍ´¦"

        });

        string *directions=({

"ÖÜÎ§","±±·½", "ÄÏ·½", "¶«·½","Î÷·½",

"¶«±±·½","Î÷±±·½","¶«ÄÏ·½","Î÷ÄÏ·½"

        });

        object ob, tmpobj,where, *ob_list,me,obtwo,obthree,tob;

        object item,room;

        string output,outputt,dis,alt,dir,local,tlocal,ck,playout;
        
        int i;

        int x,y,z,x0,y0,z0;

        int realdis;
	 mixed map,mapt;

        int tmp;
        string *dir1;
        string *dir2;

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
                
                ob=find_book(ob_list[i]);

                this_player()->add("jing",-5);

if(ob)
 {
ck=HIC"ÎÞ"NOR;
local=ob->query("short");
tlocal=ob->query("short");                



if (wizardp(this_player()) && ob)
{
//outputt ="1:"+ob->query("short")+"¡»\n";
}
playout ="¡º"+ob->query("short")+"¡»ÕâÀï¸½½ü¡£\n";
                if(sizeof(ob->query("exits"))) 
                {
ck=chinese_number(sizeof(ob->query("exits")));
                map=values(ob->query("exits"));
if (map && sizeof(ob->query("exits"))>=1)
{
                 obtwo=load_object(map[random(sizeof(map))]);
if (ob==obtwo) obtwo=load_object(map[random(sizeof(map))]);	
if (ob==obtwo) obtwo=load_object(map[random(sizeof(map))]);		
if (ob==obtwo) obtwo=load_object(map[random(sizeof(map))]);		

if (obtwo)
{
if (wizardp(this_player())  && obtwo)
{
//outputt +="2:"+obtwo->query("short")+"¡»\n";
}
 
                 local=obtwo->query("short");
              if(obtwo->query("exits")) 
               { //obtwoexits
                 mapt=values(obtwo->query("exits"));
if (mapt && sizeof(obtwo->query("exits"))>=1 )
{
//if (find_object(mapt[random(sizeof(mapt))]))
//{
obthree=load_object(mapt[random(sizeof(mapt))]);
if (obthree==obtwo) obthree=load_object(mapt[random(sizeof(mapt))]);
if (obthree==obtwo) obthree=load_object(mapt[random(sizeof(mapt))]);
if (obthree==obtwo) obthree=load_object(mapt[random(sizeof(mapt))]);
tob=obthree;
if (wizardp(this_player()) && obthree)
{
//outputt +="3:"+obthree->query("short")+"¡»\n";
}

if (obthree)
{
if (sizeof(obthree->query("exits"))>=1 )
{
mapt=values(obthree->query("exits"));
obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
tob=obthree;
if (wizardp(this_player()) && obthree)
{
//outputt +="4:"+obthree->query("short")+"¡»\n";
}
}
}

if (obthree)
{
if (sizeof(obthree->query("exits"))>=1 )
{
//if (tob!=obthree)
//{
mapt=values(obthree->query("exits"));
obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);		
tob=obthree;
if (wizardp(this_player()) && obthree)
{
//outputt +="5:"+obthree->query("short")+"¡»\n";
}
}
//}
}

if (obthree)
{
if (sizeof(obthree->query("exits"))>=1 )
{
//if (tob!=obthree)
//{
mapt=values(obthree->query("exits"));
obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
tob=obthree;
if (wizardp(this_player()) && obthree)
{
//outputt +="6:"+obthree->query("short")+"¡»\n";
}
}
}
//}
/*
if (obthree)
{
if (sizeof(obthree->query("exits"))>=1 )
{
//if (tob!=obthree)
//{
mapt=values(obthree->query("exits"));
obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
tob=obthree;
if (wizardp(this_player()) && obthree)
{
outputt +="7:"+obthree->query("short")+"¡»\n";
}
}
//}
}

if (obthree)
{
if (sizeof(obthree->query("exits"))>=1 )
{
//if (tob!=obthree)
//{
mapt=values(obthree->query("exits"));
obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
if (tob==obthree || obtwo==obthree  || obthree==ob) obthree=load_object(mapt[random(sizeof(mapt))]);	
tob=obthree;
if (wizardp(this_player()) && obthree)
{
outputt +="8:"+obthree->query("short")+"¡»\n";
}
}
}
*/
//}
//}
if (obthree)
{
if (obthree!= ob)
{
                 local=obthree->query("short");
} //obthree
} //obthree
} //mapt
} //map
}//obtwoexits
}
//add by hxsd
}
else local=ob->query("short");

//dir1=explode(base_name(environment(me)),"/");
dir2=explode(base_name(ob),"/");
//    if(sizeof(dir1)==3 && sizeof(dir2)==3 && dir1[0]=="d" && dir2[0]=="d" && dir1[1]!=dir2[1])
//{
      	if (dir2[1]=="baituo")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIR"°×ÍÕÉ½µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="binghuodao")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIB"±ù»ðµºµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="city")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"ÑïÖÝµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="city2" || dir2[1]=="beijing"  || dir2[1]=="huanggon"  || dir2[1]=="huanggong" || dir2[1]=="beihai")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIG"±±¾©³ÇµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="city4" || dir2[1]=="changan")   

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIM"³¤°²³ÇµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="dali")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+RED"´óÀíµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="emei")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+GRN"¶ðÃ¼É½µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="foshan")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+YEL"·ðÉ½µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="gaibang")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+BLU"Ø¤°ïµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="gaochang")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"¸ß²ýÃÔ¹¬µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="guanwai")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+CYN"¹ØÍâµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="guiyun")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+MAG"¹éÔÆ×¯µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="gumu")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+WHT"¹ÅÄ¹ÅÉµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="hangzhou")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"º¼ÖÝµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="heimuya")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ºÚÄ¾ÑÂµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="hengshan")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIB"ºãÉ½µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="henshan")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIW"ºâÉ½µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="huanghe")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"»ÆºÓ¾ÅÇúµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="huashan")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIG"»ªÉ½µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="jinshe")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+YEL"½ðÉßÉ½¶´µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="lingjiu")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"ÁéðÕ¹¬µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="lingzhou")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIB"ÁéÖÝµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="meizhuang")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIM"Ã·×¯µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="mingjiao")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"Ã÷½ÌµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="qingcheng")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIG"Çà³ÇÉ½µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="quanzhen")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIB"È«ÕæÅÉµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="quanzhou")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIG"ÈªÖÝµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="shaolin")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+YEL"ÉÙÁÖËÂµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="shenlong")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+GRN"ÉñÁúµºµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="songshan")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIM"áÔÉ½µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="suzhou")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"ËÕÖÝµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="taishan")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+MAG"Ì©É½µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="taohua")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+RED"ÌÒ»¨µºµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="tianlongsi")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÌìÁúËÂµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="wanjiegu")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIW"Íò½Ù¹ÈµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="wudang")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+GRN"Îäµ±É½µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="xiakedao")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+BLU"ÏÀ¿ÍµºµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="xiangyang")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"ÏåÑô³ÇµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="xiaoyao")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIG"åÐÒ£ÁÖµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="xingxiu")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+YEL"ÐÇËÞº£µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="xueshan")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIW"Ñ©É½ËÂµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="xuedao")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIW"´óÑ©É½µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="mr")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+BLU"Ä½ÈÝÊÀ¼ÒµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="kunlun")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+WHT"À¥ÂØÉ½µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="tiezhang")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIR"ÌúÕÆÃÅµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="huizhu")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"»Ø×å²¿ÂäµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="yinju")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIG"Ò»µÆ´óÊ¦¾ÓµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="menggu")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIG"ÃÉ¹Å²ÝÔ­µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="qianjin")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIM"±±¾©Ç§½ðÂ¥µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="lingshedao")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+BLU"ÁéÉßµºµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="ruzhou")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+RED"ÈêÖÝ³ÇµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="kunming")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIB"À¥Ã÷µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="jingzhou")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"¾£ÖÝµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="yanjing")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"Ñà¾©µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="lanzhou" || dir2[1]=="lanzhouchen")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+YEL"À¼ÖÝµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="jyguan")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"À¼ÖÝÒÔ±±¼ÎÓø¹ØµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="changcheng")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIW"±±¾©ÒÔ±±³¤³ÇµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="fairyland")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIW"À¥ÂØ¸½½üµÄºìÃ·É½×¯"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="sdxl")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIR"½£Ä§¶À¹ÂÇó°ÜÄ¹"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="jqg")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIG"¾øÇé¹È"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="nio")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIG"Å£¼Ò´åµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="feihu")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"´³Íõ±¦²ØµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="wuguan")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"ÏåÑôÎä¹ÝµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="village")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIG"»ªÉ½´åµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="taohuacun")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIR"ÌÒ»¨´åµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="pingan")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIG"Æ½°²³ÇµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="lingxiao")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIW"ÁèÏö³ÇµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="wudujiao")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIR"Îå¶¾½ÌµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="hj")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIG"ÌìÉ½¸½½ü²ÝÔ­µÄ"NOR+local+"¸½½ü¡£\n";
else if (dir2[1]=="dali/yuxu")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"´óÀíÓñÐé¹ÛµÄ"NOR+local+"¸½½ü¡£\n";
else if (dir2[1]=="dali/wuliang")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"´óÀíÎÞÁ¿É½µÄ"NOR+local+"¸½½ü¡£\n";
else if (dir2[1]=="huanghe/yyd")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"»ÆºÓÏô¸®µÄ"NOR+local+"¸½½ü¡£\n";
else if (dir2[1]=="kaifeng")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIM"¿ª·â³ÇµÄ"NOR+local+"¸½½ü¡£\n";
else if (dir2[1]=="feitian")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIR"·ÉÌìÓù½£Á÷µÄ"NOR+local+"¸½½ü¡£\n";
else if (dir2[1]=="japan")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÈÕ±¾Éñ»§µÄ"NOR+local+"¸½½ü¡£\n";
else if (dir2[1]=="tangmen")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIG"ÌÆÃÅµÄ"NOR+local+"¸½½ü¡£\n";
else if (dir2[1]=="luoyang")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÂåÑô³ÇµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="chengdu" || dir2[1]=="city3")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"³É¶¼µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="baihuagu")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"°Ù»¨¹ÈµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="heizhao")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"°Ù»¨¹È¸½½üºÚÕÓµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="jiaxing")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"¼ÎÐËµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="shiliang")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÎÂ¼Ò×¯µÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="wuyi")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÎäÒÄÉ½ÇøµÄ"NOR+local+"¸½½ü¡£\n";

else if (dir2[1]=="yanping")  

	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÑÓÆ½³ÇµÄ"NOR+local+"¸½½ü¡£\n";
	

else 	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚÄ³¸öµØ·½µÄ"+local+"¸½½ü,³ö¿ÚÊýÎª£º"+HIW""+ck+""+NOR"µÄµØ·½¡£\n";


if (dir2[1]=="jiangling")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"½­Áê³ÇµÄ"NOR+local+"¸½½ü¡£\n";
}

if (dir2[1]=="yueyang")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÔÀÑô³ÇµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="qilian")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÆîÁ¬É½µÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="shouxihu")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÊÝÎ÷ºþµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="wuxi")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÎÞÎý³ÇµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="yixing")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÒËÐË³ÇµÄ"NOR+local+"¸½½ü¡£\n";	
}
if (dir2[1]=="taiwan")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"Ì¨ÍåµØÇøµÄ"NOR+local+"¸½½ü¡£\n";	
}
if (dir2[1]=="nanyang")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÄÏÑôµØÇøµÄ"NOR+local+"¸½½ü¡£\n";	
}
if (dir2[1]=="nanshaolin")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÄÏÉÙÁÖµØÇøµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="cangzhou")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"²×ÖÝµØÇøµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="tanggu")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÌÁ¹Á³ÇµØÇøµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="yunhe")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"¾©º¼´óÔËºÓµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="hainan")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"º£ÄÏµºµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="jindezheng")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"¾°µÂÕòµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="yandang")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"Ñãµ´É½µÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="jinling")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"½ðÁê³ÇµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="sandboy")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"½­ÄÏÅ©´åµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="huangshan")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"»ÆÉ½µÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="yubifeng")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"Óñ±Ê·åµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="quanzhouchen")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÈªÖÝ³ÇÄÚµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="qingzh")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"Çà²Ø¸ßÔ­¸½½ü"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="changbaishan" || dir2[1]=="gaoli")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"¸ßÀö ³¤°×É½¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="annan")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"°²ÄÏ ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="taiyuan")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"Ì«Ô­ ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="hefei")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ºÏ·Ê ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="jiujiang")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"¾Å½­ ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="baling")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"°ÍÁê ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="xinjiang")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÐÂ½® ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}
if (dir2[1]=="dingxiang")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"¶¨Ïå ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}
if (dir2[1]=="suiye")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ËéÒ¶ ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}


if (dir2[1]=="mayi")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÂíÒØ±ß½® ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}
if (dir2[1]=="xuzhou")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÐìÖÝ³Ç ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}
if (dir2[1]=="jinan")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"¼ÃÄÏ³Ç ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}
if (dir2[1]=="guizhou")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"¹óÑô³Ç ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="nanchang")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÄÏ²ý³Ç ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}


if (dir2[1]=="changsha")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"³¤É³³Ç ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}


if (dir2[1]=="zhongzhou")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÖÐÖÝ³Ç ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="xizang" || dir2[1]=="zangbei")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"Î÷²Ø»ò²Ø±±¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="cloud" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"¶«±±ç²ÔÆÕò¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="xueting" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"¶«±±Ñ©Í¤Õò¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="ny" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"¶«±±ÄþÔ¶³Ç¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="fengtian" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIR"¶«±±Ê¢¾©³Ç¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="yanmen" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIB"ÑãÃÅ¹Ø¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="linzhi" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"Î÷²ØÁÖÖ¥µØÇø¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="datong" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"´óÍ¬¸®¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="tianshui" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÌìË®Õò¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="heifeng" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ºÚ·çÕ¯¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="paiyun" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ÅÅÔÆÕ¯¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}


if (dir2[1]=="yeyangzai" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"Ò°ÑòÕ¯¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}


if (dir2[1]=="jinghai" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"¾¸º£ÅÉ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="zuojiacun" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"»ªÍ¤Õò¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}


if (dir2[1]=="houjizhen" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"ºî¼¯Õò¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="huayin" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"Í­É½´å¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="lumaji" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"Â¹Âí¼¯¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}


if (dir2[1]=="xiyu/gaochang" || dir2[1]=="xiyu/hami" || dir2[1]=="xiyu")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"Î÷Óò±ß½®¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="xibei/desert" || dir2[1]=="xibei/kongdong" || dir2[1]=="xibei/liangzhou" || dir2[1]=="xibei/xingqing" || dir2[1]=="xibei")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+YEL"Î÷±±±ß½®¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="zhongyuan/chuzhou" || dir2[1]=="zhongyuan" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+GRN"ÖÐÔ­¹ØÖÐ¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="xinan/after_qingcheng" || dir2[1]=="xinan/cunzi" || dir2[1]=="xinan")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"Î÷ÄÏËÄ´¨¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="loulan" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"Â¥À¼¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="biancheng" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIG"±ß³Ç¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="quicksand" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"´óÉ³Ä®¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="tieflag/qianfo" || dir2[1]=="tieflag" || dir2[1]=="tieflag/palace" || dir2[1]=="tieflag/bat" || dir2[1]=="tieflag/chuenyu")  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"¶«º£ÇøÓò¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[2]=="fy" || dir2[2]=="fycycle")  
{
output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"·çÔÆ³Ç¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="taiping" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"Ì«Æ½Õò¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="eren/eren2" || dir2[1]=="eren" )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIC"¶ñÈË¹È¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (dir2[1]=="qujing"  )  
{
	output="¡º"+ob_list[i]->query("name")+"¡»ËÆºõÔÚ"+HIY"Î÷ÓòÖî¹ú¸½½üµÄ"NOR+local+"¸½½ü¡£\n";	
}

if (wizardp(this_player()))
{
//outputt +="¡º"+ob_list[i]->query("name")+"¡»ÔÚ"+dir2[1]+"µÄ"+local+"¸½½ü,³ö¿ÚÊýÎª£º"+HIW""+ck+""+NOR"µÄµØ·½¡£\n";
//output=outputt;
}
if (this_player()->query_temp("istask"))
{
output=output+" \n¾ÝËµ×îÓÐ¿ÉÄÜÔÚ£º"+playout;
this_player()->delete_temp("istask");
}

if (wizardp(this_player()) && ob)
{
output +=base_name(ob)+" \n";
}

	return output;

                }

                }

	}

                return "È·¶¨²»ÁË"+strr+"µÄ´ó¸ÅÎ»ÖÃ.\n";



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

        { ob=environment(ob);
          if(ob)
          if(ob->query("short") ) return ob;

     //   else ob=environment(ob);

        }

        return ob;

}

object find_book(object ob)

{

        while(ob)

        {

          if(ob->query("short") ) return ob;
//        if(ob->query("exits") ) return ob;
     
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

	tell_object(me,"ÄãÕæÐÐ£¡£¡\n");

}



void execute_accept_object(object me, object who, object item)

{

	who->accept_object(me,item);

}

