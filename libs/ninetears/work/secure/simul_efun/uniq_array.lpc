//      /secure/simul_efun/uniq_array.c
//      from the RotD Mudlib
//      takes any array and returns an array with no repeat members
//      created by Descartes of Borg 930822

mixed *uniq_array(mixed *arr) {
    mapping borg;
    int i;
  
    i = sizeof(arr);
    borg = ([]);
    while(i--) borg[arr[i]] = 1;
    return keys(borg);
}
