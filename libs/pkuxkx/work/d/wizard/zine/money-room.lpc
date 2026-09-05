#include <room.h>
#include <ansi.h>
#include <localtime.h>
inherit F_SAVE;
inherit ROOM;
#define SELF_CHANNEL "/data/business/self_channel"
#define LINE   HIW"≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈\n"NOR
string query_save_file()
{
        return SELF_CHANNEL;
}
string look_heap();

mapping *books = ({
            ([  "id":1001,"file":"/d/changjiang/obj/tqt-ob1","name":"铜雀","desc":"在失败前可大幅增加铜雀台任务截止时间。","cost":1,"sets":4,]),
            ([  "id":1002,"file":"/d/luoyang/npc/obj/modaoshi-tqt","name":"磨刀石","desc":"大幅恢复武器耐久度。","cost":2,"sets":3,]),
			([  "id":1003,"file":"/d/wizard/zine/obj/key_spider","name":"钥匙","desc":"进入养蛛室的钥匙，修炼千蛛万毒手初期必须。","cost":1,"sets":1,]),
            ([  "id":1004,"file":"/d/changjiang/obj/tqt-ob3","name":"孔雀石","desc":"可以有效降低铜雀台任务的cd时间。","cost":2,"sets":3,]),
            ([  "id":1005,"file":"/d/changjiang/obj/tqt-ob4","name":"特技升级秘籍","desc":"可以再付出一些代价以后取得特技升级点数，需求不够可以购买，但是无法得到升级点数，一经售出，所有可能损失由买家承担。","cost":1,"sets":1,]),
            ([  "id":1006,"file":"/d/changjiang/obj/tqt-ob5","name":"特技研究秘籍","desc":"可以再付出一些代价以后取得一个特技， 需求不够可以购买，但是无法得到特技，一经售出，所有可能损失由买家承担。","cost":1,"sets":1,]),
            });


void create()
{
        set("short", HIM"藏室"NOR);
        set("long", @LONG
这里是古铜雀台的藏室，珍宝堆(heap)满了地板。
LONG
        );
        set("exits", ([
             "southeast" : __DIR__"dating",
 
        ]));
        set("item_desc", ([
		"heap" : (:look_heap:),
	    ]));
        
        setup();
      
}

string look_heap()
{
    int i;
    string msg,msg_body="",msg_head=HIY+"\t\t\t\t\t珍宝室出售物品\t\t\t\t\t \n"+NOR;
    for (i=0;i<sizeof(books);i++)
    {
        msg_body+="["+books[i]["id"]+"]"+sprintf("%-36s",CYN+"『"+books[i]["name"]+"』"+NOR+"×"+books[i]["sets"])+sprintf("%-30s","铜雀积分"+HIY+chinese_number(books[i]["cost"])+NOR+"点")+"简介："+books[i]["desc"]+"\n";
    }
    msg=msg_head+LINE+msg_body+LINE+HIW+"请自行按编号购买(buy)。\n"+NOR;
    return msg;
}

void init()
{
    add_action("do_buy","buy");
}



int do_buy(string arg)
{
    object new_book,me=this_player();
    mapping book;
    int num,i,cost,flag=0;
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    
    if (!arg)
    {
        tell_object(me,"你要买什么？\n");
        return 1;
    }
    if( !sscanf(arg, "%d" , num ) ) 
    {
        tell_object(me,"你要买的编号是什么？\n");
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
        tell_object(me,"看清楚了，你到底要买什么？\n");
        return 1;
    }
    cost=book["cost"];
    if (me->query("safari_credit")<cost)
    {
        tell_object(me,"至少需要"+chinese_number(cost)+"点铜雀台任务积分，方可购买你要的东西。\n");
        return 1;
    }
    for (i=0;i<book["sets"];i++)
    {
        new_book=new(book["file"]);
        if (!new_book)
        {
            tell_object(me,"物品购买失败！\n");
            return 1;
        }
        new_book->set("owner",me->query("id"));
        new_book->move(me);
        tell_object(me,"你获得了一"+new_book->query("unit")+new_book->query("name")+"。\n");
    }
    tell_object(me,"你消耗了"+chinese_number(cost)+"点铜雀台积分，将"+chinese_number(book["sets"])+"件"+new_book->query("name")+"收入囊中。\n");
    tell_room(this_object(),me->query("name")+"购买了"+new_book->query("unit")+new_book->query("name")+"，仔细收入怀里。\n",me);
    me->add("safari_credit",-cost);
	log_file("user/safari_info",sprintf("%s%s%s\n",me->query("id")+"在"+ctime(time())+"消耗",chinese_number(cost)+"点铜雀台积分，换取",new_book->query("name")));
    return 1;
}