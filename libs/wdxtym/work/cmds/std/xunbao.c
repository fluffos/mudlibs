// by fid
#include <ansi.h>
inherit F_DBASE;
inherit F_CLEAN_UP;
string *color=({HIR"红",HIY"橙",YEL"黄",HIG"绿",HIC"青",HIB"蓝",HIM"紫",HIW"白",BLK"黑"});
string *unit=({"道","缕","股","片","片"});
string *light=({"光"NOR,"烟"NOR,"气"NOR,"云"NOR,"霞"NOR});
string *baowu=({
	"clone/baowu/1",
	"clone/baowu/2",
	"clone/baowu/3",
	"clone/baowu/4",
	"clone/baowu/5",
	"clone/baowu/6",
	"clone/baowu/7",
	"clone/baowu/8",
	"clone/baowu/9",
	"clone/baowu/10"
});

void create()
{
    set("name","寻宝精灵");
    set("id","xbjl");
    seteuid(getuid());
}

int main(object me,string arg)
{
	string dest;
    object env;
    int sec,need,time,timedelay,kar;
	mapping exit;

    env=environment(me);

    if (!WABAO_D) return notify_fail("挖宝精灵还没载入。\n");
    if (me->is_busy()) return notify_fail("你现在正忙着呢。。。\n");
    if (me->query("combat_exp") < 10000 ) return notify_fail("你修为不足，如何能在江湖上寻宝？\n");
    if (me->query("mud_age") < 172800 ) return notify_fail("你太年轻了，等过两岁再寻宝吧。\n");
        if ( !present("skybook", me) )
         return notify_fail("你没有"+HIW"十四天书"NOR+"，怎么能寻宝呢？\n");
    if (!arg||arg==""||sscanf(arg,"%d",sec)!=1)
        return notify_fail("xunbao <秒数>\n\n你要花费多少时间来寻找？\n\n");
	if(!me->query_temp("xunbao"))
		         return notify_fail("你刚刚寻宝过，等待下一次吧\n");

    time=me->query_temp("xunbao/time");
    need=me->query_temp("xunbao/need");
    if (!need||need==0)
        {
        kar=40-me->query("kar");
        need=kar*3;
        need+=random(kar*2);
        if (need<30) need=30;
        me->set_temp("xunbao/need",need);
        }
    if (file_name(env)+".c"==WABAO_D->query("file"))
        {
        if (time<need)
            {
            timedelay=((sec+time>=need)?(need-time):sec);
            me->add_temp("xunbao/time",sec);
            }
        else
            timedelay=1;
        }
    else
        timedelay=sec;
    message_vision(HIC"$N对照着"+HIW"《十四天书》"+HIC"，蹲了下来开始寻宝。\n"NOR,me);
    me->start_busy(timedelay,timedelay);
    call_out("end_finding",timedelay,me,env);
    return 1;
}

void end_finding(object me,object env)
{
        int gain,i;
        object ob,bao;
        me->interrupt_me();
        if (!WABAO_D->query("file")) me->delete_temp("xunbao");
        if (file_name(env)+".c"!=WABAO_D->query("file")
                )
        {
        tell_object(me,HIC"良久，你还是一无所获,也许早就被人捷足先登了。\n"NOR);
        tell_room(env,HIC+me->query("name")+"捶了捶发酸的腰，失望的站起身来。\n"NOR,me);
        return ;
        }
        me->delete_temp("xunbao");
        WABAO_D->delete("file");
        WABAO_D->delete("desc");
        log_file("wabao",sprintf("[%s]%s wabao from %s\n",
                    ctime(time()),
                    getuid(me),
                    file_name(env)) );
        i=random(sizeof(unit));
        message_vision(HIG"突然，从地上涌起一"+unit[i]+color[random(sizeof(color))]+
                        light[i]+HIG"将$N笼罩起来……\n"NOR,me);
        gain=5000 + 100 * me->query("kar") + random(5000);
        /*me->add("xunbao/get",1);
        if (me->query("xunbao/get")>10)
                {
                tell_object(me,HIM"你已经寻到太多宝物了，是否应该考虑孝敬大家一点？\n"NOR);
                return;
                }*/
        switch(random(6))
        {
        case 0:
                gain=1+random(5);
                ob=new("/clone/money/gold");
                ob->set_amount(gain);
                ob->move(me);
	message("channel:chat", HIM + ZJSIZE(25)"【寻宝精灵】"+me->query("name")+"通过寻宝得到了"+chinese_number(gain)+"两黄金！。\n"NOR,users());
                tell_object(me,sprintf(HIY"你获得了%s两黄金，10战令修为！\n"NOR,
                        chinese_number(gain)));
						me->add("xunbaocshu1",1);
						me->add("zhanling/a7",10);
                break;
        case 1:
                gain=2+random(6);
						me->add("xunbaocshu1",1);
						me->add("zhanling/a7",10);
                me->add("jifeng",gain);
	message("channel:chat", HIM + ZJSIZE(25)"【寻宝精灵】"+me->query("name")+"通过寻宝得到了"+chinese_number(gain)+"个点券！。\n"NOR,users());
                tell_object(me,sprintf(HIY"你获得了%s点点券，10战令修为！\n"NOR,
                        chinese_number(gain)));
                break;
        case 2:
                gain=3+random(5);
						me->add("xunbaocshu1",1);
						me->add("zhanling/a7",10);
                ob=new("/clone/money/gold");
                ob->set_amount(gain);
                ob->move(me);
	message("channel:chat", HIM + ZJSIZE(25)"【寻宝精灵】"+me->query("name")+"通过寻宝得到了"+chinese_number(gain)+"两黄金！。\n"NOR,users());
                tell_object(me,sprintf(HIY"你得到了%s两黄金，10战令修为！\n"NOR,
                        chinese_number(gain)));
                break;
        case 3:
                gain=2+random(5);
				me->add("yuanbao",gain);
						me->add("zhanling/a7",10);
						me->add("xunbaocshu1",1);

	message("channel:chat", HIM + ZJSIZE(25)"【寻宝精灵】"+me->query("name")+"通过寻宝得到了"+chinese_number(gain)+"个灵石！。\n"NOR,users());
                tell_object(me,sprintf(HIY"你获得了%s个灵石，10战令修为！\n"NOR,
                        chinese_number(gain)));
                break;
        default:
                gain=1;
                me->add("tianji1",gain);
						me->add("zhanling/a7",10);
						me->add("xunbaocshu1",1);

	message("channel:chat", HIM + ZJSIZE(25)"【寻宝精灵】"+me->query("name")+"通过寻宝找到了仙人遗迹，天机点增加了"+chinese_number(gain)+"个！。\n"NOR,users());
                tell_object(me,sprintf(HIY"你的天机点增加了%s个，10战令修为！\n"NOR,
                        chinese_number(gain)));
                break;
        }

    call_out ("night_appearing",1);
        return ;
}

int help(object me)
{
  write(@HELP

找寻宝物

    系统每隔一定的时间会显示出一行不全的描述，这表示宝物就出
现在有着这段描述的地方（当然有时候有几个地方的描述是一样的，
这样就得碰运气了）。找到这个地方，然后就xunbao……寻宝所要的
时间跟福缘有关，基本上是福缘越高，就越快找到。得到的奖励是随
机的，也是福缘越高得到的越多。
    寻宝次数过多（大于10），就需要到扬州武庙捐些出来了，否则
就找不到宝物了。想要钱的可以去领（ling）。

            by fid
HELP
    );
    return 1;
}

