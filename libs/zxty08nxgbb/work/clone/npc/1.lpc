        if (job=me->query("quest"))
str=sprintf("%s的任务是：%s内%s%s，",2>1?"你":me->query("name"),time_period(job["time"]),job["job_type"],job["job"]);
        if (job["task_time"]<time())
    {
                str+=sprintf("%s已经没有足够的时间完成它了。\n",2>1?"你":me->query("name"));
}
        else
{
                str+=sprintf("%s还有%s的时间去完成它。\n",2>1?"你":me->query("name"),time_period(job["task_time"]-time()));
        write(str);
        return 1;
}

