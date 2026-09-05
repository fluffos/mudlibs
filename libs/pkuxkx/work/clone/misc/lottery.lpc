#pragma save_binary
// set("now",({"rongg","lightning"})) 购买奖券的人
// set("nowrongg",({1,2,3,4,5})) rongg购买的号码
// set("lucky_numbers",({"1","3","2345"})); 中奖号码
// set("2345",1)  set("1",2) set("3",3)
// 头等奖2345号。 一等奖1号  二等奖3号
// set("all_money"); 总共积累金钱数目
// 特等奖奖金为all_money*30%  一名
// 一等奖奖金为all_money*10%  二名
// 二等奖奖金为all_money*5%   三名
// 三等奖奖金为all_money*1%   十名
// 奖金总额为all_money*75%
// 所有没有领取的奖金连同all_money*25%滚入下一期奖金之中。并且系统每一期
// 会自动多加25两黄金作为累积奖金。。
// 数组有三个。now next temp。分别记录当前可以领奖的记录。
// 下一期的记录。以及交换数组。
// By rongg@szutx 1998 12.1
#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define LOTTERY NPCDATA + "lottery"

inherit F_SAVE;

#include <ansi.h>
inherit NPC;
string query_save_file()
{
        return LOTTERY;
}

int ask_me();

void create()
{
        seteuid(getuid());
        set_name("蓉儿", ({ "rong er" }));
        if(!restore())
        {
        	set("title",CYN"风花雪月"NOR);
        	set("gender", "女性" );
        	set("age", 23);
        	set("all_money",5000000); // 基本奖金500两黄金
        	set("time",1); // 第一期。
        	set("long", "此人专门负责发行福利券。\n");
        }        
        set("inquiry",([
            "彩券":          (:ask_me:),
            "lottery":       (:ask_me:),
            "奖券":          (:ask_me:), 
            "彩票":          (:ask_me:), 
        ]));
        setup();
        carry_object("/clone/armor/skirt")->wear();
        carry_object("/clone/armor/womanshoes")->wear();
}

void init()
{
        object me;
        me=this_player();
		if(userp(me)&&random(3))

        call_out("greeting",1,me);
		// if(!wizardp(me)) // 巫师不能购买奖券
        add_action("do_buy","buy"); // 购买
        add_action("do_demand","demand"); // 查询
        add_action("do_draw","lingjiang"); // 领取奖金。动词和金龙卡有冲突。
        add_action("do_list","list");
}

int do_list()
{
        object me;
        me=this_player();
        tell_object(me,"你可以购买以下物品\nlottery 福利奖券！  \n");
        return 1;
}
void greeting(object me)
{
        string msg;
        int all_money;
        all_money=query("all_money");
        msg = CYN"福利奖券现在发行第"+chinese_number(query("time"))+"期。\n";
        if (all_money/10000)
        {
        	msg +="本期累积奖金为"+all_money/10000+"两黄金";
            all_money =all_money%10000;
        }
        if(all_money/100)        
        {
        	msg +=""+all_money/100+"两银子";
            all_money =all_money%100;
        }    
        if(all_money>0)
        {
        	msg +=""+all_money+"个铜板";
        }
        msg += "欢迎购买！\n"NOR;
        message_vision(msg,me);
        command("say 欢迎购买福利奖券!!!");
        return ;

}

int do_buy(string arg)
{
        object me;
        int number,i,j,all_money,number1,number2,temp_number;
        string msg,*persons,*sum,my_id,*temp;
        me=this_player();
        my_id=me->query("id");

		if(!arg)
                return 0;
		tell_object(me,"暂时关闭，稍后开放\n");
		return 1;
		if(sscanf(arg,"%d to %d lottery from rong er",number1,number2)==2)
        {
        	sum=query("next"+my_id);
            if(!sum) sum = ({});
            if(sizeof(sum)>=50)
            {
            	msg = CYN"蓉儿笑道：您买的已经有五十张奖券了，不能再买了哟！\n"NOR;
                tell_object(me,msg);
                return 1;
            }
            if(number1 < 1||number1 > 8000||number2<1||number2>8000)
            {
            	tell_object(me,"奖券号码的范围只能是0--8000之间\n");
                return 1;
            }
        	temp_number=number1-number2;
        	if(temp_number==0)
            {
            	 tell_object(me,"你要购买几号到几号的彩票？\n"); 
            	 return 1;
            }
            temp=({});
            if(number1-number2>0)        //默认number2>number1
            {
            	temp_number=number1;
                number1=number2;
                number2=temp_number;
            }
            persons = query("next"); //还没有开奖的一期可以购买
            if(!persons) // 第一次有人买
            {
            	persons = ({});
                for(j=number1;j<=number2;j++)
                {
                	temp+=({j});
                    if(sizeof(temp)>=50)
                    break;
                }
            }
            else
            {
            	for(j=number1;j<=number2;j++)
                {
                	for(i=0;i<sizeof(persons);i++)
                    {
                    	if(member_array(j,query("next"+persons[i]))!=-1 ) continue;
                        else temp+=({j});
                    }
                    if((sizeof(temp)+sizeof(sum))>=50) break;
                 }
             }
             if(sizeof(temp)<=0)
             {
             	tell_object(me,"非常抱歉。您要购买的号码已经全部被卖完了。\n"); 
             	return 1;
             }
             	
             if(!me->can_afford(2500*sizeof(temp)))
             {
                        tell_object(me,"你的钱不够一次买这么多张彩票。\n");        
                        return 1;
             }
             me->pay_money(2500*sizeof(temp));
             sum +=temp;
             set("next"+my_id,sum); // 此人购买的下一期的所有号码
             if(member_array(my_id,persons)==-1)
             {
                        persons += ({my_id});
                        set("next",persons); // 购买下一期的奖券。
             }
             all_money=query("all_money");
             all_money+=2500*sizeof(temp); // 积累奖金
             set("all_money",all_money);
             msg = CYN"你买下"+chinese_number(sizeof(temp))+"张奖券。号码如下：\n"NOR;
             tell_object(me,msg);
             j=0;
             for(i=0;i<sizeof(temp);i++)
             {
                        tell_object(me,""+temp[i]+" 号");
                        j++;
                        if(j%10==0)
                                tell_object(me,"\n");
             }                
             msg = CYN"\n蓉儿笑道：好了。我帮这位"+RANK_D->query_respect(me)+"保管奖券吧！\n"
                                "每两天开一次奖。你可以随时来我这里查询(demand)。\n"NOR;
                tell_object(me,msg);
                this_object()->save();
                return 1;                
        }

        else if(sscanf(arg,"%d lottery from rong er",number)==1)
                {
                sum=query("next"+my_id);
                if(!sum) sum = ({});
                if(sizeof(sum)>=50)
                        {
                        msg = CYN"蓉儿笑道：您买的已经有五十张奖券了，不能再买了哟！\n"NOR;
                        tell_object(me,msg);
                        return 1;
                        }
                if(number < 1||number > 8000)
                        {
                        tell_object(me,"奖券号码的范围只能是0--8000之间\n");
                        return 1;
                        }
                if(!me->can_afford(2500))
                        {
                        tell_object(me,"一张奖券25两银子。您没有这么钱！\n");        
                        return 1;
                        }
                me->pay_money(2500);
                persons = query("next"); //还没有开奖的一期可以购买
                if(!persons)        persons = ({});
                for(i=0;i<sizeof(persons);i++)
                        {
                        if(member_array(number,query("next"+persons[i]))!=-1 )
                                {
                                tell_object(me,"号码"+number+"已经有人买走了。\n");
                                return 1;
                                }
                        else continue;
                        }
                
        msg = CYN"你买下一张奖券。号码是"+number+"\n"NOR;
        tell_object(me,msg);
                msg = CYN"蓉儿笑道：好了。我帮这位"+RANK_D->query_respect(me)+"保管奖券吧！\n"
                                "每两天开一次奖。你可以随时来我这里查询(demand)。\n"NOR;
                tell_object(me,msg);
                sum +=({number});
                set("next"+my_id,sum); // 此人购买的下一期的所有号码
                if(member_array(my_id,persons)==-1)
                        {
                        persons += ({my_id});
                        set("next",persons); // 购买下一期的奖券。
                        }
                all_money=query("all_money");
                all_money+=2500; // 积累奖金
                set("all_money",all_money);
                this_object()->save();
                return 1;
                }
		else if(arg=="lottery from rong er")
        {
                tell_object(me,"buy <号码> lottery from rong er\n");
                return 1;        
        }
		else	return 0; // 回传给buy 指令。不知道有没有其它办法。
}

int do_demand(string arg)
{
    object me;
    int i,j,temp,lucky_number,*lucky_numbers,start;
    string my_id,numbers,*persons;
    me=this_player();
    my_id = me->query("id");
    persons = query("now"); // 已经开奖的这一期购买人数。
    temp = 0;
//        tell_object(me,"暂时关闭稍后开放\n");
//          return ;
	
	if(!persons||member_array(my_id,persons)==-1 )
    tell_object(me,"您上一期并没有购买任何奖券！\n");
   
    numbers=query("now"+my_id); //本期已经开奖。顾客购买的号码。
    tell_object(me,"本期累积奖金高达"+query("all_money")/10000+"两黄金！\n");
    tell_object(me,"您第"+query("time")+1+"期购买的奖券号码如下：\n");
    j=0;
    for(i=0;i<sizeof(numbers);i++)
    {
   		tell_object(me,""+numbers[i]+" 号");
        j++;
        if(j%10==0)
        tell_object(me,"\n");
    }
    tell_object(me,"\n总共"+chinese_number(i)+"张奖券！\n");
    start = query("start"); // 看看有没有开奖。
    if(!start||start==0)
    {
                tell_object(me,"暂时还没有开奖。\n");
                return 1;
    }
    else    lucky_numbers = query("lucky_numbers");
    {
    	for(i=0;i<sizeof(numbers);i++)
        {
        	if(member_array(numbers[i],lucky_numbers)!=-1)
            // 中奖了。
            {
            	lucky_number = numbers[i];
                tell_object(me,CYN"恭喜您！");
                tell_object(me,"您购买的第"+lucky_number+"号奖券中");
                tell_object(me,"了"+chinese_number(query(""+lucky_number))+"");
                tell_object(me,"等奖！\n"NOR);
                tell_object(me,"\n赶快领奖吧！(lingjiang)\n"NOR);
                temp = 1;
             }
             else        continue;                                
         }
     }
     if(temp != 1)
                {
                tell_object(me,"\n很可惜！您购买的奖券没有一张中奖。\n");
                persons -= ({my_id});
                set("now",persons); // 把此人从记录中删除。
                this_object()->delete("now"+my_id);// 把此人上一期购买的号码删除
                this_object()->save();
                }
                return 1;
}

int do_draw()
{
                object me,money;
                int i,j,start,prize,lucky_number,*lucky_numbers;
                int all_money;
                string my_id,numbers,*persons;
                me=this_player();
                my_id = me->query("id");
                persons = query("now"); // 本期购买人数。
                prize = 0;
                all_money = query("all_money");
if(!persons||member_array(my_id,persons)==-1 )
                return notify_fail("您并没有购买第"+query("time")+"的奖券！\n");
                                
                numbers=query("now"+my_id); // 顾客购买的所有奖券号码。
                tell_object(me,"您这期总共购买的奖券号码如下：\n");
                j=0;
                for(i=0;i<sizeof(numbers);i++)
                        {
                        tell_object(me,""+numbers[i]+" 号");
                        j++;
                        if(j%10==0)
                                tell_object(me,"\n");
                        }
                tell_object(me,"\n总共"+chinese_number(i)+"张奖券！\n");
                start = query("start"); // 有没有开奖。
if(!start)
                {
                tell_object(me,"暂时还没有开奖。\n");
                return 1;
                }
else    lucky_numbers = query("lucky_numbers");
                {
                for(i=0;i<sizeof(numbers);i++)
                        {
                        if(member_array(numbers[i],lucky_numbers)!=-1)
                            // 中奖了。
                                {
                                lucky_number = numbers[i];
                                tell_object(me,CYN"恭喜您！");
                                tell_object(me,"您购买的第"+lucky_number+"号奖券中");
                                tell_object(me,"了"+chinese_number(query(""+lucky_number))+"");
                                tell_object(me,"等奖！\n"NOR);
                                switch (query(""+lucky_number))
                                        {
                                        case 1:
                                                prize += all_money*20/100;
                                                break;
                                        case 2:
                                                prize += all_money*10/100;
                                                break;
                                        case 3:
                                                prize += all_money*5/100;
                                                break;
                                        case 4:
                                                prize += all_money*1/100;
                                                break;
                                        default :
                                                break;
                                        }
                                lucky_numbers -=({lucky_number});
                                delete(""+lucky_number);
                                set("lucky_numbers",lucky_numbers);// 删除中奖号码。
                                }
                        else        continue;
                        }
                }
if(prize <=0)
                {
                tell_object(me,"\n很可惜！您购买的奖券没有一张中奖。\n");
                persons -= ({my_id});
                set("now",persons);
            this_object()->delete("now"+my_id);
            this_object()->save();
                }
else    
                {
                tell_object(me,"\n恭喜您！您总共的奖金金额是:");
                if (prize/10000)
                        {
                        money=new("/obj/money/gold");
                        money->set_amount(prize/10000);
                        money->move(me);
                        tell_object(me,""+prize/10000+"两黄金。");
                        prize =prize%10000;
                        }
                if(prize/100)        
                        {
                        money=new("/obj/money/silver");
                        money->set_amount(prize/100);
                        money->move(me);
                        tell_object(me,""+prize/100+"两银子");
                        prize =prize%100;
                        }
                if(prize>0)
                        {
                        money=new("/obj/money/coin");
                        money->set_amount(prize);
                        money->move(me);
                        tell_object(me,""+prize+"个铜板");
                        }
                tell_object(me,"\n");
                this_object()->delete(my_id); // 删除购买记录
                persons -= ({my_id});
                set("now",persons); // 删除购买记录
                this_object()->delete("now"+my_id);
                this_object()->save();
                }
                this_object()->save();
                return 1;
}

int start_work() // 开始抽奖
{
                int all_money,*lucky_numbers,lucky_number,i,j,prize,*numbers;
                string *persons;
// 开始抽奖之前把上一期省下的奖金累积起来。
                lucky_numbers = query("lucky_numbers");
                all_money=query("all_money");
if(lucky_numbers) // 有人没有领取奖金。自动累积。
                {
                for(i=0;i<sizeof(lucky_numbers);i++)
                        {
                        lucky_number=lucky_numbers[i];
           switch (query("lucky_number"))
                                {
                                case 1:
                                        prize += all_money*20/100;
                                        break;
                                case 2:
                                        prize += all_money*10/100;
                                        break;
                                case 3:
                                        prize += all_money*5/100;
                                        break;
                                case 4:
                                        prize += all_money*1/100;
                                        break;
                                default :
                                        break;
                                }

//          command("say i del "+query(""+lucky_number));
                        this_object()->delete(""+lucky_number); // 删除中奖号码
                        }
                }
                all_money -= prize; // 每一期系统会多25gold。
                all_money+=800000;
                set("all_money",all_money);
                this_object()->delete("lucky_numbers");
      command("say 各位先生、女士。大家好。现在开始抽奖！");
                lucky_numbers = ({});
for(j=1;j<=16;j++) // 总共十六个幸运号码故循环十六次足以。
                {
                i=random(8000)+1;
                while(member_array(i,lucky_numbers)!=-1)
                        {
                        i=random(8000)+1;        
                        }
                lucky_numbers +=({i});
                if(j<=1)
                        set(""+i+"",1); // 特等奖。
                else if(j<=3)
                        set(""+i+"",2); // 一等奖。
                else if(j<=6)
                        set(""+i+"",3); // 二等奖。
                else
                        set(""+i+"",4); // 三等奖
                }
                set("lucky_numbers",lucky_numbers);
        command("say 抽奖完毕。欢迎幸运儿前来领奖(lingjiang)");
                command("say 本期累积奖金为"+query("all_money")/10000+"两黄金！");
                add("time",1); // 当前的这一期开奖了。
                persons=query("now");
                if(persons)
                        {
                        for(i=0;i<sizeof(persons);i++)
                                {
                                this_object()->delete("now"+persons[i]);
                                }
                        this_object()->delete("now");
                        }
                persons =query("next");
                if(persons)
                        {
                        this_object()->set("now",persons);
                        for(i=0;i<sizeof(persons);i++)
                                {
                                numbers = query("next"+persons[i]);
                                if(!numbers) continue;
                                set("now"+persons[i],numbers);
                                this_object()->delete("next"+persons[i]);
                                }
                        this_object()->delete("next");
                        }
                else
                        {
                        this_object()->save();
                        return 1;
                        }
                set("start",1); // 开奖了
                if(query("all_money")>=100000000)
                     set("all_money",100000000);
                this_object()->save();
                return 1;
}


int ask_me()
{
        object me;
                string msg;
                int all_money;
        me=this_player();
        all_money=query("all_money");
        
                msg = CYN+MUD_NAME+"福利奖券现在发行"
                                "第"+chinese_number(query("time"))+"期。\n";
                if (all_money/10000)
                        {
                        msg +="本期累积奖金为"+all_money/10000+"两黄金";
                        all_money =all_money%10000;
                        }
                if(all_money/100)        
                        {
                        msg +=""+all_money/100+"两银子";
                        all_money =all_money%100;
                        }
                if(all_money>0)
                        {
                        msg +=""+all_money+"个铜板";
                        }
                msg += "欢迎购买！\n"NOR;
                message_vision(msg,me);
                return 1;
}
 
