object load_object(string str) {
    object ob;
    if(ob = find_object(str)) return ob;
    catch(call_other(str, "???"));
    return find_object(str);
}
