// wudu.h

int permit_recruit(object ob)
{
        if( query("detach/天下会", ob) || query("betrayer/天下会", ob) )
        {
                command("say 你既然已经离会，就别再回来！");
                return 0;
        }

        if( query("betrayer/times", ob) )
        {
                command("say 判师之徒，唉！你走吧！");
                return 0;
        }

        if( query("family/family_name", ob) && 
            query("family/family_name", ob) != "天下会" )
        {
                command("say 你不是已经有了师傅么，还来干什么？你不该来的？");
                return 0;
        }

        if( query("family/master_name", ob) == "雄霸" )
        {
                command("sneer");
                command("say 既然你想跟随他学习,那就先死吧!");
                return 0;
        }

        return 1;
}
