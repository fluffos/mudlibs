// girl.c 焰火销售小姐
#include <ansi.h>
inherit NPC;

void create()
{
          set_name("焰火销售小姐", ({ "fireworkgirl" }) );
         set("gender", "女性" );
        set("age", 19);
        set("long",
                 "她打扮得喜气洋洋，灿烂的笑容使你感受到了北侠春节的喜庆气氛，不禁想买几只烟花庆祝一下。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        setup();
        set("chat_chance", 3); 
        set("chat_msg", ({
"小姐说道：「来吧！买点烟花庆祝春节，请输入buy yan hua或者buy hua或者buy firework！」\n",
"小姐作神秘状说道：「烟花里可是有红包的，说不定您买的那支有巨额或者全能，甚至巨额全能红包呢！」\n",
        }));
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy","buy");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                          say( "小姐招呼道：「这位" + RANK_D->query_respect(ob)
                                  + "，来买支烟花喜庆一下吧，请输入buy yan hua或者buy hua或者buy firework！」\n");
                        break;
                case 1:
                          say( "小姐微笑着说：「" + RANK_D->query_respect(ob)
                                 + "，买支烟花，得个大红包！请输入buy yan hua或者buy hua或者buy firework！」\n");
                        break;
        }
}

int do_buy(string arg)
{
        object me;
        int i;
        me = this_player();
        
        if (arg != "yan hua" && arg != "hua" && arg != "firework")      
                return notify_fail("请打buy yan hua 或buy hua 或buy firework\n");
        if (me->query("mud_age")<36000)
            return notify_fail("对不起，至少要在线10小时以上才可以买烟花。\n");
        
		i = me->query("bonus2010/buytimes");
		i++;
		if (i==1)
			tell_object(me,"销售小姐一脸灿烂地对你说：“您是第一次购买我们的烟花，特惠价二两黄金，请give fireworkgirl 2 gold。”\n");
		else
			tell_object(me,"销售小姐狡诈地笑着对你说：“我们的烟花存量有限，您是第" + CHINESE_D->chinese_number(i) + "次购买我们的烟花了，请付" + CHINESE_D->chinese_number(to_int(pow(2,i))) + "两黄金或等值银票。”\n");
        return 1;
}

int accept_object(object me, object ob)
{
        int i,number;
        object firework;
        
        if (me->query("mud_age")<36000)
            return notify_fail("对不起，至少要在线10小时以上才可以买烟花。\n");
        
		i = me->query("bonus2010/buytimes");
		i++;
		number = pow(2,i)*10000;
		
		if (!ob->query("money_id"))
			return 0;

        if( ob->value() < number) 
        {
        	tell_object(me,"销售小姐狡诈地笑着对你说：“我们的烟花存量有限，您是第" + CHINESE_D->chinese_number(i) + "次购买我们的烟花，请付" + CHINESE_D->chinese_number(to_int(pow(2,i))) + "两黄金或等值银票。”\n");
        	return 0;
        }
        firework = new("clone/gift/firework");
		message_vision("销售小姐从身后拿出一只" + firework->query("name") +  "递给$N，笑着说道：谢谢惠顾！祝您春节愉快！\n",me);
		tell_object(me,"销售小姐又叮嘱道：为保证安全，这支烟花只能您亲自燃放，切勿让他人代您燃放！\n");
		tell_object(me,HIR+BNK+"多次燃放烟花红包不累计，只算最后一次的，请您慎重选择！\n红包只在燃放后起到正月十五期间获得经验或潜能奖励或掉宝时发放，\n如果对红包发放办法还不清楚，请查看news。\n"+NOR);
		firework->set("buyer",me->query("id"));
		firework->move(me);
		me->add("bonus2010/buytimes",1);
		call_out("dest",1,ob);
		return 1;
}
int dest(object ob)
{
	destruct(ob);
	return 1;
}


void die()
{
	return;
}