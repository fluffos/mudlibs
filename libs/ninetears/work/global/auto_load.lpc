
void auto_clone(mixed arg);
string *create_auto_load(object *obs) {
    	string s, s1, s3;
    	mixed auto_string;
    	string *fname;
    	int i;
    	if(!obs) return ({ });
    	auto_string = ({ });
    	/* do this backwards, means it comes out right on logon */
    	for (i = sizeof(obs) -1; i >= 0; i--) {
		s = s3 = 0;
		if (!catch(s=(string)obs[i]->query_auto_load()) && !s) {
	    		catch(s = (string)obs[i]->query_static_auto_load());
	    		catch(s3 = (string)obs[i]->query_dynamic_auto_load());
	    		if (!s && !s3) continue;
	    /*
	     * Fix by Aragorn. Used to be !s below
	     * Name of function is a bit mismatching (query_auto_load())
	     * because if it returns something it won't...
	     */
			}
		else if (s) continue;
		else s3 = 0;
	// Taniwha, there's some evidence that things aren't SAVING maybe something dests in query_auto_load()
		if(!obs[i]) continue;
		fname = explode(file_name(obs[i]),"#");
		s1 = fname[0];
		auto_string += ({ 1, s1, ({ s, s3 }) });
    		}
    	return auto_string;
	} /* create_auto_load() */

void make_iou(mixed stuff,object dest) {
    	object iou;
    	log_file("loader",(string)dest->query_cap_name()+" had "+(string)stuff[1]+" refuse to load .\n");
    	catch(iou=clone_object("/obj/misc/iou"));
    	if(iou) {
		iou->add_auto_string(stuff);
		catch(iou->move(dest));
    		}
	}

object *load_auto_load(string *auto_string, object dest) {
    	object ob, *obs;
    	int i;
    	obs = ({ });
    	if (stringp(auto_string)) return ({ });
    	if (!auto_string || !sizeof(auto_string)) return ({ });
    /* This for loop gives errors sometimes..
     * should be made bulletproof..
     * Baldrick.
     */
    	for (i=0;i<sizeof(auto_string);i+=3) {
	/* Maybe this line makes it bulletproof?
	 * Baldrick May '95
	 */
	// If there's a file name here
		if (sizeof(auto_string[i+1])) {
	    	// Try to clone one
	    		catch(ob = clone_object(auto_string[i+1]));
	    		if(ob) {
		// This initializes the data in the object,and saved vars
				auto_clone( ({ ob,auto_string[i+2], dest }));
		// Useful this, you can tell what didn;t laod for example.
				obs += ({ ob });
	    			}
	    		if(!ob) /* And if it didn't work , give em an IOU */ make_iou( ({auto_string[i],auto_string[i+1],auto_string[i+2]}),dest);
	    		} /* If auto_string */
    		} /* for */
    	return obs;
	} /* load_auto_load() */

void auto_clone(mixed  arg) {
    	if(!arg[0]) {
		tell_object(this_object(),"Ooops something broke.\n");
//		stuf --;
		return;
    		}

    	if (sizeof(arg[1]) == 1 || !arg[1][1]) arg[0]->init_arg(arg[1][0]);
        else {
		arg[0]->init_static_arg(arg[1][0]);
		arg[0]->init_dynamic_arg(arg[1][1]);
    		}
    	// Taniwha 1995, if the container hasn't loaded, what shall we do ?
    	if(arg[0] && arg[2] && !(arg[0]->move(arg[2]))); // if they exist AND the move succeeds
    	else {
		log_file("loader",(string)this_object()->query_name()+" Dropped a "+(string)arg[0]->query_name()+" on login.\n");
		tell_object(this_object(),"Huy, se te ha caido algo.\n");
		if(arg[0]) arg[0]->move(environment());
    		}
    	//stuf-=1;
	} /* auto_clone() */

/* The really stupid thingie..
 * Baldrick.
 */
int query_loading() {
//  if (stuf<1) return 0;
    return 0;
	}
/* In case of bugs.. */
void reset_stuff() {
 // 	stuf=0;
    	return;
	}

/* Hamlet added me -- I'm used for the 'update' command. */
string *create_update_auto_load(object ob) {
    	string s, s1, s3;
    	mixed auto_string;
    	int j;

    	if(!ob) return ({ });

    	catch(s = (string)ob->query_static_auto_load());
    	catch(s3 = (string)ob->query_dynamic_auto_load());

    	if (!s && !s3) return ({ });

    	if (sscanf(file_name(ob), "%s#%d", s1, j) == 2)	auto_string = ({ 1, s1, ({ s, s3 }) });
	else auto_string = ({ 0, file_name(ob), ({ s, s3 }) });

    	return auto_string;
	} /* create_update_auto_load() */
