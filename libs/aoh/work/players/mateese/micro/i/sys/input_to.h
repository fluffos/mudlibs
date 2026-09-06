#ifndef INPUT_TO_H
#define INPUT_TO_H 1

// input_to() may take a flagbit integer as second argument.
// These are the flags.

#define INPUT_NOECHO     1  // Line input will not be echoed
#define INPUT_CHARMODE   2  // Input is read charwise.
#define INPUT_IGNBANG  128  // Disallow shell escape

#endif
