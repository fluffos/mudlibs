varargs mixed *exclude_array(mixed *arra, int from, int to) {
    mixed *bottom, *top;

    bottom = ({});
    top = ({});
    if(!to) to = from;
    if(from > 0) bottom = arra[0..from -1];
    if(to < sizeof(arra)-1) top = arra[to+1..sizeof(arra)-1];
    return bottom + top;
}
