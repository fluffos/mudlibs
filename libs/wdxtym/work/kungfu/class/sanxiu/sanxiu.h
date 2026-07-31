int permit_recruit(object ob)
{
        if( ob->query("detach/散修") || 
            ob->query("betrayer/散修") )
        {
                command("say 离开了散修就不要再回来！");
                return 0;
        }

        if( ob->query("betrayer/times") )
        {
                command("say 阁下不忠不信，我们散修最恨的就是你这种人。");
                return 0;
        }

        if( ob->query("family/family_name") && 
            ob->query("family/family_name") != "散修" )
        {
                command("say 你有了师傅，就不要来我们散修了！");
                return 0;
        }

        return 1;
}