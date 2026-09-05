#include <ansi.h>
inherit NPC;
string ask_for_xiangyang();
string ask_for_zhutou();
void create()
{
        set_name(RED"蒙哥"NOR, ({ "meng ge","ge","meng" }) );
        set("gender", "男性" );     
        set("title",YEL"蒙古皇帝"NOR);
        set("age", 48);
        set("long", 
            "这就是当今最强大的蒙古国的皇帝蒙哥.\n");
        set("inquiry",([ 
                "攻打襄阳"  : (: ask_for_xiangyang :),
                "襄阳"  : (: ask_for_xiangyang :),
				"你是猪头": (: ask_for_zhutou :)
        ]));
        set("str", 30);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
        set("shen_type", 1);

        set_skill("unarmed", 130);
        set_skill("dodge", 130);      
        set_skill("parry", 130);
        set_skill("sword", 120);    
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set("combat_exp", 120000);
        set("attitude", "aggressive");
        setup();                                 
        carry_object(__DIR__"obj/bingfu");
        carry_object(__DIR__"obj/junfu")->wear();
        carry_object(__DIR__"obj/changjian")->wield();
}





void init()
{
int i;
mapping armor;
string *pname;
object me=this_player();
armor=me->query_temp("armor");
if(armor)
{
pname=keys(armor);
for(i=0;i<sizeof(armor);i++)
{
if ((armor[pname[i]])->query("id")=="menggu cloth"&&me->query_temp("citan"))
{
command("hi "+me->query("id"));
return ;
}
}
}
if(wizardp(me))
{
/*
        command("club pigmgjx");
        command("woman pigfd");
        command("taste tianying");
        command("zt3 niro");
        command("sing3 film");
        command("mmx qianr");
        command("trip dcl");
        command("praise mgjx");
        command("kickout ingot");
        command("sword pighs");
        command("slap4 iszt");
        command("chat* zhutou advent");
        command("chat* cook advent");
        command("chat* smell advent");
        command("rumor* unme1 advent");
*/
}
else
        command("say 嗯？你是哪里来的？大胆，竟敢私闯蒙古大帐？");
//kill_ob(me);
return;
}
string ask_for_xiangyang()
{
mapping armor;
string *pname,msg;
int number;
int i;
object xytaskd;
int time;
object me=this_player();
armor=me->query_temp("armor");
pname=keys(armor);
xytaskd=load_object("/adm/daemons/xytaskd");
if(xytaskd->query("begin")) return "ft,现在不是正在打么？";
for(i=0;i<sizeof(armor);i++)
{
if ((armor[pname[i]])->query("id")=="menggu cloth"&&me->query_temp("citan"))
{
time=14400-time()+xytaskd->query("begin_time");
if (time<=0) return "攻打襄阳，马上开始！";
time=time*365;
number= time%60;
msg=chinese_number(number)+"秒";
time=time/60;
if(time>0)
{
number=time%60;
msg=chinese_number(number)+"分"+msg;
}
time=time/60;
if(time>0)
{
number=time%24;
msg=chinese_number(number)+"小时"+msg;
}
time=time/24;
if(time>0)
{
number=time%30;
msg=chinese_number(number)+"天"+msg;
}
time=time/30;
if(time>0) msg=chinese_number(time)+"月"+msg;
msg="蒙哥说道：距离攻打襄阳还有"+msg+"\n蒙哥大笑：到时候一定把襄阳夷为平地！";
message_vision(HIY+msg+"\n"+NOR,me);
return "呵呵";
}
}
return "我凭什么要告诉你?";
}

string ask_for_zhutou()
{
mapping armor;
string *pname,msg;
int number;
int i;
object xytaskd;
int time;
object me=this_player();
armor=me->query_temp("armor");
pname=keys(armor);
xytaskd=load_object("/adm/daemons/xytaskd");
if(xytaskd->query("begin")) return "ft,现在不是正在打么？";
if(!visible(me)&&SECURITY_D->get_status(me)!= "(player)")
  return "猪头巫师，你隐身了我怎么告诉你？";

if(!visible(me))
{
	command("yi");
    return "谁在问我？";
}
for(i=0;i<sizeof(armor);i++)
{
if (((armor[pname[i]])->query("id")=="menggu cloth"&&me->query_temp("citan"))||SECURITY_D->get_status(me)=="(admin)")
{
time=14400-time()+xytaskd->query("begin_time");number= time%60;
if (time<=0) return "攻打襄阳，马上开始！";
msg=chinese_number(number)+"秒";
time=time/60;
if(time>0)
{
number=time%60;
msg=chinese_number(number)+"分"+msg;
}
time=time/60;
if(time>0)
{
number=time%24;
msg=chinese_number(number)+"小时"+msg;
}
msg=" 距离攻打襄阳还有"+msg;
set("name",RED"蒙哥"HIG);
command("tell "+me->query("id")+msg);
set("name",RED"蒙哥"NOR);
return "嘿嘿，这可是你们的实际时间哟？";
}
}
return "我凭什么要告诉你?";
}
