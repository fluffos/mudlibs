#include <room.h>
#include <ansi.h>
#include <localtime.h>
#define LINE   HIY"≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈\n"NOR
inherit ROOM;
string look_shelf();
// 给books加个mark, modified：1，2表示第一/二次修改，Value后的数值表示和原始值的变化，+3及增加三分，必须以上2个参数和分数Cost一起修改
// add huashan skills
// 各大门派大招陆续加入 by yhzzyahoo
// 大轮寺加入 
// 阴阳倒乱刃的pfm加入
mapping *books()
{ 
	return	({
            //([  "id":1001,"file":"/d/changjiang/obj/dan2","name":"武功秘籍","desc":"可通过研究提升自身的武功。","cost":1,"class":"公共武功",]),
            ([  "id":1002,"mark":"yanqing","file":"/d/changjiang/obj/dan3","name":"燕青拳心法","desc":"掌握燕青拳的精义。","cost":10,"class":"公共武功",]),
            ([  "id":1003,"skill":"wuxian-bianfa","file":"/d/changjiang/obj/dan4","name":"五仙鞭法秘籍","desc":"五毒教不传之秘。","cost":7,"class":"公共武功",]),
            ([  "id":1004,"skill":"leizhendang","file":"/d/changjiang/obj/dan5","name":"六十四路轰天雷震挡法","desc":"塞北白家堡的家传武学。","cost":2,"class":"公共武功",]),
            ([  "id":1005,"skill":"qianzhu-wandu","file":"/d/changjiang/obj/dan13","name":"千蛛万毒手心法","desc":"绝毒武功，修炼艰难。","cost":12,"class":"公共武功",]),
			([  "id":1006,"file":"/d/wizard/zine/obj/qianzhu_book","name":"千蛛万毒手精义","desc":"千蛛万毒手进阶必备。","cost":3,"class":"公共武功",]),
			([  "id":1007,"skill":"liuxing-chui","file":"/d/changjiang/obj/dan16","name":"童家流星锤法","desc":"童家流星锤法，其势不可挡。","cost":3,"class":"公共武功",]),
			([  "id":1008,"mark":"yinyang-daoluan","file":"/d/changjiang/obj/dan26","name":"阴阳倒乱刃绝学","desc":"阴阳倒乱刃之「倒乱刃法」。","cost":3,"class":"公共武功",]),
            ([  "id":2001,"mark":"player_special_contribute/gb","file":"/d/changjiang/obj/dan6","name":"降龙十八掌心法","desc":"丐帮失传武学。","cost":16,"class":"丐帮","Value":-19,"modified":1]),
            ([  "id":2002,"skill":"chilian-shenzhang","file":"/d/changjiang/obj/dan9","name":"赤炼神掌心法","desc":"李莫愁独门武学。","cost":4,"class":"古墓派",]),
            ([  "id":2003,"skill":"sanwu-shou","file":"/d/changjiang/obj/dan10","name":"三无三不手秘籍","desc":"李莫愁独门武学。","cost":8,"class":"古墓派",]),
            ([  "id":2004,"mark":"赤炼五毒","file":"/d/changjiang/obj/dan11","name":"赤炼神掌补遗","desc":"李莫愁独门武学。","cost":3,"class":"古墓派",]),
            ([  "id":2005,"mark":"tqt_sl_skill1","file":"/d/changjiang/obj/dan12","name":"大智无定指谱","desc":"少林失传武学。","cost":18,"class":"少林派",]),
            ([  "id":3001,"mark":"jiuyin_1","file":"/d/changjiang/obj/dan7","name":"九阴真经——内功篇上卷","desc":"世面上流传的其实是九阴假经。","cost":5,"class":"系列武功",]),
            ([  "id":3002,"mark":"jiuyin_2","file":"/d/changjiang/obj/dan8","name":"九阴真经——九阴白骨爪篇","desc":"世面上流传的其实是九阴假经。","cost":7,"class":"系列武功",]),
            ([  "id":3003,"mark":"jiuyin_3","file":"/d/changjiang/obj/dan14","name":"九阴真经——轻功篇","desc":"世面上流传的其实是九阴假经。","cost":8,"class":"系列武功",]),
            ([  "id":3004,"mark":"jiuyin_4","file":"/d/changjiang/obj/dan15","name":"九阴真经——摧心掌篇","desc":"世面上流传的其实是九阴假经。","cost":5,"class":"系列武功",]),
			([  "id":4001,"mark":"safari_skill/9jian","file":"/d/changjiang/obj/dan17","name":"无剑胜有剑","desc":"这是一种境界，用九剑做招架会降低对手绝招命中率，并对九剑有极大提高。","cost":16,"class":"华山派",]),
			([  "id":4002,"mark":"safari_skill/hs_jianyi","file":"/d/changjiang/obj/dan18","name":"华山剑意","desc":"华山派前辈高人所著，提升化学伤害三成。","cost":9,"class":"华山派",]),
			([  "id":4003,"mark":"safari_skill/hs_jq","file":"/d/changjiang/obj/dan24","name":"华山武功注解","desc":"华山派前辈高人所著，对华山派的剑气两宗武功融合问题提出了自己独到的见解。","cost":16,"class":"华山派",]),
			([  "id":5001,"mark":"safari_skill/xx_dushen","file":"/d/changjiang/obj/dan19","name":"毒神附体","desc":"星宿纯门派可用，出师叛师无效。"+RED+"与幽冥火焰只能选择修炼一种。"NOR,"cost":32,"class":"星宿派","no_chushi":1]),
			([  "id":5002,"mark":"safari_skill/xx_dushen","file":"/d/changjiang/obj/dan42","name":"幽冥火焰","desc":"星宿纯门派可用，出师叛师无效。"+RED+"与毒神附体只能选择修炼一种。"NOR,"cost":32,"class":"星宿派","no_chushi":1]),
			([  "id":6001,"mark":"safari_skill/mj_dny","file":"/d/changjiang/obj/dan20","name":"乾坤大挪移注","desc":"明教前人注释的乾坤大挪移，"+RED+"可增加每日次数，稍微减少每次长度，并可极大减少大挪移冲层时的走火几率。"+NOR,"cost":15,"class":"明教",]),
			([  "id":6002,"mark":"safari_skill/gm_xj","file":"/d/changjiang/obj/dan21","name":"玉女心经注解","desc":"林朝英遗失在外的玉女心经注解，"+RED+"可有效增强玉女素心效果"+NOR,"cost":15,"class":"古墓派",]),
			([  "id":6003,"mark":"safari_skill/qz1","file":"/d/changjiang/obj/dan22","name":"先天罡气谱——归元篇","desc":"重阳祖师亲手编写的先天功归元篇，"+RED+"可有效增强先天功的效果"+NOR,"cost":10,"class":"全真派",]),
			([  "id":6004,"mark":"safari_skill/qz2","file":"/d/changjiang/obj/dan23","name":"先天罡气谱——神罡篇","desc":"重阳祖师亲手编写的先天功神罡篇，"+RED+"可有效增强先天功的效果"+NOR,"cost":15,"class":"全真派",]),
			([  "id":6005,"mark":"safari_skill/dls1","file":"/d/changjiang/obj/dan25","name":"龙象般若功——金刚篇","desc":"大轮寺众位高僧研究出的『金刚护体』大法，"+RED+"可有效增强龙象般若功的效果"+NOR,"cost":25,"class":"大轮寺",]),
			([  "id":6006,"mark":"safari_skill/bts1","file":"/d/changjiang/obj/dan27","name":"蛤蟆功乱解","desc":"欧阳锋依据九阴真经对蛤蟆功的新注解，"+RED+"可有效增强蛤蟆功的效果"+NOR,"cost":12,"class":"白驼山",]),
			([  "id":6007,"mark":"safari_skill/mr_douzhuan","file":"/d/changjiang/obj/dan28","name":"斗转星移真解","desc":"姑苏慕容真正赖以成名的绝学--斗转星移，"+RED+"真正阐释了斗转星移的奥秘"+NOR,"cost":24,"class":"姑苏慕容",]),
			([  "id":6008,"mark":"safari_skill/xs_yuejian","file":"/d/changjiang/obj/dan29","name":"雪山剑法-月剑秘籍","desc":"白自在侠客岛归来后，依据侠客岛所得，"+RED+"可极大的加速雪山剑法的攻击属性"+NOR,"cost":18,"class":"雪山派",]),
			([  "id":6009,"mark":"safari_skill/em_jyg","file":"/d/changjiang/obj/dan30","name":"峨嵋九阳功残篇","desc":"峨嵋派祖师郭襄对九阳功研究心得的残篇，"+RED+"可极大的加强临济十二庄的效果"+NOR,"cost":20,"class":"峨嵋派",]),
			([  "id":6010,"mark":"safari_skill/tdh_zhengqi","file":"/d/changjiang/obj/dan31","name":"天地会-浩然正气决","desc":"天地会陈近南从文天祥正气歌中领悟所得，"+RED+"可极大的提高天地会武功绝招的命中效果"+NOR,"cost":16,"class":"天地会",]),
			([  "id":6011,"mark":"safari_skill/ct_alert","file":"/d/changjiang/obj/dan32","name":"朝廷-文韬","desc":"朝廷中为官之道的集大成者，号称文韬，"+RED+"可极大的提高召唤大内高手的效果"+NOR,"cost":12,"class":"朝廷",]),
			([  "id":6012,"mark":"safari_skill/ct_panlong","file":"/d/changjiang/obj/dan33","name":"朝廷-武略","desc":"朝廷中用兵之道的兵书，名为武略，"+RED+"可极大的提高盘龙棍的威力"+NOR,"cost":10,"class":"朝廷",]),
			([  "id":6013,"mark":"safari_skill/riyue_guiming","file":"/d/changjiang/obj/dan35","name":"葵花宝典-归冥篇","desc":"葵花宝典中最核心的部分，"+RED+"可有效增强葵花神功的效果"+NOR,"cost":10,"class":"日月神教",]),
			([  "id":6014,"mark":"safari_skill/riyue_tuci","file":"/d/changjiang/obj/dan34","name":"辟邪剑法-突刺","desc":"辟邪剑法突刺绝招增强，"+RED+"可增加突刺的次数"+NOR,"cost":10,"class":"日月神教",]),
			([  "id":6015,"mark":"safari_skill/riyue_pomo","file":"/d/changjiang/obj/dan36","name":"泼墨披麻剑法-乱泼墨","desc":"泼墨披麻剑法中新的绝招，"+RED+"可学会「乱泼墨」的使用方法"+NOR,"cost":15,"class":"日月神教",]),
			([  "id":6016,"mark":"safari_skill/thd_buzhen","file":"/d/changjiang/obj/dan37","name":"奇门八卦阵-布阵","desc":"奇门八卦阵的布阵方法，"+RED+"奇门八卦阵的使用方法"+NOR,"cost":10,"class":"桃花岛",]),
			([  "id":6017,"mark":"safari_skill/thd_dunxing","file":"/d/changjiang/obj/dan38","name":"奇门八卦阵-遁形","desc":"奇门八卦阵的使用方法，"+RED+"遁形的使用方法"+NOR,"cost":4,"class":"桃花岛",]),
			([  "id":6018,"mark":"safari_skill/thd_shangshen","file":"/d/changjiang/obj/dan39","name":"奇门八卦阵-伤神","desc":"奇门八卦阵的使用方法，"+RED+"伤神的使用方法"+NOR,"cost":4,"class":"桃花岛",]),
			([  "id":6019,"mark":"safari_skill/thd_huoxin","file":"/d/changjiang/obj/dan40","name":"奇门八卦阵-惑心","desc":"奇门八卦阵的使用方法，"+RED+"惑心的使用方法"+NOR,"cost":4,"class":"桃花岛",]),
			([  "id":6020,"mark":"safari_skill/wd_taiji","file":"/d/changjiang/obj/dan41","name":"太极神功——蓄力篇","desc":"三丰祖师亲手编写的太极蓄力篇，"+RED+"可有效增强太极神功的效果"+NOR,"cost":10,"class":"武当派",]),
			});
}
mapping *modified_skills(int increase)//increase 为+则返回增加积分的武功，否则则返回减少积分的武功
{
	mapping *books=books(),*mybooks=({});
	for (int i=0;i<sizeof(books);i++)
	{
		if (books[i]["modified"]&&(increase>0&&books[i]["Value"]>=0||increase<0&&books[i]["Value"]<=0))
		mybooks+=({books[i]});
	}
	return mybooks;
}
void create()
{
        set("short", HIY"书斋"NOR);
        set("long", @LONG
这里是古铜雀台收藏武功秘籍的所在，周围完全用黄铜浇筑，坚不可摧，书
架(shelf)上有一排古籍。

LONG
        );
        set("exits", ([
             "south" : __DIR__"dating",
 
        ]));
        set("item_desc", ([
		"shelf" : (:look_shelf:),
	    ]));
        
        setup();
      
}
int recoup(string arg)
{
	object me=this_player();
	mapping *books=modified_skills(-1),*my_books=({}),my_book;
	string msg="你可以退还铜雀台积分的武功有：\n";
	if (!arg)
	{
		for (int i=0;i<sizeof(books);i++)
		{
			if ((stringp(books[i]["mark"])&&me->query(books[i]["mark"])||(stringp(books[i]["skill"])&&me->query_skill(books[i]["skill"])))&&me->query("safari_modified/"+books[i]["id"]+"/modified")<books[i]["modified"])
			{
				my_books+=({books[i]});
				msg+=books[i]["name"]+" 可退还积分："+chinese_number(-books[i]["Value"])+"点。\n";
			}
		}
		if (my_books==({}))
		{
			tell_object(me,"你并无符合条件可以退还积分的武功。\n");
			return 1;
		}
		else
		{
			tell_object(me,msg);
			tell_object(me,"用recoup <中文武功名> 获得积分退还。\n");
			return 1;
		}
	}
	else
	{
		for (int i=0;i<sizeof(books);i++)
		if (arg==books[i]["name"])
		{
			my_book=books[i];
			break;
		}
		if (!my_book)
		{
			tell_object(me,"请输入正确的中文武功名。\n");
			return 1;
		}
		if ((my_book["mark"]&&!me->query(my_book["mark"]))||(my_book["skill"]&&!me->query_skill(my_book["skill"])))
		{
			tell_object(me,"你没在铜雀台兑换过这种武功。\n");
			return 1;
		}
		if (me->query("safari_modified/"+my_book["id"]+"/modified")>=my_book["modified"])
		{
			tell_object(me,"你已经被补偿过"+my_book["name"]+"的积分了。\n");
			return 1;
		}
		me->set("safari_modified/"+my_book["id"]+"/modified",my_book["modified"]);
		me->add("safari_credit",-my_book["Value"]);
		log_file("user/safari_info",sprintf("%s%s%s\n",me->query("id")+"在"+ctime(time())+"补偿",chinese_number(-my_book["Value"])+"点铜雀台积分，因为",my_book["name"]));
		tell_object(me,"你被补偿了"+chinese_number(-my_book["Value"])+"点铜雀台积分，因为"+my_book["name"]+"调整。\n");
		return 1;
	}
}
string look_shelf()
{
    int cost,i;
    object me=this_player();
    string str_cost,msg,msg_head=BRED+"\t\t\t\t\t秘籍室藏书\t\t\t\t\t \n"+NOR;
    string msg_public=HIB"『公共类秘籍心法』\n"NOR+LINE,msg_family=HIR"『门派类武功心法』\n"NOR+LINE,msg_sets=HIG"『系列类武功心法』\n"NOR+LINE;
    mapping *books=books();
	for (i=0;i<sizeof(books);i++)
    {
        if (books[i]["class"]=="公共武功")
        {
            msg_public+="["+books[i]["id"]+"]"+sprintf("%-42s",CYN+"《"+books[i]["name"]+"》"+NOR)+"  铜雀积分"+sprintf("%|22s",HIY+chinese_number(books[i]["cost"])+NOR)+"点  简介："+books[i]["desc"]+"\n";
        }
        else if (books[i]["class"]=="系列武功")
        {
            msg_sets+="["+books[i]["id"]+"]"+sprintf("%-42s",CYN+"《"+books[i]["name"]+"》"+NOR)+"  铜雀积分"+sprintf("%|22s",HIY+chinese_number(books[i]["cost"])+NOR)+"点  简介："+books[i]["desc"]+"\n";
        }
        else
        {
			if (me->query("chushi")&&books[i]["no_chushi"])
			{
                str_cost="∞";
            }
            else if (me->query("family/family_name")==books[i]["class"] || wizardp(me))
            {
                cost=books[i]["cost"];
                str_cost=chinese_number(cost);
            }
            else if (me->query("chushi/last_family")==books[i]["class"])
            {
                cost=books[i]["cost"]*3/2;
                str_cost=chinese_number(cost);
            }
            else
            {
                str_cost="∞";
            }
            msg_family+="["+books[i]["id"]+"]"+sprintf("%-49s",CYN+"《"+books[i]["name"]+"》"+HIW+"["+books[i]["class"]+"]"+NOR)+"  铜雀积分"+sprintf("%|22s",HIY+str_cost+NOR)+"点  简介："+books[i]["desc"]+"\n";
        }
    }
    msg=msg_head+"\n"+msg_public+"\n"+msg_sets+"\n"+msg_family+"\n\n"+"如需阅读，请自行按编号取下(qu 编号)。\n";
    return msg;
}

void init()
{
    add_action("do_qu","qu");
	add_action("recoup","recoup");
}



int do_qu(string arg)
{
    object new_book,me=this_player();
    mapping book,*books=books();
    int num,i,cost,flag=0;
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    
    if (!arg)
    {
        tell_object(me,"你要取什么？\n");
        return 1;
    }
    if( !sscanf(arg, "%d" , num ) ) 
    {
        tell_object(me,"你要取什么？\n");
        return 1;
    }
    for (i=0;i<sizeof(books);i++)
    {
        if (books[i]["id"]==num)
        {
            book=books[i];
            flag=1;
        }
    }
    if (!flag)
    {
        tell_object(me,"看清楚了，你到底要取什么？\n");
        return 1;
    }
    if (me->query("newjobs/completed/safari")<2)
    {
        tell_object(me,"至少需要完成两次以上铜雀台任务，方可在这里取物。\n");
        return 1;
    }
	if (book["no_chushi"]&&me->query("chushi"))
    {
        tell_object(me,book["name"]+"是"+book["class"]+"派不传之秘，只有纯"+book["class"]+"弟子可以修习！\n");
        return 1;
    }
    if (book["class"]!="公共武功"&&book["class"]!="系列武功"&&book["class"]!=me->query("family/family_name")&&book["class"]!=me->query("chushi/last_family"))
    {
        tell_object(me,book["name"]+"唯有"+book["class"]+"中人方可修习，你就不要做梦了！\n");
        return 1;
    }
    if (me->query("family/family_name")==book["class"])
    {
        cost=book["cost"];
    }
    else if (book["class"]=="系列武功"||book["class"]=="公共武功")
    {
        cost=book["cost"];
    }
    else
    {
        cost=book["cost"]*3/2;
    }
    if (me->query("safari_credit")<cost)
    {
        tell_object(me,"至少需要"+chinese_number(cost)+"点铜雀台任务积分，方可取到你要的东西。\n");
        return 1;
    }
    
    new_book=new(book["file"]);
    if (!new_book)
    {
            tell_object(me,"物品购买失败！\n");
            return 1;
    }
    new_book->set("owner",me->query("id"));
    new_book->move(me);
    tell_room(this_object(),me->name()+"取下了"+new_book->query("name")+"，好不得意。\n",me);
    tell_object(me,"你消耗了"+chinese_number(cost)+"点铜雀台积分，将"+new_book->query("name")+"收入囊中。\n");
    me->add("safari_credit",-cost);
	if (book["modified"])
	me->set("safari_modified/"+book["id"]+"/modified",book["modified"]);
	log_file("user/safari_info",sprintf("%s%s%s\n",me->query("id")+"在"+ctime(time())+"消耗",chinese_number(cost)+"点铜雀台积分，换取",new_book->query("name")));
    return 1;
}
