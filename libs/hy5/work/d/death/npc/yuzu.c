// yuzu.c
// cgm 28/12/1999
// idea 7/4/2000

#include <ansi.h>

inherit NPC;

string *msg_d = ({
                      "他妈的","你妈的","傻B","我操","操你","和你妈睡",
                      "操！","操!","fuck","FUCK","Fuck","婊子",
                      "你奶奶的","和你妈做爱","她妈的","你爷爷的",
                      "放你妈的屁","tmd","TMD","tmmd","TMMD","操你妈","日死你","干你娘",
                      "操你姐","狗屁wiz","狗wiz","破wiz","日死你",
                      "干你妈","干你的","ｆｕｃｋ","ＦＵＣＫ","F u c k"
                      ,"f u c k","他妈的","你妈的","傻B","我操","操你","和你妈睡",
                      "ta nai nai de","tanainaide","tanai naide","ta nainai de","tanainai de","nnd",
                      "操！","操!","fuck","FUCK","Fuck","婊子",
                      "t nn d","tnnnnd","tnn d","t nnd","t n n d","tn nd","t.m.d"
                      "你奶奶的","和你妈做爱","她妈的","你爷爷的","t.n.n.d","tnnd"
                      "小屁孩",
                      "放你妈的屁","tmd","TMD","tmmd","TMMD","操你妈","日死你","干你娘",
                      "操你姐","狗屁wiz","狗wiz","破wiz","日死你","tnnd","TNND","他奶奶的",
                      "干你","死wiz","妈的","吊你","干死你","插死你","强奸","做鸡",
                      "他妈的","妈地","日你",
                      });

string *msg_s = ({
                      "0","1","2","3","4","5",
                      "6","7","8","9"
                      });


void create()
{
        set_name("狱卒", ({"yu zu","yuzu"}));
        set("title", HIY"「四扇门高手」"NOR);
        set("gender", "男性" );
        set("age", 30);
        set("per", 5);
        set("long", HIR"一个神秘的狱卒，你碰上他准是你干了什么坏事。\n"NOR);
        set("combat_exp", 10000000);
        set("attitude", "peaceful");
        set("dex", 50);
        set("str", 50);
   
        set_skill("literate", 800);
        set("max_qi", 1000);
        set("max_jing", 500);
        set("max_neili", 1000);
  	
  	set("no_clean_up",1);
        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/obj/gangjian")->wield();

	if( !clonep() ) CHANNEL_D->register_relay_channel("rumor");
	if( !clonep() ) CHANNEL_D->register_relay_channel("chat");
	if( !clonep() ) CHANNEL_D->register_relay_channel("party");
        if( !clonep() ) CHANNEL_D->register_relay_channel("es");
        if( !clonep() ) CHANNEL_D->register_relay_channel("sing");
        if( !clonep() ) CHANNEL_D->register_relay_channel("hy");
        if( !clonep() ) CHANNEL_D->register_relay_channel("auction");
        if( !clonep() ) CHANNEL_D->register_relay_channel("yqyl");

}

void relay_channel(object criminal, string channel, string msg)
{

        int i;
        string criname,result,ia,ib,ic,id;
        int howlong;
        if( !userp(criminal) ) return;

        for(i=0; i<sizeof(msg_d); i++)
        {
            if( !wizardp(criminal) && strsrch(msg, msg_d[i]) >= 0)
                   {
                    message_vision(CYN"四扇门高手乎然出现，扔出索套，一下就套住$N的脖子。\n$N伸长舌头、翻着白眼地被拖走了。\n"NOR, criminal);
                    
                    criname = criminal->query("name") + "("+criminal->query("id")+")";
                    howlong=10;
                    
                    result = sprintf("%s在%s频道说脏话(%s)被设囚禁 %d 分\n",
                    criname,channel,msg,howlong);
                    criminal->start_busy(50);
                    criminal->set_temp("disable_inputs",1);
	            call_out("recoveralias", 120);
                    
                    message("channel:rumor",HIM"【谣言】某人：据说"+criname+"在公众频道使用粗言烂语，被禁止使用指令了。\n"NOR, users());
                    return;
                    }
        }
/*if (criminal->query("combat_exp") < 500 && strsrch(msg,"0")>=0 || strsrch(msg,"1")>=0 || strsrch(msg,"2")>=0 || strsrch(msg,"3")>=0
|| strsrch(msg,"4")>=0 || strsrch(msg,"5")>=0 || strsrch(msg,"6")>=0 || strsrch(msg,"7")>=0 
|| strsrch(msg,"8")>=0 || strsrch(msg,"9")>=0 )
{
        if( strlen(msg)>=10
         && !wizardp(criminal)
         && criminal->query("combat_exp") < 800 )
{
                    criminal->start_busy(50);
                    criminal->set_temp("disable_inputs",1);
	            call_out("recoveralias", 120);
message_vision(CYN"用公众频道做广告,太没道德了!，$N的指令被禁用了!。\n$N伸长舌头、翻着白眼地被拖走了。\n"NOR, criminal);
}
}
if (strsrch(msg,"0")>=0 || strsrch(msg,"1")>=0 || strsrch(msg,"2")>=0 || strsrch(msg,"3")>=0
|| strsrch(msg,"4")>=0 || strsrch(msg,"5")>=0 || strsrch(msg,"6")>=0 || strsrch(msg,"7")>=0 
|| strsrch(msg,"8")>=0 || strsrch(msg,"9")>=0 )
{
 	if( !wizardp(criminal) && sscanf( msg, "%s.%s.%s.%s",ia,ib,ic,id) && strlen(ia)>=1  && strlen(ib)>=1
 	 && strlen(ic)>=1 && strlen(id)>=1 && strlen(msg)>=10)
{
                    message_vision(CYN"用公众频道做广告,太没道德了!，$N的指令被禁用了!。\n$N伸长舌头、翻着白眼地被拖走了。\n"NOR, criminal);
                    criminal->start_busy(50);
                    criminal->set_temp("disable_inputs",1);
	            call_out("recoveralias", 120);
}

}
*/
}

void recoveralias()
{
        this_object()->set_temp("disable_inputs",0);
        this_player()->set_temp("disable_inputs",0);
     message("system", HIG "\n慢慢地系统恢复了你的指令....\n\n" NOR,
		this_object());
     message("system", HIG "\n慢慢地系统恢复了你的指令....\n\n" NOR,
		this_player());

}
