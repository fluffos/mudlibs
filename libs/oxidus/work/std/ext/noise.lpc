int *p;
int *perm;
mixed *grad_p;

float F2, G2;

mixed *grad3;
protected nosave int *_grid_size = ({10, 10});
protected nosave int *_seed = ({ 10, 20 });

void seed(mixed seed);

mixed *init_noise(int width, int height, int seed) {
  grad3 = ({
    ({1,1,0}) , ({-1,1,0}) , ({1,-1,0}) , ({-1,-1,0}),
    ({1,0,1}) , ({-1,0,1}) , ({1,0,-1}) , ({-1,0,-1}),
    ({0,1,1}) , ({0,-1,1}) , ({0,1,-1}) , ({0,-1,-1})
  });

  p = ({
    151,160,137,91,90,15,
    131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
    190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
    88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
    77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
    102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
    135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
    5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
    223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
    129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
    251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
    49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
    138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180
  });

  perm = allocate(512);
  grad_p = allocate(512);

  F2 = 0.5 * (sqrt(3.0) - 1.0);
  G2 = (3.0 - sqrt(3.0)) / 6.0;

  _grid_size = ({width, height});

  seed(seed);

  return _seed;
}

int *get_seed() {
  return _seed;
}

varargs void seed(mixed seed_input) {
  int i;

  // Sanitize the seed
  int *sanitized_seed = sanitize_seed(seed_input);
  int s0 = sanitized_seed[0];
  int s1 = sanitized_seed[1];

  for(i = 0; i < 256; i++) {
    int v;

    // Alternate between using s0 and s1 in the bitwise operations
    if(i & 1)
      v = p[i] ^ (s0 & 255);          // Use s0 for odd indices
    else
      v = p[i] ^ ((s1 >> 8) & 255);   // Use s1 for even indices

    perm[i] = perm[i + 256] = v;
    grad_p[i] = grad_p[i + 256] = grad3[v % 12];
  }

  _seed = ({ s0, s1 });
}

float dot2(int *grad, float x, float y) {
  return to_float(grad[0]) * x + to_float(grad[1]) * y;
}

float simplex2(float xin, float yin) {
  float n0, n1, n2; // Noise contributions from the three corners
  // Skew the input space to determine which simplex cell we're in

  float fxin, fyin;
  float s, t;
  int i, j, i1, j1;
  float x0, y0, x1, y1, x2, y2;
  int *gi0, *gi1, *gi2;
  float t0;
  float t1, t2;

  fxin = xin;
  fyin = yin;

  s = (fxin + fyin) * F2; // Hairy factor for 2D
  i = to_int(floor( fxin + s ));
  j = to_int(floor( fyin + s ));
  t = to_float(i+j) * G2;
  x0 = fxin - to_float(i) + t; // The x,y distances from the cell origin, unskewed.
  y0 = fyin - to_float(j) + t;
  // For the 2D case, the simplex shape is an equilateral triangle.
  // Determine which simplex we are in.

  if(x0>y0) {
    // lower triangle, XY order: (0,0)->(1,0)->(1,1)
    i1=1; j1=0;
  } else {
    // upper triangle, YX order: (0,0)->(0,1)->(1,1)
    i1=0; j1=1;
  }

  // A step of (1,0) in (i,j) means a step of (1-c,-c) in (x,y), and
  // a step of (0,1) in (i,j) means a step of (-c,1-c) in (x,y), where
  // c = (3-sqrt(3))/6
  x1 = x0 - (float)i1 + G2; // Offsets for middle corner in (x,y) unskewed coords
  y1 = y0 - (float)j1 + G2;
  x2 = x0 - 1.0 + 2.0 * G2; // Offsets for last corner in (x,y) unskewed coords
  y2 = y0 - 1.0 + 2.0 * G2;
  // Work out the hashed gradient indices of the three simplex corners
  i &= 255;
  j &= 255;
  gi0 = grad_p[i+perm[j]];
  gi1 = grad_p[i+i1+perm[j+j1]];
  gi2 = grad_p[i+1+perm[j+1]];
  // Calculate the contribution from the three corners
  t0 = 0.5 - x0 * x0 - y0 * y0;

  if(t0 < 0.0)
    n0 = 0.0;
  else {
    t0 *= t0;
    n0 = t0 * t0 * dot2(gi0, x0,  y0);
  }

  t1 = 0.5 - x1*x1-y1*y1;

  if(t1 < 0.0)
    n1 = 0.0;
  else {
    t1 *= t1;
    n1 = t1 * t1 * dot2(gi1, x1, y1);
  }

  t2 = 0.5 - x2*x2 - y2*y2;
  if(t2 < 0.0) {
    n2 = 0.0;
  } else {
    t2 *= t2;
    n2 = t2 * t2 * dot2(gi2, x2, y2);
  }

  // Add contributions from each corner to get the final noise value.
  // The result is scaled to return values in the interval [-1,1].
  return 70.0 * (n0 + n1 + n2);
}

float fade(float t) {
  return t*t*t*(t*(t*6.0-15.0)+10.0);
}

float lerp(float a, float b, float t) {
  return (1.0 - t) * a + t * b;
}

// 2D Perlin Noise
float perlin2 (float x, float y) {
  int X, Y;
  float n00, n01, n10, n11;
  float u;

  X = to_int(floor(x)); Y = to_int(floor(y));
  // Get relative xy coordinates of point within that cell
  x = x - to_float(X); y = y - to_float(Y);
  // Wrap the integer cells at 255 (smaller integer period can be introduced here)
  X = X & 255; Y = Y & 255;

  // Calculate noise contributions from each of the four corners
  n00 = dot2(grad_p[X+perm[Y]], x, y);
  n01 = dot2(grad_p[X+perm[Y + 1]], x, y - 1.0);
  n10 = dot2(grad_p[X+1+perm[Y]], x - 1.0, y);
  n11 = dot2(grad_p[X+1+perm[Y + 1]], x - 1.0, y - 1.0);

  // Compute the fade curve value for x
  u = fade(x);

  // Interpolate the four results
  return lerp(
    lerp(n00, n10, u),
    lerp(n01, n11, u),
    fade(y)
  );
}
