nosave object *labels;

void create() {
    labels = ({ });
    }

object *query_labels() { return labels; }

int add_weight(int n) {
    return !n;
    }

int test_remove(object ob, int flag) { return 1; }
int test_add(object ob, int flag) { 
    return ob->query_property("label") && member_array(ob, labels) != -1;
    }

/* Note, this should be called BEFORE the label is stuck on the object. */
void add_label(object ob) {
    if (environment()) {
        filter_array(all_inventory(environment()), "add_read_this", this_object());
	environment()->add_command("read", this_object());
	}
    labels += ({ ob });
    }

void remove_label(object ob) {
    labels = labels - ({ ob });
    }

mixed *query_init_data() {
    return ({ "labels", labels, "add_label/P*/" });
    }
