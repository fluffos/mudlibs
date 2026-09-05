// insert.c
// by Vast@pkuxkx
// modified by whuan to fix the bug
// all comments added by Vast

#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_GEMS;
string yinyang;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        int i;
        object *inv, gem, gem2,newgem;
        string yinyang;

        if (!arg || arg == "")
                return notify_fail("你想用什么宝石合成日魂月魄？\n");
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n");
        if( !objectp(gem = present(arg, me)) )
                return notify_fail("你身上没有这种宝石。\n");
        if (!gem->is_gem()) 
                return notify_fail("这个不是宝石，你合什么？\n");
        if (!gem->query("newgem")) 
                return notify_fail("这个不是最新版的宝石，你想搞什么鬼？\n");
        if (gem->query("yinyang") == "zhong") 
                return notify_fail("这个宝石是中性的，只能做配料。\n");
/*        if (gem->query("type") != "wuxing" )
                return notify_fail("只有火、木、土、金、水五种宝石可以用来合成日魂或月魄。\n");*/
        if (gem->query("level") == 1 && gem->query("yinyang") == "yang" && gem->query("type") == "wuxing")
                return notify_fail("这个宝石品相太低，无法合成日魂。\n");
        if (gem->query("level") == 0)
                return notify_fail("这是什么宝石啊，没见过。\n");
        if (me->query("max_neili") < 500 || me->query("neili") < 800)
                return notify_fail("以你现在的内力修为，还无法运功合并宝石！\n");
        yinyang = gem->query("yinyang");
        inv = all_inventory(me);
        for(i = 0; i < sizeof(inv); i++)
        {
          if (inv[i] != gem && 
          	  inv[i]->query("type") == "wuxing" && 
          	  gem->query("type") == "wuxing" &&
          	  (inv[i]->query("yinyang") == gem->query("yinyang") || 
          	   inv[i]->query("yinyang") == "zhong") && 
          	  inv[i]->query("level") == gem->query("level") )
          {
                if (!objectp(gem2))
                        gem2 = inv[i];
                else
                {
                        message_vision(HIG"$N暗运内力劲透宝石，但见" + gem->name() + HIG"表面异彩流动，
渐渐的$N收回了内力，只觉" + gem->name() + HIG"似乎完全变了模样！\n"NOR, me);
                                me->add("max_neili", - gem->query("level"));
                                me->add("neili", - 500);
                                me->start_busy(1);
                                if (gem->query("yinyang")=="yang")
                                newgem=new_gem("ri", gem->query("level")-1,"");//By Zine,改成先销毁再move，否则可能出现负重过重拿不动的情况，合成变重不合理。
                                if (gem->query("yinyang")=="yin")
                                newgem=new_gem("yue", gem->query("level"),"");
                                destruct(gem);
                                destruct(inv[i]);
                                destruct(gem2);
                                newgem->move(me);
                                return 1;
                }
          }
          else if ( inv[i] != gem && 
          	  inv[i]->query("type") == "siling" && 
          	  gem->query("type") == "siling" &&
          	  inv[i]->query("yinyang") != gem->query("yinyang") && 
          	  inv[i]->query("yinyang") != "zhong" && 
          	  inv[i]->query("level") == gem->query("level") &&
          	  inv[i]->query("material") == gem->query("material") )
          {
                message_vision(HIG"$N暗运内力劲透宝石，但见" + gem->name() + HIG"表面异彩流动，
渐渐的$N收回了内力，只觉" + gem->name() + HIG"似乎完全变了模样！\n"NOR, me);
                me->add("max_neili", - gem->query("level"));
                me->add("neili", - 500);
                me->start_busy(1);
                gem->set_name(query_gem_name2(gem->query("material"), gem->query("level"),"zhong"), 
                ({query_gem_id(gem->query("material"), gem->query("level")),"gem"}));
                gem->set("yinyang", query_all_yinyang(gem->query("material"), gem));
                gem->set("long", query_all_effect(gem->query("material"), gem));
                destruct(inv[i]);
                return 1;
          }
        }
        if (gem->query("type") == "wuxing" )
          return notify_fail("你必须有三块同样属性和级别的五行宝石才能进行合并！\n");
        else 
        	return notify_fail("你必须有二块同样属性、级别并且阴阳不同的四灵宝石才能进行合并！\n");
}

int help(object me)
{
        write(@HELP
指令格式：merge <宝石>

这个指令可以让你将三颗同样阴阳属性（中性宝石通用，但不能全部
是中性宝石）的五行宝石合并为日魂或月魄，或者让你将二颗阴阳属
性不同其他相同的四灵宝石合并成为一个中性的四灵宝石。合并宝石
要消耗玩家的大量内力，并且会降低最大内力。

HELP
    );
    return 1;
}
