int atoi(string str) {
    int x;

    if(!str) return 0;
    if(!sscanf(str, "%d", x)) return 0;
    return x;
}
float percent(mixed numerator, mixed denominator) {
    float a, b;

    if(!floatp(numerator) && !intp(numerator)) return 0.0;
    else a = (floatp(numerator) ? numerator : to_float(numerator));
    if(!floatp(denominator) && !intp(denominator)) return 0.0;
    else b = (floatp(denominator) ? denominator : to_float(denominator));
    return ((a/b)*100);
}
