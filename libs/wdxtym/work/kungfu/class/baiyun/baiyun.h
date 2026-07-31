// check recruit  
//by y1
int permit_recruit(object ob)
{
              if (ob->query("detach/白云城") || ob->query("betrayer/白云城"))
        {
                command("say 你当年既然已经离开本城，现在何必又要回来？");
                return 0;
        }

        if (ob->query("betrayer/times"))
        {
                command("say 我白云城虽小，但是也不会接纳你这样的背信弃义之徒！");
                return 0;
        }

        if (ob->query("family/family_name") &&
            ob->query("family/family_name") != "白云城" )

        {
                command("say 你既然已经有了名师指点，还来我们白云城干嘛？");
                return 0;
        }

        return 1;
}




 