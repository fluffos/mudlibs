int permit_recruit(object ob)
{
  if( ob->query("detach/东海龙宫") ||
      ob->query("betrayer/东海龙宫") )
  {
    command("say 离开了东海龙宫就不要再回来！\n");
    return 0;
  }

  if( ob->query("detach/times") ||
      ob->query("betrayer/times"))
  {
    command("say 我东海龙宫怎么可以接收不忠不义的人呢。\n");
    return 0;
  }

  if( ob->query("family/family_name") &&
      ob->query("family/family_name") != "东海龙宫" )
  {
    command("say 你有了师傅，就不要来我们东海龙宫了！\n");
    return 0;
  }

  return 1;
}

