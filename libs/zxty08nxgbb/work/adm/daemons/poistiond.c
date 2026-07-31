// poistiond.c
// by player 2006-2-12 参考 pklist.c
/*说明：
me->query("mark/achievement")表示功绩、也就是贡献度
me->query("mark/guanzhi") 表示品级 数字对应几品 一共是九品十八级
me->query("rank_info/title2") 是title上显示的rank称呼
*/


#include <ansi.h>
#define capacity 30 //共存多少个
#define delaytime 2    //禁止2秒内连续用list

inherit ITEM;
inherit F_SAVE;

int sort_id(mapping ob1, mapping ob2);
int query_sortall(object me);
int do_list(object me);

void setup()
{
	string loc;

	if( stringp(loc = query("location")) )
		move(loc);
	set("no_get", "这个东西不能离开那里。\n");
	restore();
}

string query_save_file()
{
	return DATA_DIR + "poistiond";
}



int query_sortall(object me)
{
	mapping *notes;
	string a1,a2,a3;
        int i, turn=0, a0; //turn检查替换了老一个id
       	
	a0 = me->query("mark/achievement");
	a1 = me->query("mark/guanzhi");
	a2 = me->query("rank_info/title2");
	a3 = me->query("name")+"("+me->query("id")+")";
	
	notes = query("notes"); 
        

        if( !pointerp(notes) || !sizeof(notes) )//本来是空就增加一个
        {
		notes = allocate(capacity);
		for (i=0;i<capacity;i++) notes[i] = ([]);
        	notes[0]["achievement"] = a0;
		notes[0]["guanzhi"] = a1;
		notes[0]["title2"] = a2;
		notes[0]["name"] = a3;
		//write("本来是空就增加一个\n");
		set("notes", notes);
		save();
		return 1;
	}

            for (i=0;i<capacity;i++)  //已经上榜的更新
               if (notes[i]["name"] == a3) 
               	  {     notes[i]["achievement"] = a0;
			notes[i]["guanzhi"] = a1;
			notes[i]["title2"] = a2;
		  	set("notes", notes);
		  	//write("已经上榜的更新\n");
			save();
		  	return 1;
		  }
		  //没上榜看够capacity个了吗？
            for (i=0;i<capacity;i++)
        	if (nullp(notes[i]["name"]))
        	{
        		notes[i]["achievement"] = a0;
			notes[i]["guanzhi"] = a1;
			notes[i]["title2"] = a2;
			notes[i]["name"] = a3;	
		  	set("notes", notes);
			//write("没上榜看够capacity个了吗？\n");
			save();
			return 1;
        	}
        	//贡献大过最后一个才处理
        	for(i = 0; i<sizeof(notes); i++)
		if( notes[i]["achievement"] < a0 ) 
		{
			notes[i]["achievement"] = a0;
			notes[i]["guanzhi"] = a1;
			notes[i]["title2"] = a2;
			notes[i]["name"] = a3;
			//write("贡献大过最后一个才处理\n");
			set("notes", notes);
			save();
			return 1;
		}
		
	return 0;//没资格存
		
}

int remove()
{
	save();
	return 1;
}

int do_list(object me)
{
	mapping *notes, list, *list2;
	int i, j=1;
	string msg, pin;
	
	
	//if ((int)me->query_temp("achievement/delay-time") > time()) return 0;
	//me->set_temp("achievement/delay-time", (int)time() + delaytime);
	
	
	notes = query("notes");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("没有任何记录 \n");
	
	notes = sort_array(notes, "sort_id", this_object());
	msg=MUD_NAME+HIM+"官阶表\n\n"+NOR;
	msg += "名  次		名  号		官  职		 品  级\n";
	msg += "---------------------------------------------------------\n";
	for (i=0;i<sizeof(notes);i++)
		if (!nullp(notes[i]["name"]))
			{
				switch (notes[i]["guanzhi"]) {
	    				case 1:
	    				pin="从九品";
	    				break;
 	    				case 2:
	    				pin="正九品";
	    				break;
	    				case 3:
	    				pin="从八品";
	    				break;         				
	    				case 4:
	    				pin="正八品";
	    				break;
	    				case 5:
	    				pin="从七品";
	    				break;
	    				case 6:
	    				pin="正七品";
	    				break;
	    				case 7:
	    				pin="从六品";
	    				break;
	    				case 8:
	    				pin="正六品";
	    				break;
	    				case 9:
	    				pin="从五品";
	    				break;
	    				case 10:
	    				pin="正五品";
	    				break;
	    				case 11:
	    				pin="从四品";
	    				break;
	    				case 12:
	    				pin="正四品";
	    				break;
	    				case 13:
	    				pin="从三品";
	    				break;
	    				case 14:
	    				pin="正三品";
	    				break;
	    				case 15:
	    				pin="从二品";
	    				break;
	    				case 16:
	    				pin="正二品";
	    				break;
	    				case 17:
	    				pin="从一品";
	    				break;
	    				case 18:
	    				pin="正一品";
	    				break;
	    				}
				msg += sprintf("%-32s%-14s%-31s%-s\n", HIR"第"+chinese_number(j)+"名"NOR, notes[i]["name"], notes[i]["title2"],pin);
				j++;
			}

	msg += "---------------------------------------------------------\n";

	this_player()->start_more(msg);
	
	this_player()->set_temp("pklist/list",1);
	
	
	return 1;
}

int sort_id(mapping ob1, mapping ob2)
{
	if (!mapp(ob1) || !mapp(ob2) )
		return 0;
	return ob1["achievement"] >= ob2["achievement"] ? -1:1; 
}