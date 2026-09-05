// condition.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
// Modified by iszt@pkuxkx, 2007-05-09, added type for conditions
// ********************
// 原来模式下的所有 condition 总是按照 heart_beat 的安排，每间隔 5-14 个心跳，一起发作。
// 这种模式在发作时间上过于死板，没法自定义每一种 condition 的发作时间，也没法设置迅速发作的 dot 类型（比如每次心跳都发作）。
// 所以这里增加一个“不规则的毒” irregular_condition。要声明为“不规则毒”的，只需要在毒文件里 query_irregular_times() 返回非零值。
// 所有该类型的毒都交由 update_irregular_condition() 来处理，而 query_irregular_times() 的返回值表示间隔几个心跳发作一次。
// by lordstar 20180713
// ********************

#include <condition.h>

mapping conditions;
nosave mapping type_conditions;
//  “不规则的毒” irregular_condition 的标记
nosave mapping irregular;

// This function is called by heart_beat to update "continously active"
// conditions. These conditions will be saved as well. Because such type
// of conditions costs heart beat evaluation time, don't make player got
// too much this kind of conditions or you might got lots fo "Too long
// evaluation" error message in the log file.

nomask int update_condition()
{
	mixed *cnd, err;
	int i, flag, update_flag;
	object cnd_d;

	if( !mapp(conditions) || !(i=sizeof(conditions)) ) return 0;
	cnd = keys(conditions);
	update_flag = 0;
	while(i--) {
		
		// “不规则的毒” irregular_condition，跳过，由后面的 update_irregular_condition() 处理
		if (mapp(irregular) && mapp(irregular[cnd[i]]) && irregular[cnd[i]]["irr_flag"] > 0) continue;
		
		// In order to not casue player lost heart beat occasionally while
		// calling external condition daemons, we take careful calling
		// convention here.
		cnd_d = find_object(CONDITION_D(cnd[i]));
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
		if( !( flag & CND_CONTINUE ) ) map_delete(conditions, cnd[i]);
		update_flag |= flag;
	}
	if( !sizeof(conditions) ) conditions = 0;

	return update_flag;
}

nomask int update_irregular_condition()
{
	mixed *cnd, err;
	int i, flag, update_flag, irr_flag;
	object cnd_d;
	if( !mapp(irregular) || !(i=sizeof(irregular)) ) return 0;
	cnd = keys(irregular);
	update_flag = 0;
	while(i--) {
		if (undefinedp(conditions[cnd[i]]))
		{
			map_delete(irregular, cnd[i]);
			continue;
		}
		if (!mapp(irregular[cnd[i]])) continue;
		irr_flag = (int)irregular[cnd[i]]["irr_flag"];
		if (irr_flag<=0) continue;
		cnd_d = find_object(CONDITION_D(cnd[i]));
		if( !cnd_d ) {
			err = catch(call_other(CONDITION_D(cnd[i]), "???"));
			cnd_d = find_object(CONDITION_D(cnd[i]));
			if( err || !cnd_d ) {
				log_file("condition.err",
					sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
						CONDITION_D(cnd[i]), this_object(), err)
				);
				map_delete(conditions, cnd[i]);
				map_delete(irregular, cnd[i]);
				continue;
			}
		}
		if (irr_flag>1)
		{
			if (undefinedp(irregular[cnd[i]]["times"]))
				irregular[cnd[i]]["times"] = 1;
			else
				irregular[cnd[i]]["times"] += 1;
			if (irregular[cnd[i]]["times"] < irr_flag)
				continue;
			else
				irregular[cnd[i]]["times"] = 0;
		}
		flag = call_other(cnd_d, "update_condition", this_object(), conditions[cnd[i]]);
		if( !( flag & CND_CONTINUE ) ) 
		{
			map_delete(conditions, cnd[i]);
			map_delete(irregular, cnd[i]);
		}
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
{
	object cnd_d;
	int irr_flag;
	cnd_d = load_object(CONDITION_D(cnd));
	if( !cnd_d ) return;
	if( !mapp(conditions) )
		conditions = ([ cnd : info ]);
	else
		conditions[cnd] = info;
	irr_flag = cnd_d->query_irregular_times();
	if (irr_flag<=0)
	{
		if (mapp(irregular) && mapp(irregular[cnd]))
			map_delete(irregular, cnd);
	}
	else
	{
		if ( !mapp(irregular) )
			irregular = ([ cnd : ([ "irr_flag": irr_flag, "times": 0, ]) ]);
		else if (!mapp(irregular[cnd]))
			irregular[cnd] = ([ "irr_flag": irr_flag, "times": 0, ]);
		else 
			irregular[cnd]["irr_flag"] = irr_flag;
	}
}

// query_condition()
//
// This function returns info about the specific condition if any.

nomask mixed query_condition(string cnd)
{
	if( !mapp(conditions) ) return 0;
// 增加无参数时的功能：返回身上带着多少种异常状态。by lordstar 2017/9/5	
	if (!cnd) return sizeof(conditions);
	if (undefinedp(conditions[cnd])) return 0;
	return conditions[cnd];
}

nomask mapping query_conditions_by_type(string required_type)
{
	object cnd_d;
	int i;
	string cnd_type;
	mixed *cnd, err;

	if (!mapp(conditions) || !(i = sizeof(conditions))) return 0;
	type_conditions = 0;
	cnd = keys(conditions);
	while(i--) {

		// In order to not casue player lost heart beat occasionally while
		// calling external condition daemons, we take careful calling
		// convention here.

		err = catch(cnd_d = load_object(CONDITION_D(cnd[i])));
		if (!cnd_d) {
			// If we failed to load the external condition daemon, remove
			// it before we stuff log files with error messages.

			log_file("condition.err",
				sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
					CONDITION_D(cnd[i]), this_object(), err)
			);
			map_delete(conditions, cnd[i]);
			continue;
		}

    if ( !cond_def[cnd[i]] )
    	continue;
     
		cnd_type = cond_def[cnd[i]]["type"];
		if (cnd_type == required_type) {
			if (!mapp(type_conditions)) type_conditions = ([ cnd[i] : conditions[cnd[i]] ]);
			else type_conditions[cnd[i]] = conditions[cnd[i]];
		}
	}
	return type_conditions;
}

nomask varargs void clear_condition(string cnd)
{							// 原先clear_condition 只是简单地删除所有 condition，没有理会这些 condition 在被清除之前是否有扫尾工作需要做，
	object cd;				// 修改之后，在删除某个 condition 前会调用它的 delete_condition 函数，告诉它要被删除了，有什么后事赶紧交代吧！
	mixed *cnds, err;		// by lordstar 2017/8/26
	int i;
	if (!cnd)
	{
		if (!mapp(conditions) || !(i = sizeof(conditions))) return;
		cnds = keys(conditions);
		while(i--) {
		// In order to not casue player lost heart beat occasionally while
		// calling external condition daemons, we take careful calling
		// convention here.
			err = catch(cd = load_object(CONDITION_D(cnds[i])));
			if (!cd) {
			// If we failed to load the external condition daemon, remove
			// it before we stuff log files with error messages.
				log_file("condition.err",
					sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
						CONDITION_D(cnds[i]), this_object(), err));
				continue;
			}
			call_other(cd, "delete_condition", this_object(), conditions[cnds[i]]);
		}
		conditions = 0;
	}
	else if (mapp(conditions)) 
	{
		err = catch(cd = load_object(CONDITION_D(cnd)));
		if (!cd)
		{
			log_file("condition.err",
				sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n", CONDITION_D(cnd), this_object(), err));		
		}
		else
		{
			call_other(cd, "delete_condition", this_object(), conditions[cnd]);
		}
		map_delete(conditions, cnd);
	}
}

nomask void clear_conditions_by_type(string required_type)
{
	object cnd_d;
	int i;
	string cnd_type;
	mixed *cnd, err;

	if (!mapp(conditions) || !(i = sizeof(conditions))) return;
	cnd = keys(conditions);
	while(i--) {
		// In order to not casue player lost heart beat occasionally while
		// calling external condition daemons, we take careful calling
		// convention here.

		err = catch(cnd_d = load_object(CONDITION_D(cnd[i])));
		if (!cnd_d) {
			// If we failed to load the external condition daemon, remove
			// it before we stuff log files with error messages.
			log_file("condition.err",
				sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
					CONDITION_D(cnd[i]), this_object(), err)
			);
			map_delete(conditions, cnd[i]);
			continue;
		}
    
    if ( !cond_def[cnd[i]] )
    	continue;
     
		cnd_type = cond_def[cnd[i]]["type"];
		if (cnd_type == required_type) 
		{		// 增加删除前调用delete_condition函数的环节，便于料理后事。by lordstar 2017/8/26
			call_other(cnd_d, "delete_condition", this_object(), conditions[cnd[i]]);
			map_delete(conditions, cnd[i]);
		}
	}
}

// 检查并重新计算所有 condition 是否属于 “不规则的毒” irregular_condition 
// 主要是用于 login 时重建 irregular 值
nomask void inspect_irregular_conditions()
{
	mixed *cnd;
	int i, irr_flag;
	object cnd_d;

	if( !mapp(conditions) || !(i=sizeof(conditions)) ) return;
	cnd = keys(conditions);
	while(i--){
		cnd_d = load_object(CONDITION_D(cnd[i]));
		if( !cnd_d ) continue;
		irr_flag = cnd_d->query_irregular_times();
		if (irr_flag<=0)
		{
			if (mapp(irregular) && mapp(irregular[cnd[i]]))
				map_delete(irregular, cnd[i]);
		}
		else
		{
			if ( !mapp(irregular) )
				irregular = ([ cnd[i] : ([ "irr_flag": irr_flag, "times": 0, ]) ]);
			else if (!mapp(irregular[cnd[i]]))
				irregular[cnd[i]] = ([ "irr_flag": irr_flag, "times": 0, ]);
			else 
				irregular[cnd[i]]["irr_flag"] = irr_flag;
		}	
	}
}