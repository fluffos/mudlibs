int *roll_dice( int dice, int sides )
{
  int *tmp = allocate( dice );
  for( int i = 0; i < dice; ++i )
    tmp[ i ] = random( sides ) + 1;
  return tmp;
}

int num_over( int *roll, int reqd_value, int reqd_count )
{
  int ct = 0;
  for( int i = 0; i < sizeof(roll); ++i )
  {
    if( roll[i] >= reqd_value )
      ++ct;
  }
  return ct >= reqd_count;
}

void checkdice( int dice, int sides, int req_value, int req_count )
{
  int success = 0;
  int tests = 8000;
  for( int i = 0; i < tests; ++i )
  {
    int *res = roll_dice( dice, sides );
    if( num_over(res, req_value, req_count) )
      ++success;
  }
  msg( "Success count " + success );
  msg( "Success percentage " + ((float) success / (float) tests) * 100.0 );
}

int main( string param )
{
  int a, b, c, d;
  if( param && sscanf(param, "%d %d %d %d", a, b, c, d) == 4 )
  {
    checkdice( a, b, c, d );
    return 1;
  }
  else
    return notify_fail( "dicetest <num-dice> <sides> <required_value> <required_count>\n" );
}