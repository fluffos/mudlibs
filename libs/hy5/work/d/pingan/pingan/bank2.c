// bank.c

inherit ROOM;

int do_apply(string);
int do_cancel(string);
int confirm(string,int,object,object);


void create()
{
        set("short", "相记钱庄");
        set("long", @LONG
        
这是一家老字号的钱庄，相老板是山西人，这家钱庄从他的爷爷的爷
爷的爷爷的爷爷那辈开始办起，一直传到他手里，声誉非常好，在全
国各地都有分店。它发行的银票通行全国。钱庄的门口挂有一块牌子
(paizi)。
LONG);
        set("item_desc", ([
                "paizi": @TEXT
                
这里是钱庄，目前我们提供的服务有：

        apply  card      申请信用卡
        
        cancel card         注销信用卡
        
TEXT]) );
//      cancel bag       注销乾坤袋

        set("exits", 
        ([ //sizeof() == 4
           "down" : __DIR__"bank1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/tiesuanpan" : 1,
        ]));

//      set("outdoors", "changan");
       set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_apply","apply");
        add_action("do_cancel","cancel");  
/*      add_action("do_upgrade","upgrade"); */
}

int do_apply(string arg)
{
        object bag,me=this_player();
        if (!arg) return notify_fail("你想申请什么?\n");
        if(arg=="card"){
                if (present("credit card",me))        tell_object(me,"铁算盘疑惑地看着你：申请信用卡吗？你已经办理过手续了!\n");
                else{
                        bag=new("/clone/money/account.c");
                        bag->move(me);
                        tell_object(me,"钱庄老板给你一张蓝色卡片，你得到了信用卡。\n");
                        tell_room(this_object(),"钱庄老板把一张蓝色卡片递给"+me->query("name")+".\n",me);
                }
                return 1;
        }
        else         if(arg=="bag"){
                if (present("big bag",me))tell_object(me,"铁算盘邪恶地看着你：申请乾坤袋吗？你还想要几口？\n");
                else{
                        }
                        /* bag=new("/obj/bigbag");
                  bag->move(me);
                        tell_object(me,"钱庄老板给你一口特大的袋子，你得到了乾坤袋。\n");
                        tell_room(this_object(),"钱庄老板把一口特大的袋子递给"+me->query("name")+"。\n",me);
                }*/
                return 1;
        }
        else  return notify_fail("铁算盘哼了一声：你想要什么?\n");
}

int do_cancel(string arg)
{
        object bag,me=this_player();
        if (!arg) return notify_fail("你想注销什么?\n");
        if(arg=="card"){
                if (!(bag=present("credit card",me)))        tell_object(me,"铁算盘疑惑地看着你：注销信用卡吗？你不会是自己弄丢了吧?\n");
                else{
                        destruct(bag);
                        tell_object(me,"你将信用卡还给了钱庄老板。\n");
                        tell_room(this_object(),me->query("name")+"把一张蓝色卡片递给钱庄老板。\n",me);
                }
                return 1;
        }
/*      
        else         if(arg=="bag"){
                if (!(bag=present("big bag",me)))tell_object(me,"铁算盘疑惑地看着你：注销乾坤袋吗？你不会是自己弄丢了吧?\n");
                else{
                        destruct(bag);
                        tell_object(me,"你将乾坤袋还给了钱庄老板。\n");
                        tell_room(this_object(),me->query("name")+"把一口特大的袋子递给钱庄老板。\n",me);
                }
                return 1;
        }
*/      
        else  return notify_fail("铁算盘哼了一声：你想注销什么?\n");
}

/* int do_upgrade(string arg)
{
        int upgrade_value=25;        //25 golds
        object bag,me=this_player();
        int i,max_bag_items=me->query("maxbagitems");
        
        if (!arg) return notify_fail("你想升级什么?\n");
        if(arg=="bag"){
                if (!(bag=present("big bag",me)))return notify_fail("铁算盘邪恶地一笑：你熬了几个通宵了?自己有没有乾坤袋都不知道!\n");
                 if(!max_bag_items){
                max_bag_items=MAX_BIGBAG_ITEMS;
                        me->set("maxbagitems",MAX_BIGBAG_ITEMS);
                };
                for(i=5 ;i<max_bag_items;i++) upgrade_value *=2;
                write("乾坤袋基本容量是五，升级一次其容量增一。\n");
                write("本次升级可将你的乾坤袋的容量从"+chinese_number(max_bag_items)+"升到"
                        +chinese_number(max_bag_items+1)+"，需要"+chinese_number(upgrade_value)+"两黄金。\n");
                upgrade_value*=10000;
                i=me->can_afford(upgrade_value);
                if( !i )return notify_fail("可是你没有足够的钱。\n");
                if(i==2)return notify_fail("可是你没有金龙卡，无法结帐。\n");

                write("\n你真地要升级吗(y/n)?\n");
             return input_to( (: confirm :) ,1,upgrade_value,me,bag);
        }
        else  return notify_fail("铁算盘哼了一声：你以为是个东西就能升级?\n");
}
*/
int confirm(string arg,int upgrade_value,object me,object bag)
{
        if(arg == "y" || arg == "Y"){
             if(me->pay_money(upgrade_value)){
                  me->add("maxbagitems",1);
                  bag->set_max_items(me->query("maxbagitems"));
                  tell_object(me,"钱庄老板在你的乾坤袋上拍了拍，眼看着乾坤袋大了一圈。\n");
                        tell_room(this_object(),"钱庄老板拍了拍"+me->query("name")+"手上的袋子，那袋子竟似乎大了一圈。\n",me);
                }
                else write("error");
                return 1;
        }
        else{
                write("你放弃升级乾坤袋。\n");
                return 0;
        }
}
