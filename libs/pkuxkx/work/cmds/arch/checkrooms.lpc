// overview.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object *ob;
        int i, m;

        ob = objects( (: function_exists("create_door", $1) :) );

        i = sizeof(ob);
        while(i--)
        {
        		if (sizeof(all_inventory(ob[i])) > 100)
			        printf("房间%s (%s)的物品大于一百个。\n", ob[i]->query("short"),file_name(ob[i]));
        			
        }
        return 1;
}

int help()
{
        write(@TEXT
指令格式：checkrooms

本命令用于查看房间中物品大于100个的房间。
TEXT
        );
        return 1;
}


