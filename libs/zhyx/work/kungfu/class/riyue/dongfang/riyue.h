
int permit_recruit(object ob)
{
        if (ob->query("detach/日月神教") || ob->query("betrayer/日月神教"))
        {
                command("say 你当年既然已经离开了黑木崖，今日何必又要回来？");
                return 0;
        }

        if (ob->query("betrayer/times"))
        {
                command("say 我日月神教即日便一统江湖，可不招收你这样的背信弃义之徒。");
                return 0;
        }

        if (ob->query("family/family_name") &&
            ob->query("family/family_name") != "日月神教")
        {
                command("say 你既然已经有了师承，又来我日月神教来干嘛？");
                return 0;
        }

        return 1;
}
