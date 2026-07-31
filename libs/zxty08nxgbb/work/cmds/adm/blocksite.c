#include <net/dns.h>
#include <net/macros.h>

int help(object me)
{
        write("\n指令格式：\n"
                "          blocksite <MudName> 过滤MudName的信息，如ES。\n\n"
        );
        return 1;
}
int main(object me, string arg)
{
        mixed *muds;
        mapping mud_list;
        string str;

        if( !find_object(DNS_MASTER) )
                return notify_fail("网路精灵并没有被载入。\n");
                
        mud_list = (mapping)DNS_MASTER->query_muds();
        if(!mud_list)
                return notify_fail( MUD_NAME + "目前并没有跟网路上其他 Mud 取得联系。\n");
        muds = keys( mud_list ) - ({ "DEFAULT" });
        if(arg ) {
                str = htonn(arg);
                if(!mapp( mud_list[str] )) {
                        write(MUD_NAME + "并没有和这个 Mud 取得联系。\n");
                        return 1;
                }
                if (GCHANNEL->is_Block(arg)){
                    GCHANNEL->remove_Block(arg);
                    write("取消对"+arg + "的过滤。\n");
                }else{
                    GCHANNEL->add_Block(arg);
                    write(arg + "设为不受欢迎的mud。\n");
                }
                return 1;
        }
        return help(me);
}

