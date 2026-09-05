// created by Zine 2012 for shediao quest
#include <ansi.h>
string to_dir(int x,int y,int dest_x,int dest_y);
mapping *wharf = ({
            ([  "x":-50,"y":50,"name":"归云庄附近的太湖码头","path":"/d/guiyunzhuang/matou","area":"归云庄"]),
			([  "x":-50,"y":-2,"name":"慕容山庄附近的太湖码头","path":"/d/murong/matou","area":"慕容"]),
			([  "x":24,"y":8,"name":"苏州附近的太湖码头","path":"/d/suzhou/matou","area":"苏州"]),
			([  "x":50,"y":-50,"name":"嘉兴附近的太湖码头","path":"/d/quanzhou/matou","area":"嘉兴"]),
        });
string look_view()
{
	object ob=this_object();
	int i,x=ob->query("x"),y=ob->query("y");
	string msg="";
	for (i=0;i<sizeof(wharf);i++)
	{
		msg+=wharf[i]["area"]+"在"+HBWHT+HIR+to_dir(x,y,wharf[i]["x"],wharf[i]["y"])+NOR+"方向 ";
	}
	if (!x||!y)
	{
		return msg+"\n太湖襟带三州，东南之水皆归于此，周行五百里，古称五湖。\n";
	}
	if (x>0&&y>0)
	{
		return msg+"\n远处隐隐可见一处泉眼，正汩汩的往外冒着水。\n";
	}
	if (x>0&&y<0)
	{
		return msg+"\n远处东洞庭山的莫厘峰被夹裹在一片雾气中。\n";
	}
	if (x<0&&y<0)
	{
		return msg+"\n一片湖光山色，美得令人惊讶。\n";
	}
	if (x<0&&y>0)
	{
		return msg+"\n不远处可以登录上到归云庄的码头。\n";
	}
}
int aftersing(object me,object huang)
{
	if (!me||!living(me))
	{
		return 1;
	}
	if (!huang||!living(huang))
	{
		return 1;
	}
	if (environment(me)!=this_object()||environment(huang)!=this_object())
	{
		return 1;
	}
	message_vision("不远处的渔人对$N和$n道：“舍下就在湖滨归云庄，不揣冒昧，想请两位去盘桓数日。”\n",huang,me);
	message_vision("$N和$n商议后，觉得这个渔人必有不凡之处，觉得此提议甚好。决定划回去(hua back)归云庄。\n",me,huang);
	huang->followme(me);
	me->set_temp("shediaoquest/guiyun/step",4);
	return 1;
}
int robber_appear(object me)
{
	object robber=new("/d/song/npc/judao");
	robber->set("owner",me);
	robber->move(this_object());
	message_vision("$N眼见甩不掉$n，决定铤而走险，乘着两船接舷，跳了过来，准备拘捕。\n",robber,me);
	robber->kill_ob(me);
	return 1;
}
int lu_appear(object me)
{
	object huang;
	if (!huang=present("huang rong",this_object()))
	{
		return 1;
	}
	if (huang->query("owner")!=me)
	{
		return 1;
	}
	huang->sing();
	me->set_temp("shediaoquest/guiyun/step",3);
	call_out("aftersing",1,me,huang);
	return 1;
}
string to_dir(int x,int y,int dest_x,int dest_y)
{
	if (dest_x>x)
	{
		x=1;
	}
	else if (dest_x==x)
	{
		x=0;
	}
	else
	{
		x=-1;
	}
	if (dest_y>y)
	{
		y=1;
	}
	else if (dest_y==y)
	{
		y=0;
	}
	else
	{
		y=-1;
	}
	if (x==1&&y==1)
	{
		return "东北";
	}
	if (x==1&&y==-1)
	{
		return "东南";
	}
	if (x==1&&y==0)
	{
		return "东";
	}
	if (x==-1&&y==1)
	{
		return "西北";
	}
	if (x==-1&&y==-1)
	{
		return "西南";
	}
	if (x==-1&&y==0)
	{
		return "西";
	}
	if (x==0&&y==1)
	{
		return "北";
	}
	if (x==0&&y==-1)
	{
		return "南";
	}
}
int check_shediao(object me,object ob)
{
	int x,y;
	string to_dir;
	if (ob->query("lu_x")&&ob->query("lu_y")&&me->query_temp("shediaoquest/guiyun/step")==2)
		{
			to_dir=to_dir(ob->query("x"),ob->query("y"),ob->query("lu_x"),ob->query("lu_y"));
			if (ob->query("x")==ob->query("lu_x")&&ob->query("y")==ob->query("lu_y"))
			{
				lu_appear(me);
				return 1;
			}
		}
		tell_room(this_object(),"这时，在"+to_dir+"方向传了了歌声。\n");
		if (!me->query_temp("shediaoquest/guiyun/song"))
		{
			me->set_temp("shediaoquest/guiyun/song",1);
			tell_object(me,HIR"歌词隐隐约约是：“回首妖氛未扫，问人间英雄何处？\n奇谋复国，可怜无用，尘昏白扇。铁锁横江，锦帆冲浪，孙郎良苦。\n但愁敲桂棹，悲吟梁父，泪流如雨。”\n"NOR);
		}
	return 1;
}
int check_xingbu(object me,object ob)
{
	int x,y;
	string to_dir;
	if (ob->query("xingbu_robber_x")&&ob->query("xingbu_robber_y"))
	{
		to_dir=to_dir(ob->query("x"),ob->query("y"),ob->query("xingbu_robber_x"),ob->query("xingbu_robber_y"));
			if (ob->query("x")==ob->query("xingbu_robber_x")&&ob->query("y")==ob->query("xingbu_robber_y"))
			{
				robber_appear(me);
				return 1;
			}
		}
		tell_room(this_object(),"根据之前的观察，巨盗应该是在"+to_dir+"的方向出没。\n");
		if (!me->query_temp("songtasks/xingbu/judao"))
		{
			me->set_temp("songtasks/xingbu/judao",1);
			tell_object(me,HIR"你刚划出未有多远，就发现了巨盗的行踪。\n"NOR);
		}
	return 1;
}
int do_hua(string dir)
{
	object *obs,ob=this_object(),me=this_player(),boat;
	string *dirs=({"north","south","east","west","northwest","northeast","southwest","southeast"}),c_dir;
	int i,n;
	if (dir=="back"&&me->query_temp("shediaoquest/guiyun/step")==4)
	{
		message_vision("$N将小船划向了归云庄的码头，停靠下来交还给渔家。\n",me);
		obs=all_inventory(ob);
		for (i=0;i<sizeof(obs);i++)
		{
			obs[i]->move("/d/guiyunzhuang/matou");
		}
		me->add_busy(2);
		me->set_temp("shediaoquest/guiyun/step",5);
		return 1;
	}
	if (dir=="back"&&me->query_temp("songtasks/xingbu/3/finish"))
	{
		message_vision("$N将小船划向了归云庄的码头，停靠下来交还给渔家。\n",me);
		obs=all_inventory(ob);
		for (i=0;i<sizeof(obs);i++)
		{
			obs[i]->move("/d/guiyunzhuang/matou");
		}
		me->add_busy(2);
		return 1;
	}
	if (member_array(dir,dirs)==-1)
	{
		tell_object(me,"划船的方向只能是north、south、east、west、northwest、northeast、southwest或是southeast。\n");
		return 1;
	}
	if (ob->query("y")>=50&&(dir=="north"||dir=="northeast"||dir=="northwest"))
	{
		tell_object(me,"已经划到太湖岸边了，不能再向北划了。\n");
		return 1;
	}
	if (ob->query("y")<=-50&&(dir=="south"||dir=="southeast"||dir=="southwest"))
	{
		tell_object(me,"已经划到太湖岸边了，不能再向南划了。\n");
		return 1;
	}
	if (ob->query("x")>=50&&(dir=="east"||dir=="southeast"||dir=="northeast"))
	{
		tell_object(me,"已经划到太湖岸边了，不能再向东划了。\n");
		return 1;
	}
	if (ob->query("x")<=-50&&(dir=="west"||dir=="southwest"||dir=="northwest"))
	{
		tell_object(me,"已经划到太湖岸边了，不能再向西划了。\n");
		return 1;
	}
	if (time()-ob->query("hua_time")<3+random(3))
	{
		tell_object(me,RED"小船只能划这么快了，再快就要拆散了。\n"NOR);
		return 1;
	}
	if (dir=="north")
	{
		ob->add("y",1);
		c_dir="北面";
	}
	if (dir=="south")
	{
		ob->add("y",-1);
		c_dir="南面";
	}
	if (dir=="east")
	{
		ob->add("x",1);
		c_dir="东面";
	}
	if (dir=="west")
	{
		ob->add("x",-1);
		c_dir="西面";
	}
	if (dir=="northwest")
	{
		ob->add("x",-1);
		ob->add("y",1);
		c_dir="西北";
	}
	if (dir=="northeast")
	{
		ob->add("x",1);
		ob->add("y",1);
		c_dir="东北";
	}
	if (dir=="southeast")
	{
		ob->add("x",1);
		ob->add("y",-1);
		c_dir="东南";
	}
	if (dir=="southwest")
	{
		ob->add("x",-1);
		ob->add("y",-1);
		c_dir="西南";
	}
	me->add_temp("taihu/hua",1);
	ob->set("hua_time",time());
	message_vision("$N将小船向"+c_dir+"方向划了过去。\n",me);
	for (i=0;i<sizeof(wharf);i++)
	{
		if (wharf[i]["x"]==ob->query("x")&&wharf[i]["y"]==ob->query("y"))
		{
			if (load_object(wharf[i]["path"]))
			{
				n=i;
				message_vision("$N将小船划向了岸边，停靠下来交还给渔家。\n",me);
				obs=all_inventory(ob);
				for (i=0;i<sizeof(obs);i++)
				{
					obs[i]->move(wharf[n]["path"]);
				}
				destruct(ob);
				return 1;
			}
		}
	}
	if (ob->query("x")<=0&&ob->query("y")>0)//归云
	{
		if (member_array(ob,children("/d/guiyunzhuang/boat2"))==-1)
		{
			boat=new("/d/guiyunzhuang/boat2");
			obs=all_inventory(ob);
			for (i=0;i<sizeof(obs);i++)
			{
				obs[i]->move(boat);
			}
			boat->set("x",ob->query("x"));
			boat->set("y",ob->query("y"));
			boat->set("hua_time",ob->query("hua_time"));
			if (ob->query("lu_x"))
			boat->set("lu_x",ob->query("lu_x"));
			if (ob->query("lu_y"))
			boat->set("lu_y",ob->query("lu_y"));
			if (ob->query("xingbu_robber_x"))
			boat->set("xingbu_robber_x",ob->query("xingbu_robber_x"));
			if (ob->query("xingbu_robber_y"))
			boat->set("xingbu_robber_y",ob->query("xingbu_robber_y"));
			if (me->query_temp("shediaoquest/guiyun/step"))
			boat->check_shediao(me,boat);
			if (me->query_temp("songtasks/xingbu/task")==3)
			boat->check_xingbu(me,boat);
			destruct(ob);
			return 1;
		}
	}
	if (ob->query("x")<0&&ob->query("y")<=0)//慕容
	{
		if (member_array(ob,children("/d/murong/boat2"))==-1)
		{
			boat=new("/d/murong/boat2");
			obs=all_inventory(ob);
			for (i=0;i<sizeof(obs);i++)
			{
				obs[i]->move(boat);
			}
			boat->set("x",ob->query("x"));
			boat->set("y",ob->query("y"));
			boat->set("hua_time",ob->query("hua_time"));
			if (ob->query("lu_x"))
			boat->set("lu_x",ob->query("lu_x"));
			if (ob->query("lu_y"))
			boat->set("lu_y",ob->query("lu_y"));
			if (ob->query("xingbu_robber_x"))
			boat->set("xingbu_robber_x",ob->query("xingbu_robber_x"));
			if (ob->query("xingbu_robber_y"))
			boat->set("xingbu_robber_y",ob->query("xingbu_robber_y"));
			if (me->query_temp("shediaoquest/guiyun/step"))
			boat->check_shediao(me,boat);
			if (me->query_temp("songtasks/xingbu/task")==3)
			boat->check_xingbu(me,boat);
			destruct(ob);
			return 1;
		}
	}
	if (ob->query("x")>0&&ob->query("y")>=0)//苏州
	{
		if (member_array(ob,children("/d/suzhou/boat2"))==-1)
		{
			boat=new("/d/suzhou/boat2");
			obs=all_inventory(ob);
			for (i=0;i<sizeof(obs);i++)
			{
				obs[i]->move(boat);
			}
			boat->set("x",ob->query("x"));
			boat->set("y",ob->query("y"));
			boat->set("hua_time",ob->query("hua_time"));
			if (ob->query("lu_x"))
			boat->set("lu_x",ob->query("lu_x"));
			if (ob->query("lu_y"))
			boat->set("lu_y",ob->query("lu_y"));
			if (ob->query("xingbu_robber_x"))
			boat->set("xingbu_robber_x",ob->query("xingbu_robber_x"));
			if (ob->query("xingbu_robber_y"))
			boat->set("xingbu_robber_y",ob->query("xingbu_robber_y"));
			if (me->query_temp("shediaoquest/guiyun/step"))
			boat->check_shediao(me,boat);
			if (me->query_temp("songtasks/xingbu/task")==3)
			boat->check_xingbu(me,boat);
			destruct(ob);
			return 1;
		}
	}
	if (ob->query("x")>=0&&ob->query("y")<0)//嘉兴
	{
		if (member_array(ob,children("/d/quanzhou/boat2"))==-1)
		{
			boat=new("/d/quanzhou/boat2");
			obs=all_inventory(ob);
			for (i=0;i<sizeof(obs);i++)
			{
				obs[i]->move(boat);
			}
			boat->set("x",ob->query("x"));
			boat->set("y",ob->query("y"));
			boat->set("hua_time",ob->query("hua_time"));
			if (ob->query("lu_x"))
			boat->set("lu_x",ob->query("lu_x"));
			if (ob->query("lu_y"))
			boat->set("lu_y",ob->query("lu_y"));
			if (ob->query("xingbu_robber_x"))
			boat->set("xingbu_robber_x",ob->query("xingbu_robber_x"));
			if (ob->query("xingbu_robber_y"))
			boat->set("xingbu_robber_y",ob->query("xingbu_robber_y"));
			if (me->query_temp("shediaoquest/guiyun/step"))
			boat->check_shediao(me,boat);
			if (me->query_temp("songtasks/xingbu/task")==3)
			boat->check_xingbu(me,boat);
			destruct(ob);
			return 1;
		}
	}
	if (me->query_temp("shediaoquest/guiyun/step"))
	check_shediao(me,ob);
	if (me->query_temp("songtasks/xingbu/task")==3)
	check_xingbu(me,ob);
	return 1;
}
void init()
{
	add_action("do_hua","hua");
	return;
}