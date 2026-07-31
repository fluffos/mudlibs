// SN:clJVO7n84=PnYLgS
int permit_recruit(object ob)
{
        if( ob->query("detach/明教") ||
            ob->query("betrayer/明教") )
        {
                command("say 离开了明教就不要再回来！");
                return 0;
        }

        if( ob->query("betrayer/times") )
        {
                command("say 阁下不忠不信，我们明教最恨的就是你这种人。");
                return 0;
        }

        if( ob->query("family/family_name") &&
            ob->query("family/family_name") != "明教" )
        {
                command("say 你有了师傅，就不要来我们明教了！");
                return 0;
        }

        return 1;
}
