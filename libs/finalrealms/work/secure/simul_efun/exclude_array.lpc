varargs mixed *exclude_array(mixed *arry, int from, int to) {
    mixed *bottom, *top;

    bottom = ({});
    top = ({});
    if(!to) to = from;
    if(from > 0) bottom = arry[0..from -1];
    if(to < sizeof(arry)-1) top = arry[to+1..sizeof(arry)-1];
    return bottom + top;
}
