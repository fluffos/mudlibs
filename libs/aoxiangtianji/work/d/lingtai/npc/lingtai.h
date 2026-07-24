int permit_recruit(object ob)
{
  if( ob->query("detach/方寸山三星洞") ||
      ob->query("betrayer/方寸山三星洞") )
  {
    command("say 离开了方寸山三星洞就不要再回来！\n");
    return 0;
  }

  if( ob->query("detach/times") ||
      ob->query("betrayer/times"))
  {
    command("say 我方寸山三星洞最恨的就是你这种不忠不义的人。\n");
    return 0;
  }

  if( ob->query("family/family_name") &&
      ob->query("family/family_name") != "方寸山三星洞" )
  {
    command("say 你有了师傅，就不要来我们方寸山三星洞了！\n");
    return 0;
  }

  return 1;
}

