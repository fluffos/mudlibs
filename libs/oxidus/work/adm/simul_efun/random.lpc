#include <simul_efun.h>

/**
 * Generates a random float between 0 and upper_bound.
 *
 * @param {mixed} upper_bound - The upper bound for the random float.
 * @returns {float} The random float between 0 and upper_bound.
 */
float random_float(mixed upper_bound) {
  if(upper_bound < 0.0)
    return 0.0;

  // Convert upper_bound to float
  upper_bound = to_float(upper_bound);

  // Generate a random float between 0 and upper_bound
  return to_float(random(to_int(upper_bound * 1000000))) / 1000000.0;
}

/**
 * Selects an element from a weighted mapping based on their weights.
 *
 * @param {mapping} m - The weighted mapping to select from, where keys are the
 *                      elements and values are their weights.
 * @returns {mixed} The selected element.
 */
mixed element_of_weighted(mapping m) {
  int total;
  int roll;
  mixed result;

  total = sum(values(m));

  roll = random(total);
  foreach(mixed item, int weight in m) {
    if(roll < weight) {
      result = item;
      break;
    }
    roll -= weight;
  }

  return result;
}

/**
 * Generates a random integer within a specified range.
 *
 * @param {int} min - The lower bound (inclusive) of the range.
 * @param {int} max - The upper bound (inclusive) of the range.
 * @returns {int} A random number in the specified range.
 */
int random_clamp(int min, int max) {
  if(min >= max)
    return min;

  return random(max - min+1) + min;
}

/* PRANDOM 128 */
/**
 * Sanitizes the seed for the random number generator. Ensuring
 * that the seed is a non-zero integer and within the range of
 * a 64-bit unsigned integer.
 *
 * @param {mixed} seed - The seed to sanitize.
 * @returns {int*} The sanitized seed.
 */
public int *sanitize_seed(mixed seed) {
  int s0, s1;

  // If seed is a single integer, generate s0 and s1
  if(intp(seed)) {
    s0 = abs(seed) % 0xFFFFFFFFFFFFFFFF || 1;  // Ensure s0 is non-zero
    s1 = (s0 + 0x9E3779B9) & 0xFFFFFFFFFFFFFFFF || 1;  // Generate s1 from s0
  }
  // If seed is an array, sanitize both s0 and s1
  else if(arrayp(seed) && sizeof(seed) == 2) {
    s0 = abs(seed[0]) % 0xFFFFFFFFFFFFFFFF || 1;
    s1 = abs(seed[1]) % 0xFFFFFFFFFFFFFFFF || 1;
  }
  // Invalid input, return a default sanitized state
  else {
    s0 = time() % 0xFFFFFFFFFFFFFFFF || 1;
    s1 = (s0 + 0x9E3779B9) & 0xFFFFFFFFFFFFFFFF || 1;
  }

  return ({ s0, s1 });
}

/**
 * Generates a random number within a specified range using the
 * xorshift128+ algorithm.
 *
 * @param {mixed} seed - The seed for the random number generator.
 * @param {int} size - The upper bound for the random number.
 * @returns {int*} A two element array where the first element is the
 *                   updated seed and the second is the random number.
 */
int *prandom(mixed seed, int size) {
  int *result = allocate(2);
  int s0, s1;
  int random_value;

  if(intp(seed))
    seed = ({ seed, seed + 0x9E3779B9 });

  // Sanitize the seed (single integer or array)
  seed = sanitize_seed(seed);
  s0 = seed[0];
  s1 = seed[1];

  // Perform xorshift128+ algorithm
  s1 ^= (s1 << 23);
  s1 ^= (s1 >> 18);
  s1 ^= s0;
  s1 ^= (s0 >> 5);

  // Update state
  seed = ({ s1, s0 });

  // Ensure the result is non-negative using bitwise AND to convert to unsigned
  random_value = (s1 + s0) & 0xFFFFFFFFFFFFFFFF;

  // Return updated state and random result modulo size
  result[0] = seed;
  result[1] = random_value % size;

  return result;
}

/**
 * Generates a random float within a specified range using the
 * xorshift128+ algorithm.
 *
 * @param {mixed} seed - The seed for the random number generator.
 * @param {float} size - The upper bound for the random float.
 * @returns {mixed*} A two element array where the first element is the
 *                      updated seed and the second is the random float.
 */
mixed *prandom_float(mixed seed, float size) {
  mixed *result = allocate(2);
  int s0, s1;

  // Check if the seed is a single integer or an array
  if(intp(seed)) {
    // Single integer: generate s0 and s1
    s0 = seed;
    s1 = s0 + 0x9E3779B9;
  } else if(arrayp(seed) && sizeof(seed) == 2) {
    // Array of integers: use it as the state
    s0 = seed[0];
    s1 = seed[1];
  } else
    return 0;
  // Perform xorshift128+ algorithm
  s1 ^= (s1 << 23);
  s1 ^= (s1 >> 18);
  s1 ^= s0;
  s1 ^= (s0 >> 5);

  // Update state
  seed = ({ s1, s0 });

  // Return the updated state and random float result
  result[0] = seed;
  result[1] = (to_float((s1 + s0) % to_int(size)) * (size / to_int(size)));

  return result;
}

/**
 * Shuffles an array using the xorshift128+ algorithm.
 *
 * @param {mixed} seed - The seed for the random number generator.
 * @param {mixed*} arr - The array to shuffle.
 * @returns {mixed*} A two element array where the first element is the
 *                      updated seed and the second is the shuffled array.
 */
mixed *pshuffle(mixed seed, mixed *arr) {
  mixed *new_arr;
  int index;
  mixed *result = allocate(2);

  // If null, empty, or not an array, return 0
  if(!arr || !arrayp(arr) || !sizeof(arr))
    return 0;

  // Copy the original array
  index = sizeof(arr);
  new_arr = copy(arr);

  while(index--) {
    int random_index;
    mixed tmp;

    // Use prandom() to generate a new random index
    result = prandom(seed, index + 1);
    random_index = result[1];

    // Swap elements
    tmp = new_arr[index];
    new_arr[index] = new_arr[random_index];
    new_arr[random_index] = tmp;

    // Update the seed with the new one from prandom
    seed = result[0];
  }

  result[1] = new_arr;

  return result;
}

/**
 * Selects an element from an array using the xorshift128+
 * algorithm.
 *
 * @param {mixed} seed - The seed for the random number generator.
 * @param {mixed*} arr - The array to select an element from.
 * @returns {mixed*} A two element array where the first element is the
 *                      updated seed and the second is the selected element.
 */
mixed *pelement_of(mixed seed, mixed *arr) {
  mixed *result = allocate(2);
  int sz;

  // If the array is empty or not an array, return 0
  if(!sizeof(arr) || !arrayp(arr))
    return 0;

  sz = sizeof(arr);
  result = prandom(seed, sz);

  result[1] = arr[result[1]];

  return result;
}

/**
 * Generates a random number within a specified range using the
 * xorshift128+ algorithm.
 *
 * @param {mixed} seed - The seed for the random number generator.
 * @param {int} min - The lower bound (inclusive) of the range.
 * @param {int} max - The upper bound (inclusive) of the range.
 * @returns {mixed*} A two element array where the first element is the
 *                      updated seed and the second is the random number.
 */
mixed *prandom_clamp(mixed seed, int min, int max) {
  mixed *result;

  if(min >= max)
    return ({ seed, min });

  result = prandom(seed, max - min + 1);
  result[1] += min;

  return result;
}

/**
 * Selects an element from a weighted mapping using the
 * xorshift128+ algorithm.
 *
 * @param {mixed} seed - The seed for the random number generator.
 * @param {mapping} weights - The weighted mapping to select from, where keys
 *                            are the elements and values are their weights.
 * @returns {mixed*} A two element array where the first element is the
 *                      updated seed and the second is the selected element.
 */
mixed *pelement_of_weighted(mixed seed, mapping weights) {
  float total = 0.0;
  mixed *_items = keys(weights);
  mixed *float_result;
  float roll;
  mixed *result = allocate(2);

  // If the mapping is empty, return 0
  if(!sizeof(_items))
    return 0;

  total = sum(map(values(weights), (: to_float :)));

  float_result = prandom_float(seed, total);
  result[0] = float_result[0];  // New seed
  roll = float_result[1];  // Random roll

  foreach(mixed item, int weight in weights) {
    if(roll < weight) {
      result[1] = item;
      break;
    }
    roll -= weight;
  }

  return result;
}
