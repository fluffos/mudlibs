void init()
{
        add_action("do_look","look");
        add_action("do_type","type");
}

int do_look(string arg)
{
        int i;
        string msg;
        mapping *bang_quest,*bang_zs;

        if (!arg || arg != "paizi")
                return 0;

        bang_zs = PARTY_QUEST_D->query_zhuisha_quest(TYPE);
        bang_quest = PARTY_QUEST_D->query_city_quest(PLACE,TYPE);
        bang_zs = sort_array(bang_zs,(: sort_by_id :));
        bang_quest = sort_array(bang_quest,(: sort_by_id :));

        msg = HIC "----------------------------------------------------------------------------\n"NOR;
        msg += WHT BBLU "                                  追杀令                                    \n"NOR;
        msg += HIC "----------------------------------------------------------------------------\n"NOR;
        msg += sprintf(HIR"%-10s%-50s%-10s%s\n"NOR,"编号","任务","难度","奖励");
        if (sizeof(bang_zs))
                for (i=0;i<sizeof(bang_zs);i++)
                        msg += sprintf("%-10s%-50s%-10s%s\n",
                                          bang_zs[i]["id"],
                                          "追杀"+bang_zs[i]["name"],
                                          bang_zs[i]["difficult"],
                                          bang_zs[i]["reward"],
                                      );
        msg += HIC "----------------------------------------------------------------------------\n"NOR;
        msg += WHT BBLU "                                  任务表                                    \n"NOR;
        msg += HIC "----------------------------------------------------------------------------\n"NOR;
        msg += sprintf(HIR"%-10s%-50s%-10s%s\n"NOR,"编号","任务","难度","奖励");
        if (sizeof(bang_quest))
                for (i=0;i<sizeof(bang_quest);i++)
                {
                        if (bang_quest[i]["id"] == "xc" && !bang_quest[i]["enable"]) continue;
                        msg += sprintf("%-10s%" + sprintf("%d", (50 + color_len(bang_quest[i]["name"]))) + "-s%-10s%s\n",
                                          bang_quest[i]["id"],
                                          bang_quest[i]["name"],
                                          bang_quest[i]["difficult"],
                                          bang_quest[i]["reward"],
                                      );
                }
        msg += HIC "----------------------------------------------------------------------------\n"NOR;
        msg += HIC "请用type <编号>查看每个任务的具体情况。\n"NOR;
        msg += HIC "请用choose <编号>选择你要完成的任务，放弃任务用giveup指令。\n"NOR;

        this_player()->start_more(msg);
        return 1;
}

int do_type(string arg)
{
        string msg;
        mapping bang_quest;

        if (!wizardp(this_player()) &&  
            (this_player()->query("bang_bad") || this_player()->query("shen") < 0))
                return notify_fail("你一个黑道人士到这里来查什么任务？\n");

        if (!wizardp(this_player()) && !this_player()->query("bang_good"))
                return notify_fail("你先加入白道联盟，才可以查看白道的任务。\n");

        if (!arg) 
                return notify_fail("你想查看哪条任务的详细信息？指令：type <编号>\n");

        bang_quest = PARTY_QUEST_D->query_zhuisha_quest(TYPE,arg);

        if (!bang_quest)     
                bang_quest = PARTY_QUEST_D->query_city_quest(PLACE,TYPE,arg);

        if (!bang_quest)
                return notify_fail("你所查询的编号为"+arg+"的任务并不存在。\n");
        
/*      if (bang_quest["id"] == "xc" && !bang_quest["enable"]) 
                return notify_fail("今天已经有弟兄去巡城了，你等改天吧。\n");
*/
        msg = HIC "\n----------------------------------------------------------------------------\n"NOR;
        msg += "任务编号：" + bang_quest["id"] + "\n";
        msg += "任务类型：" + bang_quest["type"] + "\n";
        msg += "任务名称：" + bang_quest["name"] + "\n";
        msg += "任务难度：" + bang_quest["difficult"] + "\n";
        msg += "任务奖励：" + bang_quest["reward"] + "\n";
        msg += "任务信息: \n" + bang_quest["msg"] + "\n";
        msg += HIC "----------------------------------------------------------------------------\n"NOR;
        this_player()->start_more(msg);
        return 1;
}

int sort_by_id(mapping quest1, mapping quest2)
{
          return strcmp(quest1["id"], quest2["id"]);
}


