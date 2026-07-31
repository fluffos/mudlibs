#include <ansi.h>
inherit NPC;

int check_name(string str,object me);
int create_banghui(string str);

void create()
{
        set_name("天师",({"tian shi","tian","shi"}));
        set("long","世纪狂人之一，负责武林帮会(banghui)的建立外。\n");
        set("title",RED"帮会总管"NOR);
        set("gender","男性");
        set("age",30);
        set("per",90);

        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("parry",200);
        set_temp("apply/attack",100);
        set_temp("apply/defense",100);
        set_temp("apply/damage",50);

        set("inquiry", ([
                  "banghui"       :"要创建帮会请chengli <帮会名>\n",
                  "帮会"       :"要创建帮会请chengli <帮会名>\n",
        ]) );


        set("combat_exp",2000000);
        setup();
}
int check_name(string name,object me)
{
    int i;

    i = strlen(name);
    if( i > 50 ) return 0;  //名称不得大于50个字符就是25个汉字
      else return 1;
}


void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
                {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
                }
          add_action("create_banghui","chengli");
}

int create_banghui(string str)
{
        object me,lingpai;
        int count;
        string arg;

        me=this_player();
        if((string)me->query("banghui"))        {
                tell_object(me,"你已经是"+me->query("banghui")+"的人了，不能另创帮会。\n");
                return 1;
        }
        if(me->query("zjb_dj/dj")<60)    {
                tell_object(me,"成立帮派需要60级，您的级别好象还不够!\n");
                return 1;
        }
        if(me->query("zjb_money")<10000) {
                        tell_object(me,"成立帮派需要一万枚星空币，您好象没有那么多!\n");
                        return 1;
        }                        
        if(! count=me->query("lonely/have_create"))     count=0;
        if(count>=2)    {
                tell_object(me,"天师怒道：你以为帮会是创着玩吗？想再建帮会，下辈子吧！！\n",);
                return 1;
        }
        
        if(! str)       {
                tell_object(me,"你要创建什么名字的帮会？\n");
                return 1;
        }
        if(! check_name(str,me))        return 1;

        if(file_size("/data/guild/"+str+".o")!=-1) {
                tell_object(me,"非常抱歉，你起的帮会名早就有了。\n");
                return 1;
        }
            arg = str;
            str = trans_color(str, 2);
        
        lingpai=new("/clone/misc/lingpai");
        lingpai->create(arg);
        lingpai->set("bangzhu_id",me->query("id"));
        lingpai->set("player",([me->query("id"):me->query("name")]));
        lingpai->set("weiwang",500);
        lingpai->set("npc",([]));
        lingpai->set("area",([]));
        lingpai->set("money",0);
        lingpai->save();
        destruct(lingpai);

        me->add("zjb_money",-10000);
        me->set("banghui",arg);
        me->set("tybang/banghui",str);
        me->set("tybang/bh_rank",HIR"帮主"NOR);
        count++;
        me->set("tybang/have_create",count);
        me->save();
        command("chat 恭喜"+me->query("name")+"的帮会「"+str+NOR"」创建成功！\n");
        return 1;
}

void greeting(object ob)
{
        string banghui;
        object lingpai;
        if( !ob || environment(ob) != environment() ) return;
        if((string)(banghui=ob->query("banghui")))      {
                lingpai=new("/clone/misc/lingpai");
                lingpai->create(banghui);
                if(lingpai->query("no_use"))    {
                        tell_object(ob,"天师道："+ob->query("name")+"，你的帮会文件有问题，快与巫师联系吧。\n");
                }
                else if(lingpai->query("bangzhu_id")!="???")    {
                        if( lingpai->query("bangzhu_id")==ob->query("id") )
                        tell_object(ob,"天师一抱拳道：这位"+ob->query("banghui")+
                        ob->query("bh_rank")+"，贵帮生意如何？\n");
                        else    tell_object(ob,"天师道："+ob->query("name")+
                        "，贵帮帮主身体可好？\n");
                }
                else tell_object(ob,"天师偷偷在你耳边道：贵帮主失踪多日，"+
                        RANK_D->query_respect(ob)+"只需花一千两黄金就可以买下帮主之位。\n");
                destruct(lingpai);
        }
        else    tell_object(ob,"天师对你一抱拳道：这位"+RANK_D->query_respect(ob)+"是来创建帮会的吗？\n");
}
