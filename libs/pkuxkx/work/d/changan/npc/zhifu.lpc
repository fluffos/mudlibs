//zine分管房子放出,关掉房产功能
#include <ansi.h>
inherit NPC;
int ask_real();
int ask_buy();
int buy_real(string arg);
int entry_code(string arg,object me,object real,mapping *ent,int index);
void create()
{
	set_name("孟温礼", ({ "jingzhao yin", "yin" }));
	set("title",HIY"京兆尹"NOR);
  set("gender", "男性");
	set("age", 50);
	set("long", "他是一个京兆府的长官，分管地产买卖。\n");
	
	set("combat_exp", 100000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

        set("inquiry", ([  
                "name" : "我就是大名鼎鼎的京兆尹啊！",
                /*"地契" : (: ask_real :),
                "地契列表" : (: ask_real :),
                "地契买卖" : (: ask_buy :),
                "buy" : (: ask_buy :),*/
        ]) );

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
    /*add_action("do_list","list");
    add_action("do_edit_price","edit_price");
    add_action("do_edit_owner","edit_owner");
    add_action("do_clear","clear_all");
    add_action("buy_real","buy");*/
}
int do_clear()
{
    object me=this_player();
    object real=load_object("/d/parties/public/obj/real");
    if (me->query("id")!="zine")
    {
        return 0;
    }
    real->save();
    write("所有状态清零！\n");
    return 1;
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
        tell_object(me,"BOSS,格式是edit_price <编号> <price> <新值>\n");
        return 1;
    }
    if (sscanf(arg, "%d %s %d", index,type,price)!=3)
    {
        tell_object(me,"BOSS,格式是edit_price <编号> <price> <新值>\n");
        return 1;
    }
    if (type!="price")
    {
        tell_object(me,"BOSS,格式是edit_price <编号> <price> <新值>\n");
        return 1;
    }
    entry=real->real_estate();
    entry[index]["price"]=price;
    real->save_entry(entry);
    real->save();
    tell_object(me,"修改成功！\n");
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
        tell_object(me,"BOSS,格式是edit_owner <编号> <owner> <新值>\n");
        return 1;
    }
    if (sscanf(arg, "%d %s %s", index,type,owner)!=3)
    {
        tell_object(me,"BOSS,格式是edit_owner <编号> <owner> <新值>\n");
        return 1;
    }
    if (type!="owner")
    {
        tell_object(me,"BOSS,格式是edit_owner <编号> <owner> <新值>\n");
        return 1;
    }
    entry=real->real_estate();
    entry[index][type]=owner;
    real->save_entry(entry);
    real->save();
    tell_object(me,"修改成功！\n");
    return 1;
}

int do_list()
{
    object me=this_player();
    object real=load_object("/d/parties/public/obj/real");
    mapping *entry;
    int i;
    string real_info=HIW+"房产信息。\n"+NOR;
    if (me->query("id")!="zine")
    {
        return 0;
    }
    entry=real->real_estate();
    for (i=0;i<sizeof(entry);i++)
    {
        real_info+=HIY+"编号【"+i+"】\t简介："+entry[i]["desc"]+"\t"+"售价："+entry[i]["price"]+"金\t主人："+entry[i]["owner"]+"\t\t"+"口令："+entry[i]["entry_code"]+"。\n"+NOR;
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
            real_info+=HIY+"编号【"+i+"】\t简介："+entry[i]["desc"]+"\t"+"售价："+entry[i]["price"]+"金\t主人："+entry[i]["owner"]+"。\n"+NOR;
        }
        if (entry[i]["owner"]==me->query("id"))
        {
            command("say 一人最多只许有一处房产，不得有例外。");
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
	string save_file="/data/business/real_estate_no/";
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
    if (index<0||index>=sizeof(entry))
    {
        command("say 请输入一个存在的编号，如果不知道有哪些地产在售，你可以问我关于“地契”的信息。");
        return 1;
    }
    if (entry[index]["owner"]!="N/A")
    {
        command("say 此处地产是属于"+entry[index]["owner"]+"名下的，你去和他商量吧。");
        return 1;
    }
	if (SECURITY_D->get_status(me->query("id")) != "(guider)")
    {
        command("say 这里的宅子需要新手导师才有资格购买！");
        return 1;
    }
    
    price=(int)entry[index]["price"]*10000;
    if (me->query("balance")<price/2*3)
    {
        command("say 你的存款也不多了，购买地契至少需要存款数是卖价的1.5倍，方可交易。");
        return 1;
    }
	save_file+=entry[index]["save_file"];
	rm(save_file);
    message_vision(HIG+"$N把银号里的存款转给长安府，买下了"+entry[index]["desc"]+"的一处地产。\n"+NOR,me);
    me->add("balance",-price);
    tell_object(me,"请你输入进入这处宅子的口令，必须是一句话，比如输入 <你是大猪头>。\n");
    tell_object(me,HIC+"口令："+NOR);
    input_to( (: entry_code :), me,real,entry,index);
    return 1;
}

int entry_code(string arg,object me,object real,mapping *ent,int index)
{
    object rm;
    if (!arg)
    {
        if (me->query_temp("set_self_building_code")>3)
        {
            write("不老老实实设定口令的恶果就是————你的宅子被"+this_object()->query("name")+"没收了！\n");
            return 1;
        }
        tell_object(me,"你必须设定一个进入这处宅子的口令，否则今后无法进入！\n");
        me->add_temp("set_self_building_code",1);
        tell_object(me,HIC+"口令："+NOR);
        input_to( (: entry_code :), me,real,ent,index);
        return 1;
    }
    if (strwidth(arg)>30)
    {
        if (me->query_temp("set_self_building_code")>3)
        {
            write("不老老实实设定口令的恶果就是————你的宅子被"+this_object()->query("name")+"没收了！\n");
            return 1;
        }
        tell_object(me,"你设定进入这处宅子的口令不能过长！\n");
        me->add_temp("set_self_building_code",1);
        tell_object(me,HIC+"口令："+NOR);
        input_to( (: entry_code :), me,real,ent,index);
        return 1;
    }
    ent[index]["owner"]=me->query("id");
    ent[index]["owner_name"]=me->query("name");
    ent[index]["entry_code"]=arg;
    real->save_entry(ent);
    if (rm=load_object(ent[index]["entry"]))
    {
        rm->get_lv();
    }
    write(HIG+"恭喜！你的宅子位于"+ent[index]["desc"]+"，进入那里的口令是"+ent[index]["entry_code"]+"，可别忘了，也要记得告诉你的徒弟们！\n"+NOR);
    real->save();
    return 1;
}