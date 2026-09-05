#pragma save_binary

inherit ITEM;

void create()
{
        set_name("当铺修改", ({ "shop changer"}));
        set_weight(600);
        set("unit", "个");

        
		
}
void init()
{
	add_action("do_change","change");
}

int do_change(string arg)
{
    int num;
    object box;
    mapping numbers;
    string* names;
    int i =0;
    
    if(!arg) return notify_fail("请输入数字\n");
    sscanf(arg,"%d",num);
    box = present("treasure box",environment(this_player()));
    if(!objectp(box)) return notify_fail("没有聚宝盒啊.\n");
    numbers = box->query_temp("numbers");
    names = keys(numbers);
    for(i=0;i<sizeof(names);i++)
    {
        numbers[names[i]] = num;
    }
    box->set_temp("numbers",numbers);
    write("ok\n");
    return 1;
}

