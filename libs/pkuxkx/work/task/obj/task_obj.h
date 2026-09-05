void init()
{
    if (userp(this_player()))
    {
         if (!objectp(this_object()->query("getter")) && (environment() == this_player()))
	{
		this_object()->set("getter",this_player());
		this_object()->set("gettername",this_player()->name() + "(" + this_player()->query("id") + ")");
	}
        call_out("destroying",180);
	return;
    }
}

void destroying()
{
	write(this_object()->query("name") + "悄悄地滑落在路边草丛中，再也找不到了。\n");
	if (objectp(this_player()))
	if (this_object()->query("getter") == this_player())
	{
		write("你绝望地开始在草丛中胡乱寻找，妄图找回宝物......\n");
                this_player()->start_busy(random(50));
	}
	TASK_D->task_lost(this_object(),this_object()->query("gettername"));
	destruct(this_object());
	return;
}

//判定是否是task任务物品
int is_task()
{
  return 1;
}

void ext_calldest()
{
  call_out("destroying",180);
}