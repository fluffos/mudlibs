// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <command.h>

inherit ROOM;


void create()
{
        set("short", HIW"元帅帐营"NOR);
        set("long", @LONG
这里就是「大宋」元帅的帐营，两边分立着众将领军士，大宋元帅在
这里负责调兵遣将，抗击蒙古军的入侵，不时有传令兵匆忙地进出，传递
着前线的军情。
LONG
);

        set("no_magic", "1");
        set("exits", ([ /* sizeof() == 5 */   
              "north" :   __DIR__"sying",
              "south" :   __DIR__"sying4",
              "west"  :   __DIR__"sying2",
              "east"  :   __DIR__"sying3",
        ]));    

        set("objects", ([
        ]));
    
        setup();
}

void init()
{
        object me = this_player();
        
        if (me == WAR_D->query_king())
        {
                message_vision(HIW "帐中的将士看见$N走了进来，连忙将身体站得笔直，尊敬地向$N行礼致敬！\n" NOR, me);

                add_action("do_assign", "paiqian");
                add_action("do_dianjiang", "dianjiang");
        } 
}




int do_assign(string arg)
{
        object me = this_player(), ob, ling, obb, horse;
        string who, what;
        int i, n, flag;
        mapping jiang;


        jiang = me->query_temp("jun_quest/jiang");

        if (! arg || sscanf(arg, "%s to %s", who, what) != 2)
                return notify_fail("请用 paiqian sb to do sth. 来发布号令！\n");

        if (! objectp(ob = present(who, environment(me))))
                return notify_fail("这里没有你可以调度的这名将领！\n");

        flag = 1;
        if (! (jiang = me->query_temp("jun_quest/jiang")))
                n = 1;
        else
        for (i = 0; i < sizeof(jiang); i++)
        {
                obb = me->query_temp("jun_quest/jiang/jiang" + (i + 1));
                if (obb == ob)
                        flag = 0;
        }                       

        if (sizeof(jiang) > 3 * me->query("degree_jungong") && flag)
                return notify_fail("你的统帅能力不够，带不了这么多兵啊。\n"); 

        if (ob->query_temp("jun_quest/party") != "song")
                return notify_fail("对方不是宋军，如何供你调度？！\n");

        if (ob->query("degree_jungong") < 3)
                return notify_fail("对方的统帅才能太低了，难堪大用！\n");     

        if (ob == me)
                return notify_fail("自己命令自己？你不嫌累啊你？！\n"); 

        switch(what)
        {
        case "yaliang":
                message_vision(HIR "$N略一沉思，从案前抽出一枚令箭道：“$n听令，" +
                               "近来军中粮草匮乏，\n命你火速率部，在半月内将京师供应之粮草押解" +
                               "至军中，如有延误，军法论处！\n" NOR, me, ob);
      
                ob->set("party/party_name", HIY "大宋" NOR);
                ob->set("party/rank", HIY "军备营统领" NOR);  

                if (! present("ling jian", ob))
                {
                        ling = new("/adm/npc/obj/lingjian");
                        ling->set("master", me->query("id"));
                        ling->set("owner", ob->query("id"));
                        ling->move(ob);
                        ling->check_me(ob); 
                }

                ob->set_temp("jun_quest/escort", 1);
                ob->command("yaliang");
                break;

        case "xunlian-cavalry":
        case "xunlian-qibing":
                if (ob->query_temp("jun_quest/train")
                &&  ob->query_temp("jun_quest/train") != "cavalry")
                        return notify_fail("对方已经另有他职了，请重新选派将领吧！\n");

                message_vision(HIR "$N略一沉思，从案前抽出一枚令箭道：“$n听令，" +
                               "近来军中几无能战之师，\n命你加紧训练一支精锐骑兵，以备不时之需，" +
                               "不得有误！\n" NOR, me, ob);

                ob->set("party/party_name", HIR "大宋" NOR);
                ob->set("party/rank", HIR "车骑营统领" NOR);
                if (! present("zhan ma", ob))
                {
                        horse = new(__DIR__"song/horse");
                        if (horse->move(environment(ob))) 
                                "/cmds/std/ride"->main(ob, horse->query("id"));                                
                        else destruct(horse);
                }
                if (! present("ling jian", ob))
                {      
                        ling = new("/adm/npc/obj/lingjian");
                        ling->set("master", me->query("id"));
                        ling->set("owner", ob->query("id"));
                        ling->move(ob);
                        ling->check_me(ob);
                }
  
                ob->set_temp("jun_quest/train", "cavalry");
                ob->command("xunlian");
                break;

        case "xunlian-infantry":
        case "xunlian-bubing":
                if (ob->query_temp("jun_quest/train")
                &&  ob->query_temp("jun_quest/train") != "infantry")
                        return notify_fail("对方已经另有他职了，请重新选派将领吧！\n");

                message_vision(HIR "$N略一沉思，从案前抽出一枚令箭道：“$n听令，" +
                               "近来军中几无能战之师，\n命你加紧训练一支精锐步兵，以备不时之需，" +
                               "不得有误！\n" NOR, me, ob);
                ob->set("party/party_name", HIW "大宋" NOR);
                ob->set("party/rank", HIW "步兵营统领" NOR);

                if (! present("ling jian", ob))
                {
                        ling = new("/adm/npc/obj/lingjian");
                        ling->set("master", me->query("id"));
                        ling->set("owner", ob->query("id"));
                        ling->move(ob);  
                        ling->check_me(ob); 
                }

                ob->set_temp("jun_quest/train", "infantry");
                ob->command("xunlian");
                break;

        case "xunlian-archer":
        case "xunlian-gongnu":
                if (ob->query_temp("jun_quest/train")
                &&  ob->query_temp("jun_quest/train") != "archer")
                        return notify_fail("对方已经另有他职了，请重新选派将领吧！\n");

                message_vision(HIR "$N略一沉思，从案前抽出一枚令箭道：“$n听令，" +
                               "近来军中几无能战之师，\n命你加紧训练一支精锐弓箭手，以备不时之需，" +
                               "不得有误！\n" NOR, me, ob);
                ob->set("party/party_name", HIB "大宋" NOR);
                ob->set("party/rank", HIB "神弩营统领" NOR);

                if (! present("ling jian", ob))
                {
                        ling = new("/adm/npc/obj/lingjian");
                        ling->set("master", me->query("id"));
                        ling->set("owner", ob->query("id"));
                        ling->move(ob);  
                        ling->check_me(ob); 
                }

                ob->set_temp("jun_quest/train", "archer");
                ob->command("xunlian");
                break;

        default:
                return notify_fail("身为一军之帅，请不要滥用你的军权！\n");
        }
        
        
        if (flag)
        { 
                n = sizeof(jiang) + 1;
                me->set_temp("jun_quest/jiang/jiang" + n, ob);
        }
        
        return 1;
}



int do_dianjiang()
{
        object obb, me = this_player();
        int i;
        mapping jiang;
        string site;

        if (! mapp(jiang = me->query_temp("jun_quest/jiang")))
                return notify_fail("你没有任命过任何将领，如何点将？！\n");  

        message_vision(HIR"$N召来传令兵，下令道：火速传令各营统领到本帅帐前候令！！\n", me);

        for (i = 0; i < sizeof(jiang); i++)
        {
                obb = me->query_temp("jun_quest/jiang/jiang" + (i + 1));
                
                if (objectp(obb) && ! obb->query_temp("jun_quest/escort")
                &&  ! obb->query_temp("jun_quest/chuzheng")
                &&  sscanf(file_name(environment(obb)), "/quest/quest_jun/sy%s", site) == 1)
                {
                        message_vision(HIR "一位传令兵急匆匆得赶来对$N道：三军将领" +
                                       "火速至元帅帐营侯令！！\n" NOR, obb);
                        call_out("go_back", 5, obb);
                }
        }

        return 1;
}

void go_back(object obb)
{
        object me = this_player();
        if (objectp(obb))
        {
                message_vision(HIY "$N赶忙批盔带甲，赶至元帅帐营，还好没误了时" +
                               "辰。\n" NOR, obb, me);
                obb->move(__DIR__"sying1");
        }
        return;
} 



