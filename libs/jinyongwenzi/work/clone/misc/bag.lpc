// bao.c 红包

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"红包"NOR, ({ "hong bao", "bao", "bag" }));
        set("long","这是一个红色烫金的小纸袋子，上面印着『恭贺新禧』和『恭喜发财』\n"+
                   "等吉祥的字样，红咚咚地充满了喜气。你可以用可以用 fang <数字>\n"+  
                   "(以coin计算) 把钱放进红包袋内。\n");
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 10000);
                set("material","paper");
        }
        setup();
}

void init()
{
        add_action("do_open","open");
        add_action("do_fang","fang");
        add_action("do_open","dakai");        
}

int do_open(string arg)
{
       object me, obj;
       int amount;
       me = this_player();
       obj= this_object();
       amount = obj->query("balance");
       if( !arg || arg != "bag") return notify_fail("你要打开什么?\n");
       if( me->is_fighting()) return notify_fail("你还在战斗中！只能一次拿一样。\n");
       if( !obj->query("finish")) return notify_fail("里面没有钱啊。\n");
       if( obj->query("owner") == me->query("id"))
              return notify_fail("自己给自己红包?\n");
       me->add("balance", amount) ;
       message_vision(HIY"$N慢慢的打开红包......哇！！！\n"NOR,me);
       tell_object(me,HIW"\n你收到"+obj->query("finish")+"("+capitalize(obj->query("owner"))+")给你的红包，银行存款增加了"+chinese_number(amount/10000)+"两黄金。\n\n"NOR);
        write_file("/log/quest/hongbao",sprintf("%s %s(%s)得到%s(%s)给的红包%d两黄金。\n",ctime(time())[4..19],me->name(1),capitalize(me->query("id")),obj->query("finish"),capitalize(obj->query("owner")),amount/10000));
       destruct(obj);
       return 1;
}

int do_fang(string arg)
{
       object me;
       int amount;
       me=this_player();
       if(!arg || sscanf(arg, "%d", amount) !=1) return 0;
       if( me->query("balance") < amount ) return notify_fail("你的存款不够。\n");
       if( amount < 10000) return notify_fail("大新年的，你也太小气了吧。\n");
       if( this_object()->query("balance")) return notify_fail("红包里面已经有钱了。\n");
       me->add("balance", - amount);
       tell_object(me,HIR"\n你将"+ chinese_number(amount/10000)+"两黄金放入红包，准备给别人做新年礼物。\n\n"NOR);
       this_object()->set("balance", amount);
       this_object()->set("finish", me->query("name"));
       this_object()->set("owner", me->query("id"));
       this_object()->set("value", 0);
       this_object()->set("long","这是一个红色烫金的小纸袋子，上面印着『恭贺新禧』和『恭喜发财』\n"+
                                 "等吉祥的字样，红咚咚地充满了喜气。反面印着「"+this_object()->query("finish")+"敬祝」等字样。\n"+
                                 "你可以用 open bag 打开红包。\n");
       return 1;
}
