// By Zine
#include <ansi.h> 
inherit NPC; 
mapping combat_action =
([
        "hoof": ([
                "action":               "$N用后腿往$n的$l用力一蹬",
                "damage":               100,
                "damage_type":  "瘀伤",
        ]),
        "bite": ([
                "action":               "$N扑上来张嘴往$n的$l狠狠地一咬",
                "damage":               20,
                "damage_type":  "咬伤",
        ]),
        "claw": ([
                "action":               "$N用爪子往$n的$l一抓",
                "damage":               50,
                "damage_type":  "抓伤",
        ]),
        "poke": ([
                "action":               "$N用嘴往$n的$l一啄",
                "damage":               30,
                "damage_type":  "刺伤",
        ]),
        "qian": ([
                "action":               "$N用前螯往$n的$l用力一夹",
                "damage":               50,
                "damage_type":  "夹伤",
        ]),
        "sao": ([
                "action":               "$N用翅膀往$n的$l一扫",
                "damage":               40,
                "damage_type":  "瘀伤",
        ]),

]);

string *actions;

             

int ask_sword();
int ask_blade();
int ask_staff();
int ask_whip();
int ask_axe();
int ask_hammer();
int ask_halberd();
int ask_spear();
int ask_throwing();
int ask_dagger();
int ask_intro();
int ask_puzzle();
int ask_forget();

void create()
{
	set_name("无名氏", ({ "wuming shi","wuming","wu ming"}));
        
	set("long",
	"他是一个在武林中毫无声望的人士，但是似乎也藏着许多秘密。\n"
         );
	
	set("gender", "男性");
	set("verbs", ({ "bite","hoof","poke","sao" }));
	set("race", "野兽");
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
	set("combat_exp", 650000+random(100000000));
	//actions = keys(combat_action);
    set("inquiry", ([
            "高级兵器" : (: ask_intro :),
			"剑意" : (: ask_sword :),
            "jianyi" : (: ask_sword :),
            "刀芒" : (: ask_blade :),
            "daomang" : (: ask_blade :),
            "横杖" : (: ask_staff :),
            "hengzhang" : (: ask_staff :),
            "鞭影" : (: ask_whip :),
            "bianying" : (: ask_whip :),
            "霸斧" : (: ask_axe :),
            "bafu" : (: ask_axe :),
            "怒锤" : (: ask_hammer :),
            "nuchui" : (: ask_hammer :),
            "流戟" : (: ask_halberd :),
            "liuji" : (: ask_halberd :),
            "枪魂" : (: ask_spear :),
            "qianghun" : (: ask_spear :),
            "器灵" : (: ask_throwing :),
            "qiling" : (: ask_throwing :),
            "匕魔" : (: ask_dagger :),
            "bimo" : (: ask_dagger :),
            "解惑" : (: ask_puzzle :),
            "unpuzzle" : (: ask_puzzle :),
            "忘却技能" : (: ask_forget :),
            "forget" : (: ask_forget :),
            
       	]) );    
        setup();
        carry_object("/d/yingtianfu/neicheng/npc/obj/cloth-noname")->wear();
	

}

void init()
{
    add_action("do_forget","forget");
}

int do_forget(string arg)
{
    object me=this_player();
    if (!me->query_temp("adv_weapon/forgetpermit"))
    {
        return 0;
    }
    if (!arg)
    {
        return notify_fail("你要忘却什么技能？\n");
    }
    if (arg=="sword" && me->query("adv_weapon/class/sword"))
    {
        me->delete("adv_weapon/class/sword");
        me->add("adv_weapon/amount",-1);
        me->add("max_neili",-100);
        tell_object(me,"你选择忘却了剑意，同时失去了一百点内力。\n");
        return 1;
    }
    if (arg=="blade" && me->query("adv_weapon/class/blade"))
    {
        me->delete("adv_weapon/class/blade");
        me->add("adv_weapon/amount",-1);
        me->add("max_neili",-100);
        tell_object(me,"你选择忘却了刀芒，同时失去了一百点内力。\n");
        return 1;
    }
    if (arg=="staff" && me->query("adv_weapon/class/staff"))
    {
        me->delete("adv_weapon/class/staff");
        me->add("adv_weapon/amount",-1);
        me->add("max_neili",-100);
        tell_object(me,"你选择忘却了横杖，同时失去了一百点内力。\n");
        return 1;
    }
    if (arg=="whip" && me->query("adv_weapon/class/whip"))
    {
        me->delete("adv_weapon/class/whip");
        me->add("adv_weapon/amount",-1);
        me->add("max_neili",-100);
        tell_object(me,"你选择忘却了鞭影，同时失去了一百点内力。\n");
        return 1;
    }
    if (arg=="spear" && me->query("adv_weapon/class/spear"))
    {
        me->delete("adv_weapon/class/spear");
        me->add("adv_weapon/amount",-1);
        me->add("max_neili",-100);
        tell_object(me,"你选择忘却了枪魂，同时失去了一百点内力。\n");
        return 1;
    }
    if (arg=="halberd" && me->query("adv_weapon/class/halberd"))
    {
        me->delete("adv_weapon/class/halberd");
        me->add("adv_weapon/amount",-1);
        me->add("max_neili",-100);
        tell_object(me,"你选择忘却了流戟，同时失去了一百点内力。\n");
        return 1;
    }
    if (arg=="axe" && me->query("adv_weapon/class/axe"))
    {
        me->delete("adv_weapon/class/axe");
        me->add("adv_weapon/amount",-1);
        me->add("max_neili",-100);
        tell_object(me,"你选择忘却了霸斧，同时失去了一百点内力。\n");
        return 1;
    }
    if (arg=="hammer" && me->query("adv_weapon/class/hammer"))
    {
        me->delete("adv_weapon/class/hammer");
        me->add("adv_weapon/amount",-1);
        me->add("max_neili",-100);
        tell_object(me,"你选择忘却了怒锤，同时失去了一百点内力。\n");
        return 1;
    }
    if (arg=="throwing" && me->query("adv_weapon/class/throwing"))
    {
        me->delete("adv_weapon/class/throwing");
        me->add("adv_weapon/amount",-1);
        me->add("max_neili",-100);
        tell_object(me,"你选择忘却了器灵，同时失去了一百点内力。\n");
        return 1;
    }
    if (arg=="dagger" && me->query("adv_weapon/class/dagger"))
    {
        me->delete("adv_weapon/class/dagger");
        me->add("adv_weapon/amount",-1);
        me->add("max_neili",-100);
        tell_object(me,"你选择忘却了匕魔，同时失去了一百点内力。\n");
        return 1;
    }
    else
    {
        tell_object(me,"你不会这项高级兵器技能。\n");
        return 1;
    }
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

int ask_sword()
{
    object me=this_player();
    object ob=this_object();
    object thing;
    object* inv;
    int i;
    inv = deep_inventory(me);
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
    if (base_name(environment(ob))!="/d/yingtianfu/neicheng/cyj")
    {
        tell_object(me,ob->query("name")+"抱着头痛苦地道：这里是哪里？我怎么什么都想不起来了？\n");
        return 1;
    }
    if (!me->query_temp("介绍"))
    {
        tell_object(me,"你不想知道什么是高级兵器吗？\n");
        return 1;
    }
    else
    {
        me->set("adv_weapon/permit",1);
        command("say 剑意随心，运转自如。用剑的极致其实在武当的绝义谷可以参悟(canwu)到。\n");
        command("say 你要记住的是，当你选定了一种兵器，除非把它练至极致，否则不应该再去碰别的。\n");
        if (me->query("adv_weapon/class/sword/lv")>=1)
        {
            for(i=sizeof(inv)-1; i>=0; i--)
            {
                if((inv[i])->query("jianyi"))
                {
                    return 1;
                }
            }
            thing=new("/d/yingtianfu/neicheng/adv_weapon/jianyi");
            thing->move(me);
            tell_object(me,"无名氏交给你一把小剑。\n");
        }
        return 1;
    }
}

int ask_blade()
{
    object me=this_player();
    object ob=this_object();
    object thing;
    object* inv;
    int i;
    inv = deep_inventory(me);
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
    if (base_name(environment(ob))!="/d/yingtianfu/neicheng/cyj")
    {
        tell_object(me,ob->query("name")+"抱着头痛苦地道：这里是哪里？我怎么什么都想不起来了？\n");
        return 1;
    }
    if (!me->query_temp("介绍"))
    {
        tell_object(me,"你不想知道什么是高级兵器吗？\n");
        return 1;
    }
    else
    {
        me->set("adv_weapon/permit",1);
        command("say 刀芒横亘，大开大阖。用刀的极致其实在峨嵋的清音阁可以参悟(canwu)到。\n");
        command("say 你要记住的是，当你选定了一种兵器，除非把它练至极致，否则不应该再去碰别的。\n");
        if (me->query("adv_weapon/class/blade/lv")>=1)
        {
            for(i=sizeof(inv)-1; i>=0; i--)
            {
                if((inv[i])->query("daomang"))
                {
                    return 1;
                }
            }
            thing=new("/d/yingtianfu/neicheng/adv_weapon/daomang");
            thing->move(me);
            tell_object(me,"无名氏交给你一把小刀。\n");
        }
        return 1;
    }
}

int ask_staff()
{
    object me=this_player();
    object ob=this_object();
    object thing;
    object* inv;
    int i;
    inv = deep_inventory(me);
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
    if (base_name(environment(ob))!="/d/yingtianfu/neicheng/cyj")
    {
        tell_object(me,ob->query("name")+"抱着头痛苦地道：这里是哪里？我怎么什么都想不起来了？\n");
        return 1;
    }
    if (!me->query_temp("介绍"))
    {
        tell_object(me,"你不想知道什么是高级兵器吗？\n");
        return 1;
    }
    else
    {
        me->set("adv_weapon/permit",1);
        command("say 杖法纵横，其势若颠。用杖的极致其实在洛阳的伊阙可以参悟(canwu)到。\n");
        command("say 你要记住的是，当你选定了一种兵器，除非把它练至极致，否则不应该再去碰别的。\n");
        if (me->query("adv_weapon/class/staff/lv")>=1)
        {
            for(i=sizeof(inv)-1; i>=0; i--)
            {
                if((inv[i])->query("hengzhang"))
                {
                    return 1;
                }
            }
            thing=new("/d/yingtianfu/neicheng/adv_weapon/hengzhang");
            thing->move(me);
            tell_object(me,"无名氏交给你一把小杖。\n");
        }
        return 1;
    }
}

int ask_whip()
{
    object me=this_player();
    object ob=this_object();
    object thing;
    object* inv;
    int i;
    inv = deep_inventory(me);
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
    if (base_name(environment(ob))!="/d/yingtianfu/neicheng/cyj")
    {
        tell_object(me,ob->query("name")+"抱着头痛苦地道：这里是哪里？我怎么什么都想不起来了？\n");
        return 1;
    }
    if (!me->query_temp("介绍"))
    {
        tell_object(me,"你不想知道什么是高级兵器吗？\n");
        return 1;
    }
    else
    {
        me->set("adv_weapon/permit",1);
        command("say 鞭影连环，圆中有圆。用鞭的极致其实在本地的清凉山可以参悟(canwu)到。\n");
        command("say 你要记住的是，当你选定了一种兵器，除非把它练至极致，否则不应该再去碰别的。\n");
        if (me->query("adv_weapon/class/whip/lv")>=1)
        {
            for(i=sizeof(inv)-1; i>=0; i--)
            {
                if((inv[i])->query("bianying"))
                {
                    return 1;
                }
            }
            thing=new("/d/yingtianfu/neicheng/adv_weapon/bianying");
            thing->move(me);
            tell_object(me,"无名氏交给你一把小鞭。\n");
        }
        return 1;
    }
}

int ask_axe()
{
    object me=this_player();
    object ob=this_object();
    object thing;
    object* inv;
    int i;
    inv = deep_inventory(me);
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
    if (base_name(environment(ob))!="/d/yingtianfu/neicheng/cyj")
    {
        tell_object(me,ob->query("name")+"抱着头痛苦地道：这里是哪里？我怎么什么都想不起来了？\n");
        return 1;
    }
    if (!me->query_temp("介绍"))
    {
        tell_object(me,"你不想知道什么是高级兵器吗？\n");
        return 1;
    }
    else
    {
        me->set("adv_weapon/permit",1);
        command("say 战斧霸道，冲阵斩将。用斧的极致其实在长白山的白河可以参悟(canwu)到。\n");
        command("say 你要记住的是，当你选定了一种兵器，除非把它练至极致，否则不应该再去碰别的。\n");
        if (me->query("adv_weapon/class/axe/lv")>=1)
        {
            for(i=sizeof(inv)-1; i>=0; i--)
            {
                if((inv[i])->query("bafu"))
                {
                    return 1;
                }
            }
            thing=new("/d/yingtianfu/neicheng/adv_weapon/bafu");
            thing->move(me);
            tell_object(me,"无名氏交给你一把小斧。\n");
        }
        return 1;
    }
}

int ask_hammer()
{
    object me=this_player();
    object ob=this_object();
    object thing;
    object* inv;
    int i;
    inv = deep_inventory(me);
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
    if (base_name(environment(ob))!="/d/yingtianfu/neicheng/cyj")
    {
        tell_object(me,ob->query("name")+"抱着头痛苦地道：这里是哪里？我怎么什么都想不起来了？\n");
        return 1;
    }
    if (!me->query_temp("介绍"))
    {
        tell_object(me,"你不想知道什么是高级兵器吗？\n");
        return 1;
    }
    else
    {
        me->set("adv_weapon/permit",1);
        command("say 天锤之下，其势不可挡。用锤的极致其实在大轮寺下的天湖可以参悟(canwu)到。\n");
        command("say 你要记住的是，当你选定了一种兵器，除非把它练至极致，否则不应该再去碰别的。\n");
        if (me->query("adv_weapon/class/hammer/lv")>=1)
        {
            for(i=sizeof(inv)-1; i>=0; i--)
            {
                if((inv[i])->query("nuchui"))
                {
                    return 1;
                }
            }
            thing=new("/d/yingtianfu/neicheng/adv_weapon/nuchui");
            thing->move(me);
            tell_object(me,"无名氏交给你一把小锤。\n");
        }
        return 1;
    }
}

int ask_spear()
{
    object me=this_player();
    object ob=this_object();
    object thing;
    object* inv;
    int i;
    inv = deep_inventory(me);
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
    if (base_name(environment(ob))!="/d/yingtianfu/neicheng/cyj")
    {
        tell_object(me,ob->query("name")+"抱着头痛苦地道：这里是哪里？我怎么什么都想不起来了？\n");
        return 1;
    }
    if (!me->query_temp("介绍"))
    {
        tell_object(me,"你不想知道什么是高级兵器吗？\n");
        return 1;
    }
    else
    {
        me->set("adv_weapon/permit",1);
        command("say 枪魂附体，点点红缨。用枪的极致其实在岳王墓的墓前广场可以参悟(canwu)到。\n");
        command("say 你要记住的是，当你选定了一种兵器，除非把它练至极致，否则不应该再去碰别的。\n");
        if (me->query("adv_weapon/class/spear/lv")>=1)
        {
            for(i=sizeof(inv)-1; i>=0; i--)
            {
                if((inv[i])->query("qianghun"))
                {
                    return 1;
                }
            }
            thing=new("/d/yingtianfu/neicheng/adv_weapon/qianghun");
            thing->move(me);
            tell_object(me,"无名氏交给你一把小枪。\n");
        }
        return 1;
    }
}

int ask_halberd()
{
    object me=this_player();
    object ob=this_object();
    object thing;
    object* inv;
    int i;
    inv = deep_inventory(me);
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
    if (base_name(environment(ob))!="/d/yingtianfu/neicheng/cyj")
    {
        tell_object(me,ob->query("name")+"抱着头痛苦地道：这里是哪里？我怎么什么都想不起来了？\n");
        return 1;
    }
    if (!me->query_temp("介绍"))
    {
        tell_object(me,"你不想知道什么是高级兵器吗？\n");
        return 1;
    }
    else
    {
        me->set("adv_weapon/permit",1);
        command("say 戟似流云，天威难测。用戟的极致其实在晋阳的雁门关可以参悟(canwu)到。\n");
        command("say 你要记住的是，当你选定了一种兵器，除非把它练至极致，否则不应该再去碰别的。\n");
        if (me->query("adv_weapon/class/halberd/lv")>=1)
        {
            for(i=sizeof(inv)-1; i>=0; i--)
            {
                if((inv[i])->query("liuji"))
                {
                    return 1;
                }
            }
            thing=new("/d/yingtianfu/neicheng/adv_weapon/liuji");
            thing->move(me);
            tell_object(me,"无名氏交给你一把小戟。\n");
        }
        return 1;
    }
}

int ask_dagger()
{
    object me=this_player();
    object ob=this_object();
    object thing;
    object* inv;
    int i;
    inv = deep_inventory(me);
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
    if (base_name(environment(ob))!="/d/yingtianfu/neicheng/cyj")
    {
        tell_object(me,ob->query("name")+"抱着头痛苦地道：这里是哪里？我怎么什么都想不起来了？\n");
        return 1;
    }
    if (!me->query_temp("介绍"))
    {
        tell_object(me,"你不想知道什么是高级兵器吗？\n");
        return 1;
    }
    else
    {
        me->set("adv_weapon/permit",1);
        command("say 图穷匕见，神魔血咒。用匕的极致其实在明教的碧水潭畔可以参悟(canwu)到。\n");
        command("say 你要记住的是，当你选定了一种兵器，除非把它练至极致，否则不应该再去碰别的。\n");
        if (me->query("adv_weapon/class/dagger/lv")>=1)
        {
            for(i=sizeof(inv)-1; i>=0; i--)
            {
                if((inv[i])->query("bimo"))
                {
                    return 1;
                }
            }
            thing=new("/d/yingtianfu/neicheng/adv_weapon/bimo");
            thing->move(me);
            tell_object(me,"无名氏交给你一把小匕首。\n");
        }
        return 1;
    }
}

int ask_throwing()
{
    object me=this_player();
    object ob=this_object();
    object thing;
    object* inv;
    int i;
    inv = deep_inventory(me);
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
    if (base_name(environment(ob))!="/d/yingtianfu/neicheng/cyj")
    {
        tell_object(me,ob->query("name")+"抱着头痛苦地道：这里是哪里？我怎么什么都想不起来了？\n");
        return 1;
    }
    if (!me->query_temp("介绍"))
    {
        tell_object(me,"你不想知道什么是高级兵器吗？\n");
        return 1;
    }
    else
    {
        me->set("adv_weapon/permit",1);
        command("say 暗器有灵，上天入地。用暗器的极致其实在桃花岛的积翠亭可以参悟(canwu)到。\n");
        command("say 你要记住的是，当你选定了一种兵器，除非把它练至极致，否则不应该再去碰别的。\n");
        if (me->query("adv_weapon/class/throwing/lv")>=1)
        {
            for(i=sizeof(inv)-1; i>=0; i--)
            {
                if((inv[i])->query("qiling"))
                {
                    return 1;
                }
            }
            thing=new("/d/yingtianfu/neicheng/adv_weapon/qiling");
            thing->move(me);
            tell_object(me,"无名氏交给你一件暗器。\n");
        }
        return 1;
    }
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