string *shoes = ({
    "薄底快靴", "麻鞋", GRN"葱绿绣花鞋"NOR, "皮靴", 
    MAG"细碎紫花鞋"NOR, "丝鞋", "四缝干黄靴", "弓鞋", "四缝宽靴",
});

string *food = ({
    "生肉蒸饺", "翡翠烧卖", "干菜包子", "生肉包子", "荠菜包子",
    "糯米烧卖", "水晶包子", "三丁包子", "笋肉包子", "蟹黄包子",
    "小菜包子", "稀沙包子", "千层油糕", "芝麻包子", "火腿粽子",
    "鸭菜包子", RED"红烧狗肉"NOR,
});

string *fruit = ({
    YEL"橘子"NOR, YEL"杏子"NOR, HIG"哈蜜瓜"NOR, GRN"西瓜"NOR,
    MAG"甘蔗"NOR, HIG"香瓜"NOR, HIR"草莓"NOR, HIM"桃子"NOR,
    HIR"石榴"NOR, YEL"菠萝"NOR, MAG"葡萄"NOR, HIY"香蕉"NOR,
    HIR"樱桃"NOR, YEL"枇杷"NOR, MAG"李子"NOR, RED"杨梅"NOR,
    HIG"柠檬"NOR, HIY"鸭梨"NOR,
});

string *tea = ({
    "花茶", "绿茶", "沱茶", "磨锅茶", "红茶", "龙井茶", "富春茶", "魁尖茶",
});

string *pot = ({
    "白瓷茶壶", "茶壶", "彩瓷茶壶", "紫瓷茶壶", "茶杯", 
});

string *cloth = ({
    "直缝宽衫", RED"桃花撒花袄"NOR, "白苎丝袍", "纱布直缀", HIR"银红红衫子"NOR,
    YEL"淡黄纱衣"NOR, "白缎衫", "湖蓝衲袄", GRN"嫩绿绸衫"NOR, "麻布宽衫", 
});

string *cap = ({
    "麻布头巾", "万字巾", "红缨毡帽", "范阳毡大帽", "三山帽", GRN"青纱抓角头巾"NOR,
    "皂纱转角簇花巾", "遮尘暖帽", "一字巾",
});

mapping query_quest()
{
    string name;
    int random_num, quest_num;

    quest_num = sizeof(quest);
    random_num = random(quest_num + 7);

    if ( random_num < quest_num )
    {
        return quest[random_num];
    }

    if ( random_num == quest_num )
    {
        name = shoes[random(sizeof(shoes))];
        return
           ([
                "quest":                "取" + name ,
                "time":                 400 + random(200),
                "bonus":                5 + random(15),
                "quest_msg":
"$N笑了一声，说：“府里丫鬟想找双" + name + "作样子，你就\n"
"去买一双回来吧。”\n",
                "reward_msg":
"$N点了点头说：“嗯，这么快就回来了，不错、不错。”\n",
                "delay_msg":
"$N叹了口气道：“叫你出门办事，就应快去快回，年青人也太过贪\n"
"玩了。”\n",
        ]); 
    }

    if ( random_num == quest_num + 1)
    {
        name = food[random(sizeof(food))];
        return
        ([      "quest":                "取" + name,
                "time":                 300 + random( 300 ),
                "bonus":                6 + random(10),
                "quest_msg":
"$N想了想说道：“要端午节了，府里要" + name + "，你这就\n"
"去买一点回来吧。”\n",
                "reward_msg":
"$N拿起一个" + name + "看了看，点头道：“好好，就是这种。”\n",
        ]);
    }            

    if ( random_num == quest_num + 2)
    {
        name = fruit[random(sizeof(fruit))];
        return
        ([      "quest":                "取" + name,
                "time":                 200 + random( 400 ),
                "bonus":                7 + random(10),
                "quest_msg":
"$N笑了一声，说：“府里让买点" + name + "做点夏天的水果盘，你这就去买一\n"
"点回来吧。”\n",
                "reward_msg":
"$N点了点头说：“这" + name + "倒还新鲜，你练功去吧。”\n",
        ]);
    }  

    if ( random_num == quest_num + 3)
    {
        name = tea[random(sizeof(tea))];
        return
        ([      "quest":                "取" + name,
                "time":                 150 + random( 450 ),
                "bonus":                2 + random(15),
                "quest_msg":
"$N说：“你去买点" + name + "回来吧，听总管说茶已经不多了。”\n",
                "reward_msg":
"$N拿起" + name + "看了看，“嗯，这" + name + "不太好，不过也将就了。你下去\n"
"休息吧。”\n",
        ]);
    }             

    if ( random_num == quest_num + 4)
    {
        name = pot[random(sizeof(pot))];
        return
        ([      "quest":                "取" + name,
                "time":                 100 + random( 500 ),
                "bonus":                4 + random(15),
                "quest_msg":
"$N沉吟了一下：“前两天客厅的" + name + "打破了，你去买个新的\n"
"回来吧。”\n",
                "reward_msg":
"$N仔细端详了一下，皱皱眉头：“好象有点瑕疵啊？...算了吧...”\n",
        ]);
    }

    if ( random_num == quest_num + 5)
    {
        name = cloth[random(sizeof(cloth))];
        return
           ([      "quest":                "取" + name ,
                "time":                 200 + random(300),
                "bonus":                8 + random(10),
                "quest_msg":
"$N想了一想，说：“府里丫鬟想找件" + name + "作样子，你就\n"
"去买一件回来吧。”\n",
                "reward_msg":
"$N点了点头说：“嗯，这么快就回来了，不错、不错。”\n",
                "delay_msg":
"$N叹了口气道：“叫你出门办事，就应快去快回，年青人也太过贪\n"
"玩了。”\n",
        ]); 
    }             

    if ( random_num == quest_num + 6)
    {
        name = cap[random(sizeof(cap))];
        return
           ([      "quest":                "取" + name ,
                "time":                 120 + random(480),
                "bonus":                8 + random(10),
                "quest_msg":
"$N想了一想，说：“府里丫鬟想找顶" + name + "作样子，你就\n"
"去买一顶回来吧。”\n",
                "reward_msg":
"$N点了点头说：“嗯，这么快就回来了，不错、不错。”\n",
                "delay_msg":
"$N叹了口气道：“叫你出门办事，就应快去快回，年青人也太过贪\n"
"玩了。”\n",
        ]); 
    }
}

