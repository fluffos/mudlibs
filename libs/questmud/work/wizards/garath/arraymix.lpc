mixed mix_array(mixed *array) {
mixed *arraymix;
mixed tmp;
int i;

arraymix = allocate(sizeof(array));
i = random(sizeof(arraymix));
while(tmp = array[0]) {
  while(arraymix[i]) i = random(sizeof(arraymix));
  arraymix[i] = array[0];
  array -= array[0];
}

return arraymix;

}

