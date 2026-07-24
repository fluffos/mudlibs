int permit_recruit(object ob)
{
  if( ob->query("detach/阎罗地府") ||
      ob->query("betrayer/阎罗地府") )
  {
    command("say 离开了阎罗地府就不要再回来！");
    return 0;
  }

  if( ob->query("detach/times") ||
      ob->query("betrayer/times"))
  {
    command("say 我阎罗地府怎么可以接收不忠不义的人呢。");
    return 0;
  }

  if( ob->query("family/family_name") &&
      ob->query("family/family_name") != "阎罗地府" )
  {
    command("say 你有了师傅，就不要来我们阎罗地府了！");
    return 0;
  }

  return 1;
}

