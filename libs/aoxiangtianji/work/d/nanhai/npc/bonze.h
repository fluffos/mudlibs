int permit_recruit(object ob)
{
  if( ob->query("detach/南海普陀山") ||
      ob->query("betrayer/南海普陀山") )
  {
    command("say 离开了南海普陀山就不要再回来！\n");
    return 0;
  }

  if( ob->query("detach/times") ||
      ob->query("betrayer/times"))
  {
    command("say 阁下不忠不信，南海普陀山是无法容纳的了。\n");
    return 0;
  }

  if( ob->query("family/family_name") &&
      ob->query("family/family_name") != "南海普陀山" )
  {
    command("say 你有了师傅，就不要来我们南海普陀山了！\n");
    return 0;
  }

  return 1;
}

