// qingcheng.h

int permit_recruit(object ob)
{
        if( ob->query("detach/青城派") || 
            ob->query("betrayer/青城派") )
        {
                command("say 亏你还有脸回我青城派？给我滚开！");
                return 0;
        }

        if( ob->query("betrayer/times") )
        {
                command("say 阁下不忠不信，我最痛恨你这种人了。");
                return 0;
        }

        if( ob->query("family/family_name") && 
            ob->query("family/family_name") != "青城派" )
        {
                command("say 阁下既有了名师指点，还来我们青城派做什么？");
                return 0;
        }

        return 1;
}
