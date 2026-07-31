// SN:gc2>Fe\5N^B53;fY
// check recruit

int permit_recruit(object ob)
{
        if( ob->query("detach/逍遥派") || ob->query("betrayer/逍遥派") )
        {
                command("say 你当年都已经离开了逍遥派，何必又要回来？");
                return 0;
        }

        if( ob->query("betrayer/times") && ob->query("weiwang") < 5000000 )
        {
                command("say 我们逍遥派乃名门正派，除非是江湖上德高望重之辈，决不收判师之徒！");
                return 0;
        }

        if( ob->query("family/family_name") &&
            ob->query("family/family_name") != "逍遥派" )
        {
                if( ob->query("betrayer/times") && ob->query("weiwang") > 5000000 )
                {
                        command("say 既然德高往重的你有意加入逍遥派，我也勉为其难成全你吧！");
                        return 1;
                }

                command("say 你既然已经有了名师指点，不好好学习，来我们逍遥派作甚？");
                return 0;
        }

        return 1;
}
