// /obj/nokia.c

//inherit HANDPHONE;
inherit ITEM;
#include <ansi.h>
int phone_time=0;
#define PRICE 1
//int wait_for_recall(object,object);
void create()
{
        set_name("Nokia 3210手机", ({ "nokia","3210" }) );

        set("long",
        "这是一部崭新的Nokia 3210手机，号称“一键通”、“彩壳随心换”。\n"
        "重量约和一块砖头相仿，虽然是内置天线，通话质量倒还算是不错。\n"
        "仔细看时，背面还有一行小字：\n"
        "          北京英迪时空科技发展有限公司祝您玩的开心！          \n"
        "用phone id来打电话，这是英迪公司提供的id解析功能。\n"
        "请用send 内容  来通话。如果您要结束通话，请用hangup指令"
        "特别提示：虚拟电信实行两秒计费，每两秒收费2分。\n"
        );
        set("menu",([
                "打电话给":"phone ...",
                "发送":"send ...",
                "挂机":"hangup",
                "缴费":"turnin ...",
                "查询":"checkmoney",
        ]));
        set_weight(129);
        set("value",120000);
        //set("wap_type",NOWAP);
        set("unit", "部");
        set("material", "plastic");

        setup();
}
void init()
{
        add_action("do_phone","phone");
        add_action("do_send","send");
        add_action("do_hangup","hangup");
        add_action("do_turnin","turnin");
        add_action("do_check","checkmoney");
//        add_action("do_jieting","jieting");
}
void heart_beat()
{
        phone_time+=2;
        return;
}
void turn_heart_beat(int flag)
{
        if(flag>0) set_heart_beat(1);
                else set_heart_beat(0);
}
void reset_phone_time()
{
        phone_time=0;
}
int do_phone(string arg)
{
        object me,ppl,target,phone2;
        me=this_object();
        ppl=this_player();
        if(environment(me)!=ppl)
        {
                write("那是别人的手机，不好乱用吧？\n");
                return 1;
        }
        if(!arg||arg=="")
        {
                write("你要给谁打电话？\n");

                return 1;
        }
        if(ppl->query("phone/money")<=0)
        {
                write("您的电话费已经用完了，请即时续费。\n");
                return 1;
        }
        if(ppl->query_temp("is_phone")==1)
        {
                write("你正在通话中。。。\n");
                return 1;
        }
        if(!objectp(target=find_player(arg)))
        {
                write("嘟..嘟..嘟..没有这个电话号码。。\n");
                return 1;
        }
        if(!objectp(phone2=present("nokia",target)))
        {
                write("嘟..嘟..嘟..没有这个电话号码。。\n");
                return 1;
         }
        if(target==ppl)
        {
                write("自己给自己打电话？电话费很贵的！\n");
                return 1;
        }
        if(target->query_temp("is_phone")==1)
        {
                write("嘟嘟..嘟嘟..您拨叫的用户正忙。\n");
                return 1;
        }
        if(target->query("phone/money")<0)
        {
                write("您拨叫的用户已经没有话费了，我们不能为您接通。\n");
                return 1;
        }
        write("嘟...嘟...嘟....接通了。\n");
        tell_object(target,"叮~~~~叮~~~~~,"+ppl->name()+"给你来电话了。\n");
        target->set_temp("is_phone",1);
        target->set_temp("phone/target",ppl);
        ppl->set_temp("is_phone",1);
        ppl->set_temp("phone/target",target);
        //remove_call_out("wait_for_recall");
        //call_out("wait_for_recall",10,ppl,target);
        write("您可以用send指令开始通话了。\n");
        phone_time=0;
        phone2->reset_phone_time();
        phone2->turn_heart_beat(1);
        set_heart_beat(1);
        return 1;
}
int do_send(string arg)
{
        string msg="";
        object ppl,target;
        ppl=this_player();
        if(!ppl->query_temp("is_phone"))
        {
                write("您现在并没有接通某人的电话。\n");
                return 1;
        }
        if(!objectp(target=ppl->query_temp("phone/target")))
        {
                write("对方已经离开这个世界了。\n");
                write("本次通话时间："+chinese_number(phone_time)+"秒\n"
                        "收费"+MONEY_D->money_str(phone_time*10)+"\n");
                ppl->add("phone/money",-phone_time*10);
                ppl->set_temp("is_phone",0);
                ppl->delete_temp("phone");
                return 1;
        }
        if(!arg||arg=="")
        {
                msg="对方的话很模糊。。好像是：咿咿呀呀，及拉巴拉。。。\n";
        }
        else
        {
                msg=arg;
        }
        if(sizeof(msg)>60)
                msg=msg[0..59];
        msg="手机里传来"+ppl->name()+"的声音:"+HIY+msg+NOR;

        tell_object(target,msg);
        if(!arg||arg=="")
        {
                msg=HIG"。。。。。。。\n"NOR;
        }
        else
        {
                msg=arg+"\n";
        }
        if(sizeof(msg)>60)
                msg=msg[0..59];
        msg="你对着电话那头的"+target->name()+"说道："+HIR+msg+NOR;
        tell_object(ppl,msg);
        return 1;
}
int do_hangup()
{
        object ppl,target,phone2;
        ppl=this_player();
        if(ppl->query_temp("is_phone")!=1)

        {
                write("你现在并没有在使用手机阿。\n");
                return 1;
        }
        if(objectp(target=ppl->query_temp("phone/target")))
        {
                tell_object(target,ppl->name()+"挂掉了电话。\n");
                tell_object(target,"本次通话时间："+chinese_number(phone_time)+"秒\n"
                "收费"+MONEY_D->money_str(phone_time*PRICE)+"\n");
                target->add("phone/money",-phone_time*PRICE);
                target->set_temp("is_phone",0);
                target->delete_temp("phone");
                target->save();
        }
        ppl->set_temp("is_phone",0);
        if(phone_time<=0)
        {
                write("本次通话不收取您的费用。\n");
                return 1;
        }
        write("本次通话时间："+chinese_number(phone_time)+"秒\n"

                "收费"+MONEY_D->money_str(phone_time*PRICE)+"\n");
        ppl->add("phone/money",-phone_time*PRICE);
        ppl->set_temp("is_phone",0);
        ppl->delete_temp("phone");
        phone_time=0;
        set_heart_beat(0);
        if(!objectp(phone2=present("nokia",target)))
        {
                write("对方的电话好象坏了耶~~~\n");
        }
        phone2->turn_heart_beat(0);
        phone2->reset_phone_money();
        ppl->save();
        return 1;

}
int do_turnin(string arg)
{
        int money;
        object ppl=this_player();

        if(!arg||arg==""||sscanf(arg,"%d",money)!=1)
        {
                write("您要交纳多少电话费？\n");
                return 1;
        }
        if(ppl->query("money") < money)
        {
                write("您并没有这么多现金。\n");
                return 1;
        }
        ppl->add("money",-money);
        ppl->add("phone/money",money);
        write("您现在的话费是："+MONEY_D->money_str(ppl->query("phone/money"))+"\n");
        ppl->save();
        return 1;
}
int do_check()
{
        write("您现在剩余的话费为："+MONEY_D->money_str(this_player()->query("phone/money"))+"\n");
        return 1;
}



 

  
