// condition.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <condition.h>

mapping conditions;

// Get the object of condiction daemon
private object get_object(string cnd)
{
        mixed err;
        object cnd_d;

	cnd_d = find_object(CONDITION_D(cnd));
	if( !cnd_d ) {
		err = catch(cnd_d = load_object(CONDITION_D(cnd)));

		// If we failed to load the external condition daemon, remove
		// it before we stuff log files with error messages.

		if( err || !cnd_d ) {
			log_file("condition.err",
				sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
					CONDITION_D(cnd), this_object(), err)
			);
                        if (mapp(conditions))
                                map_delete(conditions, cnd);
		}
	}

        return cnd_d;
}

// This function is called by heart_beat to update "continously active"
// conditions. These conditions will be saved as well. Because such type
// of conditions costs heart beat evaluation time, don't make player got
// too much this kind of conditions or you might got lots fo "Too long
// evaluation" error message in the log file.

nomask int update_condition()
{
	mixed *cnd;
	int i, flag, update_flag;
	object cnd_d;

	if( !mapp(conditions) || !(i=sizeof(conditions)) ) return 0;
	cnd = keys(conditions);
	update_flag = 0;
	while(i--) {

		// In order to not casue player lost heart beat occasionally while
		// calling external condition daemons, we take careful calling
		// convention here.

                cnd_d = get_object(cnd[i]);
                if( !cnd_d ) continue;

		// We assume since the condition daemon is loaded successfully, the
		// calling on its update_condition() should success as well. Because
		// catch() is somewhat costly, so we don't attempt to catch possible
		// error from the call_other. It is condition daemon's reponsibility
		// that don't cause error in users's heart beat.
		// If condition daemon returns 0 (or update_condition() not defined),
		// we can just assume the condition expired and remove it.
		
		flag = call_other(cnd_d, "update_condition", this_object(), conditions[cnd[i]]);
                if( !conditions )
                {
                        update_flag |= flag;
                        break;
                }
		if( !( flag & CND_CONTINUE ) ) map_delete(conditions, cnd[i]);
		update_flag |= flag;
	}

	if( conditions && !sizeof(conditions) ) conditions = 0;

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
	if( !mapp(conditions) )
		conditions = ([ cnd : info ]);
	else
		conditions[cnd] = info;
}

// query_condition()
//
// This function returns info about the specific condition if any.

nomask mixed query_condition(string cnd)
{
        if( !cnd ) return conditions;

	if( !mapp(conditions) || undefinedp(conditions[cnd]) ) return 0;
	return conditions[cnd];
}

nomask void clear_condition(string cnd)
{
        if ( !cnd )
	        conditions = 0;
        else
        {
                map_delete(conditions, cnd);
                if (!sizeof(conditions)) conditions = 0;
        }
}

// Query a conditon's name
nomask string query_condition_name(string cnd)
{
        object cnd_d;

        if ( !(cnd_d = get_object(cnd)) )
                return 0;

        return cnd_d->cnd_name();
}

// Dispel a condition
nomask int dispel_condition(object ob, string cnd)
{
        object cnd_d;

        if ( !(cnd_d = get_object(cnd)) )
                return 0;

        return cnd_d->dispel(ob, this_object(), conditions[cnd]);
}

// Call the condition's do_effect funtion
nomask int affect_by(string cnd, mixed para)
{
        object cnd_d;

        if ( !(cnd_d = get_object(cnd)) )
                return 0;

        if (! para) para = this_object()->query_temp("para");

        return cnd_d->do_effect(this_object(), cnd, para);
}
