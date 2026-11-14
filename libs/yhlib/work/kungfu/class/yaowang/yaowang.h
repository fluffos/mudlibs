// yaowang.h

int permit_recruit(object ob)
{
        if( ob->query("detach/药王谷") ||
            ob->query("betrayer/药王谷") )
        {
                command("say 你既然已经离开了药王谷，干嘛又要回来？");
                return 0;
        }

        if( ob->query("betrayer/times") )
        {
                command("say 阁下不忠不信，我们药王谷虽小，但却不收弃师之徒。");
                return 0;
        }

        if( ob->query("family/family_name") &&
            ob->query("family/family_name") != "药王谷" )
        {
                command("say 你既有了名师指点，就要勤下苦功，勿要三心二意！");
                return 0;
        }

        return 1;
}
