void greeting(object ob)
{

        if ((string)ob->query("family/family_name") == "神龙教")
                if ((string)ob->query("family/master_name") == "洪安通")
                {
                        command("bow " + ob->query("id"));
                        command("say 洪教主万年不老!永享仙福!寿与天齐!文武仁圣！");
                        command("say " +ob->query("rank_info/respect") + "您英明神武，定会将教主的武功发扬光大。");
                        return;
                }
                else
                {
                        command("say 洪教主万年不老!永享仙福!寿与天齐!文武仁圣！");
                        return;
                }

}
