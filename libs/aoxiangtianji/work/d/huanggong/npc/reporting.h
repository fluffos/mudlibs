void reporting (object who, string reason, int points, string name)
{
  string str = reason+"得到了"+to_chinese(points)+name+"。\n";
  MONITOR_D->report_system_object_msg (who, str);
}

void receive_damage(string type)
{
  return;
}

void receive_wound(string type)
{
  return;
}

void unconcious()
{
}

void die()
{
  unconcious();
}

