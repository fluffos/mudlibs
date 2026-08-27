/** coded by Raskolnikov October 1996 **/
inherit "/std/noncombat.c";

void setup() {
    set_light(40);
    set_short("Lost and Found");
    set_long("Lost and Found\n\n"
      "     This is a small, cluttered looking place that you come to "
      "when you have lost something and have been given an IOU for "
      "it.  It is dirty and random objects lie everywhere in various "
      "states of disrepair.  If what you have been given an IOU for "
      "is not here now it may show up here eventually.\n\n");
    add_item("objects", "As you look around you see heaps and "
      "piles of worthless, broken things.  Hopefully you will be "
      "able to find what you need in this cluttered mess.\n\n");
    add_sign("A small, scribbled up sign\n",
      "Type 'find' to reclaim your IOUs.\n\n"
      "NOTE: If your IOU is not sucessfully reclaimed bug the Thane "
      "of the domain that it is from about it.\n\n"
      "               The Management\n",
      "small sign");
}

void init() {
    ::init();
    add_action("locate_iou", "find");
}

void locate_iou(string str) {
    int i, j;
    string iou_path, switched_dirs, *oldnew_paths, *temp_exp;
    object *ious, *pinv, found_ob;

    ious = ({ });
    pinv = deep_inventory(this_player());
    for(i=0;i<sizeof(pinv);i++)
	if(pinv[i]->query_iou_object() == 1)
	    ious += ({ pinv[i] });
    for(i=0;i<sizeof(ious);i++) {
	iou_path = ious[i]->query_path();
	switched_dirs = read_file("/open/SWITCHED_DIRS");
	oldnew_paths = explode(switched_dirs, "\n");
	for(j=0;j<sizeof(oldnew_paths);j++) {
	    temp_exp = explode(oldnew_paths[j], " ");
	    if(iou_path == temp_exp[0]) {
		catch(
		  found_ob = 
		  clone_object(temp_exp[1]+"/"+ious[i]->query_file()+".c"));
		if(found_ob) {
		    found_ob->move(this_player());
		    tell_object(this_player(), "Your "
		      ""+found_ob->query_short()+" has been found "
		      "and returned.\n");
		    ious[i]->dest_me();
		}
	    }
	}
    }
    tell_object(this_player(), "IOU search completed.\n");
    tell_object(this_player(), "If you still have IOUs "
      "inform the thane of the domain that the IOU is from.\n");
    return 1;
}
