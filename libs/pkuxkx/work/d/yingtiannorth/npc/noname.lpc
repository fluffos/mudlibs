// By Zine
               
#include <ansi.h> 
inherit NPC; 
#define SWORD_TALE "剑意随心，运转自如。用剑的极致其实在武当的绝义谷可以参悟(canwu)到。"
#define BLADE_TALE "刀芒横亘，大开大阖。用刀的极致其实在峨嵋的清音阁可以参悟(canwu)到。"
#define STAFF_TALE "杖法纵横，其势若颠。用杖的极致其实在洛阳的伊阙可以参悟(canwu)到。"
#define WHIP_TALE "鞭影连环，圆中有圆。用鞭的极致其实在本地的清凉山可以参悟(canwu)到。"
#define AXE_TALE "战斧霸道，冲阵斩将。用斧的极致其实在长白山的白河可以参悟(canwu)到。"
#define HAMMER_TALE "天锤之下，其势不可挡。用锤的极致其实在大轮寺下的天湖可以参悟(canwu)到。"
#define SPEAR_TALE "枪魂附体，点点红缨。用枪的极致其实在岳王墓的墓前广场可以参悟(canwu)到。"
#define HALBERD_TALE "戟似流云，天威难测。用戟的极致其实在晋阳的雁门关可以参悟(canwu)到。"
#define DAGGER_TALE "图穷匕见，神魔血咒。用匕的极致其实在明教的碧水潭畔可以参悟(canwu)到。"
#define THROWING_TALE "暗器有灵，上天入地。用暗器的极致其实在桃花岛的积翠亭可以参悟(canwu)到。"
int ask_weapon(string);
int ask_intro();
int ask_puzzle();
int ask_forget();
int ask_vein();
void create()
{
	set_name("南贤", ({ "nan xian","xian","nan"}));
        
	set("long",
	"他是在武林中和北丑齐名的前辈——南贤，他身上藏着许多秘密。\n"
         );
	
	set("gender", "男性");
	
	set("age", 93);
	set("attitude", "peaceful");
	set("shen_type", 1);
   	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
	set("max_qi", 1000);
        set("qi", 1000);
        set("neili", 900);
	set("max_neili", 900);
	set("jiali", 50);
	set("combat_exp", 650000000);
	
    set("inquiry", ([
            "高级兵器" : (: ask_intro :),
			"剑意" : (: ask_weapon,SWORD_TALE :),
            "jianyi" : (: ask_weapon,SWORD_TALE :),
            "刀芒" : (: ask_weapon,BLADE_TALE :),
            "daomang" : (: ask_weapon,BLADE_TALE :),
            "横杖" : (: ask_weapon,STAFF_TALE :),
            "hengzhang" : (: ask_weapon,STAFF_TALE :),
            "鞭影" : (: ask_weapon,WHIP_TALE :),
            "bianying" : (: ask_weapon,WHIP_TALE :),
            "霸斧" : (: ask_weapon,AXE_TALE :),
            "bafu" : (: ask_weapon,AXE_TALE :),
            "怒锤" : (: ask_weapon,HAMMER_TALE :),
            "nuchui" : (: ask_weapon,HAMMER_TALE :),
            "流戟" : (: ask_weapon,HALBERD_TALE :),
            "liuji" : (: ask_weapon,HALBERD_TALE :),
            "枪魂" : (: ask_weapon,SPEAR_TALE :),
            "qianghun" : (: ask_weapon,SPEAR_TALE :),
            "器灵" : (: ask_weapon,THROWING_TALE :),
            "qiling" : (: ask_weapon,THROWING_TALE :),
            "匕魔" : (: ask_weapon,DAGGER_TALE :),
            "bimo" : (: ask_weapon,DAGGER_TALE :),
            "解惑" : (: ask_puzzle :),
            "unpuzzle" : (: ask_puzzle :),
            "忘却技能" : (: ask_forget :),
            "forget" : (: ask_forget :),
			"二层通脉补偿" :(:ask_vein:),
            
       	]) );    
        setup();
        carry_object("/d/yingtianfu/neicheng/npc/obj/cloth-noname")->wear();
	

}

void init()
{
    add_action("do_forget","forget");
	add_action("do_transfer","transfer");
}

int do_forget(string arg)
{
    object me=this_player();
	string *weapons=({"sword","blade","staff","whip","axe","hammer","spear","halberd","dagger","throwing"});
    if (!me->query_temp("adv_weapon/forgetpermit"))
    {
        return 0;
    }
    if (!arg)
    {
        return notify_fail("你要忘却什么技能？\n");
    }
	if (member_array(arg,weapons)!=-1&&me->query("adv_weapon/class/"+arg))
	{
		me->delete("adv_weapon/class/"+arg);
        me->add("adv_weapon/amount",-1);
        me->add("max_neili",-100);
        tell_object(me,"你选择忘却了高级兵器技能【"+arg+"】，同时失去了一百点内力。\n");
        return 1;
	}
    else
    {
        tell_object(me,"你不会这项高级兵器技能。\n");
        return 1;
    }
}
int ask_vein()
{
	object me=this_player();
	if (!me->query("myVeins/足阳明胃经/completed")||!me->query("myVeins/足太阴脾经/completed"))
	{
		command("say 你第二层通脉未成，不满足补偿条件。");
		return 1;
	}
	if (me->query("myVeins/compensate/lv2"))
	{
		command("say 你已经被补偿过一次了。");
		return 1;
	}
	me->set("myVeins/compensate/lv2",1);
	message_vision("$N在$n周身要穴不停拍打，不一会白气蒸腾起来。\n",this_object(),me);
	if (me->query("xiantian/dex/vein"))
	{
		me->add("xiantian/dex/vein",-1);
		me->add("xiantian/str/vein",1);
		me->add("dex",-1);
		me->add("str",1);
		tell_object(me,"你失去一点先天身法，获得一点先天膂力。\n");
		return 1;
	}
	if (me->query("xiantian/str/vein"))
	{
		me->add("xiantian/str/vein",-1);
		me->add("xiantian/dex/vein",1);
		me->add("dex",1);
		me->add("str",-1);
		tell_object(me,"你失去一点先天膂力，获得一点先天身法。\n");
		return 1;
	}
	return 1;
}
int ask_forget()
{
    object me=this_player();
    if (!me->query("adv_weapon/class"))
    {
        tell_object(me,"你什么高级兵器技能都不会，要忘记什么呀？\n");
        return 1;
    }
    else
    {
        tell_object(me,"贪多嚼不烂，不听老人言，吃亏在眼前吧？我可以帮你忘掉一些技能，一项需要消耗一百点内力。\n");
        tell_object(me,"如果打定主意，就用forget <技能>执行吧，比如 forget blade。\n");
        me->set_temp("adv_weapon/forgetpermit",1);
        return 1;
    }
}

int ask_intro()
{
    object me=this_player();
    object ob=this_object();
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (ob->is_busy())
    {
        tell_object(me,ob->query("name")+"正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("介绍"))
    {
        tell_object(me,"你记性不好吗？你不是刚听过一遍？\n");
        return 1;
    }
    else
    {
        me->add_busy(1);
        ob->add_busy(1);
        command("say 其实世间的武技不外空手和兵器两种。\n");
        command("say 空手功夫自然是北面那个老家伙天下第一，论到兵器功夫的造诣我也不敢妄自菲薄。\n");
        command("say 为什么有些人练一辈子，却止步不前？人力或有穷尽，贪多而嚼不烂！\n");
        command("say 也就是说如果你一辈子专心于一件事物上，不论你的资质如何，必成大器。\n");
        me->set_temp("介绍",1);
        return 1;
    }
}
int check_status(object me,object ob)
{
	if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (ob->is_busy())
    {
        tell_object(me,ob->query("name")+"正忙着呢。\n");
        return 1;
    }
    if (base_name(environment(ob))!="/d/yingtiannorth/cyj")
    {
        tell_object(me,ob->query("name")+"抱着头痛苦地道：这里是哪里？我怎么什么都想不起来了？\n");
        return 1;
    }
    if (!me->query_temp("介绍"))
    {
        tell_object(me,"你不想知道什么是高级兵器吗？\n");
        return 1;
    }
	me->set("adv_weapon/permit",1);
	return 2;
}
int ask_weapon(string intro)
{
    if (check_status(this_player(),this_object())==2)
    {
        command("say "+intro);
        command("say 你要记住的是，当你选定了一种兵器，除非把它练至极致，否则不应该再去碰别的。\n");
    }
	return 1;
}
int ask_puzzle()
{
    object me=this_player();
    object ob=this_object();
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (ob->is_busy())
    {
        tell_object(me,ob->query("name")+"正忙着呢。\n");
        return 1;
    }
    if (!me->query("adv_weapon/block"))
    {
        command("say 等你真正遇到兵器武技的瓶颈再来找我吧。\n");
        return 1;
    }
    if ((me->query("combat_exp")-me->query("adv_weapon/puzzle"))>10000&& me->query("adv_weapon/puzzle")>100000)
    {
        me->delete_temp("adv_weapon/canwu");
        me->delete("adv_weapon/block");
        command("say 你武学上的魔障已除，继续努力吧。");
        me->delete("adv_weapon/puzzle");
        return 1;
    }
    if (me->query("adv_weapon/class"))
    {
        if (me->query("adv_weapon/class/staff/accuexp")==0
            ||me->query("adv_weapon/class/sword/accuexp")==0
            ||me->query("adv_weapon/class/blade/accuexp")==0
            ||me->query("adv_weapon/class/spear/accuexp")==0
            ||me->query("adv_weapon/class/halberd/accuexp")==0
            ||me->query("adv_weapon/class/dagger/accuexp")==0
            ||me->query("adv_weapon/class/axe/accuexp")==0
            ||me->query("adv_weapon/class/throwing/accuexp")==0
            ||me->query("adv_weapon/class/whip/accuexp")==0
            ||me->query("adv_weapon/class/hammer/accuexp")==0)
        {
            command("say 所有武技其实都是平凡所得，也许你去做点别的事，比如帮帮江湖中人完成些任务再来找我，自然就化解你的困惑了。\n");
            me->set("adv_weapon/puzzle",me->query("combat_exp"));
            return 1;
        }
        else
        {
            command("say 等你真正遇到兵器武技的瓶颈再来找我吧。\n");
            return 1;
        }
    }
    else
    {
            command("say 等你真正遇到兵器武技的瓶颈再来找我吧。\n");
            return 1;
    }
}

int do_transfer()
{
	object me=this_player();
	if (me->query("family/family_name")!="明教")
	{
		command("shake");
		return 1;
	}
	if (me->query("mingjiao/new_skill/adv_weapon_transfer"))
	{
		command("say 你已经把高级技能中的sword转换为dagger了。");
		return 1;
	}
	if (!me->query("adv_weapon/class/sword"))
	{
		command("say 只能把高级兵器的sword转换为dagger。");
		return 1;
	}
	if (me->query("adv_weapon/class/dagger/lv")>me->query("adv_weapon/class/sword/lv"))
	{
		command("say 你的高级兵器的dagger级别比sword要高。");
		return 1;
	}
	me->set("mingjiao/new_skill/adv_weapon_transfer",1);
	me->set("adv_weapon/class/dagger",me->query("adv_weapon/class/sword"));
	me->delete("adv_weapon/class/sword");
	tell_object(me,"你把高级兵器中的sword技能转换为dagger级别了。\n");
	me->save();
	return 1;
}