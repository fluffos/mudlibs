//zine分管房子放出
#include <ansi.h>
inherit NPC;
int ask_real();
int ask_buy();
int buy_real(string arg);
void create()
{
	set_name("知府", ({ "zhi fu", "zhifu" }));
	set("title",HIY"长安府"NOR);
    set("gender", "男性");
	set("age", 50);
	set("long", "他是一个长安府的知府，分管地产买卖。\n");
	
	set("combat_exp", 100000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

        set("inquiry", ([  
                "name" : "我就是大名鼎鼎的长安知府啊！",
                "地契" : (: ask_real :),
                "地契列表" : (: ask_real :),
                "地契买卖" : (: ask_buy :),
                "buy" : (: ask_buy :),
        ]) );

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
    add_action("do_list","list");
    add_action("do_edit_price","edit_price");
    add_action("do_edit_owner","edit_owner");
    add_action("buy_real","buy");
}

int do_edit_price(string arg)
{
    object me=this_player();
    object real=load_object("/d/parties/public/obj/real");
    mapping *entry;
    int index,price;
    string type;
    if (me->query("id")!="zine")
    {
        return 0;
    }
    if (!arg)
    {
        tell_object(me,"BOSS,格式是edit <编号> <price> <新值>\n");
        return 1;
    }
    if (sscanf(arg, "%d %s %d", index,type,price)!=3)
    {
        tell_object(me,"BOSS,格式是edit <编号> <price> <新值>\n");
        return 1;
    }
    if (type!="price")
    {
        tell_object(me,"BOSS,格式是edit <编号> <price> <新值>\n");
        return 1;
    }
    entry=real->real_estate();
    entry[index]["price"]=price;
    real->save_entry(entry);
    real->save();
    tell_object(me,"修改成功！");
    return 1;
}

int do_edit_owner(string arg)
{
    object me=this_player();
    object real=load_object("/d/parties/public/obj/real");
    mapping *entry;
    int index;
    string type,owner;
    if (me->query("id")!="zine")
    {
        return 0;
    }
    if (!arg)
    {
        tell_object(me,"BOSS,格式是edit <编号> <owner> <新值>\n");
        return 1;
    }
    if (sscanf(arg, "%d %s %s", index,type,owner)!=3)
    {
        tell_object(me,"BOSS,格式是edit <编号> <owner> <新值>\n");
        return 1;
    }
    if (type!="owner")
    {
        tell_object(me,"BOSS,格式是edit <编号> <owner> <新值>\n");
        return 1;
    }
    entry=real->real_estate();
    entry[index][type]=owner;
    real->save_entry(entry);
    real->save();
    tell_object(me,"修改成功！");
    return 1;
}

int do_list()
{
    object me=this_player();
    object real=load_object("/d/parties/public/obj/real");
    mapping *entry;
    int i;
    string real_info=HIW+"地产信息。\n"+NOR;
    if (me->query("id")!="zine")
    {
        return 0;
    }
    entry=real->real_estate();
    for (i=0;i<sizeof(entry);i++)
    {
        real_info+=HIY+"编号【"+i+"】\t简介："+entry[i]["desc"]+"\t"+"售价："+entry[i]["price"]+"金\t"+"限盖"+chinese_number(entry[i]["room_limit"])+"间房\t主人："+entry[i]["owner"]+"存储地址："+entry[i]["user_dir"]+"\n"+NOR;
    }
    me->start_more(real_info);
    return 1;
}

int ask_real()
{
    object me=this_player();
    object real=load_object("/d/parties/public/obj/real");
    mapping *entry;
    int i;
    string real_info=HIW+"现在可以购买的地产有以下，如果有主人，你也可以与之洽谈转让。\n"+NOR;
    real->restore();
    entry=real->real_estate();
    

    for (i=0;i<sizeof(entry);i++)
    {
        if (entry[i]["owner"]!=me->query("id"))
        {
            real_info+=HIY+"编号【"+i+"】\t简介："+entry[i]["desc"]+"\t"+"售价："+entry[i]["price"]+"金\t"+"限盖"+chinese_number(entry[i]["room_limit"])+"间房\t主人："+entry[i]["owner"]+"\n"+NOR;
        }
        if (entry[i]["owner"]==me->query("id"))
        {
            command("say 一人只许有一处房产，不得有例外。");
            return 1;
        }
        real_info=YEL+replace_string(real_info,"主人：N/A","暂无主人")+NOR;
    }
    me->start_more(real_info);
    return 1;
}

int ask_buy()
{
    if (this_object()->is_busy())
    {
        tell_object(this_player(),this_object()->name()+"正忙着呢。\n");
        return 1;
    }
    this_object()->add_busy(3);
    command("say 『ask zhifu about 地契』可以查看地契编号");
    command("say buy <地契编号>可以购买。");
    return 1;
}

int buy_real(string arg)
{
    object me=this_player();
    object real=load_object("/d/parties/public/obj/real");
    mapping *entry;
    int i,index,price;
    real->restore();
    entry=real->real_estate();
    for (i=0;i<sizeof(entry);i++)
    {
        if (entry[i]["owner"]==me->query("id"))
        {
            command("say 一人只许有一处房产，不得有例外。");
            return 1;
        }
    }
    if (!arg)
    {
        command("say 你要买编号是多少的地产？");
        return 1;
    }
    if (sscanf(arg, "%d", index)!=1)
    {
        command("say 编号必须是阿拉伯数字！");
        return 1;
    }
    if (index<0||index>sizeof(entry))
    {
        command("say 请输入一个存在的编号，如果不知道有哪些地产在售，你可以问我关于“地契”的信息。");
        return 1;
    }
    if (!wizardp(me))
    {
        return 1;
    }
    price=(int)entry[index]["price"]*10000;
    if (me->query("balance")<price/2*3)
    {
        command("say 你的存款也不多了，购买地契至少需要存款数是卖价的1.5倍，方可交易。");
        return 1;
    }
    message_vision(HIG+"$N把银号里的存款转给长安府，买下了"+entry[index]["desc"]+"的一处地产。\n"+NOR,me);
    me->add("balance",-price);
    entry[index]["owner"]=me->query("id");
    entry[index]["user_dir"]="/d/parties/"+me->query("id")+"/";
    mkdir(entry[index]["user_dir"]);
    real->save_entry(entry);
    real->save();
    return 1;
}