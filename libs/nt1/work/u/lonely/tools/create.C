        index1 = random(sizeof(first_name));
        index2 = random(sizeof(first_name));        
        name1 = first_name[index1]["name"];
        name2 = first_name[index2]["name"];
        id1 = first_name[index1]["id"];
        id2 = first_name[index2]["id"];
        idf1 = id1;
        idf2 = id2;
        
        if (query("family/family_name") == "Ä½ÈÝÊÀ¼Ò")
        {
                name1 = "Ä½ÈÝ";
                name2 = "Ä½ÈÝ";
                id1 = "murong";
                id2 = "murong";
        } else
        if (query("family/family_name") == "Å·ÑôÊÀ¼Ò")
        {
                name1 = "Å·Ñô";
                name2 = "Å·Ñô";
                id1 = "ouyang";
                id2 = "ouyang";
        } else
        if (query("family/family_name") == "¹ØÍâºú¼Ò")
        {
                name1 = "ºú"
                name2 = "ºú"
                id1 = "hu";
                id2 = "hu";
        } else
        if (query("family/family_name") == "¶ÎÊÏ»Ê×å")
        {
                name1 = "¶Î";
                name2 = "¶Î";
                id1 = "duan";
                id2 = "duan";
        }
                                        
        index1 = random(sizeof(second_name1));
        index2 = random(sizeof(second_name2));
        name1 += second_name1[index1]["name"];
        name2 += second_name2[index2]["name"];
        id1 += " " + second_name1[index1]["id"];
        id2 += " " + second_name2[index2]["id"];

        index1 = random(sizeof(third_name1));
        index2 = random(sizeof(third_name2));
        name1 += third_name1[index1]["name"];
        name2 += third_name2[index2]["name"];
        id1 += third_name1[index1]["id"];
        id2 += third_name2[index2]["id"];

        set_name(name1, ({ id1, idf1 }));

        index = random(sizeof(menpai));
        mp = menpai[index];
        if (mp["gender"]) set("gender", mp["gender"]);
        if (query("gender")=="Å®ÐÔ") 
                set_name(name2,({id2, idf2}));
        if (mp["class"]) set("class", mp["class"]);
        if (me->query("shen") > 0) 
                set("title", mp["title1"]);
        else 
        if (me->query("shen") < 0) 
                set("title", mp["title2"]);
        else 
        {
                if (random(2))
                        set("title", mp["title1"]);
                else
                        set("title", mp["title2"]);
        }
        