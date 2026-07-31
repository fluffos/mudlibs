#include <ansi.h>

inherit NPC;

string *msg_d = ({
  "傻B","我操","操你","和你妈睡","傻比","傻逼",
  "fuck","FUCK","Fuck","婊子","cao","CAO","Cao",
  "放你妈的屁","操你妈","日死你","干你娘",
   "操你姐","狗屁wiz","狗wiz","破wiz","死wiz","日死你",
  "干你妈","干你的","ｆｕｃｋ","ＦＵＣＫ","F u c k","f u c k","SB",
  "Sb","sb","shabi","SHABI","我日","牛比","放屁","吃屎","你大爷","操你妈",
});

void create()
{
        set_name("狱卒", ({"yu zu","yuzu"}));
        set("title", HIY"「巡查使」"NOR);
        set("gender", "男性" );
        set("age", 30);
        set("per", 25);

        set("long", HIR"一个神秘的狱卒，你碰上他准是你干了什么坏事。\n"NOR);
        set("combat_exp", 10000000);
        set("attitude", "peaceful");
        set("str", 50);
   
        set_skill("literate", 800);
        set("max_kee", 1000);
        set("max_sen", 1000);
        set("max_force", 1000);
        
        set("no_clean_up",1);
        setup();
//在下面添加要监视的频道
        if( !clonep() ) CHANNEL_D->register_relay_channel("rumor");
        if( !clonep() ) CHANNEL_D->register_relay_channel("chat");
        if( !clonep() ) CHANNEL_D->register_relay_channel("party");
       if( !clonep() ) CHANNEL_D->register_relay_channel("es");
       if( !clonep() ) CHANNEL_D->register_relay_channel("new");
      if( !clonep() ) CHANNEL_D->register_relay_channel("ty");
        
}

void relay_channel(object criminal, string channel, string msg)
{


        int i;
        string criname,result;
        int howlong;
      if( !userp(criminal)||criminal->is_fighting() ) return;

        for(i=0; i<sizeof(msg_d); i++)
        {
           if( strsrch(msg, msg_d[i]) >= 0&&!criminal->is_fighting())
                   {
                    
                    criname = criminal->query("name") + "("+criminal->query("id")+")";
                     howlong=30;//这里更改自动囚禁时间,60=60分钟
                    
                    result = sprintf("%s在%s频道说脏话(%s)被设囚禁 %d 分\n",
                    criname,channel,msg,howlong);
/*
                    
                    criminal->set("qiushi/howlong",howlong);
                    criminal->set("qiushi/temp",result);
                   criminal->move("/d/wizard/qiushi");
*/
            criminal->set("chblk_channel",time());
                 
                   message("channel:rumor",HIM"【谣言】某人：据说"+criname+HIM"在公众频道使用粗言烂语，被巡查使封闭使用公众频道三十分钟。\n"NOR, users());
                    return;
                    }
        }

}
