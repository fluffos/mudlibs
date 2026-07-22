// condition.c
//rewrite by lonely@wmkj
// Modified by Xiang for XKX (12/15/95)
#include <condition.h>
mapping conditions;
// This function is called by heart_beat to update "continously active"
// conditions. These conditions will be saved as well. Because such type
// of conditions costs heart beat evaluation time, don't make player got
// too much this kind of conditions or you might got lots fo "Too long
// evaluation" error message in the log file.
mapping query_conditions()
{
    return conditions;
}
nomask int update_condition()
{
    mixed *cnd, err;
    int i, flag, update_flag;
    object cnd_d;
    if( !mapp(conditions) || !(i=sizeof(conditions)) ) return 0;
//没有conditions或conditions为空,返回0;
//mapp() - 判断一个指定的变数是否为映射变数 (mapping).
    cnd = keys(conditions);
	//cnd保存的是目前conditions的种类
        //keys() - 传回在一个映射变数 (mapping) 中所有
        //(关键字, 内容值) (即 (key, value) ) 资料关键字的阵列 (array).

    update_flag = 0;
    while(i--) {
        // In order to not casue player lost heart beat occasionally while
        // calling external condition daemons, we take careful calling
        // convention here.
        cnd_d = find_object(CONDITION_D(cnd[i]));
		//find_object() - 以指定的档案名称寻找一个物件.
        if( !cnd_d ) {
            err = catch(call_other(CONDITION_D(cnd[i]), "???"));
            cnd_d = find_object(CONDITION_D(cnd[i]));
            // If we failed to load the external condition daemon, remove
            // it before we stuff log files with error messages.
            if( err || !cnd_d ) {
                log_file("condition.err",
                    sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
                        CONDITION_D(cnd[i]), this_object(), err)
                );
                map_delete(conditions, cnd[i]);
                continue;
            }
        }
        // We assume since the condition daemon is loaded successfully, the
        // calling on its update_condition() should success as well. Because
        // catch() is somewhat costly, so we don't attempt to catch possible
        // error from the call_other. It is condition daemon's reponsibility
        // that don't cause error in users's heart beat.
        // If condition daemon returns 0 (or update_condition() not defined),
        // we can just assume the condition expired and remove it.
        
        flag = call_other(cnd_d, "update_condition", this_object(), conditions[cnd[i]]);
		//call_other成功的话,且这种conditions没有到头,flag=CAN_CONTINUE,否则flay=0
//        if( conditions[cnd[i]]<1 ) map_delete(conditions, cnd[i]); by lonely 取消
		if(!( flag & CND_CONTINUE )) map_delete(conditions, cnd[i]);//add by lonely
        update_flag |= flag;
    }
    if( !sizeof(conditions) ) conditions = 0;
    return update_flag;
}
// apply_condition()
//
// This function applies the specific condition to the character. Note we 
// don't check if the condition already exist before setting condition info.
// It is condition giver's reponsibility to check if the condition should
// override the old one if same condition already exists.(Use query_condition
// to check)
nomask void apply_condition(string cnd, mixed info)
//此函数用于给ob加上condition,小心覆盖
{
    if( !mapp(conditions) )
        conditions = ([ cnd : info ]);
    else
        conditions[cnd] = info;
}
// query_condition()
//
// This function returns info about the specific condition if any.
nomask mixed query_condition(string cnd)
//返回condition的情况
{
    if( !mapp(conditions) || undefinedp(conditions[cnd]) ) return 0;
    return conditions[cnd];
}
 
//因为出现类似clear_condition("menpai_busy")导致所有的condition被clear,故下面的我改写了
//by lonely@wmkj
/*
// flag==1,因死亡而清除中毒
nomask void clear_condition(int flag)
//清condition
{
    int i;
        string *cnd;
    if( !mapp(conditions) || !(i=sizeof(conditions)) )
                return;
    cnd = keys(conditions);
        while (i--) {
        
// 投票限制不能被清除
                if ( cnd[i]=="vote_clear"
                || cnd[i]=="vote_suspension")
                                continue;

                if (!flag)
// 非死亡不能清除的部分中毒                             
                  if (cnd[i]=="killer" 
                || cnd[i]=="bonze_drug"
                || cnd[i]=="bonze_jail")
                            continue;
                map_delete(conditions, cnd[i]);
        }

     conditions = 0;  // by lonely
}

*/
nomask varargs void clear_condition( string cnd )
//清condition
{
        if (!cnd)
                conditions = 0;
        else if (!mapp(conditions) || undefinedp(conditions[ cnd ]))
                return;
        else
                map_delete(conditions, cnd);
}


