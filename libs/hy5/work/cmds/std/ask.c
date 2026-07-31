// ask.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <ansi.h>
string query_inquiry(object ob);
inherit F_CLEAN_UP;
string  zuji(string str);
#include "/quest/giveaskgift.c"
void zujinpc(object me,object obj);
void zujinpc2(object me,object obj);

string *family_fame = ({
        "少林派",
        "武当派",
        "丐帮",
        "全真教",
        "华山派",
        "大理段家",
        "姑苏慕容",
        "雪山寺",
        "灵鹫宫",
        "峨嵋派",
        "桃花岛",
        "神龙教",
        "古墓派",
        "星宿派",
        "逍遥派",
        "白驼山派",
        "关外胡家",
        "飞天御剑流", 	
        "昆仑派",
        "南少林派",
        "明教",
        "云龙门",
        "五毒教",
        "铁掌帮",
        "唐门",
        "凌霄城",
        "红花会",
        "嵩山派",
        "泰山派",
        "青城派",
        "恒山派",
        "衡山派",
        "梅庄",
        "日月神教",
"靖海派",
"白云庵",
"侠客岛",
"崆峒派",
"雁荡派",	
});
string *msg_dunno = ({
	"$n摇摇头，说道：没听说过。\n",
	"$n疑惑地看着$N，摇了摇头。\n",
	"$n睁大眼睛望着$N，显然不知道$P在说什么。\n",
	"$n耸了耸肩，很抱歉地说：无可奉告。\n",
	"$n说道：嗯....这我可不清楚，你最好问问别人吧。\n",
	"$n想了一会儿，说道：对不起，你问的事我实在没有印象。\n",
});

int main(object me, string arg)
{
	string dest, topic, msg;
	object ob,letter,room2,env,letter2,*inv;
	mapping inquiry;
        string str;
int exp,pot,j,i,k;
        string room;
string file,envn;
string *roomlines;
string location,local,fname;
string *dir2;
mapping quest;
string my_file;
object newob, *ob_list;

    string week, month, year, day, time,hydata;
    string check;
 	    

	seteuid(getuid());
			str=read_file("/log/NEWS");
sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);
        if( me->is_busy() )
                return notify_fail("您先歇口气再说话吧。\n");

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("你要问谁什么事？\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("这里没有这个人。\n");

	if( !ob->is_character() ) {
		message_vision("$N对着$n自言自语....\n", me, ob);
		return 1;
	}

	if( !living(ob) ) 
		return notify_fail("你必须先把" + ob->name() + "弄醒。\n");

	if( !ob->query("can_speak") ) {
		message_vision("$N向$n打听有关『" + topic + "』的消息，但是$p显然听不懂人话。\n", me, ob);
		return 1;
	}

if (me->query_temp("big5") && userp(me) && topic!="" ) 
topic=LANGUAGE_D->Big52GB(topic); 


	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);

if (me->is_busy()) return notify_fail("你正在忙。\n");
if (ob->is_busy() && topic!="回家") return notify_fail("我正在忙。\n");


//me->start_busy(1);


if( me!=ob && userp(ob) && ob->query_temp("hdjoblb")  && ob->query_temp("hdjobtg") && topic=="news" )
{
	//ob->start_busy(1);
me->set_temp("tjoblx",0);
me->delete_temp("tjoblx");	
if (me->query_temp("tjobstart")>=3)
{
message_vision("$n说道,听说你接了很多事，却没一件完成？\n", me, ob);	
return 1;
}

if (me->query_condition("taskjob_busy"))
{
message_vision("$n说道,你才接了别的任务，你过一会再来吧。\n", me, ob);	
return 1;
}
me->apply_condition("taskjob_busy",16);


me->add_temp("tjobstart",1);	
message_vision("$n说道,我有一个事要麻烦你一下。是这样的:" + ob->query_temp("hdjobsc") + " 完成后必有重赏。\n", me, ob);
if( ob->query_temp("hdjoblb")=="会面")
{
ob->set_temp("ishm",1);
me->clear_condition("taskjob_busy");
}
}

if( me!=ob && userp(ob) && ob->query_temp("hdjoblb")  && ob->query_temp("hdjobtg") && topic=="job" )
{
	me->set_temp("tjoblx",0);
me->delete_temp("tjoblx");	
me->set_temp("nbjob38",1);

exp=388+random(188);
if ((int)me->query_temp("hdjobsl",1)>=90) me->set_temp("hdjobsl",90);
message_vision("$n点了点头。\n", me, ob);
if( ob->query_temp("hdjoblb")=="挑战")
{
message_vision("$n说道,我认输，我最近很忙，不要来找我挑战了。\n", me, ob);
ob->delete_temp("hdjoben");
ob->delete_temp("hdjoblb");
ob->delete_temp("hdjobtg");
ob->delete_temp("hdjobsc");	
addnl(me,"exp",exp);
me->apply_condition("taskjob_busy",16);
return 1;
}	

if( ob->query_temp("hdjoblb")=="会面")
{
if (environment(ob))
{
		inv = all_inventory(environment(ob));
		for(i=0; i<sizeof(inv); i++) {
			if( !userp(inv[i]) && inv[i]->query("name")==ob->query_temp("hdjobtg") ) 
{
if (exp> 800) exp=800;
if ((int)me->query_temp("hdjobsl",1)>=1) exp=exp+((int)me->query_temp("hdjobsl",1)*30);
addnl(me,"exp",3000+exp);	
addnl(ob,"exp",2000+exp);
ob->delete_temp("hdjoben");
ob->delete_temp("hdjoblb");
ob->delete_temp("hdjobtg");
ob->delete_temp("hdjobsc");	
me->clear_condition("taskjob_busy");
me->set_temp("tjobstart",0);
me->delete_temp("tjobstart");
message_vision("$n说道,不错不错，我终于见到了"+inv[i]->query("name")+"。\n", me, ob);

return 1;
}				
}
		}


if (!ob->query_temp("ishm"))
{
message_vision("$n说道,我最近很忙，没空去见人。\n", me, ob);
ob->delete_temp("hdjoben");
ob->delete_temp("hdjoblb");
ob->delete_temp("hdjobtg");
ob->delete_temp("hdjobsc");	
me->apply_condition("taskjob_busy",18);
addnl(me,"exp",exp);
}
else
{
message_vision("$n说道,已经有人接了这个任务了。\n", me, ob);	
}	
return 1;
}

message_vision("$n说道,我有一个事要麻烦你一下。是这样的:" + ob->query_temp("hdjobsc") + "，完成后必有重赏。\n", me, ob);
if (!me->query("zhuanshen")) addnl(me,"exp",exp);
addnl(ob,"exp",exp);
if (ob->query_temp("hdjoblb")=="送货")
{
        letter = new("/quest/huowo");
        letter->set("hwtg",ob->query_temp("hdjobtg"));
        letter->set("long"," "+ob->query_temp("hdjobsc")+"\n");
        letter->move(me);
	
}

if (ob->query_temp("hdjoblb")=="互动")
{
    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());

        newob = ob_list[random(sizeof(ob_list))];
if(newob->query("id")==ob->query("id")) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob)) newob = ob_list[random(sizeof(ob_list))];
if(!living(newob)) newob = ob_list[random(sizeof(ob_list))];

if(newob->query("id")==ob->query("id")) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob)) newob = ob_list[random(sizeof(ob_list))];
if(!living(newob)) newob = ob_list[random(sizeof(ob_list))];

if(newob->query("id")==ob->query("id")) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob)) newob = ob_list[random(sizeof(ob_list))];
if(!living(newob)) newob = ob_list[random(sizeof(ob_list))];

	
if (newob)
{
env=environment(newob);
if (env)
{
dir2=explode(base_name(env),"/");
envn=zuji(dir2[1])+"-"+env->query("short");
}
if (newob)
{
message_vision("$n说道:把礼物送到" + newob->query("name") + "("+ newob->query("id") + ")的手上，完成后必有重赏。\n", me, ob);
        letter = new("/quest/liwo");
        letter->set("hwtg",newob->query("id"));
        letter->set("long","送给"+envn+"附近的:"+newob->query("name")+"("+ newob->query("id") + ")的礼物。\n");
        me->set_temp("hdjob2sc","送礼物给"+envn+"附近的:"+newob->query("name")+"("+ newob->query("id") + ")。\n");
        me->set_temp("hdjob2tg",newob->query("id"));
        letter->move(me);
}
else return 0;
}
}
		
if (ob->query_temp("hdjoblb")=="仇杀")
{
room2=load_object(ob->query_temp("hdjobtg"));
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
       letter = new("/quest/boss");
       letter->move(ob->query_temp("hdjobtg"));
       letter->set_name(letter->query("name"),({ me->query("id")+" "+letter->query("id")}));
letter->set("killbyn",me->query("id"));
zujinpc(me,letter);	
message_vision("$n说道,听说我的死敌:" + letter->query("name") + "在"+room+"附近，把这个事处理了吧,完成后必有重赏。\n", me, ob);

}		


if (ob->query_temp("hdjoblb")=="寻物") 
{
ob->set_temp("hdjobxh",ob->query_temp("hdjobtg"));
}
me->set_temp("hdjob2lb",ob->query_temp("hdjoblb"));
if (ob->query_temp("hdjoblb")!="互动")
{
me->set_temp("hdjob2tg",ob->query_temp("hdjobtg"));
me->set_temp("hdjob2sc",ob->query_temp("hdjobsc"));
}

if (ob->query_temp("hdjoblb")=="悬赏")  me->set_temp("roomjob",ob->query_temp("hdjobtg"));
if (ob->query_temp("hdjoblb")=="刺探")  me->set_temp("roomjob",ob->query_temp("hdjobtg"));
if (ob->query_temp("hdjoblb")=="江湖")  me->set_temp("roomjob",ob->query_temp("hdjoben"));
if (ob->query_temp("hdjoblb")=="仇杀") me->set_temp("hdjob2sc",ob->query_temp("hdjobsc")+"附近的"+letter->query("name"));

ob->delete_temp("hdjoben");
ob->delete_temp("hdjoblb");
ob->delete_temp("hdjobtg");
ob->delete_temp("hdjobsc");
	 return 1;
}


if( me!=ob && !userp(ob) && ob->query_temp("nhdjoblb")  && ob->query_temp("nhdjobtg") && topic=="job")
{	
me->set_temp("tjoblx",0);
me->delete_temp("tjoblx");
if (me->query_temp("tjobstart")>=3)
{
message_vision("$n说道,听说你接了很多事，却没一件完成？\n", me, ob);	
return 1;
}
if (me->query_condition("taskjob_busy"))
{
message_vision("$n说道,你才接了别的任务，你过一会再来吧。\n", me, ob);	
return 1;
}
me->apply_condition("taskjob_busy",16);

env=environment(ob);
dir2=explode(base_name(env),"/");
envn=zuji(dir2[1])+"-"+env->query("short");
my_file = read_file("/log/taskjob");
my_file= replace_string(my_file,envn,"(已执行)");
write_file("/log/taskjob",my_file,1);
exp=88+random(88);
if (!me->query("zhuanshen")) addnl(me,"exp",exp);
me->set_temp("tjoblx",0);
me->delete_temp("tjoblx");
me->add_temp("tjobstart",1);
me->set_temp("nbjob37",1);
if ((int)me->query_temp("nhdjobsl",1)>=90) me->set_temp("nhdjobsl",90);
message_vision("$n说道,有这样一个事。是这样的:" + ob->query_temp("nhdjobsc") + "。\n", me, ob);
if (ob->query_temp("nhdjoblb")=="武林送货")
{
        letter = new("/quest/task/huowo");
        letter->set("nhwtg",ob->query_temp("nhdjobtg"));
        letter->set("long"," "+ob->query_temp("nhdjobsc")+"\n");
        letter->move(me);
message_vision("$n说道,货物就麻烦你了一定要好好送到,对方生意正急着用呢。\n", me, ob);
	
}
if (ob->query_temp("nhdjoblb")=="边疆御敌")
{
room2=load_object(ob->query_temp("nhdjobtg"));
if (room2) local=room2->query("short");
me->set_temp("nhdjob2tg",ob->query_temp("nhdjobtg"));
me->set_temp("roomjob",local);
message_vision("$n说道,听说敌军人马，一路烧杀而来。一定要保卫好大好河山。\n", me, ob);
}

if (ob->query_temp("nhdjoblb")=="门派守护")
{
room2=load_object(ob->query_temp("nhdjobtg"));
if (room2) local=room2->query("short");
me->set_temp("nhdjob2tg",ob->query_temp("nhdjobtg"));
me->set_temp("roomjob",local);
message_vision("$n说道,近日黑道联盟要有大举动，形势不妙。一定要消灭这些敌人。\n", me, ob);
}


if (ob->query_temp("nhdjoblb")=="江湖追杀")
{
room2=load_object(ob->query_temp("nhdjobtg"));
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
       letter = new("/quest/task/boss");
       letter->move(ob->query_temp("nhdjobtg"));
       letter->set_name(letter->query("name"),({ me->query("id")+" "+letter->query("id")}));
letter->set("killbyn",me->query("id"));
zujinpc(me,letter);	
letter->random_move();
message_vision("$n说道,听说武林公敌:" + letter->query("name") + "在"+room+"附近出现。\n", me, ob);
message_vision("$n说道,一定要把他除去。只要找到他，格杀勿论！\n", me, ob);
}		

if (ob->query_temp("nhdjoblb")=="保镖护送")
{
room2=load_object(ob->query_temp("nhdjobtg"));
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
       letter = new("/quest/task/hsnpc");
       letter->move(environment(ob));
       letter->set_name(letter->query("name"),({ me->query("id")+" "+letter->query("id")}));
letter->set("hstg",ob->query_temp("nhdjobtg"));
letter->set("hsr",me->query("id"));
me->apply_condition("taskjob_busy",22);
message_vision("$n说道,我的朋友:" + letter->query("name") + "想到"+room+"去 麻烦你护送一下吧。\n", me, ob);
message_vision("$n说道,希望你们一路顺风 平安到达。\n", me, ob);
}

if (ob->query_temp("nhdjoblb")=="宝物争夺")
{
room2=load_object(ob->query_temp("nhdjobtg"));
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
       letter = new("/quest/task/boss2");
       letter->move(ob->query_temp("nhdjobtg"));
       letter->set_name(letter->query("name"),({ me->query("id")+" "+letter->query("id")}));
letter->set("killbyn",me->query("id"));
zujinpc(me,letter);	
letter2 = new("/quest/task/mijian");
letter2->move(letter);
letter2->set("killbyn",ob->query("id"));
letter->random_move();
message_vision("$n说道,我有一件宝物给" + letter->query("name") + "抢走了，帮我找回吧。\n", me, ob);
message_vision("$n说道,一定帮我抢回来额。用他的血来给邪门歪道一个警告。\n", me, ob);
}

if (ob->query_temp("nhdjoblb")=="人物探寻")
{
room2=load_object(ob->query_temp("nhdjobtg"));
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
       letter = new("/quest/task/hsnpc");
       letter->move(room2);
       letter->set_name(letter->query("name"),({ me->query("id")+" "+letter->query("id")}));
letter->set("hstg",base_name(environment(ob))+".c");
letter->set("hsr",me->query("id"));
me->apply_condition("taskjob_busy",22);
message_vision("$n说道,我的朋友" + letter->query("name") + "在"+room+" 麻烦你把他护送到我这吧。\n", me, ob);
message_vision("$n说道,一路顺风 平安归来。\n", me, ob);
}

if (ob->query_temp("nhdjoblb")=="寻找物品") 
{
ob->set_temp("nhdjobxh",ob->query_temp("nhdjobtg"));
message_vision("$n说道,这个事很简单,请尽快帮我带来吧。\n", me, ob);
}

if (ob->query_temp("nhdjoblb")=="情报刺探") 
{
me->set_temp("roomjob",ob->query_temp("nhdjobtg"));
me->set_temp("nhdjob2tg",ob->query_temp("nhdjobtg"));
message_vision("$n说道,这个事再简单不过了,请尽快去刺探吧。\n", me, ob);
}

me->set_temp("nhdjob2lb",ob->query_temp("nhdjoblb"));
me->set_temp("nhdjob2tg",ob->query_temp("nhdjobtg"));
me->set_temp("nhdjob2sc","接收地点:"+envn+":"+" 发布人:"+ob->query("name")+":"+" 任务内容:"+ob->query_temp("nhdjobsc"));
ob->delete_temp("nhdjoblb");
ob->delete_temp("nhdjobtg");
ob->delete_temp("nhdjobsc");
ob->delete_temp("nhdjoben");
	 return 1;
}

	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		message_vision("但是很显然的，$n现在的状况没有办法给$N任何答覆。\n",
			me, ob);
		return 1;
	}
	hydata=year+month+day;
	
		if( (!me->query("jobdata") || me->query("jobdata")!=hydata) && me->is_apprentice_of(ob)   && (topic=="job" || topic=="jobs")) {
		message_vision("$N恭恭敬敬地向$n磕头请安，叫道：「师父！」\n", me, ob);

ob->start_busy(1);
//write(hydata);

    if ( !wizardp(me) && me->query("jobdata")==hydata)
{
		message_vision("$n说到，今天的任务，不是已经给你了吗? \n", me, ob);
		return 1;
}

if ( me->query("jobdata")!=hydata || wizardp(me))
{
	i=random(9)+1;
	if (me->query("combat_exp",1) < 3000000 ) i=random(4)+1;
	//if (random(2)==0) i=random(4)+1;
	
	if (i==1)
{
	j=10;
	if (me->query("zhuanshen")) j=20;
me->set("jobtime",1);	
me->set("jobtg",j);	
message_vision("$n说到，师门有件事要你完成，是这样的 到任务吏那用quest领"+chinese_number(j)+"次个人任务(help geren)做吧，做好的记的来找我 (ask about ok) 。 \n", me, ob);
}
	if (i==2)
{
	j=20;
	if (me->query("zhuanshen")) j=50;
me->set("jobtime",2);	
me->set("jobtg",j);	
message_vision("$n说到，师门有件事要你完成，是这样的 到任务吏那用job领"+chinese_number(j)+"次对练任务(help geren)做吧，做好的记的来找我 (ask about ok) 。 \n", me, ob);

}
	if (i==3)
{
	j=1;
	if (me->query("zhuanshen")) j=3;
me->set("jobtime",3);	
me->set("jobtg",j);	
message_vision("$n说到，师门有件事要你完成，是这样的 比武战胜"+chinese_number(j)+"个玩家，做好的记的来找我 (ask about ok)  。\n", me, ob);

}
	if (i==4)
{
	j=8;
	if (me->query("zhuanshen")) j=16;
	room=family_fame[random(39)];
      //扬威任务	
if (room==me->query("family/family_name")) room=family_fame[random(8)];
if (room==me->query("family/family_name")) room=family_fame[random(16)];
if (room==me->query("family/family_name")) room=family_fame[random(22)];
if (room==me->query("family/family_name")) room=family_fame[random(28)];
if (room==me->query("family/family_name")) room=family_fame[random(33)];
if (room==me->query("family/family_name")) room=family_fame[random(39)];
me->set("jobtime",4);	
me->set("jobtgn",room);	
me->set("jobtg",j);	
message_vision("$n说到，师门有件事要你完成，是这样的 去"+room+"附近，干掉他们"+chinese_number(j)+"个人(kantou)。 做好记的来找我 (ask about ok)  。\n", me, ob);

}
	if (i==5)
{
	j=3;
	if (me->query("zhuanshen")) j=8;
me->set("jobtime",5);	
me->set("jobtg",j);	
message_vision("$n说到，师门有件事要你完成，是这样的 完成"+chinese_number(j)+"次襄阳守城任务(help guojob)，做好的记的来找我 (ask about ok) 。 \n", me, ob);

}
	if (i==6)
{
	j=3;
		if (me->query("zhuanshen")) j=8;
me->set("jobtime",6);	
me->set("jobtg",j);	
message_vision("$n说到，师门有件事要你完成，是这样的 完成"+chinese_number(j)+"次襄阳护送任务(help wangjob)，做好的记的来找我 (ask about ok)  。\n", me, ob);
}
	if (i==7)
{
	j=1;
			if (me->query("zhuanshen")) j=3;
me->set("jobtime",7);	
me->set("jobtg",j);	
message_vision("$n说到，师门有件事要你完成，是这样的 完成"+chinese_number(j)+"次江湖谣言任务(help taskjobs)，查出最后真凶，做好的记的来找我 (ask about ok)  。\n", me, ob);

}
	if (i==8)
{
	j=3;
				if (me->query("zhuanshen")) j=8;
me->set("jobtime",8);	
me->set("jobtg",j);	
message_vision("$n说到，师门有件事要你完成，是这样的 到任务吏那领"+chinese_number(j)+"次组队任务(help teamjob)做吧，做好的记的来找我 (ask about ok) 。\n", me, ob);
}

	if (i==9)
{
	j=10;
				if (me->query("zhuanshen")) j=20;
me->set("jobtime",9);	
me->set("jobtg",j);	
message_vision("$n说到，师门有件事要你完成，是这样的 完成"+chinese_number(j)+"次官府任务(help guanfu) 做好的记的来找我 (ask about ok) 。 \n", me, ob);
}

}

me->set("jobdata",hydata);

		return 1;
	}
	
	if( me->is_apprentice_of(ob)   && topic=="ok" && me->query("jobtg") ) {
		message_vision("$N恭恭敬敬地向$n磕头请安，叫道：「师父！」\n", me, ob);

hydata=year+month+day;
//write(hydata);
if (wizardp(me)) message_vision("$N恭恭敬敬地向$n磕头"+me->query("jobtime")+"，"+me->query("jobtg")+"\n", me, ob);

    if ( ! me->query("jobdata") || ! me->query("jobtime"))
{
		message_vision("$n说到，今天的任务，给你了吗? \n", me, ob);
		return 1;
}

    if ( (int)me->query("jobtg",1)==0)
{
		message_vision("$n说到，今天的任务，不是已经完成了嘛。 \n", me, ob);
		return 1;
}

if ( me->query("jobdata") )
{
i=(int)me->query("jobtime",1);
	if (i==1)
{
	k=me->query_temp("mpjobn1",1);
message_vision("$n说到，个人门派任务,你已经完成了"+chinese_number(k)+"个任务 。 \n", me, ob);	
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
me->delete_temp("mpjobn1");
message_vision("$n说到，做的不错，我就指点你两手武功吧 。 \n", me, ob);
}
}
	if (i==2)
{
	k=me->query_temp("mpjobn3",1);
	message_vision("$n说到，对练任务 你已经完成了"+chinese_number(k)+"个任务 。 \n", me, ob);
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
me->delete_temp("mpjobn3");
message_vision("$n说到，做的不错，我就指点你两手武功吧 。 \n", me, ob);
}
}
	if (i==3)
{
		k=me->query_temp("mpjobn4",1);
		message_vision("$n说到，比武任务 你已经完成了"+chinese_number(k)+"个任务 。 \n", me, ob);
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
me->delete_temp("mpjobn4");
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
message_vision("$n说到，做的不错，我就指点你两手武功吧 。 \n", me, ob);
}
}
	if (i==4)
{
k=me->query_temp("mpjobn5",1);
message_vision("$n说到，扬威任务 你已经完成了"+chinese_number(k)+"个任务 。 \n", me, ob);	
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
me->delete_temp("mpjobn5");
message_vision("$n说到，做的不错，我就指点你两手武功吧 。 \n", me, ob);
}
}
	if (i==5)
{
	k=me->query_temp("mpjobn6",1);
	message_vision("$n说到，襄阳守城任务 你已经完成了"+chinese_number(k)+"个任务 。 \n", me, ob);	
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
me->delete_temp("mpjobn6");
message_vision("$n说到，做的不错，我就指点你两手武功吧 。 \n", me, ob);
}
}
	if (i==6)
{
		k=me->query_temp("mpjobn7",1);
		message_vision("$n说到，襄阳护送任务 你已经完成了"+chinese_number(k)+"个任务 。 \n", me, ob);	
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
me->delete_temp("mpjobn7");
message_vision("$n说到，做的不错，我就指点你两手武功吧 。 \n", me, ob);
}
}
	if (i==7)
{
		k=me->query_temp("mpjobn8",1);
		message_vision("$n说到，江湖任务 你已经完成了"+chinese_number(k)+"个任务 。 \n", me, ob);	
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
me->delete_temp("mpjobn8");
message_vision("$n说到，做的不错，我就指点你两手武功吧 。 \n", me, ob);
}
}
	if (i==9)
{
		k=me->query_temp("mpjobn9",1);
		message_vision("$n说到，官府任务 你已经完成了"+chinese_number(k)+"个任务 。 \n", me, ob);	
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
me->delete_temp("mpjobn9");
message_vision("$n说到，做的不错，我就指点你两手武功吧 。 \n", me, ob);
}
}

	if (i==8)
{
		k=me->query_temp("mpjobn2",1);
		message_vision("$n说到，门派组队任务 你已经完成了"+chinese_number(k)+"个任务 。 \n", me, ob);	
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
me->delete_temp("mpjobn2");
message_vision("$n说到，做的不错，我就指点你两手武功吧 。 \n", me, ob);
}
}

}

me->set("jobdata",hydata);

		return 1;
	}
	
	
	if( msg = ob->query("inquiry/" + topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$N说道：" + msg + "\n" NOR, ob);
			return 1;
		}
	} else {
  	        if(ob->query("race")=="野兽") {
			message_vision("但是很可惜，$N不会说话。\n", ob);
			return 1;
		}
		switch(topic) {
			case "name":
			message_vision( CYN "$N说道：我的名字就是$N," + RANK_D->query_respect(me)+ "有什么事?\n" NOR, ob);
				break;
			case "here":
				message_vision(CYN "$n对$N说道：这里是" + environment(ob)->query("short") + "，其它情况" + RANK_D->query_self(ob) + "也不太清楚。\n" NOR, me, ob);
				break;
			case "rumors":
			message_vision( CYN "$N对你说到,最近听有人说过:"+str+"" NOR, ob);				break;
			default:
		if(topic=="news")
			{
                        if (!str)
			{
			message_vision( CYN "$N对你说到,最近没什么新闻可说.." NOR, ob);
			}
else {
			message_vision( CYN "$N对你说到,最近听有人说过:"+str+"" NOR, ob);
}
			return 1;
		}	
		if(topic=="all")
			{
			message_vision( CYN "$N对你悄声说道:"+query_inquiry(ob)+"!\n" NOR, ob);
			return 1;
		}
				if (topic == ob->query("name") || ob->id(topic))
				message_vision(CYN "$n说道：那就是" + RANK_D->query_self_rude(ob) + "呀。\n" NOR, me, ob);
				else if (topic == me->query("name") || me->id(topic))
				message_vision(CYN "$n说道：那就是" + RANK_D->query_rude(me) + "你呀。\n" NOR, me, ob);
                                else if (topic == ob->query("name") || ob->id(topic))
				EMOTE_D->do_emote(ob, "name1");
else if (ob->query("combat_exp") < 500000)
{
                                if (strsrch(topic,"北京")>= 0 || strsrch(topic,"京城")>= 0)
                                message_vision(CYN "$n说道：那里是京城,听说那里的千金楼不错。\n" NOR, me, ob);
                                else if (strsrch(topic,"郭靖")>= 0 || strsrch(topic,"北侠")>= 0)
                                message_vision(CYN "$n说道：人称北侠的郭靖，既是蒙古成吉思汗的金刀驸马，又是
江南七怪、全真派马钰道长、「北丐」洪七公和「老顽童」周伯通等人的徒弟，身兼数门武功n" NOR, me, ob);
                                else if (strsrch(topic,"少林派")>= 0 || strsrch(topic,"少林")>= 0)
                                message_vision(CYN "$n说道：天下第一大门派就是少林。n" NOR, me, ob);
                                else if (strsrch(topic,"武当派")>= 0 || strsrch(topic,"武当")>= 0)
                                message_vision(CYN "$n说道：武当张真人是我的偶像。n" NOR, me, ob);
                                else if (strsrch(topic,"明 教")>= 0 || strsrch(topic,"明教")>= 0)
                                message_vision(CYN "$n说道：天下第一教，是人称魔教的明教。n" NOR, me, ob);
                                else if (strsrch(topic,"华山派")>= 0 || strsrch(topic,"华山")>= 0)
                                message_vision(CYN "$n说道：独孤九剑可是天下第一剑。n" NOR, me, ob);
                                else if (strsrch(topic,"姑苏慕容")>= 0 || strsrch(topic,"慕容")>= 0)
                                message_vision(CYN "$n说道：都什么朝代了, 还要什么大燕国。n" NOR, me, ob);
                                else if (strsrch(topic,"桃花岛")>= 0 || strsrch(topic,"桃花")>= 0)
                                message_vision(CYN "$n说道：桃花岛上奇门武功，怪东西可不少。n" NOR, me, ob);
                                else if (strsrch(topic,"大理段家")>= 0 || strsrch(topic,"天龙寺")>= 0)
                                message_vision(CYN "$n说道：六脉神剑、凌波微步我先学哪个更好呢？n" NOR, me, ob);
                                else if (strsrch(topic,"丐帮")>= 0 || strsrch(topic,"丐帮")>= 0)
                                message_vision(CYN "$n说道：天下第一帮么，自然是丐帮了。n" NOR, me, ob);
                                else if (strsrch(topic,"古墓")>= 0 || strsrch(topic,"古墓派")>= 0)
                                message_vision(CYN "$n说道：神雕侠侣，相继亡故，不知古墓一派可有传人？n" NOR, me, ob);
                                else if (strsrch(topic,"神龙教")>= 0 || strsrch(topic,"神龙")>= 0)
                                message_vision(CYN "$n说道：洪教主神通护佑，众弟子勇气百倍，以一当百.....n" NOR, me, ob);
                                else if (strsrch(topic,"大轮寺")>= 0 || strsrch(topic,"雪山寺")>= 0)
                                message_vision(CYN "$n说道：大雪山令人向往，我想去很久了？n" NOR, me, ob);
                                else if (strsrch(topic,"星宿派")>= 0 || strsrch(topic,"星宿")>= 0)
                                message_vision(CYN "$n说道：星宿派都是用毒高手!和无耻之徒n" NOR, me, ob);
                                else if (strsrch(topic,"铁掌帮")>= 0 || strsrch(topic,"铁掌")>= 0)
                                message_vision(CYN "$n说道：那猴爪山共有五个山峰,就像猴儿的手掌一般。n" NOR, me, ob);
                                else if (strsrch(topic,"嵩山派")>= 0 || strsrch(topic,"五岳剑派")>= 0)
                                message_vision(CYN "$n说道：据说五岳剑派就要合并了。n" NOR, me, ob);
                                else if (strsrch(topic,"峨嵋派")>= 0 || strsrch(topic,"峨嵋")>= 0)
                                message_vision(CYN "$n说道：峨嵋山的小师傅们可是漂亮的很啊，嘿嘿。n" NOR, me, ob);
                                else if (strsrch(topic,"灵鹫宫")>= 0 || strsrch(topic,"灵鹫")>= 0)
                                message_vision(CYN "$n说道：灵鹫宫上可都是大美女，一个个长的像仙女一样。n" NOR, me, ob);
                                else if (strsrch(topic,"白驼山庄")>= 0 || strsrch(topic,"白驼")>= 0)
                                message_vision(CYN "$n说道：听说白驼山上有很多蛇,好可怕啊。n" NOR, me, ob);
                                else if (strsrch(topic,"逍遥派")>= 0 || strsrch(topic,"逍遥")>= 0)
                                message_vision(CYN "$n说道：逍遥派好像和灵鹫宫的人常常来往。n" NOR, me, ob);
                                else if (strsrch(topic,"昆仑派")>= 0 || strsrch(topic,"昆仑")>= 0)
                                message_vision(CYN "$n说道：那里的人能文能武。琴剑双绝。n" NOR, me, ob);
                                else if (strsrch(topic,"日月神教 ")>= 0 || strsrch(topic,"日月")>= 0)
                                message_vision(CYN "$n说道：日出东方，唯我不败。n" NOR, me, ob);
                                else if (strsrch(topic,"昆仑派")>= 0 || strsrch(topic,"昆仑")>= 0)
                                message_vision(CYN "$n说道：那里的人能文能武。琴剑双绝。n" NOR, me, ob);
                                else if (strsrch(topic,"凌霄城")>= 0 || strsrch(topic,"凌霄")>= 0)
                                message_vision(CYN "$n说道：一走近凌霄城的人，就冷的浑身发抖。n" NOR, me, ob);
                                else if (strsrch(topic,"五毒教")>= 0 || strsrch(topic,"五毒")>= 0)
                                message_vision(CYN "$n说道：那里好可怕，什么怪物都有。n" NOR, me, ob);

}
				else
					message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
		}
	}
	return 1;
}

string query_inquiry(object ob)
{
	int i=0;
	mapping inq;
	string str="", *indexs;
	
	if(mapp(inq=ob->query("inquiry")))
		{
		indexs=keys(inq);
		for(i=0;i<sizeof(indexs);i++)
			{
				str=indexs[i]+" "+str;
				}
		str="有关于 "HIB+str+NOR CYN"的事情,我很高兴告诉你!";
		return str;
		}
	return "实在是对不起,我什么也不知道呀!";
	}

void zujinpc(object me,object obj)
{   

	int maxpot;
	int maxexp;
	int maxskill;
	int i;
        if (!me) return;
	maxskill=1+me->query_skill("force",1)*2/3;
	maxpot=me->query_temp("maxpot");
	maxexp=me->query("combat_exp",1);
        if (maxskill<100)
        maxskill=100;
        i=me->query_temp("team_count");
        if (!i) i=sizeof(me->query_team());
        if (i==0) i=1;
        if (!i) i=1;


	obj->initlvl(maxskill);
         obj->set("combat_exp",maxexp);
        obj->set("str", me->query("str"));
        obj->set("dex", me->query("dex"));
        obj->set("per", me->query("per"));
        obj->set("qi", me->query("max_qi")*i);
        obj->set("eff_qi", me->query("max_qi")*i);
        obj->set("max_qi", me->query("max_qi")*i);
        obj->set("eff_jing", me->query("max_jing")*i);
        obj->set("max_jing", me->query("max_jing")*i);
        obj->set("jing", me->query("max_jing")*i);
        obj->set("neili", me->query("max_neili")*i);
        obj->set("max_neili", me->query("max_neili")*i);

}

void zujinpc2(object me,object obj)
{   

	int maxpot;
	int maxexp;
	int maxskill;
	int i;
        if (!me) return;
	maxskill=1+me->query_skill("force",1)/2;
	maxpot=me->query_temp("maxpot");
	maxexp=me->query("combat_exp",1);
        if (maxskill<50)
        maxskill=50;
        i=me->query_temp("team_count");
        if (!i) i=sizeof(me->query_team());
        if (i==0) i=1;
        if (!i) i=1;


	obj->initlvl(maxskill);
         obj->set("combat_exp",maxexp);
        obj->set("str", me->query("str"));
        obj->set("dex", me->query("dex"));
        obj->set("per", me->query("per"));
        obj->set("qi", me->query("max_qi")*i);
        obj->set("eff_qi", me->query("max_qi")*i);
        obj->set("max_qi", me->query("max_qi")*i);
        obj->set("eff_jing", me->query("max_jing")*i);
        obj->set("max_jing", me->query("max_jing")*i);
        obj->set("jing", me->query("max_jing")*i);
        obj->set("neili", me->query("max_neili")*i);
        obj->set("max_neili", me->query("max_neili")*i);

}

string  zuji(string str)
{   
string output;
      	if (str=="baituo")  

	output="白驼山";

if (str=="binghuodao")  

	output="冰火岛";

if (str=="city")  

	output="扬州";

if (str=="city2" || str=="beijing"  || str=="huanggon"  || str=="huanggong" || str=="beihai")  

	output="北京城";

if (str=="city4" || str=="changan")   

	output="长安城";

if (str=="dali")  

	output="大理";

if (str=="emei")  

	output="娥眉山";

if (str=="foshan")  

	output="佛山";

if (str=="gaibang")  

	output="丐帮";

if (str=="gaochang")  

	output="高昌迷宫";

if (str=="guanwai")  

	output="关外";

if (str=="guiyun")  

	output="归云庄";

if (str=="gumu")  

	output="古墓派";

if (str=="hangzhou")  

	output="杭州";

if (str=="heimuya")  

	output="黑木崖";

if (str=="hengshan")  

	output="恒山";

if (str=="henshan")  

	output="衡山";

if (str=="huanghe")  

	output="黄河九曲";

if (str=="huashan")  

	output="华山";

if (str=="jinshe")  

	output="金蛇山洞";

if (str=="lingjiu")  

	output="灵鹫宫";

if (str=="lingzhou")  

	output="灵州";

if (str=="meizhuang")  

	output="梅庄";

if (str=="mingjiao")  

	output="明教";

if (str=="qingcheng")  

	output="青城山";

if (str=="quanzhen")  

	output="全真派";

if (str=="quanzhou")  

	output="泉州";

if (str=="shaolin")  

	output="少林寺";

if (str=="shenlong")  

	output="神龙岛";

if (str=="songshan")  

	output="嵩山";

if (str=="suzhou")  

	output="苏州";

if (str=="taishan")  

	output="泰山";

if (str=="taohua")  

	output="桃花岛";

if (str=="tianlongsi")  

	output="天龙寺";

if (str=="wanjiegu")  

	output="万劫谷";

if (str=="wudang")  

	output="武当山";

if (str=="xiakedao")  

	output="侠客岛";

if (str=="xiangyang")  

	output="襄阳城";

if (str=="xiaoyao")  

	output="逍遥林";

if (str=="xingxiu")  

	output="星宿海";

if (str=="xueshan")  

	output="雪山寺";

if (str=="xuedao")  

	output="大雪山";

if (str=="mr")  

	output="慕容世家";

if (str=="kunlun")  

	output="昆仑山";

if (str=="tiezhang")  

	output="铁掌门";

if (str=="huizhu")  

	output="回族部落";

if (str=="yinju")  

	output="一灯大师居";

if (str=="menggu")  

	output="蒙古草原";

if (str=="qianjin")  

	output="北京千金楼";

if (str=="lingshedao")  

	output="灵蛇岛";

if (str=="ruzhou")  

	output="汝州城";

if (str=="kunming")  

	output="昆明";

if (str=="jingzhou")  

	output="荆州";

if (str=="yanjing")  

	output="盛京";

if (str=="lanzhou" || str=="lanzhouchen")  

	output="兰州";

if (str=="jyguan")  

	output="嘉峪关";

if (str=="changcheng")  

	output="长城";

if (str=="fairyland")  

	output="红梅山庄";

if (str=="sdxl")  

	output="剑魔独孤求败墓";

if (str=="jqg")  

	output="绝情谷";

if (str=="nio")  

	output="牛家村";

if (str=="feihu")  

	output="闯王宝藏";

if (str=="wuguan")  

	output="襄阳武馆";

if (str=="village")  

	output="华山村";

if (str=="taohuacun")  

	output="桃花村";

if (str=="pingan")  

	output="平安城";

if (str=="lingxiao")  

	output="凌霄城";

if (str=="wudujiao")  

	output="五毒教";

if (str=="hj")  

	output="天山草原";
if (str=="dali/yuxu")  

	output="大理玉虚观";
if (str=="dali/wuliang")  

	output="大理无量山";
if (str=="huanghe/yyd")  

	output="黄河萧府";
if (str=="kaifeng")  

	output="开封城";
if (str=="feitian")  

	output="飞天御剑流";
if (str=="japan")  

	output="日本神户";
if (str=="tangmen")  

	output="唐门";
if (str=="luoyang")  

	output="洛阳城";

if (str=="chengdu" || str=="city3")  

	output="成都";

if (str=="baihuagu")  

	output="百花谷";

if (str=="heizhao")  

	output="百花谷黑沼";

if (str=="jiaxing")  

	output="嘉兴";

if (str=="shiliang")  

	output="温家庄";

if (str=="wuyi")  

	output="武夷山区";

if (str=="yanping")  

	output="延平城";
	

if (str=="jiangling")  
{
	output="江陵城";
}

if (str=="yueyang")  
{
	output="岳阳城";	
}

if (str=="qilian")  
{
	output="祁连山";	
}

if (str=="shouxihu")  
{
	output="瘦西湖";	
}

if (str=="wuxi")  
{
	output="无锡城";	
}

if (str=="yixing")  
{
	output="宜兴城";	
}
if (str=="taiwan")  
{
	output="台湾";	
}
if (str=="nanyang")  
{
	output="南阳";	
}
if (str=="nanshaolin")  
{
	output="南少林";	
}

if (str=="cangzhou")  
{
	output="沧州";	
}

if (str=="tanggu")  
{
	output="塘沽城";	
}

if (str=="yunhe")  
{
	output="京杭运河";	
}

if (str=="hainan")  
{
	output="海南岛";	
}

if (str=="jindezheng")  
{
	output="景德镇";	
}

if (str=="yandang")  
{
	output="雁荡山";	
}

if (str=="jinling")  
{
	output="金陵城";	
}

if (str=="sandboy")  
{
	output="江南农村";	
}

if (str=="huangshan")  
{
	output="黄山";	
}

if (str=="yubifeng")  
{
	output="玉笔峰";	
}

if (str=="quanzhouchen")  
{
	output="泉州城内";	
}

if (str=="qingzh")  
{
	output="青藏高原";	
}

if (str=="changbaishan" || str=="gaoli")  
{
	output="高丽长白山";	
}

if (str=="annan")  
{
	output="安南";	
}

if (str=="taiyuan")  
{
	output="太原";	
}

if (str=="hefei")  
{
	output="合肥";	
}

if (str=="jiujiang")  
{
	output="九江";	
}

if (str=="baling")  
{
	output="巴陵";	
}

if (str=="xinjiang")  
{
	output="新疆";	
}
if (str=="dingxiang")  
{
	output="定襄";	
}
if (str=="suiye")  
{
	output="碎叶";	
}
if (str=="lumaji")
{
	output="鹿马集";	
}


if (str=="houjizhen")
{
	output="侯集镇";	
}

if (str=="zuojiacun")
{
	output="华亭府";	
}

if (str=="biancheng")
{
	output="边城";	
}


if (str=="jinghai")
{
	output="靖海派";	
}


if (str=="huayin")
{
	output="铜山村";	
}

if (str=="xiyu")
{
	output="西域区域";	
}

if (str=="heifeng")
{
	output="黑风寨";	
}
if (str=="linzhi")
{
	output="西藏林芝地区";	
}


if (str=="cloud" )  
{
	output="东北绮云镇";	
}

if (str=="xinan")
{
	output="西南区域";	
}

if (str=="mayi")  
{
	output="马邑边疆";	
}
if (str=="xuzhou")  
{
	output="徐州城";	
}
if (str=="jinan")  
{
	output="济南城";	
}
if (str=="guizhou")  
{
	output="贵阳城";	
}

if (str=="nanchang")  
{
	output="南昌城";	
}


if (str=="changsha")  
{
	output="长沙城";	
}


if (str=="zhongzhou")  
{
	output="中州城";	
}

if (str=="xizang" || str=="zangbei")  
{
	output="西藏或藏北";	
}

if (str=="tianshui")  
{
	output="天水城";	
}

if (str=="datong")  
{
	output="大同府";	
}
if (str=="ny")  
{
	output="宁远城";	
}
if (str=="fengtian")  
{
	output="盛京城";	
}

if (str=="yanmen")  
{
	output="燕门关";	
}
if (str=="cloud")  
{
	output="绮云镇";	
}
if (str=="xueting")  
{
	output="雪亭镇";	
}
if (str=="fuzhou")  
{
	output="福州";	
}
if (str=="welcome")  
{
	output="古村";	
}
if (!output)  
{
	output="未知区域";	
}

if (output=="")  
{
	output="未知区域";	
}


return output;
}

int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;
	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2) 
			- (int)SECURITY_D->get_wiz_level(ob1);
	
	return (int)ob2->query("mud_age") - (int)ob1->query("mud_age");
}

int help(object me)
{
   write( @HELP
指令格式: ask <someone> about <something>

这个指令在解谜时很重要, 通常必须藉由此一指令才能
获得进一步的资讯。
预设的询问主题:
	here
	name
	news
	all
HELP
   );
   return 1;
}
