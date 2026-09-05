#include <room.h>
#include <ansi.h>
#include <localtime.h>  //以上都是头文件没啥好说的
inherit ROOM; //继承房间文件配置

nosave string *all_ids=({"sword","blade","staff","whip","axe","spear","hammer","halberd","dagger"});
object *sword; //两个全局变量,string和object是类型


void create() //建立房间的一些配置
{
        set("short", RED"藏剑阁"NOR);
        set("long", @LONG
这里是古铜雀台的藏剑阁，墙上(wall)挂着各种兵器。
LONG
        );
        set("exits", ([
             "north" : __DIR__"dating",
 
        ]));
        set("item_desc", ([
		"wall" : "墙上挂着很多武器，如果要进一步仔细查看，可用list <weapon类型>\n",
	    ])); //item_desc就是房间内用look wall可以看到的，这里也可以定义别的东西。
        
        setup();
      
}

int gene(string type)//函数名称，（）里是参数，也可以不带，看自己情况需不需要。
{
    int i;
    sword=({
    new("/obj/gem/weapon"),
    new("/obj/gem/weapon"),
    new("/obj/gem/weapon"),
    new("/obj/gem/weapon"),
    new("/obj/gem/weapon"),
    new("/obj/gem/weapon"),
    new("/obj/gem/weapon"),
    new("/obj/gem/weapon"),
    new("/obj/gem/weapon"),
    
});  //这里sword之前全局变量定义过了，因为多个函数需要调用，所以用全局，一般正常建议多用局部变量
    for (i=0;i<sizeof(sword);i++) //for函数没啥好说的
    {
        sword[i]->gen_weapon(1+random(9),8000+random(600),9999,type);  //这里的gen_weapon()函数是继承自 /obj/gem/weapon.c文件
        sword[i]->set_temp("safari_for_list",1); //加个mark
        sword[i]->set("forge/max",2);
        if (random(1000)>995)
        {
            sword[i]->set("forge/max",3);
        }
    }
    
    return 1;
}


string replace_color(string arg)
{
        string str;
        str = arg;
        str = replace_string(str,BLK,"");
        str = replace_string(str,RED,"");
        str = replace_string(str,GRN,"");
        str = replace_string(str,YEL,"");
        str = replace_string(str,BLU,"");
        str = replace_string(str,MAG,"");
        str = replace_string(str,CYN,"");
        str = replace_string(str,WHT,"");
        
        str = replace_string(str,HIR,"");
        str = replace_string(str,HIG,"");
        str = replace_string(str,HIY,"");
        str = replace_string(str,HIB,"");
        str = replace_string(str,HIM,"");
        str = replace_string(str,HIC,"");
        str = replace_string(str,HIW,"");
        str = replace_string(str,NOR,"");
        str = replace_string(str,BNK,"");   
        
                
        return str;
}

int do_list(string type)
{
    int i,j=0;
    string msg,arg,damage,forge;
    object me=this_player();
    if (!type)
    {
        tell_object(me,"你想看哪种武器的列表？\n"); //如果输入list命令后面没后缀就返回这条信息，程序return终止。
        return 1;
    }
    if (!type||member_array(type,all_ids)==-1) //member_array是判断第一个参数在第二个参数中是否存在，返回值-1就是不存在
    {
        tell_object(me,"你只能指定sword、blade、staff、whip、axe、spear、hammer、halberd、dagger其中的一种。\n");
        return 1;
    }
    for (i=0;i<sizeof(sword);i++)
    {
        if (sword[i]&&sword[i]->query("skill_type")==type&&sword[i]->query_temp("safari_for_list"))
        {
            j=1;
        }
    }
    if (!j)
    {
        gene(type);
    }
    set("last_person",me->query("id"));
    set("last_type",type);
    msg=YEL+"藏剑阁现有如下兵器：\n"+NOR; 
    for (i=0;i<sizeof(sword);i++)
    {
        if (sword[i]->query_temp("safari_for_list"))
        {
            arg=sword[i]->query("name");
            arg=replace_color(arg);
            if (sword[i]->query("weapon_prop/damage")>210)
            {
                damage="冠绝天下";
            }
            else if (sword[i]->query("weapon_prop/damage")>160)
            {
                damage="世所罕见";
            }
            else if (sword[i]->query("weapon_prop/damage")>100)
            {
                damage="锋锐尚可";
            }
            else
            {
                damage="劣拙之作";
            }
            if (sword[i]->query("forge/max")==3)
            {
                forge="◎◎◎";
            }
            else
            {
                forge="◎◎";
            }
            msg+="["+(int)(i+1)+"]"+arg+"\t▲"+damage+"▲"+NOR+"\t"+forge+NOR+"\n"; //+=就是之前的msg+新内容
        }
        
    }
    msg+="如有中意的武器，可以取(qu)下，"+BLINK+CYN+"将消耗铜雀台积分。\n"+NOR;
    tell_object(me,msg);//tell_object(对象,string类信息)是lpc一个函数，通知信息，只有这个me接受信息
    return 1;
}

int do_qu(string arg)
{
    int i;
    object me=this_player();//this_player就是动作的发出者
    int num,aff;
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
    if( !sscanf(arg, "%d" , num ) ) //判断arg是否是正确数据类型，如果不是返回数据，如果是把num赋值arg
    {
        tell_object(me,"你要取什么？\n");
        return 1;
    }
    if (num>sizeof(sword)||num<0)
    {
        tell_object(me,"看清楚了，你到底要取什么？\n");
        return 1;
    }
    num=num-1;
    if (me->query("newjobs/completed/safari")<2)
    {
        tell_object(me,"至少需要完成两次以上铜雀台任务，方可在这里取物。\n");
        return 1;
    }
    if (me->query("safari_credit")<2)
    {
        tell_object(me,"至少需要两点铜雀台任务积分，方可取到你要的东西。\n");
        return 1;
    }
    if (!sword[num])
    {
        tell_object(me,"这样武器不存在。\n");
        return 1;
    }
    if (!sword[num]->query_temp("safari_for_list"))
    {
        tell_object(me,"此剑不是被你取下了？\n");
        return 1;
    }
    aff=50+random(26);
    sword[num]->add("max_rigidity",aff);
    sword[num]->move(me);
    sword[num]->delete_temp("safari_for_list",1);
    message_vision("$N取下了"+sword[num]->query("name")+"，好不得意。\n",me);
    tell_object(me,"你消耗了两点铜雀台积分，将"+sword[num]->query("name")+"收入囊中。\n");
    tell_object(me,sword[num]->query("name")+"额外附加了"+chinese_number(aff)+"点永久耐久。\n");
    me->add("safari_credit",-2);
    return 1;
}

void init()
{
    add_action("do_list","list");//add_action增加任何一个object的动作，可以是npc，房间，物品等等
    add_action("do_qu","qu");
}

