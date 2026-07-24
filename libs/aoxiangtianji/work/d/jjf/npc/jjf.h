int permit_recruit(object ob)
{
  if( ob->query("detach/将军府") ||
      ob->query("betrayer/将军府") )
  {
    command("say 离开了将军府就不要再回来！\n");
    return 0;
  }

  if( ob->query("detach/times") ||
      ob->query("betrayer/times"))
  {
    command("say 阁下不忠不信，我们将军府最恨的就是你这种人。\n");
    return 0;
  }

  if( ob->query("family/family_name") &&
      ob->query("family/family_name") != "将军府" )
  {
    command("say 你有了师傅，就不要来我们将军府了！\n");
    return 0;
  }

  return 1;
}

