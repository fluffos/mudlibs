int permit_recruit(object ob)
{
  if( ob->query("detach/火云洞") ||
      ob->query("betrayer/火云洞") )
  {
    command("say 离开了火云洞就不要再回来！\n");
    return 0;
  }

  if( ob->query("detach/times") ||
      ob->query("betrayer/times"))
  {
    command("say 嘿嘿，不忠不义之人，我们火云洞不收。\n");
    return 0;
  }

  if( ob->query("family/family_name") &&
      ob->query("family/family_name") != "火云洞" )
  {
    command("say 你已经有了师傅！\n");
    return 0;
  }

  return 1;
}

