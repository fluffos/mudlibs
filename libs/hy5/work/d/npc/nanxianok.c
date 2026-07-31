// This program is a part of NITAN MudLIB

#include <ansi.h>

inherit NPC;

int ask_hygoods();
private string chinese_types(string types)
{
        switch(types)
        {
        case "object"             :    return HIC "物品" NOR;
        case "objamount"          :    return HIC "物品" NOR;
        case "special"            :    return HIG "特殊技能" NOR;
        case "special2"           :    return HIW "转世技能" NOR;
        case "story"              :    return HIM "故事" NOR;
        case "package"            :    return HIR "※" NOR;
        case "card"               :    return HIY "★" NOR;
        case "gold"               :    return HIY "＄" NOR;
        default                   :    return HIR "未知" NOR;
        }
}

mapping goods = ([
        "tishenwawa"  : "替身娃娃:2:/clone/misc/cloth:object:替身娃娃可以为你档死一次",
        "tongren"  : "冲穴铜人:100:/clone/misc/cloth:object:冲穴铜人冲穴时不产生意外",
        "seasoncard"            : "季度会员:60:seasoncard:card:会员季卡 附带会员背包",
        "yearcard"              : "年度会员:300:yearcard:card:会员年卡 加送10个替身娃娃",
        "forevercard"           : "终身会员:500:forevercard:card:会员终身卡 加送冲穴铜人",
]);



string get_types(string arg)
{
        string strtmp;
        mixed * items;

        strtmp = goods[arg];
        items = explode(strtmp, ":");

        return items[3];
}
int sort_object(string str1, string str2)
{
        if( get_types(str1) == "package" ) return 1;
        if( get_types(str2) == "package" ) return -1;

        if( get_types(str1) == "objamount" ) return 1;
        if( get_types(str2) == "objamount" ) return -1;

        if( get_types(str1) == "object" ) return 1;
        if( get_types(str2) == "object" ) return -1;

        if( get_types(str1) == "story" ) return 1;
        if( get_types(str2) == "story" ) return -1;

        if( get_types(str1) == "special" ) return 1;
        if( get_types(str2) == "special" ) return -1;

        if( get_types(str1) == "special2" ) return 1;
        if( get_types(str2) == "special2" ) return -1;
        
        if( get_types(str1) == "card" ) return 1;
        if( get_types(str2) == "card" ) return -1;

        if( get_types(str1) == "gold" ) return 1;
        if( get_types(str2) == "gold" ) return -1;

        return -1;
}

public varargs void show_goods(string arg)
{
        string strtmp;
        int i, j;
        mixed * obs, all, items;

        obs = keys(goods);

        all = unique_array(obs, (:  get_types($1) == "objamount" ? 1 : get_types($1) == "object" ? 2 :
                                    get_types($1) == "story" ? 3 : get_types($1) == "special" ? 4 :
                                    get_types($1) == "special2" ? 5 : get_types($1) == "card" ? 6 : 
                                    get_types($1) == "package" ? 7 : 8 :));

        all = sort_array(all, (: sort_object($1[0], $2[0]) :));

        write(HIY "会员商店目前出售以下货物：\n" NOR);
        write(sprintf(HIW "%-16s%-16s%-10s%-10s%s\n" NOR,
                      "名称", "代号", "价格($HY)", "种类", "简要说明"));
        write(HIG "-------------------------------------------------------------------------------\n\n" NOR);

        for (i = 0; i < sizeof(all); i ++)
        {
                strtmp = "";
                items = ({});

                for(j = 0; j < sizeof(all[i]); j ++)
                {
                        strtmp = goods[all[i][j]];
                        items = explode(strtmp, ":");
                        if (sizeof(items) != 5)
                        {
                                write("strtmp made items != 5 is : " + strtmp + "\n");
                                return;
                        }
                        write(sprintf(HIW "%-16s%-16s" HIY "%-10s" HIW "%-26s%-50s\n" NOR,
                                      items[0], all[i][j], items[1], chinese_types(items[3]), items[4]));
                }
        }

        write(HIG "凡是种类带有" HIR "※" HIG "标记的服务均为大礼包。\n" NOR);
        write(HIG "凡是种类带有" HIY "★" HIG "标记的服务均为购买会员期限。\n" NOR);
        write(HIG "请认真阅读有关说明，购买前请考虑清楚， 如无差错，恕不退货！\n" NOR);
        write(HIG "-------------------------------------------------------------------------------\n\n" NOR);
}


void create()
{
        set_name("南贤", ({ "nan xian", "nan", "xian" }));
        set("long", @LONG
此人衣着青杉，须发皆白。看似其貌不扬，实
却为世上头号人物。这便是武林中号称「南贤
北丑」的南贤。其为人亦正亦邪，年轻时曾干
下了无数轰天动地的大举。生平决战无数，仅
在北丑手下失过手。
LONG);
        set("nickname", HIW "天下至贤" NOR);
        set("title", HIC "武林泰斗" NOR);
        set("gender", "男性" );
        set("age", 74);
        set("attitude", "friendly");
        set("max_jing", 50000);
        set("max_qi", 50000);
        set("max_jingli", 50000);
        set("jingli", 50000);
        set("max_neili", 50000);
        set("neili", 50000);
        set("jiali", 350);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
   set("no_kill",1);
	    set("qi",   99999999);
	    set("jing", 99999999);
	set("eff_qi",   99999999);
	set("eff_jing", 99999999);
	set("max_qi",   99999999);
	set("max_jing", 99999999);
	set("neili", 554500);
	set("max_neili", 554500);
	set("jiali", 0);
	set("combat_exp", 85000000);
	set("score", 50000);                
        set_skill("strike",1200);
        set_skill("unarmed",1200);
        set_skill("dodge",1200);
        set_skill("force", 1200);
        set_skill("unarmed", 1200);
        set_skill("sword", 1200);
	set_skill("parry", 1210);
	set_skill("literate", 1200);
	set_skill("canzhi-duanhun",1300);
	set_skill("ai-sword",1300);
        map_skill("unarmed", "canzhi-duanhun");
        map_skill("parry", "canzhi-duanhun");
        map_skill("sword", "ai-sword");

        set("inquiry", ([
                "name" : "姓名不过是一种代号而已，问它有何意义？",
                "北丑" : "你尽提那个龌龊的家伙做甚？",
                "会员商品": (: ask_hygoods :),
                "membergoods": (: ask_hygoods :),	
        ]));

set_temp("apply/intelligence", 200);
set_temp("apply/strength",200);
set_temp("apply/dexerity",200);
set_temp("apply/constitution",200);
set_temp("apply/karey", 200);
set_temp("apply/percao", 200);	
set_temp("apply/armor", 5000);
set_temp("apply/defense", 200);
set_temp("apply/attack", 200);
set_temp("apply/damage", 5000);  
            
       	setup();
     carry_object("/clone/weapon/changjian")->wield();
          carry_object("/clone/misc/cloth")->wear();


        /*
        if (! clonep(this_object()))
        {
                move("/d/city/wumiao");
                message_vision(WHT "\n突然间你眼前一花，身后似乎多了个"
                               "人影。\n" NOR, this_object());
                set("startroom", "/d/city/wumiao");
        }
        */
        set("startroom", "/d/city/wumiao");

}
void init()
{
	add_action("buy_goods", "buygoods");
}


int ask_hygoods()
{
    string week, month, year, day, time,hydata;
    string check;
 	    int i,how=0,what_day=100,neili,exp,pot,mpgx;
 	object me = this_player();
show_goods();
        return 1;
}



public int buy_goods(string which)
{
        mixed * all, items;
        mixed specials;
        string strtmp;
        int i, vip, value, money;
        object buy_ob;
object ob=this_player();
        if (!ob->query("hyvip"))
        {
                write("对不起，只有会员才能享受此服务！请参见 " HIR "help member " NOR " ！\n");
                return 1;
        }


        all = keys(goods);
        if (member_array(which, all) == -1)
        {
                write("对不起，没有您要购买的物品 " + HIR + which + NOR + "， 请问一下"
                      "我吧(ask nanxian about 会员商品) 。\n" NOR);
                return 1;

        }

        strtmp = goods[which];
        items = explode(strtmp, ":");
        sscanf(items[1], "%d", value);

        if (items[2] == "manual")
        {
                write("对不起，该服务必须由 admin 手动实现，请及时与 admin 联系！\n");
                return 1;
        }

        vip   = ob->query("hyvip");
        money = ob->query("hymoney");

        // 会员折扣
/*
        if (vip == 3)
                value = value * 80 / 100;
        else
        if (vip == 2)
                value = value * 85 / 100;
        else
        if (vip == 1)
                value = value * 90 / 100;
*/
        if (value < 1) value = 1;

        if (money < value)
        {
                write("对不起，您的海洋金币数量不够！\n");
                return 1;
        }

        switch(items[3])
        {
        case "package":


                switch( which )
                {
                case "newbie" :
                        buy_ob = new("/clone/gift/xuanhuang");
                        buy_ob->set_amount(10);
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/jiuzhuan");
                        buy_ob->set_amount(10);
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/tianxiang");
                        buy_ob->set_amount(20);
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/puti-zi");
                        buy_ob->set_amount(50);
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/xiandan");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/xiandan");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/xisuidan");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/xisuidan");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/shenliwan");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/shenliwan");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/unknowdan");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/unknowdan");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/medicine/yuqing");
                        buy_ob->set_amount(600);
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/max/zhenyu");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/max/longjia");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/max/xuanhuang");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/gift/int3");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/gift/int3");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/gift/str3");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/gift/str3");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/gift/con3");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/gift/con3");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/gift/dex3");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/gift/dex3");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/item/tianjing");
                        buy_ob->move(ob, 1);
                        ob->add("balance", "1000000000");
                        //MEMBER_D->db_fee_member(ob, 31);
                        break;


                case "yj-rune" :
                        for (i = 0; i < 7; i++)
                        {
                                buy_ob = new("/clone/enchase/rune31");
                                buy_ob->move(ob, 1);
                                buy_ob = new("/clone/enchase/rune33");
                                buy_ob->move(ob, 1);
                        }
                        break;
                default :
                        break;
                }

                write(HIC "您总共花费了 " HIY + value + HIC + " $HY, 祝您好运！\n" NOR);
                return 1;

        case "object":

                buy_ob = new(items[2]);
                if (! objectp(buy_ob))
                {
                        write("复制物品失败，请与本站ADMIN联系！\n");
                        return 0;
                }


                buy_ob->move(ob, 1);
                write(HIC "您总共花费了 " HIY + value + HIC + " $HY, 祝您好运！\n" NOR);
                return 1;

        case "objamount":
                buy_ob = new(items[2]);
                if (! objectp(buy_ob))
                {
                        write("复制物品失败，请与本站ADMIN联系！\n");
                        return 0;
                }

                if (which == "putizi")
                        buy_ob->set_amount(20);
                else
                if (which == "jiuzhuan")
                        buy_ob->set_amount(10);
                else
                if (which == "yuqingsan")
                        buy_ob->set_amount(120);
                else
                if (which == "tianxiang")
                        buy_ob->set_amount(15);
                else
                if (which == "xuanhuang1")
                        buy_ob->set_amount(5);

                buy_ob->move(ob, 1);

                write(HIC "您总共花费了 " HIY + value + HIC + " $HY, 祝您好运！\n" NOR);
                return 1;

        case "card":

                if (which != "monthcard" && which != "seasoncard" &&
                    which != "yearcard"  && which != "forevercard")
                {
                        write("没有这种类型的会员卡！\n");
                        return 0;
                }

                if (which == "monthcard")
ob->add("hyday",31);
                else
                if (which == "seasoncard")
ob->add("hyday",92);
                else
                if (which == "yearcard")
ob->add("hyday",365);
                else
                if (which == "forevercard")
ob->add("hyday",1800000);


                write(HIC "您总共花费了 " HIY + value + HIC + " $HY, 祝您好运！\n" NOR);
                return 1;

        case "story":
                // 首先检查是否中过故事
                if (ob->query("gift/" + which))
                {
                        write("您已经中过该故事了！\n");
                        return 0;
                }
                ob->add("gift/" + which, 1);
                ob->add(items[2], 1);

                write(HIC "您总共花费了 " HIY + value + HIC + " $HY, 祝您好运！\n" NOR);
                return 1;

        case "gold" :

                ob->add("balance", items[2]);


                write(HIC "您总共花费了 " HIY + value + HIC + " $HY, 祝您好运！\n" NOR);
                return 1;

        case "special":
                // 首先检查是否有该special
                // 同时检查总共的special不能大于7
                if (! ob->query("special_skill"))specials = 0;
                else specials = keys(ob->query("special_skill"));
                if (1) // 正常出售
                {
                        if (sizeof(specials) > 0)
                        {
                                if (member_array(which, specials) != -1)
                                {
                                        write("对不起，您已经有这个特殊技能了！\n");
                                        return 0;
                                }
                                if (sizeof(specials) >= 24)
                                {
                                        write("对不起，一个帐号最多只能拥有四个特殊技能！\n");
                                        return 0;
                                }
                        }


                        ob->set("special_skill/" + which, 1);
                        write(HIC "您总共花费了 " HIY + value + HIC + " $HY, 祝您好运！\n" NOR);
                        return 1;
                }
                else
                {
                        write("暂时停止出售特殊技能！请谅解！\n");
                        return 0;
                }
        
        case "special2":
                if (! ob->query("special_skill")) specials = 0;
                else specials = keys(ob->query("special_skill"));
                if (ob->query("reborn/times")) // 正常出售
                {
                        if (sizeof(specials) > 0)
                        {
                                if (member_array(which, specials) != -1)
                                {
                                        write("对不起，您已经有这个转世技能了！\n");
                                        return 0;
                                }
                        }

                        ob->set("special_skill/" + which, 1);
                        write(HIC "您总共花费了 " HIY + value + HIC + " $HY, 祝您好运！\n" NOR);
                        return 1;
                }
                else
                {
                        write("你无法购买转世技能！请谅解！\n");
                        return 0;
                }
                
        default:
                write("无效物品种类！\n");
                return 0;
        }
}