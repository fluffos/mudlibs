void reporting (object who, string reason, int points, string name)
{
  	string str = reason+"得到了"+to_chinese(points)+name+"。\n";
	MONITOR_D->report_system_object_msg (who, str);
}

void unconcious()
{
	powerup(1);
	return;
}
void die()
{
    unconcious();
}

