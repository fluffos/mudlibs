void skill_adjust(object ob)
{
        mapping skl;
        string *sname;
        int i=3, lmt;

        lmt = (int)ob->query("combat_exp");
        if (lmt < 0) lmt = 0;
        if (ob->query("shen") > lmt) ob->set("shen", lmt);
        if (ob->query("shen") < -lmt) ob->set("shen", -lmt);
        if (ob->query("reputation") > lmt) ob->set("reputation", lmt);
        for (;i*i*i/10<=lmt;i++);
        lmt = i;
//      ob->set("max_pot", 100 + lmt);
//      if (ob->query("potential") > ob->query("max_pot"))
//              ob->set("potential", ob->query("max_pot"));
        skl = ob->query_skills();
        if (!sizeof(skl))
                return;
        sname = keys(skl);
        for (i = 0; i < sizeof(skl); i++) {
                if (!intp(skl[sname[i]])) skl[sname[i]] = 0;
                if (SKILL_D(sname[i])->type() == "martial" && skl[sname[i]] > lmt)
                        skl[sname[i]] = lmt;
        }
        switch (ob->query("family/family_name")) {
                case "昆仑派":
                        if (skl["art"] > 81) {
                                ob->add("max_jing",
                                        (skl["art"]/2-40)*(skl["xuantian-wuji"]/15));
                                ob->add("max_qi",
                                        (skl["art"]/2-40)*(skl["xuantian-wuji"]/15));
                        }
                        break;
                case "少林派":
                        if (skl["buddhism"] > 61)
                                ob->add("max_jing",(skl["buddhism"]/2-30)*(skl["hunyuan-yiqi"]/10));
                        if (skl["buddhism"] > 121)
                                ob->add("max_qi",(skl["buddhism"]/2-50)*(skl["hunyuan-yiqi"]/20));
                        break;
                case "峨嵋派":
                        if (skl["dacheng-fofa"] > 61)
                                ob->add("max_jing",(skl["mahayana"]/2-30)*(skl["linji-zhuang"]/10));
                        if (skl["dacheng-fofa"] > 101)
                                ob->add("max_qi",(skl["mahayana"]/2-40)*(skl["linji-zhuang"]/20));
                        break;
                case "桃花岛":
                        if (skl["qimen-bagua"] > 61){
                                ob->add("max_qi", (skl["qimen-wuxing"]/2-30)*(skl["bibo-shengong"]/20));
                                ob->add("max_jing", (skl["qimen-wuxing"]/2-30)*(skl["bibo-shengong"]/20));
                                }
                        break;
                case "武当派":
                        if (skl["taoism"] > 61)
                                ob->add("max_qi",(skl["taoism"]/2-30)*(skl["taiji-shengong"]/10));
                        if (skl["taoism"] > 121)
                                ob->add("max_jing",(skl["taoism"]/2-50)*(skl["taiji-shengong"]/25));
                        break;
                case "镇南王府":
                        if (skl["buddhism"] > 61)
                                ob->add("max_jing",(skl["buddhism"]/2-30)*(skl["kurong-changong"]/10));
                        if (skl["buddhism"] > 121)
                                ob->add("max_qi",(skl["buddhism"]/2-50)*(skl["kurong-changong"]/20));
                        break;
                case "天龙寺":
                        if (skl["buddhism"] > 61)
                                ob->add("max_jing",(skl["buddhism"]/2-30)*(skl["kurong-changong"]/10));
                        if (skl["buddhism"] > 121)
                                ob->add("max_qi",(skl["buddhism"]/2-50)*(skl["kurong-changong"]/20));
                        break;
                case "星宿派":
                        if (skl["poison"] > 61)
                                ob->add("max_qi",(skl["poison"]/2-30)*(skl["huagong-dafa"]/10));
                        if (skl["poison"] > 121)
                                ob->add("max_jing",(skl["poison"]/2-50)*(skl["huagong-dafa"]/20));
                        break;
                case "白驼山派":
                        if (skl["hamagong"] > 81)
                                ob->add("max_qi",(skl["hamagong"]/2-40)*15);
                        if (skl["hamagong"] > 151)
                                ob->add("max_jing",(skl["hamagong"]/2-40)*15);
                        break;
                case "移花宫":
                        if (skl["mingyu-shengong"] > 81)
                                ob->add("max_qi",(skl["mingyu-shengong"]/2-40)*15);
                        if (skl["bahuang-gong"] > 151)
                                ob->add("max_jing",(skl["mingyu-shengong"]/2-40)*15);
                        break;
                case "逍遥派":
                        if (skl["beiming-shengong"] > 81)
                                ob->add("max_qi",(skl["beiming-shengong"]/2-40)*15);
                        if (skl["bahuang-gong"] > 151)
                                ob->add("max_jing",(skl["beiming-shengong"]/2-40)*15);
                        break;
                case "灵鹫宫":
                        if (skl["bahuang-gong"] > 81)
                                ob->add("max_qi",(skl["bahuang-gong"]/2-40)*15);
                        if (skl["bahuang-gong"] > 151)
                                ob->add("max_jing",(skl["bahuang-gong"]/2-40)*15);
                        break;
                case "姑苏慕容":
                        if (skl["shenyuan-gong"] > 81)
                                ob->add("max_qi",(skl["shenyuan-gong"]/2-40)*15);
                        if (skl["shenyuan-gong"] > 151)
                                ob->add("max_jing",(skl["shenyuan-gong"]/2-40)*15);
                        break;
                case "丐帮":
                        if (ob->query("DIED") > 1){
                                ob->add("max_qi", ob->query("DIED") * ob->query("con"));
                                ob->add("max_qi", ob->query("DIED") * ob->query("con"));
                                }
                        break;
                case "明教":
                        if (skl["shenghuo-shengong"] > 81)
                                ob->add("max_qi",(skl["shenghuo-shengong"]/2-40)*15);
                        if (skl["qiankun-danuoyi"] > 81)
                                ob->add("max_jing",(skl["qiankun-danuoyi"]/2-40)*15);
                        break;
                case "密宗":
                        if (skl["mizong-xinfa"] > 61)
                                ob->add("max_jing",(skl["mizong-xinfa"]/2-30)*(skl["longxiang"]/10));
                        if (skl["mizong-xinfa"] > 121)
                                ob->add("max_qi",(skl["mizong-xinfa"]/2-50)*(skl["longxiang"]/20));
                        break;
                case "华山派":
                        if (skl["ziyin-yin"] > 61)
                                ob->add("max_jing",(skl["ziyin-yin"]/2-30)*(skl["zixia-shengong"]/10));
                        if (skl["zhengqi-jue"] > 61)
                                ob->add("max_qi",(skl["zhengqi-jue"]/2-50)*(skl["zixia-shengong"]/20));
                        break;
                case "古墓派":
                        if (skl["yunu-xinjing"] > 81)
                                ob->add("max_qi",(skl["yunu-xinjing"]/2-40)*10);
                        if (skl["yunu-xinjing"] > 81)
                                ob->add("max_jing",(skl["yunu-xinjing"]/2-40)*15);
                        break;
//                  case "嵩山派":
//                      if (skl["songshan-qigong"] > 81)
//                              ob->add("max_qi",(skl["songshan-qigong"]/2-40)*8);
//                        if (skl["songshan-qigong"] > 81)
//                              ob->add("max_jing",(skl["songshan-qigong"]/2-40)*5);
//                      break;
                case "全真教":
                        if (skl["taoism"] > 61)
                                ob->add("max_qi",(skl["taoism"]/2-30)*(skl["tiangang-zhengqi"]/10));
                        if (skl["taoism"] > 121)
                                ob->add("max_jing",(skl["taoism"]/2-50)*(skl["tiangang-zhengqi"]/25));
                        break;
//                  case "铁掌帮":
//                      if (skl["guiyuan-tunafa"] > 81)
//                              ob->add("max_qi",(skl["guiyuan-tunafa"]/2-40)*15);
//                        if (skl["guiyuan-tunafa"] > 81)
//                              ob->add("max_jing",(skl["guiyuan-tunafa"]/2-40)*15);
//                      break;
                        } 
}

