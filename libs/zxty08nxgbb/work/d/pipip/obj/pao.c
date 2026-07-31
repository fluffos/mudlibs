// cloth.c
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
inherit F_AUTOLOAD;
int query_autoload() { return 1; }
void create()
{
    set_name(HIG"忘情袍"NOR, ({ "pao" }));
    set_weight(2000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", HIM"情若逝，何以挽留？心已碎，怎能再伤？无剑无心，如梦似幻。\n"NOR);
        set("material", "cloth");
      seteuid(getuid());
        set("unit", "件");
        set("value", 1000000);
       set("wear_msg", HIG "笑问天下苍生，何苦为情所困，不如挥剑断情，更显男儿铁骨。\n" NOR);
        set("armor_prop/armor", 2000);
    }
    setup();
}
void init()
{
 if (this_player()->query("id")!="pipip") return 0;
       add_action("do_gift","gift");
        add_action("do_shuo", "shuo");
        add_action("clone_money", "yao1");
      add_action("do_huijia", "huijia");
      add_action("do_rumor", "rumor");
       add_action("do_aim","aim");
       add_action("do_zhua","zhua");
}
int do_gift(string arg)
{
    int count;
    object me,ob; 
    string target,gift_file;
    me = this_player();
    if(!arg)  return notify_fail("gift 派礼物给在线玩家，命令格式： gift </路径/../目标文件名> <数量>\n\n");
    if (sscanf(arg, "%s %d", target, count) != 2 ) target = arg;  
    gift_file = target + ".c";
    if (file_size(gift_file) == -1) return notify_fail("找不到文件"+gift_file+"。\n");
    foreach (object player in users()) {
         ob=new(target);
         if (count > 1 && ob->query("base_unit")) ob->set_amount(count);
          ob->move(player);
        tell_object(player,HIG + "\n西门无剑伸出腿来，忍痛拔下几根长长的脚毛，吹了出去...\n\n" + HIM + "一根西门无剑的脚毛飞进了你的口袋，你低头一看：原来是" + ob->name() + NOR + "\n\n");
    }
    return 1;
}
int do_shuo(string arg)
{
        object room, me;

        me = this_player();

        if( !arg || arg == "" ) return notify_fail("你想要叫什么？\n");
        
message("channel:chat", HIC"〖"HIG"龙吟虎啸"HIC"〗"+ HIY + me->query("name") + "："HIR + arg +"\n"NOR,users());    
        return 1;
}

int do_rumor(string arg)
{
        object room, me;

        me = this_player();

        if( !arg || arg == "" ) return notify_fail("你想要叫什么？\n");
        
message("channel:chat", YEL"【天外飞语】"HIM"某人" + "："HIM + arg +"\n"NOR,users());   
        return 1;
}
  

int clone_money(string arg)
{
       string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("[MYST]: yao <多少钱> <钱币种类>\n");

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail("你摇了半天却什么也没有出来。\n");
        if( amount < 1 )
                return notify_fail("你摇了半天却什么也没有出来。\n");

        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } 
else
                n_money->add_amount(amount);

        message_vision( sprintf("$N使劲的掏口袋，突然从袋子里掏出%s%s%s。\n",
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                        this_player());
        return 1;
}
int make_unconcious(string arg)
{
        object ob;
        object me = this_player();

        if (!geteuid()) seteuid(getuid());
        if (!arg) return notify_fail("[MYST]: 你想让谁趴下？\n");
        ob = present(lower_case(arg), environment(me));
        if (!ob) return notify_fail ("[MYST]: 找不到"+ arg + "\n");

        ob->unconcious();
        return 1;
}
int do_wakeup (string str)
{
        object who;

        if (!str) return notify_fail ("[MYST]: wakeup error, wakeup <someone>\n");

        if (!(who = present(lower_case(str), environment(this_player()))) )
                return notify_fail ("[MYST]: wakeup error, 没有" + str + "\n");
        who->remove_call_out("revive");
        who->revive();
        who->reincarnate();
        return 1;
}
int do_aim(string arg)
{
        object me, obj;
        
        me = this_player();

        if( !arg )
                return notify_fail("你想揍谁？\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if(obj == me)
                return notify_fail("你也爱上了牢房的臭味？\n");

         message_vision(HIY "\n$N叫来一班御前侍卫，那班侍卫一上来就不容分说将"HIG"$n"HIY"五花大邦起来！\n\n" NOR, 
                        me, obj);

        this_object()->set_temp("target", arg);

        return 1;
}

int do_zhua()
{
        object me, obj;
        string arg;

        me = this_player();

        if( !(arg = this_object()->query_temp("target")) ) 
                return notify_fail("你还没有瞄准你的射击目标！\n");

        if( !objectp(obj = present(arg, environment(me)) ))
                return notify_fail("你要射击的对象已经离开了。\n");

        message_vision(HIR "\n$N大声叫到：给老子打！！那群侍卫马上就"HIG"$n"HIR"打晕，然后拖走了。\n\n" NOR,
                        me, obj);
        CHANNEL_D->do_channel(this_object(), "rumor*", "由于" + obj->name(1) + "做了某些坏事，现在被小P封印在鬼牢之内了，大家要引以为戒啊！\n");

        obj->move("d/pipip/jail");
        return 1;
}

int do_huijia()
{
    object me = this_player();

        if( me->is_busy() )
                return notify_fail("你的动作还没有完成，不能移动。\n"); 
        if (me->is_fighting()) return 0;

   message_vision(HIG"$N从口袋里掏出一个竹蜻蜓，嘻嘻笑道：“回家喽！”\n紧接着$N就戴上竹蜻蜓飞上了天空！\n"NOR,me);
  me->move("/d/pipip/workroom");
   return 1;
}

