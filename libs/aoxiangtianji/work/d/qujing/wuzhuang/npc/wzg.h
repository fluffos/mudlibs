int permit_recruit(object ob)
{
  if( ob->query("detach/五庄观") ||
      ob->query("betrayer/五庄观") )
  {
    command("say 离开了五庄观就不要再回来！\n");
    return 0;
  }

  if( ob->query("detach/times") ||
      ob->query("betrayer/times"))
  {
    command("say 嘿嘿，不忠不义之人，我们五庄观不收。\n");
    return 0;
  }

  if( ob->query("family/family_name") &&
      ob->query("family/family_name") != "五庄观" )
  {
    command("say 你已经有了师傅！\n");
    return 0;
  }

  return 1;
}

