{
    object* listeners;
    object listener;
    listeners = all_inventory(ETP);
    listeners = filter_array(listeners, (: $1->is_living() :));
    listeners = filter_array(listeners, (: $1->query_property("detecting_thoughts") :));

    if (sizeof(listeners)) {
        foreach(listener in listeners) {
            object detect_thoughts = listener->query_property("detecting_thoughts");

            if (!objectp(detect_thoughts)) continue;
            if (listener == TP || listener == ob) continue;

            if (detect_thoughts->do_save(TP)) {
                tell_object(TP, "%^BOLD%^%^RED%^You sense your telepathic thoughts are being detected.%^RESET%^");
                if ((TP->query_stats("intelligence") - listener->query_stats("intelligence")) > 10) {
                    listener->set_paralyzed(roll_dice(2, 4), "Interception of your thought detection leaves you stunned!");
                    detect_thoughts->dest_effect();
                    continue;
                }
            }
            tell_object(listener, "%^BOLD%^%^RED%^" + TP->QCN + " communicates with " + ob->QCN + ".%^RESET%^");
        }
    }
}
