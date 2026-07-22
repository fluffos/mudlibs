// MingJiao.h for all npc of mingjiao

int permit_recruit(object ob)
{
/*
        command("say 我不收徒。");
        return 0;
*/
        return 1;
}

int recognize_apprentice(object ob, string skill)
{
        object me = this_object();
        mapping ob_fam;

        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "明教")
        {
                command("say " + RANK_D->query_respect(ob) + "与本教素无来往，不知此话从何谈起？

");
                return -1;
        }

        if ( ob_fam["generation"] <= (int)me->query("family/generation") )
        {
                return 1;
        }

        return 0;
}

