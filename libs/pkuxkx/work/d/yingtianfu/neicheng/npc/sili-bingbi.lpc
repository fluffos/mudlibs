//秉笔太监

#include <ansi.h>
inherit NPC;
#include <title.h>

int ask_convert();
int ask_fuchen();
int ask_change_title();
void create()
{
    set_name("秉笔太监", ({"bingbi taijian", "taijian","jian"}));
    set("title", HIW"大明 "HIM"司礼监"NOR);
    set("gender", "无性");
    set("age", 50);
    set("long", "他就是当今内廷司礼监的秉笔太监。\n");
    set("attitude","heroism");
    set("generation",0);

    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);

    
	set("inquiry", ([
	
     "兑换" : (: ask_convert :),
	 "convert" : (: ask_convert :),
     "拂尘" : (: ask_fuchen :),
	 "fuchen" : (: ask_fuchen :),
     "调动": (: ask_change_title :),
     "diaodong": (: ask_change_title :),
     
	]));

    setup();
   
}

int ask_change_title()
{
    object me=this_player();
    string* title1a=({"内宫监 管理","御用监 掌司","司设监 管理","御马监 提督","神宫监 掌司","尚膳监 总理","尚宝监 掌司","尚绶监 掌司",
        "直殿监 掌司","尚衣监 佥书","都知监 司房","惜薪司 总理","钟鼓司 佥书","宝钞司 佥书","混堂司 佥书","兵仗局 提督","银作局 管理",
        "浣衣局 佥书","巾帽局 管理","内织造局 管理","针工局 管理","酒醋面局 管理","司苑局 管理"});//6品
    string* title2a=({"司礼监 秉笔","内宫监 总理","御用监 把总","司设监 总理","御马监 监督","神宫监 佥书",
        "尚膳监 提督","尚宝监 佥书","尚绶监 佥书","直殿监 佥书","尚衣监 管理","都知监 佥书"});//5品副
	string* title2b=({"惜薪司","钟鼓司","宝钞司","混堂司","兵仗局","银作局","浣衣局","巾帽局","内织造局","针工局","酒醋面局","司苑局"});//5品正官
    string *title3=({"司苑局 佥书","酒醋面局 佥书","针工局 佥书","内织造局 佥书","巾帽局 佥书","浣衣局 监工",
            "银作局 佥书","兵仗局 管理","混堂司 监工","宝钞司 管理","钟鼓司 司房","惜薪司 佥书"});
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string title,pretitle;
	string color1=color[random(sizeof(color))];
	string color2=color[random(sizeof(color))];
    int n;
    if (!me->query("ming/tj/pin"))
    {
        tell_object(me,"你不是大明内廷官员，来欺骗杂家吗？\n");
        return 1;
    }
    if (me->query("ming/tj/pin")<5)
    {
        tell_object(me,"五品以上内廷官员，需要宫里直接任命的。\n");
        return 1;
    }
    if (me->query("ming/tj/pin")>7)
    {
        tell_object(me,"杂役太监再怎么调动也是杂役太监。\n");
        return 1;
    }
    if (me->query("gender")!="无性")
    {
        tell_object(me,"……\n");
        return 1;
    }
    if (time()-me->query("ming/change_position")<60*60*3)
    {
        tell_object(me,"频繁调动可不好啊……\n");
        return 1;
    }
    if (!me->query_temp("调动"))
    {
        tell_object(me,"调动工作可能要扣掉一定的大明功勋度，假如你真的愿意就<ask bingbi taijian about 调动>吧。\n");
        me->set_temp("调动",1);
        return 1;
    }
    if (me->query("ming/tj/pin")==7)
    {
        title=title3[random(sizeof(title3))];

        me->set("ming/title",title+"太监");
		me->set("title",HIW+"大明 "+CYN+"内廷七品太监 "+color2+title+"太监"+NOR);
		
			  //title系统记录玩家title by seagate@pkuxkx
			  me->set_title(({TITLE_QUEST1, TITLE_QUEST2, TITLE_QUEST3}), HIW+"大明 "+CYN+"内廷七品太监 "+color2+title+"太监"+NOR, "大明");

				tell_object(me,color1+"你任职以来，勤勤恳恳，就在别的职位上在试试吧，你且去做"+title+"太监吧。\n"NOR);

    }
    if (me->query("ming/tj/pin")==6)
    {
        title=title1a[random(sizeof(title1a))];

        me->set("ming/title",title+"太监");
		me->set("title",HIW+"大明 "+HIM+"内廷六品太监 "+color2+title+"太监"+NOR);
	
			  //title系统记录玩家title by seagate@pkuxkx
			  me->set_title(({TITLE_QUEST1, TITLE_QUEST2, TITLE_QUEST3}), HIW+"大明 "+HIM+"内廷六品太监 "+color2+title+"太监"+NOR, "大明");

				tell_object(me,color1+"你任职以来，勤勤恳恳，就在别的职位上在试试吧，你且去做"+title+"太监吧。\n"NOR);

					
    }
    
    if (me->query("ming/tj/pin")==5 && me->query("ming/tj/zhuguan"))
    {
        
        title=title2b[random(sizeof(title2b))];

        me->set("ming/title",title+"掌印太监");
		me->set("title",HIW+"大明 "+RED+"内廷五品太监 "+color2+title+"掌印太监"+NOR);
			    //title系统记录玩家title by seagate@pkuxkx

			  me->set_title(({TITLE_QUEST1, TITLE_QUEST2, TITLE_QUEST3}), HIW+"大明 "+RED+"内廷五品太监 "+color2+title+"掌印太监"+NOR, "大明");

        me->set("ming/tj/office",title+"掌印太监值房");

				tell_object(me,color1+"你任职以来，勤勤恳恳，就在别的职位上在试试吧，你且去做"+title+"掌印太监吧。\n"NOR);
    }
    if (me->query("ming/tj/pin")==5 && !me->query("ming/tj/zhuguan"))
    {
        
        title=title2a[random(sizeof(title2a))];

        me->set("ming/title",title+"太监");
		me->set("title",HIW+"大明 "+MAG+"内廷五品太监 "+color2+title+"太监"+NOR);

			  //title系统记录玩家title by seagate@pkuxkx
			  me->set_title(({TITLE_QUEST1, TITLE_QUEST2, TITLE_QUEST3}), HIW+"大明 "+MAG+"内廷五品太监 "+color2+title+"太监"+NOR, "大明");

        me->set("ming/tj/office",title+"太监值房");

				tell_object(me,color1+"你任职以来，勤勤恳恳，就在别的职位上在试试吧，你且去做"+title+"太监吧。\n"NOR);
    }
    
    if (time()>1303171199)
    {
        n=random(10)+10;
        me->add("ming/credit",-n);
        tell_object(me,"因为要求调动工作，你被扣去了"+chinese_number(n)+"点大明功勋。\n");
    }
    me->set("ming/change_position",time());
    return 1;
}


int ask_fuchen()
{
    object me=this_player();
    object* inv;    
    object fuchen;
    int i;
    inv = deep_inventory(me);
    if (!me->query("ming/tj/pin"))
    {
        command("say 杂家不认识你呀？怎么能给你呢。\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    for(i=sizeof(inv)-1; i>=0; i--)
    {
        if((inv[i])->query("is_fuchen"))
        {
            command("say 你身上不是正有一把拂尘吗？\n");
            return 1;
        }
    }
    me->add_busy(1);
    fuchen=new("/d/yingtianfu/neicheng/obj/fuchen");
    fuchen->set("owner",me->query("id"));
    fuchen->move(me);
    message_vision("$N拿出一把拂尘，交给$n。\n",this_object(),me);
    return 1;
}


int ask_convert()
{
    object me=this_player();
    int zs,getnum;
    if (!me->query("ming/tj/pin"))
    {
        tell_object(me,"秉笔太监道：你不是我内廷中人也敢来欺骗杂家？\n");
        return 1;
    }
    if (me->query("ming/tj/pin")>6)
    {
        tell_object(me,"秉笔太监道：只有六品以上内廷官员可以兑换。\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
	{
		tell_object(me,"你正忙着哪！\n");
        return 1;
    }
    if (!me->query("zhusantimes"))
    {
        tell_object(me,"你好像没啥可以兑换的东西。\n");
        return 1;
    }
        getnum=(int)me->query("zhusantimes")*9/5+random(4);
        zs=(int)me->query("zhusantimes");
        me->set("zhusantimes",0);
        me->add("ming/credit",getnum);
        tell_object(me,HIC"你把之前帮助史可法转移难民的"+chinese_number(zs)+"点功绩转换成"+chinese_number(getnum)+"点大明功勋度。\n"NOR);
        return 1;
}