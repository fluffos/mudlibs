// 宗人令
#include <ansi.h>
inherit NPC;
#include <title.h>
#define LINE   HIY" ━━━━━━━━━━━━━━━━━━━━━━━━━━ \n"NOR
int ask_shang();
string ask_me();
void create()
{
	set_name("宗人令", ({ "zongren ling", "ling" }));
	set("title", HIY"宗人府"NOR);
	set("gender", "男性");
	set("age", 43);
	set("str", 20);
	set("dex", 20);
	set("long", "他是大清宗人府的宗人令，掌管宗室事务。\n");
	set("combat_exp", 500000);
	set("shen_type", 0);
	set("attitude", "heroism");

	set_skill("unarmed", 250);
	set_skill("force", 250);
	set_skill("sword", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 15);
	set("inquiry", ([
		"gaiming" : (: ask_me :),
		"改名换姓" : (: ask_me :),
		"改名" : (: ask_me :),
        "行赏" : (: ask_shang :),
        "xingshang" : (: ask_shang :),
	]) );
	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);

	set("shen_type",1);set("score",500);setup();
	
	carry_object("/d/beijing/npc/obj/guanfu")->wear();
}



void init()
{
    add_action("do_query","query");
	add_action("change_name", "gaiming");
    add_action("do_convert","duihuan");
}

int do_convert(string arg)
{
    object me=this_player();
    if (!me->query("chaoting/wang")&&!me->query("chaoting/jiawang"))
    {
        return 0;
    }
    if (me->query("chaoting/skf")<1)
    {
        tell_object(me,"你的大清特殊功勋不够兑换任何服务。\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你要兑换什么？\n");
        return 1;
    }
    if (arg=="宗室俸禄")
    {
        if (me->query("chaoting/skf")>=4)
        {
            if (me->query("chaoting/kingbonus")>239)
            {
                tell_object(me,"你的俸禄再高的话，大清要破产了，换点别的吧。\n");
                return 1;
            }
            tell_object(me,HIW"你用四点大清特殊功勋兑换了宗室俸禄！\n"NOR);
            me->add("chaoting/skf",-4);
            me->add("chaoting/kingbonus",10);
            return 1;
        }
        tell_object(me,"你的特殊功勋不够兑换！\n");
        return 1;
    }
    if (arg=="女真硬弓")
    {
        if (me->query("chaoting/skf")>=1)
        {
            tell_object(me,HIB"暂不可用！\n"NOR);
            //me->add("chaoting/skf",-1);
            //me->add("chaoting/kingbonus",10);
            return 1;
        }
        tell_object(me,"你的特殊功勋不够兑换！\n");
        return 1;
    }
    if (arg=="亲王宅邸")
    {
        if (me->query("chaoting/skf")>=200)
        {
            tell_object(me,HIR"尚未建好！\n"NOR);
            //me->add("chaoting/skf",-200);
            //me->add("chaoting/kingbonus",10);
            return 1;
        }
        tell_object(me,"你的特殊功勋不够兑换！\n");
        return 1;
    }
    else
    {
        tell_object(me,"没有此项服务！\n");
        return 1;
    }
}

int do_query()
{
    object me=this_player();
    string msg;
    if (!me->query("chaoting/wang")&&!me->query("chaoting/jiawang"))
    {
        return 0;
    }
    msg="\n\n";
    msg+=LINE;
    msg+=HIY"              大清皇族可兑换服务列表\n"NOR;
    msg+=LINE;
    msg+=HIW"    宗室俸禄   "+NOR+"  4点特殊功勋\n";
    msg+=HIB"    女真硬弓   "+NOR+"  1点特殊功勋\n";
    msg+=HIR"    亲王宅邸   "+NOR+"200点特殊功勋\n";
    msg+=LINE;
    msg+=HIY"      使用兑换(duihuan)命令，大清宗人府\n"NOR;
    msg+=LINE;
    tell_object(me,msg);
    return 1;
    
}

int ask_shang()
{
    object me=this_player();
    if (!me->query("chaoting/wang")&&!me->query("chaoting/jiawang"))
    {
        tell_object(me,"官员的事情不归宗人府管辖。\n");
        return 1;
    }
    tell_object(me,"你的特殊功勋是"+chinese_number(me->query("chaoting/skf"))+"点，你可以用query查询我这可以领的赏。\n");
    return 1;
}

int destroying(object ob)
{
	destruct(ob);
	return 1;
}
int accept_object(object who, object ob)
{
        if (!who->query("chaoting/wang") && !who->query("chaoting/jiawang"))
        {
            return notify_fail("你不是宗室子弟，我管不到你。\n");
        }
        if (!who->query("chaoting/jiajianged"))
        {
            return notify_fail("你不是宗室子弟，我管不到你。\n");
        }
        if(!who->query_temp("name_wait_modify_ct")) 
        {
            return notify_fail("啥意思？行赂？\n");	
        }
        if (ob->query("money_id") && ob->value() >= 20000000) 
        {
			message_vision("宗人令赶紧把钱财藏了起来，这种东西也可露白吗？我们都会被砍头的。\n",who);
			who->set_temp("name_modify_paid_ct",1);
            command ("say 这样吧，悄悄告诉我你要改什么名字就行了，爱新觉罗可不敢去，你就告诉我名字吧。\n");
            tell_object(who,"请使用gaiming <名>。\n");
			call_out("destroying",0,ob);
			return 1;
        }
	    else 
        {
        	return notify_fail("啥意思？行赂？\n");	
        }
}




protected int change_name(string arg)
{
        string new_name, name,color;
        int i;
        object me = this_player();

        if (!me->query("chaoting/wang") && !me->query("chaoting/jiawang"))
        {
            command("say 你不是宗室子弟，我管不到你。");
            return 1;
        }
        if (!me->query("chaoting/jiajianged"))
        {
            command("say 你不是宗室子弟，我管不到你。");
            return 1;
        }
        if (!me->query_temp("name_modify_paid_ct") && !wizardp(me)) {
            command("say 你这是让我难办啊，皇帝亲赐的姓名也敢改？");
            return 1;
        }

        if ( !arg ) {
                command("say 你到底要改什么名字啊？");
                return 1;
        }

        name = me->query("name");
        new_name = arg;
        
        i = strwidth(new_name);

        if (i < 2 || i > 4) {
                command("say “"+new_name+"”？");
                command("say 你的中文名字必须是 2 到 4 个中文字才行。");
                return 1;
        }

        while(i--)
                if( !is_chinese(new_name[i..<1]) ) {
                        command("say 你得用「中文」取名字，本官我可不认识西洋字。");
                        return 1;
                }

	    if ( !LOGIN_D->check_legal_name(new_name) ) {
                command("say 你这种名字会造成其他人的困扰，想个其它的。");
                return 1;
        }
		color=COLOR_D->get_color(name);
		name=COLOR_D->uncolor(name);
		new_name="爱新觉罗."+new_name;
		new_name = color+new_name+NOR;
        command("rumor 听说，"+name+"("+getuid(me)+") 贿赂了宗人令，偷偷改名为：" + new_name + "。");
        me->set("name", new_name);
        me->set_face( FACE_FACT, me->query("name") );
        me->add("name_modify", 1);
        log_file("name_modify",sprintf("%-18s 第 %d 次改名于 %s 改为：%s。\n",
                name+"("+getuid(me)+")", me->query("name_modify"), ctime(time()), new_name));
        me->delete_temp("name_modify_paid_ct");
        me->delete_temp("name_wait_modify_ct");
        start_busy(2);
        command("say 这事可不能张扬，不然要掉脑袋的。");
        return 1;
}

string ask_me()
{
        object me = this_player();

        if( this_object()->is_busy())
                return "我正忙着呢，你等等。";

        if(me->query_temp("name_wait_modify_ct")){
               command("hmm");
               return "不是告诉了你，皇帝赐名还要改会杀头的。\n";
        }
        if (!me->query("chaoting/wang") && !me->query("chaoting/jiawang"))
        {
            return "say 你不是宗室子弟，我管不到你。\n";
        }
        if (!me->query("chaoting/jiajianged"))
        {
            return "say 你不是宗室子弟，我管不到你。\n";
        }
        if(me->query_temp("name_modify_paid_ct")){
                command("nod");
                command("say 其实皇上赐的名还真有点寒碜人。");
                command ("say 这样吧，悄悄告诉我你要改什么名字就行了，爱新觉罗可不敢去，你就告诉我名字吧。\n");
                tell_object(me,"请使用gaiming <名>。\n");
        }
        
        command("consider");
        command("say "+me->query("name", 1)+"你这是让我难办啊，皇帝亲赐的姓名也敢改？\n");
        me->set_temp("name_wait_modify_ct", 1);
        
        return "如果你真的要改，我要但很大风险的，但是风险可以用黄金来化解，我觉得两千两是个很公道的价格。\n";
}
