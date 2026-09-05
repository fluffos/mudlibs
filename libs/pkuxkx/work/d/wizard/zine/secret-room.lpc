#include <room.h>
#include <ansi.h>
#include <title.h>
#include <localtime.h>
inherit ROOM;
string look_shelf();
int gen_gem(object me,object equip,string gem1type,int gem1lv);
int getgem(string arg,object equip,object me,string gem1type,int gem1lv,string gem2type,int gem2lv,string gem3type,int gem3lv,int gem_num);
mapping *books = ({
            ([  "id":1,"name":"逆天改命 重铸先天","desc":"可更改先天属性。","cost":8,"method":"convert",]),
            ([  "id":2,"name":"逆天改命 重回师门","desc":"可减低判师数。","cost":68,"method":"nitian",]),
            ([  "id":3,"name":"取回宝石","desc":"取回装备的宝石，基础消耗一点铜雀台积分，每取一颗宝石另加两点。","cost":1,"method":"getgem",]),
			([  "id":4,"name":"告别师门","desc":"无损告别师门，相当于再出师一次。","cost":68,"method":"reborn",]),
			([  "id":5,"name":"醉生梦死","desc":"清除掉醉拳pfm mark。","cost":50,"method":"zuijiu",]),
			([  "id":6,"name":"技能演进","desc":"取得特技升级点数。","cost":15,"method":"yanjin",]),
			([  "id":7,"name":"龙葬八荒","desc":"取得"HIY"一代真龙"NOR"专属特技「龙葬八荒」，与「飞龙乘云」只能选择修炼一种。","cost":30,"method":"devastate",]),
			([  "id":8,"name":"飞龙乘云","desc":"取得"HIY"一代真龙"NOR"专属特技「飞龙乘云」，与「龙葬八荒」只能选择修炼一种。","cost":30,"method":"confuse",]),
			([  "id":9,"name":"天命神龙","desc":"取得"HIY"一代真龙"NOR"专属特技「天命神龙」。","cost":30,"method":"destiny",]),
			});

void create()
{
        set("short", HIC+"禁室"+NOR);
        set("long", @LONG
这里是古铜雀台的禁室，墙上有个字条(notice)。
LONG
        );
        set("exits", ([
             "east" : __DIR__"dating",
 
        ]));
        set("item_desc", ([
		"notice" : (:look_shelf:),
	    ]));
        
        setup();
      
}

string look_shelf()
{
    int i,true_value;
    object me=this_player();
    mapping book;
    string msg=YEL+"密室提供如下服务：\n"+NOR;
    for (i=0;i<sizeof(books);i++)
    {
        book=books[i];
        if (books[i]["desc"]=="可减低判师数。")
        {
            true_value=books[i]["cost"]+(int)me->query("safari_nitian_attempt")*20;
        }
        else
        {
            true_value=books[i]["cost"];
        }
        msg+=sprintf("%-40s",HIR+"★"+books[i]["name"]+"★"+NOR)+sprintf("%-36s","使用方法："+HIR+books[i]["method"]+NOR)+"铜雀积分"+sprintf("%|30s",HIY+chinese_number(true_value)+NOR+"点")+"简介："+books[i]["desc"]+"\n";
    }
    return msg;
}

void init()
{
    add_action("do_convert","convert");
    add_action("do_nitian","nitian");
    add_action("do_getgem","getgem");
	add_action("do_reborn","reborn");
	add_action("do_zuijiu","zuijiu");
	add_action("do_yanjin","yanjin");
	add_action("do_devastate","devastate");
	add_action("do_confuse","confuse");
	add_action("do_destiny","destiny");
}

int do_zuijiu()
{
object me=this_player();
mapping book=books[4];//动作编号
if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query("safari_credit")<book["cost"])
    {
        tell_object(me,"至少需要"+chinese_number(book["cost"])+"点铜雀台任务积分，方有醉生梦死一次。\n");
        return 1;
    }
    me->add("safari_credit",-book["cost"]);
	log_file("user/safari_info",sprintf("%s%s%s\n",me->query("id")+"在"+ctime(time())+"消耗",chinese_number(book["cost"])+"点铜雀台积分，","清除醉拳mark"));
    me->set("zuiquanpf",0);
    tell_object(me,"你消耗了"+chinese_number(book["cost"])+"点铜雀台积分，醉生梦死了一次。\n");
    CHANNEL_D->do_channel(this_object(), "jh", "铜雀台："+me->query("name")+"("+capitalize(me->query("id"))+")醉生梦死，烂醉如泥！\n",-1);
    return 1;
}

int do_yanjin()
{
int cost;
int c_point;
object me=this_player();
mapping book=books[5];//动作编号
if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
	cost=book["cost"];
	c_point=1<<(me->query("safari_special/levelup2"));
	cost=cost*c_point;
    if (me->query("safari_credit")<cost)
    {
        tell_object(me,"至少需要"+chinese_number(cost)+"点铜雀台任务积分，方能演进特技。\n");
        return 1;
    }
    me->add("safari_credit",-cost);
	log_file("user/safari_info",sprintf("%s%s%s\n",me->query("id")+"在"+ctime(time())+"消耗",chinese_number(cost)+"点铜雀台积分，","取得特技升级点数1"));
    me->add("safari_special/levelup2",1);
    me->add("special/levelup_point",1);
	me->save();
    tell_object(me,"你消耗了"+chinese_number(cost)+"点铜雀台积分，演进了特技。\n");
	tell_object(me,"你取得了一点特技升级点数。\n");
    CHANNEL_D->do_channel(this_object(), "jh", "铜雀台："+me->query("name")+"("+capitalize(me->query("id"))+")兴致勃发，狂飙突进！\n",-1);
    return 1;
}


int do_getgem(string arg)
{
    object gem,equip,me=this_player();
    mapping book=books[2];//动作编号
    string gem1type="",gem2type="",gem3type="";
    int gem1lv=0,gem2lv=0,gem3lv=0,gem_num=0;
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query("safari_credit")<book["cost"])
    {
        tell_object(me,"至少需要"+chinese_number(book["cost"]+2)+"点铜雀台任务积分，方有机会取回宝石。\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你要取回哪件装备上的宝石？\n");
        return 1;
    }
    if (!present(arg,me))
    {
        tell_object(me,"你身上并没有这件装备。\n");
        return 1;
    }
    equip=present(arg,me);
    if (!equip->query("forge"))
    {
        tell_object(me,"你只能从随机装备上取回宝石。\n");
        return 1;
    }
    if (equip->query("forge/material1"))
    {
        gem1type=equip->query("forge/material1");
        gem1lv=equip->query("forge/material1_level");
        gem_num+=1;
    }
    if (equip->query("forge/material2"))
    {
        gem2type=equip->query("forge/material2");
        gem2lv=equip->query("forge/material2_level");
        gem_num+=1;
    }
    if (equip->query("forge/material3"))
    {
        gem3type=equip->query("forge/material3");
        gem3lv=equip->query("forge/material3_level");
        gem_num+=1;
    }
    if (gem_num==0)
    {
        tell_object(me,"这件"+equip->query("name")+"并无任何宝石。\n");
        return 1;
    }
    tell_object(me,"你确定要把"+equip->query("name")+"的宝石取回吗？如进行将消耗"+chinese_number(book["cost"]+gem_num*2)+"点铜雀台积分，并将彻底损毁"+equip->query("name")+"。(请输入yes或者no。)\n");
    input_to( (: getgem :), equip ,me,gem1type,gem1lv,gem2type,gem2lv,gem3type,gem3lv,gem_num);
    return 1;
}

int getgem(string arg,object equip,object me,string gem1type,int gem1lv,string gem2type,int gem2lv,string gem3type,int gem3lv,int gem_num)
{
    mapping book=books[2];//动作编号
    object uitem;
    
    if(arg!="y"&&arg!="Y"&&arg!="yes"&&arg!="YES")
    return 1;
    if (!present(equip,me))
    {
        tell_object(me,"你把"+equip->query("name")+"藏到哪里去了？\n");
        return 1;
    }
    if (me->query("safari_credit")<book["cost"]+gem_num*2)
    {
        tell_object(me,"至少需要"+chinese_number(book["cost"]+gem_num*2)+"点铜雀台任务积分，才能取回宝石。\n");
        return 1;
    }
    if (gem1type)
    {
        gen_gem(me,equip,gem1type,gem1lv);
    }
    if (gem2type)
    {
        gen_gem(me,equip,gem2type,gem2lv);
    }
    if (gem3type)
    {
        gen_gem(me,equip,gem3type,gem3lv);
    }
    tell_object(me,"你消耗了"+chinese_number(book["cost"]+gem_num*2)+"点铜雀台积分，取回了宝石，在此过程中，"+equip->query("name")+"彻底被损毁了。\n");
    me->add("safari_credit",-(book["cost"]+gem_num*2));
	  log_file("user/safari_info",sprintf("%s%s%s\n",me->query("id")+"在"+ctime(time())+"消耗",chinese_number(book["cost"]+gem_num*2)+"点铜雀台积分，","取回宝石"));
    
    uitem=new(UITEM_OB);
    uitem->set("id", me->query("id"));
//    if ( uitem->check_save() )
      uitem->restore();
    
    uitem->disload_equip(equip, me);;
    uitem->save();
    destruct(uitem);
    destruct(equip);
    return 1;
}

int gen_gem(object me,object equip,string gemtype,int gemlv)
{
    object gem;
    int index;
    gem=new("/obj/gem/gem");
    if (gemlv==1)//还原级别
    {
        index=4000;
    }
    if (gemlv==2)
    {
        index=8000;
    }
    if (gemlv==3)
    {
        index=9000;
    }
    if (gemlv==4)
    {
        index=9500;
    }
    if (gemlv==5)
    {
        index=9900;
    }
    if (gemlv==6)
    {
        index=9950;
    }
    if (gemlv==7)
    {
        index=9990;
    }
    if (gemlv==8)
    {
        index=9999;
    }
    gem->set_level(index,index,gemtype);
    tell_object(me,"你从"+equip->query("name")+"上取回了"+gem->query("name")+"。\n");
    gem->move(me);
    return 1;
}

int do_convert(string arg)
{
    object me=this_player();
    string nature1,nature2;
    mapping book=books[0];//动作编号
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query("newjobs/completed/safari")<15)
    {
        tell_object(me,"至少需要完成十五次以上铜雀台任务，方可逆天改命。\n");
        return 1;
    }
    if (me->query("safari_credit")<book["cost"])
    {
        tell_object(me,"至少需要"+chinese_number(book["cost"])+"点铜雀台任务积分，方可逆天改命。\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你要把哪项先天属性变作别的先天属性？\n");
        return 1;
    }
    if (sscanf(arg, "%s to %s", nature1,nature2) != 2)
    {
        tell_object(me,"请用格式convert <希望减少的属性> to <希望增加的属性>，例如：convert str to int，即增加一点悟性，减少一点臂力。\n");
        tell_object(me,"可以修改的属性分别是膂力str，悟性int，根骨con，身法dex。\n");
        return 1;
    }
    if (nature1!="str"&&nature1!="int"&&nature1!="con"&&nature1!="dex")
    {
        tell_object(me,"你只能修改膂力str，悟性int，根骨con，身法dex这四项中的一项。\n");
        return 1;
    }
    if (nature2!="str"&&nature2!="int"&&nature2!="con"&&nature2!="dex")
    {
        tell_object(me,"你只能修改膂力str，悟性int，根骨con，身法dex这四项中的一项。\n");
        return 1;
    }
    if (nature1==nature2)
    {
        tell_object(me,"你不能把"+nature1+"改成"+nature2+"，因为他们是相同的属性。\n");
        return 1;
    }
    if (me->query(nature1)<=10)
    {
        tell_object(me,"你的"+nature1+"属性已经小于十点，无法再转换成任何属性。\n");
        return 1;
    }
    if (me->query(nature2)>=50)
    {
        tell_object(me,"你的"+nature2+"属性已经大于五十点，无法再增长。\n");
        return 1;
    }
    me->add("safari_credit",-book["cost"]);
	log_file("user/safari_info",sprintf("%s%s%s\n",me->query("id")+"在"+ctime(time())+"消耗",chinese_number(book["cost"])+"点铜雀台积分，","修改先天属性"));
    me->add(nature1,-1);
    me->add(nature2,1);
    tell_object(me,"你消耗了"+chinese_number(book["cost"])+"点铜雀台积分，将"+nature1+"转化为"+nature2+"成功。\n");
    CHANNEL_D->do_channel(this_object(), "jh", "铜雀台："+me->query("name")+"("+capitalize(me->query("id"))+")重铸先天成功！\n",-1);
    return 1;
}

int succ(object me,int true_cost)
{
    if (true_cost>168)
    {
        true_cost=168;
    }
    me->add("safari_credit",-true_cost);
	log_file("user/safari_info",sprintf("%s%s%s\n",me->query("id")+"在"+ctime(time())+"消耗",chinese_number(true_cost)+"点铜雀台积分，","逆天改命"));
    me->add("betrayer",-1);
	me->delete("safari_nitian_attempt");
    tell_object(me,"你消耗了"+chinese_number(true_cost)+"点铜雀台积分，逆天改命成功。\n");
    CHANNEL_D->do_channel(this_object(), "jh", "铜雀台："+me->query("name")+"("+capitalize(me->query("id"))+")逆天改命成功！\n",-1);
    return 1;
}

int nitian(object me,int true_cost)
{
    if (true_cost>=268)
    {
        succ(me,true_cost);
        return 1;
    }
    else if (true_cost>=248&&random(100)>11)
    {
        succ(me,true_cost);
        return 1;
    }
    else if (true_cost>=228&&random(100)>21)
    {
        succ(me,true_cost);
        return 1;
    }
    else if (true_cost>=208&&random(100)>31)
    {
        succ(me,true_cost);
        return 1;
    }
    else if (true_cost>=188&&random(100)>41)
    {
        succ(me,true_cost);
        return 1;
    }
    else if (true_cost>=168&&random(100)>51)
    {
        succ(me,true_cost);
        return 1;
    }
    else if (true_cost>=148&&random(100)>61)
    {
        succ(me,true_cost);
        return 1;
    }
    else if (true_cost>=128&&random(100)>71)
    {
        succ(me,true_cost);
        return 1;
    }
    else if (true_cost>=108&&random(100)>81)
    {
        succ(me,true_cost);
        return 1;
    }
    else if (true_cost>=88&&random(100)>91)
    {
        succ(me,true_cost);
        return 1;
    }
    else if (true_cost>=68&&random(100)>98)
    {
        succ(me,true_cost);
        return 1;
    }
    else 
    {
        me->add("safari_nitian_attempt",1);
        tell_object(me,"很遗憾，这次改命似乎失败了。\n");
        return 1;
    }
}

int do_nitian()
{
    int true_cost;
    object me=this_player();
    mapping book=books[1];//动作编号
    
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query("newjobs/completed/safari")<68)
    {
        tell_object(me,"至少需要完成六十八次以上铜雀台任务，方可逆天改命。\n");
        return 1;
    }
    true_cost=book["cost"]+(int)me->query("safari_nitian_attempt")*20;
    if (me->query("safari_credit")<true_cost)
    {
        tell_object(me,"至少需要"+chinese_number(true_cost)+"点铜雀台任务积分，方可逆天改命。\n");
        return 1;
    }
    if (me->query("betrayer")<=0)
    {
        tell_object(me,"你的判师数非正，无法另行降低。\n");
        return 1;
    }
    nitian(me,true_cost);
    return 1;
}

int succ_reborn(object me,int true_cost)
{
	string *old_family=({});
    if (true_cost>168)
    {
        true_cost=168;
    }
    me->add("safari_credit",-true_cost);
	log_file("user/safari_info",sprintf("%s%s%s\n",me->query("id")+"在"+ctime(time())+"消耗",chinese_number(true_cost)+"点铜雀台积分，","离开师门"));
    me->delete("class");
	if (me->query("tqt/old_family"))
	{
		old_family=me->query("tqt/old_family");
		if (me->query("tqt/old_family1"))
		{
			if (me->query("tqt/old_family2"))
			{
			me->set("tqt/old_family3",me->query("family/family_name"));
			}
			else
			{
			me->set("tqt/old_family2",me->query("family/family_name"));
			}
		}
		else
		{
		me->set("tqt/old_family1",me->query("family/family_name"));
		}
	}
	else
	{
	me->set("tqt/old_family1",me->query("family/family_name"));
	}
	old_family+=({me->query("family/family_name")});
	me->set("tqt/old_family",old_family);
    me->set("reborn/chushi",1);
    me->set("chushi/done",1);//加上出师标记，防止纯门派漏洞
	me->delete("family");
	me->set("score",0);
	me->set("title",HIY+"铜雀台中人"+NOR);
	me->set_title(({TITLE_QUEST1, TITLE_QUEST2, TITLE_QUEST3, TITLE_QUEST4, TITLE_QUEST5, TITLE_QUEST6, TITLE_QUEST7, TITLE_QUEST8, TITLE_QUEST9}), me->query("title"),"铜雀台");
    tell_object(me,"你消耗了"+chinese_number(true_cost)+"点铜雀台积分，无损离开师门。\n");
    CHANNEL_D->do_channel(this_object(), "jh", "铜雀台："+me->query("name")+"("+capitalize(me->query("id"))+")告别了师门！\n",-1);
	me->delete("safari_reborn_attempt");
	me->restore_face(FACE_ORIGIN); //出师之后恢复本名。by lordstar 2017/8/23
    return 1;
}

int reborn(object me,int true_cost)
{
    if (true_cost>=268)
    {
        succ_reborn(me,true_cost);
        return 1;
    }
    else if (true_cost>=248&&random(100)>11)
    {
        succ_reborn(me,true_cost);
        return 1;
    }
    else if (true_cost>=228&&random(100)>21)
    {
        succ_reborn(me,true_cost);
        return 1;
    }
    else if (true_cost>=208&&random(100)>31)
    {
        succ_reborn(me,true_cost);
        return 1;
    }
    else if (true_cost>=188&&random(100)>41)
    {
        succ_reborn(me,true_cost);
        return 1;
    }
    else if (true_cost>=168&&random(100)>51)
    {
        succ_reborn(me,true_cost);
        return 1;
    }
    else if (true_cost>=148&&random(100)>61)
    {
        succ_reborn(me,true_cost);
        return 1;
    }
    else if (true_cost>=128&&random(100)>71)
    {
        succ_reborn(me,true_cost);
        return 1;
    }
    else if (true_cost>=108&&random(100)>81)
    {
        succ_reborn(me,true_cost);
        return 1;
    }
    else if (true_cost>=88&&random(100)>91)
    {
        succ_reborn(me,true_cost);
        return 1;
    }
    else if (true_cost>=68&&random(100)>98)
    {
        succ_reborn(me,true_cost);
        return 1;
    }
    else 
    {
        me->add("safari_reborn_attempt",1);
        tell_object(me,"很遗憾，这次尝试似乎失败了。\n");
        return 1;
    }
}

int do_reborn()
{
    int true_cost;
    object me=this_player();
    mapping book=books[1];//动作编号
    
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query("newjobs/completed/safari")<68)
    {
        tell_object(me,"至少需要完成六十八次以上铜雀台任务，方可尝试告别师门。\n");
        return 1;
    }
    true_cost=book["cost"]+(int)me->query("safari_reborn_attempt")*20;
    if (me->query("safari_credit")<true_cost)
    {
        tell_object(me,"至少需要"+chinese_number(true_cost)+"点铜雀台任务积分，方可尝试告别师门。\n");
        return 1;
    }
    if (!me->query("family"))
    {
        tell_object(me,"你没有师门，谈何脱离？\n");
        return 1;
    }
    if ((int)me->query("purefamily/level")>0) //纯门派无法出师,lordstar
    {
        tell_object(me,"人无信不立，你已经发誓永远留在师门，就再也不能脱离了。\n");
        return 1; 
    }
    reborn(me,true_cost);
    return 1;
}

int do_devastate()
{
    object me=this_player();
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
	if (!me->query("yidaizhenlong"))
	{
        tell_object(me,"只有取得「一代真龙」的名号之后才能兑换专属特技。\n");
        return 1;
	}
	if (me->query("special_skill/confuse"))
	{
        tell_object(me,"你已经获得了专属特技「飞龙乘云」，无法再学习「龙葬八荒」。\n");
        return 1;
    }
	if (me->query("special_skill/devastate"))
	{
        tell_object(me,"你已经获得了「龙葬八荒」。\n");
        return 1;
    }
	if (me->query("combat_exp")<800000000)
    {
        tell_object(me,"只有经验达到800m以上，才能兑换「龙葬八荒」。\n");
        return 1;
    }
    if (me->query("newjobs/completed/safari")<30)
    {
        tell_object(me,"至少需要完成三十次以上铜雀台任务，才能兑换专属特技。\n");
        return 1;
    }
    if (me->query("safari_credit")<30)
    {
        tell_object(me,"至少需要三十点铜雀台任务积分，才能兑换专属特技。\n");
        return 1;
    }
	if (me->query("level")<100)
    {
        tell_object(me,"你的人物等级不够。至少一百级之后，才能兑换专属特技。\n");
        return 1;
    }
    tell_object(me,"你消耗了三十点铜雀台积分，兑换专属特技「龙葬八荒」。\n");
    CHANNEL_D->do_channel(this_object(), "jh", "铜雀台："+me->query("name")+"("+capitalize(me->query("id"))+")获得「龙葬八荒」！\n",-1);
	log_file("user/safari_info", ""+me->query("id")+"在"+ctime(time())+"消耗30点铜雀台积分，获得「龙葬八荒」。\n");
    me->add("safari_credit",-30);
	me->set("special_skill/devastate", 1);
	me->set("special_level/devastate", 1);
	me->save();
	return 1;
}

int do_confuse()
{
    object me=this_player();
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
	if (!me->query("yidaizhenlong"))
	{
        tell_object(me,"只有取得「一代真龙」的名号之后才能兑换专属特技。\n");
        return 1;
	}
	if (me->query("special_skill/devastate"))
	{
        tell_object(me,"你已经获得了专属特技「龙葬八荒」，无法再学习「飞龙乘云」。\n");
        return 1;
    }
	if (me->query("special_skill/confuse"))
	{
        tell_object(me,"你已经获得了「飞龙乘云」。\n");
        return 1;
    }
	if (me->query("combat_exp")<800000000)
    {
        tell_object(me,"只有经验达到800m以上，才能兑换「飞龙乘云」。\n");
        return 1;
    }

    if (me->query("newjobs/completed/safari")<30)
    {
        tell_object(me,"至少需要完成三十次以上铜雀台任务，才能兑换专属特技。\n");
        return 1;
    }
    if (me->query("safari_credit")<30)
    {
        tell_object(me,"至少需要三十点铜雀台任务积分，才能兑换专属特技。\n");
        return 1;
    }
	if (me->query("level")<100)
    {
        tell_object(me,"你的人物等级不够。至少一百级之后，才能兑换专属特技。\n");
        return 1;
    }
    tell_object(me,"你消耗了三十点铜雀台积分，兑换专属特技「飞龙乘云」。\n");
    CHANNEL_D->do_channel(this_object(), "jh", "铜雀台："+me->query("name")+"("+capitalize(me->query("id"))+")获得「飞龙乘云」！\n",-1);
	log_file("user/safari_info", ""+me->query("id")+"在"+ctime(time())+"消耗30点铜雀台积分，获得「飞龙乘云」。\n");
    me->add("safari_credit",-30);
	me->set("special_skill/confuse", 1);
	me->set("special_level/confuse", 1);
	me->save();
	return 1;
}

int do_destiny()
{
    object me=this_player();
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
	if (!me->query("yidaizhenlong"))
	{
        tell_object(me,"只有取得「一代真龙」的名号之后才能兑换专属特技。\n");
        return 1;
	}
	if (me->query("special_skill/destiny"))
	{
        tell_object(me,"你已经获得了「天命神龙」。\n");
        return 1;
    }
    if (me->query("newjobs/completed/safari")<30)
    {
        tell_object(me,"至少需要完成三十次以上铜雀台任务，才能兑换专属特技。\n");
        return 1;
    }
    if (me->query("safari_credit")<30)
    {
        tell_object(me,"至少需要三十点铜雀台任务积分，才能兑换专属特技。\n");
        return 1;
    }
	if (me->query("level")<100)
    {
        tell_object(me,"你的人物等级不够。至少一百级之后，才能兑换专属特技。\n");
        return 1;
    }
	if (me->query("combat_exp")<1000000000)
    {
        tell_object(me,"只有经验达到1000m以上，才能兑换「天命神龙」。\n");
        return 1;
    }
	if (( me->query("potential") - me->query("learned_points") )<100000000 )
    {
        tell_object(me, "兑换「天命神龙」需要消耗100m潜能，你的潜能不够呀。\n");
        return 1;
    }
	if (!me->query_temp("tqt_confirm_destiny"))
	{
        tell_object(me,"兑换「天命神龙」需消耗30点铜雀积分和巨量的经验、潜能，如果你确定要兑换，请再输入一次 destiny。\n");
		me->set_temp("tqt_confirm_destiny", 1);
        return 1;
	}
    tell_object(me,"你消耗了三十点铜雀台积分和巨量的经验潜能，兑换专属特技「天命神龙」。\n");
    CHANNEL_D->do_channel(this_object(), "jh", "铜雀台："+me->query("name")+"("+capitalize(me->query("id"))+")获得「天命神龙」！\n",-1);
	log_file("user/safari_info", ""+me->query("id")+"在"+ctime(time())+"消耗30点铜雀台积分、500m 经验、100m 潜能，获得「天命神龙」。\n");
    me->add("safari_credit",-30);
	me->add("combat_exp",-500000000);
	me->add("potential",-100000000);
	me->delete_temp("tqt_confirm_destiny");
	me->set("special_skill/destiny", 1);
	me->set("special_level/destiny", 1);
	me->save();
	return 1;
}

