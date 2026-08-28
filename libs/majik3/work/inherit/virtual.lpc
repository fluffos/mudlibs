object compile_object(string file) {
    object host, ob;

    if(virtualp(this_object())) return 0;
    host = new(file_name(this_object()));
    ob = host->create_virtual(file);
    if (!ob) destruct(host);
    return ob;
}

