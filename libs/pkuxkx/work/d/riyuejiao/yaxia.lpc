//test
//yaxia.c	黑木崖下
//by bing

#include "/d/riyuejiao/bonus.h"
#include <ansi.h>
#include <room.h>
#define LINE   HIW"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short","黑木崖下");
	set("long",@LONG 
这里有一道大石门，石门两旁刻着两行大字，右首是「文成武德」
，左首是「仁义英明」，横额上刻着「日月光明」四个大红字。地下
放着一支大竹篓 (zhu lou)。石门上贴着一张告示(gaoshi)，分配着
日月神教入门弟子的工作。
LONG
	);
//	set("number",1);
	set("item_desc",([
  	"zhu lou" : "这是一个竹子编成的大篓，大概可以装得下一个人，上面连着一根粗绳子。\n",
  	"lou" : "这是一个竹子编成的大篓，大概可以装得下一个人，上面连着一根粗绳子。\n", 	   
    "gaoshi": (:look_gaoshi:)]));
	set("outdoors", "riyuejiao");
    set("bonus",35);
	set("objects",([
		__DIR__"npc/jiaozhong4"	: 4,
		]));
    set("waittime",4);
	set("exits", ([
		"south" : __DIR__"cunlu3",
	]));
	setup();

}

string look_gaoshi()
{
    object me=this_player();
    object killer,where;
    string *name,*id,*title,*desc,msg;
    int i;
    
    if (me->query("family/family_name") != "日月神教")
    {
        return "居然是一张空白告示，真奇怪。\n";
    }
    if (me->query("combat_exp")<65000)
    {
        return "神教的告示上并没有你的名字，看来教主并没有新的指示。\n";
    }
    if (me->query("combat_exp")>80000)
    {
        return "神教的告示上并没有你的名字，看来教主并没有新的指示。\n";
    }
    if (time()-me->query("rynewbiejob/lasttime")<120+random(30))
    {
        return "神教的告示上并没有你的名字，看来教主并没有新的指示。\n";
    }
    name=({"日月教众","上官云","王铁匠","男孩","女孩","小孩",});
    id=({"riyue jiaozhong","shangguan yun","wang tiejiang","boy","girl","kid",});
    title=({"日月神教第二十二代弟子",HIG+"日月神教"+HIR+"白虎堂"+HIY+"长老"+NOR,"打铁铺","","",""});
    desc=({"他是日月神教教下弟子，入教已有四，五年，功夫也还可以。\n",
        "他乃是日月神教白虎堂长老。\n",
        "王铁匠是外地人，刚刚在此开了个打铁铺，买卖倒也红火。\n",
        "这是个农家少年，大概因从小物农，虽然年纪不大，可已长的很粗壮了。\n",
        "这是个农家少女，虽然只有十二、三岁，身材已经开始发育。\n",
        "这是个农家小孩子\n",});
    i=random(sizeof(name));
    killer=new(__DIR__"npc/killer");
    killer->do_copy(me);
    killer->set("name",name[i]);
    killer->set("id",id[i]);
    killer->set("title",title[i]);
    killer->set("long",desc[i]);
    while (!objectp(where) || 
          !where->isroom()||
          TASK_D->place_belong(where)=="不明区域"||
          base_name(where) == "/adm/daemons/taskd"||
          where->query("no_rynewbiejob"))
        {where=TASK_D->random_room("/d/riyuejiao/");}
    killer->move(where);
    me->set_temp("rynewbiejob/killer/where",where->query("short"));
    me->set("rynewbiejob/lasttime",time());
    msg=HIM+"\t\t☆神教弟子入门工作☆\n"+NOR;
    msg+=LINE;
    msg+="\t\t\t"+killer->query("realname")+"\t\t杀无赦\n";
    msg+=LINE;
    return msg;
}

void init()
{
	add_action("do_enter","enter");
    add_action("do_bian","bian");
}

int finish2(object me)
{
    if (me&&living(me)&&base_name(environment(me))=="/d/riyuejiao/yaxia")
    {
        message_vision("$N把竹篓给装好了。\n",me);
        me->delete("rynewbiejob/zhulou/start");
        bonus(me);
        this_object()->delete("cantenter");
        if (random(100)>49)
        {
            message_vision("竹篓变得生涩，上崖速度变慢了，$N苦笑一声。\n",me);
            this_object()->set("waittime",5+random(2));
        }
        else
        {
            message_vision("竹篓变得更加轻便，上崖速度变快了，$N得意的大笑起来。\n",me);
            this_object()->set("waittime",4-random(2));
        }
        return 1;
    }
    this_object()->delete("cantenter");
    return 1;
}

int finish(object me)
{
    if (base_name(environment(me))!="/d/riyuejiao/yaxia")
    {
        return 0;
    }
    if (random(100)>85)
    {
        message_vision("$N笨手把竹篓编得彻底损坏，必须丢弃了。\n",me);
        return 1;
    }
    message_vision("$N开始把新的竹篓给绑在粗绳子上，换下旧的竹篓。\n",me);
    this_object()->set("changer",me->query("name"));
    this_object()->set("cantenter",1);
    call_out("finish2",2,me);
    return 1;
}

int do_bian(string arg)
{
    object me=this_player();
    object *all;
    int i,count,descount;
    object zt;
    count=0;
    descount=0;
    if (!me->query("rynewbiejob/zhulou/start"))
        {
            return 0;
        }
    if (me->is_busy()||me->fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你要编什么东西？\n");
        return 1;
    }
    if (arg!="竹篓"&&arg!="zhulou"&&arg!="zhu lou")
    {
        tell_object(me,"你要编什么东西？\n");
        return 1;
    }
    all=all_inventory(me);
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("is_zhutiao"))
        {
            count=count+1;
        }
    }
    if (count<6)
    {
        tell_object(me,"你身上的竹条不够编一个竹篓。\n");
        return 1;
    }
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("is_zhutiao")&&descount<6)
        {
            destruct(all[i]);
            descount=descount+1;
        }
        
    }
    message_vision("$N开始努力编竹篓。\n",me);
    me->add_busy(2);
    call_out("finish",2,me);
    return 1;
}

int do_enter(string arg)
{
	object me = this_player();
    int cd=this_object()->query("waittime");
	int encum;
	object room;
    if (this_object()->query("cantenter"))
    {
        tell_object(me,this_object()->query("changer")+"正在换新的竹篓，马上就好了。\n");
        return 1;
    }
	if(!( room = find_object(__DIR__"lounei")) )
        room = load_object(__DIR__"lounei");

	
	if (!arg || (arg != "zhu lou" && arg != "lou"))
		return notify_fail("你要进哪里？\n");
//	if (query("number") == 0)
//		return notify_fail("竹篓里已经有人了，盛不下你。\n");
    encum = me->query_encumbrance();
	if ( encum > 100000 )  // 从按比例计算改成按实际重量计算。50000相当于5把玄铁剑的重量。by lordstar 2017/8/23
	{
		message_vision("日月神教教众对$N怒喝道：「背那么多东西上崖，也不怕竹篓绳索断裂把你摔成肉饼？」\n",me);
		message_vision("一位教众上前掂量了一下，说道：「竹篓负重有限，你的东西超重了大约 "+(encum-100000)*100/100000+"％，还是少带点吧。」\n",me);
		return notify_fail("你身上背的东西太多了，清理一些再试吧。\n");
	}

	if (((int)room->query_temp("无人"))==1)
                return notify_fail("竹篓里已经有人了，盛不下你。\n");
        if (me->query("family/family_name") != "日月神教" 
        	&& !me->query("special_skill/sociability")
                && !me->query_temp("allow_hmy"))
	{
		message_vision("日月神教教众对$N怒喝道：「什么人？敢擅闯黑木崖？」\n",me);
		message_vision("$N急忙跳进大竹篓内，拉了拉绳子。只见绳子一紧，竹篓「倏」的升了上去。\n",me);
		me->move(__DIR__"lounei");
//		set("number",0);
		room->set_temp("无人",1);
		call_out("lou2",1);
                call_out("goup",cd, me);
		return 1;
	}
	if (me->query_temp("allow_hmy"))
	message_vision("日月教众看了$N一眼惊讶道：原来是上官长老的人。\n",me);
	message_vision("$N走进竹篓内，拉了拉绳子，只见绳子一紧，竹篓「倏」的升了上去。\n",me);
	me->move(__DIR__"lounei");
//	set("number",0);
	room->set_temp("无人",1);
	call_out("lou2",1);
	call_out("goup",cd,me);
	return 1;
}

int me_in(object me)
{
    if (!me)
    {
        return 0;
    }
    if (!environment(me))
    {
        return 0;
    }
    if (!environment(me)->query("ry_lou_1"))
    {
        return 0;
    }
    return 1;
}

int goup(object me)
{
	object room;
    int cd=this_object()->query("waittime");
	if(!( room = find_object(__DIR__"lounei")) )
        room = load_object(__DIR__"lounei");
	add("number",1);
	
    if (query("number") < 4)
	{
        if (me_in(me))
        {
            message_vision("竹篓慢慢上升，片片白云从你身旁飘过。\n",me);
            call_out("goup",cd,me);
            return 1;
        }
		else
        {
            room->set_temp("无人",0);
            set("number",0);
            return 1;
        }
	}
    if (me_in(me))
    {
        message_vision("只觉得竹篓一震，原来已经到了崖顶。\n",me);
        if (me->query("family/family_name") != "日月神教" 
            && !me->query("special_skill/sociability")
            && !me->query_temp("allow_hmy"))
        {
            message_vision("守崖顶的日月神教弟子见到$N，「咦」了一声，接着大声喊道：「有奸细！有奸细！」\n",me);
            tell_room(__DIR__"yading","只听一阵轱辘响，一个竹篓慢慢吊上来，里面站着" + me->query("name") + "。\n");
            tell_room(__DIR__"yading","守崖顶的日月神教弟子见到" + me->query("name") + "，「咦」了一声，接着大声喊道：「有奸细！有奸细！」\n");
            message_vision(HIR "只见若干个人拔出腰刀，朝绳子上一阵乱砍！\n" NOR,me);
            tell_room(__DIR__"yading","若干个人拔出腰刀，朝绳子上一阵乱砍！\n");
            message_vision(HIR "$N只觉身体一轻，随着竹篓直直地坠了下去！\n" NOR,me);
            tell_room(__DIR__"yading",me->query("name") + "一声惨叫，随着竹篓直直的掉了下去，很快就不见踪影了。\n");
            tell_room(__DIR__"yaxia","忽然头上传来一声惨叫：「啊－－」。声音由远及近。\n",me);
            me->move(__DIR__"yaxia");
            message_vision("只听「砰」的一声，$N重重地摔在了地上。\n",me);
            me->unconcious();
        }
        else	
        {
            message_vision("$N定了定神，走了出来。\n",me);
            if (me->query_temp("allow_hmy"))
            message_vision("日月教众看了$N一眼道：哦，原来是上官长老的人。\n",me);
            tell_room(__DIR__"yading","只听一阵轱辘响，一个大竹篓慢慢的升了上来，" + me->query("name") + "从里面走了出来。\n",me);
            me->move(__DIR__"yading");
        }
    }
    room->set_temp("无人",0);
    set("number",0);
    return 1;
}


void lou2()
{
	tell_room(__DIR__"yaxia","过了不久，又一个竹篓由上面缓缓吊下。\n");
	set("number",1);
		
}

